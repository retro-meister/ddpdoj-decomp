/* Small data of the memory card unit, still to be merged into it. */
#include "common.h"

extern u8 D_0028A050[];
extern u8 D_0028A0B0[];
extern u8 D_0028A0D0[];
extern u8 D_0028A0F0[];
extern u8 D_0028A140[];
extern u8 D_0028A190[];
extern u8 D_0028A2C0[];
extern u8 D_0028A2F0[];
extern u8 D_0028A3C0[];
extern u8 D_0028A3F0[];
extern u8 D_0028A480[];
extern u8 D_0028A4A0[];
extern u8 D_0028A4D0[];
extern u8 D_0028A500[];
extern u8 D_0028A570[];
extern u8 D_0028A5E0[];
extern u8 D_0028A610[];
extern u8 D_0028A640[];
extern u8 D_0028A6E0[];
extern u8 D_0028A740[];
extern u8 D_0028A7A0[];
extern u8 D_0028A8D0[];
extern u8 D_0028A8F0[];
extern u8 D_0028A910[];
extern u8 D_0028AA30[];
extern u8 D_0028AAD0[];
extern u8 D_0028AB30[];
extern u8 D_0028AC60[];
extern u8 D_0028AC80[];
extern u8 D_0028ACA0[];
extern u8 D_0028ACC0[];
#ifdef DEATH_LABEL
extern u8 D_00280140[];
extern u8 D_002801A0[];
extern u8 D_002801C0[];
extern u8 D_002801E0[];
extern u8 D_00280230[];
extern u8 D_00280280[];
extern u8 D_002803B0[];
extern u8 D_002803E0[];
extern u8 D_002804B0[];
extern u8 D_002804E0[];
extern u8 D_00280570[];
extern u8 D_00280590[];
extern u8 D_002805C0[];
extern u8 D_002805F0[];
extern u8 D_00280660[];
extern u8 D_002806D0[];
extern u8 D_00280700[];
extern u8 D_00280730[];
extern u8 D_002807D0[];
extern u8 D_00280830[];
extern u8 D_00280890[];
extern u8 D_002809C0[];
extern u8 D_002809E0[];
extern u8 D_00280A00[];
extern u8 D_00280B20[];
extern u8 D_00280BC0[];
extern u8 D_00280C20[];
extern u8 D_00280D50[];
extern u8 D_00280D70[];
extern u8 D_00280D90[];
extern u8 D_00280DB0[];
#endif

struct D0028ddb8Record { void *p0; u16 w1[2]; };
extern struct D0028ddb8Record D_0028DDB8;
extern void *D_0028DDC0[2];
extern void *D_0028DDC8[2];
extern void *D_0028DDD0[1];
extern void *D_0028DDD4[1];
struct D0028ddd8Record { void *p0; u16 w1[2]; };
extern struct D0028ddd8Record D_0028DDD8;
extern void *D_0028DDE0[2];
extern void *D_0028DDE8[1];
extern void *D_0028DDEC[1];
struct D0028ddf0Record { void *p0; u16 w1[2]; };
extern struct D0028ddf0Record D_0028DDF0;
extern void *D_0028DDF8[2];
extern void *D_0028DE00[1];
extern void *D_0028DE04[1];
extern void *D_0028DE08[1];
extern void *D_0028DE0C[1];
extern void *D_0028DE10[1];
extern void *D_0028DE14[1];
extern void *D_0028DE18[1];
extern void *D_0028DE1C[1];
extern void *D_0028DE20[1];
extern void *D_0028DE24[1];
extern void *D_0028DE28[2];
extern void *D_0028DE30[1];
extern void *D_0028DE34[1];
extern void *D_0028DE38[1];
extern void *D_0028DE3C[1];

#ifdef DEATH_LABEL
struct D0028ddb8Record D_0028DDB8 = {
    D_00280140,
    { 0x0000, 0x0000 },
};
#else
struct D0028ddb8Record D_0028DDB8 = {
    D_0028A050,
    { 0x0000, 0x0000 },
};
#endif

#ifdef DEATH_LABEL
void *D_0028DDC0[2] = {
    D_002801A0,
    D_002801C0,
};
#else
void *D_0028DDC0[2] = {
    D_0028A0B0,
    D_0028A0D0,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DDC8[2] = {
    D_002801E0,
    D_00280230,
};
#else
void *D_0028DDC8[2] = {
    D_0028A0F0,
    D_0028A140,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DDD0[1] = {
    D_00280280,
};
#else
void *D_0028DDD0[1] = {
    D_0028A190,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DDD4[1] = {
    D_002803B0,
};
#else
void *D_0028DDD4[1] = {
    D_0028A2C0,
};
#endif

#ifdef DEATH_LABEL
struct D0028ddd8Record D_0028DDD8 = {
    D_002803E0,
    { 0x0000, 0x0000 },
};
#else
struct D0028ddd8Record D_0028DDD8 = {
    D_0028A2F0,
    { 0x0000, 0x0000 },
};
#endif

#ifdef DEATH_LABEL
void *D_0028DDE0[2] = {
    D_002804B0,
    D_002804E0,
};
#else
void *D_0028DDE0[2] = {
    D_0028A3C0,
    D_0028A3F0,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DDE8[1] = {
    D_00280570,
};
#else
void *D_0028DDE8[1] = {
    D_0028A480,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DDEC[1] = {
    D_00280590,
};
#else
void *D_0028DDEC[1] = {
    D_0028A4A0,
};
#endif

#ifdef DEATH_LABEL
struct D0028ddf0Record D_0028DDF0 = {
    D_002805C0,
    { 0x0000, 0x0000 },
};
#else
struct D0028ddf0Record D_0028DDF0 = {
    D_0028A4D0,
    { 0x0000, 0x0000 },
};
#endif

#ifdef DEATH_LABEL
void *D_0028DDF8[2] = {
    D_002805F0,
    D_00280660,
};
#else
void *D_0028DDF8[2] = {
    D_0028A500,
    D_0028A570,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE00[1] = {
    D_002806D0,
};
#else
void *D_0028DE00[1] = {
    D_0028A5E0,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE04[1] = {
    D_00280700,
};
#else
void *D_0028DE04[1] = {
    D_0028A610,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE08[1] = {
    D_00280730,
};
#else
void *D_0028DE08[1] = {
    D_0028A640,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE0C[1] = {
    D_002807D0,
};
#else
void *D_0028DE0C[1] = {
    D_0028A6E0,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE10[1] = {
    D_00280830,
};
#else
void *D_0028DE10[1] = {
    D_0028A740,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE14[1] = {
    D_00280890,
};
#else
void *D_0028DE14[1] = {
    D_0028A7A0,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE18[1] = {
    D_002809C0,
};
#else
void *D_0028DE18[1] = {
    D_0028A8D0,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE1C[1] = {
    D_002809E0,
};
#else
void *D_0028DE1C[1] = {
    D_0028A8F0,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE20[1] = {
    D_00280A00,
};
#else
void *D_0028DE20[1] = {
    D_0028A910,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE24[1] = {
    D_00280B20,
};
#else
void *D_0028DE24[1] = {
    D_0028AA30,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE28[2] = {
    D_00280BC0,
    D_00280C20,
};
#else
void *D_0028DE28[2] = {
    D_0028AAD0,
    D_0028AB30,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE30[1] = {
    D_00280D50,
};
#else
void *D_0028DE30[1] = {
    D_0028AC60,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE34[1] = {
    D_00280D70,
};
#else
void *D_0028DE34[1] = {
    D_0028AC80,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE38[1] = {
    D_00280D90,
};
#else
void *D_0028DE38[1] = {
    D_0028ACA0,
};
#endif

#ifdef DEATH_LABEL
void *D_0028DE3C[1] = {
    D_00280DB0,
};
#else
void *D_0028DE3C[1] = {
    D_0028ACC0,
};
#endif
