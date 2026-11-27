#ifndef DDPDOJ_ARCADE_GAMEPLAY_H
#define DDPDOJ_ARCADE_GAMEPLAY_H

/* These arcade routines exchange state through the shared reg_a, reg_d,
 * and condition-code variables. Some PS2 callers also load unused arguments. */
#ifdef DDPDOJ_PC
#define ARCADE_REGISTER_ARGS void
#else
#define ARCADE_REGISTER_ARGS
#endif
void active_players_mask(void);
void aim256_at_player(ARCADE_REGISTER_ARGS);
void boss_level_get(void);
void boss_movement_start(ARCADE_REGISTER_ARGS);
void boss_phase_start(ARCADE_REGISTER_ARGS);
void bullet_fire(ARCADE_REGISTER_ARGS);
void bullet_fire256(void);
void bullet_fire256_direct(void);
void bullet_fire256_fast(void);
void bullet_fire256_fixed(void);
void bullet_fire_fixed(void);
void bullet_release(void);
void deferred_text_clear(void);
void deferred_text_put(void);
void direction256_to_target_player(ARCADE_REGISTER_ARGS);
void direction_to_point(void);
void distance_between(ARCADE_REGISTER_ARGS);
void enemy_hitbox_debug_draw(void);
void enemy_init_entities(void);
void enemy_path_start(void);
void enemy_path_step(void);
void enemy_remove(ARCADE_REGISTER_ARGS);
void enemy_set_task_state(void);
void enemy_variant_offset_c_get(void);
void entity_draw_with_bullets(void);
void entity_draw_with_players(void);
void entity_draw_with_special_items(void);
void entity_velocity(void);
void hyper_ready_mark_draw(void);
void item_release(void);
void laser_muzzle_update_strong(void);
void p1_boss_hits_score(void);
void p1_maximum_level_show(void);
void p2_boss_hits_score(void);
void p2_maximum_level_show(void);
void pickup_accelerate(void);
void pickup_spin_frames_0(void);
void player_draw_entering(void);
void rng_next_bit(ARCADE_REGISTER_ARGS);
void sprite_draw_layer1(void);
void sprite_draw_layer2(void);
void sprite_draw_layer2_keep(ARCADE_REGISTER_ARGS);
void sprite_draw_layer3_keep(void);
void sprite_draw_layer4(void);
void sprite_draw_layer5(void);
void sprite_draw_with_special_items(void);
void text_layer_print(void);
void velocity_from_direction(void);

#undef ARCADE_REGISTER_ARGS

#endif
