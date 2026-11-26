#ifndef DDPDOJ_PC_PAD_H
#define DDPDOJ_PC_PAD_H

typedef union SDL_Event SDL_Event;

/* Forward hotplug events and capture once just before advancing a game frame. */
void pc_pad_handle_event(const SDL_Event *event);
void pc_pad_capture(void);
void pc_pad_shutdown(void);

#endif
