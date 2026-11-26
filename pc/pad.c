#include "pc_input.h"
#include "sdk/libpad.h"

#include <SDL3/SDL.h>

typedef struct {
    SDL_Gamepad *gamepad;
    bool opened;
    u16 buttons;
    u8 axis[4];
} PadPort;

static PadPort ports[2];

static void attach_pad(SDL_JoystickID id) {
    PadPort *empty = NULL;
    for (size_t i = 0; i < SDL_arraysize(ports); ++i) {
        if (ports[i].gamepad) {
            if (SDL_GetGamepadID(ports[i].gamepad) == id) {
                return;
            }
        } else if (!empty) {
            empty = &ports[i];
        }
    }
    if (empty) {
        empty->gamepad = SDL_OpenGamepad(id);
    }
}

void pc_pad_handle_event(const SDL_Event *event) {
    if (event->type == SDL_EVENT_GAMEPAD_ADDED) {
        attach_pad(event->gdevice.which);
    } else if (event->type == SDL_EVENT_GAMEPAD_REMOVED) {
        for (size_t i = 0; i < SDL_arraysize(ports); ++i) {
            if (ports[i].gamepad && SDL_GetGamepadID(ports[i].gamepad) == event->gdevice.which) {
                SDL_CloseGamepad(ports[i].gamepad);
                ports[i].gamepad = NULL;
            }
        }
    }
}

static u16 keyboard_buttons(void) {
    static const struct { SDL_Scancode key; u16 mask; } bindings[] = {
        {SDL_SCANCODE_UP, SCE_PADLup}, {SDL_SCANCODE_RIGHT, SCE_PADLright},
        {SDL_SCANCODE_DOWN, SCE_PADLdown}, {SDL_SCANCODE_LEFT, SCE_PADLleft},
        {SDL_SCANCODE_Z, SCE_PADRdown}, {SDL_SCANCODE_X, SCE_PADRright},
        {SDL_SCANCODE_C, SCE_PADRleft}, {SDL_SCANCODE_V, SCE_PADRup},
        {SDL_SCANCODE_Q, SCE_PADL1}, {SDL_SCANCODE_E, SCE_PADR1},
        {SDL_SCANCODE_RETURN, SCE_PADstart}, {SDL_SCANCODE_BACKSPACE, SCE_PADselect},
    };
    if (!SDL_GetKeyboardFocus()) {
        return 0;
    }
    const bool *keys = SDL_GetKeyboardState(NULL);
    u16 buttons = 0;
    for (size_t i = 0; i < SDL_arraysize(bindings); ++i) {
        if (keys[bindings[i].key]) {
            buttons |= bindings[i].mask;
        }
    }
    return buttons;
}

static void capture_gamepad(PadPort *port) {
    static const struct { SDL_GamepadButton button; u16 mask; } bindings[] = {
        {SDL_GAMEPAD_BUTTON_DPAD_UP, SCE_PADLup}, {SDL_GAMEPAD_BUTTON_DPAD_RIGHT, SCE_PADLright},
        {SDL_GAMEPAD_BUTTON_DPAD_DOWN, SCE_PADLdown}, {SDL_GAMEPAD_BUTTON_DPAD_LEFT, SCE_PADLleft},
        {SDL_GAMEPAD_BUTTON_NORTH, SCE_PADRup}, {SDL_GAMEPAD_BUTTON_EAST, SCE_PADRright},
        {SDL_GAMEPAD_BUTTON_SOUTH, SCE_PADRdown}, {SDL_GAMEPAD_BUTTON_WEST, SCE_PADRleft},
        {SDL_GAMEPAD_BUTTON_LEFT_SHOULDER, SCE_PADL1}, {SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER, SCE_PADR1},
        {SDL_GAMEPAD_BUTTON_BACK, SCE_PADselect}, {SDL_GAMEPAD_BUTTON_START, SCE_PADstart},
    };
    static const SDL_GamepadAxis axes[] = {
        SDL_GAMEPAD_AXIS_RIGHTX, SDL_GAMEPAD_AXIS_RIGHTY,
        SDL_GAMEPAD_AXIS_LEFTX, SDL_GAMEPAD_AXIS_LEFTY,
    };
    for (size_t i = 0; i < SDL_arraysize(bindings); ++i) {
        if (SDL_GetGamepadButton(port->gamepad, bindings[i].button)) {
            port->buttons |= bindings[i].mask;
        }
    }
    for (size_t i = 0; i < SDL_arraysize(axes); ++i) {
        int axis = SDL_GetGamepadAxis(port->gamepad, axes[i]);
        port->axis[i] = (u8)((axis + 32768) / 256);
    }
    if (SDL_GetGamepadAxis(port->gamepad, SDL_GAMEPAD_AXIS_LEFT_TRIGGER) >= 16384) {
        port->buttons |= SCE_PADL2;
    }
    if (SDL_GetGamepadAxis(port->gamepad, SDL_GAMEPAD_AXIS_RIGHT_TRIGGER) >= 16384) {
        port->buttons |= SCE_PADR2;
    }
}

void pc_pad_capture(void) {
    ports[0].buttons = keyboard_buttons();
    ports[1].buttons = 0;
    for (size_t i = 0; i < SDL_arraysize(ports); ++i) {
        PadPort *port = &ports[i];
        SDL_memset(port->axis, 0x80, sizeof port->axis);
        if (port->gamepad && SDL_GamepadConnected(port->gamepad)) {
            capture_gamepad(port);
        }
    }
}

void pc_pad_shutdown(void) {
    for (size_t i = 0; i < SDL_arraysize(ports); ++i) {
        if (ports[i].gamepad) {
            SDL_CloseGamepad(ports[i].gamepad);
        }
        ports[i] = (PadPort){0};
    }
}

static bool valid_port(s32 port, s32 slot) {
    return slot == 0 && port >= 0 && port < (s32)SDL_arraysize(ports);
}

static bool ready(s32 port, s32 slot) {
    return valid_port(port, slot) && ports[port].opened &&
           (port == 0 || (ports[port].gamepad && SDL_GamepadConnected(ports[port].gamepad)));
}

s32 scePadInit(s32 mode) {
    return mode == 0;
}

s32 scePadPortOpen(s32 port, s32 slot, void *addr) {
    (void)addr;
    if (!valid_port(port, slot)) {
        return 0;
    }
    ports[port].opened = true;
    return 1;
}

s32 scePadGetState(s32 port, s32 slot) {
    return ready(port, slot) ? 6 : 0;
}

s32 scePadRead(s32 port, s32 slot, u8 *rdata) {
    if (!ready(port, slot)) {
        return 0;
    }
    const PadPort *state = &ports[port];
    u16 buttons = (u16)~state->buttons;
    SDL_memset(rdata, 0, 32);
    rdata[1] = 0x73;
    rdata[2] = (u8)(buttons >> 8);
    rdata[3] = (u8)buttons;
    SDL_memcpy(rdata + 4, state->axis, sizeof state->axis);
    return 8;
}

s32 scePadGetReqState(s32 port, s32 slot) {
    return ready(port, slot) ? 0 : 1;
}

s32 scePadInfoMode(s32 port, s32 slot, s32 term, s32 offs) {
    (void)offs;
    return ready(port, slot) && (term == 1 || term == 2) ? 7 : 0;
}

s32 scePadSetMainMode(s32 port, s32 slot, s32 offs, s32 lock) {
    return ready(port, slot) && offs == 1 && lock == 3;
}

s32 scePadInfoAct(s32 port, s32 slot, s32 actno, s32 term) {
    if (!ready(port, slot) || !ports[port].gamepad || actno != -1 || term != 0) {
        return 0;
    }
    SDL_PropertiesID properties = SDL_GetGamepadProperties(ports[port].gamepad);
    return SDL_GetBooleanProperty(properties, SDL_PROP_GAMEPAD_CAP_RUMBLE_BOOLEAN, false) ? 2 : 0;
}

s32 scePadSetActAlign(s32 port, s32 slot, u8 *data) {
    (void)data;
    return scePadInfoAct(port, slot, -1, 0) != 0;
}

void scePadSetActDirect(s32 port, s32 slot, u8 *data) {
    if (scePadInfoAct(port, slot, -1, 0)) {
        SDL_RumbleGamepad(ports[port].gamepad, (Uint16)(data[1] * 257u),
                         data[0] ? 65535 : 0, 60);
    }
}

s32 scePadInfoPressMode(s32 port, s32 slot) {
    (void)port;
    (void)slot;
    return 0;
}

s32 scePadEnterPressMode(s32 port, s32 slot) {
    return scePadInfoPressMode(port, slot);
}
