#ifndef DDPDOJ_PC_MEMORY_CARD_H
#define DDPDOJ_PC_MEMORY_CARD_H

#include <stdbool.h>

/* Optional explicit root. Otherwise sceMcInit uses the per-user SDL data directory. */
bool pc_mc_open_storage(const char *root);
bool pc_mc_idle(void);
void pc_mc_close_storage(void);

#endif
