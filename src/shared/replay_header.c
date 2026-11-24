#include "common.h"
#include "sdk/ps2sdk.h"

void func_00236C50(u8 *arg0) {
    printf("fig1p type[%d] doll[%d] \n", (*(u16 *)((u8 *)(arg0) + (2))), (*(u16 *)((u8 *)(arg0) + (4))));
    printf("fig2p type[%d] doll[%d] \n", (*(u16 *)((u8 *)(arg0) + (6))), (*(u16 *)((u8 *)(arg0) + (8))));
    printf("difficulty[%d]\n", (*(u16 *)((u8 *)(arg0) + (0xA))));
    printf("round[%d]\n", (*(u16 *)((u8 *)(arg0) + (0xC))));
    printf("stage[%d]\n", (*(u16 *)((u8 *)(arg0) + (0xE))));
    printf("rank[%d]\n", (*(u16 *)((u8 *)(arg0) + (0x20))));
    printf("max bom[%d]\n", (*(u16 *)((u8 *)(arg0) + (0x14))));
    printf("stock bom[%d]\n", (*(u16 *)((u8 *)(arg0) + (0x16))));
    printf("hyper stock[%d]\n", (*(u16 *)((u8 *)(arg0) + (0x1C))));
    printf("hyper gage[%d]\n", (*(u16 *)((u8 *)(arg0) + (0x1E))));
    printf("start[%d]\n", (*(u16 *)((u8 *)(arg0) + (0x18))));
    printf("death[%d]\n", (*(u16 *)((u8 *)(arg0) + (0x1A))));
    printf("bullet[%d]\n", (*(u16 *)((u8 *)(arg0) + (0x24))));
}

extern s32 D_006E5BE0_as_s32_a[];
extern s16 D_006E5BE2[];
extern s16 D_006E5BE4[];
extern s16 D_006E5BE6[];
extern s16 D_006E5BE8[];

void func_00236D50(void) {
    memset(D_006E5BE0_as_s32_a, 0, 0x42);
    D_006E5BE2[0] = 0xFF;
    D_006E5BE4[0] = 0xFF;
    D_006E5BE6[0] = 0xFF;
    D_006E5BE8[0] = 0xFF;
}

void func_002075F0(void);

void func_00236DA0(void) {
    func_002075F0();
}

typedef struct {
    unsigned __int128 quadwords[4];
} StatePayload;

typedef struct {
    StatePayload payload;
    s16 trailingHalfword;
} StateBlock;

extern StateBlock D_006E5B90_as_StateBlock_a[];
extern StateBlock D_006E5BE0_as_StateBlock_a[];

void func_00236DB0(void)
{
    u32 destinationAddress = (u32)D_006E5B90_as_StateBlock_a;
    u32 sourceAddress = (u32)D_006E5BE0_as_StateBlock_a;

    *(StatePayload *)destinationAddress = *(const StatePayload *)sourceAddress;
    *(s16 *)(destinationAddress + sizeof(StatePayload)) =
        *(const s16 *)(sourceAddress + sizeof(StatePayload));
}

extern void func_00136600(void);
extern u8 D_0028E370;
extern u8 D_006E5BE0[];
extern u16 D_006E5BE2_as_u16_a[];
extern u16 D_006E5BE4_as_u16_a[];
extern u16 D_006E5BE6_as_u16_a[];
extern u16 D_006E5BE8_as_u16_a[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;

void func_00236DF0(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.h[0] = D_006E5BE2_as_u16_a[0];
    reg_d1.h[0] = D_006E5BE4_as_u16_a[0];
    reg_d2.w = 0;
    D_0028E370 = 0;
    reg_d3.w = 0;
    reg_d4.w = 1;
    reg_d2.h[0] = D_006E5BE6_as_u16_a[0];
    reg_d3.h[0] = D_006E5BE8_as_u16_a[0];
    func_00136600();
    func_00236C50(D_006E5BE0);
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
}
