/* Tables of the stage 2 scenery. */
#include "common.h"

void stage1_scenery_00_setup();
void stage1_scenery_01_setup();
void stage1_scenery_02_setup();
void stage1_scenery_03_setup();
void stage1_scenery_04_setup();
void stage1_scenery_05_setup();
void stage1_scenery_06_setup();
void stage1_scenery_07_setup();
void stage1_scenery_08_setup();
void stage1_scenery_09_setup();
void stage1_scenery_10_setup();
void stage1_scenery_11_setup();
void stage1_scenery_12_setup();
void stage2_scenery_00_setup();
void stage2_scenery_01_setup();
void stage2_scenery_02_setup();
void stage2_scenery_02_setup_alt();
void stage2_scenery_03_setup();
void stage2_scenery_03_setup_alt();
void stage2_scenery_04_setup();
void stage2_scenery_05_setup();
void stage3_scenery_00_setup();
void stage3_scenery_01_setup();
void stage3_scenery_02_setup();
void stage3_scenery_03_setup();
void stage3_scenery_04_setup();
void stage3_scenery_05_setup();
void stage3_scenery_06_setup();
void stage3_scenery_07_setup();
void stage3_scenery_08_setup();
void stage3_scenery_09_setup();
void stage3_scenery_10_setup();
void stage3_scenery_11_setup();
void stage3_scenery_12_setup();
void stage3_scenery_13_setup();
void stage4_scenery_00_setup();
void stage4_scenery_00_setup_alt();
void stage4_scenery_01_setup();
void stage4_scenery_02_setup();
void stage4_scenery_03_setup();
void stage4_scenery_04_setup();
void stage4_scenery_05_setup();
void stage5_scenery_00_setup();
void stage5_scenery_01_setup();
void stage5_scenery_02_setup();
void stage5_scenery_03_setup();

struct GStage2Scenery05FramesRecord { u16 w0[128]; void *p1; void *p2; void *p3; void *p4; void *p5; void *p6; void *p7; void *p8; void *p9; void *p10; void *p11; void *p12; void *p13; u16 w14[6]; void *p15; void *p16; void *p17; void *p18; void *p19; void *p20; void *p21; void *p22; void *p23; void *p24; void *p25; void *p26; void *p27; void *p28; void *p29; void *p30; void *p31; void *p32; void *p33; void *p34; void *p35; void *p36; u16 w37[4]; void *p38; void *p39; void *p40; void *p41; void *p42; void *p43; void *p44; u16 w45[2]; void *p46; void *p47; void *p48; void *p49; };
extern struct GStage2Scenery05FramesRecord g_stage2_scenery_05_frames;

struct GStage2Scenery05FramesRecord g_stage2_scenery_05_frames = {
    { 0x0000, 0x1BC6, 0x0000, 0x1BE6, 0x0000, 0x1BC6, 0x0000, 0x1BE5, 0x0000, 0x1BC6, 0x0000, 0x1BE4, 0x0000, 0x1BC6, 0x0000, 0x1BE3, 0x0000, 0x1BC6, 0x0000, 0x1BE2, 0x0000, 0x1BC6, 0x0000, 0x1BE1, 0x0000, 0x1BC6, 0x0000, 0x1BE0, 0x0000, 0x1BC6, 0x0000, 0x1BDF, 0x0000, 0x1BC6, 0x0000, 0x1BDE, 0x0000, 0x1BC6, 0x0000, 0x1BDD, 0x0000, 0x1BC6, 0x0000, 0x1BDC, 0x0000, 0x1BC6, 0x0000, 0x1BDB, 0x0000, 0x1BC6, 0x0000, 0x1BDA, 0x0000, 0x1BC6, 0x0000, 0x1BD9, 0x0000, 0x1BC6, 0x0000, 0x1BD8, 0x0000, 0x1BC6, 0x0000, 0x1BD7, 0x0000, 0x1BC6, 0x0000, 0x1BD6, 0x0000, 0x1BC5, 0x0000, 0x1BD5, 0x0000, 0x1BC4, 0x0000, 0x1BD4, 0x0000, 0x1BC3, 0x0000, 0x1BD3, 0x0000, 0x1BC2, 0x0000, 0x1BD2, 0x0000, 0x1BC1, 0x0000, 0x1BD1, 0x0000, 0x1BC0, 0x0000, 0x1BD0, 0x0000, 0x1BBF, 0x0000, 0x1BCF, 0x0000, 0x1BBE, 0x0000, 0x1BCE, 0x0000, 0x1BBD, 0x0000, 0x1BCD, 0x0000, 0x1BBC, 0x0000, 0x1BCC, 0x0000, 0x1BBB, 0x0000, 0x1BCB, 0x0000, 0x1BBA, 0x0000, 0x1BCA, 0x0000, 0x1BB9, 0x0000, 0x1BC9, 0x0000, 0x1BB8, 0x0000, 0x1BC8, 0x0000, 0x1BB7, 0x0000, 0x1BC7 },
    stage1_scenery_00_setup,
    stage1_scenery_01_setup,
    stage1_scenery_02_setup,
    stage1_scenery_03_setup,
    stage1_scenery_04_setup,
    stage1_scenery_05_setup,
    stage1_scenery_06_setup,
    stage1_scenery_07_setup,
    stage1_scenery_08_setup,
    stage1_scenery_09_setup,
    stage1_scenery_10_setup,
    stage1_scenery_11_setup,
    stage1_scenery_12_setup,
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
    stage2_scenery_00_setup,
    stage2_scenery_01_setup,
    stage2_scenery_02_setup,
    stage2_scenery_03_setup,
    stage2_scenery_02_setup_alt,
    stage2_scenery_03_setup_alt,
    stage2_scenery_04_setup,
    stage2_scenery_05_setup,
    stage3_scenery_00_setup,
    stage3_scenery_01_setup,
    stage3_scenery_02_setup,
    stage3_scenery_03_setup,
    stage3_scenery_04_setup,
    stage3_scenery_05_setup,
    stage3_scenery_06_setup,
    stage3_scenery_07_setup,
    stage3_scenery_08_setup,
    stage3_scenery_09_setup,
    stage3_scenery_10_setup,
    stage3_scenery_11_setup,
    stage3_scenery_12_setup,
    stage3_scenery_13_setup,
    { 0x0000, 0x0000, 0x0000, 0x0000 },
    stage4_scenery_00_setup,
    stage4_scenery_01_setup,
    stage4_scenery_02_setup,
    stage4_scenery_03_setup,
    stage4_scenery_04_setup,
    stage4_scenery_05_setup,
    stage4_scenery_00_setup_alt,
    { 0x0000, 0x0000 },
    stage5_scenery_00_setup,
    stage5_scenery_01_setup,
    stage5_scenery_02_setup,
    stage5_scenery_03_setup,
};
