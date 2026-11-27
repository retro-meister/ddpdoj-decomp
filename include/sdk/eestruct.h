#ifndef DDPDOJ_SDK_EESTRUCT_H
#define DDPDOJ_SDK_EESTRUCT_H

#include "types.h"

/* GIF tag modes and register descriptors */
#define SCE_GIF_PACKED    0
#define SCE_GIF_REGLIST   1
#define SCE_GIF_IMAGE     2
#define SCE_GIF_PACKED_AD 0x0EULL

#define SCE_GIF_SET_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop) << 15) | ((u64)(pre) << 46) | \
     ((u64)(prim) << 47) | ((u64)(flg) << 58) | ((u64)(nreg) << 60))

/* GS primitive types */
#define SCE_GS_PRIM_LINE     0x01
#define SCE_GS_PRIM_TRISTRIP 0x04
#define SCE_GS_PRIM_TRIFAN   0x05
#define SCE_GS_PRIM_SPRITE   0x06

/* GS privileged / general purpose register addresses */
#define SCE_GS_PRIM       0x00ULL
#define SCE_GS_RGBAQ      0x01ULL
#define SCE_GS_UV         0x03ULL
#define SCE_GS_XYZ2       0x05ULL
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
#define SCE_GS_PSMZ24     0x31

/* EE Hardware Timer 0 registers (eeregs.h) */
#define T0_COUNT          ((volatile u32 *)0x10000000)
#define T0_MODE           ((volatile u32 *)0x10000010)

/* GS register bit-packing macros */
#define SCE_GS_SET_PRIM(prim, iip, tme, fge, abe, aa1, fst, ctxt, fix) \
    ((u64)(prim)        | ((u64)(iip) << 3)  | ((u64)(tme) << 4) | \
     ((u64)(fge) << 5)  | ((u64)(abe) << 6)  | ((u64)(aa1) << 7) | \
     ((u64)(fst) << 8)  | ((u64)(ctxt) << 9) | ((u64)(fix) << 10))

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

#define SCE_GS_SET_TEX1(lcm, mxl, mmag, mmin, mtba, l, k) \
    ((u64)(lcm)        | ((u64)(mxl) << 2)  | ((u64)(mmag) << 5) | \
     ((u64)(mmin) << 6)| ((u64)(mtba) << 9) | ((u64)(l) << 19)   | ((u64)(k) << 32))

#define SCE_GS_SET_TEXA(ta0, aem, ta1) \
    ((u64)(ta0) | ((u64)(aem) << 15) | ((u64)(ta1) << 32))

#define SCE_GS_SET_ALPHA(a, b, c, d, fix) \
    ((u64)(a) | ((u64)(b) << 2) | ((u64)(c) << 4) | ((u64)(d) << 6) | ((u64)(fix) << 32))

#define SCE_GS_SET_TEST(ate, atst, aref, afail, date, datm, zte, ztst) \
    ((u64)(ate)         | ((u64)(atst) << 1) | ((u64)(aref) << 4)  | ((u64)(afail) << 12) | \
     ((u64)(date) << 14)| ((u64)(datm) << 15)| ((u64)(zte) << 16)  | ((u64)(ztst) << 17))

#define SCE_GS_SET_ZBUF(zbp, psm, zmsk) \
    ((u64)(zbp) | ((u64)(psm) << 24) | ((u64)(zmsk) << 32))

/* 16-bit PS2 CLUT color helpers (ABGR1555) */
#define RGB555(r, g, b) \
    ((s16)(((b) << 10) | ((g) << 5) | (r)))

#define RGBA5551(r, g, b, a) \
    ((s16)(((a) << 15) | ((b) << 10) | ((g) << 5) | (r)))

#endif
