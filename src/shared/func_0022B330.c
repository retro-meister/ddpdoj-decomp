#include "common.h"

extern void *memcpy(void *dst, const void *src, u32 n);
extern s32 printf(const char *format, ...);
extern void func_0021D410(u8 *buf);
extern void func_0023DBF0(void *data);
extern char D_00289E50[];
extern char D_00289E70[];
extern char D_00289E90[];
extern char D_00289EB0[];
extern char D_00289ED0[];
extern char D_00289EF0[];
extern u8 D_0028ED30[8];
extern u16 D_0028ED40;
extern s32 D_0028ED44;
extern u16 D_0028ED48;
extern u16 D_0028ED4C;
extern s32 D_0028ED50;
extern u16 D_0028ED54;
extern u8 D_0028ED68;
extern u8 D_006A4800[];
extern u8 D_006A4C00[];
extern u8 D_006C58A0[];

typedef struct {
    u8 pad0000[0x327C];
    s32 score1;
    s32 score2;
    u8 pad3284[4];
    u16 stage1;
    u16 stage2;
    u16 pad328C;
    u16 count1;
    u16 pad3290;
    u16 count2;
} SaveBody;

void func_0022B330(void) {
    s32 count;
    s32 i;
    SaveBody *data;

    count = 0;
    for (i = 0; i < 6; i++) {
        if (D_0028ED30[i] == D_006A4800[0x38 + i]) {
            count++;
        }
    }
    if (count == 6) {
        data = (SaveBody *)D_006A4C00;
        func_0021D410((u8 *)data);
        func_0023DBF0(D_006A4800);
        printf(D_00289E50, D_0028ED50, data->score1);
        printf(D_00289E70, D_0028ED54, data->count1);
        printf(D_00289E90, D_0028ED4C, data->stage1);
        printf(D_00289EB0, D_0028ED44, data->score2);
        printf(D_00289ED0, D_0028ED48, data->count2);
        printf(D_00289EF0, D_0028ED40, data->stage2);
        if (D_0028ED54 == data->count1 && D_0028ED50 == data->score1 &&
            D_0028ED4C == data->stage1 && D_0028ED48 == data->count2 &&
            D_0028ED44 == data->score2 && D_0028ED40 == data->stage2) {
            memcpy(D_006C58A0, D_006A4800, 0x202E8);
            D_0028ED68 = 1;
        }
    }
}
