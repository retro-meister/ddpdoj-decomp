
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
extern u64 D_001A4A80[12];
extern u32 *func_001162D8(u32 size);
extern s32 func_00101120(void *packet, s16 base, s16 bufferWidth, s16 format, s16 x, s16 y, s16 width, s16 height);
extern void func_00103220(s32 mode);
extern s32 func_00101308(void *packet, const void *pixels);
extern s32 func_00100E08(s32 mode, s32 timeout);
extern void func_00116330(void *buffer);
void func_0011D9D0(void)
{
  u32 *buffer;
  u32 wordIndex;
  s32 vramBase;
  u32 blockIndex;
  buffer = func_001162D8(0x40000);
  for (wordIndex = 0; wordIndex < 0x10000; wordIndex++)
  {
    buffer[wordIndex] = 0;
  }

  for (blockIndex = 0, vramBase = 0; blockIndex < 0x10; blockIndex++, vramBase += 0x400)
  {
    func_00101120(D_001A4A80, (s16) vramBase, 4, 0, 0, 0, 0x100, 0x100);
    func_00103220(0);
    func_00101308(D_001A4A80, buffer);
    func_00100E08(0, 0);
  }

  func_00116330(buffer);
}
