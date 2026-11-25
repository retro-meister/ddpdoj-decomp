#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"
#include "cd.h"
#include "replay.h"

void func_0018E060(void);
void func_0018E0B0(void);
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

s32 sound_rpc_call(s32, s32, s32);   /* extern */
extern s8 D_0028DF98;

void func_0018E020(void) {
    sound_rpc_call(0x530, 0, 0);
    if (D_0028DF98 != 0) {
        func_0018E060();
    }
    func_0018E0B0();
}

extern s32 D_0029CA10_as_s32_a[];
extern s32 D_0029CA14_as_s32_a[];

void func_0018E060(void) {
    if (sound_rpc_call(0x100, 0, 0) == 0) {
        sound_rpc_call(0x150, 0, 0);
        D_0028DF98 = 0;
        D_0029CA10_as_s32_a[0] = 0;
        D_0029CA14_as_s32_a[0] = 0;
    }
}

extern s32 sound_rpc_call(s32, s32, s32);
extern void func_0018CCA0(s32);
extern u8 D_00277FB0[];
extern u8 D_00277FC8[];
extern s8 D_0028DF94;
extern u8 D_0029CA10[];
extern u8 D_0029CA18[];

void func_0018E0B0(void) {
    s32 i;
    s32 off;
    u8 *p;
    s32 *f;
    s32 *c;
    s32 *tg;
    s32 t;
    s32 v;
    s32 hi;

    off = 0;
    i = 0;
    do {
        p = D_0029CA10 + off;
        f = (s32 *)(p + 8);
        if (*f != 0) {
            *(s32 *)(p + 0x20) -= 1;
            if (*(s32 *)(p + 0x20) <= 0) {
                *(s32 *)(p + 0xC) = *(s32 *)(p + 0x14);
                printf((const char *)D_00277FB0, *(s32 *)(p + 0xC));
                t = *f;
                if (t == 3) {
                    D_0028DF94 = 0;
                }
                if (t == 2) {
                    func_0018CCA0(i);
                    *(s32 *)(D_0029CA18 + i * 0x28) = 0;
                    printf((const char *)D_00277FC8);
                    return;
                }
                if (t == 4) {
                    sound_rpc_call(i | 0x60, 0, 0);
                    *(s32 *)(D_0029CA18 + i * 0x28) = 0;
                    return;
                }
                *f = 0;
            }
            c = (s32 *)(p + 0xC);
            tg = (s32 *)(p + 0x14);
            if (*c != *tg) {
                if (*c < *tg) {
                    *(s32 *)(p + 0x18) += *(s32 *)(p + 0x1C);
                    *c = *(s32 *)(p + 0x18) / 100;
                    if (*tg < *c) {
                        *c = *tg;
                    }
                } else {
                    *(s32 *)(p + 0x18) -= *(s32 *)(p + 0x1C);
                    *c = *(s32 *)(p + 0x18) / 100;
                    if (*c < *tg) {
                        *c = *tg;
                    }
                }
            }
            v = *c;
            if (v != 0) {
                v = v * 0x7FFF / 100;
            }
            hi = v << 16;
            hi |= v;
            sound_rpc_call(i | 0x80, hi, 0);
        }
        i += 1;
        off += 0x28;
    } while (i < 2);
}

extern const char *D_0025BC50[];
extern const char *D_0025BCC0[];
extern const char *D_0025BCF0[];
extern const char *D_0025BD30[];
extern ReplayHeader D_0068DF10[];

void func_0018E300(void) {
    s32 i;

    for (i = 0; i < 0x1A; i++) {
        cd_search_file(D_0025BC50[i]);
        g_bgm_files[i].size = g_cd_file.size;
        g_bgm_files[i].lba = g_cd_file.lsn;
    }
}

void func_0018E390(void) {
    s32 i;

    for (i = 0; i < 0xA; i++) {
        cd_search_file(D_0025BCC0[i]);
        g_stage_bg_files[i].size = g_cd_file.size;
        g_stage_bg_files[i].lba = g_cd_file.lsn;
    }
}

void func_0018E420(void) {
    s32 i;

    for (i = 0; i < MAIN_OR_DEATH_LABEL(0xE, 0x10); i++) {
        cd_search_file(D_0025BCF0[i]);
        g_data_files[i].size = g_cd_file.size;
        g_data_files[i].lba = g_cd_file.lsn;
    }
}

void func_0018E4B0(void) {
    s32 i;
    void *buf;
    ReplayHeader *dst;

    buf = memalign(0x40, 0x800);
    for (i = 0; i < 10; i++) {
        cd_search_file(D_0025BD30[i]);
        g_replay_files[i].size = g_cd_file.size;
        g_replay_files[i].lba = g_cd_file.lsn;
        cd_read_sync(buf, 0x800, g_cd_file.lsn);
        dst = &D_0068DF10[i];
        memcpy(dst, buf, 0x42);
        dst->unk00 = 1;
    }
    free(buf);
}


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
extern void func_0018D1D0(void);
extern void func_0018D210(void);
extern void func_0018D250(void);
extern void func_0018D290(void);
extern void func_0018D2D0(void);
extern void func_0018D310(void);

extern u16 D_0024D0B8[];
extern u16 D_0024D0BA[];
extern u16 D_0024D0C6[];
extern u16 D_0024D0C8[];
extern u16 D_0024D0D4[];
extern u16 D_0024D0D6[];
extern u16 D_0024D238[];
extern u16 D_0024D23A[];
extern u16 D_0024D246[];
extern u16 D_0024D248[];
extern u16 D_0024D258[];
extern u16 D_0024D25A[];
extern u16 D_0024D266[];
extern u16 D_0024D268[];
extern u16 D_0024D278[];
extern u16 D_0024D27A[];
extern u16 D_0024D286[];
extern u16 D_0024D288[];
extern u16 D_0024D298[];
extern u16 D_0024D29A[];
extern u16 D_0024D2A6[];
extern u16 D_0024D2A8[];
extern u16 D_0024D2B8[];
extern u16 D_0024D2BA[];
extern u16 D_0024D2C6[];
extern u16 D_0024D2C8[];
extern u16 D_0024E2E6[];
extern u16 D_0024E2E8[];
extern u16 D_0024E2F0[];
extern u16 D_0024E2F2[];
extern u16 D_0024E2FA[];
extern u16 D_0024E2FC[];
extern u16 D_0024E304[];
extern u16 D_0024E306[];
extern u16 D_0024E30E[];
extern u16 D_0024E310[];
extern u16 D_0024E318[];
extern u16 D_0024E31A[];
extern u16 D_0024E322[];
extern u16 D_0024E324[];
extern u16 D_0024E32C[];
extern u16 D_0024E32E[];
extern u16 D_0024E336[];
extern u16 D_0024E338[];
extern u16 D_0024E340[];
extern u16 D_0024E342[];
extern u16 D_0024E34A[];
extern u16 D_0024E34C[];
extern u16 D_0024E354[];
extern u16 D_0024E356[];
extern u16 D_0024E35E[];
extern u16 D_0024E360[];
extern u16 D_0024E368[];
extern u16 D_0024E36A[];
extern u16 D_0024E372[];
extern u16 D_0024E374[];
extern u16 D_0024E37C[];
extern u16 D_0024E37E[];
extern u16 D_0024E386[];
extern u16 D_0024E388[];
extern u16 D_0024E390[];
extern u16 D_0024E392[];
extern u16 D_0024E39A[];
extern u16 D_0024E39C[];
extern u16 D_0024E3A4[];
extern u16 D_0024E3A6[];
extern u16 D_0024E3AE[];
extern u16 D_0024E3B0[];
extern u16 D_0024E3B8[];
extern u16 D_0024E3BA[];
extern u16 D_0024E3C2[];
extern u16 D_0024E3C4[];
extern u16 D_0024E3CC[];
extern u16 D_0024E3CE[];
extern u16 D_0024E3D6[];
extern u16 D_0024E3D8[];
extern u16 D_0024E3E0[];
extern u16 D_0024E3E2[];
extern u16 D_0024E3EA[];
extern u16 D_0024E3EC[];
extern u16 D_0024E3F4[];
extern u16 D_0024E3F6[];
extern u16 D_0024E3FE[];
extern u16 D_0024E400[];
extern u16 D_0024E408[];
extern u16 D_0024E40A[];
extern u16 D_0024E412[];
extern u16 D_0024E414[];
extern u16 D_0024E41C[];
extern u16 D_0024E41E[];
extern u16 D_0024E426[];
extern u16 D_0024E428[];
extern u16 D_0024E430[];
extern u16 D_0024E432[];
extern u16 D_0024E740_as_u16_a[];
extern u16 D_0024E742[];
extern u16 D_0024E744[];
extern u16 D_0024E746[];
extern u16 D_0024E748[];
extern u16 D_0024E74A[];
extern u16 D_0024E74C[];
extern u16 D_0024E74E[];
extern u16 D_0024E750[];
extern u16 D_0024E752[];
extern u16 D_0024E754[];
extern u16 D_0024E756[];
extern u16 D_0024E758[];
extern u16 D_0024E75A[];
extern u16 D_0024E75C[];
extern u16 D_0024E75E[];
extern u16 D_0024E760[];
extern u16 D_0024E762[];
extern u16 D_0024E764[];
extern u16 D_0024E766[];
extern u16 D_0024E768[];
extern u16 D_0024E76A[];
extern u16 D_0024E76C[];
extern u16 D_0024E76E[];
extern u16 D_0024E770[];
extern u16 D_0024E772[];
extern u16 D_0024E774[];
extern u16 D_0024E776[];
extern u16 D_0024E778[];
extern u16 D_0024E77A[];
extern u16 D_0024E77C[];
extern u16 D_0024E77E[];
extern u16 D_0024E780[];
extern u16 D_0024E782[];
extern u16 D_0024E784[];
extern u16 D_0024E786[];
extern u16 D_0024E788[];
extern u16 D_0024E78A[];
extern u16 D_0024E78C[];
extern u16 D_0024E78E[];
extern u16 D_0024E790[];
extern u16 D_0024E792[];
extern u16 D_0024E794[];
extern u16 D_0024E796[];
extern u16 D_0024E798[];
extern u16 D_0024E79A[];
extern u16 D_0024E79C[];
extern u16 D_0024E79E[];
extern u16 D_0024E7A0[];
extern u16 D_0024E7A2[];
extern u16 D_0024E7A4[];
extern u16 D_0024E7A6[];
extern u16 D_0024E7A8[];
extern u16 D_0024E7AA[];
extern u16 D_0024E7AC[];
extern u16 D_0024E7AE[];
extern u16 D_0024E7B0[];
extern u16 D_0024E7B2[];
extern u16 D_0024E7B4[];
extern u16 D_0024E7B6[];
extern u16 D_0024E7B8[];
extern u16 D_0024E7BA[];
extern u16 D_0024E7BC[];
extern u16 D_0024E7BE[];
extern u16 D_0024E7C0[];
extern u16 D_0024E7C2[];
extern u16 D_0024E7C4[];
extern u16 D_0024E7C6[];
extern u16 D_0024E7C8[];
extern u16 D_0024E7CA[];
extern u16 D_0024E7CC[];
extern u16 D_0024E7CE[];
extern u16 D_0024E7D0[];
extern u16 D_0024E7D2[];
extern u16 D_0024E7D4[];
extern u16 D_0024E7D6[];
extern u16 D_0024E7D8[];
extern u16 D_0024E7DA[];
extern u16 D_0024E7DC[];
extern u16 D_0024E7DE[];
extern u16 D_0024E7E0[];
extern u16 D_0024E7E2[];
extern u16 D_0024E7E4[];
extern u16 D_0024E7E6[];
extern u16 D_0024E7E8[];
extern u16 D_0024E7EA[];
extern u16 D_0024E7EC[];
extern u16 D_0024E7EE[];
extern u16 D_0024E7F0[];
extern u16 D_0024E7F2[];
extern u16 D_0024E7F4[];
extern u16 D_0024E7F6[];
extern u16 D_0024E7F8[];
extern u16 D_0024E7FA[];
extern u16 D_0024E7FC[];
extern u16 D_0024E7FE[];
extern u16 D_0024E800[];
extern u16 D_0024E802[];
extern u16 D_0024E804[];
extern u16 D_0024E806[];
extern u16 D_0024E808[];
extern u16 D_0024E80A[];
extern u16 D_0024E80C[];
extern u16 D_0024E80E[];
extern u16 D_0024E810[];
extern u16 D_0024E812[];
extern u16 D_0024E814[];
extern u16 D_0024E816[];
extern u16 D_0024E818[];
extern u16 D_0024E81A[];
extern u16 D_0024E81C[];
extern u16 D_0024E81E[];
extern u16 D_0024E820[];
extern u16 D_0024E822[];
extern u16 D_0024E824[];
extern u16 D_0024E826[];
extern u16 D_0024E828[];
extern u16 D_0024E82A[];
extern u16 D_0024E82C[];
extern u16 D_0024E82E[];
extern u16 D_0024E830[];
extern u16 D_0024E832[];
extern u16 D_0024E834[];
extern u16 D_0024E836[];
extern u16 D_0024E838[];
extern u16 D_0024E83A[];
extern u16 D_0024E83C[];
extern u16 D_0024E83E[];
extern u16 D_0024E840[];
extern u16 D_0024E842[];
extern u16 D_0024E844[];
extern u16 D_0024E846[];
extern u16 D_0024E848[];
extern u16 D_0024E84A[];
extern u16 D_0024E84C[];
extern u16 D_0024E84E[];
extern u16 D_0024E850[];
extern u16 D_0024E852[];
extern u16 D_0024E854[];
extern u16 D_0024E856[];
extern u16 D_0024E858[];
extern u16 D_0024E85A[];
extern u16 D_0024E85C[];
extern u16 D_0024E85E[];
extern u16 D_0024EB30_as_u16_a[];
extern u16 D_0024EB32[];
extern u16 D_0024EB34[];
extern u16 D_0024EB36[];
extern u16 D_0024EB38[];
extern u16 D_0024EB3A[];
extern u16 D_0024EB3C[];
extern u16 D_0024EB3E[];
extern u16 D_0024EB40[];
extern u16 D_0024EB42[];
extern u16 D_0024EB44[];
extern u16 D_0024EB46[];
extern u16 D_0024EB48[];
extern u16 D_0024EB4A[];
extern u16 D_0024EB4C[];
extern u16 D_0024EB4E[];
extern u16 D_0024EB50[];
extern u16 D_0024EB52[];
extern u16 D_0024EB54[];
extern u16 D_0024EB56[];
extern u16 D_0024EB58[];
extern u16 D_0024EB5A[];
extern u16 D_0024EB5C[];
extern u16 D_0024EB5E[];
extern u16 D_0024EB60[];
extern u16 D_0024EB62[];
extern u16 D_0024EB64[];
extern u16 D_0024EB66[];
extern u16 D_0024EB68[];
extern u16 D_0024EB6A[];
extern u16 D_0024EB6C[];
extern u16 D_0024EB6E[];
extern u16 D_0024EB70[];
extern u16 D_0024EB72[];
extern u16 D_0024EB74[];
extern u16 D_0024EB76[];
extern u16 D_0024EB78[];
extern u16 D_0024EB7A[];
extern u16 D_0024EB7C[];
extern u16 D_0024EB7E[];
extern u16 D_0024EB80[];
extern u16 D_0024EB82[];
extern u16 D_0024EB84[];
extern u16 D_0024EB86[];
extern u16 D_0024EB88[];
extern u16 D_0024EB8A[];
extern u16 D_0024EB8C[];
extern u16 D_0024EB8E[];
extern u16 D_0024EB90[];
extern u16 D_0024EB92[];
extern u16 D_0024EB94[];
extern u16 D_0024EB96[];
extern u16 D_0024EB98[];
extern u16 D_0024EB9A[];
extern u16 D_0024EB9C[];
extern u16 D_0024EB9E[];
extern u16 D_0024EBA0[];
extern u16 D_0024EBA2[];
extern u16 D_0024EBA4[];
extern u16 D_0024EBA6[];
extern u16 D_0024EBA8[];
extern u16 D_0024EBAA[];
extern u16 D_0024EBAC[];
extern u16 D_0024EBAE[];
extern u16 D_0024EBB0[];
extern u16 D_0024EBB2[];
extern u16 D_0024EBB4[];
extern u16 D_0024EBB6[];
extern u16 D_0024EBB8[];
extern u16 D_0024EBBA[];
extern u16 D_0024EBBC[];
extern u16 D_0024EBBE[];
extern u16 D_0024EBC0_as_u16_a[];
extern u16 D_0024EBC2[];
extern u16 D_0024EBC4[];
extern u16 D_0024EBC6[];
extern u16 D_0024EBC8[];
extern u16 D_0024EBCA[];
extern u16 D_0024EBCC[];
extern u16 D_0024EBCE[];
extern u16 D_0024EBD0[];
extern u16 D_0024EBD2[];
extern u16 D_0024EBD4[];
extern u16 D_0024EBD6[];
extern u16 D_0024EBD8[];
extern u16 D_0024EBDA[];
extern u16 D_0024EBDC[];
extern u16 D_0024EBDE[];
extern u16 D_0024EBE0[];
extern u16 D_0024EBE2[];
extern u16 D_0024EDB0_as_u16_a[];
extern u16 D_0024EDB2[];
extern u16 D_0024EDB4[];
extern u16 D_0024EDB6[];
extern u16 D_0024EDB8[];
extern u16 D_0024EDBA[];
extern u16 D_0024EDBC[];
extern u16 D_0024EDBE[];
extern u16 D_0024EDC0[];
extern u16 D_0024EDC2[];
extern u16 D_0024EDC4[];
extern u16 D_0024EDC6[];
extern u16 D_0024EDC8[];
extern u16 D_0024EDCA[];
extern u16 D_0024EDCC[];
extern u16 D_0024EDCE[];
extern u16 D_0024EDD0[];
extern u16 D_0024EDD2[];
extern u16 D_0024F0B0[];
extern u16 D_0024F0B2[];
extern u16 D_0024F0B8[];
extern u16 D_0024F0BA[];
extern u16 D_0024F0C0[];
extern u16 D_0024F0C2[];
extern u16 D_0024F0C8[];
extern u16 D_0024F0CA[];
extern u16 D_0024F0D0[];
extern u16 D_0024F0D2[];
extern u16 D_0024F0D8[];
extern u16 D_0024F0DA[];
extern u16 D_0024F0E0[];
extern u16 D_0024F0E2[];
extern u16 D_0024F0E8[];
extern u16 D_0024F0EA[];
extern u16 D_0024F570[];
extern u16 D_0024F572[];
extern u16 D_0024F574[];
extern u16 D_0024F576[];
extern u16 D_0024F578[];
extern u16 D_0024F57A[];
extern u16 D_0024F57C[];
extern u16 D_0024F57E[];
extern u16 D_0024F580[];
extern u16 D_0024F582[];
extern u16 D_0024F584[];
extern u16 D_0024F586[];
extern u16 D_0024F588[];
extern u16 D_0024F58A[];
extern u16 D_0024F58C[];
extern u16 D_0024F58E[];
extern u16 D_0024F590[];
extern u16 D_0024F592[];
extern u16 D_0024F594[];
extern u16 D_0024F596[];
extern u16 D_0024F598[];
extern u16 D_0024F59A[];
extern u16 D_0024F59C[];
extern u16 D_0024F59E[];
extern u16 D_0024F5A0[];
extern u16 D_0024F5A2[];
extern u16 D_0024F5A4[];
extern u16 D_0024F5A6[];
extern u16 D_0024F5A8[];
extern u16 D_0024F5AA[];
extern u16 D_0024F5AC[];
extern u16 D_0024F5AE[];
extern u16 D_0024F5B0[];
extern u16 D_0024F5B2[];
extern u16 D_0024F5B4[];
extern u16 D_0024F5B6[];
extern u16 D_0024F5B8[];
extern u16 D_0024F5BA[];
extern u16 D_0024F5BC[];
extern u16 D_0024F5BE[];
extern u16 D_0024F5C0[];
extern u16 D_0024F5C2[];
extern u16 D_0024F5C4[];
extern u16 D_0024F5C6[];
extern u16 D_0024F5C8[];
extern u16 D_0024F5CA[];
extern u16 D_0024F5CC[];
extern u16 D_0024F5CE[];
extern u16 D_0024F5D0[];
extern u16 D_0024F5D2[];
extern u16 D_0024F5D4[];
extern u16 D_0024F5D6[];
extern u16 D_0024F5D8[];
extern u16 D_0024F5DA[];
extern u16 D_0024F5DC[];
extern u16 D_0024F5DE[];
extern u16 D_0024F5E0[];
extern u16 D_0024F5E2[];
extern u16 D_0024F5E4[];
extern u16 D_0024F5E6[];
extern u16 D_0024F5E8[];
extern u16 D_0024F5EA[];
extern u16 D_0024F5EC[];
extern u16 D_0024F5EE[];
extern u16 D_0024F5F0[];
extern u16 D_0024F5F2[];
extern u16 D_0024F5F4[];
extern u16 D_0024F5F6[];
extern u16 D_0024F5F8[];
extern u16 D_0024F5FA[];
extern u16 D_0024F5FC[];
extern u16 D_0024F5FE[];
extern u16 D_0024F600[];
extern u16 D_0024F602[];
extern u16 D_0024F604[];
extern u16 D_0024F606[];
extern u16 D_0024F608[];
extern u16 D_0024F60A[];
extern u16 D_0024F60C[];
extern u16 D_0024F60E[];
extern u16 D_0024F610[];
extern u16 D_0024F612[];
extern u16 D_0024F614[];
extern u16 D_0024F616[];
extern u16 D_0024F618[];
extern u16 D_0024F61A[];
extern u16 D_0024F61C[];
extern u16 D_0024F61E[];
extern u16 D_0024F620[];
extern u16 D_0024F622[];
extern u16 D_0024F624[];
extern u16 D_0024F626[];
extern u16 D_0024F628[];
extern u16 D_0024F62A[];
extern u16 D_0024F62C[];
extern u16 D_0024F62E[];
extern u16 D_0024F630[];
extern u16 D_0024F632[];
extern u16 D_0024F634[];
extern u16 D_0024F636[];
extern u16 D_0024F638[];
extern u16 D_0024F63A[];
extern u16 D_0024F63C[];
extern u16 D_0024F63E[];
extern u16 D_0024F640[];
extern u16 D_0024F642[];
extern u16 D_0024F644[];
extern u16 D_0024F646[];
extern u16 D_0024F648[];
extern u16 D_0024F64A[];
extern u16 D_0024F64C[];
extern u16 D_0024F64E[];
extern u16 D_0024F650[];
extern u16 D_0024F652[];
extern u16 D_0024F654[];
extern u16 D_0024F656[];
extern u16 D_0024F658[];
extern u16 D_0024F65A[];
extern u16 D_0024F65C[];
extern u16 D_0024F65E[];
extern u16 D_0024F660[];
extern u16 D_0024F662[];
extern u16 D_0024F664[];
extern u16 D_0024F666[];
extern u16 D_0024F668[];
extern u16 D_0024F66A[];
extern u16 D_0024F66C[];
extern u16 D_0024F66E[];
extern u16 D_0024F670[];
extern u16 D_0024F672[];
extern u16 D_0024F674[];
extern u16 D_0024F676[];
extern u16 D_0024F678[];
extern u16 D_0024F67A[];
extern u16 D_0024F67C[];
extern u16 D_0024F67E[];
extern u16 D_0024F680[];
extern u16 D_0024F682[];
extern u16 D_0024F684[];
extern u16 D_0024F686[];
extern u16 D_0024F688[];
extern u16 D_0024F68A[];
extern u16 D_0024F68C[];
extern u16 D_0024F68E[];
extern u16 D_0024F690[];
extern u16 D_0024F692[];
extern u16 D_0024F694[];
extern u16 D_0024F696[];
extern u16 D_0024F698[];
extern u16 D_0024F69A[];
extern u16 D_0024F69C[];
extern u16 D_0024F69E[];
extern u16 D_0024F6A0[];
extern u16 D_0024F6A2[];
extern u16 D_0024F6A4[];
extern u16 D_0024F6A6[];
extern u16 D_0024F6A8[];
extern u16 D_0024F6AA[];
extern u16 D_0024F6AC[];
extern u16 D_0024F6AE[];
extern u16 D_0024F6B0[];
extern u16 D_0024F6B2[];
extern u16 D_0024F6B4[];
extern u16 D_0024F6B6[];
extern u16 D_0024F6B8[];
extern u16 D_0024F6BA[];
extern u16 D_0024F6BC[];
extern u16 D_0024F6BE[];
extern u16 D_0024F6C0[];
extern u16 D_0024F6C2[];
extern u16 D_0024F6C4[];
extern u16 D_0024F6C6[];
extern u16 D_0024F6C8[];
extern u16 D_0024F6CA[];
extern u16 D_0024F6CC[];
extern u16 D_0024F6CE[];
extern u16 D_0024F6D0[];
extern u16 D_0024F6D2[];
extern u16 D_0024F6D4[];
extern u16 D_0024F6D6[];
extern u16 D_0024F6D8[];
extern u16 D_0024F6DA[];
extern u16 D_0024F6DC[];
extern u16 D_0024F6DE[];
extern u16 D_0024F6E0[];
extern u16 D_0024F6E2[];
extern u16 D_0024F6E4[];
extern u16 D_0024F6E6[];
extern u16 D_0024F6E8[];
extern u16 D_0024F6EA[];
extern u16 D_0024F6EC[];
extern u16 D_0024F6EE[];
extern u16 D_0024F6F0[];
extern u16 D_0024F6F2[];
extern u16 D_0024F6F4[];
extern u16 D_0024F6F6[];
extern u16 D_0024F6F8[];
extern u16 D_0024F6FA[];
extern u16 D_0024F6FC[];
extern u16 D_0024F6FE[];
extern u16 D_0024F700[];
extern u16 D_0024F702[];
extern u16 D_0024F704[];
extern u16 D_0024F706[];
extern u16 D_0024F708[];
extern u16 D_0024F70A[];
extern u16 D_0024F70C[];
extern u16 D_0024F70E[];
extern u16 D_0024F710[];
extern u16 D_0024F712[];
extern u16 D_0024F714[];
extern u16 D_0024F716[];
extern u16 D_0024F718[];
extern u16 D_0024F71A[];
extern u16 D_0024F71C[];
extern u16 D_0024F71E[];
extern u16 D_0024F720[];
extern u16 D_0024F722[];
extern u16 D_0024F724[];
extern u16 D_0024F726[];
extern u16 D_0024F728[];
extern u16 D_0024F72A[];
extern u16 D_0024F72C[];
extern u16 D_0024F72E[];
extern u16 D_0024F730[];
extern u16 D_0024F732[];
extern u16 D_0024F734[];
extern u16 D_0024F736[];
extern u16 D_0024F738[];
extern u16 D_0024F73A[];
extern u16 D_0024F73C[];
extern u16 D_0024F73E[];
extern u16 D_0024F740[];
extern u16 D_0024F742[];
extern u16 D_0024F744[];
extern u16 D_0024F746[];
extern u16 D_0024F748[];
extern u16 D_0024F74A[];
extern u16 D_0024F74C[];
extern u16 D_0024F74E[];
extern u16 D_0024F750[];
extern u16 D_0024F752[];
extern u16 D_0024F754[];
extern u16 D_0024F756[];
extern u16 D_0024F758[];
extern u16 D_0024F75A[];
extern u16 D_0024F75C[];
extern u16 D_0024F75E[];
extern u16 D_0024F760[];
extern u16 D_0024F762[];
extern u16 D_0024F764[];
extern u16 D_0024F766[];
extern u16 D_0024F768[];
extern u16 D_0024F76A[];
extern u16 D_0024F76C[];
extern u16 D_0024F76E[];
extern u16 D_0024F770[];
extern u16 D_0024F772[];
extern u16 D_0024F774[];
extern u16 D_0024F776[];
extern u16 D_0024F778[];
extern u16 D_0024F77A[];
extern u16 D_0024F77C[];
extern u16 D_0024F77E[];
extern u16 D_0024F780[];
extern u16 D_0024F782[];
extern u16 D_0024F784[];
extern u16 D_0024F786[];
extern u16 D_0024F788[];
extern u16 D_0024F78A[];
extern u16 D_0024F78C[];
extern u16 D_0024F78E[];
extern u16 D_00250A86[];
extern u16 D_00250A88[];
extern u16 D_00250B16[];
extern u16 D_00250B18[];
extern u16 D_00250BA6[];
extern u16 D_00250BA8[];
extern u16 D_00250C36[];
extern u16 D_00250C38[];
extern u16 D_00250CC6[];
extern u16 D_00250CC8[];
extern u16 D_00250CD0_as_u16_a[];
extern u16 D_00250CD2[];
extern u16 D_00250CD4[];
extern u16 D_00250CD6[];
extern u16 D_00250CD8[];
extern u16 D_00250CDA[];
extern u16 D_00250CDC[];
extern u16 D_00250CDE[];
extern u16 D_00250D40[];
extern u16 D_00250D42[];
extern u16 D_00250D60[];
extern u16 D_00250D62[];
extern u16 D_00250D80[];
extern u16 D_00250D82[];
extern u16 D_00250E10[];
extern u16 D_00250E12[];
extern u16 D_00250F50[];
extern u16 D_00250F52[];
extern u16 D_00250F70[];
extern u16 D_00250F72[];
extern u16 D_00250F90[];
extern u16 D_00250F92[];
extern u16 D_00250FB0[];
extern u16 D_00250FB2[];
extern u16 D_00250FD0[];
extern u16 D_00250FD2[];
extern u16 D_00250FF0[];
extern u16 D_00250FF2[];
extern u16 D_00251010[];
extern u16 D_00251012[];
extern u16 D_00251030[];
extern u16 D_00251032[];
extern u16 D_00251050[];
extern u16 D_00251052[];
extern u16 D_00251070[];
extern u16 D_00251072[];
extern u16 D_00251090[];
extern u16 D_00251092[];
extern u16 D_002510B0[];
extern u16 D_002510B2[];
extern u16 D_002510D0[];
extern u16 D_002510D2[];
extern u16 D_002510F0[];
extern u16 D_002510F2[];
extern u16 D_00251110[];
extern u16 D_00251112[];
extern u16 D_00251690[];
extern u16 D_00251692[];
extern u16 D_00251694[];
extern u16 D_00251696[];
extern u16 D_00251698[];
extern u16 D_0025169A[];
extern u16 D_002516B0[];
extern u16 D_002516B2[];
extern u16 D_002516B4[];
extern u16 D_002516B6[];
extern u16 D_002516B8[];
extern u16 D_002516BA[];
extern u16 D_002516D0[];
extern u16 D_002516D2[];
extern u16 D_002516D4[];
extern u16 D_002516D6[];
extern u16 D_002516D8[];
extern u16 D_002516DA[];
extern u16 D_002516F0[];
extern u16 D_002516F2[];
extern u16 D_002516F4[];
extern u16 D_002516F6[];
extern u16 D_002516F8[];
extern u16 D_002516FA[];
extern u16 D_00251A80_as_u16_a[];
extern u16 D_00251A84[];
extern u16 D_00251A86[];
extern u16 D_00251A90_as_u16_a[];
extern u16 D_00251A94[];
extern u16 D_00251A96[];
extern u16 D_00251AB0_as_u16_a[];
extern u16 D_00251AB4[];
extern u16 D_00251AB6[];
extern u16 D_00251AC0_as_u16_a[];
extern u16 D_00251AC4[];
extern u16 D_00251AC6[];
extern u16 D_00251AE4[];
extern u16 D_00251AE8[];
extern u16 D_00251AEC[];
extern u16 D_00251AF0[];
extern u16 D_00251B04[];
extern u16 D_00251B08[];
extern u16 D_00251B0C[];
extern u16 D_00251B10[];
extern u16 D_00251CC0[];
extern u16 D_00251CC4[];
extern u16 D_00251CC8[];
extern u16 D_00251CCC[];
extern u16 D_00251CD0[];
extern u16 D_00251CD4[];
extern u16 D_00252010[];
extern u16 D_00252014[];
extern u16 D_00252018[];
extern u16 D_00252024[];
extern u16 D_00252028[];
extern u16 D_00252034[];
extern u16 D_00252038[];
extern u16 D_00252044[];
extern u16 D_00252048[];
extern u16 D_00252050[];
extern u16 D_00252054[];
extern u16 D_00252058[];
extern u16 D_00252064[];
extern u16 D_00252068[];
extern u16 D_00252074[];
extern u16 D_00252078[];
extern u16 D_00252084[];
extern u16 D_00252088[];
extern u16 D_002520C6[];
extern u16 D_002520D6[];
extern u16 D_002520E6[];
extern u16 D_00252156[];
extern u16 D_00252166[];
extern u16 D_00252176[];
extern u16 D_00252210[];
extern u16 D_00252214[];
extern u16 D_00252218[];
extern u16 D_00252220[];
extern u16 D_00252224[];
extern u16 D_00252228[];
extern u16 D_00252236[];
extern u16 D_00252246[];
extern u16 D_00252256[];
extern u16 D_00252260[];
extern u16 D_0025226E[];
extern u16 D_0025227E[];
extern u16 D_00252296[];
extern u16 D_002522A0[];
extern u16 D_002526D0_as_u16_a[];
extern u16 D_002526D2[];
extern u16 D_002526D4[];
extern u16 D_002526D8[];
extern u16 D_002526DC[];
extern u16 D_002526E0[];
extern u16 D_002526E4[];
extern u16 D_002526E8[];
extern u16 D_002526F0_as_u16_a[];
extern u16 D_002526F2[];
extern u16 D_002526F4[];
extern u16 D_002526F8[];
extern u16 D_00252700_as_u16_a[];
extern u16 D_00252702[];
extern u16 D_00252704[];
extern u16 D_00252708[];
extern u16 D_0025270C[];
extern u16 D_00252710[];
extern u16 D_00252720_as_u16_a[];
extern u16 D_00252722[];
extern u16 D_00252724[];
extern u16 D_00252728[];
extern u16 D_0025272C[];
extern u16 D_00252730[];
extern u16 D_00252740[];
extern u16 D_00252744[];
extern u16 D_00252748[];
extern u16 D_0025274C[];
extern u16 D_00252750[];
extern u16 D_00252766[];
extern u16 D_0025276C[];
extern u16 D_00252772[];
extern u16 D_00252778[];
extern u16 D_0025277E[];
extern u16 D_00252784[];
extern u16 D_0025278A[];
extern u16 D_00252790[];
extern u16 D_00252796[];
extern u16 D_0025279C[];
extern u16 D_002527A2[];
extern u16 D_002527A8[];
extern u16 D_002527AE[];
extern u16 D_002527B4[];
extern u16 D_002527BA[];
extern u16 D_002527C0[];
extern u16 D_002527C6[];
extern u16 D_002527CC[];
extern u16 D_002527D2[];
extern u16 D_002527D8[];
extern u16 D_002527DE[];
extern u16 D_002527F0[];
extern u16 D_00252804[];
extern u16 D_00252A26[];
extern u16 D_00252A2C[];
extern u16 D_00252A32[];
extern u16 D_00252A38[];
extern u16 D_00252A3E[];
extern u16 D_00252A44[];
extern u16 D_00252A4A[];
extern u16 D_00252A50[];
extern u16 D_00252A56[];
extern u16 D_00252A5C[];
extern u16 D_00252A62[];
extern u16 D_00252A68[];
extern u16 D_00252A6E[];
extern u16 D_00252A74[];
extern u16 D_00252A7A[];
extern u16 D_00252A80[];
extern u16 D_00252A86[];
extern u16 D_00252A8C[];
extern u16 D_00252A92[];
extern u16 D_00252A98[];
extern u16 D_00252A9E[];
extern u16 D_00252AA4[];
extern u16 D_00252AAA[];
extern u16 D_00252AB0[];
extern u16 D_00252AB6[];
extern u16 D_00252AC4[];
extern u16 D_00252AD0[];
extern u16 D_00252AE4[];
extern u16 D_00252BD6[];
extern u16 D_00252BDC[];
extern u16 D_00252BE2[];
extern u16 D_00252BE8[];
extern u16 D_00252BEE[];
extern u16 D_00252BF4[];
extern u16 D_00252BFA[];
extern u16 D_00252C00[];
extern u16 D_00252C06[];
extern u16 D_00252C0C[];
extern u16 D_00252C12[];
extern u16 D_00252C18[];
extern u16 D_00252C1E[];
extern u16 D_00252C24[];
extern u16 D_00252C2A[];
extern u16 D_00252C30[];
extern u16 D_00252C36[];
extern u16 D_00252C3C[];
extern u16 D_00252C42[];
extern u16 D_00252C48[];
extern u16 D_00252C4E[];
extern u16 D_00252C54[];
extern u16 D_00252C5A[];
extern u16 D_00252C74[];
extern u16 D_00252C80[];
extern u16 D_00252C94[];
extern u16 D_00252DB6[];
extern u16 D_00252DBC[];
extern u16 D_00252DC2[];
extern u16 D_00252DC8[];
extern u16 D_00252DCE[];
extern u16 D_00252DD4[];
extern u16 D_00252DDA[];
extern u16 D_00252DE0[];
extern u16 D_00252DE6[];
extern u16 D_00252DEC[];
extern u16 D_00252DF2[];
extern u16 D_00252DF8[];
extern u16 D_00252DFE[];
extern u16 D_00252E04[];
extern u16 D_00252E0A[];
extern u16 D_00252E10[];
extern u16 D_00252E16[];
extern u16 D_00252E1C[];
extern u16 D_00252E22[];
extern u16 D_00252E28[];
extern u16 D_00252E2E[];
extern u16 D_00252E44[];
extern u16 D_00252E50[];
extern u16 D_00252E64[];
extern u16 D_00252F86[];
extern u16 D_00252F8C[];
extern u16 D_00252F92[];
extern u16 D_00252F98[];
extern u16 D_00252F9E[];
extern u16 D_00252FA4[];
extern u16 D_00252FAA[];
extern u16 D_00252FB0[];
extern u16 D_00252FB6[];
extern u16 D_00252FBC[];
extern u16 D_00252FC2[];
extern u16 D_00252FC8[];
extern u16 D_00252FCE[];
extern u16 D_00252FD4[];
extern u16 D_00252FDA[];
extern u16 D_00252FE0[];
extern u16 D_00252FE6[];
extern u16 D_00252FEC[];
extern u16 D_00252FF2[];
extern u16 D_00253004[];
extern u16 D_00253010[];
extern u16 D_00253024[];
extern u16 D_0025BF98[];
extern u16 D_0025BFA6[];
extern u16 D_0025BFB4[];
extern u16 D_0025BFC2[];
extern u16 D_0025C3C0[];
extern u16 D_0025C3C4[];
extern u16 D_0025C3C8[];
extern u16 D_0025C3CC[];
extern u16 D_0025C3D0[];
extern u16 D_0025C3D4[];
extern u16 D_0025C3D8[];
extern u16 D_0025C3DC[];
extern u16 D_0025C3E0[];
extern u16 D_0025C3E4[];
extern u16 D_0025C3E8[];
extern u16 D_0025C3EC[];
extern u16 D_0025C3F0[];
extern u16 D_0025C3F4[];
extern u16 D_0025C3F8[];
extern u16 D_0025C3FC[];
extern u16 D_0025C400[];
extern u16 D_0025C404[];
extern u16 D_0025C408[];
extern u16 D_0025C40C[];
extern u16 D_0025C410[];
extern u16 D_0025C414[];
extern u16 D_0025C418[];
extern u16 D_0025C41C[];
extern u16 D_0025C420[];
extern u16 D_0025C424[];
extern u16 D_0025C428[];
extern u16 D_0025C42C[];
extern u16 D_002643E0_as_u16_a[];
extern u16 D_002643E2[];
extern u16 D_002643E4[];
extern u16 D_002643E8[];
extern u16 D_002643EC[];
extern u16 D_00264C38[];
extern u16 D_00264C46[];
extern u16 D_00264C54[];
extern u16 D_00264C62[];
extern u16 D_00264C70[];
extern u16 D_00264C7E[];
extern u16 D_00264C8C[];
extern u16 D_00264C9A[];
extern u16 D_00264CA8[];
extern u16 D_00264CB6[];
extern u16 D_00264CC4[];
extern u16 D_00264CD2[];
extern u16 D_00264CE0[];
extern u16 D_00264CEE[];
extern u16 D_00264D08[];
extern u16 D_00264D16[];
extern u16 D_00264D24[];
extern u16 D_00264D32[];
extern u16 D_00264D40[];
extern u16 D_00264D4E[];
extern u16 D_00264D5C[];
extern u16 D_00264D6A[];
extern u16 D_00264D78[];
extern u16 D_00264E18[];
extern u16 D_00264E26[];
extern u16 D_00264E34[];
extern u16 D_00264E42[];
extern u16 D_00264E50[];
extern u16 D_00264E5E[];
extern u16 D_00264E6C[];
extern u16 D_00264E86[];
extern u16 D_00264E92[];
extern u16 D_00264EA8[];
extern u16 D_00264EB6[];
extern u16 D_00264EC4[];
extern u16 D_00264ED2[];
extern u16 D_0028C148_as_u16_a[];
extern u16 D_0028C14A[];
extern u16 D_0028C14C[];
extern u16 D_0028C164[];
extern u16 D_0028C16C[];
extern u16 D_0028C174[];
extern u16 D_0028C17C[];
extern u16 D_0028C184[];

#ifdef DEATH_LABEL
extern u16 death_D_002506F0[];
extern u16 death_D_002506F2[];
extern u16 death_D_00250790[];
extern u16 death_D_00250792[];
extern u16 death_D_00250A72[];
extern u16 death_D_00250B20[];
extern u16 death_D_00250B22[];
extern u16 death_D_00254748[];
extern u16 death_D_00254758[];
extern u16 death_D_00254768[];
extern u16 death_D_00254778[];
extern u16 death_D_00254790[];
extern u16 death_D_002547A0[];
extern u16 death_D_002547B0[];
extern u16 death_D_002547C0[];
extern u16 death_D_0025495A[];
extern u16 death_D_0025495C[];
extern u16 death_D_00254964[];
extern u16 death_D_00254966[];
extern u16 death_D_0025496E[];
extern u16 death_D_00254970[];
extern u16 death_D_00254978[];
extern u16 death_D_0025497A[];
extern u16 death_D_00254982[];
extern u16 death_D_00254984[];
extern const char death_D_0027B030[];
extern const char death_D_0027B4D0[];
extern const char death_D_0027B970[];
extern void death_func_0012E5B0(void);
#endif

void func_0018E5A0(void) {
    extern void func_0016A8B0(void);
    extern void func_0016A8C0(void);
    extern void func_0016A8D0(void);
    extern void func_0016A8E0(void);
    if (D_0024E740_as_u16_a[0] != 0x0) {
        printf((const char *)D_002784E0);
    }
    D_0024E740_as_u16_a[0] = ((u32)func_001298A0) >> 16;
    D_0024E742[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E744[0] != 0x2) {
        printf((const char *)D_00278500);
    }
    D_0024E744[0] = ((u32)func_001298A0) >> 16;
    D_0024E746[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E748[0] != 0x4) {
        printf((const char *)D_00278520);
    }
    D_0024E748[0] = ((u32)func_001298A0) >> 16;
    D_0024E74A[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E74C[0] != 0x6) {
        printf((const char *)D_00278540);
    }
    D_0024E74C[0] = ((u32)func_001298D0) >> 16;
    D_0024E74E[0] = ((u32)func_001298D0) & 0xFFFF;
    if (D_0024E750[0] != 0x8) {
        printf((const char *)D_00278560);
    }
    D_0024E750[0] = ((u32)func_001298D0) >> 16;
    D_0024E752[0] = ((u32)func_001298D0) & 0xFFFF;
    if (D_0024E754[0] != 0xa) {
        printf((const char *)D_00278580);
    }
    D_0024E754[0] = ((u32)func_001298D0) >> 16;
    D_0024E756[0] = ((u32)func_001298D0) & 0xFFFF;
    if (D_0024E758[0] != 0xc) {
        printf((const char *)D_002785A0);
    }
    D_0024E758[0] = ((u32)func_001298D0) >> 16;
    D_0024E75A[0] = ((u32)func_001298D0) & 0xFFFF;
    if (D_0024E75C[0] != 0xe) {
        printf((const char *)D_002785C0);
    }
    D_0024E75C[0] = ((u32)func_001298A0) >> 16;
    D_0024E75E[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E760[0] != 0x10) {
        printf((const char *)D_002785E0);
    }
    D_0024E760[0] = ((u32)func_001298A0) >> 16;
    D_0024E762[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E764[0] != 0x12) {
        printf((const char *)D_00278600);
    }
    D_0024E764[0] = ((u32)func_001298A0) >> 16;
    D_0024E766[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E768[0] != 0x14) {
        printf((const char *)D_00278620);
    }
    D_0024E768[0] = ((u32)func_001298A0) >> 16;
    D_0024E76A[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E76C[0] != 0x16) {
        printf((const char *)D_00278640);
    }
    D_0024E76C[0] = ((u32)func_001298A0) >> 16;
    D_0024E76E[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E770[0] != 0x18) {
        printf((const char *)D_00278660);
    }
    D_0024E770[0] = ((u32)func_001298A0) >> 16;
    D_0024E772[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E774[0] != 0x1a) {
        printf((const char *)D_00278680);
    }
    D_0024E774[0] = ((u32)func_001298A0) >> 16;
    D_0024E776[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E778[0] != 0x1c) {
        printf((const char *)D_002786A0);
    }
    D_0024E778[0] = ((u32)func_001298A0) >> 16;
    D_0024E77A[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E77C[0] != 0x1e) {
        printf((const char *)D_002786C0);
    }
    D_0024E77C[0] = ((u32)func_001298A0) >> 16;
    D_0024E77E[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E780[0] != 0x20) {
        printf((const char *)D_002786E0);
    }
    D_0024E780[0] = ((u32)func_001298A0) >> 16;
    D_0024E782[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E784[0] != 0x22) {
        printf((const char *)D_00278700);
    }
    D_0024E784[0] = ((u32)func_00129930) >> 16;
    D_0024E786[0] = ((u32)func_00129930) & 0xFFFF;
    if (D_0024E788[0] != 0x24) {
        printf((const char *)D_00278720);
    }
    D_0024E788[0] = ((u32)func_00129970) >> 16;
    D_0024E78A[0] = ((u32)func_00129970) & 0xFFFF;
    if (D_0024E78C[0] != 0x26) {
        printf((const char *)D_00278740);
    }
    D_0024E78C[0] = ((u32)func_001299B0) >> 16;
    D_0024E78E[0] = ((u32)func_001299B0) & 0xFFFF;
    if (D_0024E790[0] != 0x28) {
        printf((const char *)D_00278760);
    }
    D_0024E790[0] = ((u32)func_001298A0) >> 16;
    D_0024E792[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E794[0] != 0x2a) {
        printf((const char *)D_00278780);
    }
    D_0024E794[0] = ((u32)func_001298A0) >> 16;
    D_0024E796[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E798[0] != 0x2c) {
        printf((const char *)D_002787A0);
    }
    D_0024E798[0] = ((u32)func_001299B0) >> 16;
    D_0024E79A[0] = ((u32)func_001299B0) & 0xFFFF;
    if (D_0024E79C[0] != 0x2e) {
        printf((const char *)D_002787C0);
    }
    D_0024E79C[0] = ((u32)func_00129A10) >> 16;
    D_0024E79E[0] = ((u32)func_00129A10) & 0xFFFF;
    if (D_0024E7A0[0] != 0x30) {
        printf((const char *)D_002787E0);
    }
    D_0024E7A0[0] = ((u32)func_00129A10) >> 16;
    D_0024E7A2[0] = ((u32)func_00129A10) & 0xFFFF;
    if (D_0024E7A4[0] != 0x32) {
        printf((const char *)D_00278800);
    }
    D_0024E7A4[0] = ((u32)func_001298A0) >> 16;
    D_0024E7A6[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E7A8[0] != 0x34) {
        printf((const char *)D_00278820);
    }
    D_0024E7A8[0] = ((u32)func_001298A0) >> 16;
    D_0024E7AA[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E7AC[0] != 0x36) {
        printf((const char *)D_00278840);
    }
    D_0024E7AC[0] = ((u32)func_00129A80) >> 16;
    D_0024E7AE[0] = ((u32)func_00129A80) & 0xFFFF;
    if (D_0024E7B0[0] != 0x38) {
        printf((const char *)D_00278860);
    }
    D_0024E7B0[0] = ((u32)func_00129B10) >> 16;
    D_0024E7B2[0] = ((u32)func_00129B10) & 0xFFFF;
    if (D_0024E7B4[0] != 0x3a) {
        printf((const char *)D_00278880);
    }
    D_0024E7B4[0] = ((u32)func_001298A0) >> 16;
    D_0024E7B6[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E7B8[0] != 0x3c) {
        printf((const char *)D_002788A0);
    }
    D_0024E7B8[0] = ((u32)func_00129B60) >> 16;
    D_0024E7BA[0] = ((u32)func_00129B60) & 0xFFFF;
    if (D_0024E7BC[0] != 0x3e) {
        printf((const char *)D_002788C0);
    }
    D_0024E7BC[0] = ((u32)func_00129B70) >> 16;
    D_0024E7BE[0] = ((u32)func_00129B70) & 0xFFFF;
    if (D_0024E7C0[0] != 0x40) {
        printf((const char *)D_002788E0);
    }
    D_0024E7C0[0] = ((u32)func_00129A90) >> 16;
    D_0024E7C2[0] = ((u32)func_00129A90) & 0xFFFF;
    if (D_0024E7C4[0] != 0x42) {
        printf((const char *)D_00278900);
    }
    D_0024E7C4[0] = ((u32)func_001298A0) >> 16;
    D_0024E7C6[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E7C8[0] != 0x44) {
        printf((const char *)D_00278920);
    }
    D_0024E7C8[0] = ((u32)func_001298A0) >> 16;
    D_0024E7CA[0] = ((u32)func_001298A0) & 0xFFFF;
    if (D_0024E7CC[0] != 0x46) {
        printf((const char *)D_00278940);
    }
    D_0024E7CC[0] = ((u32)func_001298D0) >> 16;
    D_0024E7CE[0] = ((u32)func_001298D0) & 0xFFFF;
#ifdef DEATH_LABEL
    if (death_D_002506F0[0] != 0x48) {
        printf(death_D_0027B030);
    }
    death_D_002506F0[0] = ((u32)func_00129B10) >> 16;
    death_D_002506F2[0] = ((u32)func_00129B10) & 0xFFFF;
#endif
    if (D_0024E7D0[0] != 0x0) {
        printf((const char *)D_00278960);
    }
    D_0024E7D0[0] = ((u32)D_0024E862) >> 16;
    D_0024E7D2[0] = ((u32)D_0024E862) & 0xFFFF;
    if (D_0024E7D4[0] != 0x2) {
        printf((const char *)D_00278980);
    }
    D_0024E7D4[0] = ((u32)D_0024E876) >> 16;
    D_0024E7D6[0] = ((u32)D_0024E876) & 0xFFFF;
    if (D_0024E7D8[0] != 0x4) {
        printf((const char *)D_002789A0);
    }
    D_0024E7D8[0] = ((u32)D_0024E88A) >> 16;
    D_0024E7DA[0] = ((u32)D_0024E88A) & 0xFFFF;
    if (D_0024E7DC[0] != 0x6) {
        printf((const char *)D_002789C0);
    }
    D_0024E7DC[0] = ((u32)D_0024E89E) >> 16;
    D_0024E7DE[0] = ((u32)D_0024E89E) & 0xFFFF;
    if (D_0024E7E0[0] != 0x8) {
        printf((const char *)D_002789E0);
    }
    D_0024E7E0[0] = ((u32)D_0024E8B2) >> 16;
    D_0024E7E2[0] = ((u32)D_0024E8B2) & 0xFFFF;
    if (D_0024E7E4[0] != 0xa) {
        printf((const char *)D_00278A00);
    }
    D_0024E7E4[0] = ((u32)D_0024E8C6) >> 16;
    D_0024E7E6[0] = ((u32)D_0024E8C6) & 0xFFFF;
    if (D_0024E7E8[0] != 0xc) {
        printf((const char *)D_00278A20);
    }
    D_0024E7E8[0] = ((u32)D_0024E8DA) >> 16;
    D_0024E7EA[0] = ((u32)D_0024E8DA) & 0xFFFF;
    if (D_0024E7EC[0] != 0xe) {
        printf((const char *)D_00278A40);
    }
    D_0024E7EC[0] = ((u32)D_0024E8EE) >> 16;
    D_0024E7EE[0] = ((u32)D_0024E8EE) & 0xFFFF;
    if (D_0024E7F0[0] != 0x10) {
        printf((const char *)D_00278A60);
    }
    D_0024E7F0[0] = ((u32)D_0024E902) >> 16;
    D_0024E7F2[0] = ((u32)D_0024E902) & 0xFFFF;
    if (D_0024E7F4[0] != 0x12) {
        printf((const char *)D_00278A80);
    }
    D_0024E7F4[0] = ((u32)D_0024E916) >> 16;
    D_0024E7F6[0] = ((u32)D_0024E916) & 0xFFFF;
    if (D_0024E7F8[0] != 0x14) {
        printf((const char *)D_00278AA0);
    }
    D_0024E7F8[0] = ((u32)D_0024E92A) >> 16;
    D_0024E7FA[0] = ((u32)D_0024E92A) & 0xFFFF;
    if (D_0024E7FC[0] != 0x16) {
        printf((const char *)D_00278AC0);
    }
    D_0024E7FC[0] = ((u32)D_0024E93E) >> 16;
    D_0024E7FE[0] = ((u32)D_0024E93E) & 0xFFFF;
    if (D_0024E800[0] != 0x18) {
        printf((const char *)D_00278AE0);
    }
    D_0024E800[0] = ((u32)D_0024E952) >> 16;
    D_0024E802[0] = ((u32)D_0024E952) & 0xFFFF;
    if (D_0024E804[0] != 0x1a) {
        printf((const char *)D_00278B00);
    }
    D_0024E804[0] = ((u32)D_0024E966) >> 16;
    D_0024E806[0] = ((u32)D_0024E966) & 0xFFFF;
    if (D_0024E808[0] != 0x1c) {
        printf((const char *)D_00278B20);
    }
    D_0024E808[0] = ((u32)D_0024E97A) >> 16;
    D_0024E80A[0] = ((u32)D_0024E97A) & 0xFFFF;
    if (D_0024E80C[0] != 0x1e) {
        printf((const char *)D_00278B40);
    }
    D_0024E80C[0] = ((u32)D_0024E98E) >> 16;
    D_0024E80E[0] = ((u32)D_0024E98E) & 0xFFFF;
    if (D_0024E810[0] != 0x20) {
        printf((const char *)D_00278B60);
    }
    D_0024E810[0] = ((u32)D_0024E9A2) >> 16;
    D_0024E812[0] = ((u32)D_0024E9A2) & 0xFFFF;
    if (D_0024E814[0] != 0x22) {
        printf((const char *)D_00278B80);
    }
    D_0024E814[0] = ((u32)D_0024E9B6) >> 16;
    D_0024E816[0] = ((u32)D_0024E9B6) & 0xFFFF;
    if (D_0024E818[0] != 0x24) {
        printf((const char *)D_00278BA0);
    }
    D_0024E818[0] = ((u32)D_0024E9CA) >> 16;
    D_0024E81A[0] = ((u32)D_0024E9CA) & 0xFFFF;
    if (D_0024E81C[0] != 0x26) {
        printf((const char *)D_00278BC0);
    }
    D_0024E81C[0] = ((u32)D_0024E9DE) >> 16;
    D_0024E81E[0] = ((u32)D_0024E9DE) & 0xFFFF;
    if (D_0024E820[0] != 0x28) {
        printf((const char *)D_00278BE0);
    }
    D_0024E820[0] = ((u32)D_0024E9F2) >> 16;
    D_0024E822[0] = ((u32)D_0024E9F2) & 0xFFFF;
    if (D_0024E824[0] != 0x2a) {
        printf((const char *)D_00278C00);
    }
    D_0024E824[0] = ((u32)D_0024EA06) >> 16;
    D_0024E826[0] = ((u32)D_0024EA06) & 0xFFFF;
    if (D_0024E828[0] != 0x2c) {
        printf((const char *)D_00278C20);
    }
    D_0024E828[0] = ((u32)D_0024EA1A) >> 16;
    D_0024E82A[0] = ((u32)D_0024EA1A) & 0xFFFF;
    if (D_0024E82C[0] != 0x2e) {
        printf((const char *)D_00278C40);
    }
    D_0024E82C[0] = ((u32)D_0024EA2E) >> 16;
    D_0024E82E[0] = ((u32)D_0024EA2E) & 0xFFFF;
    if (D_0024E830[0] != 0x30) {
        printf((const char *)D_00278C60);
    }
    D_0024E830[0] = ((u32)D_0024EA42) >> 16;
    D_0024E832[0] = ((u32)D_0024EA42) & 0xFFFF;
    if (D_0024E834[0] != 0x32) {
        printf((const char *)D_00278C80);
    }
    D_0024E834[0] = ((u32)D_0024EA56) >> 16;
    D_0024E836[0] = ((u32)D_0024EA56) & 0xFFFF;
    if (D_0024E838[0] != 0x34) {
        printf((const char *)D_00278CA0);
    }
    D_0024E838[0] = ((u32)D_0024EA6A) >> 16;
    D_0024E83A[0] = ((u32)D_0024EA6A) & 0xFFFF;
    if (D_0024E83C[0] != 0x36) {
        printf((const char *)D_00278CC0);
    }
    D_0024E83C[0] = ((u32)D_0024EA7E) >> 16;
    D_0024E83E[0] = ((u32)D_0024EA7E) & 0xFFFF;
    if (D_0024E840[0] != 0x38) {
        printf((const char *)D_00278CE0);
    }
    D_0024E840[0] = ((u32)D_0024EA92) >> 16;
    D_0024E842[0] = ((u32)D_0024EA92) & 0xFFFF;
    if (D_0024E844[0] != 0x3a) {
        printf((const char *)D_00278D00);
    }
    D_0024E844[0] = ((u32)D_0024EAA6) >> 16;
    D_0024E846[0] = ((u32)D_0024EAA6) & 0xFFFF;
    if (D_0024E848[0] != 0x3c) {
        printf((const char *)D_00278D20);
    }
    D_0024E848[0] = ((u32)D_0024EABA) >> 16;
    D_0024E84A[0] = ((u32)D_0024EABA) & 0xFFFF;
    if (D_0024E84C[0] != 0x3e) {
        printf((const char *)D_00278D40);
    }
    D_0024E84C[0] = ((u32)D_0024EACE) >> 16;
    D_0024E84E[0] = ((u32)D_0024EACE) & 0xFFFF;
    if (D_0024E850[0] != 0x40) {
        printf((const char *)D_00278D60);
    }
    D_0024E850[0] = ((u32)D_0024EAE2) >> 16;
    D_0024E852[0] = ((u32)D_0024EAE2) & 0xFFFF;
    if (D_0024E854[0] != 0x42) {
        printf((const char *)D_00278D80);
    }
    D_0024E854[0] = ((u32)D_0024EAF6) >> 16;
    D_0024E856[0] = ((u32)D_0024EAF6) & 0xFFFF;
    if (D_0024E858[0] != 0x44) {
        printf((const char *)D_00278DA0);
    }
    D_0024E858[0] = ((u32)D_0024EB0A) >> 16;
    D_0024E85A[0] = ((u32)D_0024EB0A) & 0xFFFF;
    if (D_0024E85C[0] != 0x46) {
        printf((const char *)D_00278DC0);
    }
    D_0024E85C[0] = ((u32)D_0024EB1E) >> 16;
    D_0024E85E[0] = ((u32)D_0024EB1E) & 0xFFFF;
#ifdef DEATH_LABEL
    if (death_D_00250790[0] != 0x48) {
        printf(death_D_0027B4D0);
    }
    death_D_00250790[0] = ((u32)death_D_00250A72) >> 16;
    death_D_00250792[0] = ((u32)death_D_00250A72) & 0xFFFF;
#endif
    if (D_0024EB30_as_u16_a[0] != 0x0) {
        printf((const char *)D_00278DE0);
    }
    D_0024EB30_as_u16_a[0] = ((u32)func_0012DE90) >> 16;
    D_0024EB32[0] = ((u32)func_0012DE90) & 0xFFFF;
    if (D_0024EB34[0] != 0x2) {
        printf((const char *)D_00278E00);
    }
    D_0024EB34[0] = ((u32)func_0012DF50) >> 16;
    D_0024EB36[0] = ((u32)func_0012DF50) & 0xFFFF;
    if (D_0024EB38[0] != 0x4) {
        printf((const char *)D_00278E20);
    }
    D_0024EB38[0] = ((u32)func_0012E010) >> 16;
    D_0024EB3A[0] = ((u32)func_0012E010) & 0xFFFF;
    if (D_0024EB3C[0] != 0x6) {
        printf((const char *)D_00278E40);
    }
    D_0024EB3C[0] = ((u32)func_0012E0B0) >> 16;
    D_0024EB3E[0] = ((u32)func_0012E0B0) & 0xFFFF;
    if (D_0024EB40[0] != 0x8) {
        printf((const char *)D_00278E60);
    }
    D_0024EB40[0] = ((u32)func_0012E130) >> 16;
    D_0024EB42[0] = ((u32)func_0012E130) & 0xFFFF;
    if (D_0024EB44[0] != 0xa) {
        printf((const char *)D_00278E80);
    }
    D_0024EB44[0] = ((u32)func_0012E1B0) >> 16;
    D_0024EB46[0] = ((u32)func_0012E1B0) & 0xFFFF;
    if (D_0024EB48[0] != 0xc) {
        printf((const char *)D_00278EA0);
    }
    D_0024EB48[0] = ((u32)func_0012E230) >> 16;
    D_0024EB4A[0] = ((u32)func_0012E230) & 0xFFFF;
    if (D_0024EB4C[0] != 0xe) {
        printf((const char *)D_00278EC0);
    }
    D_0024EB4C[0] = ((u32)func_0012E2B0) >> 16;
    D_0024EB4E[0] = ((u32)func_0012E2B0) & 0xFFFF;
    if (D_0024EB50[0] != 0x10) {
        printf((const char *)D_00278EE0);
    }
    D_0024EB50[0] = ((u32)func_0012E440) >> 16;
    D_0024EB52[0] = ((u32)func_0012E440) & 0xFFFF;
    if (D_0024EB54[0] != 0x12) {
        printf((const char *)D_00278F00);
    }
    D_0024EB54[0] = ((u32)func_0012E4D0) >> 16;
    D_0024EB56[0] = ((u32)func_0012E4D0) & 0xFFFF;
    if (D_0024EB58[0] != 0x14) {
        printf((const char *)D_00278F20);
    }
    D_0024EB58[0] = ((u32)func_0012E530) >> 16;
    D_0024EB5A[0] = ((u32)func_0012E530) & 0xFFFF;
    if (D_0024EB5C[0] != 0x16) {
        printf((const char *)D_00278F40);
    }
    D_0024EB5C[0] = ((u32)func_0012E590) >> 16;
    D_0024EB5E[0] = ((u32)func_0012E590) & 0xFFFF;
    if (D_0024EB60[0] != 0x18) {
        printf((const char *)D_00278F60);
    }
    D_0024EB60[0] = ((u32)func_0012E620) >> 16;
    D_0024EB62[0] = ((u32)func_0012E620) & 0xFFFF;
    if (D_0024EB64[0] != 0x1a) {
        printf((const char *)D_00278F80);
    }
    D_0024EB64[0] = ((u32)func_0012E680) >> 16;
    D_0024EB66[0] = ((u32)func_0012E680) & 0xFFFF;
    if (D_0024EB68[0] != 0x1c) {
        printf((const char *)D_00278FA0);
    }
    D_0024EB68[0] = ((u32)func_0012E530) >> 16;
    D_0024EB6A[0] = ((u32)func_0012E530) & 0xFFFF;
    if (D_0024EB6C[0] != 0x1e) {
        printf((const char *)D_00278FC0);
    }
    D_0024EB6C[0] = ((u32)func_0012E530) >> 16;
    D_0024EB6E[0] = ((u32)func_0012E530) & 0xFFFF;
    if (D_0024EB70[0] != 0x20) {
        printf((const char *)D_00278FE0);
    }
    D_0024EB70[0] = ((u32)func_0012E6E0) >> 16;
    D_0024EB72[0] = ((u32)func_0012E6E0) & 0xFFFF;
    if (D_0024EB74[0] != 0x22) {
        printf((const char *)D_00279000);
    }
    D_0024EB74[0] = ((u32)func_0012E7A0) >> 16;
    D_0024EB76[0] = ((u32)func_0012E7A0) & 0xFFFF;
    if (D_0024EB78[0] != 0x24) {
        printf((const char *)D_00279020);
    }
    D_0024EB78[0] = ((u32)func_0012E860) >> 16;
    D_0024EB7A[0] = ((u32)func_0012E860) & 0xFFFF;
    if (D_0024EB7C[0] != 0x26) {
        printf((const char *)D_00279040);
    }
    D_0024EB7C[0] = ((u32)func_0012E920) >> 16;
    D_0024EB7E[0] = ((u32)func_0012E920) & 0xFFFF;
    if (D_0024EB80[0] != 0x28) {
        printf((const char *)D_00279060);
    }
    D_0024EB80[0] = ((u32)func_0012E9E0) >> 16;
    D_0024EB82[0] = ((u32)func_0012E9E0) & 0xFFFF;
    if (D_0024EB84[0] != 0x2a) {
        printf((const char *)D_00279080);
    }
    D_0024EB84[0] = ((u32)func_0012EAA0) >> 16;
    D_0024EB86[0] = ((u32)func_0012EAA0) & 0xFFFF;
    if (D_0024EB88[0] != 0x2c) {
        printf((const char *)D_002790A0);
    }
    D_0024EB88[0] = ((u32)func_0012EB40) >> 16;
    D_0024EB8A[0] = ((u32)func_0012EB40) & 0xFFFF;
    if (D_0024EB8C[0] != 0x2e) {
        printf((const char *)D_002790C0);
    }
    D_0024EB8C[0] = ((u32)func_0012EC00) >> 16;
    D_0024EB8E[0] = ((u32)func_0012EC00) & 0xFFFF;
    if (D_0024EB90[0] != 0x30) {
        printf((const char *)D_002790E0);
    }
    D_0024EB90[0] = ((u32)func_0012EC90) >> 16;
    D_0024EB92[0] = ((u32)func_0012EC90) & 0xFFFF;
    if (D_0024EB94[0] != 0x32) {
        printf((const char *)D_00279100);
    }
    D_0024EB94[0] = ((u32)func_0012ED50) >> 16;
    D_0024EB96[0] = ((u32)func_0012ED50) & 0xFFFF;
    if (D_0024EB98[0] != 0x34) {
        printf((const char *)D_00279120);
    }
    D_0024EB98[0] = ((u32)func_0012EDF0) >> 16;
    D_0024EB9A[0] = ((u32)func_0012EDF0) & 0xFFFF;
    if (D_0024EB9C[0] != 0x36) {
        printf((const char *)D_00279140);
    }
    D_0024EB9C[0] = ((u32)func_0012EE90) >> 16;
    D_0024EB9E[0] = ((u32)func_0012EE90) & 0xFFFF;
    if (D_0024EBA0[0] != 0x38) {
        printf((const char *)D_00279160);
    }
    D_0024EBA0[0] = ((u32)func_0012EF80) >> 16;
    D_0024EBA2[0] = ((u32)func_0012EF80) & 0xFFFF;
    if (D_0024EBA4[0] != 0x3a) {
        printf((const char *)D_00279180);
    }
    D_0024EBA4[0] = ((u32)func_0012F020) >> 16;
    D_0024EBA6[0] = ((u32)func_0012F020) & 0xFFFF;
    if (D_0024EBA8[0] != 0x3c) {
        printf((const char *)D_002791A0);
    }
    D_0024EBA8[0] = ((u32)func_0012F0C0) >> 16;
    D_0024EBAA[0] = ((u32)func_0012F0C0) & 0xFFFF;
    if (D_0024EBAC[0] != 0x3e) {
        printf((const char *)D_002791C0);
    }
    D_0024EBAC[0] = ((u32)func_0012F1B0) >> 16;
    D_0024EBAE[0] = ((u32)func_0012F1B0) & 0xFFFF;
    if (D_0024EBB0[0] != 0x40) {
        printf((const char *)D_002791E0);
    }
    D_0024EBB0[0] = ((u32)func_0012F2A0) >> 16;
    D_0024EBB2[0] = ((u32)func_0012F2A0) & 0xFFFF;
    if (D_0024EBB4[0] != 0x42) {
        printf((const char *)D_00279200);
    }
    D_0024EBB4[0] = ((u32)func_0012F330) >> 16;
    D_0024EBB6[0] = ((u32)func_0012F330) & 0xFFFF;
    if (D_0024EBB8[0] != 0x44) {
        printf((const char *)D_00279220);
    }
    D_0024EBB8[0] = ((u32)func_0012F3B0) >> 16;
    D_0024EBBA[0] = ((u32)func_0012F3B0) & 0xFFFF;
    if (D_0024EBBC[0] != 0x46) {
        printf((const char *)D_00279240);
    }
    D_0024EBBC[0] = ((u32)func_0012F450) >> 16;
    D_0024EBBE[0] = ((u32)func_0012F450) & 0xFFFF;
#ifdef DEATH_LABEL
    if (death_D_00250B20[0] != 0x48) {
        printf(death_D_0027B970);
    }
    death_D_00250B20[0] = ((u32)death_func_0012E5B0) >> 16;
    death_D_00250B22[0] = ((u32)death_func_0012E5B0) & 0xFFFF;
#endif
    if (D_0024EBC0_as_u16_a[0] != 0x0) {
        printf((const char *)D_00279260);
    }
    D_0024EBC0_as_u16_a[0] = ((u32)D_0024EBF0) >> 16;
    D_0024EBC2[0] = ((u32)D_0024EBF0) & 0xFFFF;
    if (D_0024EBC4[0] != 0x2) {
        printf((const char *)D_00279280);
    }
    D_0024EBC4[0] = ((u32)D_0024EC00) >> 16;
    D_0024EBC6[0] = ((u32)D_0024EC00) & 0xFFFF;
    if (D_0024EBC8[0] != 0x4) {
        printf((const char *)D_002792A0);
    }
    D_0024EBC8[0] = ((u32)D_0024EC10) >> 16;
    D_0024EBCA[0] = ((u32)D_0024EC10) & 0xFFFF;
    if (D_0024EBCC[0] != 0x6) {
        printf((const char *)D_002792C0);
    }
    D_0024EBCC[0] = ((u32)D_0024EC20) >> 16;
    D_0024EBCE[0] = ((u32)D_0024EC20) & 0xFFFF;
    if (D_0024EBD0[0] != 0x8) {
        printf((const char *)D_002792E0);
    }
    D_0024EBD0[0] = ((u32)D_0024EC30) >> 16;
    D_0024EBD2[0] = ((u32)D_0024EC30) & 0xFFFF;
    if (D_0024EBD4[0] != 0xa) {
        printf((const char *)D_00279300);
    }
    D_0024EBD4[0] = ((u32)D_0024EC40) >> 16;
    D_0024EBD6[0] = ((u32)D_0024EC40) & 0xFFFF;
    if (D_0024EBD8[0] != 0xc) {
        printf((const char *)D_00279320);
    }
    D_0024EBD8[0] = ((u32)D_0024EC50) >> 16;
    D_0024EBDA[0] = ((u32)D_0024EC50) & 0xFFFF;
    if (D_0024EBDC[0] != 0xe) {
        printf((const char *)D_00279340);
    }
    D_0024EBDC[0] = ((u32)D_0024EC60) >> 16;
    D_0024EBDE[0] = ((u32)D_0024EC60) & 0xFFFF;
    if (D_0024EBE0[0] != 0x10) {
        printf((const char *)D_00279360);
    }
    D_0024EBE0[0] = ((u32)D_0024EC70) >> 16;
    D_0024EBE2[0] = ((u32)D_0024EC70) & 0xFFFF;
    if (D_0024EDB0_as_u16_a[0] != 0x0) {
        printf((const char *)D_00279380);
    }
    D_0024EDB0_as_u16_a[0] = ((u32)D_0024EDE0) >> 16;
    D_0024EDB2[0] = ((u32)D_0024EDE0) & 0xFFFF;
    if (D_0024EDB4[0] != 0x2) {
        printf((const char *)D_002793A0);
    }
    D_0024EDB4[0] = ((u32)D_0024EDF0) >> 16;
    D_0024EDB6[0] = ((u32)D_0024EDF0) & 0xFFFF;
    if (D_0024EDB8[0] != 0x4) {
        printf((const char *)D_002793C0);
    }
    D_0024EDB8[0] = ((u32)D_0024EE00) >> 16;
    D_0024EDBA[0] = ((u32)D_0024EE00) & 0xFFFF;
    if (D_0024EDBC[0] != 0x6) {
        printf((const char *)D_002793E0);
    }
    D_0024EDBC[0] = ((u32)D_0024EE10) >> 16;
    D_0024EDBE[0] = ((u32)D_0024EE10) & 0xFFFF;
    if (D_0024EDC0[0] != 0x8) {
        printf((const char *)D_00279400);
    }
    D_0024EDC0[0] = ((u32)D_0024EE20) >> 16;
    D_0024EDC2[0] = ((u32)D_0024EE20) & 0xFFFF;
    if (D_0024EDC4[0] != 0xa) {
        printf((const char *)D_00279420);
    }
    D_0024EDC4[0] = ((u32)D_0024EE30) >> 16;
    D_0024EDC6[0] = ((u32)D_0024EE30) & 0xFFFF;
    if (D_0024EDC8[0] != 0xc) {
        printf((const char *)D_00279440);
    }
    D_0024EDC8[0] = ((u32)D_0024EE40) >> 16;
    D_0024EDCA[0] = ((u32)D_0024EE40) & 0xFFFF;
    if (D_0024EDCC[0] != 0xe) {
        printf((const char *)D_00279460);
    }
    D_0024EDCC[0] = ((u32)D_0024EE50) >> 16;
    D_0024EDCE[0] = ((u32)D_0024EE50) & 0xFFFF;
    if (D_0024EDD0[0] != 0x10) {
        printf((const char *)D_00279480);
    }
    D_0024EDD0[0] = ((u32)D_0024EDE0) >> 16;
    D_0024EDD2[0] = ((u32)D_0024EDE0) & 0xFFFF;
    if (D_0024F0B0[0] != 0x0) {
        printf((const char *)D_002794A0);
    }
    D_0024F0B0[0] = ((u32)func_0012D980) >> 16;
    D_0024F0B2[0] = ((u32)func_0012D980) & 0xFFFF;
    if (D_0024F0B8[0] != 0x4) {
        printf((const char *)D_002794C0);
    }
    D_0024F0B8[0] = ((u32)func_0012D960) >> 16;
    D_0024F0BA[0] = ((u32)func_0012D960) & 0xFFFF;
    if (D_0024F0C0[0] != 0x8) {
        printf((const char *)D_002794E0);
    }
    D_0024F0C0[0] = ((u32)func_0012D990) >> 16;
    D_0024F0C2[0] = ((u32)func_0012D990) & 0xFFFF;
    if (D_0024F0C8[0] != 0xc) {
        printf((const char *)D_00279500);
    }
    D_0024F0C8[0] = ((u32)func_0012D9B0) >> 16;
    D_0024F0CA[0] = ((u32)func_0012D9B0) & 0xFFFF;
    if (D_0024F0D0[0] != 0x10) {
        printf((const char *)D_00279520);
    }
    D_0024F0D0[0] = ((u32)func_0012D9F0) >> 16;
    D_0024F0D2[0] = ((u32)func_0012D9F0) & 0xFFFF;
    if (D_0024F0D8[0] != 0x14) {
        printf((const char *)D_00279540);
    }
    D_0024F0D8[0] = ((u32)func_0012D9D0) >> 16;
    D_0024F0DA[0] = ((u32)func_0012D9D0) & 0xFFFF;
    if (D_0024F0E0[0] != 0x18) {
        printf((const char *)D_00279560);
    }
    D_0024F0E0[0] = ((u32)func_0012D940) >> 16;
    D_0024F0E2[0] = ((u32)func_0012D940) & 0xFFFF;
    if (D_0024F0E8[0] != 0x1c) {
        printf((const char *)D_00279580);
    }
    D_0024F0E8[0] = ((u32)func_0012DA10) >> 16;
    D_0024F0EA[0] = ((u32)func_0012DA10) & 0xFFFF;
    if (D_0024F570[0] != 0x0) {
        printf((const char *)D_002795A0);
    }
    D_0024F570[0] = ((u32)D_0024F790) >> 16;
    D_0024F572[0] = ((u32)D_0024F790) & 0xFFFF;
    if (D_0024F574[0] != 0x2) {
        printf((const char *)D_002795C0);
    }
    D_0024F574[0] = ((u32)D_0024F7D0) >> 16;
    D_0024F576[0] = ((u32)D_0024F7D0) & 0xFFFF;
    if (D_0024F578[0] != 0x4) {
        printf((const char *)D_002795E0);
    }
    D_0024F578[0] = ((u32)D_0024F870) >> 16;
    D_0024F57A[0] = ((u32)D_0024F870) & 0xFFFF;
    if (D_0024F57C[0] != 0x6) {
        printf((const char *)D_00279600);
    }
    D_0024F57C[0] = ((u32)D_0024F8B0) >> 16;
    D_0024F57E[0] = ((u32)D_0024F8B0) & 0xFFFF;
    if (D_0024F580[0] != 0x8) {
        printf((const char *)D_00279620);
    }
    D_0024F580[0] = ((u32)D_0024F950) >> 16;
    D_0024F582[0] = ((u32)D_0024F950) & 0xFFFF;
    if (D_0024F584[0] != 0xa) {
        printf((const char *)D_00279640);
    }
    D_0024F584[0] = ((u32)D_0024F990) >> 16;
    D_0024F586[0] = ((u32)D_0024F990) & 0xFFFF;
    if (D_0024F588[0] != 0xc) {
        printf((const char *)D_00279660);
    }
    D_0024F588[0] = ((u32)D_0024FA30) >> 16;
    D_0024F58A[0] = ((u32)D_0024FA30) & 0xFFFF;
    if (D_0024F58C[0] != 0xe) {
        printf((const char *)D_00279680);
    }
    D_0024F58C[0] = ((u32)D_0024FAA0) >> 16;
    D_0024F58E[0] = ((u32)D_0024FAA0) & 0xFFFF;
    if (D_0024F590[0] != 0x10) {
        printf((const char *)D_002796A0);
    }
    D_0024F590[0] = ((u32)D_0024FBB0) >> 16;
    D_0024F592[0] = ((u32)D_0024FBB0) & 0xFFFF;
    if (D_0024F594[0] != 0x12) {
        printf((const char *)D_002796C0);
    }
    D_0024F594[0] = ((u32)D_0024FC30) >> 16;
    D_0024F596[0] = ((u32)D_0024FC30) & 0xFFFF;
    if (D_0024F598[0] != 0x14) {
        printf((const char *)D_002796E0);
    }
    D_0024F598[0] = ((u32)D_0024FD50) >> 16;
    D_0024F59A[0] = ((u32)D_0024FD50) & 0xFFFF;
    if (D_0024F59C[0] != 0x16) {
        printf((const char *)D_00279700);
    }
    D_0024F59C[0] = ((u32)D_0024FDE0) >> 16;
    D_0024F59E[0] = ((u32)D_0024FDE0) & 0xFFFF;
    if (D_0024F5A0[0] != 0x18) {
        printf((const char *)D_00279720);
    }
    D_0024F5A0[0] = ((u32)D_0024FF20) >> 16;
    D_0024F5A2[0] = ((u32)D_0024FF20) & 0xFFFF;
    if (D_0024F5A4[0] != 0x1a) {
        printf((const char *)D_00279740);
    }
    D_0024F5A4[0] = ((u32)D_0024FF90) >> 16;
    D_0024F5A6[0] = ((u32)D_0024FF90) & 0xFFFF;
    if (D_0024F5A8[0] != 0x1c) {
        printf((const char *)D_00279760);
    }
    D_0024F5A8[0] = ((u32)D_0024FFD0) >> 16;
    D_0024F5AA[0] = ((u32)D_0024FFD0) & 0xFFFF;
    if (D_0024F5AC[0] != 0x1e) {
        printf((const char *)D_00279780);
    }
    D_0024F5AC[0] = ((u32)D_00250060) >> 16;
    D_0024F5AE[0] = ((u32)D_00250060) & 0xFFFF;
    if (D_0024F5B0[0] != 0x20) {
        printf((const char *)D_002797A0);
    }
    D_0024F5B0[0] = ((u32)D_002500B0) >> 16;
    D_0024F5B2[0] = ((u32)D_002500B0) & 0xFFFF;
    if (D_0024F5B4[0] != 0x22) {
        printf((const char *)D_002797C0);
    }
    D_0024F5B4[0] = ((u32)D_00250130) >> 16;
    D_0024F5B6[0] = ((u32)D_00250130) & 0xFFFF;
    if (D_0024F5B8[0] != 0x24) {
        printf((const char *)D_002797E0);
    }
    D_0024F5B8[0] = ((u32)D_00250170) >> 16;
    D_0024F5BA[0] = ((u32)D_00250170) & 0xFFFF;
    if (D_0024F5BC[0] != 0x26) {
        printf((const char *)D_00279800);
    }
    D_0024F5BC[0] = ((u32)D_00250210) >> 16;
    D_0024F5BE[0] = ((u32)D_00250210) & 0xFFFF;
    if (D_0024F5C0[0] != 0x28) {
        printf((const char *)D_00279820);
    }
    D_0024F5C0[0] = ((u32)D_00250260) >> 16;
    D_0024F5C2[0] = ((u32)D_00250260) & 0xFFFF;
    if (D_0024F5C4[0] != 0x2a) {
        printf((const char *)D_00279840);
    }
    D_0024F5C4[0] = ((u32)D_002502C0) >> 16;
    D_0024F5C6[0] = ((u32)D_002502C0) & 0xFFFF;
    if (D_0024F5C8[0] != 0x2c) {
        printf((const char *)D_00279860);
    }
    D_0024F5C8[0] = ((u32)D_002502F0) >> 16;
    D_0024F5CA[0] = ((u32)D_002502F0) & 0xFFFF;
    if (D_0024F5CC[0] != 0x2e) {
        printf((const char *)D_00279880);
    }
    D_0024F5CC[0] = ((u32)D_002503A0) >> 16;
    D_0024F5CE[0] = ((u32)D_002503A0) & 0xFFFF;
    if (D_0024F5D0[0] != 0x30) {
        printf((const char *)D_002798A0);
    }
    D_0024F5D0[0] = ((u32)D_002503F0) >> 16;
    D_0024F5D2[0] = ((u32)D_002503F0) & 0xFFFF;
    if (D_0024F5D4[0] != 0x32) {
        printf((const char *)D_002798C0);
    }
    D_0024F5D4[0] = ((u32)D_00250490) >> 16;
    D_0024F5D6[0] = ((u32)D_00250490) & 0xFFFF;
    if (D_0024F5D8[0] != 0x34) {
        printf((const char *)D_002798E0);
    }
    D_0024F5D8[0] = ((u32)D_002504D0) >> 16;
    D_0024F5DA[0] = ((u32)D_002504D0) & 0xFFFF;
    if (D_0024F5DC[0] != 0x36) {
        printf((const char *)D_00279900);
    }
    D_0024F5DC[0] = ((u32)D_00250570) >> 16;
    D_0024F5DE[0] = ((u32)D_00250570) & 0xFFFF;
    if (D_0024F5E0[0] != 0x38) {
        printf((const char *)D_00279920);
    }
    D_0024F5E0[0] = ((u32)D_002505C0) >> 16;
    D_0024F5E2[0] = ((u32)D_002505C0) & 0xFFFF;
    if (D_0024F5E4[0] != 0x3a) {
        printf((const char *)D_00279940);
    }
    D_0024F5E4[0] = ((u32)D_00250600) >> 16;
    D_0024F5E6[0] = ((u32)D_00250600) & 0xFFFF;
    if (D_0024F5E8[0] != 0x3c) {
        printf((const char *)D_00279960);
    }
    D_0024F5E8[0] = ((u32)D_00250620) >> 16;
    D_0024F5EA[0] = ((u32)D_00250620) & 0xFFFF;
    if (D_0024F5EC[0] != 0x3e) {
        printf((const char *)D_00279980);
    }
    D_0024F5EC[0] = ((u32)D_002506B0) >> 16;
    D_0024F5EE[0] = ((u32)D_002506B0) & 0xFFFF;
    if (D_0024F5F0[0] != 0x40) {
        printf((const char *)D_002799A0);
    }
    D_0024F5F0[0] = ((u32)D_002506F0) >> 16;
    D_0024F5F2[0] = ((u32)D_002506F0) & 0xFFFF;
    if (D_0024F5F4[0] != 0x42) {
        printf((const char *)D_002799C0);
    }
    D_0024F5F4[0] = ((u32)D_00250740) >> 16;
    D_0024F5F6[0] = ((u32)D_00250740) & 0xFFFF;
    if (D_0024F5F8[0] != 0x44) {
        printf((const char *)D_002799E0);
    }
    D_0024F5F8[0] = ((u32)D_0024F790) >> 16;
    D_0024F5FA[0] = ((u32)D_0024F790) & 0xFFFF;
    if (D_0024F5FC[0] != 0x46) {
        printf((const char *)D_00279A00);
    }
    D_0024F5FC[0] = ((u32)D_0024F7D0) >> 16;
    D_0024F5FE[0] = ((u32)D_0024F7D0) & 0xFFFF;
    if (D_0024F600[0] != 0x48) {
        printf((const char *)D_00279A20);
    }
    D_0024F600[0] = ((u32)D_0024F870) >> 16;
    D_0024F602[0] = ((u32)D_0024F870) & 0xFFFF;
    if (D_0024F604[0] != 0x4a) {
        printf((const char *)D_00279A40);
    }
    D_0024F604[0] = ((u32)D_0024F8B0) >> 16;
    D_0024F606[0] = ((u32)D_0024F8B0) & 0xFFFF;
    if (D_0024F608[0] != 0x4c) {
        printf((const char *)D_00279A60);
    }
    D_0024F608[0] = ((u32)D_0024F950) >> 16;
    D_0024F60A[0] = ((u32)D_0024F950) & 0xFFFF;
    if (D_0024F60C[0] != 0x4e) {
        printf((const char *)D_00279A80);
    }
    D_0024F60C[0] = ((u32)D_0024F990) >> 16;
    D_0024F60E[0] = ((u32)D_0024F990) & 0xFFFF;
    if (D_0024F610[0] != 0x50) {
        printf((const char *)D_00279AA0);
    }
    D_0024F610[0] = ((u32)D_0024FA30) >> 16;
    D_0024F612[0] = ((u32)D_0024FA30) & 0xFFFF;
    if (D_0024F614[0] != 0x52) {
        printf((const char *)D_00279AC0);
    }
    D_0024F614[0] = ((u32)D_0024FAA0) >> 16;
    D_0024F616[0] = ((u32)D_0024FAA0) & 0xFFFF;
    if (D_0024F618[0] != 0x54) {
        printf((const char *)D_00279AE0);
    }
    D_0024F618[0] = ((u32)D_0024FBB0) >> 16;
    D_0024F61A[0] = ((u32)D_0024FBB0) & 0xFFFF;
    if (D_0024F61C[0] != 0x56) {
        printf((const char *)D_00279B00);
    }
    D_0024F61C[0] = ((u32)D_0024FC30) >> 16;
    D_0024F61E[0] = ((u32)D_0024FC30) & 0xFFFF;
    if (D_0024F620[0] != 0x58) {
        printf((const char *)D_00279B20);
    }
    D_0024F620[0] = ((u32)D_0024FD50) >> 16;
    D_0024F622[0] = ((u32)D_0024FD50) & 0xFFFF;
    if (D_0024F624[0] != 0x5a) {
        printf((const char *)D_00279B40);
    }
    D_0024F624[0] = ((u32)D_0024FDE0) >> 16;
    D_0024F626[0] = ((u32)D_0024FDE0) & 0xFFFF;
    if (D_0024F628[0] != 0x5c) {
        printf((const char *)D_00279B60);
    }
    D_0024F628[0] = ((u32)D_0024FF20) >> 16;
    D_0024F62A[0] = ((u32)D_0024FF20) & 0xFFFF;
    if (D_0024F62C[0] != 0x5e) {
        printf((const char *)D_00279B80);
    }
    D_0024F62C[0] = ((u32)D_0024FF90) >> 16;
    D_0024F62E[0] = ((u32)D_0024FF90) & 0xFFFF;
    if (D_0024F630[0] != 0x60) {
        printf((const char *)D_00279BA0);
    }
    D_0024F630[0] = ((u32)D_0024FFD0) >> 16;
    D_0024F632[0] = ((u32)D_0024FFD0) & 0xFFFF;
    if (D_0024F634[0] != 0x62) {
        printf((const char *)D_00279BC0);
    }
    D_0024F634[0] = ((u32)D_00250060) >> 16;
    D_0024F636[0] = ((u32)D_00250060) & 0xFFFF;
    if (D_0024F638[0] != 0x64) {
        printf((const char *)D_00279BE0);
    }
    D_0024F638[0] = ((u32)D_002500B0) >> 16;
    D_0024F63A[0] = ((u32)D_002500B0) & 0xFFFF;
    if (D_0024F63C[0] != 0x66) {
        printf((const char *)D_00279C00);
    }
    D_0024F63C[0] = ((u32)D_00250130) >> 16;
    D_0024F63E[0] = ((u32)D_00250130) & 0xFFFF;
    if (D_0024F640[0] != 0x68) {
        printf((const char *)D_00279C20);
    }
    D_0024F640[0] = ((u32)D_00250170) >> 16;
    D_0024F642[0] = ((u32)D_00250170) & 0xFFFF;
    if (D_0024F644[0] != 0x6a) {
        printf((const char *)D_00279C40);
    }
    D_0024F644[0] = ((u32)D_00250210) >> 16;
    D_0024F646[0] = ((u32)D_00250210) & 0xFFFF;
    if (D_0024F648[0] != 0x6c) {
        printf((const char *)D_00279C60);
    }
    D_0024F648[0] = ((u32)D_00250260) >> 16;
    D_0024F64A[0] = ((u32)D_00250260) & 0xFFFF;
    if (D_0024F64C[0] != 0x6e) {
        printf((const char *)D_00279C80);
    }
    D_0024F64C[0] = ((u32)D_002502C0) >> 16;
    D_0024F64E[0] = ((u32)D_002502C0) & 0xFFFF;
    if (D_0024F650[0] != 0x70) {
        printf((const char *)D_00279CA0);
    }
    D_0024F650[0] = ((u32)D_002502F0) >> 16;
    D_0024F652[0] = ((u32)D_002502F0) & 0xFFFF;
    if (D_0024F654[0] != 0x72) {
        printf((const char *)D_00279CC0);
    }
    D_0024F654[0] = ((u32)D_002503A0) >> 16;
    D_0024F656[0] = ((u32)D_002503A0) & 0xFFFF;
    if (D_0024F658[0] != 0x74) {
        printf((const char *)D_00279CE0);
    }
    D_0024F658[0] = ((u32)D_002503F0) >> 16;
    D_0024F65A[0] = ((u32)D_002503F0) & 0xFFFF;
    if (D_0024F65C[0] != 0x76) {
        printf((const char *)D_00279D00);
    }
    D_0024F65C[0] = ((u32)D_00250490) >> 16;
    D_0024F65E[0] = ((u32)D_00250490) & 0xFFFF;
    if (D_0024F660[0] != 0x78) {
        printf((const char *)D_00279D20);
    }
    D_0024F660[0] = ((u32)D_002504D0) >> 16;
    D_0024F662[0] = ((u32)D_002504D0) & 0xFFFF;
    if (D_0024F664[0] != 0x7a) {
        printf((const char *)D_00279D40);
    }
    D_0024F664[0] = ((u32)D_00250570) >> 16;
    D_0024F666[0] = ((u32)D_00250570) & 0xFFFF;
    if (D_0024F668[0] != 0x7c) {
        printf((const char *)D_00279D60);
    }
    D_0024F668[0] = ((u32)D_002505C0) >> 16;
    D_0024F66A[0] = ((u32)D_002505C0) & 0xFFFF;
    if (D_0024F66C[0] != 0x7e) {
        printf((const char *)D_00279D80);
    }
    D_0024F66C[0] = ((u32)D_00250600) >> 16;
    D_0024F66E[0] = ((u32)D_00250600) & 0xFFFF;
    if (D_0024F670[0] != 0x80) {
        printf((const char *)D_00279DA0);
    }
    D_0024F670[0] = ((u32)D_00250620) >> 16;
    D_0024F672[0] = ((u32)D_00250620) & 0xFFFF;
    if (D_0024F674[0] != 0x82) {
        printf((const char *)D_00279DC0);
    }
    D_0024F674[0] = ((u32)D_002506B0) >> 16;
    D_0024F676[0] = ((u32)D_002506B0) & 0xFFFF;
    if (D_0024F678[0] != 0x84) {
        printf((const char *)D_00279DE0);
    }
    D_0024F678[0] = ((u32)D_002506F0) >> 16;
    D_0024F67A[0] = ((u32)D_002506F0) & 0xFFFF;
    if (D_0024F67C[0] != 0x86) {
        printf((const char *)D_00279E00);
    }
    D_0024F67C[0] = ((u32)D_00250740) >> 16;
    D_0024F67E[0] = ((u32)D_00250740) & 0xFFFF;
    if (D_0024F680[0] != 0x0) {
        printf((const char *)D_00279E20);
    }
    D_0024F680[0] = ((u32)D_0024F7F0) >> 16;
    D_0024F682[0] = ((u32)D_0024F7F0) & 0xFFFF;
    if (D_0024F684[0] != 0x2) {
        printf((const char *)D_00279E40);
    }
    D_0024F684[0] = ((u32)D_0024F850) >> 16;
    D_0024F686[0] = ((u32)D_0024F850) & 0xFFFF;
    if (D_0024F688[0] != 0x4) {
        printf((const char *)D_00279E60);
    }
    D_0024F688[0] = ((u32)D_0024F8D0) >> 16;
    D_0024F68A[0] = ((u32)D_0024F8D0) & 0xFFFF;
    if (D_0024F68C[0] != 0x6) {
        printf((const char *)D_00279E80);
    }
    D_0024F68C[0] = ((u32)D_0024F930) >> 16;
    D_0024F68E[0] = ((u32)D_0024F930) & 0xFFFF;
    if (D_0024F690[0] != 0x8) {
        printf((const char *)D_00279EA0);
    }
    D_0024F690[0] = ((u32)D_0024F9B0) >> 16;
    D_0024F692[0] = ((u32)D_0024F9B0) & 0xFFFF;
    if (D_0024F694[0] != 0xa) {
        printf((const char *)D_00279EC0);
    }
    D_0024F694[0] = ((u32)D_0024FA10) >> 16;
    D_0024F696[0] = ((u32)D_0024FA10) & 0xFFFF;
    if (D_0024F698[0] != 0xc) {
        printf((const char *)D_00279EE0);
    }
    D_0024F698[0] = ((u32)D_0024FAE0) >> 16;
    D_0024F69A[0] = ((u32)D_0024FAE0) & 0xFFFF;
    if (D_0024F69C[0] != 0xe) {
        printf((const char *)D_00279F00);
    }
    D_0024F69C[0] = ((u32)D_0024FB70) >> 16;
    D_0024F69E[0] = ((u32)D_0024FB70) & 0xFFFF;
    if (D_0024F6A0[0] != 0x10) {
        printf((const char *)D_00279F20);
    }
    D_0024F6A0[0] = ((u32)D_0024FC70) >> 16;
    D_0024F6A2[0] = ((u32)D_0024FC70) & 0xFFFF;
    if (D_0024F6A4[0] != 0x12) {
        printf((const char *)D_00279F40);
    }
    D_0024F6A4[0] = ((u32)D_0024FD10) >> 16;
    D_0024F6A6[0] = ((u32)D_0024FD10) & 0xFFFF;
    if (D_0024F6A8[0] != 0x14) {
        printf((const char *)D_00279F60);
    }
    D_0024F6A8[0] = ((u32)D_0024FE30) >> 16;
    D_0024F6AA[0] = ((u32)D_0024FE30) & 0xFFFF;
    if (D_0024F6AC[0] != 0x16) {
        printf((const char *)D_00279F80);
    }
    D_0024F6AC[0] = ((u32)D_0024FED0) >> 16;
    D_0024F6AE[0] = ((u32)D_0024FED0) & 0xFFFF;
    if (D_0024F6B0[0] != 0x18) {
        printf((const char *)D_00279FA0);
    }
    D_0024F6B0[0] = ((u32)D_00250260) >> 16;
    D_0024F6B2[0] = ((u32)D_00250260) & 0xFFFF;
    if (D_0024F6B4[0] != 0x1a) {
        printf((const char *)D_00279FC0);
    }
    D_0024F6B4[0] = ((u32)D_002502C0) >> 16;
    D_0024F6B6[0] = ((u32)D_002502C0) & 0xFFFF;
    if (D_0024F6B8[0] != 0x1c) {
        printf((const char *)D_00279FE0);
    }
    D_0024F6B8[0] = ((u32)D_002502F0) >> 16;
    D_0024F6BA[0] = ((u32)D_002502F0) & 0xFFFF;
    if (D_0024F6BC[0] != 0x1e) {
        printf((const char *)D_0027A000);
    }
    D_0024F6BC[0] = ((u32)D_002503A0) >> 16;
    D_0024F6BE[0] = ((u32)D_002503A0) & 0xFFFF;
    if (D_0024F6C0[0] != 0x20) {
        printf((const char *)D_0027A020);
    }
    D_0024F6C0[0] = ((u32)D_002503F0) >> 16;
    D_0024F6C2[0] = ((u32)D_002503F0) & 0xFFFF;
    if (D_0024F6C4[0] != 0x22) {
        printf((const char *)D_0027A040);
    }
    D_0024F6C4[0] = ((u32)D_00250490) >> 16;
    D_0024F6C6[0] = ((u32)D_00250490) & 0xFFFF;
    if (D_0024F6C8[0] != 0x24) {
        printf((const char *)D_0027A060);
    }
    D_0024F6C8[0] = ((u32)D_002504D0) >> 16;
    D_0024F6CA[0] = ((u32)D_002504D0) & 0xFFFF;
    if (D_0024F6CC[0] != 0x26) {
        printf((const char *)D_0027A080);
    }
    D_0024F6CC[0] = ((u32)D_00250570) >> 16;
    D_0024F6CE[0] = ((u32)D_00250570) & 0xFFFF;
    if (D_0024F6D0[0] != 0x28) {
        printf((const char *)D_0027A0A0);
    }
    D_0024F6D0[0] = ((u32)D_00250260) >> 16;
    D_0024F6D2[0] = ((u32)D_00250260) & 0xFFFF;
    if (D_0024F6D4[0] != 0x2a) {
        printf((const char *)D_0027A0C0);
    }
    D_0024F6D4[0] = ((u32)D_002502C0) >> 16;
    D_0024F6D6[0] = ((u32)D_002502C0) & 0xFFFF;
    if (D_0024F6D8[0] != 0x2c) {
        printf((const char *)D_0027A0E0);
    }
    D_0024F6D8[0] = ((u32)D_002502F0) >> 16;
    D_0024F6DA[0] = ((u32)D_002502F0) & 0xFFFF;
    if (D_0024F6DC[0] != 0x2e) {
        printf((const char *)D_0027A100);
    }
    D_0024F6DC[0] = ((u32)D_002503A0) >> 16;
    D_0024F6DE[0] = ((u32)D_002503A0) & 0xFFFF;
    if (D_0024F6E0[0] != 0x30) {
        printf((const char *)D_0027A120);
    }
    D_0024F6E0[0] = ((u32)D_002503F0) >> 16;
    D_0024F6E2[0] = ((u32)D_002503F0) & 0xFFFF;
    if (D_0024F6E4[0] != 0x32) {
        printf((const char *)D_0027A140);
    }
    D_0024F6E4[0] = ((u32)D_00250490) >> 16;
    D_0024F6E6[0] = ((u32)D_00250490) & 0xFFFF;
    if (D_0024F6E8[0] != 0x34) {
        printf((const char *)D_0027A160);
    }
    D_0024F6E8[0] = ((u32)D_002504D0) >> 16;
    D_0024F6EA[0] = ((u32)D_002504D0) & 0xFFFF;
    if (D_0024F6EC[0] != 0x36) {
        printf((const char *)D_0027A180);
    }
    D_0024F6EC[0] = ((u32)D_00250570) >> 16;
    D_0024F6EE[0] = ((u32)D_00250570) & 0xFFFF;
    if (D_0024F6F0[0] != 0x38) {
        printf((const char *)D_0027A1A0);
    }
    D_0024F6F0[0] = ((u32)D_002505C0) >> 16;
    D_0024F6F2[0] = ((u32)D_002505C0) & 0xFFFF;
    if (D_0024F6F4[0] != 0x3a) {
        printf((const char *)D_0027A1C0);
    }
    D_0024F6F4[0] = ((u32)D_00250600) >> 16;
    D_0024F6F6[0] = ((u32)D_00250600) & 0xFFFF;
    if (D_0024F6F8[0] != 0x3c) {
        printf((const char *)D_0027A1E0);
    }
    D_0024F6F8[0] = ((u32)D_00250620) >> 16;
    D_0024F6FA[0] = ((u32)D_00250620) & 0xFFFF;
    if (D_0024F6FC[0] != 0x3e) {
        printf((const char *)D_0027A200);
    }
    D_0024F6FC[0] = ((u32)D_002506B0) >> 16;
    D_0024F6FE[0] = ((u32)D_002506B0) & 0xFFFF;
    if (D_0024F700[0] != 0x40) {
        printf((const char *)D_0027A220);
    }
    D_0024F700[0] = ((u32)D_002506F0) >> 16;
    D_0024F702[0] = ((u32)D_002506F0) & 0xFFFF;
    if (D_0024F704[0] != 0x42) {
        printf((const char *)D_0027A240);
    }
    D_0024F704[0] = ((u32)D_00250740) >> 16;
    D_0024F706[0] = ((u32)D_00250740) & 0xFFFF;
    if (D_0024F708[0] != 0x44) {
        printf((const char *)D_0027A260);
    }
    D_0024F708[0] = ((u32)D_0024F7F0) >> 16;
    D_0024F70A[0] = ((u32)D_0024F7F0) & 0xFFFF;
    if (D_0024F70C[0] != 0x46) {
        printf((const char *)D_0027A280);
    }
    D_0024F70C[0] = ((u32)D_0024F850) >> 16;
    D_0024F70E[0] = ((u32)D_0024F850) & 0xFFFF;
    if (D_0024F710[0] != 0x48) {
        printf((const char *)D_0027A2A0);
    }
    D_0024F710[0] = ((u32)D_0024F8D0) >> 16;
    D_0024F712[0] = ((u32)D_0024F8D0) & 0xFFFF;
    if (D_0024F714[0] != 0x4a) {
        printf((const char *)D_0027A2C0);
    }
    D_0024F714[0] = ((u32)D_0024F930) >> 16;
    D_0024F716[0] = ((u32)D_0024F930) & 0xFFFF;
    if (D_0024F718[0] != 0x4c) {
        printf((const char *)D_0027A2E0);
    }
    D_0024F718[0] = ((u32)D_0024F9B0) >> 16;
    D_0024F71A[0] = ((u32)D_0024F9B0) & 0xFFFF;
    if (D_0024F71C[0] != 0x4e) {
        printf((const char *)D_0027A300);
    }
    D_0024F71C[0] = ((u32)D_0024FA10) >> 16;
    D_0024F71E[0] = ((u32)D_0024FA10) & 0xFFFF;
    if (D_0024F720[0] != 0x50) {
        printf((const char *)D_0027A320);
    }
    D_0024F720[0] = ((u32)D_0024FAE0) >> 16;
    D_0024F722[0] = ((u32)D_0024FAE0) & 0xFFFF;
    if (D_0024F724[0] != 0x52) {
        printf((const char *)D_0027A340);
    }
    D_0024F724[0] = ((u32)D_0024FB70) >> 16;
    D_0024F726[0] = ((u32)D_0024FB70) & 0xFFFF;
    if (D_0024F728[0] != 0x54) {
        printf((const char *)D_0027A360);
    }
    D_0024F728[0] = ((u32)D_0024FC70) >> 16;
    D_0024F72A[0] = ((u32)D_0024FC70) & 0xFFFF;
    if (D_0024F72C[0] != 0x56) {
        printf((const char *)D_0027A380);
    }
    D_0024F72C[0] = ((u32)D_0024FD10) >> 16;
    D_0024F72E[0] = ((u32)D_0024FD10) & 0xFFFF;
    if (D_0024F730[0] != 0x58) {
        printf((const char *)D_0027A3A0);
    }
    D_0024F730[0] = ((u32)D_0024FE30) >> 16;
    D_0024F732[0] = ((u32)D_0024FE30) & 0xFFFF;
    if (D_0024F734[0] != 0x5a) {
        printf((const char *)D_0027A3C0);
    }
    D_0024F734[0] = ((u32)D_0024FED0) >> 16;
    D_0024F736[0] = ((u32)D_0024FED0) & 0xFFFF;
    if (D_0024F738[0] != 0x5c) {
        printf((const char *)D_0027A3E0);
    }
    D_0024F738[0] = ((u32)D_00250260) >> 16;
    D_0024F73A[0] = ((u32)D_00250260) & 0xFFFF;
    if (D_0024F73C[0] != 0x5e) {
        printf((const char *)D_0027A400);
    }
    D_0024F73C[0] = ((u32)D_002502C0) >> 16;
    D_0024F73E[0] = ((u32)D_002502C0) & 0xFFFF;
    if (D_0024F740[0] != 0x60) {
        printf((const char *)D_0027A420);
    }
    D_0024F740[0] = ((u32)D_002502F0) >> 16;
    D_0024F742[0] = ((u32)D_002502F0) & 0xFFFF;
    if (D_0024F744[0] != 0x62) {
        printf((const char *)D_0027A440);
    }
    D_0024F744[0] = ((u32)D_002503A0) >> 16;
    D_0024F746[0] = ((u32)D_002503A0) & 0xFFFF;
    if (D_0024F748[0] != 0x64) {
        printf((const char *)D_0027A460);
    }
    D_0024F748[0] = ((u32)D_002503F0) >> 16;
    D_0024F74A[0] = ((u32)D_002503F0) & 0xFFFF;
    if (D_0024F74C[0] != 0x66) {
        printf((const char *)D_0027A480);
    }
    D_0024F74C[0] = ((u32)D_00250490) >> 16;
    D_0024F74E[0] = ((u32)D_00250490) & 0xFFFF;
    if (D_0024F750[0] != 0x68) {
        printf((const char *)D_0027A4A0);
    }
    D_0024F750[0] = ((u32)D_002504D0) >> 16;
    D_0024F752[0] = ((u32)D_002504D0) & 0xFFFF;
    if (D_0024F754[0] != 0x6a) {
        printf((const char *)D_0027A4C0);
    }
    D_0024F754[0] = ((u32)D_00250570) >> 16;
    D_0024F756[0] = ((u32)D_00250570) & 0xFFFF;
    if (D_0024F758[0] != 0x6c) {
        printf((const char *)D_0027A4E0);
    }
    D_0024F758[0] = ((u32)D_00250260) >> 16;
    D_0024F75A[0] = ((u32)D_00250260) & 0xFFFF;
    if (D_0024F75C[0] != 0x6e) {
        printf((const char *)D_0027A500);
    }
    D_0024F75C[0] = ((u32)D_002502C0) >> 16;
    D_0024F75E[0] = ((u32)D_002502C0) & 0xFFFF;
    if (D_0024F760[0] != 0x70) {
        printf((const char *)D_0027A520);
    }
    D_0024F760[0] = ((u32)D_002502F0) >> 16;
    D_0024F762[0] = ((u32)D_002502F0) & 0xFFFF;
    if (D_0024F764[0] != 0x72) {
        printf((const char *)D_0027A540);
    }
    D_0024F764[0] = ((u32)D_002503A0) >> 16;
    D_0024F766[0] = ((u32)D_002503A0) & 0xFFFF;
    if (D_0024F768[0] != 0x74) {
        printf((const char *)D_0027A560);
    }
    D_0024F768[0] = ((u32)D_002503F0) >> 16;
    D_0024F76A[0] = ((u32)D_002503F0) & 0xFFFF;
    if (D_0024F76C[0] != 0x76) {
        printf((const char *)D_0027A580);
    }
    D_0024F76C[0] = ((u32)D_00250490) >> 16;
    D_0024F76E[0] = ((u32)D_00250490) & 0xFFFF;
    if (D_0024F770[0] != 0x78) {
        printf((const char *)D_0027A5A0);
    }
    D_0024F770[0] = ((u32)D_002504D0) >> 16;
    D_0024F772[0] = ((u32)D_002504D0) & 0xFFFF;
    if (D_0024F774[0] != 0x7a) {
        printf((const char *)D_0027A5C0);
    }
    D_0024F774[0] = ((u32)D_00250570) >> 16;
    D_0024F776[0] = ((u32)D_00250570) & 0xFFFF;
    if (D_0024F778[0] != 0x7c) {
        printf((const char *)D_0027A5E0);
    }
    D_0024F778[0] = ((u32)D_002505C0) >> 16;
    D_0024F77A[0] = ((u32)D_002505C0) & 0xFFFF;
    if (D_0024F77C[0] != 0x7e) {
        printf((const char *)D_0027A600);
    }
    D_0024F77C[0] = ((u32)D_00250600) >> 16;
    D_0024F77E[0] = ((u32)D_00250600) & 0xFFFF;
    if (D_0024F780[0] != 0x80) {
        printf((const char *)D_0027A620);
    }
    D_0024F780[0] = ((u32)D_00250620) >> 16;
    D_0024F782[0] = ((u32)D_00250620) & 0xFFFF;
    if (D_0024F784[0] != 0x82) {
        printf((const char *)D_0027A640);
    }
    D_0024F784[0] = ((u32)D_002506B0) >> 16;
    D_0024F786[0] = ((u32)D_002506B0) & 0xFFFF;
    if (D_0024F788[0] != 0x84) {
        printf((const char *)D_0027A660);
    }
    D_0024F788[0] = ((u32)D_002506F0) >> 16;
    D_0024F78A[0] = ((u32)D_002506F0) & 0xFFFF;
    if (D_0024F78C[0] != 0x86) {
        printf((const char *)D_0027A680);
    }
    D_0024F78C[0] = ((u32)D_00250740) >> 16;
    D_0024F78E[0] = ((u32)D_00250740) & 0xFFFF;
    if (D_00250A86[0] != 0x3) {
        printf((const char *)D_0027A6A0);
    }
    D_00250A86[0] = ((u32)D_00250A00) >> 16;
    D_00250A88[0] = ((u32)D_00250A00) & 0xFFFF;
    if (D_00250B16[0] != 0x3) {
        printf((const char *)D_0027A6C0);
    }
    D_00250B16[0] = ((u32)D_00250A90) >> 16;
    D_00250B18[0] = ((u32)D_00250A90) & 0xFFFF;
    if (D_00250BA6[0] != 0x3) {
        printf((const char *)D_0027A6E0);
    }
    D_00250BA6[0] = ((u32)D_00250B20) >> 16;
    D_00250BA8[0] = ((u32)D_00250B20) & 0xFFFF;
    if (D_00250C36[0] != 0x3) {
        printf((const char *)D_0027A700);
    }
    D_00250C36[0] = ((u32)D_00250BB0) >> 16;
    D_00250C38[0] = ((u32)D_00250BB0) & 0xFFFF;
    if (D_00250CC6[0] != 0x3) {
        printf((const char *)D_0027A720);
    }
    D_00250CC6[0] = ((u32)D_00250C40) >> 16;
    D_00250CC8[0] = ((u32)D_00250C40) & 0xFFFF;
    if (D_00250CD0_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027A740);
    }
    D_00250CD0_as_u16_a[0] = ((u32)D_00250A00) >> 16;
    D_00250CD2[0] = ((u32)D_00250A00) & 0xFFFF;
    if (D_00250CD4[0] != 0x2) {
        printf((const char *)D_0027A760);
    }
    D_00250CD4[0] = ((u32)D_00250B20) >> 16;
    D_00250CD6[0] = ((u32)D_00250B20) & 0xFFFF;
    if (D_00250CD8[0] != 0x4) {
        printf((const char *)D_0027A780);
    }
    D_00250CD8[0] = ((u32)D_00250BB0) >> 16;
    D_00250CDA[0] = ((u32)D_00250BB0) & 0xFFFF;
    if (D_00250CDC[0] != 0x6) {
        printf((const char *)D_0027A7A0);
    }
    D_00250CDC[0] = ((u32)D_00250C40) >> 16;
    D_00250CDE[0] = ((u32)D_00250C40) & 0xFFFF;
    if (D_00250D40[0] != 0x8) {
        printf((const char *)D_0027A7C0);
    }
    D_00250D40[0] = ((u32)D_00250DA0) >> 16;
    D_00250D42[0] = ((u32)D_00250DA0) & 0xFFFF;
    if (D_00250D60[0] != 0x8) {
        printf((const char *)D_0027A7E0);
    }
    D_00250D60[0] = ((u32)D_00250DC0) >> 16;
    D_00250D62[0] = ((u32)D_00250DC0) & 0xFFFF;
    if (D_00250D80[0] != 0x8) {
        printf((const char *)D_0027A800);
    }
    D_00250D80[0] = ((u32)D_00250DE0) >> 16;
    D_00250D82[0] = ((u32)D_00250DE0) & 0xFFFF;
    if (D_00250E10[0] != 0x8) {
        printf((const char *)D_0027A820);
    }
    D_00250E10[0] = ((u32)D_00250E20) >> 16;
    D_00250E12[0] = ((u32)D_00250E20) & 0xFFFF;
    if (D_00250F50[0] != 0x8) {
        printf((const char *)D_0027A840);
    }
    D_00250F50[0] = ((u32)D_00250EB0) >> 16;
    D_00250F52[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00250F70[0] != 0x8) {
        printf((const char *)D_0027A860);
    }
    D_00250F70[0] = ((u32)D_00250EB0) >> 16;
    D_00250F72[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00250F90[0] != 0x8) {
        printf((const char *)D_0027A880);
    }
    D_00250F90[0] = ((u32)D_00250EB0) >> 16;
    D_00250F92[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00250FB0[0] != 0x8) {
        printf((const char *)D_0027A8A0);
    }
    D_00250FB0[0] = ((u32)D_00250EB0) >> 16;
    D_00250FB2[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00250FD0[0] != 0x8) {
        printf((const char *)D_0027A8C0);
    }
    D_00250FD0[0] = ((u32)D_00250EB0) >> 16;
    D_00250FD2[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00250FF0[0] != 0x8) {
        printf((const char *)D_0027A8E0);
    }
    D_00250FF0[0] = ((u32)D_00250EB0) >> 16;
    D_00250FF2[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00251010[0] != 0x8) {
        printf((const char *)D_0027A900);
    }
    D_00251010[0] = ((u32)D_00250EB0) >> 16;
    D_00251012[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00251030[0] != 0x8) {
        printf((const char *)D_0027A920);
    }
    D_00251030[0] = ((u32)D_00250EB0) >> 16;
    D_00251032[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00251050[0] != 0x8) {
        printf((const char *)D_0027A940);
    }
    D_00251050[0] = ((u32)D_00250EB0) >> 16;
    D_00251052[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00251070[0] != 0x8) {
        printf((const char *)D_0027A960);
    }
    D_00251070[0] = ((u32)D_00250EB0) >> 16;
    D_00251072[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00251090[0] != 0x8) {
        printf((const char *)D_0027A980);
    }
    D_00251090[0] = ((u32)D_00250EB0) >> 16;
    D_00251092[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_002510B0[0] != 0x8) {
        printf((const char *)D_0027A9A0);
    }
    D_002510B0[0] = ((u32)D_00250EB0) >> 16;
    D_002510B2[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_002510D0[0] != 0x8) {
        printf((const char *)D_0027A9C0);
    }
    D_002510D0[0] = ((u32)D_00250EB0) >> 16;
    D_002510D2[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_002510F0[0] != 0x8) {
        printf((const char *)D_0027A9E0);
    }
    D_002510F0[0] = ((u32)D_00250EB0) >> 16;
    D_002510F2[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00251110[0] != 0x8) {
        printf((const char *)D_0027AA00);
    }
    D_00251110[0] = ((u32)D_00250EB0) >> 16;
    D_00251112[0] = ((u32)D_00250EB0) & 0xFFFF;
    if (D_00251690[0] != 0x8) {
        printf((const char *)D_0027AA20);
    }
    D_00251690[0] = ((u32)D_002515C0) >> 16;
    D_00251692[0] = ((u32)D_002515C0) & 0xFFFF;
    if (D_00251694[0] != 0xa) {
        printf((const char *)D_0027AA40);
    }
    D_00251694[0] = ((u32)D_002515D0) >> 16;
    D_00251696[0] = ((u32)D_002515D0) & 0xFFFF;
    if (D_00251698[0] != 0xc) {
        printf((const char *)D_0027AA60);
    }
    D_00251698[0] = ((u32)D_002515E0) >> 16;
    D_0025169A[0] = ((u32)D_002515E0) & 0xFFFF;
    D_002516B0[0] = ((u32)D_002515F0) >> 16;
    D_002516B2[0] = ((u32)D_002515F0) & 0xFFFF;
    if (D_002516B4[0] != 0xa) {
        printf((const char *)D_0027AA80);
    }
    D_002516B4[0] = ((u32)D_00251600) >> 16;
    D_002516B6[0] = ((u32)D_00251600) & 0xFFFF;
    if (D_002516B8[0] != 0xc) {
        printf((const char *)D_0027AAA0);
    }
    D_002516B8[0] = ((u32)D_00251610) >> 16;
    D_002516BA[0] = ((u32)D_00251610) & 0xFFFF;
    if (D_002516D0[0] != 0x8) {
        printf((const char *)D_0027AAC0);
    }
    D_002516D0[0] = ((u32)D_00251620) >> 16;
    D_002516D2[0] = ((u32)D_00251620) & 0xFFFF;
    if (D_002516D4[0] != 0xa) {
        printf((const char *)D_0027AAE0);
    }
    D_002516D4[0] = ((u32)D_00251630) >> 16;
    D_002516D6[0] = ((u32)D_00251630) & 0xFFFF;
    if (D_002516D8[0] != 0xc) {
        printf((const char *)D_0027AB00);
    }
    D_002516D8[0] = ((u32)D_00251640) >> 16;
    D_002516DA[0] = ((u32)D_00251640) & 0xFFFF;
    if (D_002516F0[0] != 0x8) {
        printf((const char *)D_0027AB20);
    }
    D_002516F0[0] = ((u32)D_00251650) >> 16;
    D_002516F2[0] = ((u32)D_00251650) & 0xFFFF;
    if (D_002516F4[0] != 0xa) {
        printf((const char *)D_0027AB40);
    }
    D_002516F4[0] = ((u32)D_00251660) >> 16;
    D_002516F6[0] = ((u32)D_00251660) & 0xFFFF;
    if (D_002516F8[0] != 0xc) {
        printf((const char *)D_0027AB60);
    }
    D_002516F8[0] = ((u32)D_00251670) >> 16;
    D_002516FA[0] = ((u32)D_00251670) & 0xFFFF;
    if (D_0024D0B8[0] != 0x4) {
        printf((const char *)D_0027AB80);
    }
    D_0024D0B8[0] = ((u32)D_0024D030_as_u16_a) >> 16;
    D_0024D0BA[0] = ((u32)D_0024D030_as_u16_a) & 0xFFFF;
    if (D_0024D0C6[0] != 0xb) {
        printf((const char *)D_0027ABA0);
    }
    D_0024D0C6[0] = ((u32)D_002624F0) >> 16;
    D_0024D0C8[0] = ((u32)D_002624F0) & 0xFFFF;
    if (D_0024D0D4[0] != 0x12) {
        printf((const char *)D_0027ABC0);
    }
    D_0024D0D4[0] = ((u32)D_00262530) >> 16;
    D_0024D0D6[0] = ((u32)D_00262530) & 0xFFFF;
    if (D_0024D238[0] != 0x4) {
        printf((const char *)D_0027ABE0);
    }
    D_0024D238[0] = ((u32)D_002624F0) >> 16;
    D_0024D23A[0] = ((u32)D_002624F0) & 0xFFFF;
    if (D_0024D246[0] != 0xb) {
        printf((const char *)D_0027AC00);
    }
    D_0024D246[0] = ((u32)D_00262530) >> 16;
    D_0024D248[0] = ((u32)D_00262530) & 0xFFFF;
    if (D_0024D258[0] != 0x4) {
        printf((const char *)D_0027AC20);
    }
    D_0024D258[0] = ((u32)D_002624F0) >> 16;
    D_0024D25A[0] = ((u32)D_002624F0) & 0xFFFF;
    if (D_0024D266[0] != 0xb) {
        printf((const char *)D_0027AC40);
    }
    D_0024D266[0] = ((u32)D_00262530) >> 16;
    D_0024D268[0] = ((u32)D_00262530) & 0xFFFF;
    if (D_0024D278[0] != 0x4) {
        printf((const char *)D_0027AC60);
    }
    D_0024D278[0] = ((u32)D_002624F0) >> 16;
    D_0024D27A[0] = ((u32)D_002624F0) & 0xFFFF;
    if (D_0024D286[0] != 0xb) {
        printf((const char *)D_0027AC80);
    }
    D_0024D286[0] = ((u32)D_00262530) >> 16;
    D_0024D288[0] = ((u32)D_00262530) & 0xFFFF;
    if (D_0024D298[0] != 0x4) {
        printf((const char *)D_0027ACA0);
    }
    D_0024D298[0] = ((u32)D_002624F0) >> 16;
    D_0024D29A[0] = ((u32)D_002624F0) & 0xFFFF;
    if (D_0024D2A6[0] != 0xb) {
        printf((const char *)D_0027ACC0);
    }
    D_0024D2A6[0] = ((u32)D_00262530) >> 16;
    D_0024D2A8[0] = ((u32)D_00262530) & 0xFFFF;
    if (D_0024D2B8[0] != 0x4) {
        printf((const char *)D_0027ACE0);
    }
    D_0024D2B8[0] = ((u32)D_002624F0) >> 16;
    D_0024D2BA[0] = ((u32)D_002624F0) & 0xFFFF;
    if (D_0024D2C6[0] != 0xb) {
        printf((const char *)D_0027AD00);
    }
    D_0024D2C6[0] = ((u32)D_00262530) >> 16;
    D_0024D2C8[0] = ((u32)D_00262530) & 0xFFFF;
    if (D_0024E2E6[0] != 0x3) {
        printf((const char *)D_0027AD20);
    }
    D_0024E2E6[0] = ((u32)D_0028C0A0) >> 16;
    D_0024E2E8[0] = ((u32)D_0028C0A0) & 0xFFFF;
    if (D_0024E2F0[0] != 0x8) {
        printf((const char *)D_0027AD40);
    }
    D_0024E2F0[0] = ((u32)D_0024E0A0) >> 16;
    D_0024E2F2[0] = ((u32)D_0024E0A0) & 0xFFFF;
    if (D_0024E2FA[0] != 0xd) {
        printf((const char *)D_0027AD60);
    }
    D_0024E2FA[0] = ((u32)D_0024E0B0) >> 16;
    D_0024E2FC[0] = ((u32)D_0024E0B0) & 0xFFFF;
    if (D_0024E304[0] != 0x12) {
        printf((const char *)D_0027AD80);
    }
    D_0024E304[0] = ((u32)D_0024E0C0) >> 16;
    D_0024E306[0] = ((u32)D_0024E0C0) & 0xFFFF;
    if (D_0024E30E[0] != 0x17) {
        printf((const char *)D_0027ADA0);
    }
    D_0024E30E[0] = ((u32)D_0024E0D0) >> 16;
    D_0024E310[0] = ((u32)D_0024E0D0) & 0xFFFF;
    if (D_0024E318[0] != 0x1c) {
        printf((const char *)D_0027ADC0);
    }
    D_0024E318[0] = ((u32)D_0024E0E0) >> 16;
    D_0024E31A[0] = ((u32)D_0024E0E0) & 0xFFFF;
    if (D_0024E322[0] != 0x21) {
        printf((const char *)D_0027ADE0);
    }
    D_0024E322[0] = ((u32)D_0024E0D0) >> 16;
    D_0024E324[0] = ((u32)D_0024E0D0) & 0xFFFF;
    if (D_0024E32C[0] != 0x26) {
        printf((const char *)D_0027AE00);
    }
    D_0024E32C[0] = ((u32)D_0024E0F8) >> 16;
    D_0024E32E[0] = ((u32)D_0024E0F8) & 0xFFFF;
    if (D_0024E336[0] != 0x2b) {
        printf((const char *)D_0027AE20);
    }
    D_0024E336[0] = ((u32)D_0024E110) >> 16;
    D_0024E338[0] = ((u32)D_0024E110) & 0xFFFF;
    if (D_0024E340[0] != 0x30) {
        printf((const char *)D_0027AE40);
    }
    D_0024E340[0] = ((u32)D_0024E140) >> 16;
    D_0024E342[0] = ((u32)D_0024E140) & 0xFFFF;
    if (D_0024E34A[0] != 0x35) {
        printf((const char *)D_0027AE60);
    }
    D_0024E34A[0] = ((u32)D_0024E150) >> 16;
    D_0024E34C[0] = ((u32)D_0024E150) & 0xFFFF;
    if (D_0024E354[0] != 0x3a) {
        printf((const char *)D_0027AE80);
    }
    D_0024E354[0] = ((u32)D_0024E170) >> 16;
    D_0024E356[0] = ((u32)D_0024E170) & 0xFFFF;
    if (D_0024E35E[0] != 0x3f) {
        printf((const char *)D_0027AEA0);
    }
    D_0024E35E[0] = ((u32)D_0024E188) >> 16;
    D_0024E360[0] = ((u32)D_0024E188) & 0xFFFF;
    if (D_0024E368[0] != 0x44) {
        printf((const char *)D_0027AEC0);
    }
    D_0024E368[0] = ((u32)D_0024E1A0) >> 16;
    D_0024E36A[0] = ((u32)D_0024E1A0) & 0xFFFF;
    if (D_0024E372[0] != 0x49) {
        printf((const char *)D_0027AEE0);
    }
    D_0024E372[0] = ((u32)D_0024E150) >> 16;
    D_0024E374[0] = ((u32)D_0024E150) & 0xFFFF;
    if (D_0024E37C[0] != 0x4e) {
        printf((const char *)D_0027AF00);
    }
    D_0024E37C[0] = ((u32)D_0024E1B8) >> 16;
    D_0024E37E[0] = ((u32)D_0024E1B8) & 0xFFFF;
    if (D_0024E386[0] != 0x53) {
        printf((const char *)D_0027AF20);
    }
    D_0024E386[0] = ((u32)D_0024E1C8) >> 16;
    D_0024E388[0] = ((u32)D_0024E1C8) & 0xFFFF;
    if (D_0024E390[0] != 0x58) {
        printf((const char *)D_0027AF40);
    }
    D_0024E390[0] = ((u32)D_0024E1E0) >> 16;
    D_0024E392[0] = ((u32)D_0024E1E0) & 0xFFFF;
    if (D_0024E39A[0] != 0x5d) {
        printf((const char *)D_0027AF60);
    }
    D_0024E39A[0] = ((u32)D_0024E1C8) >> 16;
    D_0024E39C[0] = ((u32)D_0024E1C8) & 0xFFFF;
    if (D_0024E3A4[0] != 0x62) {
        printf((const char *)D_0027AF80);
    }
    D_0024E3A4[0] = ((u32)D_0024E188) >> 16;
    D_0024E3A6[0] = ((u32)D_0024E188) & 0xFFFF;
    if (D_0024E3AE[0] != 0x67) {
        printf((const char *)D_0027AFA0);
    }
    D_0024E3AE[0] = ((u32)D_0024E200) >> 16;
    D_0024E3B0[0] = ((u32)D_0024E200) & 0xFFFF;
    if (D_0024E3B8[0] != 0x6c) {
        printf((const char *)D_0027AFC0);
    }
    D_0024E3B8[0] = ((u32)D_0024E188) >> 16;
    D_0024E3BA[0] = ((u32)D_0024E188) & 0xFFFF;
    if (D_0024E3C2[0] != 0x71) {
        printf((const char *)D_0027AFE0);
    }
    D_0024E3C2[0] = ((u32)D_0024E210) >> 16;
    D_0024E3C4[0] = ((u32)D_0024E210) & 0xFFFF;
    if (D_0024E3CC[0] != 0x76) {
        printf((const char *)D_0027B000);
    }
    D_0024E3CC[0] = ((u32)D_0024E220) >> 16;
    D_0024E3CE[0] = ((u32)D_0024E220) & 0xFFFF;
    if (D_0024E3D6[0] != 0x7b) {
        printf((const char *)D_0027B020);
    }
    D_0024E3D6[0] = ((u32)D_0024E2B0) >> 16;
    D_0024E3D8[0] = ((u32)D_0024E2B0) & 0xFFFF;
    if (D_0024E3E0[0] != 0x80) {
        printf((const char *)D_0027B040);
    }
    D_0024E3E0[0] = ((u32)D_0024E130) >> 16;
    D_0024E3E2[0] = ((u32)D_0024E130) & 0xFFFF;
    if (D_0024E3EA[0] != 0x85) {
        printf((const char *)D_0027B060);
    }
    D_0024E3EA[0] = ((u32)D_0024E230) >> 16;
    D_0024E3EC[0] = ((u32)D_0024E230) & 0xFFFF;
    if (D_0024E3F4[0] != 0x8a) {
        printf((const char *)D_0027B080);
    }
    D_0024E3F4[0] = ((u32)D_0024E240) >> 16;
    D_0024E3F6[0] = ((u32)D_0024E240) & 0xFFFF;
    if (D_0024E3FE[0] != 0x8f) {
        printf((const char *)D_0027B0A0);
    }
    D_0024E3FE[0] = ((u32)D_0024E250) >> 16;
    D_0024E400[0] = ((u32)D_0024E250) & 0xFFFF;
    if (D_0024E408[0] != 0x94) {
        printf((const char *)D_0027B0C0);
    }
    D_0024E408[0] = ((u32)D_0024E260) >> 16;
    D_0024E40A[0] = ((u32)D_0024E260) & 0xFFFF;
    if (D_0024E412[0] != 0x99) {
        printf((const char *)D_0027B0E0);
    }
#ifdef DEATH_LABEL
    D_0024E412[0] = ((u32)D_0024E2C8) >> 16;
    D_0024E414[0] = ((u32)D_0024E2C8) & 0xFFFF;
    D_0024E41C[0] = ((u32)death_D_00254748) >> 16;
    D_0024E41E[0] = ((u32)death_D_00254748) & 0xFFFF;
    D_0024E426[0] = ((u32)death_D_00254758) >> 16;
    D_0024E428[0] = ((u32)death_D_00254758) & 0xFFFF;
    D_0024E430[0] = ((u32)death_D_00254768) >> 16;
    D_0024E432[0] = ((u32)death_D_00254768) & 0xFFFF;
    death_D_0025495A[0] = ((u32)death_D_00254778) >> 16;
    death_D_0025495C[0] = ((u32)death_D_00254778) & 0xFFFF;
    death_D_00254964[0] = ((u32)death_D_00254790) >> 16;
    death_D_00254966[0] = ((u32)death_D_00254790) & 0xFFFF;
    death_D_0025496E[0] = ((u32)death_D_002547A0) >> 16;
    death_D_00254970[0] = ((u32)death_D_002547A0) & 0xFFFF;
    death_D_00254978[0] = ((u32)death_D_002547B0) >> 16;
    death_D_0025497A[0] = ((u32)death_D_002547B0) & 0xFFFF;
    death_D_00254982[0] = ((u32)death_D_002547C0) >> 16;
    death_D_00254984[0] = ((u32)death_D_002547C0) & 0xFFFF;
#else
    D_0024E412[0] = ((u32)D_0024E2C8) >> 16;
    D_0024E414[0] = ((u32)D_0024E2C8) & 0xFFFF;
    D_0024E41C[0] = ((u32)D_0024E280) >> 16;
    D_0024E41E[0] = ((u32)D_0024E280) & 0xFFFF;
    D_0024E426[0] = ((u32)D_0024E290) >> 16;
    D_0024E428[0] = ((u32)D_0024E290) & 0xFFFF;
    D_0024E430[0] = ((u32)D_0024E2A0) >> 16;
    D_0024E432[0] = ((u32)D_0024E2A0) & 0xFFFF;
#endif
    if (D_002526D0_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027B100);
    }
    reg_tmp.w = (u32)func_0014CC90;
    D_002526D0_as_u16_a[0] = reg_tmp.h[1];
    D_002526D2[0] = reg_tmp.h[0];
    if (D_002526D4[0] != 0x2) {
        printf((const char *)D_0027B120);
    }
    STORE_POINTER(D_002526D4, func_0014CD70);
    if (D_002526D8[0] != 0x4) {
        printf((const char *)D_0027B140);
    }
    STORE_POINTER(D_002526D8, func_0014CEA0);
    if (D_002526DC[0] != 0x6) {
        printf((const char *)D_0027B160);
    }
    STORE_POINTER(D_002526DC, func_0014CEE0);
    if (D_002526E0[0] != 0x8) {
        printf((const char *)D_0027B180);
    }
    STORE_POINTER(D_002526E0, func_0014CF10);
    if (D_002526E4[0] != 0xa) {
        printf((const char *)D_0027B1A0);
    }
    STORE_POINTER(D_002526E4, func_0014CF90);
    if (D_002526E8[0] != 0xc) {
        printf((const char *)D_0027B1C0);
    }
    STORE_POINTER(D_002526E8, func_0014D170);
    if (D_002526F0_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027B1E0);
    }
    reg_tmp.w = (u32)func_0014D0F0;
    D_002526F0_as_u16_a[0] = reg_tmp.h[1];
    D_002526F2[0] = reg_tmp.h[0];
    if (D_002526F4[0] != 0x2) {
        printf((const char *)D_0027B200);
    }
    STORE_POINTER(D_002526F4, func_0014D140);
    if (D_002526F8[0] != 0x4) {
        printf((const char *)D_0027B220);
    }
    STORE_POINTER(D_002526F8, func_0014D150);
    if (D_00252700_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027B240);
    }
    reg_tmp.w = (u32)D_00244070;
    D_00252700_as_u16_a[0] = reg_tmp.h[1];
    D_00252702[0] = reg_tmp.h[0];
    if (D_00252704[0] != 0x2) {
        printf((const char *)D_0027B260);
    }
    STORE_POINTER(D_00252704, D_002461D0);
    if (D_00252708[0] != 0x4) {
        printf((const char *)D_0027B280);
    }
    STORE_POINTER(D_00252708, D_00247080);
    if (D_0025270C[0] != 0x6) {
        printf((const char *)D_0027B2A0);
    }
    STORE_POINTER(D_0025270C, D_00249610);
    if (D_00252710[0] != 0x8) {
        printf((const char *)D_0027B2C0);
    }
    STORE_POINTER(D_00252710, D_0024C240);
    if (D_00252720_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027B2E0);
    }
    reg_tmp.w = (u32)D_002420F0;
    D_00252720_as_u16_a[0] = reg_tmp.h[1];
    D_00252722[0] = reg_tmp.h[0];
    if (D_00252724[0] != 0x2) {
        printf((const char *)D_0027B300);
    }
    STORE_POINTER(D_00252724, D_00244A30);
    if (D_00252728[0] != 0x4) {
        printf((const char *)D_0027B320);
    }
    STORE_POINTER(D_00252728, D_00246C90);
    if (D_0025272C[0] != 0x6) {
        printf((const char *)D_0027B340);
    }
    STORE_POINTER(D_0025272C, D_00247880);
    if (D_00252730[0] != 0x8) {
        printf((const char *)D_0027B360);
    }
    STORE_POINTER(D_00252730, D_00249ED0);
    if (D_0028C160[0] != 0x0) {
        printf((const char *)D_0027B380);
    }
    STORE_POINTER(D_0028C160, D_00252800);
    if (D_0028C164[0] != 0x2) {
        printf((const char *)D_0027B3A0);
    }
    STORE_POINTER(D_0028C164, D_00252990);
    if (D_0028C168[0] != 0x0) {
        printf((const char *)D_0027B3C0);
    }
    STORE_POINTER(D_0028C168, D_00252AE0);
    if (D_0028C16C[0] != 0x2) {
        printf((const char *)D_0027B3E0);
    }
    STORE_POINTER(D_0028C16C, D_00252BB0);
    if (D_0028C170[0] != 0x0) {
        printf((const char *)D_0027B400);
    }
    STORE_POINTER(D_0028C170, D_00252C90);
    if (D_0028C174[0] != 0x2) {
        printf((const char *)D_0027B420);
    }
    STORE_POINTER(D_0028C174, D_00252D70);
    if (D_0028C178[0] != 0x0) {
        printf((const char *)D_0027B440);
    }
    STORE_POINTER(D_0028C178, D_00252E60);
    if (D_0028C17C[0] != 0x2) {
        printf((const char *)D_0027B460);
    }
    STORE_POINTER(D_0028C17C, D_00252F40);
    if (D_0028C180[0] != 0x0) {
        printf((const char *)D_0027B480);
    }
    STORE_POINTER(D_0028C180, D_00253020);
    if (D_0028C184[0] != 0x2) {
        printf((const char *)D_0027B4A0);
    }
    STORE_POINTER(D_0028C184, D_00253160);
    if (D_00252740[0] != 0x0) {
        printf((const char *)D_0027B4C0);
    }
    STORE_POINTER(D_00252740, D_0028C160);
    if (D_00252744[0] != 0x2) {
        printf((const char *)D_0027B4E0);
    }
    STORE_POINTER(D_00252744, D_0028C168);
    if (D_00252748[0] != 0x4) {
        printf((const char *)D_0027B500);
    }
    STORE_POINTER(D_00252748, D_0028C170);
    if (D_0025274C[0] != 0x6) {
        printf((const char *)D_0027B520);
    }
    STORE_POINTER(D_0025274C, D_0028C178);
    if (D_00252750[0] != 0x8) {
        printf((const char *)D_0027B540);
    }
    STORE_POINTER(D_00252750, D_0028C180);
    if (D_00252760[0] != 0x0) {
        printf((const char *)D_0027B560);
    }
    STORE_POINTER(D_00252760, D_002606F0);
    if (D_00252766[0] != 0x3) {
        printf((const char *)D_0027B580);
    }
    STORE_POINTER(D_00252766, D_002606B0);
    if (D_0025276C[0] != 0x6) {
        printf((const char *)D_0027B5A0);
    }
    STORE_POINTER(D_0025276C, D_00260630);
    if (D_00252772[0] != 0x9) {
        printf((const char *)D_0027B5C0);
    }
    STORE_POINTER(D_00252772, D_00260670);
    if (D_00252778[0] != 0xc) {
        printf((const char *)D_0027B5E0);
    }
    STORE_POINTER(D_00252778, D_002607B0);
    if (D_0025277E[0] != 0xf) {
        printf((const char *)D_0027B600);
    }
    STORE_POINTER(D_0025277E, D_00260730);
    if (D_00252784[0] != 0x12) {
        printf((const char *)D_0027B620);
    }
    STORE_POINTER(D_00252784, D_00255470);
    if (D_0025278A[0] != 0x15) {
        printf((const char *)D_0027B640);
    }
    STORE_POINTER(D_0025278A, D_00261DB0);
    if (D_00252790[0] != 0x18) {
        printf((const char *)D_0027B660);
    }
    STORE_POINTER(D_00252790, D_002610B0_as_u16_a);
    if (D_00252796[0] != 0x1b) {
        printf((const char *)D_0027B680);
    }
    STORE_POINTER(D_00252796, D_00260FB0);
    if (D_0025279C[0] != 0x1e) {
        printf((const char *)D_0027B6A0);
    }
    STORE_POINTER(D_0025279C, D_00260FF0);
    if (D_002527A2[0] != 0x21) {
        printf((const char *)D_0027B6C0);
    }
    STORE_POINTER(D_002527A2, D_002610F0);
    if (D_002527A8[0] != 0x24) {
        printf((const char *)D_0027B6E0);
    }
    STORE_POINTER(D_002527A8, D_00261030);
    if (D_002527AE[0] != 0x27) {
        printf((const char *)D_0027B700);
    }
    STORE_POINTER(D_002527AE, D_00261D70);
    if (D_002527B4[0] != 0x2a) {
        printf((const char *)D_0027B720);
    }
    STORE_POINTER(D_002527B4, D_00261170);
    if (D_002527BA[0] != 0x2d) {
        printf((const char *)D_0027B740);
    }
    STORE_POINTER(D_002527BA, D_00261130);
    if (D_002527C0[0] != 0x30) {
        printf((const char *)D_0027B760);
    }
    STORE_POINTER(D_002527C0, D_002612B0);
    if (D_002527C6[0] != 0x33) {
        printf((const char *)D_0027B780);
    }
    STORE_POINTER(D_002527C6, D_002611B0);
    if (D_002527CC[0] != 0x36) {
        printf((const char *)D_0027B7A0);
    }
    STORE_POINTER(D_002527CC, D_002611F0);
    if (D_002527D2[0] != 0x39) {
        printf((const char *)D_0027B7C0);
    }
    STORE_POINTER(D_002527D2, D_00260730);
    if (D_002527D8[0] != 0x3c) {
        printf((const char *)D_0027B7E0);
    }
    STORE_POINTER(D_002527D8, D_00261230);
    if (D_002527DE[0] != 0x3f) {
        printf((const char *)D_0027B800);
    }
    STORE_POINTER(D_002527DE, D_00261270);
    if (D_002527F0[0] != 0x4) {
        printf((const char *)D_0027B820);
    }
    STORE_POINTER(D_002527F0, func_0018D2D0);
    if (D_00252800[0] != 0x0) {
        printf((const char *)D_0027B840);
    }
    STORE_POINTER(D_00252800, D_00252760);
    if (D_00252804[0] != 0x2) {
        printf((const char *)D_0027B860);
    }
    STORE_POINTER(D_00252804, D_002527E8);
    if (D_00252A20[0] != 0x0) {
        printf((const char *)D_0027B880);
    }
    STORE_POINTER(D_00252A20, D_00255470);
    if (D_00252A26[0] != 0x3) {
        printf((const char *)D_0027B8A0);
    }
    STORE_POINTER(D_00252A26, D_00261DB0);
    if (D_00252A2C[0] != 0x6) {
        printf((const char *)D_0027B8C0);
    }
    STORE_POINTER(D_00252A2C, D_002610B0_as_u16_a);
    if (D_00252A32[0] != 0x9) {
        printf((const char *)D_0027B8E0);
    }
    STORE_POINTER(D_00252A32, D_00260FB0);
    if (D_00252A38[0] != 0xc) {
        printf((const char *)D_0027B900);
    }
    STORE_POINTER(D_00252A38, D_00260FF0);
    if (D_00252A3E[0] != 0xf) {
        printf((const char *)D_0027B920);
    }
    STORE_POINTER(D_00252A3E, D_002610F0);
    if (D_00252A44[0] != 0x12) {
        printf((const char *)D_0027B940);
    }
    STORE_POINTER(D_00252A44, D_00261030);
    if (D_00252A4A[0] != 0x15) {
        printf((const char *)D_0027B960);
    }
    STORE_POINTER(D_00252A4A, D_00261D70);
    if (D_00252A50[0] != 0x18) {
        printf((const char *)D_0027B980);
    }
    STORE_POINTER(D_00252A50, D_002606F0);
    if (D_00252A56[0] != 0x1b) {
        printf((const char *)D_0027B9A0);
    }
    STORE_POINTER(D_00252A56, D_002606B0);
    if (D_00252A5C[0] != 0x1e) {
        printf((const char *)D_0027B9C0);
    }
    STORE_POINTER(D_00252A5C, D_00260630);
    if (D_00252A62[0] != 0x21) {
        printf((const char *)D_0027B9E0);
    }
    STORE_POINTER(D_00252A62, D_00260570);
    if (D_00252A68[0] != 0x24) {
        printf((const char *)D_0027BA00);
    }
    STORE_POINTER(D_00252A68, D_002605F0);
    if (D_00252A6E[0] != 0x27) {
        printf((const char *)D_0027BA20);
    }
    STORE_POINTER(D_00252A6E, D_00260730);
    if (D_00252A74[0] != 0x2a) {
        printf((const char *)D_0027BA40);
    }
    STORE_POINTER(D_00252A74, D_00260670);
    if (D_00252A7A[0] != 0x2d) {
        printf((const char *)D_0027BA60);
    }
    STORE_POINTER(D_00252A7A, D_00261370);
    if (D_00252A80[0] != 0x30) {
        printf((const char *)D_0027BA80);
    }
    STORE_POINTER(D_00252A80, D_002614F0);
    if (D_00252A86[0] != 0x33) {
        printf((const char *)D_0027BAA0);
    }
    STORE_POINTER(D_00252A86, D_002612F0);
    if (D_00252A8C[0] != 0x36) {
        printf((const char *)D_0027BAC0);
    }
    STORE_POINTER(D_00252A8C, D_002605B0);
    if (D_00252A92[0] != 0x39) {
        printf((const char *)D_0027BAE0);
    }
    STORE_POINTER(D_00252A92, D_00261530);
    if (D_00252A98[0] != 0x3c) {
        printf((const char *)D_0027BB00);
    }
    STORE_POINTER(D_00252A98, D_00261330);
    if (D_00252A9E[0] != 0x3f) {
        printf((const char *)D_0027BB20);
    }
    STORE_POINTER(D_00252A9E, D_002613B0);
    if (D_00252AA4[0] != 0x42) {
        printf((const char *)D_0027BB40);
    }
    STORE_POINTER(D_00252AA4, D_002613F0);
    if (D_00252AAA[0] != 0x45) {
        printf((const char *)D_0027BB60);
    }
    STORE_POINTER(D_00252AAA, D_00261430);
    if (D_00252AB0[0] != 0x48) {
        printf((const char *)D_0027BB80);
    }
    STORE_POINTER(D_00252AB0, D_00261470);
    if (D_00252AB6[0] != 0x4b) {
        printf((const char *)D_0027BBA0);
    }
    STORE_POINTER(D_00252AB6, D_002614B0);
    if (D_00252AC4[0] != 0x2) {
        printf((const char *)D_0027BBC0);
    }
    STORE_POINTER(D_00252AC4, func_0018D1D0);
    if (D_00252AD0[0] != 0x8) {
        printf((const char *)D_0027BBE0);
    }
    STORE_POINTER(D_00252AD0, func_0018D2D0);
    if (D_00252AE0[0] != 0x0) {
        printf((const char *)D_0027BC00);
    }
    STORE_POINTER(D_00252AE0, D_00252A20);
    if (D_00252AE4[0] != 0x2) {
        printf((const char *)D_0027BC20);
    }
    STORE_POINTER(D_00252AE4, D_00252AC0);
    if (D_00252BD0[0] != 0x0) {
        printf((const char *)D_0027BC40);
    }
    STORE_POINTER(D_00252BD0, D_00255470);
    if (D_00252BD6[0] != 0x3) {
        printf((const char *)D_0027BC60);
    }
    STORE_POINTER(D_00252BD6, D_00261DB0);
    if (D_00252BDC[0] != 0x6) {
        printf((const char *)D_0027BC80);
    }
    STORE_POINTER(D_00252BDC, D_002610B0_as_u16_a);
    if (D_00252BE2[0] != 0x9) {
        printf((const char *)D_0027BCA0);
    }
    STORE_POINTER(D_00252BE2, D_00260FB0);
    if (D_00252BE8[0] != 0xc) {
        printf((const char *)D_0027BCC0);
    }
    STORE_POINTER(D_00252BE8, D_00260FF0);
    if (D_00252BEE[0] != 0xf) {
        printf((const char *)D_0027BCE0);
    }
    STORE_POINTER(D_00252BEE, D_002610F0);
    if (D_00252BF4[0] != 0x12) {
        printf((const char *)D_0027BD00);
    }
    STORE_POINTER(D_00252BF4, D_00261030);
    if (D_00252BFA[0] != 0x15) {
        printf((const char *)D_0027BD20);
    }
    STORE_POINTER(D_00252BFA, D_00261D70);
    if (D_00252C00[0] != 0x18) {
        printf((const char *)D_0027BD40);
    }
    STORE_POINTER(D_00252C00, D_002606F0);
    if (D_00252C06[0] != 0x1b) {
        printf((const char *)D_0027BD60);
    }
    STORE_POINTER(D_00252C06, D_002606B0);
    if (D_00252C0C[0] != 0x1e) {
        printf((const char *)D_0027BD80);
    }
    STORE_POINTER(D_00252C0C, D_00260630);
    if (D_00252C12[0] != 0x21) {
        printf((const char *)D_0027BDA0);
    }
    STORE_POINTER(D_00252C12, D_002608B0);
    if (D_00252C18[0] != 0x24) {
        printf((const char *)D_0027BDC0);
    }
    STORE_POINTER(D_00252C18, D_002605F0);
    if (D_00252C1E[0] != 0x27) {
        printf((const char *)D_0027BDE0);
    }
    STORE_POINTER(D_00252C1E, D_00260730);
    if (D_00252C24[0] != 0x2a) {
        printf((const char *)D_0027BE00);
    }
    STORE_POINTER(D_00252C24, D_00260670);
    if (D_00252C2A[0] != 0x2d) {
        printf((const char *)D_0027BE20);
    }
    STORE_POINTER(D_00252C2A, D_00260630);
    if (D_00252C30[0] != 0x30) {
        printf((const char *)D_0027BE40);
    }
    STORE_POINTER(D_00252C30, D_002608F0);
    if (D_00252C36[0] != 0x33) {
        printf((const char *)D_0027BE60);
    }
    STORE_POINTER(D_00252C36, D_002606B0);
    if (D_00252C3C[0] != 0x36) {
        printf((const char *)D_0027BE80);
    }
    STORE_POINTER(D_00252C3C, D_002616B0);
    if (D_00252C42[0] != 0x39) {
        printf((const char *)D_0027BEA0);
    }
    STORE_POINTER(D_00252C42, D_00261670);
    if (D_00252C48[0] != 0x3c) {
        printf((const char *)D_0027BEC0);
    }
    STORE_POINTER(D_00252C48, D_00261630);
    if (D_00252C4E[0] != 0x3f) {
        printf((const char *)D_0027BEE0);
    }
    STORE_POINTER(D_00252C4E, D_002615F0);
    if (D_00252C54[0] != 0x42) {
        printf((const char *)D_0027BF00);
    }
    STORE_POINTER(D_00252C54, D_00261570);
    if (D_00252C5A[0] != 0x45) {
        printf((const char *)D_0027BF20);
    }
    STORE_POINTER(D_00252C5A, D_002615B0);
    if (D_00252C74[0] != 0x2) {
        printf((const char *)D_0027BF40);
    }
    STORE_POINTER(D_00252C74, func_0018D210);
    if (D_00252C80[0] != 0x8) {
        printf((const char *)D_0027BF60);
    }
    STORE_POINTER(D_00252C80, func_0018D2D0);
    if (D_00252C90[0] != 0x0) {
        printf((const char *)D_0027BF80);
    }
    STORE_POINTER(D_00252C90, D_00252BD0);
    if (D_00252C94[0] != 0x2) {
        printf((const char *)D_0027BFA0);
    }
    STORE_POINTER(D_00252C94, D_00252C70);
    if (D_00252DB0[0] != 0x0) {
        printf((const char *)D_0027BFC0);
    }
    STORE_POINTER(D_00252DB0, D_00255470);
    if (D_00252DB6[0] != 0x3) {
        printf((const char *)D_0027BFE0);
    }
    STORE_POINTER(D_00252DB6, D_00261DB0);
    if (D_00252DBC[0] != 0x6) {
        printf((const char *)D_0027C000);
    }
    STORE_POINTER(D_00252DBC, D_002610B0_as_u16_a);
    if (D_00252DC2[0] != 0x9) {
        printf((const char *)D_0027C020);
    }
    STORE_POINTER(D_00252DC2, D_00260FB0);
    if (D_00252DC8[0] != 0xc) {
        printf((const char *)D_0027C040);
    }
    STORE_POINTER(D_00252DC8, D_00260FF0);
    if (D_00252DCE[0] != 0xf) {
        printf((const char *)D_0027C060);
    }
    STORE_POINTER(D_00252DCE, D_002610F0);
    if (D_00252DD4[0] != 0x12) {
        printf((const char *)D_0027C080);
    }
    STORE_POINTER(D_00252DD4, D_00261030);
    if (D_00252DDA[0] != 0x15) {
        printf((const char *)D_0027C0A0);
    }
    STORE_POINTER(D_00252DDA, D_00261D70);
    if (D_00252DE0[0] != 0x18) {
        printf((const char *)D_0027C0C0);
    }
    STORE_POINTER(D_00252DE0, D_002606F0);
    if (D_00252DE6[0] != 0x1b) {
        printf((const char *)D_0027C0E0);
    }
    STORE_POINTER(D_00252DE6, D_002606B0);
    if (D_00252DEC[0] != 0x1e) {
        printf((const char *)D_0027C100);
    }
    STORE_POINTER(D_00252DEC, D_00260630);
    if (D_00252DF2[0] != 0x21) {
        printf((const char *)D_0027C120);
    }
    STORE_POINTER(D_00252DF2, D_002605F0);
    if (D_00252DF8[0] != 0x24) {
        printf((const char *)D_0027C140);
    }
    STORE_POINTER(D_00252DF8, D_00260730);
    if (D_00252DFE[0] != 0x27) {
        printf((const char *)D_0027C160);
    }
    STORE_POINTER(D_00252DFE, D_002607F0);
    if (D_00252E04[0] != 0x2a) {
        printf((const char *)D_0027C180);
    }
    STORE_POINTER(D_00252E04, D_00261A30);
    if (D_00252E0A[0] != 0x2d) {
        printf((const char *)D_0027C1A0);
    }
    STORE_POINTER(D_00252E0A, D_00261930);
    if (D_00252E10[0] != 0x30) {
        printf((const char *)D_0027C1C0);
    }
    STORE_POINTER(D_00252E10, D_00261730_as_u16_a);
    if (D_00252E16[0] != 0x33) {
        printf((const char *)D_0027C1E0);
    }
    STORE_POINTER(D_00252E16, D_00261970);
    if (D_00252E1C[0] != 0x36) {
        printf((const char *)D_0027C200);
    }
    STORE_POINTER(D_00252E1C, D_002619B0);
    if (D_00252E22[0] != 0x39) {
        printf((const char *)D_0027C220);
    }
    STORE_POINTER(D_00252E22, D_00260830);
    if (D_00252E28[0] != 0x3c) {
        printf((const char *)D_0027C240);
    }
    STORE_POINTER(D_00252E28, D_002607F0);
    if (D_00252E2E[0] != 0x3f) {
        printf((const char *)D_0027C260);
    }
    STORE_POINTER(D_00252E2E, D_002619F0);
    if (D_00252E44[0] != 0x2) {
        printf((const char *)D_0027C280);
    }
    STORE_POINTER(D_00252E44, func_0018D250);
    if (D_00252E50[0] != 0x8) {
        printf((const char *)D_0027C2A0);
    }
    STORE_POINTER(D_00252E50, func_0018D2D0);
    if (D_00252E60[0] != 0x0) {
        printf((const char *)D_0027C2C0);
    }
    STORE_POINTER(D_00252E60, D_00252DB0);
    if (D_00252E64[0] != 0x2) {
        printf((const char *)D_0027C2E0);
    }
    STORE_POINTER(D_00252E64, D_00252E40);
    if (D_00252F80[0] != 0x0) {
        printf((const char *)D_0027C300);
    }
    STORE_POINTER(D_00252F80, D_00255470);
    if (D_00252F86[0] != 0x3) {
        printf((const char *)D_0027C320);
    }
    STORE_POINTER(D_00252F86, D_00261DB0);
    if (D_00252F8C[0] != 0x6) {
        printf((const char *)D_0027C340);
    }
    STORE_POINTER(D_00252F8C, D_002610B0_as_u16_a);
    if (D_00252F92[0] != 0x9) {
        printf((const char *)D_0027C360);
    }
    STORE_POINTER(D_00252F92, D_00260FB0);
    if (D_00252F98[0] != 0xc) {
        printf((const char *)D_0027C380);
    }
    STORE_POINTER(D_00252F98, D_00260FF0);
    if (D_00252F9E[0] != 0xf) {
        printf((const char *)D_0027C3A0);
    }
    STORE_POINTER(D_00252F9E, D_002610F0);
    if (D_00252FA4[0] != 0x12) {
        printf((const char *)D_0027C3C0);
    }
    STORE_POINTER(D_00252FA4, D_00261030);
    if (D_00252FAA[0] != 0x15) {
        printf((const char *)D_0027C3E0);
    }
    STORE_POINTER(D_00252FAA, D_00261D70);
    if (D_00252FB0[0] != 0x18) {
        printf((const char *)D_0027C400);
    }
    STORE_POINTER(D_00252FB0, D_002606F0);
    if (D_00252FB6[0] != 0x1b) {
        printf((const char *)D_0027C420);
    }
    STORE_POINTER(D_00252FB6, D_002606B0);
    if (D_00252FBC[0] != 0x1e) {
        printf((const char *)D_0027C440);
    }
    STORE_POINTER(D_00252FBC, D_00260630);
    if (D_00252FC2[0] != 0x21) {
        printf((const char *)D_0027C460);
    }
    STORE_POINTER(D_00252FC2, D_002605F0);
    if (D_00252FC8[0] != 0x24) {
        printf((const char *)D_0027C480);
    }
    STORE_POINTER(D_00252FC8, D_00260730);
    if (D_00252FCE[0] != 0x27) {
        printf((const char *)D_0027C4A0);
    }
    STORE_POINTER(D_00252FCE, D_002608B0);
    if (D_00252FD4[0] != 0x2a) {
        printf((const char *)D_0027C4C0);
    }
    STORE_POINTER(D_00252FD4, D_00261AB0);
    if (D_00252FDA[0] != 0x2d) {
        printf((const char *)D_0027C4E0);
    }
    STORE_POINTER(D_00252FDA, D_00261A70);
    if (D_00252FE0[0] != 0x30) {
        printf((const char *)D_0027C500);
    }
    STORE_POINTER(D_00252FE0, D_00260670);
    if (D_00252FE6[0] != 0x33) {
        printf((const char *)D_0027C520);
    }
    STORE_POINTER(D_00252FE6, D_00260770);
    if (D_00252FEC[0] != 0x36) {
        printf((const char *)D_0027C540);
    }
    STORE_POINTER(D_00252FEC, D_00261B30);
    if (D_00252FF2[0] != 0x39) {
        printf((const char *)D_0027C560);
    }
    STORE_POINTER(D_00252FF2, D_00261B70);
    if (D_00253004[0] != 0x2) {
        printf((const char *)D_0027C580);
    }
    STORE_POINTER(D_00253004, func_0018D290);
    if (D_00253010[0] != 0x8) {
        printf((const char *)D_0027C5A0);
    }
    STORE_POINTER(D_00253010, func_0018D310);
    if (D_00253020[0] != 0x0) {
        printf((const char *)D_0027C5C0);
    }
    STORE_POINTER(D_00253020, D_00252F80);
    if (D_00253024[0] != 0x2) {
        printf((const char *)D_0027C5E0);
    }
    STORE_POINTER(D_00253024, D_00253000);
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
    if (D_0025C3C4[0] != 0x2) {
        printf((const char *)D_0027C6A0);
    }
    STORE_POINTER(D_0025C3C4, D_0025C060);
    if (D_0025C3C8[0] != 0x4) {
        printf((const char *)D_0027C6C0);
    }
    STORE_POINTER(D_0025C3C8, D_0025C080);
    if (D_0025C3CC[0] != 0x6) {
        printf((const char *)D_0027C6E0);
    }
    STORE_POINTER(D_0025C3CC, D_0025C0A0);
    if (D_0025C3D0[0] != 0x8) {
        printf((const char *)D_0027C700);
    }
    STORE_POINTER(D_0025C3D0, D_0025C0C0);
    if (D_0025C3D4[0] != 0xa) {
        printf((const char *)D_0027C720);
    }
    STORE_POINTER(D_0025C3D4, D_0025C0E0);
    if (D_0025C3D8[0] != 0xc) {
        printf((const char *)D_0027C740);
    }
    STORE_POINTER(D_0025C3D8, D_0025C100);
    if (D_0025C3DC[0] != 0xe) {
        printf((const char *)D_0027C760);
    }
    STORE_POINTER(D_0025C3DC, D_0025C120);
    if (D_0025C3E0[0] != 0x10) {
        printf((const char *)D_0027C780);
    }
    STORE_POINTER(D_0025C3E0, D_0025C140);
    if (D_0025C3E4[0] != 0x12) {
        printf((const char *)D_0027C7A0);
    }
    STORE_POINTER(D_0025C3E4, D_0025C160);
    if (D_0025C3E8[0] != 0x14) {
        printf((const char *)D_0027C7C0);
    }
    STORE_POINTER(D_0025C3E8, D_0025C180);
    if (D_0025C3EC[0] != 0x16) {
        printf((const char *)D_0027C7E0);
    }
    STORE_POINTER(D_0025C3EC, D_0025C1A0);
    if (D_0025C3F0[0] != 0x18) {
        printf((const char *)D_0027C800);
    }
    STORE_POINTER(D_0025C3F0, D_0025C1C0);
    if (D_0025C3F4[0] != 0x1a) {
        printf((const char *)D_0027C820);
    }
    STORE_POINTER(D_0025C3F4, D_0025C1E0);
    if (D_0025C3F8[0] != 0x1c) {
        printf((const char *)D_0027C840);
    }
    STORE_POINTER(D_0025C3F8, D_0025C200);
    if (D_0025C3FC[0] != 0x1e) {
        printf((const char *)D_0027C860);
    }
    STORE_POINTER(D_0025C3FC, D_0025C220);
    if (D_0025C400[0] != 0x20) {
        printf((const char *)D_0027C880);
    }
    STORE_POINTER(D_0025C400, D_0025C240);
    if (D_0025C404[0] != 0x22) {
        printf((const char *)D_0027C8A0);
    }
    STORE_POINTER(D_0025C404, D_0025C260);
    if (D_0025C408[0] != 0x24) {
        printf((const char *)D_0027C8C0);
    }
    STORE_POINTER(D_0025C408, D_0025C280);
    if (D_0025C40C[0] != 0x26) {
        printf((const char *)D_0027C8E0);
    }
    STORE_POINTER(D_0025C40C, D_0025C2A0);
    if (D_0025C410[0] != 0x28) {
        printf((const char *)D_0027C900);
    }
    STORE_POINTER(D_0025C410, D_0025C2C0);
    if (D_0025C414[0] != 0x2a) {
        printf((const char *)D_0027C920);
    }
    STORE_POINTER(D_0025C414, D_0025C2E0);
    if (D_0025C418[0] != 0x2c) {
        printf((const char *)D_0027C940);
    }
    STORE_POINTER(D_0025C418, D_0025C300);
    if (D_0025C41C[0] != 0x2e) {
        printf((const char *)D_0027C960);
    }
    STORE_POINTER(D_0025C41C, D_0025C320);
    if (D_0025C420[0] != 0x30) {
        printf((const char *)D_0027C980);
    }
    STORE_POINTER(D_0025C420, D_0025C340);
    if (D_0025C424[0] != 0x32) {
        printf((const char *)D_0027C9A0);
    }
    STORE_POINTER(D_0025C424, D_0025C360);
    if (D_0025C428[0] != 0x34) {
        printf((const char *)D_0027C9C0);
    }
    STORE_POINTER(D_0025C428, D_0025C380);
    if (D_0025C42C[0] != 0x36) {
        printf((const char *)D_0027C9E0);
    }
    STORE_POINTER(D_0025C42C, D_0025C3A0);
    if (D_00251A80_as_u16_a[1] != 0x1) {
        printf((const char *)D_0027CA00);
    }
    reg_tmp.w = (u32)func_0016A8B0;
    D_00251A80_as_u16_a[1] = reg_tmp.h[1];
    D_00251A84[0] = reg_tmp.h[0];
    if (D_00251A86[0] != 0x3) {
        printf((const char *)D_0027CA20);
    }
    STORE_POINTER(D_00251A86, func_0016A8D0);
    if (D_00251A90_as_u16_a[1] != 0x1) {
        printf((const char *)D_0027CA40);
    }
    reg_tmp.w = (u32)func_0016A8C0;
    D_00251A90_as_u16_a[1] = reg_tmp.h[1];
    D_00251A94[0] = reg_tmp.h[0];
    if (D_00251A96[0] != 0x3) {
        printf((const char *)D_0027CA60);
    }
    STORE_POINTER(D_00251A96, func_0016A8E0);
    if (D_00251AB0_as_u16_a[1] != 0x1) {
        printf((const char *)D_0027CA80);
    }
    reg_tmp.w = (u32)func_0016A8B0;
    D_00251AB0_as_u16_a[1] = reg_tmp.h[1];
    D_00251AB4[0] = reg_tmp.h[0];
    if (D_00251AB6[0] != 0x3) {
        printf((const char *)D_0027CAA0);
    }
    STORE_POINTER(D_00251AB6, func_0016A8D0);
    if (D_00251AC0_as_u16_a[1] != 0x1) {
        printf((const char *)D_0027CAC0);
    }
    reg_tmp.w = (u32)func_0016A8C0;
    D_00251AC0_as_u16_a[1] = reg_tmp.h[1];
    D_00251AC4[0] = reg_tmp.h[0];
    if (D_00251AC6[0] != 0x3) {
        printf((const char *)D_0027CAE0);
    }
    STORE_POINTER(D_00251AC6, func_0016A8E0);
    if (D_00251AE4[0] != 0x2) {
        printf((const char *)D_0027CB00);
    }
    STORE_POINTER(D_00251AE4, func_0016A8B0);
    if (D_00251AE8[0] != 0x4) {
        printf((const char *)D_0027CB20);
    }
    STORE_POINTER(D_00251AE8, func_0016A8D0);
    if (D_00251AEC[0] != 0x6) {
        printf((const char *)D_0027CB40);
    }
    STORE_POINTER(D_00251AEC, func_00130270);
    if (D_00251AF0[0] != 0x8) {
        printf((const char *)D_0027CB60);
    }
    STORE_POINTER(D_00251AF0, D_0029BF40_as_u16_a);
    if (D_00251B04[0] != 0x2) {
        printf((const char *)D_0027CB80);
    }
    STORE_POINTER(D_00251B04, func_0016A8C0);
    if (D_00251B08[0] != 0x4) {
        printf((const char *)D_0027CBA0);
    }
    STORE_POINTER(D_00251B08, func_0016A8E0);
    if (D_00251B0C[0] != 0x6) {
        printf((const char *)D_0027CBC0);
    }
    STORE_POINTER(D_00251B0C, func_001303A0);
    if (D_00251B10[0] != 0x8) {
        printf((const char *)D_0027CBE0);
    }
    STORE_POINTER(D_00251B10, D_0029BF30_as_u16_a);
    if (D_00251CC0[0] != 0x0) {
        printf((const char *)D_0027CC00);
    }
    STORE_POINTER(D_00251CC0, D_00251CE0);
    if (D_00251CC4[0] != 0x2) {
        printf((const char *)D_0027CC20);
    }
    STORE_POINTER(D_00251CC4, D_00260F30);
    if (D_00251CC8[0] != 0x4) {
        printf((const char *)D_0027CC40);
    }
    STORE_POINTER(D_00251CC8, D_00251D10);
    if (D_00251CCC[0] != 0x6) {
        printf((const char *)D_0027CC60);
    }
    STORE_POINTER(D_00251CCC, D_00260EF0);
    if (D_00251CD0[0] != 0x8) {
        printf((const char *)D_0027CC80);
    }
    STORE_POINTER(D_00251CD0, D_00251D40);
    if (D_00251CD4[0] != 0xa) {
        printf((const char *)D_0027CCA0);
    }
    STORE_POINTER(D_00251CD4, D_00260EB0);
    if (D_0028C148_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027CCC0);
    }
    reg_tmp.w = (u32)D_0028C680;
    D_0028C148_as_u16_a[0] = reg_tmp.h[1];
    D_0028C14A[0] = reg_tmp.h[0];
    if (D_0028C14C[0] != 0x2) {
        printf((const char *)D_0027CCE0);
    }
    STORE_POINTER(D_0028C14C, D_0028C708);
    if (D_00252010[0] != 0x0) {
        printf((const char *)D_0027CD00);
    }
    STORE_POINTER(D_00252010, D_00252020);
    if (D_00252014[0] != 0x2) {
        printf((const char *)D_0027CD20);
    }
    STORE_POINTER(D_00252014, D_00252030);
    if (D_00252018[0] != 0x4) {
        printf((const char *)D_0027CD40);
    }
    STORE_POINTER(D_00252018, D_00252040);
    if (D_00252020[0] != 0x0) {
        printf((const char *)D_0027CD60);
    }
    STORE_POINTER(D_00252020, D_00252090);
    if (D_00252024[0] != 0x2) {
        printf((const char *)D_0027CD80);
    }
    STORE_POINTER(D_00252024, D_002520A0);
    if (D_00252028[0] != 0x4) {
        printf((const char *)D_0027CDA0);
    }
    STORE_POINTER(D_00252028, D_002520B0);
    if (D_00252030[0] != 0x0) {
        printf((const char *)D_0027CDC0);
    }
    STORE_POINTER(D_00252030, D_002520C0);
    if (D_00252034[0] != 0x2) {
        printf((const char *)D_0027CDE0);
    }
    STORE_POINTER(D_00252034, D_002520D0);
    if (D_00252038[0] != 0x4) {
        printf((const char *)D_0027CE00);
    }
    STORE_POINTER(D_00252038, D_002520E0);
    if (D_00252040[0] != 0x0) {
        printf((const char *)D_0027CE20);
    }
    STORE_POINTER(D_00252040, D_002520F0);
    if (D_00252044[0] != 0x2) {
        printf((const char *)D_0027CE40);
    }
    STORE_POINTER(D_00252044, D_00252100);
    if (D_00252048[0] != 0x4) {
        printf((const char *)D_0027CE60);
    }
    STORE_POINTER(D_00252048, D_00252110);
    if (D_00252050[0] != 0x0) {
        printf((const char *)D_0027CE80);
    }
    STORE_POINTER(D_00252050, D_00252060);
    if (D_00252054[0] != 0x2) {
        printf((const char *)D_0027CEA0);
    }
    STORE_POINTER(D_00252054, D_00252070);
    if (D_00252058[0] != 0x4) {
        printf((const char *)D_0027CEC0);
    }
    STORE_POINTER(D_00252058, D_00252080);
    if (D_00252060[0] != 0x0) {
        printf((const char *)D_0027CEE0);
    }
    STORE_POINTER(D_00252060, D_00252120);
    if (D_00252064[0] != 0x2) {
        printf((const char *)D_0027CF00);
    }
    STORE_POINTER(D_00252064, D_00252130);
    if (D_00252068[0] != 0x4) {
        printf((const char *)D_0027CF20);
    }
    STORE_POINTER(D_00252068, D_00252140);
    if (D_00252070[0] != 0x0) {
        printf((const char *)D_0027CF40);
    }
    STORE_POINTER(D_00252070, D_00252150);
    if (D_00252074[0] != 0x2) {
        printf((const char *)D_0027CF60);
    }
    STORE_POINTER(D_00252074, D_00252160);
    if (D_00252078[0] != 0x4) {
        printf((const char *)D_0027CF80);
    }
    STORE_POINTER(D_00252078, D_00252170);
    if (D_00252080[0] != 0x0) {
        printf((const char *)D_0027CFA0);
    }
    STORE_POINTER(D_00252080, D_00252180);
    if (D_00252084[0] != 0x2) {
        printf((const char *)D_0027CFC0);
    }
    STORE_POINTER(D_00252084, D_00252190);
    if (D_00252088[0] != 0x4) {
        printf((const char *)D_0027CFE0);
    }
    STORE_POINTER(D_00252088, D_002521A0);
    if (D_002520C6[0] != 0x3) {
        printf((const char *)D_0027D000);
    }
    STORE_POINTER(D_002520C6, D_002521B0);
    if (D_002520D6[0] != 0x3) {
        printf((const char *)D_0027D020);
    }
    STORE_POINTER(D_002520D6, D_002521D0);
    if (D_002520E6[0] != 0x3) {
        printf((const char *)D_0027D040);
    }
    STORE_POINTER(D_002520E6, D_002521F0);
    if (D_00252156[0] != 0x3) {
        printf((const char *)D_0027D060);
    }
    STORE_POINTER(D_00252156, D_002521B0);
    if (D_00252166[0] != 0x3) {
        printf((const char *)D_0027D080);
    }
    STORE_POINTER(D_00252166, D_002521D0);
    if (D_00252176[0] != 0x3) {
        printf((const char *)D_0027D0A0);
    }
    STORE_POINTER(D_00252176, D_002521F0);
    if (D_00252210[0] != 0x0) {
        printf((const char *)D_0027D0C0);
    }
    STORE_POINTER(D_00252210, D_00252230);
    if (D_00252214[0] != 0x2) {
        printf((const char *)D_0027D0E0);
    }
    STORE_POINTER(D_00252214, D_00252240);
    if (D_00252218[0] != 0x4) {
        printf((const char *)D_0027D100);
    }
    STORE_POINTER(D_00252218, D_00252250);
    if (D_00252220[0] != 0x0) {
        printf((const char *)D_0027D120);
    }
    STORE_POINTER(D_00252220, D_00252268);
    if (D_00252224[0] != 0x2) {
        printf((const char *)D_0027D140);
    }
    STORE_POINTER(D_00252224, D_00252278);
    if (D_00252228[0] != 0x4) {
        printf((const char *)D_0027D160);
    }
    STORE_POINTER(D_00252228, D_00252290);
    if (D_00252236[0] != 0x3) {
        printf((const char *)D_0027D180);
    }
    STORE_POINTER(D_00252236, D_002522B0);
    if (D_00252246[0] != 0x3) {
        printf((const char *)D_0027D1A0);
    }
    STORE_POINTER(D_00252246, D_002522D0);
    if (D_00252256[0] != 0x3) {
        printf((const char *)D_0027D1C0);
    }
    STORE_POINTER(D_00252256, D_002522F0);
    if (D_00252260[0] != 0x8) {
        printf((const char *)D_0027D1E0);
    }
    STORE_POINTER(D_00252260, D_00252310);
    if (D_0025226E[0] != 0x3) {
        printf((const char *)D_0027D200);
    }
    STORE_POINTER(D_0025226E, D_002522B0);
    if (D_0025227E[0] != 0x3) {
        printf((const char *)D_0027D220);
    }
    STORE_POINTER(D_0025227E, D_002522D0);
    if (D_00252296[0] != 0x3) {
        printf((const char *)D_0027D240);
    }
    STORE_POINTER(D_00252296, D_002522F0);
    if (D_002522A0[0] != 0x8) {
        printf((const char *)D_0027D260);
    }
    STORE_POINTER(D_002522A0, D_00252310);
    if (D_002643E0_as_u16_a[0] != 0x0) {
        printf((const char *)D_0027D280);
    }
    reg_tmp.w = (u32)D_002644E0;
    D_002643E0_as_u16_a[0] = reg_tmp.h[1];
    D_002643E2[0] = reg_tmp.h[0];
    if (D_002643E4[0] != 0x2) {
        printf((const char *)D_0027D2B0);
    }
    STORE_POINTER(D_002643E4, D_00264490);
    if (D_002643E8[0] != 0x4) {
        printf((const char *)D_0027D2E0);
    }
    STORE_POINTER(D_002643E8, D_00264440);
    if (D_002643EC[0] != 0x6) {
        printf((const char *)D_0027D310);
    }
    STORE_POINTER(D_002643EC, D_002643F0);
    if (D_00264C38[0] != 0x4) {
        printf((const char *)D_0027D340);
    }
    STORE_POINTER(D_00264C38, D_002610F0);
    if (D_00264C46[0] != 0xb) {
        printf((const char *)D_0027D360);
    }
    STORE_POINTER(D_00264C46, D_0025FF70_as_u16_a);
    if (D_00264C54[0] != 0x12) {
        printf((const char *)D_0027D380);
    }
    STORE_POINTER(D_00264C54, D_0025FFB0_as_u16_a);
    if (D_00264C62[0] != 0x19) {
        printf((const char *)D_0027D3A0);
    }
    STORE_POINTER(D_00264C62, D_0025FFF0_as_u16_a);
    if (D_00264C70[0] != 0x20) {
        printf((const char *)D_0027D3C0);
    }
    STORE_POINTER(D_00264C70, D_00260030_as_u16_a);
    if (D_00264C7E[0] != 0x27) {
        printf((const char *)D_0027D3E0);
    }
    STORE_POINTER(D_00264C7E, D_00260070_as_u16_a);
    if (D_00264C8C[0] != 0x2e) {
        printf((const char *)D_0027D400);
    }
    STORE_POINTER(D_00264C8C, D_002600B0_as_u16_a);
    if (D_00264C9A[0] != 0x35) {
        printf((const char *)D_0027D420);
    }
    STORE_POINTER(D_00264C9A, D_002600F0_as_u16_a);
    if (D_00264CA8[0] != 0x3c) {
        printf((const char *)D_0027D440);
    }
    STORE_POINTER(D_00264CA8, D_0024CA40);
    if (D_00264CB6[0] != 0x43) {
        printf((const char *)D_0027D460);
    }
    STORE_POINTER(D_00264CB6, D_0024CA80);
    if (D_00264CC4[0] != 0x4a) {
        printf((const char *)D_0027D480);
    }
    STORE_POINTER(D_00264CC4, D_0024CAC0);
    if (D_00264CD2[0] != 0x51) {
        printf((const char *)D_0027D4A0);
    }
    STORE_POINTER(D_00264CD2, D_0024CB00);
    if (D_00264CE0[0] != 0x58) {
        printf((const char *)D_0027D4C0);
    }
    STORE_POINTER(D_00264CE0, D_0024CB40);
    if (D_00264CEE[0] != 0x5f) {
        printf((const char *)D_0027D4E0);
    }
    STORE_POINTER(D_00264CEE, D_0024CB80);
    if (D_00264D08[0] != 0x4) {
        printf((const char *)D_0027D500);
    }
    STORE_POINTER(D_00264D08, D_002610F0);
    if (D_00264D16[0] != 0xb) {
        printf((const char *)D_0027D520);
    }
    STORE_POINTER(D_00264D16, D_00260130_as_u16_a);
    if (D_00264D24[0] != 0x12) {
        printf((const char *)D_0027D540);
    }
    STORE_POINTER(D_00264D24, D_00260170_as_u16_a);
    if (D_00264D32[0] != 0x19) {
        printf((const char *)D_0027D560);
    }
    STORE_POINTER(D_00264D32, D_0024CA40);
    if (D_00264D40[0] != 0x20) {
        printf((const char *)D_0027D580);
    }
    STORE_POINTER(D_00264D40, D_0024CA80);
    if (D_00264D4E[0] != 0x27) {
        printf((const char *)D_0027D5A0);
    }
    STORE_POINTER(D_00264D4E, D_0024CAC0);
    if (D_00264D5C[0] != 0x2e) {
        printf((const char *)D_0027D5C0);
    }
    STORE_POINTER(D_00264D5C, D_0024CB00);
    if (D_00264D6A[0] != 0x35) {
        printf((const char *)D_0027D5E0);
    }
    STORE_POINTER(D_00264D6A, D_0024CB40);
    if (D_00264D78[0] != 0x3c) {
        printf((const char *)D_0027D600);
    }
    STORE_POINTER(D_00264D78, D_0024CB80);
    if (D_00264E18[0] != 0x4) {
        printf((const char *)D_0027D620);
    }
    STORE_POINTER(D_00264E18, D_002610F0);
    if (D_00264E26[0] != 0xb) {
        printf((const char *)D_0027D640);
    }
    STORE_POINTER(D_00264E26, D_0024CA40);
    if (D_00264E34[0] != 0x12) {
        printf((const char *)D_0027D660);
    }
    STORE_POINTER(D_00264E34, D_0024CA80);
    if (D_00264E42[0] != 0x19) {
        printf((const char *)D_0027D680);
    }
    STORE_POINTER(D_00264E42, D_0024CAC0);
    if (D_00264E50[0] != 0x20) {
        printf((const char *)D_0027D6A0);
    }
    STORE_POINTER(D_00264E50, D_0024CB00);
    if (D_00264E5E[0] != 0x27) {
        printf((const char *)D_0027D6C0);
    }
    STORE_POINTER(D_00264E5E, D_0024CB40);
    if (D_00264E6C[0] != 0x2e) {
        printf((const char *)D_0027D6E0);
    }
    STORE_POINTER(D_00264E6C, D_0024CB80);
    if (D_00264E86[0] != 0x3) {
        printf((const char *)D_0027D700);
    }
    STORE_POINTER(D_00264E86, D_00261D30);
    if (D_00264E92[0] != 0x9) {
        printf((const char *)D_0027D720);
    }
    STORE_POINTER(D_00264E92, D_00261D30);
    if (D_00264EA8[0] != 0x4) {
        printf((const char *)D_0027D740);
    }
    STORE_POINTER(D_00264EA8, D_0025FF70_as_u16_a);
    if (D_00264EB6[0] != 0xb) {
        printf((const char *)D_0027D760);
    }
    STORE_POINTER(D_00264EB6, D_0025FFB0_as_u16_a);
    if (D_00264EC4[0] != 0x12) {
        printf((const char *)D_0027D780);
    }
    STORE_POINTER(D_00264EC4, D_0025FFF0_as_u16_a);
    if (D_00264ED2[0] != 0x19) {
        printf((const char *)D_0027D7A0);
    }
    STORE_POINTER(D_00264ED2, D_002600F0_as_u16_a);
}


s32 text_layer_clear();
s32 func_0018D450();
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
        func_0018D450();
    }
}

s32 text_layer_clear();                            /* extern */
s32 func_00135ED0();                            /* extern */
s32 func_00137C20();                            /* extern */
s32 func_0013FD80();                            /* extern */
s32 func_0018DE90();                            /* extern */
s32 text_palette_load();                            /* extern */
s32 task_start();                            /* extern */
s32 func_002075F0();                            /* extern */
extern s32 D_00269160_as_s32_a[];
extern u8 D_0028E258;
extern u8 D_0028E25C;
extern u8 D_0028E290;
extern s32 D_0028EAFC;

void func_001980A0() {
    func_0013FD80();
    func_00137C20();
    func_00135ED0();
    func_002075F0();
    func_0018DE90();
    text_layer_clear();
    reg_d0.w = 0;
    reg_a0 = (u8 *)D_00269160_as_s32_a;
    text_palette_load();
    if ((s32) D_0028E258 < (s32) D_0028E25C) {
        D_0028E258 = D_0028E25C;
    }
    if (D_0028E290 == 2) {
        func_001984C0();
    } else if (func_001981F0() != 0) {
        func_001984C0();
    } else {
        D_0028EAFC = 0xFF;
    }
    reg_d0.h[0] = 8;
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
extern u8 D_0028E384;
extern u8 D_0028E388;
extern u8 D_0028E38C;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;

s32 func_001981F0(void) {
    if ((D_0028E38C == 1) && (D_0028E388 == 0) && (D_0028E384 == 0) && (D_0028E290 == 0) && (g_p1_score_digits == 0) && (g_p2_score_digits == 0) && (MAIN_OR_DEATH_LABEL(D_0028E4B0, g_two_player_seen) != 3)) {
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
    if (D_0028E290 == 2) {
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
    if (D_0028E290 == 2) {
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
    s32 func_0016A8B0();
    s32 func_0016A8D0();
    s32 temp_s6;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;

    reg_a4 = (u8 *)D_002BAE00;
    func_0016A8B0();
    *(u16 *)(reg_a4 + 0x34) = (u16) reg_d0.h[0];
    func_0016A8D0();
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
    s32 func_0016A8C0();
    s32 func_0016A8E0();
    s32 temp_s6;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;

    reg_a4 = (u8 *)D_002BAE40;
    func_0016A8C0();
    *(u16 *)(reg_a4 + 0x34) = (u16) reg_d0.h[0];
    func_0016A8E0();
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
s32 func_0018DA30();
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
    func_0018DA30();
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
    func_0018DA30();
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

s32 func_0018DA50();
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
            func_0018DA50();
        }
    }
}
