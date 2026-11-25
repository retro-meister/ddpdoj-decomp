#include "common.h"
#include "task.h"
#include "entity.h"
#include "sdk/ps2sdk.h"
#include "cd.h"
#include "replay.h"

extern u16 D_0024E740[];
extern u16 D_0024EB30[];
extern u16 D_0024EBC0[];
extern u16 D_0024EDB0[];
extern u16 D_0024EF30[];
extern u16 D_00250CD0[];
extern u16 D_00250D20[];
extern u16 D_00250E00[];
extern u16 D_00251AE0[];
extern u16 D_00251B00[];
extern u16 D_00264C30[];
extern u16 D_00264D00[];
extern u16 D_00264E10[];
extern u16 D_00264E80[];
extern u16 D_00264EA0[];

void music_start_when_ready(void);
void sound_update_bgm_fade(void);
s32 func_001981F0(void);
void func_001984C0(void);
void func_00198C40();
void func_00198D90();
void func_00198EF0(void);
void func_00198F30(void);
void func_001994F0(void);
void func_00199540(void);
void func_00199550(void);
void func_00199560(void);
void func_00199710(void);
void func_00199970(void);
void func_00199A50(void);
void func_00199D50(void);
void func_0019A050(void);
void func_0019A2B0(void);
void func_0019A410(void);
void func_0019A520(void);
void func_0019A5B0(void);
void func_0019A640(void);
void func_0019A870(void);

extern const char D_002784E0[];
extern const char D_00278500[];
extern const char D_00278520[];
extern const char D_00278540[];
extern const char D_00278560[];
extern const char D_00278580[];
extern const char D_002785A0[];
extern const char D_002785C0[];
extern const char D_002785E0[];
extern const char D_00278600[];
extern const char D_00278620[];
extern const char D_00278640[];
extern const char D_00278660[];
extern const char D_00278680[];
extern const char D_002786A0[];
extern const char D_002786C0[];
extern const char D_002786E0[];
extern const char D_00278700[];
extern const char D_00278720[];
extern const char D_00278740[];
extern const char D_00278760[];
extern const char D_00278780[];
extern const char D_002787A0[];
extern const char D_002787C0[];
extern const char D_002787E0[];
extern const char D_00278800[];
extern const char D_00278820[];
extern const char D_00278840[];
extern const char D_00278860[];
extern const char D_00278880[];
extern const char D_002788A0[];
extern const char D_002788C0[];
extern const char D_002788E0[];
extern const char D_00278900[];
extern const char D_00278920[];
extern const char D_00278940[];
extern const char D_00278960[];
extern const char D_00278980[];
extern const char D_002789A0[];
extern const char D_002789C0[];
extern const char D_002789E0[];
extern const char D_00278A00[];
extern const char D_00278A20[];
extern const char D_00278A40[];
extern const char D_00278A60[];
extern const char D_00278A80[];
extern const char D_00278AA0[];
extern const char D_00278AC0[];
extern const char D_00278AE0[];
extern const char D_00278B00[];
extern const char D_00278B20[];
extern const char D_00278B40[];
extern const char D_00278B60[];
extern const char D_00278B80[];
extern const char D_00278BA0[];
extern const char D_00278BC0[];
extern const char D_00278BE0[];
extern const char D_00278C00[];
extern const char D_00278C20[];
extern const char D_00278C40[];
extern const char D_00278C60[];
extern const char D_00278C80[];
extern const char D_00278CA0[];
extern const char D_00278CC0[];
extern const char D_00278CE0[];
extern const char D_00278D00[];
extern const char D_00278D20[];
extern const char D_00278D40[];
extern const char D_00278D60[];
extern const char D_00278D80[];
extern const char D_00278DA0[];
extern const char D_00278DC0[];
extern const char D_00278DE0[];
extern const char D_00278E00[];
extern const char D_00278E20[];
extern const char D_00278E40[];
extern const char D_00278E60[];
extern const char D_00278E80[];
extern const char D_00278EA0[];
extern const char D_00278EC0[];
extern const char D_00278EE0[];
extern const char D_00278F00[];
extern const char D_00278F20[];
extern const char D_00278F40[];
extern const char D_00278F60[];
extern const char D_00278F80[];
extern const char D_00278FA0[];
extern const char D_00278FC0[];
extern const char D_00278FE0[];
extern const char D_00279000[];
extern const char D_00279020[];
extern const char D_00279040[];
extern const char D_00279060[];
extern const char D_00279080[];
extern const char D_002790A0[];
extern const char D_002790C0[];
extern const char D_002790E0[];
extern const char D_00279100[];
extern const char D_00279120[];
extern const char D_00279140[];
extern const char D_00279160[];
extern const char D_00279180[];
extern const char D_002791A0[];
extern const char D_002791C0[];
extern const char D_002791E0[];
extern const char D_00279200[];
extern const char D_00279220[];
extern const char D_00279240[];
extern const char D_00279260[];
extern const char D_00279280[];
extern const char D_002792A0[];
extern const char D_002792C0[];
extern const char D_002792E0[];
extern const char D_00279300[];
extern const char D_00279320[];
extern const char D_00279340[];
extern const char D_00279360[];
extern const char D_00279380[];
extern const char D_002793A0[];
extern const char D_002793C0[];
extern const char D_002793E0[];
extern const char D_00279400[];
extern const char D_00279420[];
extern const char D_00279440[];
extern const char D_00279460[];
extern const char D_00279480[];
extern const char D_002794A0[];
extern const char D_002794C0[];
extern const char D_002794E0[];
extern const char D_00279500[];
extern const char D_00279520[];
extern const char D_00279540[];
extern const char D_00279560[];
extern const char D_00279580[];
extern const char D_002795A0[];
extern const char D_002795C0[];
extern const char D_002795E0[];
extern const char D_00279600[];
extern const char D_00279620[];
extern const char D_00279640[];
extern const char D_00279660[];
extern const char D_00279680[];
extern const char D_002796A0[];
extern const char D_002796C0[];
extern const char D_002796E0[];
extern const char D_00279700[];
extern const char D_00279720[];
extern const char D_00279740[];
extern const char D_00279760[];
extern const char D_00279780[];
extern const char D_002797A0[];
extern const char D_002797C0[];
extern const char D_002797E0[];
extern const char D_00279800[];
extern const char D_00279820[];
extern const char D_00279840[];
extern const char D_00279860[];
extern const char D_00279880[];
extern const char D_002798A0[];
extern const char D_002798C0[];
extern const char D_002798E0[];
extern const char D_00279900[];
extern const char D_00279920[];
extern const char D_00279940[];
extern const char D_00279960[];
extern const char D_00279980[];
extern const char D_002799A0[];
extern const char D_002799C0[];
extern const char D_002799E0[];
extern const char D_00279A00[];
extern const char D_00279A20[];
extern const char D_00279A40[];
extern const char D_00279A60[];
extern const char D_00279A80[];
extern const char D_00279AA0[];
extern const char D_00279AC0[];
extern const char D_00279AE0[];
extern const char D_00279B00[];
extern const char D_00279B20[];
extern const char D_00279B40[];
extern const char D_00279B60[];
extern const char D_00279B80[];
extern const char D_00279BA0[];
extern const char D_00279BC0[];
extern const char D_00279BE0[];
extern const char D_00279C00[];
extern const char D_00279C20[];
extern const char D_00279C40[];
extern const char D_00279C60[];
extern const char D_00279C80[];
extern const char D_00279CA0[];
extern const char D_00279CC0[];
extern const char D_00279CE0[];
extern const char D_00279D00[];
extern const char D_00279D20[];
extern const char D_00279D40[];
extern const char D_00279D60[];
extern const char D_00279D80[];
extern const char D_00279DA0[];
extern const char D_00279DC0[];
extern const char D_00279DE0[];
extern const char D_00279E00[];
extern const char D_00279E20[];
extern const char D_00279E40[];
extern const char D_00279E60[];
extern const char D_00279E80[];
extern const char D_00279EA0[];
extern const char D_00279EC0[];
extern const char D_00279EE0[];
extern const char D_00279F00[];
extern const char D_00279F20[];
extern const char D_00279F40[];
extern const char D_00279F60[];
extern const char D_00279F80[];
extern const char D_00279FA0[];
extern const char D_00279FC0[];
extern const char D_00279FE0[];
extern const char D_0027A000[];
extern const char D_0027A020[];
extern const char D_0027A040[];
extern const char D_0027A060[];
extern const char D_0027A080[];
extern const char D_0027A0A0[];
extern const char D_0027A0C0[];
extern const char D_0027A0E0[];
extern const char D_0027A100[];
extern const char D_0027A120[];
extern const char D_0027A140[];
extern const char D_0027A160[];
extern const char D_0027A180[];
extern const char D_0027A1A0[];
extern const char D_0027A1C0[];
extern const char D_0027A1E0[];
extern const char D_0027A200[];
extern const char D_0027A220[];
extern const char D_0027A240[];
extern const char D_0027A260[];
extern const char D_0027A280[];
extern const char D_0027A2A0[];
extern const char D_0027A2C0[];
extern const char D_0027A2E0[];
extern const char D_0027A300[];
extern const char D_0027A320[];
extern const char D_0027A340[];
extern const char D_0027A360[];
extern const char D_0027A380[];
extern const char D_0027A3A0[];
extern const char D_0027A3C0[];
extern const char D_0027A3E0[];
extern const char D_0027A400[];
extern const char D_0027A420[];
extern const char D_0027A440[];
extern const char D_0027A460[];
extern const char D_0027A480[];
extern const char D_0027A4A0[];
extern const char D_0027A4C0[];
extern const char D_0027A4E0[];
extern const char D_0027A500[];
extern const char D_0027A520[];
extern const char D_0027A540[];
extern const char D_0027A560[];
extern const char D_0027A580[];
extern const char D_0027A5A0[];
extern const char D_0027A5C0[];
extern const char D_0027A5E0[];
extern const char D_0027A600[];
extern const char D_0027A620[];
extern const char D_0027A640[];
extern const char D_0027A660[];
extern const char D_0027A680[];
extern const char D_0027A6A0[];
extern const char D_0027A6C0[];
extern const char D_0027A6E0[];
extern const char D_0027A700[];
extern const char D_0027A720[];
extern const char D_0027A740[];
extern const char D_0027A760[];
extern const char D_0027A780[];
extern const char D_0027A7A0[];
extern const char D_0027A7C0[];
extern const char D_0027A7E0[];
extern const char D_0027A800[];
extern const char D_0027A820[];
extern const char D_0027A840[];
extern const char D_0027A860[];
extern const char D_0027A880[];
extern const char D_0027A8A0[];
extern const char D_0027A8C0[];
extern const char D_0027A8E0[];
extern const char D_0027A900[];
extern const char D_0027A920[];
extern const char D_0027A940[];
extern const char D_0027A960[];
extern const char D_0027A980[];
extern const char D_0027A9A0[];
extern const char D_0027A9C0[];
extern const char D_0027A9E0[];
extern const char D_0027AA00[];
extern const char D_0027AA20[];
extern const char D_0027AA40[];
extern const char D_0027AA60[];
extern const char D_0027AA80[];
extern const char D_0027AAA0[];
extern const char D_0027AAC0[];
extern const char D_0027AAE0[];
extern const char D_0027AB00[];
extern const char D_0027AB20[];
extern const char D_0027AB40[];
extern const char D_0027AB60[];
extern const char D_0027AB80[];
extern const char D_0027ABA0[];
extern const char D_0027ABC0[];
extern const char D_0027ABE0[];
extern const char D_0027AC00[];
extern const char D_0027AC20[];
extern const char D_0027AC40[];
extern const char D_0027AC60[];
extern const char D_0027AC80[];
extern const char D_0027ACA0[];
extern const char D_0027ACC0[];
extern const char D_0027ACE0[];
extern const char D_0027AD00[];
extern const char D_0027AD20[];
extern const char D_0027AD40[];
extern const char D_0027AD60[];
extern const char D_0027AD80[];
extern const char D_0027ADA0[];
extern const char D_0027ADC0[];
extern const char D_0027ADE0[];
extern const char D_0027AE00[];
extern const char D_0027AE20[];
extern const char D_0027AE40[];
extern const char D_0027AE60[];
extern const char D_0027AE80[];
extern const char D_0027AEA0[];
extern const char D_0027AEC0[];
extern const char D_0027AEE0[];
extern const char D_0027AF00[];
extern const char D_0027AF20[];
extern const char D_0027AF40[];
extern const char D_0027AF60[];
extern const char D_0027AF80[];
extern const char D_0027AFA0[];
extern const char D_0027AFC0[];
extern const char D_0027AFE0[];
extern const char D_0027B000[];
extern const char D_0027B020[];
extern const char D_0027B040[];
extern const char D_0027B060[];
extern const char D_0027B080[];
extern const char D_0027B0A0[];
extern const char D_0027B0C0[];
extern const char D_0027B0E0[];
extern const char D_0027B100[];
extern const char D_0027B120[];
extern const char D_0027B140[];
extern const char D_0027B160[];
extern const char D_0027B180[];
extern const char D_0027B1A0[];
extern const char D_0027B1C0[];
extern const char D_0027B1E0[];
extern const char D_0027B200[];
extern const char D_0027B220[];
extern const char D_0027B240[];
extern const char D_0027B260[];
extern const char D_0027B280[];
extern const char D_0027B2A0[];
extern const char D_0027B2C0[];
extern const char D_0027B2E0[];
extern const char D_0027B300[];
extern const char D_0027B320[];
extern const char D_0027B340[];
extern const char D_0027B360[];
extern const char D_0027B380[];
extern const char D_0027B3A0[];
extern const char D_0027B3C0[];
extern const char D_0027B3E0[];
extern const char D_0027B400[];
extern const char D_0027B420[];
extern const char D_0027B440[];
extern const char D_0027B460[];
extern const char D_0027B480[];
extern const char D_0027B4A0[];
extern const char D_0027B4C0[];
extern const char D_0027B4E0[];
extern const char D_0027B500[];
extern const char D_0027B520[];
extern const char D_0027B540[];
extern const char D_0027B560[];
extern const char D_0027B580[];
extern const char D_0027B5A0[];
extern const char D_0027B5C0[];
extern const char D_0027B5E0[];
extern const char D_0027B600[];
extern const char D_0027B620[];
extern const char D_0027B640[];
extern const char D_0027B660[];
extern const char D_0027B680[];
extern const char D_0027B6A0[];
extern const char D_0027B6C0[];
extern const char D_0027B6E0[];
extern const char D_0027B700[];
extern const char D_0027B720[];
extern const char D_0027B740[];
extern const char D_0027B760[];
extern const char D_0027B780[];
extern const char D_0027B7A0[];
extern const char D_0027B7C0[];
extern const char D_0027B7E0[];
extern const char D_0027B800[];
extern const char D_0027B820[];
extern const char D_0027B840[];
extern const char D_0027B860[];
extern const char D_0027B880[];
extern const char D_0027B8A0[];
extern const char D_0027B8C0[];
extern const char D_0027B8E0[];
extern const char D_0027B900[];
extern const char D_0027B920[];
extern const char D_0027B940[];
extern const char D_0027B960[];
extern const char D_0027B980[];
extern const char D_0027B9A0[];
extern const char D_0027B9C0[];
extern const char D_0027B9E0[];
extern const char D_0027BA00[];
extern const char D_0027BA20[];
extern const char D_0027BA40[];
extern const char D_0027BA60[];
extern const char D_0027BA80[];
extern const char D_0027BAA0[];
extern const char D_0027BAC0[];
extern const char D_0027BAE0[];
extern const char D_0027BB00[];
extern const char D_0027BB20[];
extern const char D_0027BB40[];
extern const char D_0027BB60[];
extern const char D_0027BB80[];
extern const char D_0027BBA0[];
extern const char D_0027BBC0[];
extern const char D_0027BBE0[];
extern const char D_0027BC00[];
extern const char D_0027BC20[];
extern const char D_0027BC40[];
extern const char D_0027BC60[];
extern const char D_0027BC80[];
extern const char D_0027BCA0[];
extern const char D_0027BCC0[];
extern const char D_0027BCE0[];
extern const char D_0027BD00[];
extern const char D_0027BD20[];
extern const char D_0027BD40[];
extern const char D_0027BD60[];
extern const char D_0027BD80[];
extern const char D_0027BDA0[];
extern const char D_0027BDC0[];
extern const char D_0027BDE0[];
extern const char D_0027BE00[];
extern const char D_0027BE20[];
extern const char D_0027BE40[];
extern const char D_0027BE60[];
extern const char D_0027BE80[];
extern const char D_0027BEA0[];
extern const char D_0027BEC0[];
extern const char D_0027BEE0[];
extern const char D_0027BF00[];
extern const char D_0027BF20[];
extern const char D_0027BF40[];
extern const char D_0027BF60[];
extern const char D_0027BF80[];
extern const char D_0027BFA0[];
extern const char D_0027BFC0[];
extern const char D_0027BFE0[];
extern const char D_0027C000[];
extern const char D_0027C020[];
extern const char D_0027C040[];
extern const char D_0027C060[];
extern const char D_0027C080[];
extern const char D_0027C0A0[];
extern const char D_0027C0C0[];
extern const char D_0027C0E0[];
extern const char D_0027C100[];
extern const char D_0027C120[];
extern const char D_0027C140[];
extern const char D_0027C160[];
extern const char D_0027C180[];
extern const char D_0027C1A0[];
extern const char D_0027C1C0[];
extern const char D_0027C1E0[];
extern const char D_0027C200[];
extern const char D_0027C220[];
extern const char D_0027C240[];
extern const char D_0027C260[];
extern const char D_0027C280[];
extern const char D_0027C2A0[];
extern const char D_0027C2C0[];
extern const char D_0027C2E0[];
extern const char D_0027C300[];
extern const char D_0027C320[];
extern const char D_0027C340[];
extern const char D_0027C360[];
extern const char D_0027C380[];
extern const char D_0027C3A0[];
extern const char D_0027C3C0[];
extern const char D_0027C3E0[];
extern const char D_0027C400[];
extern const char D_0027C420[];
extern const char D_0027C440[];
extern const char D_0027C460[];
extern const char D_0027C480[];
extern const char D_0027C4A0[];
extern const char D_0027C4C0[];
extern const char D_0027C4E0[];
extern const char D_0027C500[];
extern const char D_0027C520[];
extern const char D_0027C540[];
extern const char D_0027C560[];
extern const char D_0027C580[];
extern const char D_0027C5A0[];
extern const char D_0027C5C0[];
extern const char D_0027C5E0[];
extern const char D_0027C600[];
extern const char D_0027C620[];
extern const char D_0027C640[];
extern const char D_0027C660[];
extern const char D_0027C680[];
extern const char D_0027C6A0[];
extern const char D_0027C6C0[];
extern const char D_0027C6E0[];
extern const char D_0027C700[];
extern const char D_0027C720[];
extern const char D_0027C740[];
extern const char D_0027C760[];
extern const char D_0027C780[];
extern const char D_0027C7A0[];
extern const char D_0027C7C0[];
extern const char D_0027C7E0[];
extern const char D_0027C800[];
extern const char D_0027C820[];
extern const char D_0027C840[];
extern const char D_0027C860[];
extern const char D_0027C880[];
extern const char D_0027C8A0[];
extern const char D_0027C8C0[];
extern const char D_0027C8E0[];
extern const char D_0027C900[];
extern const char D_0027C920[];
extern const char D_0027C940[];
extern const char D_0027C960[];
extern const char D_0027C980[];
extern const char D_0027C9A0[];
extern const char D_0027C9C0[];
extern const char D_0027C9E0[];
extern const char D_0027CA00[];
extern const char D_0027CA20[];
extern const char D_0027CA40[];
extern const char D_0027CA60[];
extern const char D_0027CA80[];
extern const char D_0027CAA0[];
extern const char D_0027CAC0[];
extern const char D_0027CAE0[];
extern const char D_0027CB00[];
extern const char D_0027CB20[];
extern const char D_0027CB40[];
extern const char D_0027CB60[];
extern const char D_0027CB80[];
extern const char D_0027CBA0[];
extern const char D_0027CBC0[];
extern const char D_0027CBE0[];
extern const char D_0027CC00[];
extern const char D_0027CC20[];
extern const char D_0027CC40[];
extern const char D_0027CC60[];
extern const char D_0027CC80[];
extern const char D_0027CCA0[];
extern const char D_0027CCC0[];
extern const char D_0027CCE0[];
extern const char D_0027CD00[];
extern const char D_0027CD20[];
extern const char D_0027CD40[];
extern const char D_0027CD60[];
extern const char D_0027CD80[];
extern const char D_0027CDA0[];
extern const char D_0027CDC0[];
extern const char D_0027CDE0[];
extern const char D_0027CE00[];
extern const char D_0027CE20[];
extern const char D_0027CE40[];
extern const char D_0027CE60[];
extern const char D_0027CE80[];
extern const char D_0027CEA0[];
extern const char D_0027CEC0[];
extern const char D_0027CEE0[];
extern const char D_0027CF00[];
extern const char D_0027CF20[];
extern const char D_0027CF40[];
extern const char D_0027CF60[];
extern const char D_0027CF80[];
extern const char D_0027CFA0[];
extern const char D_0027CFC0[];
extern const char D_0027CFE0[];
extern const char D_0027D000[];
extern const char D_0027D020[];
extern const char D_0027D040[];
extern const char D_0027D060[];
extern const char D_0027D080[];
extern const char D_0027D0A0[];
extern const char D_0027D0C0[];
extern const char D_0027D0E0[];
extern const char D_0027D100[];
extern const char D_0027D120[];
extern const char D_0027D140[];
extern const char D_0027D160[];
extern const char D_0027D180[];
extern const char D_0027D1A0[];
extern const char D_0027D1C0[];
extern const char D_0027D1E0[];
extern const char D_0027D200[];
extern const char D_0027D220[];
extern const char D_0027D240[];
extern const char D_0027D260[];
extern const char D_0027D280[];
extern const char D_0027D2B0[];
extern const char D_0027D2E0[];
extern const char D_0027D310[];
extern const char D_0027D340[];
extern const char D_0027D360[];
extern const char D_0027D380[];
extern const char D_0027D3A0[];
extern const char D_0027D3C0[];
extern const char D_0027D3E0[];
extern const char D_0027D400[];
extern const char D_0027D420[];
extern const char D_0027D440[];
extern const char D_0027D460[];
extern const char D_0027D480[];
extern const char D_0027D4A0[];
extern const char D_0027D4C0[];
extern const char D_0027D4E0[];
extern const char D_0027D500[];
extern const char D_0027D520[];
extern const char D_0027D540[];
extern const char D_0027D560[];
extern const char D_0027D580[];
extern const char D_0027D5A0[];
extern const char D_0027D5C0[];
extern const char D_0027D5E0[];
extern const char D_0027D600[];
extern const char D_0027D620[];
extern const char D_0027D640[];
extern const char D_0027D660[];
extern const char D_0027D680[];
extern const char D_0027D6A0[];
extern const char D_0027D6C0[];
extern const char D_0027D6E0[];
extern const char D_0027D700[];
extern const char D_0027D720[];
extern const char D_0027D740[];
extern const char D_0027D760[];
extern const char D_0027D780[];
extern const char D_0027D7A0[];

extern u16 D_002420F0[];
extern u16 D_00244070[];
extern u16 D_00244A30[];
extern u16 D_002461D0[];
extern u16 D_00246C90[];
extern u16 D_00247080[];
extern u16 D_00247880[];
extern u16 D_00249610[];
extern u16 D_00249ED0[];
extern u16 D_0024C240[];
extern u16 D_0024CA40[];
extern u16 D_0024CA80[];
extern u16 D_0024CAC0[];
extern u16 D_0024CB00[];
extern u16 D_0024CB40[];
extern u16 D_0024CB80[];
extern u16 D_0024D030_as_u16_a[];
extern u16 D_0024E0A0[];
extern u16 D_0024E0B0[];
extern u16 D_0024E0C0[];
extern u16 D_0024E0D0[];
extern u16 D_0024E0E0[];
extern u16 D_0024E0F8[];
extern u16 D_0024E110[];
extern u16 D_0024E130[];
extern u16 D_0024E140[];
extern u16 D_0024E150[];
extern u16 D_0024E170[];
extern u16 D_0024E188[];
extern u16 D_0024E1A0[];
extern u16 D_0024E1B8[];
extern u16 D_0024E1C8[];
extern u16 D_0024E1E0[];
extern u16 D_0024E200[];
extern u16 D_0024E210[];
extern u16 D_0024E220[];
extern u16 D_0024E230[];
extern u16 D_0024E240[];
extern u16 D_0024E250[];
extern u16 D_0024E260[];
extern u16 D_0024E280[];
extern u16 D_0024E290[];
extern u16 D_0024E2A0[];
extern u16 D_0024E2B0[];
extern u16 D_0024E2C8[];
extern u16 D_0024E862[];
extern u16 D_0024E876[];
extern u16 D_0024E88A[];
extern u16 D_0024E89E[];
extern u16 D_0024E8B2[];
extern u16 D_0024E8C6[];
extern u16 D_0024E8DA[];
extern u16 D_0024E8EE[];
extern u16 D_0024E902[];
extern u16 D_0024E916[];
extern u16 D_0024E92A[];
extern u16 D_0024E93E[];
extern u16 D_0024E952[];
extern u16 D_0024E966[];
extern u16 D_0024E97A[];
extern u16 D_0024E98E[];
extern u16 D_0024E9A2[];
extern u16 D_0024E9B6[];
extern u16 D_0024E9CA[];
extern u16 D_0024E9DE[];
extern u16 D_0024E9F2[];
extern u16 D_0024EA06[];
extern u16 D_0024EA1A[];
extern u16 D_0024EA2E[];
extern u16 D_0024EA42[];
extern u16 D_0024EA56[];
extern u16 D_0024EA6A[];
extern u16 D_0024EA7E[];
extern u16 D_0024EA92[];
extern u16 D_0024EAA6[];
extern u16 D_0024EABA[];
extern u16 D_0024EACE[];
extern u16 D_0024EAE2[];
extern u16 D_0024EAF6[];
extern u16 D_0024EB0A[];
extern u16 D_0024EB1E[];
extern u16 D_0024EBF0[];
extern u16 D_0024EC00[];
extern u16 D_0024EC10[];
extern u16 D_0024EC20[];
extern u16 D_0024EC30[];
extern u16 D_0024EC40[];
extern u16 D_0024EC50[];
extern u16 D_0024EC60[];
extern u16 D_0024EC70[];
extern u16 D_0024EDE0[];
extern u16 D_0024EDF0[];
extern u16 D_0024EE00[];
extern u16 D_0024EE10[];
extern u16 D_0024EE20[];
extern u16 D_0024EE30[];
extern u16 D_0024EE40[];
extern u16 D_0024EE50[];
extern u16 D_0024F790[];
extern u16 D_0024F7D0[];
extern u16 D_0024F7F0[];
extern u16 D_0024F850[];
extern u16 D_0024F870[];
extern u16 D_0024F8B0[];
extern u16 D_0024F8D0[];
extern u16 D_0024F930[];
extern u16 D_0024F950[];
extern u16 D_0024F990[];
extern u16 D_0024F9B0[];
extern u16 D_0024FA10[];
extern u16 D_0024FA30[];
extern u16 D_0024FAA0[];
extern u16 D_0024FAE0[];
extern u16 D_0024FB70[];
extern u16 D_0024FBB0[];
extern u16 D_0024FC30[];
extern u16 D_0024FC70[];
extern u16 D_0024FD10[];
extern u16 D_0024FD50[];
extern u16 D_0024FDE0[];
extern u16 D_0024FE30[];
extern u16 D_0024FED0[];
extern u16 D_0024FF20[];
extern u16 D_0024FF90[];
extern u16 D_0024FFD0[];
extern u16 D_00250060[];
extern u16 D_002500B0[];
extern u16 D_00250130[];
extern u16 D_00250170[];
extern u16 D_00250210[];
extern u16 D_00250260[];
extern u16 D_002502C0[];
extern u16 D_002502F0[];
extern u16 D_002503A0[];
extern u16 D_002503F0[];
extern u16 D_00250490[];
extern u16 D_002504D0[];
extern u16 D_00250570[];
extern u16 D_002505C0[];
extern u16 D_00250600[];
extern u16 D_00250620[];
extern u16 D_002506B0[];
extern u16 D_002506F0[];
extern u16 D_00250740[];
extern u16 D_00250A00[];
extern u16 D_00250A90[];
extern u16 D_00250B20[];
extern u16 D_00250BB0[];
extern u16 D_00250C40[];
extern u16 D_00250DA0[];
extern u16 D_00250DC0[];
extern u16 D_00250DE0[];
extern u16 D_00250E20[];
extern u16 D_00250EB0[];
extern u16 D_002515C0[];
extern u16 D_002515D0[];
extern u16 D_002515E0[];
extern u16 D_002515F0[];
extern u16 D_00251600[];
extern u16 D_00251610[];
extern u16 D_00251620[];
extern u16 D_00251630[];
extern u16 D_00251640[];
extern u16 D_00251650[];
extern u16 D_00251660[];
extern u16 D_00251670[];
extern u16 D_00251CE0[];
extern u16 D_00251D10[];
extern u16 D_00251D40[];
extern u16 D_00252020[];
extern u16 D_00252030[];
extern u16 D_00252040[];
extern u16 D_00252060[];
extern u16 D_00252070[];
extern u16 D_00252080[];
extern u16 D_00252090[];
extern u16 D_002520A0[];
extern u16 D_002520B0[];
extern u16 D_002520C0[];
extern u16 D_002520D0[];
extern u16 D_002520E0[];
extern u16 D_002520F0[];
extern u16 D_00252100[];
extern u16 D_00252110[];
extern u16 D_00252120[];
extern u16 D_00252130[];
extern u16 D_00252140[];
extern u16 D_00252150[];
extern u16 D_00252160[];
extern u16 D_00252170[];
extern u16 D_00252180[];
extern u16 D_00252190[];
extern u16 D_002521A0[];
extern u16 D_002521B0[];
extern u16 D_002521D0[];
extern u16 D_002521F0[];
extern u16 D_00252230[];
extern u16 D_00252240[];
extern u16 D_00252250[];
extern u16 D_00252268[];
extern u16 D_00252278[];
extern u16 D_00252290[];
extern u16 D_002522B0[];
extern u16 D_002522D0[];
extern u16 D_002522F0[];
extern u16 D_00252310[];
extern u16 D_00252760[];
extern u16 D_002527E8[];
extern u16 D_00252800[];
extern u16 D_00252990[];
extern u16 D_00252A20[];
extern u16 D_00252AC0[];
extern u16 D_00252AE0[];
extern u16 D_00252BB0[];
extern u16 D_00252BD0[];
extern u16 D_00252C70[];
extern u16 D_00252C90[];
extern u16 D_00252D70[];
extern u16 D_00252DB0[];
extern u16 D_00252E40[];
extern u16 D_00252E60[];
extern u16 D_00252F40[];
extern u16 D_00252F80[];
extern u16 D_00253000[];
extern u16 D_00253020[];
extern u16 D_00253160[];
extern u16 D_00255470[];
extern u16 D_0025C040[];
extern u16 D_0025C060[];
extern u16 D_0025C080[];
extern u16 D_0025C0A0[];
extern u16 D_0025C0C0[];
extern u16 D_0025C0E0[];
extern u16 D_0025C100[];
extern u16 D_0025C120[];
extern u16 D_0025C140[];
extern u16 D_0025C160[];
extern u16 D_0025C180[];
extern u16 D_0025C1A0[];
extern u16 D_0025C1C0[];
extern u16 D_0025C1E0[];
extern u16 D_0025C200[];
extern u16 D_0025C220[];
extern u16 D_0025C240[];
extern u16 D_0025C260[];
extern u16 D_0025C280[];
extern u16 D_0025C2A0[];
extern u16 D_0025C2C0[];
extern u16 D_0025C2E0[];
extern u16 D_0025C300[];
extern u16 D_0025C320[];
extern u16 D_0025C340[];
extern u16 D_0025C360[];
extern u16 D_0025C380[];
extern u16 D_0025C3A0[];
extern u16 D_0025FF70_as_u16_a[];
extern u16 D_0025FFB0_as_u16_a[];
extern u16 D_0025FFF0_as_u16_a[];
extern u16 D_00260030_as_u16_a[];
extern u16 D_00260070_as_u16_a[];
extern u16 D_002600B0_as_u16_a[];
extern u16 D_002600F0_as_u16_a[];
extern u16 D_00260130_as_u16_a[];
extern u16 D_00260170_as_u16_a[];
extern u16 D_00260570[];
extern u16 D_002605B0[];
extern u16 D_002605F0[];
extern u16 D_00260630[];
extern u16 D_00260670[];
extern u16 D_002606B0[];
extern u16 D_002606F0[];
extern u16 D_00260730[];
extern u16 D_00260770[];
extern u16 D_002607B0[];
extern u16 D_002607F0[];
extern u16 D_00260830[];
extern u16 D_002608B0[];
extern u16 D_002608F0[];
extern u16 D_00260EB0[];
extern u16 D_00260EF0[];
extern u16 D_00260F30[];
extern u16 D_00260FB0[];
extern u16 D_00260FF0[];
extern u16 D_00261030[];
extern u16 D_002610B0_as_u16_a[];
extern u16 D_002610F0[];
extern u16 D_00261130[];
extern u16 D_00261170[];
extern u16 D_002611B0[];
extern u16 D_002611F0[];
extern u16 D_00261230[];
extern u16 D_00261270[];
extern u16 D_002612B0[];
extern u16 D_002612F0[];
extern u16 D_00261330[];
extern u16 D_00261370[];
extern u16 D_002613B0[];
extern u16 D_002613F0[];
extern u16 D_00261430[];
extern u16 D_00261470[];
extern u16 D_002614B0[];
extern u16 D_002614F0[];
extern u16 D_00261530[];
extern u16 D_00261570[];
extern u16 D_002615B0[];
extern u16 D_002615F0[];
extern u16 D_00261630[];
extern u16 D_00261670[];
extern u16 D_002616B0[];
extern u16 D_00261730_as_u16_a[];
extern u16 D_00261930[];
extern u16 D_00261970[];
extern u16 D_002619B0[];
extern u16 D_002619F0[];
extern u16 D_00261A30[];
extern u16 D_00261A70[];
extern u16 D_00261AB0[];
extern u16 D_00261B30[];
extern u16 D_00261B70[];
extern u16 D_00261D30[];
extern u16 D_00261D70[];
extern u16 D_00261DB0[];
extern u16 D_00261EF0_as_u16_a[];
extern u16 D_00261F30[];
extern u16 D_00261F70_as_u16_a[];
extern u16 D_00261FB0_as_u16_a[];
extern u16 D_002624F0[];
extern u16 D_00262530[];
extern u16 D_002643F0[];
extern u16 D_00264440[];
extern u16 D_00264490[];
extern u16 D_002644E0[];
extern u16 D_0028C0A0[];
extern u16 D_0028C160[];
extern u16 D_0028C168[];
extern u16 D_0028C170[];
extern u16 D_0028C178[];
extern u16 D_0028C180[];
extern u16 D_0028C680[];
extern u16 D_0028C708[];
extern u16 D_0029BF30_as_u16_a[];
extern u16 D_0029BF40_as_u16_a[];
extern void func_001298A0(void);
extern void func_001298D0(void);
extern void func_00129930(void);
extern void func_00129970(void);
extern void func_001299B0(void);
extern void func_00129A10(void);
extern void func_00129A80(void);
extern void func_00129A90(void);
extern void func_00129B10(void);
extern void func_00129B60(void);
extern void func_00129B70(void);
extern void func_0012D940(void);
extern void func_0012D960(void);
extern void func_0012D980(void);
extern void func_0012D990(void);
extern void func_0012D9B0(void);
extern void func_0012D9D0(void);
extern void func_0012D9F0(void);
extern void func_0012DA10(void);
extern void func_0012DE90(void);
extern void func_0012DF50(void);
extern void func_0012E010(void);
extern void func_0012E0B0(void);
extern void func_0012E130(void);
extern void func_0012E1B0(void);
extern void func_0012E230(void);
extern void func_0012E2B0(void);
extern void func_0012E440(void);
extern void func_0012E4D0(void);
extern void func_0012E530(void);
extern void func_0012E590(void);
extern void func_0012E620(void);
extern void func_0012E680(void);
extern void func_0012E6E0(void);
extern void func_0012E7A0(void);
extern void func_0012E860(void);
extern void func_0012E920(void);
extern void func_0012E9E0(void);
extern void func_0012EAA0(void);
extern void func_0012EB40(void);
extern void func_0012EC00(void);
extern void func_0012EC90(void);
extern void func_0012ED50(void);
extern void func_0012EDF0(void);
extern void func_0012EE90(void);
extern void func_0012EF80(void);
extern void func_0012F020(void);
extern void func_0012F0C0(void);
extern void func_0012F1B0(void);
extern void func_0012F2A0(void);
extern void func_0012F330(void);
extern void func_0012F3B0(void);
extern void func_0012F450(void);
extern void func_00130270(void);
extern void func_001303A0(void);
extern void func_0014CC90(void);
extern void func_0014CD70(void);
extern void func_0014CEA0(void);
extern void func_0014CEE0(void);
extern void func_0014CF10(void);
extern void func_0014CF90(void);
extern void func_0014D0F0(void);
extern void func_0014D140(void);
extern void func_0014D150(void);
extern void func_0014D170(void);
extern void music_play_bgm3(void);
extern void music_play_bgm4(void);
extern void music_play_bgm5(void);
extern void music_play_bgm6(void);
extern void music_play_bgm7(void);
extern void music_play_bgm8(void);

extern u16 D_0024D0B8[];
extern u16 D_0024D0C6[];
extern u16 D_0024D0D4[];
extern u16 D_0024D238[];
extern u16 D_0024D246[];
extern u16 D_0024D258[];
extern u16 D_0024D266[];
extern u16 D_0024D278[];
extern u16 D_0024D286[];
extern u16 D_0024D298[];
extern u16 D_0024D2A6[];
extern u16 D_0024D2B8[];
extern u16 D_0024D2C6[];
extern u16 D_0024E2E6[];
extern u16 D_0024E2F0[];
extern u16 D_0024E2FA[];
extern u16 D_0024E304[];
extern u16 D_0024E30E[];
extern u16 D_0024E318[];
extern u16 D_0024E322[];
extern u16 D_0024E32C[];
extern u16 D_0024E336[];
extern u16 D_0024E340[];
extern u16 D_0024E34A[];
extern u16 D_0024E354[];
extern u16 D_0024E35E[];
extern u16 D_0024E368[];
extern u16 D_0024E372[];
extern u16 D_0024E37C[];
extern u16 D_0024E386[];
extern u16 D_0024E390[];
extern u16 D_0024E39A[];
extern u16 D_0024E3A4[];
extern u16 D_0024E3AE[];
extern u16 D_0024E3B8[];
extern u16 D_0024E3C2[];
extern u16 D_0024E3CC[];
extern u16 D_0024E3D6[];
extern u16 D_0024E3E0[];
extern u16 D_0024E3EA[];
extern u16 D_0024E3F4[];
extern u16 D_0024E3FE[];
extern u16 D_0024E408[];
extern u16 D_0024E412[];
extern u16 D_0024E41C[];
extern u16 D_0024E426[];
extern u16 D_0024E430[];
extern u16 D_0024E740_as_u16_a[];
extern u16 D_0024E7D0[];
extern u16 D_0024EB30_as_u16_a[];
extern u16 D_0024EBC0_as_u16_a[];
extern u16 D_0024EDB0_as_u16_a[];
extern u16 D_0024F570[];
extern u16 D_0024F680[];
extern u16 D_00250CD0_as_u16_a[];
extern u16 D_00251A80_as_u16_a[];
extern u16 D_00251A84[];
extern u16 D_00251A90_as_u16_a[];
extern u16 D_00251A94[];
extern u16 D_00251AB0_as_u16_a[];
extern u16 D_00251AB4[];
extern u16 D_00251AC0_as_u16_a[];
extern u16 D_00251AC4[];
extern u16 D_00251CC0[];
extern u16 D_00252010[];
extern u16 D_00252050[];
extern u16 D_00252210[];
extern u16 D_00252220[];
extern u16 D_002526D0_as_u16_a[];
extern u16 D_002526D2[];
extern u16 D_002526F0_as_u16_a[];
extern u16 D_002526F2[];
extern u16 D_00252700_as_u16_a[];
extern u16 D_00252702[];
extern u16 D_00252720_as_u16_a[];
extern u16 D_00252722[];
extern u16 D_00252740[];
extern u16 D_0025BF98[];
extern u16 D_0025BFA6[];
extern u16 D_0025BFB4[];
extern u16 D_0025BFC2[];
extern u16 D_0025C3C0[];
extern u16 D_002643E0_as_u16_a[];
extern u16 D_002643E2[];
extern u16 D_0028C148_as_u16_a[];
extern u16 D_0028C14A[];

#ifdef DEATH_LABEL
extern u16 death_D_002506F0[];
extern u16 death_D_00250790[];
extern u16 death_D_00250A72[];
extern u16 death_D_00250B20[];
extern u16 death_D_00254748[];
extern u16 death_D_00254758[];
extern u16 death_D_00254768[];
extern u16 death_D_00254778[];
extern u16 death_D_00254790[];
extern u16 death_D_002547A0[];
extern u16 death_D_002547B0[];
extern u16 death_D_002547C0[];
extern u16 death_D_0025495A[];
extern u16 death_D_00254964[];
extern u16 death_D_0025496E[];
extern u16 death_D_00254978[];
extern u16 death_D_00254982[];
extern const char death_D_0027B030[];
extern const char death_D_0027B4D0[];
extern const char death_D_0027B970[];
extern void death_func_0012E5B0(void);
#endif

void func_0018E5A0(void) {
    extern void input_get_p1_held(void);
    extern void input_get_p2_held(void);
    extern void input_get_p1_pressed(void);
    extern void input_get_p2_pressed(void);
    if (D_0024E740_as_u16_a[0] != 0x0) {
        printf((const char *)D_002784E0);
    }
    STORE_POINTER_DIRECT(D_0024E740_as_u16_a, func_001298A0);
    if (D_0024E740[2] != 0x2) {
        printf((const char *)D_00278500);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 2, func_001298A0);
    if (D_0024E740[4] != 0x4) {
        printf((const char *)D_00278520);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 4, func_001298A0);
    if (D_0024E740[6] != 0x6) {
        printf((const char *)D_00278540);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 6, func_001298D0);
    if (D_0024E740[8] != 0x8) {
        printf((const char *)D_00278560);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 8, func_001298D0);
    if (D_0024E740[10] != 0xa) {
        printf((const char *)D_00278580);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 10, func_001298D0);
    if (D_0024E740[12] != 0xc) {
        printf((const char *)D_002785A0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 12, func_001298D0);
    if (D_0024E740[14] != 0xe) {
        printf((const char *)D_002785C0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 14, func_001298A0);
    if (D_0024E740[16] != 0x10) {
        printf((const char *)D_002785E0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 16, func_001298A0);
    if (D_0024E740[18] != 0x12) {
        printf((const char *)D_00278600);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 18, func_001298A0);
    if (D_0024E740[20] != 0x14) {
        printf((const char *)D_00278620);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 20, func_001298A0);
    if (D_0024E740[22] != 0x16) {
        printf((const char *)D_00278640);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 22, func_001298A0);
    if (D_0024E740[24] != 0x18) {
        printf((const char *)D_00278660);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 24, func_001298A0);
    if (D_0024E740[26] != 0x1a) {
        printf((const char *)D_00278680);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 26, func_001298A0);
    if (D_0024E740[28] != 0x1c) {
        printf((const char *)D_002786A0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 28, func_001298A0);
    if (D_0024E740[30] != 0x1e) {
        printf((const char *)D_002786C0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 30, func_001298A0);
    if (D_0024E740[32] != 0x20) {
        printf((const char *)D_002786E0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 32, func_001298A0);
    if (D_0024E740[34] != 0x22) {
        printf((const char *)D_00278700);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 34, func_00129930);
    if (D_0024E740[36] != 0x24) {
        printf((const char *)D_00278720);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 36, func_00129970);
    if (D_0024E740[38] != 0x26) {
        printf((const char *)D_00278740);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 38, func_001299B0);
    if (D_0024E740[40] != 0x28) {
        printf((const char *)D_00278760);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 40, func_001298A0);
    if (D_0024E740[42] != 0x2a) {
        printf((const char *)D_00278780);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 42, func_001298A0);
    if (D_0024E740[44] != 0x2c) {
        printf((const char *)D_002787A0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 44, func_001299B0);
    if (D_0024E740[46] != 0x2e) {
        printf((const char *)D_002787C0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 46, func_00129A10);
    if (D_0024E740[48] != 0x30) {
        printf((const char *)D_002787E0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 48, func_00129A10);
    if (D_0024E740[50] != 0x32) {
        printf((const char *)D_00278800);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 50, func_001298A0);
    if (D_0024E740[52] != 0x34) {
        printf((const char *)D_00278820);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 52, func_001298A0);
    if (D_0024E740[54] != 0x36) {
        printf((const char *)D_00278840);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 54, func_00129A80);
    if (D_0024E740[56] != 0x38) {
        printf((const char *)D_00278860);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 56, func_00129B10);
    if (D_0024E740[58] != 0x3a) {
        printf((const char *)D_00278880);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 58, func_001298A0);
    if (D_0024E740[60] != 0x3c) {
        printf((const char *)D_002788A0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 60, func_00129B60);
    if (D_0024E740[62] != 0x3e) {
        printf((const char *)D_002788C0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 62, func_00129B70);
    if (D_0024E740[64] != 0x40) {
        printf((const char *)D_002788E0);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 64, func_00129A90);
    if (D_0024E740[66] != 0x42) {
        printf((const char *)D_00278900);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 66, func_001298A0);
    if (D_0024E740[68] != 0x44) {
        printf((const char *)D_00278920);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 68, func_001298A0);
    if (D_0024E740[70] != 0x46) {
        printf((const char *)D_00278940);
    }
    STORE_POINTER_DIRECT(D_0024E740 + 70, func_001298D0);
#ifdef DEATH_LABEL
    if (death_D_002506F0[0] != 0x48) {
        printf(death_D_0027B030);
    }
    STORE_POINTER_DIRECT(death_D_002506F0, func_00129B10);
#endif
    if (D_0024E7D0[0] != 0x0) {
        printf((const char *)D_00278960);
    }
    STORE_POINTER_DIRECT(D_0024E7D0, D_0024E862);
    if (D_0024E7D0[2] != 0x2) {
        printf((const char *)D_00278980);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 2, D_0024E876);
    if (D_0024E7D0[4] != 0x4) {
        printf((const char *)D_002789A0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 4, D_0024E88A);
    if (D_0024E7D0[6] != 0x6) {
        printf((const char *)D_002789C0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 6, D_0024E89E);
    if (D_0024E7D0[8] != 0x8) {
        printf((const char *)D_002789E0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 8, D_0024E8B2);
    if (D_0024E7D0[10] != 0xa) {
        printf((const char *)D_00278A00);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 10, D_0024E8C6);
    if (D_0024E7D0[12] != 0xc) {
        printf((const char *)D_00278A20);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 12, D_0024E8DA);
    if (D_0024E7D0[14] != 0xe) {
        printf((const char *)D_00278A40);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 14, D_0024E8EE);
    if (D_0024E7D0[16] != 0x10) {
        printf((const char *)D_00278A60);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 16, D_0024E902);
    if (D_0024E7D0[18] != 0x12) {
        printf((const char *)D_00278A80);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 18, D_0024E916);
    if (D_0024E7D0[20] != 0x14) {
        printf((const char *)D_00278AA0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 20, D_0024E92A);
    if (D_0024E7D0[22] != 0x16) {
        printf((const char *)D_00278AC0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 22, D_0024E93E);
    if (D_0024E7D0[24] != 0x18) {
        printf((const char *)D_00278AE0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 24, D_0024E952);
    if (D_0024E7D0[26] != 0x1a) {
        printf((const char *)D_00278B00);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 26, D_0024E966);
    if (D_0024E7D0[28] != 0x1c) {
        printf((const char *)D_00278B20);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 28, D_0024E97A);
    if (D_0024E7D0[30] != 0x1e) {
        printf((const char *)D_00278B40);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 30, D_0024E98E);
    if (D_0024E7D0[32] != 0x20) {
        printf((const char *)D_00278B60);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 32, D_0024E9A2);
    if (D_0024E7D0[34] != 0x22) {
        printf((const char *)D_00278B80);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 34, D_0024E9B6);
    if (D_0024E7D0[36] != 0x24) {
        printf((const char *)D_00278BA0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 36, D_0024E9CA);
    if (D_0024E7D0[38] != 0x26) {
        printf((const char *)D_00278BC0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 38, D_0024E9DE);
    if (D_0024E7D0[40] != 0x28) {
        printf((const char *)D_00278BE0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 40, D_0024E9F2);
    if (D_0024E7D0[42] != 0x2a) {
        printf((const char *)D_00278C00);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 42, D_0024EA06);
    if (D_0024E7D0[44] != 0x2c) {
        printf((const char *)D_00278C20);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 44, D_0024EA1A);
    if (D_0024E7D0[46] != 0x2e) {
        printf((const char *)D_00278C40);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 46, D_0024EA2E);
    if (D_0024E7D0[48] != 0x30) {
        printf((const char *)D_00278C60);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 48, D_0024EA42);
    if (D_0024E7D0[50] != 0x32) {
        printf((const char *)D_00278C80);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 50, D_0024EA56);
    if (D_0024E7D0[52] != 0x34) {
        printf((const char *)D_00278CA0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 52, D_0024EA6A);
    if (D_0024E7D0[54] != 0x36) {
        printf((const char *)D_00278CC0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 54, D_0024EA7E);
    if (D_0024E7D0[56] != 0x38) {
        printf((const char *)D_00278CE0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 56, D_0024EA92);
    if (D_0024E7D0[58] != 0x3a) {
        printf((const char *)D_00278D00);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 58, D_0024EAA6);
    if (D_0024E7D0[60] != 0x3c) {
        printf((const char *)D_00278D20);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 60, D_0024EABA);
    if (D_0024E7D0[62] != 0x3e) {
        printf((const char *)D_00278D40);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 62, D_0024EACE);
    if (D_0024E7D0[64] != 0x40) {
        printf((const char *)D_00278D60);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 64, D_0024EAE2);
    if (D_0024E7D0[66] != 0x42) {
        printf((const char *)D_00278D80);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 66, D_0024EAF6);
    if (D_0024E7D0[68] != 0x44) {
        printf((const char *)D_00278DA0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 68, D_0024EB0A);
    if (D_0024E7D0[70] != 0x46) {
        printf((const char *)D_00278DC0);
    }
    STORE_POINTER_DIRECT(D_0024E7D0 + 70, D_0024EB1E);
#ifdef DEATH_LABEL
    if (death_D_00250790[0] != 0x48) {
        printf(death_D_0027B4D0);
    }
    STORE_POINTER_DIRECT(death_D_00250790, death_D_00250A72);
#endif
    if (D_0024EB30_as_u16_a[0] != 0x0) {
        printf((const char *)D_00278DE0);
    }
    STORE_POINTER_DIRECT(D_0024EB30_as_u16_a, func_0012DE90);
    if (D_0024EB30[2] != 0x2) {
        printf((const char *)D_00278E00);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 2, func_0012DF50);
    if (D_0024EB30[4] != 0x4) {
        printf((const char *)D_00278E20);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 4, func_0012E010);
    if (D_0024EB30[6] != 0x6) {
        printf((const char *)D_00278E40);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 6, func_0012E0B0);
    if (D_0024EB30[8] != 0x8) {
        printf((const char *)D_00278E60);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 8, func_0012E130);
    if (D_0024EB30[10] != 0xa) {
        printf((const char *)D_00278E80);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 10, func_0012E1B0);
    if (D_0024EB30[12] != 0xc) {
        printf((const char *)D_00278EA0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 12, func_0012E230);
    if (D_0024EB30[14] != 0xe) {
        printf((const char *)D_00278EC0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 14, func_0012E2B0);
    if (D_0024EB30[16] != 0x10) {
        printf((const char *)D_00278EE0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 16, func_0012E440);
    if (D_0024EB30[18] != 0x12) {
        printf((const char *)D_00278F00);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 18, func_0012E4D0);
    if (D_0024EB30[20] != 0x14) {
        printf((const char *)D_00278F20);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 20, func_0012E530);
    if (D_0024EB30[22] != 0x16) {
        printf((const char *)D_00278F40);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 22, func_0012E590);
    if (D_0024EB30[24] != 0x18) {
        printf((const char *)D_00278F60);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 24, func_0012E620);
    if (D_0024EB30[26] != 0x1a) {
        printf((const char *)D_00278F80);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 26, func_0012E680);
    if (D_0024EB30[28] != 0x1c) {
        printf((const char *)D_00278FA0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 28, func_0012E530);
    if (D_0024EB30[30] != 0x1e) {
        printf((const char *)D_00278FC0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 30, func_0012E530);
    if (D_0024EB30[32] != 0x20) {
        printf((const char *)D_00278FE0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 32, func_0012E6E0);
    if (D_0024EB30[34] != 0x22) {
        printf((const char *)D_00279000);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 34, func_0012E7A0);
    if (D_0024EB30[36] != 0x24) {
        printf((const char *)D_00279020);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 36, func_0012E860);
    if (D_0024EB30[38] != 0x26) {
        printf((const char *)D_00279040);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 38, func_0012E920);
    if (D_0024EB30[40] != 0x28) {
        printf((const char *)D_00279060);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 40, func_0012E9E0);
    if (D_0024EB30[42] != 0x2a) {
        printf((const char *)D_00279080);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 42, func_0012EAA0);
    if (D_0024EB30[44] != 0x2c) {
        printf((const char *)D_002790A0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 44, func_0012EB40);
    if (D_0024EB30[46] != 0x2e) {
        printf((const char *)D_002790C0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 46, func_0012EC00);
    if (D_0024EB30[48] != 0x30) {
        printf((const char *)D_002790E0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 48, func_0012EC90);
    if (D_0024EB30[50] != 0x32) {
        printf((const char *)D_00279100);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 50, func_0012ED50);
    if (D_0024EB30[52] != 0x34) {
        printf((const char *)D_00279120);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 52, func_0012EDF0);
    if (D_0024EB30[54] != 0x36) {
        printf((const char *)D_00279140);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 54, func_0012EE90);
    if (D_0024EB30[56] != 0x38) {
        printf((const char *)D_00279160);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 56, func_0012EF80);
    if (D_0024EB30[58] != 0x3a) {
        printf((const char *)D_00279180);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 58, func_0012F020);
    if (D_0024EB30[60] != 0x3c) {
        printf((const char *)D_002791A0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 60, func_0012F0C0);
    if (D_0024EB30[62] != 0x3e) {
        printf((const char *)D_002791C0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 62, func_0012F1B0);
    if (D_0024EB30[64] != 0x40) {
        printf((const char *)D_002791E0);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 64, func_0012F2A0);
    if (D_0024EB30[66] != 0x42) {
        printf((const char *)D_00279200);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 66, func_0012F330);
    if (D_0024EB30[68] != 0x44) {
        printf((const char *)D_00279220);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 68, func_0012F3B0);
    if (D_0024EB30[70] != 0x46) {
        printf((const char *)D_00279240);
    }
    STORE_POINTER_DIRECT(D_0024EB30 + 70, func_0012F450);
#ifdef DEATH_LABEL
    if (death_D_00250B20[0] != 0x48) {
        printf(death_D_0027B970);
    }
    STORE_POINTER_DIRECT(death_D_00250B20, death_func_0012E5B0);
#endif
    if (D_0024EBC0_as_u16_a[0] != 0x0) {
        printf((const char *)D_00279260);
    }
    STORE_POINTER_DIRECT(D_0024EBC0_as_u16_a, D_0024EBF0);
    if (D_0024EBC0[2] != 0x2) {
        printf((const char *)D_00279280);
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 2, D_0024EC00);
    if (D_0024EBC0[4] != 0x4) {
        printf((const char *)D_002792A0);
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 4, D_0024EC10);
    if (D_0024EBC0[6] != 0x6) {
        printf((const char *)D_002792C0);
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 6, D_0024EC20);
    if (D_0024EBC0[8] != 0x8) {
        printf((const char *)D_002792E0);
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 8, D_0024EC30);
    if (D_0024EBC0[10] != 0xa) {
        printf((const char *)D_00279300);
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 10, D_0024EC40);
    if (D_0024EBC0[12] != 0xc) {
        printf((const char *)D_00279320);
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 12, D_0024EC50);
    if (D_0024EBC0[14] != 0xe) {
        printf((const char *)D_00279340);
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 14, D_0024EC60);
    if (D_0024EBC0[16] != 0x10) {
        printf((const char *)D_00279360);
    }
    STORE_POINTER_DIRECT(D_0024EBC0 + 16, D_0024EC70);
    if (D_0024EDB0_as_u16_a[0] != 0x0) {
        printf((const char *)D_00279380);
    }
    STORE_POINTER_DIRECT(D_0024EDB0_as_u16_a, D_0024EDE0);
    if (D_0024EDB0[2] != 0x2) {
        printf((const char *)D_002793A0);
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 2, D_0024EDF0);
    if (D_0024EDB0[4] != 0x4) {
        printf((const char *)D_002793C0);
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 4, D_0024EE00);
    if (D_0024EDB0[6] != 0x6) {
        printf((const char *)D_002793E0);
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 6, D_0024EE10);
    if (D_0024EDB0[8] != 0x8) {
        printf((const char *)D_00279400);
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 8, D_0024EE20);
    if (D_0024EDB0[10] != 0xa) {
        printf((const char *)D_00279420);
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 10, D_0024EE30);
    if (D_0024EDB0[12] != 0xc) {
        printf((const char *)D_00279440);
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 12, D_0024EE40);
    if (D_0024EDB0[14] != 0xe) {
        printf((const char *)D_00279460);
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 14, D_0024EE50);
    if (D_0024EDB0[16] != 0x10) {
        printf((const char *)D_00279480);
    }
    STORE_POINTER_DIRECT(D_0024EDB0 + 16, D_0024EDE0);
    if (D_0024EF30[192] != 0x0) {
        printf((const char *)D_002794A0);
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 192, func_0012D980);
    if (D_0024EF30[196] != 0x4) {
        printf((const char *)D_002794C0);
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 196, func_0012D960);
    if (D_0024EF30[200] != 0x8) {
        printf((const char *)D_002794E0);
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 200, func_0012D990);
    if (D_0024EF30[204] != 0xc) {
        printf((const char *)D_00279500);
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 204, func_0012D9B0);
    if (D_0024EF30[208] != 0x10) {
        printf((const char *)D_00279520);
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 208, func_0012D9F0);
    if (D_0024EF30[212] != 0x14) {
        printf((const char *)D_00279540);
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 212, func_0012D9D0);
    if (D_0024EF30[216] != 0x18) {
        printf((const char *)D_00279560);
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 216, func_0012D940);
    if (D_0024EF30[220] != 0x1c) {
        printf((const char *)D_00279580);
    }
    STORE_POINTER_DIRECT(D_0024EF30 + 220, func_0012DA10);
    if (D_0024F570[0] != 0x0) {
        printf((const char *)D_002795A0);
    }
    STORE_POINTER_DIRECT(D_0024F570, D_0024F790);
    if (D_0024F570[2] != 0x2) {
        printf((const char *)D_002795C0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 2, D_0024F7D0);
    if (D_0024F570[4] != 0x4) {
        printf((const char *)D_002795E0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 4, D_0024F870);
    if (D_0024F570[6] != 0x6) {
        printf((const char *)D_00279600);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 6, D_0024F8B0);
    if (D_0024F570[8] != 0x8) {
        printf((const char *)D_00279620);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 8, D_0024F950);
    if (D_0024F570[10] != 0xa) {
        printf((const char *)D_00279640);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 10, D_0024F990);
    if (D_0024F570[12] != 0xc) {
        printf((const char *)D_00279660);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 12, D_0024FA30);
    if (D_0024F570[14] != 0xe) {
        printf((const char *)D_00279680);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 14, D_0024FAA0);
    if (D_0024F570[16] != 0x10) {
        printf((const char *)D_002796A0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 16, D_0024FBB0);
    if (D_0024F570[18] != 0x12) {
        printf((const char *)D_002796C0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 18, D_0024FC30);
    if (D_0024F570[20] != 0x14) {
        printf((const char *)D_002796E0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 20, D_0024FD50);
    if (D_0024F570[22] != 0x16) {
        printf((const char *)D_00279700);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 22, D_0024FDE0);
    if (D_0024F570[24] != 0x18) {
        printf((const char *)D_00279720);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 24, D_0024FF20);
    if (D_0024F570[26] != 0x1a) {
        printf((const char *)D_00279740);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 26, D_0024FF90);
    if (D_0024F570[28] != 0x1c) {
        printf((const char *)D_00279760);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 28, D_0024FFD0);
    if (D_0024F570[30] != 0x1e) {
        printf((const char *)D_00279780);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 30, D_00250060);
    if (D_0024F570[32] != 0x20) {
        printf((const char *)D_002797A0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 32, D_002500B0);
    if (D_0024F570[34] != 0x22) {
        printf((const char *)D_002797C0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 34, D_00250130);
    if (D_0024F570[36] != 0x24) {
        printf((const char *)D_002797E0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 36, D_00250170);
    if (D_0024F570[38] != 0x26) {
        printf((const char *)D_00279800);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 38, D_00250210);
    if (D_0024F570[40] != 0x28) {
        printf((const char *)D_00279820);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 40, D_00250260);
    if (D_0024F570[42] != 0x2a) {
        printf((const char *)D_00279840);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 42, D_002502C0);
    if (D_0024F570[44] != 0x2c) {
        printf((const char *)D_00279860);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 44, D_002502F0);
    if (D_0024F570[46] != 0x2e) {
        printf((const char *)D_00279880);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 46, D_002503A0);
    if (D_0024F570[48] != 0x30) {
        printf((const char *)D_002798A0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 48, D_002503F0);
    if (D_0024F570[50] != 0x32) {
        printf((const char *)D_002798C0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 50, D_00250490);
    if (D_0024F570[52] != 0x34) {
        printf((const char *)D_002798E0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 52, D_002504D0);
    if (D_0024F570[54] != 0x36) {
        printf((const char *)D_00279900);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 54, D_00250570);
    if (D_0024F570[56] != 0x38) {
        printf((const char *)D_00279920);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 56, D_002505C0);
    if (D_0024F570[58] != 0x3a) {
        printf((const char *)D_00279940);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 58, D_00250600);
    if (D_0024F570[60] != 0x3c) {
        printf((const char *)D_00279960);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 60, D_00250620);
    if (D_0024F570[62] != 0x3e) {
        printf((const char *)D_00279980);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 62, D_002506B0);
    if (D_0024F570[64] != 0x40) {
        printf((const char *)D_002799A0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 64, D_002506F0);
    if (D_0024F570[66] != 0x42) {
        printf((const char *)D_002799C0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 66, D_00250740);
    if (D_0024F570[68] != 0x44) {
        printf((const char *)D_002799E0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 68, D_0024F790);
    if (D_0024F570[70] != 0x46) {
        printf((const char *)D_00279A00);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 70, D_0024F7D0);
    if (D_0024F570[72] != 0x48) {
        printf((const char *)D_00279A20);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 72, D_0024F870);
    if (D_0024F570[74] != 0x4a) {
        printf((const char *)D_00279A40);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 74, D_0024F8B0);
    if (D_0024F570[76] != 0x4c) {
        printf((const char *)D_00279A60);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 76, D_0024F950);
    if (D_0024F570[78] != 0x4e) {
        printf((const char *)D_00279A80);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 78, D_0024F990);
    if (D_0024F570[80] != 0x50) {
        printf((const char *)D_00279AA0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 80, D_0024FA30);
    if (D_0024F570[82] != 0x52) {
        printf((const char *)D_00279AC0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 82, D_0024FAA0);
    if (D_0024F570[84] != 0x54) {
        printf((const char *)D_00279AE0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 84, D_0024FBB0);
    if (D_0024F570[86] != 0x56) {
        printf((const char *)D_00279B00);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 86, D_0024FC30);
    if (D_0024F570[88] != 0x58) {
        printf((const char *)D_00279B20);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 88, D_0024FD50);
    if (D_0024F570[90] != 0x5a) {
        printf((const char *)D_00279B40);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 90, D_0024FDE0);
    if (D_0024F570[92] != 0x5c) {
        printf((const char *)D_00279B60);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 92, D_0024FF20);
    if (D_0024F570[94] != 0x5e) {
        printf((const char *)D_00279B80);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 94, D_0024FF90);
    if (D_0024F570[96] != 0x60) {
        printf((const char *)D_00279BA0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 96, D_0024FFD0);
    if (D_0024F570[98] != 0x62) {
        printf((const char *)D_00279BC0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 98, D_00250060);
    if (D_0024F570[100] != 0x64) {
        printf((const char *)D_00279BE0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 100, D_002500B0);
    if (D_0024F570[102] != 0x66) {
        printf((const char *)D_00279C00);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 102, D_00250130);
    if (D_0024F570[104] != 0x68) {
        printf((const char *)D_00279C20);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 104, D_00250170);
    if (D_0024F570[106] != 0x6a) {
        printf((const char *)D_00279C40);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 106, D_00250210);
    if (D_0024F570[108] != 0x6c) {
        printf((const char *)D_00279C60);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 108, D_00250260);
    if (D_0024F570[110] != 0x6e) {
        printf((const char *)D_00279C80);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 110, D_002502C0);
    if (D_0024F570[112] != 0x70) {
        printf((const char *)D_00279CA0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 112, D_002502F0);
    if (D_0024F570[114] != 0x72) {
        printf((const char *)D_00279CC0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 114, D_002503A0);
    if (D_0024F570[116] != 0x74) {
        printf((const char *)D_00279CE0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 116, D_002503F0);
    if (D_0024F570[118] != 0x76) {
        printf((const char *)D_00279D00);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 118, D_00250490);
    if (D_0024F570[120] != 0x78) {
        printf((const char *)D_00279D20);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 120, D_002504D0);
    if (D_0024F570[122] != 0x7a) {
        printf((const char *)D_00279D40);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 122, D_00250570);
    if (D_0024F570[124] != 0x7c) {
        printf((const char *)D_00279D60);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 124, D_002505C0);
    if (D_0024F570[126] != 0x7e) {
        printf((const char *)D_00279D80);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 126, D_00250600);
    if (D_0024F570[128] != 0x80) {
        printf((const char *)D_00279DA0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 128, D_00250620);
    if (D_0024F570[130] != 0x82) {
        printf((const char *)D_00279DC0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 130, D_002506B0);
    if (D_0024F570[132] != 0x84) {
        printf((const char *)D_00279DE0);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 132, D_002506F0);
    if (D_0024F570[134] != 0x86) {
        printf((const char *)D_00279E00);
    }
    STORE_POINTER_DIRECT(D_0024F570 + 134, D_00250740);
    if (D_0024F680[0] != 0x0) {
        printf((const char *)D_00279E20);
    }
    STORE_POINTER_DIRECT(D_0024F680, D_0024F7F0);
    if (D_0024F680[2] != 0x2) {
        printf((const char *)D_00279E40);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 2, D_0024F850);
    if (D_0024F680[4] != 0x4) {
        printf((const char *)D_00279E60);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 4, D_0024F8D0);
    if (D_0024F680[6] != 0x6) {
        printf((const char *)D_00279E80);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 6, D_0024F930);
    if (D_0024F680[8] != 0x8) {
        printf((const char *)D_00279EA0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 8, D_0024F9B0);
    if (D_0024F680[10] != 0xa) {
        printf((const char *)D_00279EC0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 10, D_0024FA10);
    if (D_0024F680[12] != 0xc) {
        printf((const char *)D_00279EE0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 12, D_0024FAE0);
    if (D_0024F680[14] != 0xe) {
        printf((const char *)D_00279F00);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 14, D_0024FB70);
    if (D_0024F680[16] != 0x10) {
        printf((const char *)D_00279F20);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 16, D_0024FC70);
    if (D_0024F680[18] != 0x12) {
        printf((const char *)D_00279F40);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 18, D_0024FD10);
    if (D_0024F680[20] != 0x14) {
        printf((const char *)D_00279F60);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 20, D_0024FE30);
    if (D_0024F680[22] != 0x16) {
        printf((const char *)D_00279F80);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 22, D_0024FED0);
    if (D_0024F680[24] != 0x18) {
        printf((const char *)D_00279FA0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 24, D_00250260);
    if (D_0024F680[26] != 0x1a) {
        printf((const char *)D_00279FC0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 26, D_002502C0);
    if (D_0024F680[28] != 0x1c) {
        printf((const char *)D_00279FE0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 28, D_002502F0);
    if (D_0024F680[30] != 0x1e) {
        printf((const char *)D_0027A000);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 30, D_002503A0);
    if (D_0024F680[32] != 0x20) {
        printf((const char *)D_0027A020);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 32, D_002503F0);
    if (D_0024F680[34] != 0x22) {
        printf((const char *)D_0027A040);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 34, D_00250490);
    if (D_0024F680[36] != 0x24) {
        printf((const char *)D_0027A060);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 36, D_002504D0);
    if (D_0024F680[38] != 0x26) {
        printf((const char *)D_0027A080);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 38, D_00250570);
    if (D_0024F680[40] != 0x28) {
        printf((const char *)D_0027A0A0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 40, D_00250260);
    if (D_0024F680[42] != 0x2a) {
        printf((const char *)D_0027A0C0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 42, D_002502C0);
    if (D_0024F680[44] != 0x2c) {
        printf((const char *)D_0027A0E0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 44, D_002502F0);
    if (D_0024F680[46] != 0x2e) {
        printf((const char *)D_0027A100);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 46, D_002503A0);
    if (D_0024F680[48] != 0x30) {
        printf((const char *)D_0027A120);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 48, D_002503F0);
    if (D_0024F680[50] != 0x32) {
        printf((const char *)D_0027A140);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 50, D_00250490);
    if (D_0024F680[52] != 0x34) {
        printf((const char *)D_0027A160);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 52, D_002504D0);
    if (D_0024F680[54] != 0x36) {
        printf((const char *)D_0027A180);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 54, D_00250570);
    if (D_0024F680[56] != 0x38) {
        printf((const char *)D_0027A1A0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 56, D_002505C0);
    if (D_0024F680[58] != 0x3a) {
        printf((const char *)D_0027A1C0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 58, D_00250600);
    if (D_0024F680[60] != 0x3c) {
        printf((const char *)D_0027A1E0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 60, D_00250620);
    if (D_0024F680[62] != 0x3e) {
        printf((const char *)D_0027A200);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 62, D_002506B0);
    if (D_0024F680[64] != 0x40) {
        printf((const char *)D_0027A220);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 64, D_002506F0);
    if (D_0024F680[66] != 0x42) {
        printf((const char *)D_0027A240);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 66, D_00250740);
    if (D_0024F680[68] != 0x44) {
        printf((const char *)D_0027A260);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 68, D_0024F7F0);
    if (D_0024F680[70] != 0x46) {
        printf((const char *)D_0027A280);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 70, D_0024F850);
    if (D_0024F680[72] != 0x48) {
        printf((const char *)D_0027A2A0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 72, D_0024F8D0);
    if (D_0024F680[74] != 0x4a) {
        printf((const char *)D_0027A2C0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 74, D_0024F930);
    if (D_0024F680[76] != 0x4c) {
        printf((const char *)D_0027A2E0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 76, D_0024F9B0);
    if (D_0024F680[78] != 0x4e) {
        printf((const char *)D_0027A300);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 78, D_0024FA10);
    if (D_0024F680[80] != 0x50) {
        printf((const char *)D_0027A320);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 80, D_0024FAE0);
    if (D_0024F680[82] != 0x52) {
        printf((const char *)D_0027A340);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 82, D_0024FB70);
    if (D_0024F680[84] != 0x54) {
        printf((const char *)D_0027A360);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 84, D_0024FC70);
    if (D_0024F680[86] != 0x56) {
        printf((const char *)D_0027A380);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 86, D_0024FD10);
    if (D_0024F680[88] != 0x58) {
        printf((const char *)D_0027A3A0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 88, D_0024FE30);
    if (D_0024F680[90] != 0x5a) {
        printf((const char *)D_0027A3C0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 90, D_0024FED0);
    if (D_0024F680[92] != 0x5c) {
        printf((const char *)D_0027A3E0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 92, D_00250260);
    if (D_0024F680[94] != 0x5e) {
        printf((const char *)D_0027A400);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 94, D_002502C0);
    if (D_0024F680[96] != 0x60) {
        printf((const char *)D_0027A420);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 96, D_002502F0);
    if (D_0024F680[98] != 0x62) {
        printf((const char *)D_0027A440);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 98, D_002503A0);
    if (D_0024F680[100] != 0x64) {
        printf((const char *)D_0027A460);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 100, D_002503F0);
    if (D_0024F680[102] != 0x66) {
        printf((const char *)D_0027A480);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 102, D_00250490);
    if (D_0024F680[104] != 0x68) {
        printf((const char *)D_0027A4A0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 104, D_002504D0);
    if (D_0024F680[106] != 0x6a) {
        printf((const char *)D_0027A4C0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 106, D_00250570);
    if (D_0024F680[108] != 0x6c) {
        printf((const char *)D_0027A4E0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 108, D_00250260);
    if (D_0024F680[110] != 0x6e) {
        printf((const char *)D_0027A500);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 110, D_002502C0);
    if (D_0024F680[112] != 0x70) {
        printf((const char *)D_0027A520);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 112, D_002502F0);
    if (D_0024F680[114] != 0x72) {
        printf((const char *)D_0027A540);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 114, D_002503A0);
    if (D_0024F680[116] != 0x74) {
        printf((const char *)D_0027A560);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 116, D_002503F0);
    if (D_0024F680[118] != 0x76) {
        printf((const char *)D_0027A580);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 118, D_00250490);
    if (D_0024F680[120] != 0x78) {
        printf((const char *)D_0027A5A0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 120, D_002504D0);
    if (D_0024F680[122] != 0x7a) {
        printf((const char *)D_0027A5C0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 122, D_00250570);
    if (D_0024F680[124] != 0x7c) {
        printf((const char *)D_0027A5E0);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 124, D_002505C0);
    if (D_0024F680[126] != 0x7e) {
        printf((const char *)D_0027A600);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 126, D_00250600);
    if (D_0024F680[128] != 0x80) {
        printf((const char *)D_0027A620);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 128, D_00250620);
    if (D_0024F680[130] != 0x82) {
        printf((const char *)D_0027A640);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 130, D_002506B0);
    if (D_0024F680[132] != 0x84) {
        printf((const char *)D_0027A660);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 132, D_002506F0);
    if (D_0024F680[134] != 0x86) {
        printf((const char *)D_0027A680);
    }
    STORE_POINTER_DIRECT(D_0024F680 + 134, D_00250740);
    if (D_00250A00[67] != 0x3) {
        printf((const char *)D_0027A6A0);
    }
    STORE_POINTER_DIRECT(D_00250A00 + 67, D_00250A00);
    if (D_00250A90[67] != 0x3) {
        printf((const char *)D_0027A6C0);
    }
    STORE_POINTER_DIRECT(D_00250A90 + 67, D_00250A90);
    if (D_00250B20[67] != 0x3) {
        printf((const char *)D_0027A6E0);
    }
    STORE_POINTER_DIRECT(D_00250B20 + 67, D_00250B20);
    if (D_00250BB0[67] != 0x3) {
        printf((const char *)D_0027A700);
    }
    STORE_POINTER_DIRECT(D_00250BB0 + 67, D_00250BB0);
    if (D_00250C40[67] != 0x3) {
        printf((const char *)D_0027A720);
    }
    STORE_POINTER_DIRECT(D_00250C40 + 67, D_00250C40);
    if (D_00250CD0_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027A740);
    }
    STORE_POINTER_DIRECT(D_00250CD0_as_u16_a, D_00250A00);
    if (D_00250CD0[2] != 0x2) {
        printf((const char *)D_0027A760);
    }
    STORE_POINTER_DIRECT(D_00250CD0 + 2, D_00250B20);
    if (D_00250CD0[4] != 0x4) {
        printf((const char *)D_0027A780);
    }
    STORE_POINTER_DIRECT(D_00250CD0 + 4, D_00250BB0);
    if (D_00250CD0[6] != 0x6) {
        printf((const char *)D_0027A7A0);
    }
    STORE_POINTER_DIRECT(D_00250CD0 + 6, D_00250C40);
    if (D_00250D20[16] != 0x8) {
        printf((const char *)D_0027A7C0);
    }
    STORE_POINTER_DIRECT(D_00250D20 + 16, D_00250DA0);
    if (D_00250D20[32] != 0x8) {
        printf((const char *)D_0027A7E0);
    }
    STORE_POINTER_DIRECT(D_00250D20 + 32, D_00250DC0);
    if (D_00250D20[48] != 0x8) {
        printf((const char *)D_0027A800);
    }
    STORE_POINTER_DIRECT(D_00250D20 + 48, D_00250DE0);
    if (D_00250E00[8] != 0x8) {
        printf((const char *)D_0027A820);
    }
    STORE_POINTER_DIRECT(D_00250E00 + 8, D_00250E20);
    if (D_00250EB0[80] != 0x8) {
        printf((const char *)D_0027A840);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 80, D_00250EB0);
    if (D_00250EB0[96] != 0x8) {
        printf((const char *)D_0027A860);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 96, D_00250EB0);
    if (D_00250EB0[112] != 0x8) {
        printf((const char *)D_0027A880);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 112, D_00250EB0);
    if (D_00250EB0[128] != 0x8) {
        printf((const char *)D_0027A8A0);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 128, D_00250EB0);
    if (D_00250EB0[144] != 0x8) {
        printf((const char *)D_0027A8C0);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 144, D_00250EB0);
    if (D_00250EB0[160] != 0x8) {
        printf((const char *)D_0027A8E0);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 160, D_00250EB0);
    if (D_00250EB0[176] != 0x8) {
        printf((const char *)D_0027A900);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 176, D_00250EB0);
    if (D_00250EB0[192] != 0x8) {
        printf((const char *)D_0027A920);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 192, D_00250EB0);
    if (D_00250EB0[208] != 0x8) {
        printf((const char *)D_0027A940);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 208, D_00250EB0);
    if (D_00250EB0[224] != 0x8) {
        printf((const char *)D_0027A960);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 224, D_00250EB0);
    if (D_00250EB0[240] != 0x8) {
        printf((const char *)D_0027A980);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 240, D_00250EB0);
    if (D_00250EB0[256] != 0x8) {
        printf((const char *)D_0027A9A0);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 256, D_00250EB0);
    if (D_00250EB0[272] != 0x8) {
        printf((const char *)D_0027A9C0);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 272, D_00250EB0);
    if (D_00250EB0[288] != 0x8) {
        printf((const char *)D_0027A9E0);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 288, D_00250EB0);
    if (D_00250EB0[304] != 0x8) {
        printf((const char *)D_0027AA00);
    }
    STORE_POINTER_DIRECT(D_00250EB0 + 304, D_00250EB0);
    if (D_00251670[16] != 0x8) {
        printf((const char *)D_0027AA20);
    }
    STORE_POINTER_DIRECT(D_00251670 + 16, D_002515C0);
    if (D_00251670[18] != 0xa) {
        printf((const char *)D_0027AA40);
    }
    STORE_POINTER_DIRECT(D_00251670 + 18, D_002515D0);
    if (D_00251670[20] != 0xc) {
        printf((const char *)D_0027AA60);
    }
    STORE_POINTER_DIRECT(D_00251670 + 20, D_002515E0);
    STORE_POINTER_DIRECT(D_00251670 + 32, D_002515F0);
    if (D_00251670[34] != 0xa) {
        printf((const char *)D_0027AA80);
    }
    STORE_POINTER_DIRECT(D_00251670 + 34, D_00251600);
    if (D_00251670[36] != 0xc) {
        printf((const char *)D_0027AAA0);
    }
    STORE_POINTER_DIRECT(D_00251670 + 36, D_00251610);
    if (D_00251670[48] != 0x8) {
        printf((const char *)D_0027AAC0);
    }
    STORE_POINTER_DIRECT(D_00251670 + 48, D_00251620);
    if (D_00251670[50] != 0xa) {
        printf((const char *)D_0027AAE0);
    }
    STORE_POINTER_DIRECT(D_00251670 + 50, D_00251630);
    if (D_00251670[52] != 0xc) {
        printf((const char *)D_0027AB00);
    }
    STORE_POINTER_DIRECT(D_00251670 + 52, D_00251640);
    if (D_00251670[64] != 0x8) {
        printf((const char *)D_0027AB20);
    }
    STORE_POINTER_DIRECT(D_00251670 + 64, D_00251650);
    if (D_00251670[66] != 0xa) {
        printf((const char *)D_0027AB40);
    }
    STORE_POINTER_DIRECT(D_00251670 + 66, D_00251660);
    if (D_00251670[68] != 0xc) {
        printf((const char *)D_0027AB60);
    }
    STORE_POINTER_DIRECT(D_00251670 + 68, D_00251670);
    if (D_0024D0B8[0] != 0x4) {
        printf((const char *)D_0027AB80);
    }
    STORE_POINTER_DIRECT(D_0024D0B8, D_0024D030_as_u16_a);
    if (D_0024D0C6[0] != 0xb) {
        printf((const char *)D_0027ABA0);
    }
    STORE_POINTER_DIRECT(D_0024D0C6, D_002624F0);
    if (D_0024D0D4[0] != 0x12) {
        printf((const char *)D_0027ABC0);
    }
    STORE_POINTER_DIRECT(D_0024D0D4, D_00262530);
    if (D_0024D238[0] != 0x4) {
        printf((const char *)D_0027ABE0);
    }
    STORE_POINTER_DIRECT(D_0024D238, D_002624F0);
    if (D_0024D246[0] != 0xb) {
        printf((const char *)D_0027AC00);
    }
    STORE_POINTER_DIRECT(D_0024D246, D_00262530);
    if (D_0024D258[0] != 0x4) {
        printf((const char *)D_0027AC20);
    }
    STORE_POINTER_DIRECT(D_0024D258, D_002624F0);
    if (D_0024D266[0] != 0xb) {
        printf((const char *)D_0027AC40);
    }
    STORE_POINTER_DIRECT(D_0024D266, D_00262530);
    if (D_0024D278[0] != 0x4) {
        printf((const char *)D_0027AC60);
    }
    STORE_POINTER_DIRECT(D_0024D278, D_002624F0);
    if (D_0024D286[0] != 0xb) {
        printf((const char *)D_0027AC80);
    }
    STORE_POINTER_DIRECT(D_0024D286, D_00262530);
    if (D_0024D298[0] != 0x4) {
        printf((const char *)D_0027ACA0);
    }
    STORE_POINTER_DIRECT(D_0024D298, D_002624F0);
    if (D_0024D2A6[0] != 0xb) {
        printf((const char *)D_0027ACC0);
    }
    STORE_POINTER_DIRECT(D_0024D2A6, D_00262530);
    if (D_0024D2B8[0] != 0x4) {
        printf((const char *)D_0027ACE0);
    }
    STORE_POINTER_DIRECT(D_0024D2B8, D_002624F0);
    if (D_0024D2C6[0] != 0xb) {
        printf((const char *)D_0027AD00);
    }
    STORE_POINTER_DIRECT(D_0024D2C6, D_00262530);
    if (D_0024E2E6[0] != 0x3) {
        printf((const char *)D_0027AD20);
    }
    STORE_POINTER_DIRECT(D_0024E2E6, D_0028C0A0);
    if (D_0024E2F0[0] != 0x8) {
        printf((const char *)D_0027AD40);
    }
    STORE_POINTER_DIRECT(D_0024E2F0, D_0024E0A0);
    if (D_0024E2FA[0] != 0xd) {
        printf((const char *)D_0027AD60);
    }
    STORE_POINTER_DIRECT(D_0024E2FA, D_0024E0B0);
    if (D_0024E304[0] != 0x12) {
        printf((const char *)D_0027AD80);
    }
    STORE_POINTER_DIRECT(D_0024E304, D_0024E0C0);
    if (D_0024E30E[0] != 0x17) {
        printf((const char *)D_0027ADA0);
    }
    STORE_POINTER_DIRECT(D_0024E30E, D_0024E0D0);
    if (D_0024E318[0] != 0x1c) {
        printf((const char *)D_0027ADC0);
    }
    STORE_POINTER_DIRECT(D_0024E318, D_0024E0E0);
    if (D_0024E322[0] != 0x21) {
        printf((const char *)D_0027ADE0);
    }
    STORE_POINTER_DIRECT(D_0024E322, D_0024E0D0);
    if (D_0024E32C[0] != 0x26) {
        printf((const char *)D_0027AE00);
    }
    STORE_POINTER_DIRECT(D_0024E32C, D_0024E0F8);
    if (D_0024E336[0] != 0x2b) {
        printf((const char *)D_0027AE20);
    }
    STORE_POINTER_DIRECT(D_0024E336, D_0024E110);
    if (D_0024E340[0] != 0x30) {
        printf((const char *)D_0027AE40);
    }
    STORE_POINTER_DIRECT(D_0024E340, D_0024E140);
    if (D_0024E34A[0] != 0x35) {
        printf((const char *)D_0027AE60);
    }
    STORE_POINTER_DIRECT(D_0024E34A, D_0024E150);
    if (D_0024E354[0] != 0x3a) {
        printf((const char *)D_0027AE80);
    }
    STORE_POINTER_DIRECT(D_0024E354, D_0024E170);
    if (D_0024E35E[0] != 0x3f) {
        printf((const char *)D_0027AEA0);
    }
    STORE_POINTER_DIRECT(D_0024E35E, D_0024E188);
    if (D_0024E368[0] != 0x44) {
        printf((const char *)D_0027AEC0);
    }
    STORE_POINTER_DIRECT(D_0024E368, D_0024E1A0);
    if (D_0024E372[0] != 0x49) {
        printf((const char *)D_0027AEE0);
    }
    STORE_POINTER_DIRECT(D_0024E372, D_0024E150);
    if (D_0024E37C[0] != 0x4e) {
        printf((const char *)D_0027AF00);
    }
    STORE_POINTER_DIRECT(D_0024E37C, D_0024E1B8);
    if (D_0024E386[0] != 0x53) {
        printf((const char *)D_0027AF20);
    }
    STORE_POINTER_DIRECT(D_0024E386, D_0024E1C8);
    if (D_0024E390[0] != 0x58) {
        printf((const char *)D_0027AF40);
    }
    STORE_POINTER_DIRECT(D_0024E390, D_0024E1E0);
    if (D_0024E39A[0] != 0x5d) {
        printf((const char *)D_0027AF60);
    }
    STORE_POINTER_DIRECT(D_0024E39A, D_0024E1C8);
    if (D_0024E3A4[0] != 0x62) {
        printf((const char *)D_0027AF80);
    }
    STORE_POINTER_DIRECT(D_0024E3A4, D_0024E188);
    if (D_0024E3AE[0] != 0x67) {
        printf((const char *)D_0027AFA0);
    }
    STORE_POINTER_DIRECT(D_0024E3AE, D_0024E200);
    if (D_0024E3B8[0] != 0x6c) {
        printf((const char *)D_0027AFC0);
    }
    STORE_POINTER_DIRECT(D_0024E3B8, D_0024E188);
    if (D_0024E3C2[0] != 0x71) {
        printf((const char *)D_0027AFE0);
    }
    STORE_POINTER_DIRECT(D_0024E3C2, D_0024E210);
    if (D_0024E3CC[0] != 0x76) {
        printf((const char *)D_0027B000);
    }
    STORE_POINTER_DIRECT(D_0024E3CC, D_0024E220);
    if (D_0024E3D6[0] != 0x7b) {
        printf((const char *)D_0027B020);
    }
    STORE_POINTER_DIRECT(D_0024E3D6, D_0024E2B0);
    if (D_0024E3E0[0] != 0x80) {
        printf((const char *)D_0027B040);
    }
    STORE_POINTER_DIRECT(D_0024E3E0, D_0024E130);
    if (D_0024E3EA[0] != 0x85) {
        printf((const char *)D_0027B060);
    }
    STORE_POINTER_DIRECT(D_0024E3EA, D_0024E230);
    if (D_0024E3F4[0] != 0x8a) {
        printf((const char *)D_0027B080);
    }
    STORE_POINTER_DIRECT(D_0024E3F4, D_0024E240);
    if (D_0024E3FE[0] != 0x8f) {
        printf((const char *)D_0027B0A0);
    }
    STORE_POINTER_DIRECT(D_0024E3FE, D_0024E250);
    if (D_0024E408[0] != 0x94) {
        printf((const char *)D_0027B0C0);
    }
    STORE_POINTER_DIRECT(D_0024E408, D_0024E260);
    if (D_0024E412[0] != 0x99) {
        printf((const char *)D_0027B0E0);
    }
#ifdef DEATH_LABEL
    STORE_POINTER_DIRECT(D_0024E412, D_0024E2C8);
    STORE_POINTER_DIRECT(D_0024E41C, death_D_00254748);
    STORE_POINTER_DIRECT(D_0024E426, death_D_00254758);
    STORE_POINTER_DIRECT(D_0024E430, death_D_00254768);
    STORE_POINTER_DIRECT(death_D_0025495A, death_D_00254778);
    STORE_POINTER_DIRECT(death_D_00254964, death_D_00254790);
    STORE_POINTER_DIRECT(death_D_0025496E, death_D_002547A0);
    STORE_POINTER_DIRECT(death_D_00254978, death_D_002547B0);
    STORE_POINTER_DIRECT(death_D_00254982, death_D_002547C0);
#else
    STORE_POINTER_DIRECT(D_0024E412, D_0024E2C8);
    STORE_POINTER_DIRECT(D_0024E41C, D_0024E280);
    STORE_POINTER_DIRECT(D_0024E426, D_0024E290);
    STORE_POINTER_DIRECT(D_0024E430, D_0024E2A0);
#endif
    if (D_002526D0_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027B100);
    }
    reg_tmp.w = (u32)func_0014CC90;
    D_002526D0_as_u16_a[0] = reg_tmp.h[1];
    D_002526D2[0] = reg_tmp.h[0];
    if (D_002526D2[1] != 0x2) {
        printf((const char *)D_0027B120);
    }
    STORE_POINTER(D_002526D2 + 1, func_0014CD70);
    if (D_002526D2[3] != 0x4) {
        printf((const char *)D_0027B140);
    }
    STORE_POINTER(D_002526D2 + 3, func_0014CEA0);
    if (D_002526D2[5] != 0x6) {
        printf((const char *)D_0027B160);
    }
    STORE_POINTER(D_002526D2 + 5, func_0014CEE0);
    if (D_002526D2[7] != 0x8) {
        printf((const char *)D_0027B180);
    }
    STORE_POINTER(D_002526D2 + 7, func_0014CF10);
    if (D_002526D2[9] != 0xa) {
        printf((const char *)D_0027B1A0);
    }
    STORE_POINTER(D_002526D2 + 9, func_0014CF90);
    if (D_002526D2[11] != 0xc) {
        printf((const char *)D_0027B1C0);
    }
    STORE_POINTER(D_002526D2 + 11, func_0014D170);
    if (D_002526F0_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027B1E0);
    }
    reg_tmp.w = (u32)func_0014D0F0;
    D_002526F0_as_u16_a[0] = reg_tmp.h[1];
    D_002526F2[0] = reg_tmp.h[0];
    if (D_002526F2[1] != 0x2) {
        printf((const char *)D_0027B200);
    }
    STORE_POINTER(D_002526F2 + 1, func_0014D140);
    if (D_002526F2[3] != 0x4) {
        printf((const char *)D_0027B220);
    }
    STORE_POINTER(D_002526F2 + 3, func_0014D150);
    if (D_00252700_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027B240);
    }
    reg_tmp.w = (u32)D_00244070;
    D_00252700_as_u16_a[0] = reg_tmp.h[1];
    D_00252702[0] = reg_tmp.h[0];
    if (D_00252702[1] != 0x2) {
        printf((const char *)D_0027B260);
    }
    STORE_POINTER(D_00252702 + 1, D_002461D0);
    if (D_00252702[3] != 0x4) {
        printf((const char *)D_0027B280);
    }
    STORE_POINTER(D_00252702 + 3, D_00247080);
    if (D_00252702[5] != 0x6) {
        printf((const char *)D_0027B2A0);
    }
    STORE_POINTER(D_00252702 + 5, D_00249610);
    if (D_00252702[7] != 0x8) {
        printf((const char *)D_0027B2C0);
    }
    STORE_POINTER(D_00252702 + 7, D_0024C240);
    if (D_00252720_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027B2E0);
    }
    reg_tmp.w = (u32)D_002420F0;
    D_00252720_as_u16_a[0] = reg_tmp.h[1];
    D_00252722[0] = reg_tmp.h[0];
    if (D_00252722[1] != 0x2) {
        printf((const char *)D_0027B300);
    }
    STORE_POINTER(D_00252722 + 1, D_00244A30);
    if (D_00252722[3] != 0x4) {
        printf((const char *)D_0027B320);
    }
    STORE_POINTER(D_00252722 + 3, D_00246C90);
    if (D_00252722[5] != 0x6) {
        printf((const char *)D_0027B340);
    }
    STORE_POINTER(D_00252722 + 5, D_00247880);
    if (D_00252722[7] != 0x8) {
        printf((const char *)D_0027B360);
    }
    STORE_POINTER(D_00252722 + 7, D_00249ED0);
    if (D_0028C160[0] != 0x0) {
        printf((const char *)D_0027B380);
    }
    STORE_POINTER(D_0028C160, D_00252800);
    if (D_0028C160[2] != 0x2) {
        printf((const char *)D_0027B3A0);
    }
    STORE_POINTER(D_0028C160 + 2, D_00252990);
    if (D_0028C168[0] != 0x0) {
        printf((const char *)D_0027B3C0);
    }
    STORE_POINTER(D_0028C168, D_00252AE0);
    if (D_0028C168[2] != 0x2) {
        printf((const char *)D_0027B3E0);
    }
    STORE_POINTER(D_0028C168 + 2, D_00252BB0);
    if (D_0028C170[0] != 0x0) {
        printf((const char *)D_0027B400);
    }
    STORE_POINTER(D_0028C170, D_00252C90);
    if (D_0028C170[2] != 0x2) {
        printf((const char *)D_0027B420);
    }
    STORE_POINTER(D_0028C170 + 2, D_00252D70);
    if (D_0028C178[0] != 0x0) {
        printf((const char *)D_0027B440);
    }
    STORE_POINTER(D_0028C178, D_00252E60);
    if (D_0028C178[2] != 0x2) {
        printf((const char *)D_0027B460);
    }
    STORE_POINTER(D_0028C178 + 2, D_00252F40);
    if (D_0028C180[0] != 0x0) {
        printf((const char *)D_0027B480);
    }
    STORE_POINTER(D_0028C180, D_00253020);
    if (D_0028C180[2] != 0x2) {
        printf((const char *)D_0027B4A0);
    }
    STORE_POINTER(D_0028C180 + 2, D_00253160);
    if (D_00252740[0] != 0x0) {
        printf((const char *)D_0027B4C0);
    }
    STORE_POINTER(D_00252740, D_0028C160);
    if (D_00252740[2] != 0x2) {
        printf((const char *)D_0027B4E0);
    }
    STORE_POINTER(D_00252740 + 2, D_0028C168);
    if (D_00252740[4] != 0x4) {
        printf((const char *)D_0027B500);
    }
    STORE_POINTER(D_00252740 + 4, D_0028C170);
    if (D_00252740[6] != 0x6) {
        printf((const char *)D_0027B520);
    }
    STORE_POINTER(D_00252740 + 6, D_0028C178);
    if (D_00252740[8] != 0x8) {
        printf((const char *)D_0027B540);
    }
    STORE_POINTER(D_00252740 + 8, D_0028C180);
    if (D_00252760[0] != 0x0) {
        printf((const char *)D_0027B560);
    }
    STORE_POINTER(D_00252760, D_002606F0);
    if (D_00252760[3] != 0x3) {
        printf((const char *)D_0027B580);
    }
    STORE_POINTER(D_00252760 + 3, D_002606B0);
    if (D_00252760[6] != 0x6) {
        printf((const char *)D_0027B5A0);
    }
    STORE_POINTER(D_00252760 + 6, D_00260630);
    if (D_00252760[9] != 0x9) {
        printf((const char *)D_0027B5C0);
    }
    STORE_POINTER(D_00252760 + 9, D_00260670);
    if (D_00252760[12] != 0xc) {
        printf((const char *)D_0027B5E0);
    }
    STORE_POINTER(D_00252760 + 12, D_002607B0);
    if (D_00252760[15] != 0xf) {
        printf((const char *)D_0027B600);
    }
    STORE_POINTER(D_00252760 + 15, D_00260730);
    if (D_00252760[18] != 0x12) {
        printf((const char *)D_0027B620);
    }
    STORE_POINTER(D_00252760 + 18, D_00255470);
    if (D_00252760[21] != 0x15) {
        printf((const char *)D_0027B640);
    }
    STORE_POINTER(D_00252760 + 21, D_00261DB0);
    if (D_00252760[24] != 0x18) {
        printf((const char *)D_0027B660);
    }
    STORE_POINTER(D_00252760 + 24, D_002610B0_as_u16_a);
    if (D_00252760[27] != 0x1b) {
        printf((const char *)D_0027B680);
    }
    STORE_POINTER(D_00252760 + 27, D_00260FB0);
    if (D_00252760[30] != 0x1e) {
        printf((const char *)D_0027B6A0);
    }
    STORE_POINTER(D_00252760 + 30, D_00260FF0);
    if (D_00252760[33] != 0x21) {
        printf((const char *)D_0027B6C0);
    }
    STORE_POINTER(D_00252760 + 33, D_002610F0);
    if (D_00252760[36] != 0x24) {
        printf((const char *)D_0027B6E0);
    }
    STORE_POINTER(D_00252760 + 36, D_00261030);
    if (D_00252760[39] != 0x27) {
        printf((const char *)D_0027B700);
    }
    STORE_POINTER(D_00252760 + 39, D_00261D70);
    if (D_00252760[42] != 0x2a) {
        printf((const char *)D_0027B720);
    }
    STORE_POINTER(D_00252760 + 42, D_00261170);
    if (D_00252760[45] != 0x2d) {
        printf((const char *)D_0027B740);
    }
    STORE_POINTER(D_00252760 + 45, D_00261130);
    if (D_00252760[48] != 0x30) {
        printf((const char *)D_0027B760);
    }
    STORE_POINTER(D_00252760 + 48, D_002612B0);
    if (D_00252760[51] != 0x33) {
        printf((const char *)D_0027B780);
    }
    STORE_POINTER(D_00252760 + 51, D_002611B0);
    if (D_00252760[54] != 0x36) {
        printf((const char *)D_0027B7A0);
    }
    STORE_POINTER(D_00252760 + 54, D_002611F0);
    if (D_00252760[57] != 0x39) {
        printf((const char *)D_0027B7C0);
    }
    STORE_POINTER(D_00252760 + 57, D_00260730);
    if (D_00252760[60] != 0x3c) {
        printf((const char *)D_0027B7E0);
    }
    STORE_POINTER(D_00252760 + 60, D_00261230);
    if (D_00252760[63] != 0x3f) {
        printf((const char *)D_0027B800);
    }
    STORE_POINTER(D_00252760 + 63, D_00261270);
    if (D_002527E8[4] != 0x4) {
        printf((const char *)D_0027B820);
    }
    STORE_POINTER(D_002527E8 + 4, music_play_bgm7);
    if (D_00252800[0] != 0x0) {
        printf((const char *)D_0027B840);
    }
    STORE_POINTER(D_00252800, D_00252760);
    if (D_00252800[2] != 0x2) {
        printf((const char *)D_0027B860);
    }
    STORE_POINTER(D_00252800 + 2, D_002527E8);
    if (D_00252A20[0] != 0x0) {
        printf((const char *)D_0027B880);
    }
    STORE_POINTER(D_00252A20, D_00255470);
    if (D_00252A20[3] != 0x3) {
        printf((const char *)D_0027B8A0);
    }
    STORE_POINTER(D_00252A20 + 3, D_00261DB0);
    if (D_00252A20[6] != 0x6) {
        printf((const char *)D_0027B8C0);
    }
    STORE_POINTER(D_00252A20 + 6, D_002610B0_as_u16_a);
    if (D_00252A20[9] != 0x9) {
        printf((const char *)D_0027B8E0);
    }
    STORE_POINTER(D_00252A20 + 9, D_00260FB0);
    if (D_00252A20[12] != 0xc) {
        printf((const char *)D_0027B900);
    }
    STORE_POINTER(D_00252A20 + 12, D_00260FF0);
    if (D_00252A20[15] != 0xf) {
        printf((const char *)D_0027B920);
    }
    STORE_POINTER(D_00252A20 + 15, D_002610F0);
    if (D_00252A20[18] != 0x12) {
        printf((const char *)D_0027B940);
    }
    STORE_POINTER(D_00252A20 + 18, D_00261030);
    if (D_00252A20[21] != 0x15) {
        printf((const char *)D_0027B960);
    }
    STORE_POINTER(D_00252A20 + 21, D_00261D70);
    if (D_00252A20[24] != 0x18) {
        printf((const char *)D_0027B980);
    }
    STORE_POINTER(D_00252A20 + 24, D_002606F0);
    if (D_00252A20[27] != 0x1b) {
        printf((const char *)D_0027B9A0);
    }
    STORE_POINTER(D_00252A20 + 27, D_002606B0);
    if (D_00252A20[30] != 0x1e) {
        printf((const char *)D_0027B9C0);
    }
    STORE_POINTER(D_00252A20 + 30, D_00260630);
    if (D_00252A20[33] != 0x21) {
        printf((const char *)D_0027B9E0);
    }
    STORE_POINTER(D_00252A20 + 33, D_00260570);
    if (D_00252A20[36] != 0x24) {
        printf((const char *)D_0027BA00);
    }
    STORE_POINTER(D_00252A20 + 36, D_002605F0);
    if (D_00252A20[39] != 0x27) {
        printf((const char *)D_0027BA20);
    }
    STORE_POINTER(D_00252A20 + 39, D_00260730);
    if (D_00252A20[42] != 0x2a) {
        printf((const char *)D_0027BA40);
    }
    STORE_POINTER(D_00252A20 + 42, D_00260670);
    if (D_00252A20[45] != 0x2d) {
        printf((const char *)D_0027BA60);
    }
    STORE_POINTER(D_00252A20 + 45, D_00261370);
    if (D_00252A20[48] != 0x30) {
        printf((const char *)D_0027BA80);
    }
    STORE_POINTER(D_00252A20 + 48, D_002614F0);
    if (D_00252A20[51] != 0x33) {
        printf((const char *)D_0027BAA0);
    }
    STORE_POINTER(D_00252A20 + 51, D_002612F0);
    if (D_00252A20[54] != 0x36) {
        printf((const char *)D_0027BAC0);
    }
    STORE_POINTER(D_00252A20 + 54, D_002605B0);
    if (D_00252A20[57] != 0x39) {
        printf((const char *)D_0027BAE0);
    }
    STORE_POINTER(D_00252A20 + 57, D_00261530);
    if (D_00252A20[60] != 0x3c) {
        printf((const char *)D_0027BB00);
    }
    STORE_POINTER(D_00252A20 + 60, D_00261330);
    if (D_00252A20[63] != 0x3f) {
        printf((const char *)D_0027BB20);
    }
    STORE_POINTER(D_00252A20 + 63, D_002613B0);
    if (D_00252A20[66] != 0x42) {
        printf((const char *)D_0027BB40);
    }
    STORE_POINTER(D_00252A20 + 66, D_002613F0);
    if (D_00252A20[69] != 0x45) {
        printf((const char *)D_0027BB60);
    }
    STORE_POINTER(D_00252A20 + 69, D_00261430);
    if (D_00252A20[72] != 0x48) {
        printf((const char *)D_0027BB80);
    }
    STORE_POINTER(D_00252A20 + 72, D_00261470);
    if (D_00252A20[75] != 0x4b) {
        printf((const char *)D_0027BBA0);
    }
    STORE_POINTER(D_00252A20 + 75, D_002614B0);
    if (D_00252AC0[2] != 0x2) {
        printf((const char *)D_0027BBC0);
    }
    STORE_POINTER(D_00252AC0 + 2, music_play_bgm3);
    if (D_00252AC0[8] != 0x8) {
        printf((const char *)D_0027BBE0);
    }
    STORE_POINTER(D_00252AC0 + 8, music_play_bgm7);
    if (D_00252AE0[0] != 0x0) {
        printf((const char *)D_0027BC00);
    }
    STORE_POINTER(D_00252AE0, D_00252A20);
    if (D_00252AE0[2] != 0x2) {
        printf((const char *)D_0027BC20);
    }
    STORE_POINTER(D_00252AE0 + 2, D_00252AC0);
    if (D_00252BD0[0] != 0x0) {
        printf((const char *)D_0027BC40);
    }
    STORE_POINTER(D_00252BD0, D_00255470);
    if (D_00252BD0[3] != 0x3) {
        printf((const char *)D_0027BC60);
    }
    STORE_POINTER(D_00252BD0 + 3, D_00261DB0);
    if (D_00252BD0[6] != 0x6) {
        printf((const char *)D_0027BC80);
    }
    STORE_POINTER(D_00252BD0 + 6, D_002610B0_as_u16_a);
    if (D_00252BD0[9] != 0x9) {
        printf((const char *)D_0027BCA0);
    }
    STORE_POINTER(D_00252BD0 + 9, D_00260FB0);
    if (D_00252BD0[12] != 0xc) {
        printf((const char *)D_0027BCC0);
    }
    STORE_POINTER(D_00252BD0 + 12, D_00260FF0);
    if (D_00252BD0[15] != 0xf) {
        printf((const char *)D_0027BCE0);
    }
    STORE_POINTER(D_00252BD0 + 15, D_002610F0);
    if (D_00252BD0[18] != 0x12) {
        printf((const char *)D_0027BD00);
    }
    STORE_POINTER(D_00252BD0 + 18, D_00261030);
    if (D_00252BD0[21] != 0x15) {
        printf((const char *)D_0027BD20);
    }
    STORE_POINTER(D_00252BD0 + 21, D_00261D70);
    if (D_00252BD0[24] != 0x18) {
        printf((const char *)D_0027BD40);
    }
    STORE_POINTER(D_00252BD0 + 24, D_002606F0);
    if (D_00252BD0[27] != 0x1b) {
        printf((const char *)D_0027BD60);
    }
    STORE_POINTER(D_00252BD0 + 27, D_002606B0);
    if (D_00252BD0[30] != 0x1e) {
        printf((const char *)D_0027BD80);
    }
    STORE_POINTER(D_00252BD0 + 30, D_00260630);
    if (D_00252BD0[33] != 0x21) {
        printf((const char *)D_0027BDA0);
    }
    STORE_POINTER(D_00252BD0 + 33, D_002608B0);
    if (D_00252BD0[36] != 0x24) {
        printf((const char *)D_0027BDC0);
    }
    STORE_POINTER(D_00252BD0 + 36, D_002605F0);
    if (D_00252BD0[39] != 0x27) {
        printf((const char *)D_0027BDE0);
    }
    STORE_POINTER(D_00252BD0 + 39, D_00260730);
    if (D_00252BD0[42] != 0x2a) {
        printf((const char *)D_0027BE00);
    }
    STORE_POINTER(D_00252BD0 + 42, D_00260670);
    if (D_00252BD0[45] != 0x2d) {
        printf((const char *)D_0027BE20);
    }
    STORE_POINTER(D_00252BD0 + 45, D_00260630);
    if (D_00252BD0[48] != 0x30) {
        printf((const char *)D_0027BE40);
    }
    STORE_POINTER(D_00252BD0 + 48, D_002608F0);
    if (D_00252BD0[51] != 0x33) {
        printf((const char *)D_0027BE60);
    }
    STORE_POINTER(D_00252BD0 + 51, D_002606B0);
    if (D_00252BD0[54] != 0x36) {
        printf((const char *)D_0027BE80);
    }
    STORE_POINTER(D_00252BD0 + 54, D_002616B0);
    if (D_00252BD0[57] != 0x39) {
        printf((const char *)D_0027BEA0);
    }
    STORE_POINTER(D_00252BD0 + 57, D_00261670);
    if (D_00252BD0[60] != 0x3c) {
        printf((const char *)D_0027BEC0);
    }
    STORE_POINTER(D_00252BD0 + 60, D_00261630);
    if (D_00252BD0[63] != 0x3f) {
        printf((const char *)D_0027BEE0);
    }
    STORE_POINTER(D_00252BD0 + 63, D_002615F0);
    if (D_00252BD0[66] != 0x42) {
        printf((const char *)D_0027BF00);
    }
    STORE_POINTER(D_00252BD0 + 66, D_00261570);
    if (D_00252BD0[69] != 0x45) {
        printf((const char *)D_0027BF20);
    }
    STORE_POINTER(D_00252BD0 + 69, D_002615B0);
    if (D_00252C70[2] != 0x2) {
        printf((const char *)D_0027BF40);
    }
    STORE_POINTER(D_00252C70 + 2, music_play_bgm4);
    if (D_00252C70[8] != 0x8) {
        printf((const char *)D_0027BF60);
    }
    STORE_POINTER(D_00252C70 + 8, music_play_bgm7);
    if (D_00252C90[0] != 0x0) {
        printf((const char *)D_0027BF80);
    }
    STORE_POINTER(D_00252C90, D_00252BD0);
    if (D_00252C90[2] != 0x2) {
        printf((const char *)D_0027BFA0);
    }
    STORE_POINTER(D_00252C90 + 2, D_00252C70);
    if (D_00252DB0[0] != 0x0) {
        printf((const char *)D_0027BFC0);
    }
    STORE_POINTER(D_00252DB0, D_00255470);
    if (D_00252DB0[3] != 0x3) {
        printf((const char *)D_0027BFE0);
    }
    STORE_POINTER(D_00252DB0 + 3, D_00261DB0);
    if (D_00252DB0[6] != 0x6) {
        printf((const char *)D_0027C000);
    }
    STORE_POINTER(D_00252DB0 + 6, D_002610B0_as_u16_a);
    if (D_00252DB0[9] != 0x9) {
        printf((const char *)D_0027C020);
    }
    STORE_POINTER(D_00252DB0 + 9, D_00260FB0);
    if (D_00252DB0[12] != 0xc) {
        printf((const char *)D_0027C040);
    }
    STORE_POINTER(D_00252DB0 + 12, D_00260FF0);
    if (D_00252DB0[15] != 0xf) {
        printf((const char *)D_0027C060);
    }
    STORE_POINTER(D_00252DB0 + 15, D_002610F0);
    if (D_00252DB0[18] != 0x12) {
        printf((const char *)D_0027C080);
    }
    STORE_POINTER(D_00252DB0 + 18, D_00261030);
    if (D_00252DB0[21] != 0x15) {
        printf((const char *)D_0027C0A0);
    }
    STORE_POINTER(D_00252DB0 + 21, D_00261D70);
    if (D_00252DB0[24] != 0x18) {
        printf((const char *)D_0027C0C0);
    }
    STORE_POINTER(D_00252DB0 + 24, D_002606F0);
    if (D_00252DB0[27] != 0x1b) {
        printf((const char *)D_0027C0E0);
    }
    STORE_POINTER(D_00252DB0 + 27, D_002606B0);
    if (D_00252DB0[30] != 0x1e) {
        printf((const char *)D_0027C100);
    }
    STORE_POINTER(D_00252DB0 + 30, D_00260630);
    if (D_00252DB0[33] != 0x21) {
        printf((const char *)D_0027C120);
    }
    STORE_POINTER(D_00252DB0 + 33, D_002605F0);
    if (D_00252DB0[36] != 0x24) {
        printf((const char *)D_0027C140);
    }
    STORE_POINTER(D_00252DB0 + 36, D_00260730);
    if (D_00252DB0[39] != 0x27) {
        printf((const char *)D_0027C160);
    }
    STORE_POINTER(D_00252DB0 + 39, D_002607F0);
    if (D_00252DB0[42] != 0x2a) {
        printf((const char *)D_0027C180);
    }
    STORE_POINTER(D_00252DB0 + 42, D_00261A30);
    if (D_00252DB0[45] != 0x2d) {
        printf((const char *)D_0027C1A0);
    }
    STORE_POINTER(D_00252DB0 + 45, D_00261930);
    if (D_00252DB0[48] != 0x30) {
        printf((const char *)D_0027C1C0);
    }
    STORE_POINTER(D_00252DB0 + 48, D_00261730_as_u16_a);
    if (D_00252DB0[51] != 0x33) {
        printf((const char *)D_0027C1E0);
    }
    STORE_POINTER(D_00252DB0 + 51, D_00261970);
    if (D_00252DB0[54] != 0x36) {
        printf((const char *)D_0027C200);
    }
    STORE_POINTER(D_00252DB0 + 54, D_002619B0);
    if (D_00252DB0[57] != 0x39) {
        printf((const char *)D_0027C220);
    }
    STORE_POINTER(D_00252DB0 + 57, D_00260830);
    if (D_00252DB0[60] != 0x3c) {
        printf((const char *)D_0027C240);
    }
    STORE_POINTER(D_00252DB0 + 60, D_002607F0);
    if (D_00252DB0[63] != 0x3f) {
        printf((const char *)D_0027C260);
    }
    STORE_POINTER(D_00252DB0 + 63, D_002619F0);
    if (D_00252E40[2] != 0x2) {
        printf((const char *)D_0027C280);
    }
    STORE_POINTER(D_00252E40 + 2, music_play_bgm5);
    if (D_00252E40[8] != 0x8) {
        printf((const char *)D_0027C2A0);
    }
    STORE_POINTER(D_00252E40 + 8, music_play_bgm7);
    if (D_00252E60[0] != 0x0) {
        printf((const char *)D_0027C2C0);
    }
    STORE_POINTER(D_00252E60, D_00252DB0);
    if (D_00252E60[2] != 0x2) {
        printf((const char *)D_0027C2E0);
    }
    STORE_POINTER(D_00252E60 + 2, D_00252E40);
    if (D_00252F80[0] != 0x0) {
        printf((const char *)D_0027C300);
    }
    STORE_POINTER(D_00252F80, D_00255470);
    if (D_00252F80[3] != 0x3) {
        printf((const char *)D_0027C320);
    }
    STORE_POINTER(D_00252F80 + 3, D_00261DB0);
    if (D_00252F80[6] != 0x6) {
        printf((const char *)D_0027C340);
    }
    STORE_POINTER(D_00252F80 + 6, D_002610B0_as_u16_a);
    if (D_00252F80[9] != 0x9) {
        printf((const char *)D_0027C360);
    }
    STORE_POINTER(D_00252F80 + 9, D_00260FB0);
    if (D_00252F80[12] != 0xc) {
        printf((const char *)D_0027C380);
    }
    STORE_POINTER(D_00252F80 + 12, D_00260FF0);
    if (D_00252F80[15] != 0xf) {
        printf((const char *)D_0027C3A0);
    }
    STORE_POINTER(D_00252F80 + 15, D_002610F0);
    if (D_00252F80[18] != 0x12) {
        printf((const char *)D_0027C3C0);
    }
    STORE_POINTER(D_00252F80 + 18, D_00261030);
    if (D_00252F80[21] != 0x15) {
        printf((const char *)D_0027C3E0);
    }
    STORE_POINTER(D_00252F80 + 21, D_00261D70);
    if (D_00252F80[24] != 0x18) {
        printf((const char *)D_0027C400);
    }
    STORE_POINTER(D_00252F80 + 24, D_002606F0);
    if (D_00252F80[27] != 0x1b) {
        printf((const char *)D_0027C420);
    }
    STORE_POINTER(D_00252F80 + 27, D_002606B0);
    if (D_00252F80[30] != 0x1e) {
        printf((const char *)D_0027C440);
    }
    STORE_POINTER(D_00252F80 + 30, D_00260630);
    if (D_00252F80[33] != 0x21) {
        printf((const char *)D_0027C460);
    }
    STORE_POINTER(D_00252F80 + 33, D_002605F0);
    if (D_00252F80[36] != 0x24) {
        printf((const char *)D_0027C480);
    }
    STORE_POINTER(D_00252F80 + 36, D_00260730);
    if (D_00252F80[39] != 0x27) {
        printf((const char *)D_0027C4A0);
    }
    STORE_POINTER(D_00252F80 + 39, D_002608B0);
    if (D_00252F80[42] != 0x2a) {
        printf((const char *)D_0027C4C0);
    }
    STORE_POINTER(D_00252F80 + 42, D_00261AB0);
    if (D_00252F80[45] != 0x2d) {
        printf((const char *)D_0027C4E0);
    }
    STORE_POINTER(D_00252F80 + 45, D_00261A70);
    if (D_00252F80[48] != 0x30) {
        printf((const char *)D_0027C500);
    }
    STORE_POINTER(D_00252F80 + 48, D_00260670);
    if (D_00252F80[51] != 0x33) {
        printf((const char *)D_0027C520);
    }
    STORE_POINTER(D_00252F80 + 51, D_00260770);
    if (D_00252F80[54] != 0x36) {
        printf((const char *)D_0027C540);
    }
    STORE_POINTER(D_00252F80 + 54, D_00261B30);
    if (D_00252F80[57] != 0x39) {
        printf((const char *)D_0027C560);
    }
    STORE_POINTER(D_00252F80 + 57, D_00261B70);
    if (D_00253000[2] != 0x2) {
        printf((const char *)D_0027C580);
    }
    STORE_POINTER(D_00253000 + 2, music_play_bgm6);
    if (D_00253000[8] != 0x8) {
        printf((const char *)D_0027C5A0);
    }
    STORE_POINTER(D_00253000 + 8, music_play_bgm8);
    if (D_00253020[0] != 0x0) {
        printf((const char *)D_0027C5C0);
    }
    STORE_POINTER(D_00253020, D_00252F80);
    if (D_00253020[2] != 0x2) {
        printf((const char *)D_0027C5E0);
    }
    STORE_POINTER(D_00253020 + 2, D_00253000);
    if (D_0025BF98[0] != 0x4) {
        printf((const char *)D_0027C600);
    }
    STORE_POINTER(D_0025BF98, D_00261F30);
    if (D_0025BFA6[0] != 0xb) {
        printf((const char *)D_0027C620);
    }
    STORE_POINTER(D_0025BFA6, D_00261F70_as_u16_a);
    if (D_0025BFB4[0] != 0x12) {
        printf((const char *)D_0027C640);
    }
    STORE_POINTER(D_0025BFB4, D_00261FB0_as_u16_a);
    if (D_0025BFC2[0] != 0x19) {
        printf((const char *)D_0027C660);
    }
    STORE_POINTER(D_0025BFC2, D_00261EF0_as_u16_a);
    if (D_0025C3C0[0] != 0x0) {
        printf((const char *)D_0027C680);
    }
    STORE_POINTER(D_0025C3C0, D_0025C040);
    if (D_0025C3C0[2] != 0x2) {
        printf((const char *)D_0027C6A0);
    }
    STORE_POINTER(D_0025C3C0 + 2, D_0025C060);
    if (D_0025C3C0[4] != 0x4) {
        printf((const char *)D_0027C6C0);
    }
    STORE_POINTER(D_0025C3C0 + 4, D_0025C080);
    if (D_0025C3C0[6] != 0x6) {
        printf((const char *)D_0027C6E0);
    }
    STORE_POINTER(D_0025C3C0 + 6, D_0025C0A0);
    if (D_0025C3C0[8] != 0x8) {
        printf((const char *)D_0027C700);
    }
    STORE_POINTER(D_0025C3C0 + 8, D_0025C0C0);
    if (D_0025C3C0[10] != 0xa) {
        printf((const char *)D_0027C720);
    }
    STORE_POINTER(D_0025C3C0 + 10, D_0025C0E0);
    if (D_0025C3C0[12] != 0xc) {
        printf((const char *)D_0027C740);
    }
    STORE_POINTER(D_0025C3C0 + 12, D_0025C100);
    if (D_0025C3C0[14] != 0xe) {
        printf((const char *)D_0027C760);
    }
    STORE_POINTER(D_0025C3C0 + 14, D_0025C120);
    if (D_0025C3C0[16] != 0x10) {
        printf((const char *)D_0027C780);
    }
    STORE_POINTER(D_0025C3C0 + 16, D_0025C140);
    if (D_0025C3C0[18] != 0x12) {
        printf((const char *)D_0027C7A0);
    }
    STORE_POINTER(D_0025C3C0 + 18, D_0025C160);
    if (D_0025C3C0[20] != 0x14) {
        printf((const char *)D_0027C7C0);
    }
    STORE_POINTER(D_0025C3C0 + 20, D_0025C180);
    if (D_0025C3C0[22] != 0x16) {
        printf((const char *)D_0027C7E0);
    }
    STORE_POINTER(D_0025C3C0 + 22, D_0025C1A0);
    if (D_0025C3C0[24] != 0x18) {
        printf((const char *)D_0027C800);
    }
    STORE_POINTER(D_0025C3C0 + 24, D_0025C1C0);
    if (D_0025C3C0[26] != 0x1a) {
        printf((const char *)D_0027C820);
    }
    STORE_POINTER(D_0025C3C0 + 26, D_0025C1E0);
    if (D_0025C3C0[28] != 0x1c) {
        printf((const char *)D_0027C840);
    }
    STORE_POINTER(D_0025C3C0 + 28, D_0025C200);
    if (D_0025C3C0[30] != 0x1e) {
        printf((const char *)D_0027C860);
    }
    STORE_POINTER(D_0025C3C0 + 30, D_0025C220);
    if (D_0025C3C0[32] != 0x20) {
        printf((const char *)D_0027C880);
    }
    STORE_POINTER(D_0025C3C0 + 32, D_0025C240);
    if (D_0025C3C0[34] != 0x22) {
        printf((const char *)D_0027C8A0);
    }
    STORE_POINTER(D_0025C3C0 + 34, D_0025C260);
    if (D_0025C3C0[36] != 0x24) {
        printf((const char *)D_0027C8C0);
    }
    STORE_POINTER(D_0025C3C0 + 36, D_0025C280);
    if (D_0025C3C0[38] != 0x26) {
        printf((const char *)D_0027C8E0);
    }
    STORE_POINTER(D_0025C3C0 + 38, D_0025C2A0);
    if (D_0025C3C0[40] != 0x28) {
        printf((const char *)D_0027C900);
    }
    STORE_POINTER(D_0025C3C0 + 40, D_0025C2C0);
    if (D_0025C3C0[42] != 0x2a) {
        printf((const char *)D_0027C920);
    }
    STORE_POINTER(D_0025C3C0 + 42, D_0025C2E0);
    if (D_0025C3C0[44] != 0x2c) {
        printf((const char *)D_0027C940);
    }
    STORE_POINTER(D_0025C3C0 + 44, D_0025C300);
    if (D_0025C3C0[46] != 0x2e) {
        printf((const char *)D_0027C960);
    }
    STORE_POINTER(D_0025C3C0 + 46, D_0025C320);
    if (D_0025C3C0[48] != 0x30) {
        printf((const char *)D_0027C980);
    }
    STORE_POINTER(D_0025C3C0 + 48, D_0025C340);
    if (D_0025C3C0[50] != 0x32) {
        printf((const char *)D_0027C9A0);
    }
    STORE_POINTER(D_0025C3C0 + 50, D_0025C360);
    if (D_0025C3C0[52] != 0x34) {
        printf((const char *)D_0027C9C0);
    }
    STORE_POINTER(D_0025C3C0 + 52, D_0025C380);
    if (D_0025C3C0[54] != 0x36) {
        printf((const char *)D_0027C9E0);
    }
    STORE_POINTER(D_0025C3C0 + 54, D_0025C3A0);
    if (D_00251A80_as_u16_a[1] != 0x1) {
        printf((const char *)D_0027CA00);
    }
    reg_tmp.w = (u32)input_get_p1_held;
    D_00251A80_as_u16_a[1] = reg_tmp.h[1];
    D_00251A84[0] = reg_tmp.h[0];
    if (D_00251A84[1] != 0x3) {
        printf((const char *)D_0027CA20);
    }
    STORE_POINTER(D_00251A84 + 1, input_get_p1_pressed);
    if (D_00251A90_as_u16_a[1] != 0x1) {
        printf((const char *)D_0027CA40);
    }
    reg_tmp.w = (u32)input_get_p2_held;
    D_00251A90_as_u16_a[1] = reg_tmp.h[1];
    D_00251A94[0] = reg_tmp.h[0];
    if (D_00251A94[1] != 0x3) {
        printf((const char *)D_0027CA60);
    }
    STORE_POINTER(D_00251A94 + 1, input_get_p2_pressed);
    if (D_00251AB0_as_u16_a[1] != 0x1) {
        printf((const char *)D_0027CA80);
    }
    reg_tmp.w = (u32)input_get_p1_held;
    D_00251AB0_as_u16_a[1] = reg_tmp.h[1];
    D_00251AB4[0] = reg_tmp.h[0];
    if (D_00251AB4[1] != 0x3) {
        printf((const char *)D_0027CAA0);
    }
    STORE_POINTER(D_00251AB4 + 1, input_get_p1_pressed);
    if (D_00251AC0_as_u16_a[1] != 0x1) {
        printf((const char *)D_0027CAC0);
    }
    reg_tmp.w = (u32)input_get_p2_held;
    D_00251AC0_as_u16_a[1] = reg_tmp.h[1];
    D_00251AC4[0] = reg_tmp.h[0];
    if (D_00251AC4[1] != 0x3) {
        printf((const char *)D_0027CAE0);
    }
    STORE_POINTER(D_00251AC4 + 1, input_get_p2_pressed);
    if (D_00251AE0[2] != 0x2) {
        printf((const char *)D_0027CB00);
    }
    STORE_POINTER(D_00251AE0 + 2, input_get_p1_held);
    if (D_00251AE0[4] != 0x4) {
        printf((const char *)D_0027CB20);
    }
    STORE_POINTER(D_00251AE0 + 4, input_get_p1_pressed);
    if (D_00251AE0[6] != 0x6) {
        printf((const char *)D_0027CB40);
    }
    STORE_POINTER(D_00251AE0 + 6, func_00130270);
    if (D_00251AE0[8] != 0x8) {
        printf((const char *)D_0027CB60);
    }
    STORE_POINTER(D_00251AE0 + 8, D_0029BF40_as_u16_a);
    if (D_00251B00[2] != 0x2) {
        printf((const char *)D_0027CB80);
    }
    STORE_POINTER(D_00251B00 + 2, input_get_p2_held);
    if (D_00251B00[4] != 0x4) {
        printf((const char *)D_0027CBA0);
    }
    STORE_POINTER(D_00251B00 + 4, input_get_p2_pressed);
    if (D_00251B00[6] != 0x6) {
        printf((const char *)D_0027CBC0);
    }
    STORE_POINTER(D_00251B00 + 6, func_001303A0);
    if (D_00251B00[8] != 0x8) {
        printf((const char *)D_0027CBE0);
    }
    STORE_POINTER(D_00251B00 + 8, D_0029BF30_as_u16_a);
    if (D_00251CC0[0] != 0x0) {
        printf((const char *)D_0027CC00);
    }
    STORE_POINTER(D_00251CC0, D_00251CE0);
    if (D_00251CC0[2] != 0x2) {
        printf((const char *)D_0027CC20);
    }
    STORE_POINTER(D_00251CC0 + 2, D_00260F30);
    if (D_00251CC0[4] != 0x4) {
        printf((const char *)D_0027CC40);
    }
    STORE_POINTER(D_00251CC0 + 4, D_00251D10);
    if (D_00251CC0[6] != 0x6) {
        printf((const char *)D_0027CC60);
    }
    STORE_POINTER(D_00251CC0 + 6, D_00260EF0);
    if (D_00251CC0[8] != 0x8) {
        printf((const char *)D_0027CC80);
    }
    STORE_POINTER(D_00251CC0 + 8, D_00251D40);
    if (D_00251CC0[10] != 0xa) {
        printf((const char *)D_0027CCA0);
    }
    STORE_POINTER(D_00251CC0 + 10, D_00260EB0);
    if (D_0028C148_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027CCC0);
    }
    reg_tmp.w = (u32)D_0028C680;
    D_0028C148_as_u16_a[0] = reg_tmp.h[1];
    D_0028C14A[0] = reg_tmp.h[0];
    if (D_0028C14A[1] != 0x2) {
        printf((const char *)D_0027CCE0);
    }
    STORE_POINTER(D_0028C14A + 1, D_0028C708);
    if (D_00252010[0] != 0x0) {
        printf((const char *)D_0027CD00);
    }
    STORE_POINTER(D_00252010, D_00252020);
    if (D_00252010[2] != 0x2) {
        printf((const char *)D_0027CD20);
    }
    STORE_POINTER(D_00252010 + 2, D_00252030);
    if (D_00252010[4] != 0x4) {
        printf((const char *)D_0027CD40);
    }
    STORE_POINTER(D_00252010 + 4, D_00252040);
    if (D_00252020[0] != 0x0) {
        printf((const char *)D_0027CD60);
    }
    STORE_POINTER(D_00252020, D_00252090);
    if (D_00252020[2] != 0x2) {
        printf((const char *)D_0027CD80);
    }
    STORE_POINTER(D_00252020 + 2, D_002520A0);
    if (D_00252020[4] != 0x4) {
        printf((const char *)D_0027CDA0);
    }
    STORE_POINTER(D_00252020 + 4, D_002520B0);
    if (D_00252030[0] != 0x0) {
        printf((const char *)D_0027CDC0);
    }
    STORE_POINTER(D_00252030, D_002520C0);
    if (D_00252030[2] != 0x2) {
        printf((const char *)D_0027CDE0);
    }
    STORE_POINTER(D_00252030 + 2, D_002520D0);
    if (D_00252030[4] != 0x4) {
        printf((const char *)D_0027CE00);
    }
    STORE_POINTER(D_00252030 + 4, D_002520E0);
    if (D_00252040[0] != 0x0) {
        printf((const char *)D_0027CE20);
    }
    STORE_POINTER(D_00252040, D_002520F0);
    if (D_00252040[2] != 0x2) {
        printf((const char *)D_0027CE40);
    }
    STORE_POINTER(D_00252040 + 2, D_00252100);
    if (D_00252040[4] != 0x4) {
        printf((const char *)D_0027CE60);
    }
    STORE_POINTER(D_00252040 + 4, D_00252110);
    if (D_00252050[0] != 0x0) {
        printf((const char *)D_0027CE80);
    }
    STORE_POINTER(D_00252050, D_00252060);
    if (D_00252050[2] != 0x2) {
        printf((const char *)D_0027CEA0);
    }
    STORE_POINTER(D_00252050 + 2, D_00252070);
    if (D_00252050[4] != 0x4) {
        printf((const char *)D_0027CEC0);
    }
    STORE_POINTER(D_00252050 + 4, D_00252080);
    if (D_00252060[0] != 0x0) {
        printf((const char *)D_0027CEE0);
    }
    STORE_POINTER(D_00252060, D_00252120);
    if (D_00252060[2] != 0x2) {
        printf((const char *)D_0027CF00);
    }
    STORE_POINTER(D_00252060 + 2, D_00252130);
    if (D_00252060[4] != 0x4) {
        printf((const char *)D_0027CF20);
    }
    STORE_POINTER(D_00252060 + 4, D_00252140);
    if (D_00252070[0] != 0x0) {
        printf((const char *)D_0027CF40);
    }
    STORE_POINTER(D_00252070, D_00252150);
    if (D_00252070[2] != 0x2) {
        printf((const char *)D_0027CF60);
    }
    STORE_POINTER(D_00252070 + 2, D_00252160);
    if (D_00252070[4] != 0x4) {
        printf((const char *)D_0027CF80);
    }
    STORE_POINTER(D_00252070 + 4, D_00252170);
    if (D_00252080[0] != 0x0) {
        printf((const char *)D_0027CFA0);
    }
    STORE_POINTER(D_00252080, D_00252180);
    if (D_00252080[2] != 0x2) {
        printf((const char *)D_0027CFC0);
    }
    STORE_POINTER(D_00252080 + 2, D_00252190);
    if (D_00252080[4] != 0x4) {
        printf((const char *)D_0027CFE0);
    }
    STORE_POINTER(D_00252080 + 4, D_002521A0);
    if (D_002520C0[3] != 0x3) {
        printf((const char *)D_0027D000);
    }
    STORE_POINTER(D_002520C0 + 3, D_002521B0);
    if (D_002520D0[3] != 0x3) {
        printf((const char *)D_0027D020);
    }
    STORE_POINTER(D_002520D0 + 3, D_002521D0);
    if (D_002520E0[3] != 0x3) {
        printf((const char *)D_0027D040);
    }
    STORE_POINTER(D_002520E0 + 3, D_002521F0);
    if (D_00252150[3] != 0x3) {
        printf((const char *)D_0027D060);
    }
    STORE_POINTER(D_00252150 + 3, D_002521B0);
    if (D_00252160[3] != 0x3) {
        printf((const char *)D_0027D080);
    }
    STORE_POINTER(D_00252160 + 3, D_002521D0);
    if (D_00252170[3] != 0x3) {
        printf((const char *)D_0027D0A0);
    }
    STORE_POINTER(D_00252170 + 3, D_002521F0);
    if (D_00252210[0] != 0x0) {
        printf((const char *)D_0027D0C0);
    }
    STORE_POINTER(D_00252210, D_00252230);
    if (D_00252210[2] != 0x2) {
        printf((const char *)D_0027D0E0);
    }
    STORE_POINTER(D_00252210 + 2, D_00252240);
    if (D_00252210[4] != 0x4) {
        printf((const char *)D_0027D100);
    }
    STORE_POINTER(D_00252210 + 4, D_00252250);
    if (D_00252220[0] != 0x0) {
        printf((const char *)D_0027D120);
    }
    STORE_POINTER(D_00252220, D_00252268);
    if (D_00252220[2] != 0x2) {
        printf((const char *)D_0027D140);
    }
    STORE_POINTER(D_00252220 + 2, D_00252278);
    if (D_00252220[4] != 0x4) {
        printf((const char *)D_0027D160);
    }
    STORE_POINTER(D_00252220 + 4, D_00252290);
    if (D_00252230[3] != 0x3) {
        printf((const char *)D_0027D180);
    }
    STORE_POINTER(D_00252230 + 3, D_002522B0);
    if (D_00252240[3] != 0x3) {
        printf((const char *)D_0027D1A0);
    }
    STORE_POINTER(D_00252240 + 3, D_002522D0);
    if (D_00252250[3] != 0x3) {
        printf((const char *)D_0027D1C0);
    }
    STORE_POINTER(D_00252250 + 3, D_002522F0);
    if (D_00252250[8] != 0x8) {
        printf((const char *)D_0027D1E0);
    }
    STORE_POINTER(D_00252250 + 8, D_00252310);
    if (D_00252268[3] != 0x3) {
        printf((const char *)D_0027D200);
    }
    STORE_POINTER(D_00252268 + 3, D_002522B0);
    if (D_00252278[3] != 0x3) {
        printf((const char *)D_0027D220);
    }
    STORE_POINTER(D_00252278 + 3, D_002522D0);
    if (D_00252290[3] != 0x3) {
        printf((const char *)D_0027D240);
    }
    STORE_POINTER(D_00252290 + 3, D_002522F0);
    if (D_00252290[8] != 0x8) {
        printf((const char *)D_0027D260);
    }
    STORE_POINTER(D_00252290 + 8, D_00252310);
    if (D_002643E0_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027D280);
    }
    reg_tmp.w = (u32)D_002644E0;
    D_002643E0_as_u16_a[0] = reg_tmp.h[1];
    D_002643E2[0] = reg_tmp.h[0];
    if (D_002643E2[1] != 0x2) {
        printf((const char *)D_0027D2B0);
    }
    STORE_POINTER(D_002643E2 + 1, D_00264490);
    if (D_002643E2[3] != 0x4) {
        printf((const char *)D_0027D2E0);
    }
    STORE_POINTER(D_002643E2 + 3, D_00264440);
    if (D_002643E2[5] != 0x6) {
        printf((const char *)D_0027D310);
    }
    STORE_POINTER(D_002643E2 + 5, D_002643F0);
    if (D_00264C30[4] != 0x4) {
        printf((const char *)D_0027D340);
    }
    STORE_POINTER(D_00264C30 + 4, D_002610F0);
    if (D_00264C30[11] != 0xb) {
        printf((const char *)D_0027D360);
    }
    STORE_POINTER(D_00264C30 + 11, D_0025FF70_as_u16_a);
    if (D_00264C30[18] != 0x12) {
        printf((const char *)D_0027D380);
    }
    STORE_POINTER(D_00264C30 + 18, D_0025FFB0_as_u16_a);
    if (D_00264C30[25] != 0x19) {
        printf((const char *)D_0027D3A0);
    }
    STORE_POINTER(D_00264C30 + 25, D_0025FFF0_as_u16_a);
    if (D_00264C30[32] != 0x20) {
        printf((const char *)D_0027D3C0);
    }
    STORE_POINTER(D_00264C30 + 32, D_00260030_as_u16_a);
    if (D_00264C30[39] != 0x27) {
        printf((const char *)D_0027D3E0);
    }
    STORE_POINTER(D_00264C30 + 39, D_00260070_as_u16_a);
    if (D_00264C30[46] != 0x2e) {
        printf((const char *)D_0027D400);
    }
    STORE_POINTER(D_00264C30 + 46, D_002600B0_as_u16_a);
    if (D_00264C30[53] != 0x35) {
        printf((const char *)D_0027D420);
    }
    STORE_POINTER(D_00264C30 + 53, D_002600F0_as_u16_a);
    if (D_00264C30[60] != 0x3c) {
        printf((const char *)D_0027D440);
    }
    STORE_POINTER(D_00264C30 + 60, D_0024CA40);
    if (D_00264C30[67] != 0x43) {
        printf((const char *)D_0027D460);
    }
    STORE_POINTER(D_00264C30 + 67, D_0024CA80);
    if (D_00264C30[74] != 0x4a) {
        printf((const char *)D_0027D480);
    }
    STORE_POINTER(D_00264C30 + 74, D_0024CAC0);
    if (D_00264C30[81] != 0x51) {
        printf((const char *)D_0027D4A0);
    }
    STORE_POINTER(D_00264C30 + 81, D_0024CB00);
    if (D_00264C30[88] != 0x58) {
        printf((const char *)D_0027D4C0);
    }
    STORE_POINTER(D_00264C30 + 88, D_0024CB40);
    if (D_00264C30[95] != 0x5f) {
        printf((const char *)D_0027D4E0);
    }
    STORE_POINTER(D_00264C30 + 95, D_0024CB80);
    if (D_00264D00[4] != 0x4) {
        printf((const char *)D_0027D500);
    }
    STORE_POINTER(D_00264D00 + 4, D_002610F0);
    if (D_00264D00[11] != 0xb) {
        printf((const char *)D_0027D520);
    }
    STORE_POINTER(D_00264D00 + 11, D_00260130_as_u16_a);
    if (D_00264D00[18] != 0x12) {
        printf((const char *)D_0027D540);
    }
    STORE_POINTER(D_00264D00 + 18, D_00260170_as_u16_a);
    if (D_00264D00[25] != 0x19) {
        printf((const char *)D_0027D560);
    }
    STORE_POINTER(D_00264D00 + 25, D_0024CA40);
    if (D_00264D00[32] != 0x20) {
        printf((const char *)D_0027D580);
    }
    STORE_POINTER(D_00264D00 + 32, D_0024CA80);
    if (D_00264D00[39] != 0x27) {
        printf((const char *)D_0027D5A0);
    }
    STORE_POINTER(D_00264D00 + 39, D_0024CAC0);
    if (D_00264D00[46] != 0x2e) {
        printf((const char *)D_0027D5C0);
    }
    STORE_POINTER(D_00264D00 + 46, D_0024CB00);
    if (D_00264D00[53] != 0x35) {
        printf((const char *)D_0027D5E0);
    }
    STORE_POINTER(D_00264D00 + 53, D_0024CB40);
    if (D_00264D00[60] != 0x3c) {
        printf((const char *)D_0027D600);
    }
    STORE_POINTER(D_00264D00 + 60, D_0024CB80);
    if (D_00264E10[4] != 0x4) {
        printf((const char *)D_0027D620);
    }
    STORE_POINTER(D_00264E10 + 4, D_002610F0);
    if (D_00264E10[11] != 0xb) {
        printf((const char *)D_0027D640);
    }
    STORE_POINTER(D_00264E10 + 11, D_0024CA40);
    if (D_00264E10[18] != 0x12) {
        printf((const char *)D_0027D660);
    }
    STORE_POINTER(D_00264E10 + 18, D_0024CA80);
    if (D_00264E10[25] != 0x19) {
        printf((const char *)D_0027D680);
    }
    STORE_POINTER(D_00264E10 + 25, D_0024CAC0);
    if (D_00264E10[32] != 0x20) {
        printf((const char *)D_0027D6A0);
    }
    STORE_POINTER(D_00264E10 + 32, D_0024CB00);
    if (D_00264E10[39] != 0x27) {
        printf((const char *)D_0027D6C0);
    }
    STORE_POINTER(D_00264E10 + 39, D_0024CB40);
    if (D_00264E10[46] != 0x2e) {
        printf((const char *)D_0027D6E0);
    }
    STORE_POINTER(D_00264E10 + 46, D_0024CB80);
    if (D_00264E80[3] != 0x3) {
        printf((const char *)D_0027D700);
    }
    STORE_POINTER(D_00264E80 + 3, D_00261D30);
    if (D_00264E80[9] != 0x9) {
        printf((const char *)D_0027D720);
    }
    STORE_POINTER(D_00264E80 + 9, D_00261D30);
    if (D_00264EA0[4] != 0x4) {
        printf((const char *)D_0027D740);
    }
    STORE_POINTER(D_00264EA0 + 4, D_0025FF70_as_u16_a);
    if (D_00264EA0[11] != 0xb) {
        printf((const char *)D_0027D760);
    }
    STORE_POINTER(D_00264EA0 + 11, D_0025FFB0_as_u16_a);
    if (D_00264EA0[18] != 0x12) {
        printf((const char *)D_0027D780);
    }
    STORE_POINTER(D_00264EA0 + 18, D_0025FFF0_as_u16_a);
    if (D_00264EA0[25] != 0x19) {
        printf((const char *)D_0027D7A0);
    }
    STORE_POINTER(D_00264EA0 + 25, D_002600F0_as_u16_a);
}


s32 text_layer_clear();
s32 music_play_bgm13();
s32 sprite_palette_load();
s32 func_001ACBA0();
s32 func_001ACC60();
s32 stage_map_reset();
extern u8 D_00261EF0[];
extern u8 D_00261F30_as_u8_a[];
extern u8 D_00261F70[];
extern u8 D_00261FB0[];
extern u16 D_0028E4B0;
extern u8 D_0028E8B4;
extern u16 g_two_player_seen;
extern s16 g_player2[];
extern s16 g_player1[];
extern u8 D_002BAE00[];

void func_00197F60() {
    stage_map_reset();
#ifndef DEATH_LABEL
    D_0028E4B0 = g_two_player_seen;
#endif
    text_layer_clear();
    *(s8 *)(reg_a5 + 3) = 1;
    memset(D_002BAE00, 0, 0x84);
    reg_a0 = (u8 *)D_00261F30_as_u8_a;
    reg_d0.h[0] = 2;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00261F70;
    reg_d0.h[0] = 3;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00261FB0;
    reg_d0.h[0] = 4;
    sprite_palette_load();
    reg_a0 = (u8 *)D_00261EF0;
    reg_d0.h[0] = 5;
    sprite_palette_load();
    if (0 > g_player1[0]) {
        func_001ACBA0();
        if (cond_flag == 0) {
            D_0028E8B4 |= 1;
        }
    }
    if (0 > g_player2[0]) {
        func_001ACC60();
        if (cond_flag == 0) {
            D_0028E8B4 |= 2;
        }
    }
    *(u8 *)(reg_a5 + 4) = (u8) D_0028E8B4;
    if (*(u8 *)(reg_a5 + 4) != 0) {
        music_play_bgm13();
    }
}

s32 text_layer_clear();                            /* extern */
s32 func_00135ED0();                            /* extern */
s32 func_00137C20();                            /* extern */
s32 func_0013FD80();                            /* extern */
s32 sound_stop_effects();                            /* extern */
s32 text_palette_load();                            /* extern */
extern s32 test_palette_0_as_s32_a[];
extern u8 D_0028E258;
extern u8 D_0028E25C;
extern u8 g_game_mode;
extern s32 D_0028EAFC;

void func_001980A0() {
    func_0013FD80();
    func_00137C20();
    func_00135ED0();
    task_stop_self();
    sound_stop_effects();
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)test_palette_0_as_s32_a;
    text_palette_load();
    if ((s32) D_0028E258 < (s32) D_0028E25C) {
        D_0028E258 = D_0028E25C;
    }
    if (g_game_mode == 2) {
        func_001984C0();
    } else if (func_001981F0() != 0) {
        func_001984C0();
    } else {
        D_0028EAFC = 0xFF;
    }
    reg_d0.h[0] = TASK_ATTRACT;
    task_start();
    (*(s16 *)((u8 *)((s32 *)reg_a0) + (4))) = 0x12;
}

u8 func_00198170(s32 a, s32 b) {
    s8 i;
    s8 val = (s8)a;
    for (i = 0; i < (s8)b; i++) {
        s8 bit = (s8)(val & 1);
        val >>= 1;
        val &= 0x7F;
        if (bit) {
            val |= -0x80;
        }
    }
    return (u8)val;
}

extern u8 D_0027D7C0[];
extern u8 g_setting_ship_stock;
extern u8 g_setting_extend;
extern u8 g_setting_difficulty;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;

s32 func_001981F0(void) {
    if ((g_setting_difficulty == 1) && (g_setting_extend == 0) && (g_setting_ship_stock == 0) && (g_game_mode == 0) && (g_p1_score_digits == 0) && (g_p2_score_digits == 0) && (MAIN_OR_DEATH_LABEL(D_0028E4B0, g_two_player_seen) != 3)) {
#ifdef DEATH_LABEL
        printf((const char *)D_0027D7C0);
#else
        printf((const char *)D_0027D7C0, D_0028E4B0);
#endif
        return 1;
    }
    return 0;
}

s32 rand(void);
extern s8 D_0025C4A0[];
extern const char D_0027D7E0[];
extern s32 D_0028E4AC;
extern u8 D_002BAD50[];
extern u8 D_002BAD63[];
extern u8 D_002BAD70[];
extern s8 D_002BADD0_as_s8_a[];
extern u8 D_002BADF0[];

s32 func_00198280(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 val;
    u8 ch;

    memset(D_002BAD70, 0, 0x60);
    k = 0;
    for (i = 0; i < 12; i++) {
        for (j = 0; j < 8; j++) {
            if (D_002BADF0[i] & (1 << j)) {
                D_002BAD70[k] = 1;
            }
            k++;
        }
    }
    memset(D_002BAD50, 0, 20);
    k = 0;
    for (i = 0; i < 20; i++) {
        val = 0;
        for (j = 0; j < 5; j++) {
            if (D_002BAD70[k] != 0) {
                val |= 1 << j;
            }
            k++;
        }
        D_002BAD50[i] = val;
    }
    for (i = 0; i < 4; i++) {
        if ((rand() % 2) != 0) {
            D_002BAD63[0] |= 1 << (i + 1);
        }
    }
    D_0028E4AC = 0;
    for (i = 0; D_0025C4A0[i] != -1; i++) {
        D_0028E4AC++;
    }
    memset(D_002BADD0_as_s8_a, 0, 30);
    for (i = 0; i < 20; i++) {
        ch = D_002BAD50[i];
        if ((((s32) ch < 0) || ((s32) ch >= D_0028E4AC)) ? 1 : 0) {
            printf((const char *)D_0027D7E0);
            return 0;
        }
        D_002BADD0_as_s8_a[i] = D_0025C4A0[ch];
    }
    return 1;
}

s64 atoi();
s32 sprintf();
extern u8 D_0027D810[];
extern u8 D_0027D820[];
extern u8 D_0027D830[];
extern u8 D_0027D840[];
extern u8 D_0027D850[];
extern u8 D_0027D860[];
extern u8 D_0027D870[];
extern u8 D_0027D880[];
extern u8 D_0027D890[];
extern u8 D_0027D8A0[];
extern u8 D_0027D8B0[];
extern u8 D_0027D8D0[];
extern u8 D_0027D8F0[];
extern u8 D_0028E2BC;
extern u8 D_002BADD0[];
extern u8 D_002BB060_as_u8_a[];
extern u8 D_002BB100_as_u8_a[];
extern u8 D_002BB338_as_u8_a[];
extern u8 D_002BB348_as_u8_a[];
extern u8 D_002BB358_as_u8_a[];
extern u8 D_002BB368_as_u8_a[];
extern u8 D_002BB378_as_u8_a[];
extern u8 D_002BB388_as_u8_a[];
extern u8 D_002BB398_as_u8_a[];
extern u8 D_002BB3B0_as_u8_a[];
extern u8 D_002BB3F0_as_u8_a[];
void func_001984C0(void) {
    u32 save_d0;
    char str[0x28];
    u8 rec[14];
    u8 code[12];
    u32 score;
    u8 name[3];
    u16 val_fc;
    u16 val_fe;
    s32 i;
    u8 *p;
    s32 j;
    s32 i2;
    s32 k;
    s32 bits;
    s32 i1;
    s32 sum;
    u32 v0;
    u8 shift;
    u32 v3;
    u32 v4;
    u8 flags;
    u32 v1;
    u32 v2;
    u8 packed;
    u8 sw;
    u8 x;

    if (D_0028EAFC == 0xFF) return;
    save_d0 = reg_d0.w;
    for (j = 0; j < 14; j++) {
        rec[j] = 0;
    }
    flags = 0;
    score = ((u32 *)D_002BB3F0_as_u8_a)[D_0028EAFC];
    for (i = 0; i < 3; i++) {
        name[i] = ((u32 *)D_002BB3B0_as_u8_a)[D_0028EAFC * 3 + i];
    }
    v0 = ((u16 *)D_002BB388_as_u8_a)[D_0028EAFC];
    v1 = ((u16 *)D_002BB378_as_u8_a)[D_0028EAFC];
    v2 = ((u16 *)D_002BB368_as_u8_a)[D_0028EAFC];
    val_fc = ((u16 *)D_002BB338_as_u8_a)[D_0028EAFC];
    v3 = ((u16 *)D_002BB398_as_u8_a)[D_0028EAFC];
    val_fe = ((u16 *)D_002BB358_as_u8_a)[D_0028EAFC];
    v4 = ((u16 *)D_002BB348_as_u8_a)[D_0028EAFC];
    shift = (u32)D_0028E2BC & 3;
    if (shift == 0) {
        shift = (u8)(shift + 1);
    }
    printf((const char *)D_0027D810, D_0028EAFC);
    printf((const char *)D_0027D820, (u8)shift);
    printf((const char *)D_0027D830, val_fc);
    printf((const char *)D_0027D840, score);
    printf((const char *)D_0027D850, (u16)v0);
    v1 = (u16)(v1 >> 1);
    printf((const char *)D_0027D860, v1);
    v2 = (u16)(v2 >> 1);
    printf((const char *)D_0027D870, v2);
    printf((const char *)D_0027D880, (u16)v3);
    printf((const char *)D_0027D890, val_fe);
    printf((const char *)D_0027D8A0, (u16)v4);
    printf((const char *)D_0027D8B0, name[0], name[1], name[2]);
    packed = (s8)(v1 & 3) << 6;
    packed |= (s8)(v2 & 3) << 4;
    packed |= v0 & 7;
    if (g_game_mode == 2) {
        flags |= 0x80;
    } else {
        flags = 0;
    }
    flags |= (v3 & 1) << 6;
    flags |= (v4 & 0xF) << 2;
    p = (u8 *)&score;
    rec[0] = p[0];
    rec[1] = p[1];
    rec[2] = p[2];
    rec[3] = p[3];
    rec[4] = packed;
    p = (u8 *)&val_fc;
    rec[5] = p[0];
    rec[6] = p[1];
    rec[8] = name[0];
    rec[9] = name[1];
    rec[10] = name[2];
    rec[7] = 0;
    rec[11] = 0;
    p = (u8 *)&val_fe;
    rec[12] = p[0];
    rec[13] = p[1];
    memset(code, 0, 12);
    memcpy(code, rec, 12);
    sum = 0;
    sprintf(str, (const char *)D_0027D8D0, code[3], code[2], code[1], code[0]);
    sum += atoi(str);
    sprintf(str, (const char *)D_0027D8F0, code[6], code[5]);
    sum += atoi(str);
    j = 2;
    bits = 0;
    for (i1 = 0; i1 < 4; i1++, j++) {
        if (code[11] & (1 << j)) {
            bits |= 1 << i1;
        }
    }
    code[0] = 0;
    code[1] = 0;
    code[2] = 0;
    code[3] = 0;
    sum += bits;
    k = 0;
    for (i2 = 0; i2 < 4; i2++) {
        for (j = 0; j < 8; j++, k++) {
            if (sum & (1 << k)) {
                code[i2] |= 1 << j;
            }
        }
    }
    code[5] = rec[12];
    code[6] = rec[13];
    sw = code[0];
    code[0] = code[8];
    code[8] = sw;
    sw = code[5];
    code[5] = code[10];
    code[10] = sw;
    for (i = 0; i < 12; i++) {
        code[i] = func_00198170(code[i], (s8)shift);
    }
    flags |= shift;
    code[11] = flags;
    x = 0;
    for (i = 0; i < 12; i++) {
        x ^= code[i];
    }
    code[7] = x;
    memset(D_002BADF0, 0, 12);
    memcpy(D_002BADF0, code, 12);
    func_00198280();
    if (g_game_mode == 2) {
        memcpy(D_002BB060_as_u8_a + D_0028EAFC * 0x1E, D_002BADD0, 0x1E);
    } else {
        memcpy(D_002BB100_as_u8_a + D_0028EAFC * 0x1E, D_002BADD0, 0x1E);
    }
    reg_d0.w = save_d0;
}


void func_00198B70(void) {
    u8 temp_a0;

    temp_a0 = *(u8 *)(reg_a5 + 3);
    if (temp_a0 == 0) {
        func_00197F60(temp_a0, reg_a5);
        return;
    }
    if (temp_a0 == 2) {
        func_001980A0(temp_a0, reg_a5);
        return;
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 4);
    if (reg_d0.b[0] == 0) {
        func_001980A0(reg_d0.b[0], reg_a5);
        return;
    }
    if (reg_d0.b[0] == 3) {
        func_00198C40(reg_d0.b[0], reg_a5);
        reg_d0.w = 3;
        func_00198D90();
        return;
    }
    if (reg_d0.w & 1) {
        func_00198C40(reg_d0.w, reg_a5);
        return;
    }
    if (reg_d0.w & 2) {
        func_00198D90(reg_d0.w, reg_a5);
    }
}

extern u16 D_002BAE80[];

void func_00198C40() {
    s32 input_get_p1_held();
    s32 input_get_p1_pressed();
    s32 temp_s6;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;

    reg_a4 = (u8 *)D_002BAE00;
    input_get_p1_held();
    *(u16 *)(reg_a4 + 0x34) = (u16) reg_d0.h[0];
    input_get_p1_pressed();
    *(u16 *)(reg_a4 + 0x36) = (u16) reg_d0.h[0];
    reg_d7.h[0] = *(u16 *)(reg_a4 + 2);
    if (reg_d7.h[0] != 0) {
        func_00198F30();
        return;
    }
    *(s16 *)(reg_a4 + 0x12) = 1;
    *(s16 *)(reg_a4 + 0x2C) = 0;
    *(s16 *)(reg_a4 + 0x2E) = 0;
    temp_s6 = (s32)reg_a0;
    temp_s0 = (s32)reg_a1;
    temp_s1 = (s32)reg_a2;
    temp_s2 = (s32)reg_a3;
    temp_s3 = (s32)reg_a4;
    temp_s4 = (s32)reg_a5;
    temp_s5 = (s32)reg_a6;
    func_00199540();
    if (cond_flag != 0) {
        reg_a0 = (u8 *)temp_s6;
        reg_a1 = (u8 *)temp_s0;
        reg_a2 = (u8 *)temp_s1;
        reg_a3 = (u8 *)temp_s2;
        reg_a4 = (u8 *)temp_s3;
        reg_a5 = (u8 *)temp_s4;
        reg_a6 = (u8 *)temp_s5;
        func_001994F0();
        return;
    }
    func_00199710();
    reg_a0 = (u8 *)temp_s6;
    reg_a1 = (u8 *)temp_s0;
    reg_a2 = (u8 *)temp_s1;
    reg_a3 = (u8 *)temp_s2;
    reg_a4 = (u8 *)temp_s3;
    reg_a5 = (u8 *)temp_s4;
    reg_a6 = (u8 *)temp_s5;
    if (D_002BAE80[0] != 0) {
        func_00198F30();
        return;
    }
    func_00198EF0();
}

extern u8 D_002BAE40[];

void func_00198D90() {
    s32 input_get_p2_held();
    s32 input_get_p2_pressed();
    s32 temp_s6;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;

    reg_a4 = (u8 *)D_002BAE40;
    input_get_p2_held();
    *(u16 *)(reg_a4 + 0x34) = (u16) reg_d0.h[0];
    input_get_p2_pressed();
    *(u16 *)(reg_a4 + 0x36) = (u16) reg_d0.h[0];
    reg_d7.h[0] = *(u16 *)(reg_a4 + 2);
    if (reg_d7.h[0] != 0) {
        func_00198F30();
        return;
    }
    *(s16 *)(reg_a4 + 0x12) = 2;
    *(s16 *)(reg_a4 + 0x2C) = 1;
    *(s16 *)(reg_a4 + 0x2E) = 0;
    temp_s6 = (s32)reg_a0;
    temp_s0 = (s32)reg_a1;
    temp_s1 = (s32)reg_a2;
    temp_s2 = (s32)reg_a3;
    temp_s3 = (s32)reg_a4;
    temp_s4 = (s32)reg_a5;
    temp_s5 = (s32)reg_a6;
    func_00199550();
    if (cond_flag != 0) {
        reg_a0 = (u8 *)temp_s6;
        reg_a1 = (u8 *)temp_s0;
        reg_a2 = (u8 *)temp_s1;
        reg_a3 = (u8 *)temp_s2;
        reg_a4 = (u8 *)temp_s3;
        reg_a5 = (u8 *)temp_s4;
        reg_a6 = (u8 *)temp_s5;
        func_001994F0();
        return;
    }
    func_00199710();
    reg_a0 = (u8 *)temp_s6;
    reg_a1 = (u8 *)temp_s0;
    reg_a2 = (u8 *)temp_s1;
    reg_a3 = (u8 *)temp_s2;
    reg_a4 = (u8 *)temp_s3;
    reg_a5 = (u8 *)temp_s4;
    reg_a6 = (u8 *)temp_s5;
    if (D_002BAE80[0] != 0) {
        func_00198F30();
        return;
    }
    func_00198EF0();
}

s32 func_0013B2E0();
extern u8 D_0025BF90[];
extern s16 D_002BAE80_as_s16_a[];

void func_00198EF0() {
    *(s16 *)(reg_a4 + 0x2E) = 1;
    D_002BAE80_as_s16_a[0] = 1;
    reg_a0 = D_0025BF90;
    func_0013B2E0();
    func_00198F30();
}

s32 func_0013BDE0();
s32 sfx_confirm();
extern u8 D_0025BD60[];
extern u8 D_0025BFD0[];
extern u16 D_002BAE82_as_u16_a[];

#define W(o) (*(u16 *)(reg_a4 + (o)))
#define L(p, o) (*(u32 *)((p) + (o)))

void func_00198F30(void) {
    u8 *ptr;

    if (W(0x2E) == 0) goto next_1;
    func_0019A410();
next_1:
    reg_d0.b[0] = reg_a5[4];
    if (reg_d0.b[0] != 3) {
        if (reg_d0.w & 1) {
            func_0019A5B0();
        } else if (reg_d0.w & 2) {
            func_0019A520();
        }
    }
    func_0019A050();
    func_0019A2B0();
    if (W(0x1E) == 0) goto block_count;
    func_00199A50();
    if (D_002BAE82_as_u16_a[0] != 0) return;
    if (W(0x2E) == 0) return;
    if (W(0x1E) != 0x30) goto next_4;
    W(0x1E) -= 1;
    reg_a0 = (u8 *)D_0025BFD0;
    func_0013BDE0();
    return;
next_4:
    W(0x1E) -= 1;
    if (W(0x1E) != 0) goto next_5;
    reg_a5[3] = 2;
    return;
next_5:
    if (W(0x1E) == 0x30) {
        reg_d2.w = 0x20;
    }
    return;
block_count:
    W(2) += 1;
    reg_d7.h[0] = W(2);
    if (reg_d7.h[0] >= 0x30) goto next_6;
    func_00199A50();
    return;
next_6:
    if (reg_d7.h[0] >= 0x738) goto block_fill;
    reg_d0.w = 0xF;
    reg_d0.h[0] &= W(0x36);
    if (reg_d0.h[0] != 0) goto next_7;
    if (reg_a4[0x21] == 0) goto next_8;
    reg_a4[0x20] -= 1;
    if (reg_a4[0x20] != 0) goto next_8;
    func_0019A870();
    goto next_8;
next_7:
    W(0x14) = 0;
    func_0019A640();
next_8:
    func_00199D50();
    func_00199A50();
    reg_d0.h[0] = W(0x36);
    if (!(reg_d0.w & 0x8000)) goto next_9;
    sfx_confirm();
    if (W(0x16) != 0) goto block_fill;
block_default:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_a1 = reg_a0;
    ptr = reg_a1;
    L(ptr, 0) = 0xC;
    L(ptr, 4) = 0xC;
    L(ptr, 8) = 0x3C;
    reg_a1 = ptr + 0xC;
    W(0x16) = 3;
    goto block_copy;
next_9:
    reg_d0.h[0] = W(0x36);
    reg_d3.w = 0x20;
    reg_d3.h[0] &= reg_d0.h[0];
    if (reg_d3.h[0] != 0) goto next_12;
    reg_d0.h[0] &= 0x50;
    if (reg_d0.h[0] == 0) return;
    sfx_confirm();
    reg_d0.h[0] = W(0x18);
    if (reg_d0.h[0] < 27) goto next_13;
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
loop_10:
    reg_d0.w = 0x70;
loop_11:
    reg_d1.h[0] = W(0x16);
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    W(0x16) += 1;
    if (W(0x16) != 3) goto loop_11;
    goto block_check;
block_fill:
    reg_d0.h[0] = W(0x18);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = W(0x16);
    if (W(0x18) < 27) goto next_14;
    reg_d0.w = 0;
    goto block_default;
next_14:
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    W(0x16) += 1;
    if (W(0x16) != 3) goto loop_10;
    goto block_check;
next_12:
    reg_d1.w = 0;
    reg_d1.h[0] = W(0x16);
    if (reg_d1.h[0] == 0) return;
    W(0x16) -= 1;
    reg_d1.h[0] = W(0x16);
    reg_d0.w = 0;
    goto block_store;
next_13:
    reg_d1.h[0] = W(0x16);
    W(0x16) += 1;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
block_store:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    L(reg_a0, reg_d1.h[0] * 4) = reg_d0.w;
    if (W(0x16) < 3) return;
block_check:
    reg_a1 = (u8 *)D_0025BD60;
loop_15:
    reg_tmp.h[1] = W(0x30);
    reg_tmp.h[0] = W(0x32);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 0);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 2);
    if (reg_d0.w == 0xFFFFFFFF) goto block_copy;
    reg_tmp.w = L(reg_a0, 0);
    if (reg_tmp.w != reg_d0.w) goto next_16;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 6);
    reg_tmp.w = L(reg_a0, 4);
    if (reg_tmp.w != reg_d0.w) goto next_16;
    reg_d0.h[1] = *(u16 *)(reg_a1 + 8);
    reg_d0.h[0] = *(u16 *)(reg_a1 + 0xA);
    reg_tmp.w = L(reg_a0, 8);
    if (reg_tmp.w == reg_d0.w) goto block_default;
next_16:
    reg_a1 += 0xC;
    goto loop_15;
block_copy:
    func_00199970();
    reg_d1.h[0] = W(0x12);
    *(u8 *)D_002BAE82_as_u16_a &= ~(1 << reg_d1.sb[0]);
    W(0x1E) = 0x70;
    reg_d0.w = 0;
    W(0x1A) = reg_d0.h[1];
    W(0x1C) = reg_d0.h[0];
    func_00199A50();
}

void func_001994F0(void) {
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2C);
    *(u8 *)(reg_a5 + 4) &= (~(1 << (s8) reg_d0.b[0]) & 0xFF);
    if (*(u8 *)(reg_a5 + 4) == 0) {
        *(s8 *)(reg_a5 + 3) = 2;
    }
}


void func_00199540(void) {
    reg_d0.w = 0xFF;
    func_00199560();
}

void func_00199550(void) {
    reg_d0.w = 0xFE;
    func_00199560();
}

extern u16 D_002BB338_as_u16_a[];
extern u16 D_002BB348_as_u16_a[];
extern u16 D_002BB358_as_u16_a[];
extern u16 D_002BB368_as_u16_a[];
extern u16 D_002BB378_as_u16_a[];
extern u16 D_002BB398_as_u16_a[];
extern s32 D_002BB3B0_as_s32_a[];


void func_00199560(void) {
    u32 tmp;

    cond_flag = 0;
    reg_d4.w = 4;
    reg_d1.w = 0;
    reg_a0 = (u8 *)D_002BB3B0_as_s32_a;
loop_1:
    if (*(u32 *)reg_a0 != reg_d0.w) {
        reg_a0 += 0xC;
        reg_d1.h[0] += 1;
        tmp = reg_d4.h[0] - 1;
        reg_d4.h[0] = tmp;
        if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
        reg_d0.w = 0;
        cond_flag = 1;
        reg_d0.h[0] -= 1;
        return;
    }
    reg_a2 = (u8 *)D_002BB348_as_u16_a;
    reg_d0.h[0] = reg_d1.h[0];
    reg_a3 = (u8 *)D_002BB338_as_u16_a;
    reg_a5 = (u8 *)D_002BB378_as_u16_a;
    reg_a6 = (u8 *)D_002BB368_as_u16_a;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a2 += reg_d0.h[0];
    reg_a3 += reg_d0.h[0];
    reg_a5 += reg_d0.h[0];
    reg_a6 += reg_d0.h[0];
    reg_d2.h[0] = *(u16 *)reg_a3;
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    reg_d2.h[0] = *(u16 *)reg_a2;
    reg_d3.h[0] = ENTITY(reg_a6)->flags.h;
    reg_tmp.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp.h[0];
    reg_d3.h[0] = reg_tmp.h[1];
    reg_d3.h[0] = *(u16 *)reg_a5;
    reg_a2 = (u8 *)D_002BB398_as_u16_a;
    reg_a3 = (u8 *)D_002BB358_as_u16_a;
    reg_a2 += reg_d0.h[0];
    reg_a3 += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *)D_002BB3F0_as_u8_a;
    reg_a1 += reg_d0.h[0];
}

#pragma push
#pragma opt_common_subs off
extern u8 D_0025BE50[];
extern u8 D_0025BE70[];
extern u8 D_002BAE82[];

void func_00199710(void) {
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a4 + 0x30) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x32) = (u16) reg_tmp.h[0];
    *(u16 *)(reg_a4 + 0xC) = (u16) *(u16 *)reg_a1;
    *(u16 *)(reg_a4 + 0xE) = (u16) *(u16 *)(reg_a1 + 2);
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_d2.h[0];
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x10) = (u16) reg_d2.h[0];
    *(u16 *)(reg_a4 + 0x38) = (u16) reg_d1.h[0];
    *(u16 *)(reg_a4 + 0x3A) = (u16) reg_d3.h[0];
    reg_tmp.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp.h[0];
    reg_d3.h[0] = reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x3C) = (u16) reg_d3.h[0];
    reg_d0.w = 1;
    reg_a0 = (u8 *)((u32) D_0025BE50);
    if (*(u16 *)(reg_a4 + 0x2C) != 0) {
        reg_d0.w = 2;
        reg_a0 = (u8 *)((u32) D_0025BE70);
    }
    D_002BAE82[0] |= (1 << (s8) reg_d0.b[0]) & 0xFF;
    *(u16 *)(reg_a4 + 6) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 8) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x14) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x16) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x18) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x1E) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x20) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x22) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x24) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x26) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x28) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0x2A) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
}
#pragma pop

extern u32 D_002BB3B0_as_u32_a[];

void func_00199970(void) {
    u32 t;
    u8 *p;
    u8 *q;

    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2C);
    reg_d0.b[0] = ~(s8) reg_d0.b[0];
    reg_d5.w = 4;
    reg_a1 = (u8 *)(D_002BB3B0_as_u32_a);
loop_1:
    reg_tmp.w = *(u32 *)reg_a1;
    if (reg_tmp.w != reg_d0.w) goto next_2;
    reg_a2 = (u8 *)(reg_a0);
    reg_d7.h[0] = 2;
loop_2:
    p = reg_a2;
    q = reg_a1;
    *(u32 *)q = *(u32 *)p;
    reg_a1 = q + 4;
    reg_a2 = p + 4;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
    goto next_3;
next_2:
    reg_a1 += 0xC;
next_3:
    t = reg_d5.h[0] - 1;
    reg_d5.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
}

s32 sprite_draw_layer4_keep();
s32 sprite_draw_layer4_zoom_keep();
extern u8 D_0025BF10[];

void func_00199A50(void) {
    u32 temp_a1;

    reg_d1.h[0] = 0x4840;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[0] = 0x380;
    reg_d1.h[1] = reg_tmp.h[0];
    if (*(u16 *)(reg_a4 + 0x2C) != 0) {
        reg_d1.h[0] = 0x2240;
    }
    reg_d3.h[0] = 0x418;
    reg_d4.h[0] = 4;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x30);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x32);
    reg_a0 = (u8 *)(reg_tmp.w);
    reg_d7.h[0] = *(u16 *)(reg_a4 + 0x16);
    if (reg_d7.h[0] != 0) {
        reg_d7.h[0] -= 1;
        do {
            temp_a1 = *(u32 *)reg_a0;
            reg_d0.w = temp_a1;
            reg_a0 += 4;
            reg_a1 = (u8 *)D_0025BF10;
            reg_a1 += reg_d0.h[0];
            reg_d2.h[1] = *(u16 *)reg_a1;
            reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d6.w = 0x40004000;
            sprite_draw_layer4_zoom_keep();
            reg_d1.h[0] += 0x600;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    if (*(u16 *)(reg_a4 + 0x16) != 3) {
        reg_a1 = (u8 *)D_0025BF10;
        reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
        reg_d2.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
        sprite_draw_layer4_keep();
        if ((s32) *(u16 *)(reg_a4 + 0x16) < 2) {
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x3E);
            *(u16 *)(reg_a4 + 0x3E) += 4;
            if (reg_d0.h[0] == 0x68) {
                *(u16 *)(reg_a4 + 0x3E) = 0U;
            }
            reg_a1 = (u8 *)D_0025BF10;
            reg_d7.h[0] = 1;
            reg_d7.h[0] -= *(u16 *)(reg_a4 + 0x16);
            do {
                reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d1.h[0] += 0x600;
                reg_d6.w = 0x40004000;
                sprite_draw_layer4_zoom_keep();
                reg_d0.h[0] += 0x34;
                if ((s32) reg_d0.h[0] >= 0x6C) {
                    reg_d0.h[0] -= 0x6C;
                }
            } while ((s16)(--reg_d7.h[0]) >= 0);
        }
    }
}

s32 sprite_draw_layer2_keep();
s32 sprite_draw_layer3_keep();
extern u16 D_0025BE90[];
extern u16 D_0025BEA0[];
extern u16 D_0025BEB0[];
extern u16 D_0025BED0[];
extern u16 D_0025BEF0[];
extern u16 D_0025BF00[];

void func_00199D50(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a1_3;
    u16 temp_a2;
    u16 temp_a3;
    u16 temp_a3_2;
    u32 temp_a1;
    u32 temp_a1_2;
    u32 temp_a2_2;

    *(u8 *)(reg_a4 + 0x23) -= 1;
    if (0 > (s64)*(s8 *)(reg_a4 + 0x23)) {
        *(u8 *)(reg_a4 + 0x23) = (u8) *(u8 *)(reg_a4 + 0x22);
        *(u16 *)(reg_a4 + 0x24) -= 4;
        if (0 > (s16) *(u16 *)(reg_a4 + 0x24)) {
            *(u16 *)(reg_a4 + 0x24) = 0xCU;
        }
    }
    do {
        *(u8 *)(reg_a4 + 0x27) -= 1;
    } while (0 <= (s64)*(s8 *)(reg_a4 + 0x27));
    *(u8 *)(reg_a4 + 0x27) = (u8) *(u8 *)(reg_a4 + 0x26);
    *(u16 *)(reg_a4 + 0x28) -= 8;
    if (0 > (s16) *(u16 *)(reg_a4 + 0x28)) {
        *(u16 *)(reg_a4 + 0x28) = 0x18U;
    }
    reg_d7.h[1] = *(u16 *)(reg_a4 + 6);
    reg_d7.h[0] = *(u16 *)(reg_a4 + 8);
    reg_a0 = (u8 *)(D_0025BE90);
    reg_a1 = (u8 *)(D_0025BEB0);
    reg_a2 = (u8 *)(D_0025BEF0);
    if (*(u16 *)(reg_a4 + 0x2C) != 0) {
        reg_a0 = (u8 *)(D_0025BEA0);
        reg_a1 = (u8 *)(D_0025BED0);
        reg_a2 = (u8 *)(D_0025BF00);
    }
    reg_d4.h[0] = 5;
    reg_d1.w = reg_d7.w;
    temp_a1 = reg_d1.w;
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a2 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a2;
    reg_a2 += 2;
    reg_d1.w = temp_a1 + reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x28);
    reg_a1 += reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    temp_a0 = *(u16 *)reg_a1;
    reg_d2.h[0] = temp_a0;
    reg_a1 += 2;
    reg_d3.h[0] = 0x3808;
    sprite_draw_layer2_keep();
    reg_d1.w = reg_d7.w;
    temp_a3 = *(u16 *)reg_a2;
    temp_a2_2 = reg_d1.w;
    reg_a2 += 2;
    reg_tmp.h[1] = temp_a3;
    temp_a3_2 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a3_2;
    reg_a2 += 2;
    temp_a1_2 = temp_a2_2 + reg_tmp.w;
    reg_d1.w = temp_a1_2;
    temp_a0_2 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d2.h[1] = temp_a0_2;
    temp_a0_3 = *(u16 *)reg_a1;
    reg_d2.h[0] = temp_a0_3;
    reg_a1 += 2;
    reg_d3.h[0] = 0x3C0;
    sprite_draw_layer2_keep();
    reg_d1.w = reg_d7.w;
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a1_3 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a1_3;
    reg_a2 += 2;
    reg_d1.w += reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x24);
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x620;
    sprite_draw_layer3_keep();
}

extern u16 D_0025C020[];

void func_0019A050(void) {
    u32 t;

    reg_d1.h[0] = 0x4040;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[0] = 0x1540;
    reg_d1.h[1] = reg_tmp.h[0];
    switch (*(u16 *)(reg_a4 + 0x2C)) {
    case 0:
        goto next_1;
    }
    reg_d1.h[0] = 0x3300;
next_1:
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 4;
    reg_a0 = (u8 *)(D_0025C020);
    reg_d2.w = 0xF;
    reg_d2.h[0] &= *(u16 *)(reg_a4 + 0xA);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w += 0x147C;
    sprite_draw_layer4_keep();
    reg_d1.h[0] -= 0x200;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    reg_d0.h[1] = *(u16 *)(reg_a4 + 0xE);
    reg_d7.w = 7;
loop_1:
    reg_d2.w = 0xF;
    reg_d2.h[0] &= reg_d0.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w += 0x147C;
    sprite_draw_layer4_keep();
    reg_d1.h[0] -= 0x200;
    reg_d0.w >>= 4;
    if (reg_d0.w == 0) goto next_2;
    t = reg_d7.h[0] - 1;
    reg_d7.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_2:
    reg_d7.h[0] -= 1;
    if (*(u16 *)(reg_a4 + 0x10) == 0) return;
    if (!(0 > (s16) reg_d7.h[0])) goto loop_1;
    reg_d2.w = 0xF;
    reg_d2.h[0] &= *(u16 *)(reg_a4 + 0x10);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w += 0x147C;
    sprite_draw_layer4_keep();
}

extern u16 D_0025C000[];

void func_0019A2B0(void) {
    reg_d1.h[0] = 0x5200;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[0] = 0xC00;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d2.w = 0x144C;
    reg_d7.h[0] = 0x5200;
    reg_tmp.w = reg_d7.w;
    reg_d7.h[0] = 0x440;
    reg_d7.h[1] = reg_tmp.h[0];
    if (*(u16 *)(reg_a4 + 0x2C) == 0) goto next_1;
    reg_d1.h[0] = 0x2240;
    reg_d2.w = 0x144D;
    reg_d7.h[0] = 0x2D40;
next_1:
    reg_d3.h[0] = 0x228;
    reg_d4.h[0] = 5;
    sprite_draw_layer3_keep();
    reg_d1.w = reg_d7.w;
    reg_d2.h[0] = *(u16 *)(reg_a4 + 0x38);
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)(D_0025C000);
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x218;
    reg_d4.h[0] = 4;
    sprite_draw_layer4_keep();
}

s32 sprite_draw_layer1();
s32 sprite_draw_layer3();
s32 sprite_draw_layer4();
void func_0019A410(void) {
    reg_d1.w = 0x2A001C00;
    reg_d1.w += 0xEE00EA00;
    reg_d2.w = 0x145A;
    reg_d3.h[0] = 0x12B0;
    reg_d4.h[0] = 4;
    sprite_draw_layer1();
    reg_d1.w = 0x38001C00;
    reg_d1.w += 0xC800E400;
    reg_d2.w = 0x1457;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 2;
    sprite_draw_layer3();
    reg_d1.w = 0x38001C00;
    reg_d1.w += 0xC800E400;
    reg_d2.w = 0x1486;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 3;
    sprite_draw_layer4();
    reg_d1.w = 0x62801C40;
    reg_d1.w += 0xFA00EA00;
    reg_d2.w = 0x1454;
    reg_d3.h[0] = 0x6B0;
    reg_d4.h[0] = 4;
    sprite_draw_layer4();
}

void func_0019A520(void) {
    reg_d1.w = 0x4E800C80;
    reg_d1.w += 0xF600F500;
    reg_d2.w = 0x1455;
    reg_d3.h[0] = 0xA58;
    reg_d4.h[0] = 3;
    sprite_draw_layer4();
    reg_d1.w = 0x42000D00;
    reg_d1.w += 0xFC00F500;
    reg_d2.w = 0x1456;
    reg_d3.h[0] = 0x458;
    reg_d4.h[0] = 3;
    sprite_draw_layer4();
}

void func_0019A5B0(void) {
    reg_d1.w = 0x4E802B80;
    reg_d1.w += 0xF600F500;
    reg_d2.w = 0x1455;
    reg_d3.h[0] = 0xA58;
    reg_d4.h[0] = 0x43;
    sprite_draw_layer4();
    reg_d1.w = 0x42002B00;
    reg_d1.w += 0xFC00F500;
    reg_d2.w = 0x1456;
    reg_d3.h[0] = 0x458;
    reg_d4.h[0] = 0x43;
    sprite_draw_layer4();
}


void func_0019A640(void) {
    if (*(u8 *)(reg_a4 + 0x21) == 1) {
        goto block_2;
    }
    if (!(reg_d0.w & 1)) {
        goto next_1;
    }
    *(u8 *)(reg_a4 + 0x21) = 1;
    *(u16 *)(reg_a4 + 0x2A) = 1;
    goto next_2;
next_1:
    if (!(reg_d0.w & 2)) {
        goto next_2;
    }
    *(u8 *)(reg_a4 + 0x21) = 1;
    *(u16 *)(reg_a4 + 0x2A) = 2;
next_2:
    if (!(reg_d0.w & 4)) {
        goto next_3;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 4;
    goto next_4;
next_3:
    if (!(reg_d0.w & 8)) {
        goto next_4;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 8;
next_4:
    if (*(u8 *)(reg_a4 + 0x21) == 2) {
        func_0019A870();
        return;
    }
    *(u8 *)(reg_a4 + 0x20) = 4;
    return;
block_2:
    *(u8 *)(reg_a4 + 0x20) -= 1;
    if (*(u8 *)(reg_a4 + 0x20) == 0) {
        func_0019A870();
        return;
    }
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0x2A);
    if (reg_d1.h[0] == 1) {
        goto next_5;
    }
    if (reg_d1.h[0] != 2) {
        goto next_7;
    }
next_5:
    if (!(reg_d0.w & 4)) {
        goto next_6;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 4;
    func_0019A870();
    return;
next_6:
    if (!(reg_d0.w & 8)) {
        goto next_4;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 8;
    func_0019A870();
    return;
next_7:
    if (reg_d1.h[0] == 4) {
        goto next_8;
    }
    if (reg_d1.h[0] == 8) {
        goto next_8;
    }
block_rts:
    return;
next_8:
    if (!(reg_d0.w & 1)) {
        goto next_9;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 1;
    func_0019A870();
    return;
next_9:
    if (!(reg_d0.w & 2)) {
        goto block_rts;
    }
    *(u8 *)(reg_a4 + 0x21) += 1;
    *(u16 *)(reg_a4 + 0x2A) |= 2;
    func_0019A870();
}

s32 sfx_cursor_move();
extern u16 D_0025C430[];

void func_0019A870(void) {
    u32 t;
    u32 t1;
    *(s8 *)(reg_a4 + 0x21) = 0;
    *(s8 *)(reg_a4 + 0x20) = 0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
    reg_a0 = (u8 *)(D_0025C3C0);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    t = reg_d0.h[0];
    reg_tmp.h[1] = (t != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)t & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)t + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)t + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x2A);
    *(u16 *)(reg_a4 + 0x2A) = 0U;
    reg_d0.h[0] -= 1;
    if (!(0 > (s16)(reg_d0.h[0])) && ((reg_d0.h[0] & 0xFFFF) < 0xA)) {
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        t1 = reg_d0.h[0];
        if (!(0 > (s16)(t1))) {
            *(u16 *)(reg_a4 + 0x18) = t1;
            reg_a0 = (u8 *)(D_0025C430);
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            *(u16 *)(reg_a4 + 6) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
            *(u16 *)(reg_a4 + 8) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            sfx_cursor_move();
        }
    }
}
