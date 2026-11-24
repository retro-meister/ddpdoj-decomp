#include "common.h"

s32 sprintf(char *buf, const char *format, ...);
extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
extern s32 D_00271D60[];
extern s32 D_00271F40[];
extern char D_0028BCB8[];
extern char D_0028BCC8[];
extern s32 D_0028DE24;
extern s32 D_0028DE28;
extern s32 D_0028E9F8;
extern u8 D_0028ECE8;
extern s32 D_0028ED10;
extern s32 D_0028ED1C;

void func_00234460(s32 arg0) {
    func_0022C5E0(160, D_0028DE24, 0, 20, 14, D_0028ED10, 100);
    func_0022C5E0(220, D_00271F40[arg0], 0, 20, 14, D_0028ED10, 100);
    func_0022C5E0(260, (&D_0028DE28)[D_0028ECE8], 0, 20, 14, D_0028ED10, 100);
    if (arg0 == 0) {
        sprintf((char *)D_0028E9F8, D_0028BCB8, D_00271D60[D_0028ED1C * 2]);
    } else {
        sprintf((char *)D_0028E9F8, D_0028BCC8, D_00271D60[D_0028ED1C * 2]);
    }
    func_0022C5E0(300, D_0028E9F8, 0, 20, 14, D_0028ED10, 100);
}
