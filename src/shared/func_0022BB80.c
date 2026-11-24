#include "common.h"

typedef struct {
    u8 stat;
    u8 second;
    u8 minute;
    u8 hour;
    u8 pad;
    u8 day;
    u8 month;
    u8 year;
} CdClock;

s32 func_0010EB50(CdClock *clock);

#define FROM_BCD(x) (((x) & 0xF) + ((x) >> 4) * 10)

s32 func_0022BB80(u8 *out)
{
    CdClock clock;

    if (func_0010EB50(&clock) != 0) {
        out[0] = FROM_BCD(clock.month);
        out[1] = FROM_BCD(clock.day);
        out[2] = FROM_BCD(clock.hour);
        out[3] = FROM_BCD(clock.minute);
        out[4] = FROM_BCD(clock.second);
        return 0;
    }
    return clock.stat;
}
