#include "common.h"

extern const char D_0012B158[];
extern const char D_0012B160[];
extern const char D_0012B168[];
extern s32 D_0012B3DC;
extern s32 D_0012B3E0;

extern void func_0011C360(void);
extern void func_0011C460(s16 x, s16 y, const char *text, s32 style,
                          u16 glyphWidth, u16 glyphHeight, s32 intensity, s32 flags);
extern void func_0011C7D0(void);

void func_001236D0(s32 selection, s32 centerX, s32 y, s32 spacing)
{
    s32 highlightOffset;
    s32 glyphSize;

    if (selection < 0) {
        if (selection == -1) {
            D_0012B3DC = 1;
        } else {
            D_0012B3DC = 0;
        }
        D_0012B3E0 = 4;
        return;
    }

    if (D_0012B3DC != selection) {
        D_0012B3DC = selection;
        D_0012B3E0 = 0;
    }

    if (D_0012B3E0 < 4) {
        D_0012B3E0 += 2;
    }

    highlightOffset = 0;
    if (D_0012B3E0 != 0) {
        highlightOffset = D_0012B3E0 / 2;
    }
    glyphSize = D_0012B3E0 + 24;

    func_0011C7D0();

    if (D_0012B3DC == 0) {
        func_0011C460((s16)(centerX - spacing - 100 - highlightOffset),
                      (s16)(y - highlightOffset), D_0012B158, 4,
                      (u16)glyphSize, (u16)glyphSize, 128, 0);
        func_0011C460((s16)(centerX - 88), (s16)y, D_0012B160, 0, 24, 24, 128, 0);
        func_0011C460((s16)(centerX + spacing - 100), (s16)y,
                      D_0012B168, 0, 24, 24, 128, 0);
    } else {
        func_0011C460((s16)(centerX - spacing - 100), (s16)y,
                      D_0012B158, 0, 24, 24, 128, 0);
        func_0011C460((s16)(centerX - 88), (s16)y, D_0012B160, 0, 24, 24, 128, 0);
        func_0011C460((s16)(centerX + spacing - 100 - highlightOffset),
                      (s16)(y - highlightOffset), D_0012B168, 4,
                      (u16)glyphSize, (u16)glyphSize, 128, 0);
    }

    func_0011C360();
}
