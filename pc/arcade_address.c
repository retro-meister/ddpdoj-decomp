#if defined(__linux__)
#define _GNU_SOURCE
#endif

#include "pc_arcade_address.h"
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#if defined(__APPLE__)
#include <dlfcn.h>
#include <mach-o/loader.h>
#include <string.h>
#elif defined(_WIN32)
#include <windows.h>
extern IMAGE_DOS_HEADER __ImageBase;
#elif defined(__linux__)
#include <link.h>
#endif

uintptr_t pc_arcade_image_base;
uint32_t pc_arcade_image_size;

_Noreturn void pc_arcade_address_invalid(uintptr_t value)
{
    fprintf(stderr, "Invalid packed arcade address or slot: 0x%" PRIxPTR "\n", value);
    abort();
}

#if defined(__linux__)
static int executable_bounds(struct dl_phdr_info *info, size_t size, void *context)
{
    (void)size;
    uintptr_t *bounds = context;
    uintptr_t first = UINTPTR_MAX, last = 0;
    bool found = false;
    for (unsigned i = 0; i < info->dlpi_phnum; i++) {
        const ElfW(Phdr) *segment = &info->dlpi_phdr[i];
        if (segment->p_type == PT_LOAD) {
            uintptr_t start = info->dlpi_addr + segment->p_vaddr;
            uintptr_t end = start + segment->p_memsz;
            if (start < first) first = start;
            if (end > last) last = end;
            uintptr_t marker = (uintptr_t)&pc_arcade_image_base;
            if (start <= marker && marker < end) found = true;
        }
    }
    if (!found) return 0;
    bounds[0] = first;
    bounds[1] = last;
    return 1;
}
#endif

void pc_arcade_address_init(void)
{
    uintptr_t base = 0;
    uintptr_t size = 0;
#if defined(__APPLE__)
    Dl_info info;
    if (!dladdr(&pc_arcade_image_base, &info)) abort();
    const struct mach_header_64 *header = info.dli_fbase;
    base = (uintptr_t)header;
    uint64_t text_address = 0;
    uint64_t image_end = 0;
    const struct load_command *command = (const void *)(header + 1);
    for (uint32_t i = 0; i < header->ncmds; i++) {
        if (command->cmd == LC_SEGMENT_64) {
            const struct segment_command_64 *segment = (const void *)command;
            if (strcmp(segment->segname, SEG_TEXT) == 0) {
                text_address = segment->vmaddr;
            }
            uint64_t end = segment->vmaddr + segment->vmsize;
            if (segment->initprot && end > image_end) {
                image_end = end;
            }
        }
        command = (const void *)((const char *)command + command->cmdsize);
    }
    size = image_end - text_address;
#elif defined(_WIN32)
    base = (uintptr_t)&__ImageBase;
    const IMAGE_NT_HEADERS64 *header = (const void *)(base + __ImageBase.e_lfanew);
    size = header->OptionalHeader.SizeOfImage;
#elif defined(__linux__)
    uintptr_t bounds[2] = {0};
    dl_iterate_phdr(executable_bounds, bounds);
    base = bounds[0];
    size = bounds[1] - bounds[0];
#endif
    if (!base || !size || size > UINT32_MAX) {
        abort();
    }
    pc_arcade_image_base = base;
    pc_arcade_image_size = (uint32_t)size;
}
