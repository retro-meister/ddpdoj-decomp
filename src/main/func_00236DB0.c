#include "common.h"

typedef struct {
    unsigned __int128 quadwords[4];
} StatePayload;

typedef struct {
    StatePayload payload;
    s16 trailingHalfword;
} StateBlock;

extern StateBlock D_006E5B90[];
extern StateBlock D_006E5BE0[];

void func_00236DB0(void)
{
    u32 destinationAddress = (u32)D_006E5B90;
    u32 sourceAddress = (u32)D_006E5BE0;

    *(StatePayload *)destinationAddress = *(const StatePayload *)sourceAddress;
    *(s16 *)(destinationAddress + sizeof(StatePayload)) =
        *(const s16 *)(sourceAddress + sizeof(StatePayload));
}
