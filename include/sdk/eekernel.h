#ifndef DDPDOJ_SDK_EEKERNEL_H
#define DDPDOJ_SDK_EEKERNEL_H

#include "types.h"

void FlushCache(s32 mode);
void LoadExecPS2(const char *filename, s32 argc, char *argv[]);

#endif
