#ifndef DDPDOJ_BLACK_LABEL_H
#define DDPDOJ_BLACK_LABEL_H

#ifdef DDPDOJ_BONUS_FEATURES
extern int g_black_label_active;
extern unsigned short g_black_label_single_loop;
extern unsigned short g_loop2_starting_lives[2];
void black_label_card_init(void);
void black_label_menu_init(void);
void black_label_title_init(void);
void black_label_round_select(int departure_finished);
extern unsigned short black_label_hyper_speeds[2][35];
#define GAME_RULE(original, black) (g_black_label_active ? (black) : (original))
#else
#define GAME_RULE(original, black) (original)
#endif

#endif
