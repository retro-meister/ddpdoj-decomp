#include "common.h"
#include "sdk/ps2sdk.h"
#include "pad.h"

void replay_slots_start(void);
void replay_slots_card_scan_wait(void);
void replay_slots_card_ready(void);
void replay_slots_card_select(void);
s32 replay_slots_card_save(void);
s32 replay_slots_card_load(void);

s32 replay_slots_closing();
s32 replay_slots_disc_scan();
s32 replay_slots_disc_ready();
s32 replay_slots_disc_select();
s32 replay_slots_disc_load();
extern u8 g_replay_slots_from_disc;
extern u8 g_replay_slots_state_as_u8;

s32 replay_slots_update(void) {
    if (g_replay_slots_from_disc == 0) {
        switch (g_replay_slots_state_as_u8) {
        case 0:
            return 0;
        case 1:
            replay_slots_start();
            break;
        case 2:
            replay_slots_card_scan_wait();
            break;
        case 3:
            replay_slots_card_ready();
            break;
        case 4:
            replay_slots_card_select();
            break;
        case 5:
            return replay_slots_card_save();
        case 6:
            return replay_slots_card_load();
        case 7:
            replay_slots_closing();
            break;
        }
    } else {
        switch (g_replay_slots_state_as_u8) {
        case 0:
            return 0;
        case 1:
            replay_slots_start();
            break;
        case 2:
            replay_slots_disc_scan();
            break;
        case 3:
            replay_slots_disc_ready();
            break;
        case 4:
            replay_slots_disc_select();
            break;
        case 5:
            printf("program error\n");
            break;
        case 6:
            return replay_slots_disc_load();
        case 7:
            replay_slots_closing();
            break;
        }
    }
    return 1;
}

extern s8 g_replay_slots_state;
extern s8 g_replay_slots_fade;
extern s32 g_replay_slots_alpha;

void replay_slots_reset(void) {
    g_replay_slots_alpha = 0;
    g_replay_slots_fade = 0;
    g_replay_slots_state = 0;
}

extern s8 g_replay_slots_saving;
extern s8 g_replay_slots_from_disc_as_s8;
extern s8 g_replay_slots_pad_as_s8;

void replay_slots_open(s8 arg0, s8 arg1, s8 arg2) {
    g_replay_slots_pad_as_s8 = arg1;
    g_replay_slots_saving = arg0;
    g_replay_slots_state = 1;
    g_replay_slots_from_disc_as_s8 = arg2;
}

void replay_slots_close(void) {
    g_replay_slots_state = 7;
    g_replay_slots_fade = 2;
}

s32 func_00236900();                            /* extern */
extern s32 g_memcard_watch_step;

void replay_slots_card_scan_begin(void) {
    g_memcard_watch_step = 0;
    func_00236900();
    g_replay_slots_state = 2;
}

extern s8 g_replay_slots_cursor;


void replay_slots_start(void) {
    g_replay_slots_alpha = 0;
    g_replay_slots_fade = 0;
    g_replay_slots_cursor = 0;
    replay_slots_card_scan_begin();
}

s32 memcard_watch_update();                                /* extern */
extern s8 D_0028EB04;
extern s32 D_0028EB90;

void replay_slots_card_scan_wait(void) {
    if (memcard_watch_update() != 0) {
        g_replay_slots_state = 3;
        g_replay_slots_fade = 1;
        D_0028EB90 = 0x40;
        D_0028EB04 = 1;
    }
}

s32 memcard_watch_update();                                /* extern */

void replay_slots_card_ready(void) {
    if (memcard_watch_update() == 0) {
        replay_slots_card_scan_begin();
        return;
    }
    g_replay_slots_state = 4;
}

s32 sfx_menu_confirm();
s32 sfx_menu_move();
s32 memcard_watch_update();
extern u8 g_replay_slots_pad;
extern s8 g_replay_slots_step_as_s8;
extern u8 g_replay_slot_infos[];
void replay_slots_card_select(void) {
    s32 temp_a0;
    s32 temp_a0_3;
    u16 temp_a0_2;

    if (memcard_watch_update() == 0) {
        replay_slots_card_scan_begin();
        return;
    }
    temp_a0 = g_pad_trigger[g_replay_slots_pad];
    if (temp_a0 & 0x40) {
        sfx_menu_confirm();
        replay_slots_close();
    } else if (temp_a0 & 0x20) {
        g_replay_slots_step_as_s8 = 0;
        if (g_replay_slots_saving == 1) {
            g_replay_slots_state = 5;
            sfx_menu_confirm();
        } else {
            temp_a0_2 = *(u16 *)(g_replay_slot_infos + (g_replay_slots_cursor << 0xA));
            if ((temp_a0_2 != 0) && (temp_a0_2 != 3)) {
                g_replay_slots_state = 6;
                sfx_menu_confirm();
            }
        }
    }
    temp_a0_3 = g_pad_repeat[g_replay_slots_pad];
    if (temp_a0_3 & 0x1000) {
        sfx_menu_move();
        g_replay_slots_cursor -= 1;
        if (0 > g_replay_slots_cursor) {
            g_replay_slots_cursor = 9;
        }
    } else if (temp_a0_3 & 0x4000) {
        sfx_menu_move();
        g_replay_slots_cursor += 1;
        if (g_replay_slots_cursor >= 0xA) {
            g_replay_slots_cursor = 0;
        }
    }
}

s32 func_0022C750();
s32 memcard_watch_recheck();
s32 func_00236960();
extern s32 D_0028EABC;
extern u8 g_replay_slots_step;
extern s32 D_0028ECC0;
extern s32 D_0028ED0C;

s32 replay_slots_card_save(void) {
    switch (g_replay_slots_step) {
    case 0:
        D_0028ED0C = 0;
        g_replay_slots_step += 1;
    case 1:
        func_0022C750(g_replay_slots_cursor + 1);
        if (D_0028ED0C != 0) {
            memcard_watch_recheck();
            D_0028ED0C = 0;
            g_memcard_watch_step = 0;
            g_replay_slots_step += 1;
            D_0028EABC = D_0028ECC0;
            if (D_0028ECC0 != 0) {
                func_00236960(g_replay_slots_cursor);
            }
        }
        break;
    case 2:
        if (memcard_watch_update() != 0) {
            D_0028EB04 = 1;
            D_0028EB90 = 0x40;
            g_replay_slots_state = 4;
            g_replay_slots_step = 0;
            if (D_0028EABC != 0) {
                return 2;
            }
        }
        break;
    }
    return 1;
}

s32 delta_encode(s32 *);                   /* extern */
s32 func_0022C760(s32);                         /* extern */
s32 memcard_watch_recheck();                            /* extern */
s32 replay_file_pointers_decode(s32 *);                   /* extern */
extern s8 g_replay_slot_loaded;
extern s32 D_0028ECC4;
extern u8 D_0028ED30;
extern u8 D_0028ED31;
extern u8 D_0028ED32;
extern u8 D_0028ED33;
extern u8 D_0028ED34;
extern u8 D_0028ED35;
extern u8 D_0028ED36;
extern u8 D_0028ED37;
extern s32 g_replay_file_loaded_as_s32_a[];
extern s32 g_replay_file_as_s32_a[];
extern u8 D_006C58D8[];
extern u8 D_006C58D9[];
extern u8 D_006C58DA[];
extern u8 D_006C58DB[];
extern u8 D_006C58DC[];
extern u8 D_006C58DD[];
extern u8 D_006C58DE[];
extern u8 D_006C58DF[];
extern s32 g_replay_snapshot_as_s32_a[];

s32 replay_slots_card_load(void) {
    switch (g_replay_slots_step) {                           /* irregular */
    case 0:
        D_0028ED0C = 0;
        g_replay_slots_step += 1;
        /* fallthrough */
    case 1:
        func_0022C760(g_replay_slots_cursor + 1);
        if (D_0028ED0C != 0) {
            memcard_watch_recheck();
            g_replay_slots_state = 4;
            D_0028ED0C = 0;
            D_0028EB04 = 1;
            g_replay_slots_step = 0;
            D_0028EB90 = 0x40;
            g_replay_slot_loaded = g_replay_slots_cursor;
            if (D_0028ECC4 != 0) {
                memcpy(g_replay_file_as_s32_a, g_replay_file_loaded_as_s32_a, 0x202E8);
                delta_encode(g_replay_snapshot_as_s32_a);
                replay_file_pointers_decode(g_replay_file_as_s32_a);
                D_0028ED30 = D_006C58D8[0];
                D_0028ED31 = D_006C58D9[0];
                D_0028ED32 = D_006C58DA[0];
                D_0028ED33 = D_006C58DB[0];
                D_0028ED34 = D_006C58DC[0];
                D_0028ED35 = D_006C58DD[0];
                D_0028ED36 = D_006C58DE[0];
                D_0028ED37 = D_006C58DF[0];
                return 3;
            }
        }
    default:
        return 1;
    }
}
