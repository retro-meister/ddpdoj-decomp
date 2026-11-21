#include "common.h"

typedef struct {
    s32 selection;
    s32 selectionCount;
    s32 movementSteps[5];
    s32 actionEnabled[5];
    s32 heldFrames;
} GalleryMenuState;

typedef struct {
    u8 reserved[0x20];
    u32 heldButtons;
    u32 pressedButtons;
} GalleryMenuInput;

extern u16 D_0012AFE0[8];
extern u16 D_0012AFF0[8];

s32 func_001246C0(GalleryMenuState *menu, GalleryMenuInput *input)
{
    s32 heldFrames;
    s32 buttonIndex;

    if (input->heldButtons == 0) {
        menu->heldFrames = 0;
    } else {
        menu->heldFrames++;
    }

    heldFrames = menu->heldFrames;
    if (heldFrames != 1) {
        if (heldFrames <= 20) {
            goto checkMovement;
        }
        if ((heldFrames & 3) != 0) {
            goto checkMovement;
        }
    }

    input->pressedButtons =
        (input->pressedButtons & 0x0FFF) | (input->heldButtons & 0xF000);

checkMovement:
    for (buttonIndex = 0; buttonIndex < 5; buttonIndex++) {
        if (menu->movementSteps[buttonIndex] != 0 &&
            (input->pressedButtons & D_0012AFE0[buttonIndex]) != 0) {
            menu->selection += menu->movementSteps[buttonIndex];
            if (menu->selection < 0) {
                menu->selection += menu->selectionCount;
                return -1;
            }
            if (menu->selection >= menu->selectionCount) {
                menu->selection -= menu->selectionCount;
                return -1;
            }
            return 1;
        }
    }

    for (buttonIndex = 0; buttonIndex < 5; buttonIndex++) {
        if (menu->actionEnabled[buttonIndex] != 0 &&
            (input->pressedButtons & D_0012AFF0[buttonIndex]) != 0) {
            return buttonIndex + 0x100;
        }
    }

    return 0;
}
