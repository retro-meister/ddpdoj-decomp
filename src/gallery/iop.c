#include "common.h"

extern const char D_0012AE30[];
extern const char D_0012AE50[];
extern const char D_0012AE70[];
extern const char D_0012AE90[];
extern const char D_0012AEB0[];
extern const char D_0012AED0[];
extern const char D_0012AEF0[];
extern const char D_0012AF10[];
extern const char D_0012AF30[];

extern void func_001057E8(s32 mode);
extern s32 func_00107108(void);
extern s32 func_0010A8F8(const char *modulePath, s32 argumentSize, const char *arguments);
extern s32 func_0010ADC0(void);
extern s32 func_0010ADF8(const char *imagePath);
extern s32 func_0010E188(s32 mode);
extern s32 func_0010E468(s32 mode);
extern s32 func_0010E650(s32 mediaMode);
extern s32 func_00118268(const char *format, ...);

void func_0011E870(void)
{
    func_001057E8(0);
    func_0010E188(0);
    func_0010E650(2);

    do {
    } while (!func_0010ADF8(D_0012AE30));

    do {
    } while (!func_0010ADC0());

    func_001057E8(0);
    func_0010E188(0);
    func_0010E650(2);
    func_00107108();
    func_0010E468(0);
    func_00118268(D_0012AE50);

    do {
    } while (func_0010A8F8(D_0012AE70, 0, 0) < 0);

    do {
    } while (func_0010A8F8(D_0012AE90, 0, 0) < 0);

    do {
    } while (func_0010A8F8(D_0012AEB0, 0, 0) < 0);

    do {
    } while (func_0010A8F8(D_0012AED0, 0, 0) < 0);

    do {
    } while (func_0010A8F8(D_0012AEF0, 0, 0) < 0);

    do {
    } while (func_0010A8F8(D_0012AF10, 0, 0) < 0);

    func_00118268(D_0012AF30);
}
