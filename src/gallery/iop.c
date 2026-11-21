#include "gallery/gallery.h"

void iop_reboot_and_load_modules(void)
{
    sceSifInitRpc(0);
    sceCdInit(0);
    sceCdMmode(2);

    do {
    } while (!sceSifRebootIop("cdrom0:\\MODULE\\IOPRP260.IMG;1"));

    do {
    } while (!sceSifSyncIop());

    sceSifInitRpc(0);
    sceCdInit(0);
    sceCdMmode(2);
    sceFsReset();
    sceCdDiskReady(0);
    printf("iop reboot 260!\n");

    do {
    } while (sceSifLoadModule("cdrom0:\\MODULE\\SIO2MAN.IRX;1", 0, 0) < 0);

    do {
    } while (sceSifLoadModule("cdrom0:\\MODULE\\MCMAN.IRX;1", 0, 0) < 0);

    do {
    } while (sceSifLoadModule("cdrom0:\\MODULE\\MCSERV.IRX;1", 0, 0) < 0);

    do {
    } while (sceSifLoadModule("cdrom0:\\MODULE\\PADMAN.IRX;1", 0, 0) < 0);

    do {
    } while (sceSifLoadModule("cdrom0:\\MODULE\\LIBSD.IRX;1", 0, 0) < 0);

    do {
    } while (sceSifLoadModule("cdrom0:\\MODULE\\EZBGM.IRX;1", 0, 0) < 0);

    printf("cd modules ok!\n");
}
