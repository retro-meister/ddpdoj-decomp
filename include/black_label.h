#ifndef DDPDOJ_BLACK_LABEL_H
#define DDPDOJ_BLACK_LABEL_H

#ifdef DDPDOJ_BONUS_FEATURES
extern int g_black_label_active;
extern unsigned short g_black_label_single_loop;
extern unsigned short g_loop2_starting_lives[2];
unsigned short black_label_demo_power(void);
unsigned char black_label_demo_input(void);
void black_label_card_init(void);
void black_label_menu_init(void);
void black_label_title_init(void);
void black_label_boss_burst(unsigned short y, unsigned short x);
void black_label_shake_start(void);
void black_label_shake_step(void);
void black_label_shake_stop(void);
extern short g_boss_shake_y, g_boss_shake_x;
extern short g_slowdown_boss_allowed;
void black_label_round_select(int departure_finished);
/* These three ring colors share the movement and collision data of bullet 0x1b. */
static inline unsigned int black_label_ring_frames(unsigned int type)
{
    if (g_black_label_active && type >= 0x24 && type <= 0x26)
        return (type - 0x23) * 4;
    return 0;
}
#define GAME_RULE(original, black) (g_black_label_active ? (black) : (original))
#else
#define GAME_RULE(original, black) (original)
#endif

#endif
