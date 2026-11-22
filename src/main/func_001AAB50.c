#include "common.h"

extern s32 *D_0028E464;
extern s32 *D_0028E468;
extern s32 D_0028E72C;
extern s32 D_0028E734;
void func_001AAB90(void);

void func_001AAB50(void) {
    D_0028E468 = &D_0028E734;
    D_0028E464 = &D_0028E72C;
    func_001AAB90();
}
