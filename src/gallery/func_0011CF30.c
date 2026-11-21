
typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef union 
{
  u32 w;
  s32 sw;
  u16 h[2];
  s16 sh[2];
  u8 b[4];
  s8 sb[4];
} Reg32;
extern u16 rng_cursor;
extern s8 rng_values[256];
extern u8 bcd_digits[4];
extern void func_0011C990(void);
extern void func_00101120(void *context, s64 index, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
extern void func_00103220(s32 arg0);
extern void func_00101308(void *context, void *data);
extern void func_00100E08(s32 arg0, s32 arg1);
extern void func_0011E9E0(void);
extern u8 D_00132900[];
extern u8 D_00132980[];
extern u8 D_001A4A80[];
void func_0011CF30(void)
{
  s32 entryIndex;
  u8 *galleryEntry;
  short new_var;
  func_0011C990();
  entryIndex = 0;
  galleryEntry = D_00132980;
  do
  {
    new_var = (s64) (entryIndex + 0x37E8);
    func_00101120(D_001A4A80, new_var, 1, 0, 0, 0, 8, 2);
    func_00103220(0);
    func_00101308(D_001A4A80, galleryEntry);
    func_00100E08(0, 0);
    entryIndex++;
    galleryEntry += 0x40;
  }
  while (entryIndex < 0x11);
  func_00101120(D_001A4A80, 0x37FA, 1, 0, 0, 0, 8, 2);
  func_00103220(0);
  func_00101308(D_001A4A80, D_00132900);
  func_00100E08(0, 0);
  func_0011E9E0();
}
