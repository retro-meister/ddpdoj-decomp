#ifndef DDPDOJ_PC_ARCADE_ADDRESS_H
#define DDPDOJ_PC_ARCADE_ADDRESS_H

#include <stdbool.h>
#include <stdint.h>

/* Slots hold the address relative to the executable image, plus one. Zero
 * remains null. Keep stack and heap pointers in native-width storage. */
extern uintptr_t pc_arcade_image_base;
extern uint32_t pc_arcade_image_size;

void pc_arcade_address_init(void);
_Noreturn void pc_arcade_address_invalid(uintptr_t value);

static inline bool pc_arcade_address_contains(uintptr_t address)
{
    return address - pc_arcade_image_base < pc_arcade_image_size;
}

static inline uint32_t pc_arcade_address_encode(uintptr_t address)
{
    if (!address) {
        return 0;
    }
    if (!pc_arcade_address_contains(address)) {
        pc_arcade_address_invalid(address);
    }
    return (uint32_t)(address - pc_arcade_image_base) + 1;
}

static inline uintptr_t pc_arcade_address_decode(uint32_t slot)
{
    if (!slot) {
        return 0;
    }
    if (slot > pc_arcade_image_size) {
        pc_arcade_address_invalid(slot);
    }
    return pc_arcade_image_base + slot - 1;
}

#endif
