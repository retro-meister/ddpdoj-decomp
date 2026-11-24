#include "common.h"

s32 func_0016A710();                            /* extern */
s32 text_queue_clear();                            /* extern */
s32 func_00216980();                            /* extern */
s32 func_0021A920(s32 *, s32 *);        /* extern */
s32 func_0021B400(s32 *);                   /* extern */
s32 func_0021B680();                            /* extern */
s32 func_0021DF60();                            /* extern */
s32 sceGsSwapDBuffDc(s32 *, s32);           /* extern */
extern s32 D_0028DC98;
extern s8 D_0028E9EC;
extern s32 D_0028E9F0;
extern s32 g_gif_buf[];
extern s32 D_0057C7E0[];
extern s32 D_00586FF0[];

void func_00216570(void) {
    *(s32 *)0x10000000 = 0;
    sceGsSwapDBuffDc(D_0057C7E0, D_0028E9F0);
    text_queue_clear();
    func_00216980();
    func_0016A710();
    if (D_0028E9EC != 0) {
        D_0028E9EC = 0;
        func_0021DF60();
        func_0021B680();
    }
    if (D_0028DC98 < 2) {
        func_0021B400(g_gif_buf);
        return;
    }
    func_0021A920(D_00586FF0, g_gif_buf);
}
