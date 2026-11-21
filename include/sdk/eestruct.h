#ifndef DDPDOJ_SDK_EESTRUCT_H
#define DDPDOJ_SDK_EESTRUCT_H

#include "types.h"

/* GIF tag register descriptors */
#define SCE_GIF_PACKED_AD 0x0EULL

/* GS privileged / general purpose register addresses */
#define SCE_GS_TEX0_1     0x06ULL
#define SCE_GS_CLAMP_1    0x08ULL
#define SCE_GS_TEX1_1     0x14ULL
#define SCE_GS_TEXA       0x3BULL
#define SCE_GS_TEXFLUSH   0x3FULL
#define SCE_GS_ALPHA_1    0x42ULL
#define SCE_GS_TEST_1     0x47ULL
#define SCE_GS_ZBUF_1     0x4EULL

/* GS Pixel Storage Modes (PSM) */
#define SCE_GS_PSMCT32    0x00
#define SCE_GS_PSMCT24    0x01
#define SCE_GS_PSMCT16    0x02
#define SCE_GS_PSMT8      0x13
#define SCE_GS_PSMT4      0x14

/* GS register bit-packing macros */
#define SCE_GS_SET_RGBAQ(r, g, b, a, q) \
    ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))

#define SCE_GS_SET_UV(u, v) \
    ((u64)(u) | ((u64)(v) << 16))

#define SCE_GS_SET_XYZ2(x, y, z) \
    ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))

#define SCE_GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp)         | ((u64)(tbw) << 14) | ((u64)(psm) << 20)  | ((u64)(tw) << 26) | \
     ((u64)(th) << 30)  | ((u64)(tcc) << 34) | ((u64)(tfx) << 35)  | ((u64)(cbp) << 37) | \
     ((u64)(cpsm) << 51)| ((u64)(csm) << 55) | ((u64)(csa) << 56)  | ((u64)(cld) << 61))

/* 16-bit PS2 CLUT color helpers (ABGR1555) */
#define RGB555(r, g, b) \
    ((s16)(((b) << 10) | ((g) << 5) | (r)))

#define RGBA5551(r, g, b, a) \
    ((s16)(((a) << 15) | ((b) << 10) | ((g) << 5) | (r)))

#endif
