/* The scroll events of the stages: what happens when the scroll reaches a line. */
#include "common.h"
#include "scroll_events.h"

#include "scenery.h"

void stage1_scenery_00_setup(void);
void stage1_scenery_01_setup(void);
void stage1_scenery_02_setup(void);
void stage1_scenery_03_setup(void);
void stage1_scenery_04_setup(void);
void stage1_scenery_05_setup(void);
void stage1_scenery_06_setup(void);
void stage1_scenery_07_setup(void);
void stage1_scenery_08_setup(void);
void stage1_scenery_09_setup(void);
void stage1_scenery_10_setup(void);
void stage1_scenery_11_setup(void);
void stage1_scenery_12_setup(void);
void stage2_scenery_00_setup(void);
void stage2_scenery_01_setup(void);
void stage2_scenery_02_setup(void);
void stage2_scenery_02_setup_alt(void);
void stage2_scenery_03_setup(void);
void stage2_scenery_03_setup_alt(void);
void stage2_scenery_04_setup(void);
void stage2_scenery_05_setup(void);
void stage3_scenery_00_setup(void);
void stage3_scenery_01_setup(void);
void stage3_scenery_02_setup(void);
void stage3_scenery_03_setup(void);
void stage3_scenery_04_setup(void);
void stage3_scenery_05_setup(void);
void stage3_scenery_06_setup(void);
void stage3_scenery_07_setup(void);
void stage3_scenery_08_setup(void);
void stage3_scenery_09_setup(void);
void stage3_scenery_10_setup(void);
void stage3_scenery_11_setup(void);
void stage3_scenery_12_setup(void);
void stage3_scenery_13_setup(void);
void stage4_scenery_00_setup(void);
void stage4_scenery_00_setup_alt(void);
void stage4_scenery_01_setup(void);
void stage4_scenery_02_setup(void);
void stage4_scenery_03_setup(void);
void stage4_scenery_04_setup(void);
void stage4_scenery_05_setup(void);
void stage5_scenery_00_setup(void);
void stage5_scenery_01_setup(void);
void stage5_scenery_02_setup(void);
void stage5_scenery_03_setup(void);

/*
 * By stage: the set-up routines of the stage's scenery pieces. The number in SCROLL_SCENERY picks one.
 */
ScenerySetup stage1_scenery_setups[13] = {
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
};

ScenerySetup stage2_scenery_setups[8] = {
    stage2_scenery_00_setup,
    stage2_scenery_01_setup,
    stage2_scenery_02_setup,
    stage2_scenery_03_setup,
    stage2_scenery_02_setup_alt,
    stage2_scenery_03_setup_alt,
    stage2_scenery_04_setup,
    stage2_scenery_05_setup,
};

ScenerySetup stage3_scenery_setups[14] = {
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
};

ScenerySetup stage4_scenery_setups[7] = {
    stage4_scenery_00_setup,
    stage4_scenery_01_setup,
    stage4_scenery_02_setup,
    stage4_scenery_03_setup,
    stage4_scenery_04_setup,
    stage4_scenery_05_setup,
    stage4_scenery_00_setup_alt,
};

ScenerySetup stage5_scenery_setups[4] = {
    stage5_scenery_00_setup,
    stage5_scenery_01_setup,
    stage5_scenery_02_setup,
    stage5_scenery_03_setup,
};

ScenerySetup *stage_scenery_setups[5] = {
    stage1_scenery_setups,
    stage2_scenery_setups,
    stage3_scenery_setups,
    stage4_scenery_setups,
    stage5_scenery_setups,
};

/* The tables up to the stages' own hold pointer slots: the start-up routine checks the numbers and puts the addresses in. */
/* The routines of the events, by event number: scroll_event_palettes, _map_loop, _speed, _line_hold, _object, _sounds, _flags. */
u16 scroll_event_routines[14] = { POINTER_SLOT(0), POINTER_SLOT(2), POINTER_SLOT(4), POINTER_SLOT(6), POINTER_SLOT(8), POINTER_SLOT(10), POINTER_SLOT(12) };

/* The routines of the sound commands: scroll_sound_call, _music_stop, _music_fade. */
u16 scroll_sound_routines[6] = { POINTER_SLOT(0), POINTER_SLOT(2), POINTER_SLOT(4) };

/* By stage: the 32 palettes of the map, and the map. */
u16 stage_map_palettes[10] = { POINTER_SLOT(0), POINTER_SLOT(2), POINTER_SLOT(4), POINTER_SLOT(6), POINTER_SLOT(8) };

u16 stage_maps[10] = { POINTER_SLOT(0), POINTER_SLOT(2), POINTER_SLOT(4), POINTER_SLOT(6), POINTER_SLOT(8) };

/* By stage: the stage's two lists of events. */
u16 stage_scroll_event_lists[10] = { POINTER_SLOT(0), POINTER_SLOT(2), POINTER_SLOT(4), POINTER_SLOT(6), POINTER_SLOT(8) };

/* Stage 1. The palettes its events load, in the order they are loaded: slot of the palette's address, palette number. */
u16 stage1_scroll_palettes[68] = {
    SCROLL_PALETTE(0, 10),
    SCROLL_PALETTE(3, 11),
    SCROLL_PALETTE(6, 12),
    SCROLL_PALETTE(9, 13),
    SCROLL_PALETTE(12, 14),
    SCROLL_PALETTE(15, 15),
    SCROLL_PALETTE(18, 24),
    SCROLL_PALETTE(21, 25),
    SCROLL_PALETTE(24, 26),
    SCROLL_PALETTE(27, 27),
    SCROLL_PALETTE(30, 28),
    SCROLL_PALETTE(33, 30),
    SCROLL_PALETTE(36, 29),
    SCROLL_PALETTE(39, 31),
    SCROLL_PALETTE(42, 19),
    SCROLL_PALETTE(45, 20),
    SCROLL_PALETTE(48, 21),
    SCROLL_PALETTE(51, 22),
    SCROLL_PALETTE(54, 18),
    SCROLL_PALETTE(57, 15),
    SCROLL_PALETTE(60, 19),
    SCROLL_PALETTE(63, 20),
    SCROLL_PALETTES_END,
};

u16 stage1_scroll_sounds[7] = {
    SCROLL_SOUND_MUSIC_FADE(0),
    SCROLL_SOUND_CALL(0, 4),
    SCROLL_SOUNDS_END,
};

u16 stage1_scroll_events[197] = {
    POINTER_SLOT(0), /* stage1_scroll_palettes */
    POINTER_SLOT(2), /* stage1_scroll_sounds */
    SCROLL_SPEED(0, 0x200),
    SCROLL_MAP_LOOP(52, -28, 28, 2),
    SCROLL_LINE_HOLD(52),
    SCROLL_PALETTES(56, 6),
    SCROLL_PALETTES(57, 8),
    SCROLL_PALETTES(58, 4),
    SCROLL_SPEED(60, 0x1C0),
    SCROLL_SPEED(68, 0x180),
    SCROLL_SPEED(76, 0x140),
    SCROLL_SPEED(84, 0x100),
    SCROLL_SPEED(92, 0x0C0),
    SCROLL_SPEED(96, 0x080),
    SCROLL_SPEED(104, 0x040),
    SCROLL_SCENERY(144, 12, 0x7000, 0x0C00),
    SCROLL_SCENERY(146, 1, 0x7000, 0x0000),
    SCROLL_SPEED(152, 0x020),
    SCROLL_SCENERY(158, 2, 0x7000, 0x2400),
    SCROLL_SCENERY(192, 0, 0x7000, 0x0A00),
    SCROLL_PALETTES(224, 1),
    SCROLL_SPEED(229, 0x010),
    SCROLL_SPEED(231, 0x008),
    SCROLL_SCENERY(238, 3, 0x7000, 0x0000),
    SCROLL_SPEED(240, 0x020),
    SCROLL_SCENERY(254, 5, 0x7000, 0x3000),
    SCROLL_PALETTES(275, 1),
    SCROLL_SCENERY(276, 4, 0x7000, 0x0000),
    SCROLL_SCENERY(294, 6, 0x7000, 0x1800),
    SCROLL_PALETTES(320, 2),
    SCROLL_SCENERY(326, 8, 0x7000, 0x0000),
    SCROLL_SCENERY(334, 7, 0x7000, 0x3000),
    SCROLL_SCENERY(368, 9, 0x7000, 0x0000),
    SCROLL_SCENERY(396, 10, 0x7000, 0x2800),
    SCROLL_SCENERY(429, 11, 0x7000, 0x0000),
    SCROLL_SOUNDS(474, 1),
    SCROLL_SPEED(484, 0x040),
    SCROLL_SPEED(488, 0x080),
    SCROLL_SOUNDS(498, 1),
    SCROLL_SPEED(504, 0x0C0),
    SCROLL_SPEED(536, 0x100),
    SCROLL_MAP_LOOP(836, -14, 14, -1),
    SCROLL_LINE_HOLD(836),
    SCROLL_EVENTS_END,
};

/* The second plane. */
u16 stage1_plane2_scroll_events[69] = {
    0, 0, 0, 0,
    SCROLL_SPEED(0, 0x200),
    SCROLL_SPEED(60, 0x1C0),
    SCROLL_SPEED(68, 0x180),
    SCROLL_SPEED(76, 0x140),
    SCROLL_SPEED(84, 0x100),
    SCROLL_SPEED(92, 0x0C0),
    SCROLL_SPEED(96, 0x080),
    SCROLL_SPEED(104, 0x040),
    SCROLL_SPEED(152, 0x020),
    SCROLL_SPEED(229, 0x010),
    SCROLL_SPEED(231, 0x008),
    SCROLL_SPEED(240, 0x020),
    SCROLL_SPEED(484, 0x040),
    SCROLL_SPEED(488, 0x080),
    SCROLL_SPEED(504, 0x0C0),
    SCROLL_SPEED(536, 0x100),
    SCROLL_EVENTS_END,
};

/* Stage 2. The palettes its events load, in the order they are loaded: slot of the palette's address, palette number. */
u16 stage2_scroll_palettes[80] = {
    SCROLL_PALETTE(0, 24),
    SCROLL_PALETTE(3, 25),
    SCROLL_PALETTE(6, 26),
    SCROLL_PALETTE(9, 27),
    SCROLL_PALETTE(12, 28),
    SCROLL_PALETTE(15, 30),
    SCROLL_PALETTE(18, 29),
    SCROLL_PALETTE(21, 31),
    SCROLL_PALETTE(24, 10),
    SCROLL_PALETTE(27, 11),
    SCROLL_PALETTE(30, 12),
    SCROLL_PALETTE(33, 13),
    SCROLL_PALETTE(36, 14),
    SCROLL_PALETTE(39, 15),
    SCROLL_PALETTE(42, 16),
    SCROLL_PALETTE(45, 17),
    SCROLL_PALETTE(48, 18),
    SCROLL_PALETTE(51, 19),
    SCROLL_PALETTE(54, 20),
    SCROLL_PALETTE(57, 21),
    SCROLL_PALETTE(60, 17),
    SCROLL_PALETTE(63, 17),
    SCROLL_PALETTE(66, 18),
    SCROLL_PALETTE(69, 19),
    SCROLL_PALETTE(72, 20),
    SCROLL_PALETTE(75, 21),
    SCROLL_PALETTES_END,
};

u16 stage2_scroll_sounds[11] = {
    SCROLL_SOUND_CALL(40, 2),
    SCROLL_SOUND_MUSIC_FADE(0),
    SCROLL_SOUND_CALL(0, 8),
    SCROLL_SOUNDS_END,
};

u16 stage2_scroll_events[98] = {
    POINTER_SLOT(0), /* stage2_scroll_palettes */
    POINTER_SLOT(2), /* stage2_scroll_sounds */
    SCROLL_PALETTES(0, 20),
    SCROLL_SOUNDS(0, 1),
    SCROLL_SCENERY(36, 0, 0x7000, 0x0000),
    SCROLL_SCENERY(145, 6, 0x7000, 0x4000),
    SCROLL_PALETTES(202, 1),
    SCROLL_SCENERY(224, 1, 0x7000, 0x0000),
    SCROLL_PALETTES(310, 4),
    SCROLL_SCENERY(326, 2, 0x7000, 0x0000),
    SCROLL_SCENERY(358, 3, 0x7000, 0x0000),
    SCROLL_SCENERY(360, 4, 0x7040, 0x3400),
    SCROLL_PALETTES(378, 1),
    SCROLL_SCENERY(392, 5, 0x7040, 0x3400),
    SCROLL_SCENERY(444, 7, 0x7200, 0x2400),
    SCROLL_SOUNDS(475, 1),
    SCROLL_SOUNDS(493, 1),
    SCROLL_SPEED(497, 0x040),
    SCROLL_SPEED(512, 0x080),
    SCROLL_MAP_LOOP(612, -28, 28, -1),
    SCROLL_LINE_HOLD(612),
    SCROLL_EVENTS_END,
};

/* The second plane. */
u16 stage2_plane2_scroll_events[13] = {
    0, 0, 0, 0,
    SCROLL_SPEED(497, 0x040),
    SCROLL_SPEED(512, 0x080),
    SCROLL_EVENTS_END,
};

/* Stage 3. The palettes its events load, in the order they are loaded: slot of the palette's address, palette number. */
u16 stage3_scroll_palettes[74] = {
    SCROLL_PALETTE(0, 24),
    SCROLL_PALETTE(3, 25),
    SCROLL_PALETTE(6, 26),
    SCROLL_PALETTE(9, 27),
    SCROLL_PALETTE(12, 28),
    SCROLL_PALETTE(15, 30),
    SCROLL_PALETTE(18, 29),
    SCROLL_PALETTE(21, 31),
    SCROLL_PALETTE(24, 10),
    SCROLL_PALETTE(27, 11),
    SCROLL_PALETTE(30, 12),
    SCROLL_PALETTE(33, 13),
    SCROLL_PALETTE(36, 14),
    SCROLL_PALETTE(39, 15),
    SCROLL_PALETTE(42, 16),
    SCROLL_PALETTE(45, 17),
    SCROLL_PALETTE(48, 18),
    SCROLL_PALETTE(51, 19),
    SCROLL_PALETTE(54, 21),
    SCROLL_PALETTE(57, 22),
    SCROLL_PALETTE(60, 23),
    SCROLL_PALETTE(63, 22),
    SCROLL_PALETTE(66, 21),
    SCROLL_PALETTE(69, 20),
    SCROLL_PALETTES_END,
};

u16 stage3_scroll_sounds[11] = {
    SCROLL_SOUND_CALL(40, 2),
    SCROLL_SOUND_MUSIC_FADE(0),
    SCROLL_SOUND_CALL(0, 8),
    SCROLL_SOUNDS_END,
};

u16 stage3_scroll_events[106] = {
    POINTER_SLOT(0), /* stage3_scroll_palettes */
    POINTER_SLOT(2), /* stage3_scroll_sounds */
    SCROLL_SOUNDS(0, 1),
    SCROLL_PALETTES(0, 20),
    SCROLL_SPEED(0, 0x020),
    SCROLL_SCENERY(32, 0, 0x7000, 0x0000),
    SCROLL_MAP_LOOP(52, -28, 28, -1),
    SCROLL_SCENERY(60, 1, 0x7000, 0x0000),
    SCROLL_SCENERY(88, 2, 0x7000, 0x0000),
    SCROLL_SCENERY(112, 4, 0x7000, 0x0000),
    SCROLL_SCENERY(116, 3, 0x7000, 0x3800),
    SCROLL_SCENERY(140, 5, 0x7000, 0x0000),
    SCROLL_SCENERY(168, 6, 0x7000, 0x0000),
    SCROLL_SCENERY(196, 7, 0x7000, 0x0000),
    SCROLL_SPEED(216, 0x040),
    SCROLL_SPEED(224, 0x080),
    SCROLL_PALETTES(227, 4),
    SCROLL_LINE_HOLD(228),
    SCROLL_SPEED(264, 0x040),
    SCROLL_SPEED(272, 0x020),
    SCROLL_SPEED(276, 0x010),
    SCROLL_SOUNDS(411, 1),
    SCROLL_SOUNDS(423, 1),
    SCROLL_EVENTS_END,
};

/* The second plane. */
u16 stage3_plane2_scroll_events[29] = {
    0, 0, 0, 0,
    SCROLL_SPEED(0, 0x040),
    SCROLL_SPEED(216, 0x080),
    SCROLL_SPEED(224, 0x100),
    SCROLL_SPEED(264, 0x080),
    SCROLL_SPEED(272, 0x040),
    SCROLL_SPEED(276, 0x020),
    SCROLL_EVENTS_END,
};

/* Stage 4. The palettes its events load, in the order they are loaded: slot of the palette's address, palette number. */
u16 stage4_scroll_palettes[68] = {
    SCROLL_PALETTE(0, 24),
    SCROLL_PALETTE(3, 25),
    SCROLL_PALETTE(6, 26),
    SCROLL_PALETTE(9, 27),
    SCROLL_PALETTE(12, 28),
    SCROLL_PALETTE(15, 30),
    SCROLL_PALETTE(18, 29),
    SCROLL_PALETTE(21, 31),
    SCROLL_PALETTE(24, 10),
    SCROLL_PALETTE(27, 11),
    SCROLL_PALETTE(30, 12),
    SCROLL_PALETTE(33, 13),
    SCROLL_PALETTE(36, 14),
    SCROLL_PALETTE(39, 15),
    SCROLL_PALETTE(42, 22),
    SCROLL_PALETTE(45, 23),
    SCROLL_PALETTE(48, 22),
    SCROLL_PALETTE(51, 22),
    SCROLL_PALETTE(54, 23),
    SCROLL_PALETTE(57, 10),
    SCROLL_PALETTE(60, 12),
    SCROLL_PALETTE(63, 23),
    SCROLL_PALETTES_END,
};

u16 stage4_scroll_sounds[11] = {
    SCROLL_SOUND_CALL(36, 2),
    SCROLL_SOUND_MUSIC_FADE(0),
    SCROLL_SOUND_CALL(0, 8),
    SCROLL_SOUNDS_END,
};

u16 stage4_scroll_events[108] = {
    POINTER_SLOT(0), /* stage4_scroll_palettes */
    POINTER_SLOT(2), /* stage4_scroll_sounds */
    SCROLL_SOUNDS(0, 1),
    SCROLL_SPEED(0, 0x020),
    SCROLL_PALETTES(0, 14),
    SCROLL_PALETTES(0, 1),
    SCROLL_SCENERY(0, 5, 0x6200, 0x0000),
    SCROLL_PALETTES(164, 1),
    SCROLL_SCENERY(164, 1, 0x7000, 0x0000),
    SCROLL_PALETTES(205, 1),
    SCROLL_PALETTES(360, 1),
    SCROLL_SCENERY(360, 2, 0x7000, 0x0000),
    SCROLL_PALETTES(528, 1),
    SCROLL_SCENERY(528, 3, 0x7000, 0x0000),
    SCROLL_PALETTES(560, 2),
    SCROLL_PALETTES(696, 1),
    SCROLL_SCENERY(696, 4, 0x7000, 0x0000),
    SCROLL_SOUNDS(718, 1),
    SCROLL_SOUNDS(735, 1),
    SCROLL_SPEED(736, 0x040),
    SCROLL_SPEED(740, 0x080),
    SCROLL_SPEED(744, 0x0C0),
    SCROLL_SPEED(748, 0x100),
    SCROLL_MAP_LOOP(780, -14, 14, -1),
    SCROLL_LINE_HOLD(780),
    SCROLL_EVENTS_END,
};

/* The second plane. */
u16 stage4_plane2_scroll_events[25] = {
    0, 0, 0, 0,
    SCROLL_SPEED(0, 0x020),
    SCROLL_SPEED(736, 0x040),
    SCROLL_SPEED(740, 0x080),
    SCROLL_SPEED(744, 0x0C0),
    SCROLL_SPEED(748, 0x100),
    SCROLL_EVENTS_END,
};

/* Stage 5. The palettes its events load, in the order they are loaded: slot of the palette's address, palette number. */
u16 stage5_scroll_palettes[61] = {
    SCROLL_PALETTE(0, 24),
    SCROLL_PALETTE(3, 25),
    SCROLL_PALETTE(6, 26),
    SCROLL_PALETTE(9, 27),
    SCROLL_PALETTE(12, 28),
    SCROLL_PALETTE(15, 30),
    SCROLL_PALETTE(18, 29),
    SCROLL_PALETTE(21, 31),
    SCROLL_PALETTE(24, 10),
    SCROLL_PALETTE(27, 11),
    SCROLL_PALETTE(30, 12),
    SCROLL_PALETTE(33, 13),
    SCROLL_PALETTE(36, 14),
    SCROLL_PALETTE(39, 15),
    SCROLL_PALETTE(42, 22),
    SCROLL_PALETTE(45, 23),
    SCROLL_PALETTE(48, 15),
    SCROLL_PALETTE(51, 17),
    SCROLL_PALETTE(54, 23),
    SCROLL_PALETTE(57, 22),
    0xFFFF /* half an end mark */,
};

u16 stage5_scroll_sounds[11] = {
    SCROLL_SOUND_CALL(40, 2),
    SCROLL_SOUND_MUSIC_FADE(0),
    SCROLL_SOUND_CALL(0, 8),
    SCROLL_SOUNDS_END,
};

u16 stage5_scroll_events[154] = {
    POINTER_SLOT(0), /* stage5_scroll_palettes */
    POINTER_SLOT(2), /* stage5_scroll_sounds */
    SCROLL_SOUNDS(0, 1),
    SCROLL_PALETTES(0, 15),
    SCROLL_FLAGS(0, 1),
    SCROLL_PALETTES(16, 1),
    SCROLL_SCENERY(74, 0, 0x7000, 0x0000),
    SCROLL_FLAGS(76, 2),
    SCROLL_SCENERY(104, 1, 0x7000, 0x0000),
    SCROLL_SCENERY(144, 2, 0x7000, 0x0000),
    SCROLL_SPEED(176, 0x010),
    SCROLL_PALETTES(199, 2),
    SCROLL_FLAGS(208, 2),
    SCROLL_SPEED(224, 0x020),
    SCROLL_SPEED(368, 0x020),
    SCROLL_PALETTES(375, 1),
    SCROLL_SCENERY(375, 3, 0x7000, 0x0000),
    SCROLL_SPEED(376, 0x010),
    SCROLL_SPEED(380, 0x008),
    SCROLL_SPEED(428, 0x020),
    SCROLL_SPEED(440, 0x010),
    SCROLL_PALETTES(456, 1),
    SCROLL_SPEED(488, 0x020),
    SCROLL_SOUNDS(797, 1),
    SCROLL_SOUNDS(832, 1),
    SCROLL_SPEED(836, 0x015),
    SCROLL_SPEED(837, 0x010),
    SCROLL_SPEED(838, 0x000),
    SCROLL_SPEED(839, 0x010),
    SCROLL_SPEED(840, 0x015),
    SCROLL_SPEED(841, 0x020),
    SCROLL_SPEED(842, 0x040),
    SCROLL_SPEED(844, 0x080),
    SCROLL_SPEED(846, 0x0C0),
    SCROLL_SPEED(848, 0x100),
    SCROLL_MAP_LOOP(948, -28, 28, -1),
    SCROLL_LINE_HOLD(948),
    SCROLL_EVENTS_END,
};

/* The second plane. */
u16 stage5_plane2_scroll_events[77] = {
    0, 0, 0, 0,
    SCROLL_SPEED(176, 0x010),
    SCROLL_SPEED(224, 0x020),
    SCROLL_SPEED(368, 0x020),
    SCROLL_SPEED(376, 0x010),
    SCROLL_SPEED(380, 0x008),
    SCROLL_SPEED(428, 0x020),
    SCROLL_SPEED(440, 0x010),
    SCROLL_SPEED(488, 0x020),
    SCROLL_SPEED(836, 0x015),
    SCROLL_SPEED(837, 0x010),
    SCROLL_SPEED(838, 0x000),
    SCROLL_SPEED(839, 0x010),
    SCROLL_SPEED(840, 0x015),
    SCROLL_SPEED(841, 0x020),
    SCROLL_SPEED(842, 0x040),
    SCROLL_SPEED(844, 0x080),
    SCROLL_SPEED(846, 0x0C0),
    SCROLL_SPEED(848, 0x100),
    SCROLL_EVENTS_END,
};

/* .sdata */
u16 stage1_scroll_event_lists[4] = { POINTER_SLOT(0), POINTER_SLOT(2) };
u16 stage2_scroll_event_lists[4] = { POINTER_SLOT(0), POINTER_SLOT(2) };
u16 stage3_scroll_event_lists[4] = { POINTER_SLOT(0), POINTER_SLOT(2) };
u16 stage4_scroll_event_lists[4] = { POINTER_SLOT(0), POINTER_SLOT(2) };
u16 stage5_scroll_event_lists[4] = { POINTER_SLOT(0), POINTER_SLOT(2) };

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(D_002526D2, scroll_event_routines, 0x2);

PC_DATA_ALIAS(D_002526F2, scroll_sound_routines, 0x2);

PC_DATA_ALIAS(D_00252702, stage_map_palettes, 0x2);

PC_DATA_ALIAS(D_00252722, stage_maps, 0x2);
#endif
