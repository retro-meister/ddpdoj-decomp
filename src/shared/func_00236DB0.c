#include "common.h"

typedef struct {
    unsigned __int128 quadwords[4];
} StatePayload;

typedef struct {
    StatePayload payload;
    s16 trailingHalfword;
} StateBlock;

extern StateBlock D_006E5B90_as_StateBlock_a[];
extern StateBlock D_006E5BE0_as_StateBlock_a[];

void func_00236DB0(void)
{
    u32 destinationAddress = (u32)D_006E5B90_as_StateBlock_a;
    u32 sourceAddress = (u32)D_006E5BE0_as_StateBlock_a;

    *(StatePayload *)destinationAddress = *(const StatePayload *)sourceAddress;
    *(s16 *)(destinationAddress + sizeof(StatePayload)) =
        *(const s16 *)(sourceAddress + sizeof(StatePayload));
}
