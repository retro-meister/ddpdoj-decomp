#include "disc_image.h"
#include "pc_sound.h"
#include "sfx.h"

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

static void require(bool condition, const char *message)
{
    if (!condition) {
        fprintf(stderr, "%s (%s)\n", message, SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
    require(argc == 2 && SDL_Init(SDL_INIT_AUDIO), "Initialize the test audio device");
    require(pc_sfx_load(argv[1]), "Decode the retail effects");
    require(pc_sound_command(0x580, 0x36, 0x94, 4) == 0, "Play a sample on a named channel");
    float samples[334];
    require(pc_sfx_render(samples, SDL_arraysize(samples)), "Mix the playing channel");
    bool nonzero = false;
    for (size_t i = 0; i < SDL_arraysize(samples); ++i) nonzero |= samples[i] != 0;
    require(nonzero, "The playing channel has nonzero output");
    require(pc_sound_command(0x510, 4, 0, 0) == 0 &&
            pc_sfx_render(samples, SDL_arraysize(samples)), "Stop the named channel");
    for (size_t i = 0; i < SDL_arraysize(samples); ++i) require(samples[i] == 0, "The channel is silent");

    DiscImage *disc = disc_image_open(argv[1]);
    DiscExtent track;
    require(disc && disc_image_find(disc, "BGM/BGM1.D2", &track), "Find a retail D2 music track");
    disc_image_close(disc);
    require(pc_bgm_open(argv[1]), "Start the music worker");
    require(pc_sound_command(0x80c0, 0, 0, 0) == 0 &&
            pc_sound_command(0x160, track.size, track.lba, 0) == 0, "Queue music preparation");
    const Uint64 deadline = SDL_GetTicks() + 2000;
    s32 status;
    while ((status = pc_sound_command(0x100, 0, 0, 0)) > 0 && SDL_GetTicks() < deadline) {
        SDL_Delay(1);
    }
    require(status == 0, "Buffer stereo PCM from the disc");
    require(pc_sound_command(0x150, 0, 0, 0) == 0 &&
            pc_sound_command(0x80b0, 0, 0, 0) == 0x1000, "Start the prepared stream");
    SDL_Delay(100);
    require(pc_sound_command(0x60, 0, 0, 0) == 0 &&
            pc_sound_command(0x80b0, 0, 0, 0) == 0, "Pause the stream");
    require(pc_sound_command(0x50, 0, 0, 0) == 0 &&
            pc_sound_command(0x80b0, 0, 0, 0) == 0x1000, "Resume the stream");
    require(pc_sound_command(0x30, 0, 0, 0) == 0 &&
            pc_sound_command(0x80b0, 0, 0, 0) == 0, "Close the stream");
    pc_bgm_close();
    pc_sfx_shutdown();
    SDL_Quit();
    return EXIT_SUCCESS;
}
