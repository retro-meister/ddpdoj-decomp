#ifndef DDPDOJ_EXPLOSION_SCRIPTS_H
#define DDPDOJ_EXPLOSION_SCRIPTS_H

#include "types.h"

enum {
    EXPLOSION_SET_LOOK = -1,
    EXPLOSION_MOVE = -2,
    EXPLOSION_TIMING_END = 0xFFFF,
};

typedef struct {
    /* 0x00 */ s16 opcode;
    /* 0x02 */ u16 look;
    /* 0x04 */ s16 offset_y;
    /* 0x06 */ s16 offset_x;
} ExplosionSetLook;

typedef struct {
    /* 0x00 */ s16 opcode;
    /* 0x02 */ u16 unused_02;
    /* 0x04 */ s16 delta_y;
    /* 0x06 */ s16 delta_x;
} ExplosionMove;

typedef struct {
    /* 0x00 */ u16 draw;
    /* 0x02 */ u16 sprite;
} ExplosionFrame;

typedef struct {
    /* 0x00 */ ExplosionSetLook set_look;
    /* 0x08 */ ExplosionMove move;
    /* 0x10 */ ExplosionFrame frames[3];
} ExplosionIntro;

struct ExplosionScript12Frames {
    /* 0x00 */ ExplosionSetLook set_look;
    /* 0x08 */ ExplosionFrame frames[12];
    /* 0x38 */ u16 padding[4];
};

struct ExplosionScript15Frames {
    /* 0x00 */ ExplosionSetLook set_look;
    /* 0x08 */ ExplosionMove move;
    /* 0x10 */ ExplosionFrame frames[15];
    /* 0x4C */ u16 padding[2];
};

struct ExplosionScript18Frames {
    /* 0x00 */ ExplosionSetLook set_look;
    /* 0x08 */ ExplosionMove move;
    /* 0x10 */ ExplosionFrame frames[18];
    /* 0x58 */ u16 padding[4];
};

struct ExplosionScript24Frames {
    /* 0x00 */ ExplosionSetLook set_look;
    /* 0x08 */ ExplosionMove move;
    /* 0x10 */ ExplosionFrame frames[24];
};

struct ExplosionScript28Frames {
    /* 0x00 */ ExplosionSetLook set_look;
    /* 0x08 */ ExplosionMove move;
    /* 0x10 */ ExplosionFrame frames[28];
};

struct ExplosionScript32Frames {
    /* 0x00 */ ExplosionSetLook set_look;
    /* 0x08 */ ExplosionMove move;
    /* 0x10 */ ExplosionFrame frames[32];
};

struct ExplosionScript33Frames {
    /* 0x00 */ ExplosionSetLook set_look;
    /* 0x08 */ ExplosionMove move;
    /* 0x10 */ ExplosionFrame frames[33];
    /* 0x94 */ u16 padding[6];
};

struct ExplosionScript35Frames {
    /* 0x00 */ ExplosionSetLook set_look;
    /* 0x08 */ ExplosionMove move;
    /* 0x10 */ ExplosionFrame frames[35];
    /* 0x9C */ u16 padding[2];
};

struct ExplosionScript36Frames {
    /* 0x00 */ ExplosionSetLook set_look;
    /* 0x08 */ ExplosionMove move;
    /* 0x10 */ ExplosionFrame frames[36];
};

struct ExplosionTwoPhaseScript12Frames {
    /* 0x00 */ ExplosionIntro intro;
    /* 0x1C */ ExplosionSetLook set_look;
    /* 0x24 */ ExplosionMove move;
    /* 0x2C */ ExplosionFrame frames[12];
    /* 0x5C */ u16 padding[2];
};

struct ExplosionTwoPhaseScript24Frames {
    /* 0x00 */ ExplosionIntro intro;
    /* 0x1C */ ExplosionSetLook set_look;
    /* 0x24 */ ExplosionMove move;
    /* 0x2C */ ExplosionFrame frames[24];
    /* 0x8C */ u16 padding[2];
};

struct ExplosionTwoPhaseScript28Frames {
    /* 0x00 */ ExplosionIntro intro;
    /* 0x1C */ ExplosionSetLook set_look;
    /* 0x24 */ ExplosionMove move;
    /* 0x2C */ ExplosionFrame frames[28];
    /* 0x9C */ u16 padding[2];
};

struct ExplosionTwoPhaseScript32Frames {
    /* 0x00 */ ExplosionIntro intro;
    /* 0x1C */ ExplosionSetLook set_look;
    /* 0x24 */ ExplosionMove move;
    /* 0x2C */ ExplosionFrame frames[32];
    /* 0xAC */ u16 padding[2];
};

struct ExplosionLifetimeTable {
    u16 timings[16];
    void (*draw[5])(void);
    u16 padding[6];
};

extern struct ExplosionLifetimeTable explosion_scripts_33;

typedef struct {
    /* 0x00 */ u16 frames[2];
    /* 0x04 */ u16 timings[2];
} ExplosionScriptEntry;

extern ExplosionScriptEntry explosion_scripts[34];
extern ExplosionScriptEntry explosion_scripts_b[34];

extern struct ExplosionScript12Frames explosion_script_00;
extern u16 explosion_timings_00[16];
extern struct ExplosionScript12Frames explosion_script_02;
extern u16 explosion_timings_02[16];
extern struct ExplosionScript12Frames explosion_script_04;
extern u16 explosion_timings_04[16];
extern struct ExplosionScript24Frames explosion_script_06;
extern u16 explosion_timings_06[32];
extern struct ExplosionScript28Frames explosion_script_08;
extern u16 explosion_timings_08[32];
extern struct ExplosionScript32Frames explosion_script_10;
extern u16 explosion_timings_10[40];
extern struct ExplosionScript24Frames explosion_script_12;
extern u16 explosion_timings_12[32];
extern struct ExplosionScript32Frames explosion_script_14;
extern u16 explosion_timings_14[40];
extern struct ExplosionScript28Frames explosion_script_16;
extern u16 explosion_timings_16[32];
extern struct ExplosionScript33Frames explosion_script_18;
extern u16 explosion_timings_18[40];
extern struct ExplosionScript18Frames explosion_scripts_20;
extern u16 explosion_timings_20[24];
extern struct ExplosionTwoPhaseScript32Frames explosion_scripts_22;
extern u16 explosion_timings_22[40];
extern struct ExplosionTwoPhaseScript28Frames explosion_scripts_24;
extern u16 explosion_timings_24[32];
extern struct ExplosionScript36Frames explosion_scripts_26;
extern u16 explosion_timings_26[40];
extern struct ExplosionScript12Frames explosion_scripts_28;
extern u16 explosion_timings_28[16];
extern struct ExplosionTwoPhaseScript24Frames explosion_scripts_30;
extern u16 explosion_timings_30[32];
extern struct ExplosionScript15Frames explosion_scripts_32;
extern struct ExplosionTwoPhaseScript12Frames explosion_script_b_00;
extern u16 explosion_timings_b_00[16];
extern struct ExplosionTwoPhaseScript12Frames explosion_script_b_02;
extern u16 explosion_timings_b_02[16];
extern struct ExplosionTwoPhaseScript12Frames explosion_script_b_04;
extern u16 explosion_timings_b_04[16];
extern struct ExplosionTwoPhaseScript24Frames explosion_script_b_06;
extern u16 explosion_timings_b_06[32];
extern struct ExplosionTwoPhaseScript28Frames explosion_script_b_08;
extern u16 explosion_timings_b_08[32];
extern struct ExplosionScript35Frames explosion_script_b_10;
extern u16 explosion_timings_b_10[40];

#endif
