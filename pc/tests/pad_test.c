#include "pc_input.h"
#include "gallery/gallery.h"

#include <SDL3/SDL.h>

extern u32 g_pad_held[4];
extern u32 g_pad_trigger[4];
extern u32 g_pad_repeat[4];

static void require(bool condition, const char *message) {
    if (!condition) {
        SDL_LogError(SDL_LOG_CATEGORY_TEST, "%s (%s)", message, SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

static void send_event(Uint32 type, SDL_JoystickID id) {
    SDL_Event event = {0};
    event.gdevice.type = type;
    event.gdevice.which = id;
    pc_pad_handle_event(&event);
}

static void tick(void) {
    SDL_UpdateGamepads();
    pc_pad_capture();
    pad_update();
}

int main(void) {
    require(SDL_Init(SDL_INIT_GAMEPAD), "Initialize SDL gamepads");
    SDL_VirtualJoystickDesc description;
    SDL_INIT_INTERFACE(&description);
    description.type = SDL_JOYSTICK_TYPE_GAMEPAD;
    description.nbuttons = SDL_GAMEPAD_BUTTON_COUNT;
    description.naxes = SDL_GAMEPAD_AXIS_COUNT;
    SDL_JoystickID player_one = SDL_AttachVirtualJoystick(&description);
    SDL_JoystickID player_two = SDL_AttachVirtualJoystick(&description);
    require(player_one && player_two, "Attach two virtual gamepads");
    send_event(SDL_EVENT_GAMEPAD_ADDED, player_one);
    send_event(SDL_EVENT_GAMEPAD_ADDED, player_two);
    SDL_Joystick *first = SDL_OpenJoystick(player_one);
    SDL_Joystick *second = SDL_OpenJoystick(player_two);
    require(first && second, "Open virtual joystick state");
    pad_init_system();
    for (int i = 0; i < 3; ++i) {
        tick();
    }
    require(g_pad_held[0] == 0 && g_pad_held[1] == 0, "Both controllers start neutral");

    require(SDL_SetJoystickVirtualButton(first, SDL_GAMEPAD_BUTTON_SOUTH, true), "Press player one's Cross");
    require(SDL_SetJoystickVirtualButton(second, SDL_GAMEPAD_BUTTON_EAST, true), "Press player two's Circle");
    require(SDL_SetJoystickVirtualAxis(first, SDL_GAMEPAD_AXIS_LEFTX, -32768), "Move player one's left stick");
    tick();
    const u16 one_mask = SCE_PADRdown | SCE_PADLleft;
    const u16 two_mask = SCE_PADRright;
    require(g_pad_held[0] == one_mask && g_pad_trigger[0] == one_mask, "Player one has a same-frame edge");
    require(g_pad_held[1] == two_mask && g_pad_trigger[1] == two_mask, "Player two has independent input");
    require(g_pad_held[2] == (one_mask | two_mask), "Original menu logic merges both ports");
    require(g_pad_repeat[0] == one_mask, "Menu repeat includes the initial edge");
    tick();
    require(g_pad_held[0] == one_mask && g_pad_trigger[0] == 0, "Held input must not retrigger");
    for (int held_frames = 1; held_frames < 11; ++held_frames) {
        require(g_pad_repeat[0] == 0, "No repeat before the original hold interval");
        tick();
    }
    require(g_pad_repeat[0] == one_mask && g_pad_trigger[0] == 0,
            "The original menu repeat fires after 11 held frames");

    require(SDL_DetachVirtualJoystick(player_two), "Detach player two");
    send_event(SDL_EVENT_GAMEPAD_REMOVED, player_two);
    tick();
    require(g_pad_held[0] == one_mask && g_pad_held[1] == 0,
            "Disconnect clears player two without disturbing player one");
    require(SDL_SetJoystickVirtualButton(first, SDL_GAMEPAD_BUTTON_SOUTH, false), "Release player one's Cross");
    require(SDL_SetJoystickVirtualAxis(first, SDL_GAMEPAD_AXIS_LEFTX, 0), "Center player one's stick");
    tick();
    require(g_pad_held[0] == 0 && g_pad_held[2] == 0, "Released inputs must clear");

    pc_pad_shutdown();
    SDL_CloseJoystick(first);
    SDL_CloseJoystick(second);
    SDL_DetachVirtualJoystick(player_one);
    SDL_Quit();
    return EXIT_SUCCESS;
}
