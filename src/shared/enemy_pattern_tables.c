/* Tables the enemy scripts and several enemy units share. */
#include "common.h"

void battleship();
void battleship_b();
void battleship_b_first();
void battleship_b_start();
void battleship_first();
void battleship_start();
void bee_container();
void bee_container_first();
void bee_container_start();
void bomb_carrier_first();
void bomb_carrier_start();
void crane_turret();
void crane_turret_first();
void crane_turret_start();
void debris_test_first();
void debris_test_main();
void debris_test_setup();
void dummy_enemy_first();
void dummy_enemy_main();
void dummy_enemy_main_b();
void enemy_remove_entry();
void enemy_remove_entry_entry();
void enemy_spawner_first();
void enemy_spawner_main();
void enemy_spawner_setup();
void explosion_test_first();
void explosion_test_main();
void explosion_test_setup();
void formation_fire_timer_first();
void formation_fire_timer_main();
void formation_fire_timer_setup();
void func_001571D0();
void func_001571E0();
void func_00157260();
void func_001578A0();
void func_001578B0();
void func_001579A0();
void func_00157D80();
void func_00157D90();
void func_00157DC0();
void func_001581E0();
void func_001581F0();
void func_00158370();
void func_00159030();
void func_00159040();
void func_001590B0();
void func_00159C50();
void func_00159C60();
void func_00159CB0();
void func_0015A500();
void func_0015A510();
void func_0015A5B0();
void func_0015AE00();
void func_0015AE10();
void func_0015AE70();
void func_0015AEF0();
void func_0015AF00();
void func_0015B210();
void func_0015C440();
void func_00168110();
void func_00168120();
void func_001683C0();
void func_0016CCD0();
void func_0016CCE0();
void func_0016CD40();
void func_0016EA90();
void func_0016EAA0();
void func_0016ED40();
void func_0016F930();
void func_0016F940();
void func_0016FAE0();
void func_001CBD50();
void func_001CBD60();
void func_001CC0A0();
void func_001D6C80();
void func_001D6C90();
void func_001D6D60();
void func_001F93C0();
void func_001F93D0();
void func_001F9450();
void func_001F9540();
void func_001F9550();
void func_001F95D0();
void ground_turret_a();
void ground_turret_a_first();
void ground_turret_a_start();
void ground_turret_b();
void ground_turret_b_first();
void ground_turret_b_start();
void ground_turret_c();
void ground_turret_c_first();
void ground_turret_c_start();
void heli_a();
void heli_a_first();
void heli_a_start();
void heli_b();
void heli_b_first();
void heli_b_start();
void heli_c();
void heli_c_first();
void heli_c_start();
void heli_d();
void heli_d_first();
void heli_d_start();
void heli_e();
void heli_e_first();
void heli_e_start();
void heli_f();
void heli_f_first();
void heli_f_start();
void heli_g();
void heli_g_first();
void heli_g_start();
void heli_h();
void heli_h_first();
void heli_h_start();
void item_carrier();
void item_carrier_first();
void item_carrier_start();
void map_cell_test_first();
void map_cell_test_main();
void map_cell_test_setup();
void mid_flyer_a();
void mid_flyer_a_first();
void mid_flyer_a_start();
void mid_flyer_b();
void mid_flyer_b_first();
void mid_flyer_b_start();
void mid_flyer_c();
void mid_flyer_c_first();
void mid_flyer_c_start();
void mid_flyer_d();
void mid_flyer_d_first();
void mid_flyer_d_start();
void mid_flyer_e();
void mid_flyer_e_first();
void mid_flyer_e_start();
void mid_tank_horizontal();
void mid_tank_horizontal_b();
void mid_tank_horizontal_b_first();
void mid_tank_horizontal_b_start();
void mid_tank_horizontal_first();
void mid_tank_horizontal_start();
void mid_tank_vertical();
void mid_tank_vertical_first();
void mid_tank_vertical_start();
void rail_turret();
void rail_turret_first();
void rail_turret_start();
void shooter_drone();
void shooter_drone_first();
void shooter_drone_start();
void small_tank_a();
void small_tank_a_first();
void small_tank_a_start();
void small_tank_b();
void small_tank_b_first();
void small_tank_b_start();
void stage1_boss_breakable_bullet();
void stage1_boss_breakable_bullet_b();
void stage1_boss_breakable_bullet_b_first();
void stage1_boss_breakable_bullet_b_start();
void stage1_boss_breakable_bullet_first();
void stage1_boss_breakable_bullet_start();
void stage1_boss_entrance();
void stage1_boss_entrance_first();
void stage1_boss_entrance_start();
void stage1_boss_first();
void stage1_boss_main();
void stage1_boss_side_bullet();
void stage1_boss_side_bullet_first();
void stage1_boss_side_bullet_start();
void stage1_boss_start();
void stage1_midboss_first();
void stage1_midboss_main();
void stage1_midboss_start();
void stage1_midboss_wreck();
void stage1_midboss_wreck_first();
void stage1_midboss_wreck_start();
void stage2_blooming_base();
void stage2_blooming_base_first();
void stage2_blooming_base_start();
void stage2_boss_cannon_shell();
void stage2_boss_cannon_shell_first();
void stage2_boss_cannon_shell_start();
void stage2_boss_dropped_bomb();
void stage2_boss_dropped_bomb_first();
void stage2_boss_dropped_bomb_start();
void stage2_boss_first();
void stage2_boss_hangar();
void stage2_boss_hangar_first();
void stage2_boss_hangar_start();
void stage2_boss_main();
void stage2_boss_ripple();
void stage2_boss_ripple_first();
void stage2_boss_ripple_start();
void stage2_boss_shoulder_bullet();
void stage2_boss_shoulder_bullet_first();
void stage2_boss_shoulder_bullet_start();
void stage2_boss_spread_bullet();
void stage2_boss_spread_bullet_first();
void stage2_boss_spread_bullet_start();
void stage2_boss_start();
void stage2_gymnasium();
void stage2_gymnasium_first();
void stage2_gymnasium_start();
void stage2_long_warehouse();
void stage2_long_warehouse_first();
void stage2_long_warehouse_start();
void stage2_sliding_gun();
void stage2_sliding_gun_first();
void stage2_sliding_gun_start();
void stage2_square_warehouse();
void stage2_square_warehouse_first();
void stage2_square_warehouse_start();
void stage2_wrecker_gun();
void stage2_wrecker_gun_first();
void stage2_wrecker_gun_start();
void stage3_boss_first();
void stage3_boss_lid_bullet();
void stage3_boss_lid_bullet_first();
void stage3_boss_lid_bullet_start();
void stage3_boss_main();
void stage3_boss_start();
void stage3_boss_timber();
void stage3_boss_timber_first();
void stage3_boss_timber_start();
void stage3_cloud();
void stage3_cloud_first();
void stage3_cloud_start();
void stage3_gun_a();
void stage3_gun_a_first();
void stage3_gun_a_start();
void stage3_gun_b_first();
void stage3_gun_b_start();
void stage3_gun_c_first();
void stage3_gun_c_start();
void stage3_gun_d_first();
void stage3_gun_d_start();
void stage3_large_gun();
void stage3_large_gun_first();
void stage3_large_gun_start();
void stage3_midboss_first();
void stage3_midboss_main();
void stage3_midboss_start();
void stage4_boss_cutter();
void stage4_boss_cutter_first();
void stage4_boss_cutter_start();
void stage4_boss_first();
void stage4_boss_main();
void stage4_boss_missile();
void stage4_boss_missile_first();
void stage4_boss_missile_start();
void stage4_boss_start();
void stage4_gate();
void stage4_gate_first();
void stage4_gate_start();
void stage4_heavy_cannon();
void stage4_heavy_cannon_casing();
void stage4_heavy_cannon_casing_first();
void stage4_heavy_cannon_casing_start();
void stage4_heavy_cannon_first();
void stage4_heavy_cannon_start();
void stage4_lift();
void stage4_lift_first();
void stage4_lift_start();
void stage4_reactor();
void stage4_reactor_first();
void stage4_reactor_start();
void stage4_tachyon_particle();
void stage4_tachyon_particle_first();
void stage4_tachyon_particle_start();
void stage4_wave_cannon();
void stage4_wave_cannon_first();
void stage4_wave_cannon_start();
void stage5_bee_drone();
void stage5_bee_drone_first();
void stage5_bee_drone_start();
void stage5_bee_hatch();
void stage5_bee_hatch_first();
void stage5_bee_hatch_start();
void stage5_boss_first();
void stage5_boss_main();
void stage5_boss_start();
void stage5_large_spider_head();
void stage5_large_spider_head_first();
void stage5_large_spider_head_start();
void stage5_large_spider_turret();
void stage5_large_spider_turret_first();
void stage5_large_spider_turret_start();
void stage5_midboss3_first();
void stage5_midboss3_main();
void stage5_midboss3_start();
void stage5_midboss4_arrival();
void stage5_midboss4_arrival_first();
void stage5_midboss4_arrival_start();
void stage5_midboss4_first();
void stage5_midboss4_main();
void stage5_midboss4_start();
void stage5_midboss4_wave_beam();
void stage5_midboss4_wave_beam_first();
void stage5_midboss4_wave_beam_start();
void stage5_midboss5_drone();
void stage5_midboss5_drone_first();
void stage5_midboss5_drone_start();
void stage5_midboss5_first();
void stage5_midboss5_large_blast();
void stage5_midboss5_large_blast_first();
void stage5_midboss5_large_blast_start();
void stage5_midboss5_large_missile();
void stage5_midboss5_large_missile_first();
void stage5_midboss5_large_missile_start();
void stage5_midboss5_main();
void stage5_midboss5_small_blast();
void stage5_midboss5_small_blast_first();
void stage5_midboss5_small_blast_start();
void stage5_midboss5_small_missile();
void stage5_midboss5_small_missile_first();
void stage5_midboss5_small_missile_start();
void stage5_midboss5_spin_drone();
void stage5_midboss5_spin_drone_first();
void stage5_midboss5_spin_drone_start();
void stage5_midboss5_start();
void stage5_small_spider_head();
void stage5_small_spider_head_first();
void stage5_small_spider_head_start();
void stage5_small_spider_turret();
void stage5_small_spider_turret_first();
void stage5_small_spider_turret_start();
void stage5_small_turret();
void stage5_small_turret_first();
void stage5_small_turret_start();
void stage5_spiderling();
void stage5_spiderling_first();
void stage5_spiderling_start();
void star_container();
void star_container_first();
void star_container_start();
void warning_sign();
void warning_sign_first();
void warning_sign_start();
void water_flower_turret();
void water_flower_turret_first();
void water_flower_turret_start();
void wreck_test_first();
void wreck_test_main();
void wreck_test_setup();

struct D002589f0Record { void *p0; void *p1; void *p2; void *p3; void *p4; void *p5; void *p6; void *p7; void *p8; void *p9; void *p10; void *p11; void *p12; void *p13; void *p14; void *p15; void *p16; void *p17; void *p18; void *p19; void *p20; void *p21; void *p22; void *p23; void *p24; void *p25; void *p26; void *p27; void *p28; void *p29; void *p30; void *p31; void *p32; void *p33; void *p34; void *p35; void *p36; void *p37; void *p38; void *p39; void *p40; void *p41; void *p42; void *p43; void *p44; void *p45; void *p46; void *p47; void *p48; void *p49; void *p50; void *p51; void *p52; void *p53; void *p54; void *p55; void *p56; void *p57; void *p58; void *p59; void *p60; void *p61; void *p62; void *p63; void *p64; void *p65; void *p66; void *p67; void *p68; void *p69; void *p70; void *p71; void *p72; void *p73; void *p74; void *p75; void *p76; void *p77; void *p78; void *p79; void *p80; void *p81; void *p82; void *p83; void *p84; void *p85; void *p86; void *p87; void *p88; void *p89; void *p90; void *p91; void *p92; void *p93; void *p94; void *p95; void *p96; void *p97; void *p98; void *p99; void *p100; void *p101; void *p102; void *p103; void *p104; void *p105; void *p106; void *p107; void *p108; void *p109; void *p110; void *p111; void *p112; void *p113; void *p114; void *p115; void *p116; void *p117; void *p118; void *p119; void *p120; void *p121; void *p122; void *p123; void *p124; void *p125; void *p126; void *p127; void *p128; void *p129; void *p130; void *p131; void *p132; void *p133; void *p134; void *p135; void *p136; void *p137; void *p138; void *p139; void *p140; void *p141; void *p142; void *p143; void *p144; void *p145; void *p146; void *p147; void *p148; void *p149; void *p150; void *p151; void *p152; void *p153; void *p154; void *p155; void *p156; void *p157; void *p158; void *p159; void *p160; void *p161; void *p162; void *p163; void *p164; void *p165; void *p166; void *p167; void *p168; void *p169; void *p170; void *p171; void *p172; void *p173; void *p174; void *p175; void *p176; void *p177; void *p178; void *p179; void *p180; void *p181; void *p182; void *p183; void *p184; void *p185; void *p186; void *p187; void *p188; void *p189; void *p190; void *p191; void *p192; void *p193; void *p194; void *p195; void *p196; void *p197; void *p198; void *p199; void *p200; void *p201; void *p202; void *p203; void *p204; void *p205; void *p206; void *p207; void *p208; void *p209; void *p210; void *p211; void *p212; void *p213; void *p214; void *p215; void *p216; void *p217; void *p218; void *p219; void *p220; void *p221; void *p222; void *p223; void *p224; void *p225; void *p226; void *p227; void *p228; void *p229; void *p230; void *p231; void *p232; void *p233; void *p234; void *p235; void *p236; void *p237; void *p238; void *p239; void *p240; void *p241; void *p242; void *p243; void *p244; void *p245; void *p246; void *p247; void *p248; void *p249; void *p250; void *p251; void *p252; void *p253; void *p254; void *p255; void *p256; void *p257; void *p258; void *p259; void *p260; void *p261; void *p262; void *p263; void *p264; void *p265; void *p266; void *p267; void *p268; void *p269; void *p270; void *p271; void *p272; void *p273; void *p274; void *p275; void *p276; void *p277; void *p278; void *p279; void *p280; void *p281; void *p282; void *p283; void *p284; void *p285; void *p286; void *p287; void *p288; void *p289; void *p290; void *p291; void *p292; void *p293; void *p294; void *p295; void *p296; void *p297; void *p298; void *p299; void *p300; void *p301; void *p302; void *p303; void *p304; void *p305; void *p306; void *p307; void *p308; void *p309; void *p310; void *p311; void *p312; void *p313; void *p314; void *p315; void *p316; void *p317; void *p318; void *p319; void *p320; void *p321; void *p322; void *p323; void *p324; void *p325; void *p326; void *p327; void *p328; void *p329; void *p330; void *p331; void *p332; void *p333; void *p334; void *p335; void *p336; void *p337; void *p338; void *p339; void *p340; void *p341; void *p342; void *p343; void *p344; void *p345; void *p346; void *p347; void *p348; void *p349; void *p350; void *p351; void *p352; void *p353; void *p354; void *p355; void *p356; void *p357; void *p358; void *p359; void *p360; void *p361; void *p362; void *p363; void *p364; void *p365; void *p366; void *p367; void *p368; void *p369; void *p370; void *p371; void *p372; void *p373; void *p374; void *p375; void *p376; void *p377; void *p378; void *p379; void *p380; void *p381; void *p382; void *p383; u16 w384[1344]; void *p385; void *p386; void *p387; void *p388; void *p389; void *p390; void *p391; void *p392; void *p393; void *p394; void *p395; void *p396; void *p397; void *p398; void *p399; void *p400; void *p401; void *p402; void *p403; void *p404; void *p405; void *p406; void *p407; void *p408; void *p409; void *p410; void *p411; void *p412; void *p413; void *p414; void *p415; void *p416; void *p417; void *p418; void *p419; void *p420; void *p421; void *p422; void *p423; void *p424; void *p425; void *p426; void *p427; void *p428; void *p429; void *p430; void *p431; void *p432; void *p433; void *p434; void *p435; void *p436; void *p437; void *p438; void *p439; void *p440; void *p441; void *p442; void *p443; void *p444; void *p445; void *p446; void *p447; void *p448; void *p449; void *p450; void *p451; void *p452; void *p453; void *p454; void *p455; void *p456; void *p457; void *p458; void *p459; void *p460; void *p461; void *p462; void *p463; void *p464; void *p465; void *p466; void *p467; void *p468; void *p469; void *p470; void *p471; void *p472; void *p473; void *p474; void *p475; void *p476; void *p477; void *p478; void *p479; void *p480; void *p481; void *p482; void *p483; void *p484; void *p485; void *p486; void *p487; void *p488; void *p489; void *p490; void *p491; void *p492; void *p493; void *p494; void *p495; void *p496; void *p497; void *p498; void *p499; void *p500; void *p501; void *p502; void *p503; void *p504; void *p505; void *p506; void *p507; void *p508; void *p509; void *p510; void *p511; void *p512; void *p513; void *p514; void *p515; void *p516; void *p517; void *p518; void *p519; void *p520; void *p521; void *p522; void *p523; void *p524; void *p525; void *p526; void *p527; void *p528; void *p529; void *p530; void *p531; void *p532; void *p533; void *p534; void *p535; void *p536; void *p537; void *p538; void *p539; void *p540; void *p541; void *p542; void *p543; void *p544; void *p545; void *p546; void *p547; void *p548; void *p549; void *p550; void *p551; void *p552; void *p553; void *p554; void *p555; void *p556; void *p557; void *p558; void *p559; void *p560; void *p561; void *p562; void *p563; void *p564; void *p565; void *p566; void *p567; void *p568; void *p569; void *p570; void *p571; void *p572; void *p573; void *p574; void *p575; void *p576; void *p577; void *p578; void *p579; void *p580; void *p581; void *p582; void *p583; void *p584; void *p585; void *p586; void *p587; void *p588; void *p589; void *p590; void *p591; void *p592; void *p593; void *p594; void *p595; void *p596; void *p597; void *p598; void *p599; void *p600; void *p601; void *p602; void *p603; void *p604; void *p605; void *p606; void *p607; void *p608; void *p609; void *p610; void *p611; void *p612; void *p613; void *p614; void *p615; void *p616; void *p617; void *p618; void *p619; void *p620; void *p621; void *p622; void *p623; void *p624; void *p625; void *p626; void *p627; void *p628; void *p629; void *p630; void *p631; void *p632; void *p633; void *p634; void *p635; void *p636; void *p637; void *p638; void *p639; void *p640; void *p641; void *p642; void *p643; void *p644; void *p645; void *p646; void *p647; void *p648; void *p649; void *p650; void *p651; void *p652; void *p653; void *p654; void *p655; void *p656; void *p657; void *p658; void *p659; void *p660; void *p661; void *p662; void *p663; void *p664; void *p665; void *p666; void *p667; void *p668; void *p669; void *p670; void *p671; void *p672; void *p673; void *p674; void *p675; void *p676; void *p677; void *p678; void *p679; void *p680; void *p681; void *p682; void *p683; void *p684; void *p685; void *p686; void *p687; void *p688; void *p689; void *p690; void *p691; void *p692; void *p693; void *p694; void *p695; void *p696; void *p697; void *p698; void *p699; void *p700; void *p701; void *p702; void *p703; void *p704; void *p705; void *p706; void *p707; void *p708; void *p709; void *p710; void *p711; void *p712; void *p713; void *p714; void *p715; void *p716; void *p717; void *p718; void *p719; void *p720; void *p721; void *p722; void *p723; void *p724; void *p725; void *p726; void *p727; void *p728; void *p729; void *p730; void *p731; void *p732; void *p733; void *p734; void *p735; void *p736; void *p737; void *p738; void *p739; void *p740; void *p741; void *p742; void *p743; void *p744; void *p745; void *p746; void *p747; void *p748; void *p749; void *p750; void *p751; void *p752; void *p753; void *p754; void *p755; void *p756; void *p757; void *p758; void *p759; void *p760; void *p761; void *p762; void *p763; void *p764; void *p765; void *p766; void *p767; void *p768; };
extern struct D002589f0Record D_002589F0;

struct D002589f0Record D_002589F0 = {
    dummy_enemy_main,
    dummy_enemy_main_b,
    func_0016CCE0,
    func_0016CD40,
    explosion_test_setup,
    explosion_test_main,
    debris_test_setup,
    debris_test_main,
    wreck_test_setup,
    wreck_test_main,
    heli_a_start,
    heli_a,
    heli_b_start,
    heli_b,
    heli_c_start,
    heli_c,
    heli_d_start,
    heli_d,
    heli_e_start,
    heli_e,
    heli_f_start,
    heli_f,
    heli_g_start,
    heli_g,
    heli_h_start,
    heli_h,
    stage1_midboss_start,
    stage1_midboss_main,
    stage1_boss_start,
    stage1_boss_main,
    stage1_boss_breakable_bullet_start,
    stage1_boss_breakable_bullet,
    small_tank_a_start,
    small_tank_a,
    small_tank_b_start,
    small_tank_b,
    stage3_midboss_start,
    stage3_midboss_main,
    func_001D6C90,
    func_001D6D60,
    stage3_cloud_start,
    stage3_cloud,
    func_001581F0,
    func_00158370,
    func_0015A510,
    func_0015A5B0,
    battleship_b_start,
    battleship_b,
    func_00159040,
    func_001590B0,
    func_0015AE10,
    func_0015AE70,
    func_0016EAA0,
    func_0016ED40,
    func_0016F940,
    func_0016FAE0,
    stage1_midboss_wreck_start,
    stage1_midboss_wreck,
    dummy_enemy_main,
    dummy_enemy_main_b,
    stage1_boss_side_bullet_start,
    stage1_boss_side_bullet,
    stage1_boss_breakable_bullet_b_start,
    stage1_boss_breakable_bullet_b,
    enemy_spawner_setup,
    enemy_spawner_main,
    enemy_spawner_setup,
    enemy_spawner_main,
    enemy_spawner_setup,
    enemy_spawner_main,
    enemy_spawner_setup,
    enemy_spawner_main,
    stage1_boss_entrance_start,
    stage1_boss_entrance,
    heli_a_start,
    heli_a,
    heli_b_start,
    heli_b,
    heli_c_start,
    heli_c,
    heli_d_start,
    heli_d,
    heli_e_start,
    heli_e,
    heli_f_start,
    heli_f,
    heli_g_start,
    heli_g,
    heli_h_start,
    heli_h,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    stage2_boss_start,
    stage2_boss_main,
    warning_sign_start,
    warning_sign,
    stage2_boss_shoulder_bullet_start,
    stage2_boss_shoulder_bullet,
    stage2_boss_spread_bullet_start,
    stage2_boss_spread_bullet,
    stage2_boss_cannon_shell_start,
    stage2_boss_cannon_shell,
    stage2_boss_dropped_bomb_start,
    stage2_boss_dropped_bomb,
    battleship_start,
    battleship,
    stage3_gun_a_start,
    stage3_gun_a,
    stage3_gun_b_start,
    stage3_gun_a,
    stage3_gun_c_start,
    stage3_gun_a,
    stage3_gun_d_start,
    stage3_gun_a,
    stage3_large_gun_start,
    stage3_large_gun,
    func_00159C60,
    func_00159CB0,
    func_0015AF00,
    func_0015B210,
    func_001571E0,
    func_00157260,
    func_001578B0,
    func_001579A0,
    stage4_boss_start,
    stage4_boss_main,
    stage4_boss_missile_start,
    stage4_boss_missile,
    stage4_boss_cutter_start,
    stage4_boss_cutter,
    stage5_midboss4_arrival_start,
    stage5_midboss4_arrival,
    stage5_midboss4_start,
    stage5_midboss4_main,
    stage5_small_turret_start,
    stage5_small_turret,
    stage5_bee_hatch_start,
    stage5_bee_hatch,
    stage5_midboss3_start,
    stage5_midboss3_main,
    stage5_small_spider_turret_start,
    stage5_small_spider_turret,
    stage5_small_spider_head_start,
    stage5_small_spider_head,
    stage5_large_spider_turret_start,
    stage5_large_spider_turret,
    stage5_large_spider_head_start,
    stage5_large_spider_head,
    stage5_midboss5_start,
    stage5_midboss5_main,
    stage2_boss_ripple_start,
    stage2_boss_ripple,
    stage5_midboss5_small_missile_start,
    stage5_midboss5_small_missile,
    stage5_midboss5_small_blast_start,
    stage5_midboss5_small_blast,
    stage5_midboss5_large_missile_start,
    stage5_midboss5_large_missile,
    stage5_midboss5_large_blast_start,
    stage5_midboss5_large_blast,
    stage5_midboss5_drone_start,
    stage5_midboss5_drone,
    stage5_midboss4_wave_beam_start,
    stage5_midboss4_wave_beam,
    stage5_spiderling_start,
    stage5_spiderling,
    stage5_bee_drone_start,
    stage5_bee_drone,
    func_001F93D0,
    func_001F9450,
    func_001F9550,
    func_001F95D0,
    stage5_midboss5_spin_drone_start,
    stage5_midboss5_spin_drone,
    func_00157D90,
    func_00157DC0,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    dummy_enemy_main,
    dummy_enemy_main_b,
    map_cell_test_setup,
    map_cell_test_main,
    dummy_enemy_first,
    func_0016CCD0,
    explosion_test_first,
    debris_test_first,
    wreck_test_first,
    heli_a_first,
    heli_b_first,
    heli_c_first,
    heli_d_first,
    heli_e_first,
    heli_f_first,
    heli_g_first,
    heli_h_first,
    stage1_midboss_first,
    stage1_boss_first,
    stage1_boss_breakable_bullet_first,
    small_tank_a_first,
    small_tank_b_first,
    stage3_midboss_first,
    func_001D6C80,
    stage3_cloud_first,
    func_001581E0,
    func_0015A500,
    battleship_b_first,
    func_00159030,
    func_0015AE00,
    func_0016EA90,
    func_0016F930,
    stage1_midboss_wreck_first,
    dummy_enemy_first,
    stage1_boss_side_bullet_first,
    stage1_boss_breakable_bullet_b_first,
    enemy_spawner_first,
    enemy_spawner_first,
    enemy_spawner_first,
    enemy_spawner_first,
    stage1_boss_entrance_first,
    heli_a_first,
    heli_b_first,
    heli_c_first,
    heli_d_first,
    heli_e_first,
    heli_f_first,
    heli_g_first,
    heli_h_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    stage2_boss_first,
    warning_sign_first,
    stage2_boss_shoulder_bullet_first,
    stage2_boss_spread_bullet_first,
    stage2_boss_cannon_shell_first,
    stage2_boss_dropped_bomb_first,
    battleship_first,
    stage3_gun_a_first,
    stage3_gun_b_first,
    stage3_gun_c_first,
    stage3_gun_d_first,
    stage3_large_gun_first,
    func_00159C50,
    func_0015AEF0,
    func_001571D0,
    func_001578A0,
    stage4_boss_first,
    stage4_boss_missile_first,
    stage4_boss_cutter_first,
    stage5_midboss4_arrival_first,
    stage5_midboss4_first,
    stage5_small_turret_first,
    stage5_bee_hatch_first,
    stage5_midboss3_first,
    stage5_small_spider_turret_first,
    stage5_small_spider_head_first,
    stage5_large_spider_turret_first,
    stage5_large_spider_head_first,
    stage5_midboss5_first,
    stage2_boss_ripple_first,
    stage5_midboss5_small_missile_first,
    stage5_midboss5_small_blast_first,
    stage5_midboss5_large_missile_first,
    stage5_midboss5_large_blast_first,
    stage5_midboss5_drone_first,
    stage5_midboss4_wave_beam_first,
    stage5_spiderling_first,
    stage5_bee_drone_first,
    func_001F93C0,
    func_001F9540,
    stage5_midboss5_spin_drone_first,
    func_00157D80,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    dummy_enemy_first,
    map_cell_test_first,
    { 0x0000, 0x1566, 0x0000, 0x1567, 0x0000, 0x1568, 0x0000, 0x1569, 0x0000, 0x156A, 0x0000, 0x156B, 0x0000, 0x156C, 0x0000, 0x156D, 0x0000, 0x156E, 0x0000, 0x156F, 0x0000, 0x1570, 0x0000, 0x1571, 0x0000, 0x1572, 0x0000, 0x1573, 0x0000, 0x1574, 0x0000, 0x1575, 0x0000, 0x1576, 0x0000, 0x1577, 0x0000, 0x1578, 0x0000, 0x1579, 0x0000, 0x157A, 0x0000, 0x157B, 0x0000, 0x157C, 0x0000, 0x157D, 0x0000, 0x157E, 0x0000, 0x157F, 0x0000, 0x1580, 0x0000, 0x1581, 0x0000, 0x1582, 0x0000, 0x1583, 0x0000, 0x1584, 0x0000, 0x1585, 0x0000, 0x1586, 0x0000, 0x1587, 0x0000, 0x1588, 0x0000, 0x1589, 0x0000, 0x158A, 0x0000, 0x158B, 0x0000, 0x158C, 0x0000, 0x158D, 0x0000, 0x158E, 0x0000, 0x158F, 0x0000, 0x1590, 0x0000, 0x1591, 0x0000, 0x1592, 0x0000, 0x1593, 0x0000, 0x1594, 0x0000, 0x1595, 0x0000, 0x1596, 0x0000, 0x1597, 0x0000, 0x1598, 0x0000, 0x1599, 0x0000, 0x159A, 0x0000, 0x159B, 0x0000, 0x159C, 0x0000, 0x159D, 0x0000, 0x159E, 0x0000, 0x159F, 0x0000, 0x15A0, 0x0000, 0x15A1, 0x0000, 0x15A2, 0x0000, 0x15A3, 0x0000, 0x15A4, 0x0000, 0x15A5, 0x0000, 0x15A6, 0x0000, 0x15A7, 0x0000, 0x15A8, 0x0000, 0x15A9, 0x0000, 0x15AA, 0x0000, 0x15AB, 0x0000, 0x15AC, 0x0000, 0x15AD, 0x0000, 0x15AE, 0x0000, 0x15AF, 0x0000, 0x15B0, 0x0000, 0x15B1, 0x0000, 0x15B2, 0x0000, 0x15B3, 0x0000, 0x15B4, 0x0000, 0x15B5, 0x0000, 0x15B6, 0x0000, 0x15B7, 0x0000, 0x15B8, 0x0000, 0x15B9, 0x0000, 0x15BA, 0x0000, 0x15BB, 0x0000, 0x15BC, 0x0000, 0x15BD, 0x0000, 0x15BE, 0x0000, 0x15BF, 0x0000, 0x15C0, 0x0000, 0x15C1, 0x0000, 0x15C2, 0x0000, 0x15C3, 0x0000, 0x15C4, 0x0000, 0x15C5, 0x0000, 0x15C6, 0x0000, 0x15C7, 0x0000, 0x15C8, 0x0000, 0x15C9, 0x0000, 0x15CA, 0x0000, 0x15CB, 0x0000, 0x15CC, 0x0000, 0x15CD, 0x0000, 0x15CE, 0x0000, 0x15CF, 0x0000, 0x15D0, 0x0000, 0x15D1, 0x0000, 0x15D2, 0x0000, 0x15D3, 0x0000, 0x15D4, 0x0000, 0x15D5, 0x0000, 0x15D6, 0x0000, 0x15D7, 0x0000, 0x15D8, 0x0000, 0x15D9, 0x0000, 0x15DA, 0x0000, 0x15DB, 0x0000, 0x15DC, 0x0000, 0x15DD, 0x0000, 0x15DE, 0x0000, 0x15DF, 0x0000, 0x15E0, 0x0000, 0x15E1, 0x0000, 0x15E2, 0x0000, 0x15E3, 0x0000, 0x15E4, 0x0000, 0x15E5, 0x0000, 0x15E6, 0x0000, 0x15E7, 0x0000, 0x15E8, 0x0000, 0x15E9, 0x0000, 0x15EA, 0x0000, 0x15EB, 0x0000, 0x15EC, 0x0000, 0x15ED, 0x0000, 0x15EE, 0x0000, 0x15EF, 0x0000, 0x15F0, 0x0000, 0x15F1, 0x0000, 0x15F2, 0x0000, 0x15F3, 0x0000, 0x15F4, 0x0000, 0x15F5, 0x0000, 0x15F6, 0x0000, 0x15F7, 0x0000, 0x15F8, 0x0000, 0x15F9, 0x0000, 0x15FA, 0x0000, 0x15FB, 0x0000, 0x15FC, 0x0000, 0x15FD, 0x0000, 0x15FE, 0x0000, 0x15FF, 0x0000, 0x1600, 0x0000, 0x1601, 0x0000, 0x1602, 0x0000, 0x1603, 0x0000, 0x1604, 0x0000, 0x1605, 0x0000, 0x1606, 0x0000, 0x1607, 0x0000, 0x1608, 0x0000, 0x1609, 0x0000, 0x160A, 0x0000, 0x160B, 0x0000, 0x160C, 0x0000, 0x160D, 0x0000, 0x160E, 0x0000, 0x160F, 0x0000, 0x1610, 0x0000, 0x1611, 0x0000, 0x1612, 0x0000, 0x1613, 0x0000, 0x1614, 0x0000, 0x1615, 0x0000, 0x1616, 0x0000, 0x1617, 0x0000, 0x1618, 0x0000, 0x1619, 0x0000, 0x161A, 0x0000, 0x161B, 0x0000, 0x161C, 0x0000, 0x161D, 0x0000, 0x161E, 0x0000, 0x161F, 0x0000, 0x1620, 0x0000, 0x1621, 0x0000, 0x1622, 0x0000, 0x1623, 0x0000, 0x1624, 0x0000, 0x1625, 0x0000, 0x1627, 0x0000, 0x1628, 0x0000, 0x1629, 0x0000, 0x162A, 0x0000, 0x162B, 0x0000, 0x162C, 0x0000, 0x162D, 0x0000, 0x162E, 0x0000, 0x162F, 0x0000, 0x1630, 0x0000, 0x1631, 0x0000, 0x1632, 0x0000, 0x1633, 0x0000, 0x1634, 0x0000, 0x1635, 0x0000, 0x1636, 0x0000, 0x1637, 0x0000, 0x1638, 0x0000, 0x1639, 0x0000, 0x163A, 0x0000, 0x163B, 0x0000, 0x163C, 0x0000, 0x163D, 0x0000, 0x163E, 0x0000, 0x163F, 0x0000, 0x1640, 0x0000, 0x1641, 0x0000, 0x1642, 0x0000, 0x1643, 0x0000, 0x1644, 0x0000, 0x1645, 0x0000, 0x1646, 0x0540, 0x0000, 0x0500, 0x00C0, 0x04C0, 0x0180, 0x0480, 0x0200, 0x0400, 0x0280, 0x0340, 0x0300, 0x0280, 0x0340, 0x01C0, 0x0380, 0x0100, 0x03C0, 0x0040, 0x0380, 0xFF80, 0x0340, 0xFEC0, 0x0300, 0xFE00, 0x0280, 0xFD80, 0x0200, 0xFD40, 0x0180, 0xFD00, 0x00C0, 0xFCC0, 0x0000, 0xFD00, 0xFF40, 0xFD40, 0xFE80, 0xFD80, 0xFE00, 0xFE00, 0xFD80, 0xFEC0, 0xFD00, 0xFF80, 0xFCC0, 0x0040, 0xFC80, 0x0100, 0xFC40, 0x01C0, 0xFC80, 0x0280, 0xFCC0, 0x0340, 0xFD00, 0x0400, 0xFD80, 0x0480, 0xFE00, 0x04C0, 0xFE80, 0x0500, 0xFF40, 0x0400, 0xFEC0, 0x0400, 0x0140, 0x0400, 0xFF80, 0x0380, 0x01C0, 0x0400, 0x0040, 0x0300, 0x0280, 0x03C0, 0x0100, 0x0240, 0x0300, 0x0380, 0x0180, 0x0180, 0x0380, 0x0300, 0x0240, 0x00C0, 0x03C0, 0x0280, 0x02C0, 0x0000, 0x03C0, 0x01C0, 0x0340, 0xFF00, 0x03C0, 0x00C0, 0x0380, 0xFE00, 0x0380, 0x0000, 0x03C0, 0xFD40, 0x0340, 0xFF40, 0x03C0, 0xFC80, 0x02C0, 0xFE40, 0x03C0, 0xFC00, 0x0240, 0xFDC0, 0x0380, 0xFBC0, 0x0180, 0xFD00, 0x0300, 0xFB80, 0x0100, 0xFC80, 0x0280, 0xFB80, 0x0040, 0xFC40, 0x01C0, 0xFB80, 0xFF80, 0xFBC0, 0x0140, 0xFBC0, 0xFEC0, 0xFB80, 0x0080, 0xFC40, 0xFE40, 0xFB80, 0xFFC0, 0xFC80, 0xFD80, 0xFB80, 0xFF00, 0xFD00, 0xFD00, 0xFBC0, 0xFE80, 0xFDC0, 0xFC80, 0xFC00, 0xFDC0, 0xFE40, 0xFC40, 0xFC80, 0xFD40, 0xFF40, 0xFC40, 0xFD40, 0xFCC0, 0x0000, 0xFC40, 0xFE00, 0xFC80, 0x00C0, 0xFC80, 0xFF00, 0xFC40, 0x01C0, 0xFCC0, 0x0000, 0xFC40, 0x0280, 0xFD40, 0x00C0, 0xFC40, 0x0300, 0xFDC0, 0x0180, 0xFC80, 0x0380, 0xFE80, 0x0240, 0xFD00, 0x03C0, 0xFF00, 0x0300, 0xFD80, 0x0400, 0xFFC0, 0x0380, 0xFE40, 0x0400, 0x0080, 0x0400, 0x0000, 0x0400, 0x0080, 0x03C0, 0x0100, 0x0380, 0x0180, 0x0300, 0x0200, 0x0280, 0x0280, 0x0200, 0x02C0, 0x0140, 0x0300, 0x0080, 0x0300, 0xFFC0, 0x0300, 0xFF00, 0x02C0, 0xFE80, 0x0280, 0xFE00, 0x0200, 0xFD80, 0x0180, 0xFD40, 0x0100, 0xFD00, 0x0080, 0xFD00, 0x0000, 0xFD00, 0xFF80, 0xFD40, 0xFF00, 0xFD80, 0xFE80, 0xFE00, 0xFE00, 0xFE80, 0xFD80, 0xFF00, 0xFD40, 0xFFC0, 0xFD00, 0x0080, 0xFD00, 0x0140, 0xFD00, 0x0200, 0xFD40, 0x0280, 0xFD80, 0x0300, 0xFE00, 0x0380, 0xFE80, 0x03C0, 0xFF00, 0x0400, 0xFF80, 0x0500, 0x0000, 0x04C0, 0x00C0, 0x0480, 0x0180, 0x0440, 0x0200, 0x03C0, 0x0280, 0x0300, 0x0300, 0x0200, 0x0340, 0x0140, 0x0380, 0x0040, 0x03C0, 0xFF40, 0x0380, 0xFE80, 0x0340, 0xFD80, 0x0300, 0xFCC0, 0x0280, 0xFC40, 0x0200, 0xFC00, 0x0180, 0xFBC0, 0x00C0, 0xFB80, 0x0000, 0xFBC0, 0xFF40, 0xFC00, 0xFE80, 0xFC40, 0xFE00, 0xFCC0, 0xFD80, 0xFD80, 0xFD00, 0xFE80, 0xFCC0, 0xFF40, 0xFC80, 0x0040, 0xFC40, 0x0140, 0xFC80, 0x0200, 0xFCC0, 0x0300, 0xFD00, 0x03C0, 0xFD80, 0x0440, 0xFE00, 0x0480, 0xFE80, 0x04C0, 0xFF40, 0x0840, 0xFE80, 0x0840, 0x01C0, 0x0840, 0xFF40, 0x0780, 0x0300, 0x07C0, 0x0140, 0x06C0, 0x0400, 0x0740, 0x0280, 0x0580, 0x0540, 0x06C0, 0x0380, 0x0440, 0x0600, 0x0600, 0x0480, 0x0300, 0x0680, 0x0540, 0x0540, 0x0140, 0x06C0, 0x0380, 0x0600, 0xFFC0, 0x06C0, 0x0200, 0x0640, 0xFE00, 0x0640, 0x0040, 0x06C0, 0xFC00, 0x0600, 0xFE80, 0x06C0, 0xFAC0, 0x0540, 0xFD40, 0x0680, 0xFA00, 0x0480, 0xFC00, 0x0600, 0xF980, 0x0380, 0xFB00, 0x0540, 0xF900, 0x0280, 0xFA40, 0x0400, 0xF8C0, 0x0140, 0xF940, 0x0300, 0xF880, 0xFF40, 0xF880, 0x01C0, 0xF880, 0xFE80, 0xF940, 0xFD00, 0xF880, 0x00C0, 0xFA40, 0xFC00, 0xF8C0, 0xFEC0, 0xFB00, 0xFAC0, 0xF900, 0xFD80, 0xFC00, 0xFA00, 0xF980, 0xFC80, 0xFD40, 0xF980, 0xFA00, 0xFB80, 0xFE80, 0xF940, 0xFAC0, 0xFAC0, 0x0040, 0xF940, 0xFC00, 0xFA00, 0x0200, 0xF9C0, 0xFE00, 0xF9C0, 0x0380, 0xFA00, 0xFFC0, 0xF940, 0x0540, 0xFAC0, 0x0140, 0xF940, 0x0600, 0xFB80, 0x0300, 0xF980, 0x06C0, 0xFC80, 0x0440, 0xFA00, 0x0740, 0xFD80, 0x0580, 0xFAC0, 0x07C0, 0xFEC0, 0x06C0, 0xFC00, 0x0840, 0x00C0, 0x0780, 0xFD00, 0x0600, 0x0000, 0x0600, 0x0100, 0x05C0, 0x01C0, 0x0500, 0x0280, 0x0480, 0x0380, 0x03C0, 0x0440, 0x02C0, 0x04C0, 0x0180, 0x0500, 0x0040, 0x0540, 0xFF00, 0x0500, 0xFDC0, 0x04C0, 0xFCC0, 0x0440, 0xFC00, 0x0380, 0xFB80, 0x0280, 0xFAC0, 0x01C0, 0xFA80, 0x0100, 0xFA80, 0x0000, 0xFA80, 0xFF00, 0xFAC0, 0xFE40, 0xFB80, 0xFD80, 0xFC00, 0xFC80, 0xFCC0, 0xFBC0, 0xFDC0, 0xFB40, 0xFF00, 0xFB00, 0x0040, 0xFAC0, 0x0180, 0xFB00, 0x02C0, 0xFB40, 0x03C0, 0xFBC0, 0x0480, 0xFC80, 0x0500, 0xFD80, 0x05C0, 0xFE40, 0x0600, 0xFF00, 0x0166, 0x0000, 0x0162, 0x0016, 0x015C, 0x002C, 0x0154, 0x0044, 0x014A, 0x0058, 0x0138, 0x0070, 0x0128, 0x0084, 0x0112, 0x0096, 0x00FA, 0x00A8, 0x00E2, 0x00B6, 0x00C6, 0x00C4, 0x00A6, 0x00D0, 0x0086, 0x00DC, 0x0066, 0x00E2, 0x0042, 0x00E8, 0x0020, 0x00EC, 0x0000, 0x00EE, 0xFFE0, 0x00EC, 0xFFBE, 0x00E8, 0xFF9A, 0x00E2, 0xFF7A, 0x00DC, 0xFF5A, 0x00D0, 0xFF3A, 0x00C4, 0xFF1E, 0x00B6, 0xFF06, 0x00A8, 0xFEEE, 0x0096, 0xFED8, 0x0084, 0xFEC8, 0x0070, 0xFEB6, 0x0058, 0xFEAC, 0x0044, 0xFEA4, 0x002C, 0xFE9E, 0x0016, 0xFE9A, 0x0000, 0xFE9E, 0xFFEA, 0xFEA4, 0xFFD4, 0xFEAC, 0xFFBC, 0xFEB6, 0xFFA8, 0xFEC8, 0xFF90, 0xFED8, 0xFF7C, 0xFEEE, 0xFF6A, 0xFF06, 0xFF58, 0xFF1E, 0xFF4A, 0xFF3A, 0xFF3C, 0xFF5A, 0xFF30, 0xFF7A, 0xFF24, 0xFF9A, 0xFF1E, 0xFFBE, 0xFF18, 0xFFE0, 0xFF14, 0x0000, 0xFF12, 0x0020, 0xFF14, 0x0042, 0xFF18, 0x0066, 0xFF1E, 0x0086, 0xFF24, 0x00A6, 0xFF30, 0x00C6, 0xFF3C, 0x00E2, 0xFF4A, 0x00FA, 0xFF58, 0x0112, 0xFF6A, 0x0128, 0xFF7C, 0x0138, 0xFF90, 0x014A, 0xFFA8, 0x0154, 0xFFBC, 0x015C, 0xFFD4, 0x0162, 0xFFEA, 0x02CC, 0x0000, 0x02C4, 0x002C, 0x02B8, 0x0058, 0x02A8, 0x0088, 0x0294, 0x00B0, 0x0270, 0x00E0, 0x0250, 0x0108, 0x0224, 0x012C, 0x01F4, 0x0150, 0x01C4, 0x016C, 0x018C, 0x0188, 0x014C, 0x01A0, 0x010C, 0x01B8, 0x00CC, 0x01C4, 0x0084, 0x01D0, 0x0040, 0x01D8, 0x0000, 0x01DC, 0xFFC0, 0x01D8, 0xFF7C, 0x01D0, 0xFF34, 0x01C4, 0xFEF4, 0x01B8, 0xFEB4, 0x01A0, 0xFE74, 0x0188, 0xFE3C, 0x016C, 0xFE0C, 0x0150, 0xFDDC, 0x012C, 0xFDB0, 0x0108, 0xFD90, 0x00E0, 0xFD6C, 0x00B0, 0xFD58, 0x0088, 0xFD48, 0x0058, 0xFD3C, 0x002C, 0xFD34, 0x0000, 0xFD3C, 0xFFD4, 0xFD48, 0xFFA8, 0xFD58, 0xFF78, 0xFD6C, 0xFF50, 0xFD90, 0xFF20, 0xFDB0, 0xFEF8, 0xFDDC, 0xFED4, 0xFE0C, 0xFEB0, 0xFE3C, 0xFE94, 0xFE74, 0xFE78, 0xFEB4, 0xFE60, 0xFEF4, 0xFE48, 0xFF34, 0xFE3C, 0xFF7C, 0xFE30, 0xFFC0, 0xFE28, 0x0000, 0xFE24, 0x0040, 0xFE28, 0x0084, 0xFE30, 0x00CC, 0xFE3C, 0x010C, 0xFE48, 0x014C, 0xFE60, 0x018C, 0xFE78, 0x01C4, 0xFE94, 0x01F4, 0xFEB0, 0x0224, 0xFED4, 0x0250, 0xFEF8, 0x0270, 0xFF20, 0x0294, 0xFF50, 0x02A8, 0xFF78, 0x02B8, 0xFFA8, 0x02C4, 0xFFD4, 0x0432, 0x0000, 0x0426, 0x0042, 0x0414, 0x0084, 0x03FC, 0x00CC, 0x03DE, 0x0108, 0x03A8, 0x0150, 0x0378, 0x018C, 0x0336, 0x01C2, 0x02EE, 0x01F8, 0x02A6, 0x0222, 0x0252, 0x024C, 0x01F2, 0x0270, 0x0192, 0x0294, 0x0132, 0x02A6, 0x00C6, 0x02B8, 0x0060, 0x02C4, 0x0000, 0x02CA, 0xFFA0, 0x02C4, 0xFF3A, 0x02B8, 0xFECE, 0x02A6, 0xFE6E, 0x0294, 0xFE0E, 0x0270, 0xFDAE, 0x024C, 0xFD5A, 0x0222, 0xFD12, 0x01F8, 0xFCCA, 0x01C2, 0xFC88, 0x018C, 0xFC58, 0x0150, 0xFC22, 0x0108, 0xFC04, 0x00CC, 0xFBEC, 0x0084, 0xFBDA, 0x0042, 0xFBCE, 0x0000, 0xFBDA, 0xFFBE, 0xFBEC, 0xFF7C, 0xFC04, 0xFF34, 0xFC22, 0xFEF8, 0xFC58, 0xFEB0, 0xFC88, 0xFE74, 0xFCCA, 0xFE3E, 0xFD12, 0xFE08, 0xFD5A, 0xFDDE, 0xFDAE, 0xFDB4, 0xFE0E, 0xFD90, 0xFE6E, 0xFD6C, 0xFECE, 0xFD5A, 0xFF3A, 0xFD48, 0xFFA0, 0xFD3C, 0x0000, 0xFD36, 0x0060, 0xFD3C, 0x00C6, 0xFD48, 0x0132, 0xFD5A, 0x0192, 0xFD6C, 0x01F2, 0xFD90, 0x0252, 0xFDB4, 0x02A6, 0xFDDE, 0x02EE, 0xFE08, 0x0336, 0xFE3E, 0x0378, 0xFE74, 0x03A8, 0xFEB0, 0x03DE, 0xFEF8, 0x03FC, 0xFF34, 0x0414, 0xFF7C, 0x0426, 0xFFBE },
    mid_flyer_a_start,
    mid_flyer_a,
    mid_flyer_b_start,
    mid_flyer_b,
    mid_flyer_c_start,
    mid_flyer_c,
    mid_flyer_d_start,
    mid_flyer_d,
    mid_tank_vertical_start,
    mid_tank_vertical,
    item_carrier_start,
    item_carrier,
    bomb_carrier_start,
    item_carrier,
    shooter_drone_start,
    shooter_drone,
    mid_tank_horizontal_start,
    mid_tank_horizontal,
    ground_turret_b_start,
    ground_turret_b,
    bee_container_start,
    bee_container,
    star_container_start,
    star_container,
    func_001CBD60,
    func_001CC0A0,
    water_flower_turret_start,
    water_flower_turret,
    ground_turret_a_start,
    ground_turret_a,
    ground_turret_c_start,
    ground_turret_c,
    stage2_blooming_base_start,
    stage2_blooming_base,
    stage2_long_warehouse_start,
    stage2_long_warehouse,
    stage2_square_warehouse_start,
    stage2_square_warehouse,
    stage2_gymnasium_start,
    stage2_gymnasium,
    stage2_sliding_gun_start,
    stage2_sliding_gun,
    mid_flyer_e_start,
    mid_flyer_e,
    stage2_wrecker_gun_start,
    stage2_wrecker_gun,
    mid_tank_horizontal_b_start,
    mid_tank_horizontal_b,
    stage2_boss_hangar_start,
    stage2_boss_hangar,
    stage3_boss_timber_start,
    stage3_boss_timber,
    stage3_boss_lid_bullet_start,
    stage3_boss_lid_bullet,
    stage4_gate_start,
    stage4_gate,
    stage4_lift_start,
    stage4_lift,
    stage4_heavy_cannon_start,
    stage4_heavy_cannon,
    stage4_heavy_cannon_casing_start,
    stage4_heavy_cannon_casing,
    stage4_wave_cannon_start,
    stage4_wave_cannon,
    stage3_boss_start,
    stage3_boss_main,
    stage4_reactor_start,
    stage4_reactor,
    crane_turret_start,
    crane_turret,
    rail_turret_start,
    rail_turret,
    stage4_tachyon_particle_start,
    stage4_tachyon_particle,
    func_00168120,
    func_001683C0,
    formation_fire_timer_setup,
    formation_fire_timer_main,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    stage5_boss_start,
    stage5_boss_main,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    enemy_remove_entry_entry,
    enemy_remove_entry,
    mid_flyer_a_first,
    mid_flyer_b_first,
    mid_flyer_c_first,
    mid_flyer_d_first,
    mid_tank_vertical_first,
    item_carrier_first,
    bomb_carrier_first,
    shooter_drone_first,
    mid_tank_horizontal_first,
    ground_turret_b_first,
    bee_container_first,
    star_container_first,
    func_001CBD50,
    water_flower_turret_first,
    ground_turret_a_first,
    ground_turret_c_first,
    stage2_blooming_base_first,
    stage2_long_warehouse_first,
    stage2_square_warehouse_first,
    stage2_gymnasium_first,
    stage2_sliding_gun_first,
    mid_flyer_e_first,
    stage2_wrecker_gun_first,
    mid_tank_horizontal_b_first,
    stage2_boss_hangar_first,
    stage3_boss_timber_first,
    stage3_boss_lid_bullet_first,
    stage4_gate_first,
    stage4_lift_first,
    stage4_heavy_cannon_first,
    stage4_heavy_cannon_casing_first,
    stage4_wave_cannon_first,
    stage3_boss_first,
    stage4_reactor_first,
    crane_turret_first,
    rail_turret_first,
    stage4_tachyon_particle_first,
    func_00168110,
    formation_fire_timer_first,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    stage5_boss_first,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
    func_0015C440,
};
