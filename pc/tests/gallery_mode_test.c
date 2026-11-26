#include "game_loop.h"
#include "gallery/gallery.h"

#include <stdlib.h>

int main(void) {
    gallery_exit_to_elf(0);
    return game_take_mode_request() == GAME_MODE_MAIN &&
           game_take_mode_request() == GAME_MODE_NONE ? EXIT_SUCCESS : EXIT_FAILURE;
}
