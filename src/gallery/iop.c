#include "gallery/gallery.h"

extern const char D_0012AE30[];
extern const char D_0012AE50[];
extern const char D_0012AE70[];
extern const char D_0012AE90[];
extern const char D_0012AEB0[];
extern const char D_0012AED0[];
extern const char D_0012AEF0[];
extern const char D_0012AF10[];
extern const char D_0012AF30[];

void iop_reboot_and_load_modules(void)
{
    sceSifInitRpc(0);
    sceCdInit(0);
    sceCdMmode(2);

    do {
    } while (!sceSifRebootIop(D_0012AE30));

    do {
    } while (!sceSifSyncIop());

    sceSifInitRpc(0);
    sceCdInit(0);
    sceCdMmode(2);
    sceFsReset();
    sceCdDiskReady(0);
    printf(D_0012AE50);

    do {
    } while (sceSifLoadModule(D_0012AE70, 0, 0) < 0);

    do {
    } while (sceSifLoadModule(D_0012AE90, 0, 0) < 0);

    do {
    } while (sceSifLoadModule(D_0012AEB0, 0, 0) < 0);

    do {
    } while (sceSifLoadModule(D_0012AED0, 0, 0) < 0);

    do {
    } while (sceSifLoadModule(D_0012AEF0, 0, 0) < 0);

    do {
    } while (sceSifLoadModule(D_0012AF10, 0, 0) < 0);

    printf(D_0012AF30);
}
