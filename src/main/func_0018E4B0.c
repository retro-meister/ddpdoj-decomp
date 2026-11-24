#include "common.h"

void *func_00115160(s32, s32);
void func_001153E8(void *);
void func_00216160(void *, s32, s32);
void func_00216210(char *);
void *memcpy(void *, const void *, s32);

typedef struct {
    s32 f0;
    s32 f4;
} Entry18E4B0;

typedef struct {
    s32 size;
    s32 lsn;
} CdInfo18E4B0;

extern char *D_0025BD30[];
extern Entry18E4B0 D_0029CA60[];
extern CdInfo18E4B0 D_002C0100[];
extern u8 D_0068DF10[];

void func_0018E4B0(void) {
    s32 i;
    void *buf;
    s16 *dst;

    buf = func_00115160(0x40, 0x800);
    for (i = 0; i < 10; i++) {
        func_00216210(D_0025BD30[i]);
        D_0029CA60[i].f0 = D_002C0100[0].lsn;
        D_0029CA60[i].f4 = D_002C0100[0].size;
        func_00216160(buf, 0x800, D_002C0100[0].size);
        dst = (s16 *)(D_0068DF10 + i * 0x42);
        memcpy(dst, buf, 0x42);
        *dst = 1;
    }
    func_001153E8(buf);
}
