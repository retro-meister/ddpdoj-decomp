#include "common.h"

Reg32 reg_tmp;
static u8 data[32];
static volatile bool called;

static void callback(void)
{
    called = true;
}

int main(void)
{
    typedef void (*Callback)(void);
    pc_arcade_address_init();

    u16 slot[2];
    STORE_ARCADE_ADDRESS(slot, data + 5);
    u32 encoded = ((u32)slot[0] << 16) | slot[1];
    if (!encoded || ARCADE_ADDRESS_DECODE(u8 *, encoded) != data + 5) {
        return 1;
    }
    STORE_ARCADE_ADDRESS(slot, callback);
    encoded = ((u32)slot[0] << 16) | slot[1];
    ARCADE_ADDRESS_DECODE(Callback, encoded)();

    return (!called || ARCADE_ADDRESS_ENCODE(NULL) != 0 ||
            ARCADE_ADDRESS_DECODE(void *, 0) != NULL ||
            pc_arcade_address_contains((uintptr_t)&slot));
}
