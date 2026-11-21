#include "common.h"

extern u16 D_0012B2D0;
extern s32 D_0012B2E0;
extern s32 D_0012B2E4;
extern u8 D_00132850[0x30];
extern s32 D_00132880[16];
extern s32 D_00132884[];

extern s32 func_001060F8(void *client, s32 command, s32 mode,
                        void *sendBuffer, s32 sendSize, void *receiveBuffer,
                        s32 receiveSize, void (*callback)(void *),
                        void *callbackData);

void func_0011AFD0(s32 selection)
{
    s32 adjustedValue;
    s32 requestIndex;

    if (D_0012B2D0 == 0) {
        requestIndex = selection;
        if (selection != 0) {
            requestIndex--;
        }

        adjustedValue = D_0012B2E0;
        adjustedValue -= 30;
        if (adjustedValue < 0) {
            adjustedValue = 0;
        }

        if (selection == 2 || selection == 10 || selection == 18 ||
            selection == 45 || selection == 50 || selection == 37) {
            requestIndex |= 0x80;
        }

        D_00132880[0] = requestIndex;
        D_00132884[0] = adjustedValue;
        func_001060F8(D_00132850, 0x500, 0, D_00132880, 0x10,
                      D_00132880, 0x40, 0, 0);
        D_0012B2E4 = D_00132880[0];
    }
}
