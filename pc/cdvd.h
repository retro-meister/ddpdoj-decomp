#ifndef DDPDOJ_PC_CDVD_H
#define DDPDOJ_PC_CDVD_H

#include <stdbool.h>

/* Lifecycle calls and the game's CD functions are owned by the game thread. */
bool pc_cdvd_mount(const char *iso_path);
void pc_cdvd_unmount(void);

#endif
