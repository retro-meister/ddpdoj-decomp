#include "common.h"

typedef struct {
    s16 next;
    s16 previous;
    s16 link;
    u8 data[6];
} ListEntry;

extern void func_00218210(s32 index, s32 lastIndex, ListEntry *entries);
extern void func_002182B0(void);
extern ListEntry D_0057EF80[];
extern ListEntry D_00583FC0[];

void func_002182F0(void) {
    s32 i;

    func_002182B0();
    for (i = 2; i < 0x402; i++) {
        D_00583FC0[i].previous = D_00583FC0[i].next = i - 2;
    }
    D_00583FC0[0].previous = -1;
    D_00583FC0[1].next = -2;
    func_00218210(0, 0x400, &D_00583FC0[2]);
    for (i = 2; i < 0xE3; i++) {
        D_0057EF80[i].previous = D_0057EF80[i].next = i - 2;
    }
    D_0057EF80[0].previous = -1;
    D_0057EF80[1].next = -2;
    func_00218210(0, 0xE1, &D_0057EF80[2]);
}
