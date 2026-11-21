#include "common.h"

extern u16 D_0012B2B8;
extern u16 D_0012B2BC;
extern u16 D_0012B2C0;
extern u16 D_0012B2C4;
extern u8 D_0012B2C8;
extern u8 D_0012B2CC;
extern u16 D_0012B2D0;
extern u8 D_0012B380;
extern u8 D_0012B381;

extern void func_0010CCE0(s32 port, s32 slot, u8 *actuatorData);

void func_0011D880(void)
{
    if (D_0012B2D0 == 0) {
        switch (D_0012B2CC) {
            case 0:
                break;
            case 1:
                D_0012B381 = (u8)D_0012B2BC;
                func_0010CCE0(0, 0, &D_0012B380);
                D_0012B2CC++;
                break;
            case 2:
                D_0012B2C4--;
                if (D_0012B2C4 <= 0) {
                    D_0012B2CC++;
                }
                break;
            case 3:
                D_0012B381 = 0;
                func_0010CCE0(0, 0, &D_0012B380);
                D_0012B2CC = 0;
                break;
        }

        switch (D_0012B2C8) {
            case 0:
                break;
            case 1:
                D_0012B381 = (u8)D_0012B2B8;
                func_0010CCE0(1, 0, &D_0012B380);
                D_0012B2C8++;
                break;
            case 2:
                D_0012B2C0--;
                if (D_0012B2C0 <= 0) {
                    D_0012B2C8++;
                }
                break;
            case 3:
                D_0012B381 = 0;
                func_0010CCE0(1, 0, &D_0012B380);
                D_0012B2C8 = 0;
                break;
        }
    }
}
