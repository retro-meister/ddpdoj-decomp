#include "common.h"

typedef struct {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
} GifPacket;

typedef struct {
    u8 pad_000000[0x505000];
    s32 menu_params[12];
    u8 pad_505030[0x118];
    s32 unk_505148;
    s32 state;
    u8 pad_505150[0x8];
    s32 timer;
    u8 pad_50515C[0x8];
    s16 unk_505164;
    u8 pad_505166[0x6];
    s16 unk_50516C;
    u8 pad_50516E[0x1];
    s8 unk_50516F;
    u8 pad_505170[0x388];
    s32 box_x0;
    s32 box_y0;
    s32 box_x1;
    s32 box_y1;
    u8 box_color_r;
    u8 box_color_g;
    u8 box_color_b;
    u8 box_color_a;
    u8 pad_50550C[0x1C];
    u8 cursor_color_r;
    u8 cursor_color_g;
    u8 cursor_color_b;
    u8 cursor_color_a;
    s32 unk_50552C;
    u8 pad_505530[0x10];
    s32 unlocked_count;
    s32 selected_index;
    u8 pad_505548[0x270];
    u8 unk_5057B8[6];
} GalleryWork;

extern u8 D_0012B0B0[];
extern s8 D_0012B2F4;
extern void *D_0012B318;
extern GalleryWork *D_0012B3D8;
extern u32 D_0012B438;
extern u64 D_00180A80[];
extern s8 D_001C0C40[0x100];

extern void func_00100E08(s32, s32);
extern void func_00101FB0(void *, void *, s32);
extern void func_00102AC8(GifPacket *, void *);
extern void func_00102AD8(GifPacket *);
extern void func_00102AE8(GifPacket *);
extern s32 func_00102B40(GifPacket *);
extern void func_00102B58(GifPacket *, u64);
extern void func_00103220(s32);
extern void func_0011D150(void);
extern s32 func_00121720(void);
extern void func_00123480(GifPacket *, s32, s32, s32);
extern void func_00124E50(s32, s32, s32, s32, s32, s32, s32, s32, s32);

s32 func_00121150(void) {
    GifPacket pkt;
    u32 i;
    s32 idx;
    s32 count;
    s32 *params;

    switch (D_0012B3D8->state) {
        case 0:
            D_0012B3D8->unk_50516F = 0;
            D_0012B3D8->unk_50516C = 0;
            D_0012B3D8->timer = 0;
            D_0012B3D8->state++;
        case 1:
            func_0011D150();
            if (D_0012B2F4 == 0) {
                D_0012B3D8->state++;
            }
            break;
        case 2:
            if (func_00121720() != 0) {
                D_0012B3D8->state++;
            }
            break;
        case 3:
            D_0012B3D8->unk_50516C = 9;
            D_0012B3D8->timer = 0;
            D_0012B3D8->state++;
        case 4:
            if (D_0012B3D8->timer >= 0x20) {
                D_0012B3D8->unk_50516C = 0;
                D_0012B3D8->timer = 0;
                D_0012B3D8->state++;
            }
            break;
        case 5:
            D_0012B3D8->state++;
            break;
        case 6:
            D_0012B3D8->box_x0 = 0x38;
            D_0012B3D8->box_x1 = 0x248;
            D_0012B3D8->box_y0 = 0x50;
            D_0012B3D8->box_y1 = 0x130;
            D_0012B3D8->box_color_r = 0x80;
            D_0012B3D8->box_color_g = 0x18;
            D_0012B3D8->box_color_b = 0x80;
            D_0012B3D8->box_color_a = 0x33;
            D_0012B3D8->unk_505164 = 0;
            D_0012B3D8->cursor_color_r = 0x18;
            D_0012B3D8->cursor_color_g = 0xFF;
            D_0012B3D8->cursor_color_b = 0x30;
            D_0012B3D8->cursor_color_a = 0x33;
            D_0012B3D8->unk_50552C = 0x80;

            params = D_0012B3D8->menu_params;
            params[0] = 0;
            params[1] = 6;
            params[2] = -3;
            params[3] = 3;
            params[4] = -1;
            params[5] = 1;
            params[6] = 0;
            params[7] = 0;
            params[8] = 0;
            params[9] = 1;
            params[10] = 0;
            params[11] = 0;

            D_0012B3D8->unk_5057B8[0] = 0;
            D_0012B3D8->unk_5057B8[1] = 0;
            D_0012B3D8->unk_5057B8[2] = 0;
            D_0012B3D8->unk_5057B8[3] = 0;
            D_0012B3D8->unk_5057B8[4] = 0;
            D_0012B3D8->unk_5057B8[5] = 0;

            count = 0;
            for (idx = 0; idx < 0x100; idx++) {
                if (D_001C0C40[idx] != 0) {
                    count++;
                }
            }

            D_0012B3D8->unk_50516F = 1;
            D_0012B3D8->unlocked_count = count;
            D_0012B3D8->selected_index = 0;
            D_0012B3D8->unk_505148 = 1;
            D_0012B3D8->state = 0;
            break;
    }

    if (D_0012B3D8->state < 5) {
        func_00124E50(0, 0, 0x280, 0x1C0, 0, 0, 0, 0x80, 0);
        func_00102AC8(&pkt, D_00180A80);
        func_00102AD8(&pkt);
        func_00102B58(&pkt, 0x1000000000008002ULL);
        func_00102B58(&pkt, 0xE);
        func_00102B58(&pkt, 0x20170606A9441E40ULL);
        func_00102B58(&pkt, 0x6);
        func_00102B58(&pkt, 0);
        func_00102B58(&pkt, 0x14);

        for (i = 0; i < 11; i++) {
            func_00123480(&pkt, 0x180 + i * 16, 0x1A0, D_0012B0B0[i]);
        }

        for (i = 0; i < ((D_0012B438 & 0x7F) >> 5); i++) {
            func_00123480(&pkt, 0x180 + (i + 11) * 16, 0x1A0, '.');
        }

        func_00102AE8(&pkt);
        func_00103220(0);
        func_00101FB0(D_0012B318, D_00180A80, func_00102B40(&pkt));
        func_00100E08(0, 0);

        if (D_0012B3D8->timer < 0x20) {
            D_0012B3D8->timer++;
        }
    }

    return 0;
}
