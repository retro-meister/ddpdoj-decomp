#include "common.h"

extern u8 *D_0012B3D8;
extern void *func_00116EA8(void *destination, const void *source, u32 size);
extern void *func_00117060(void *destination, s32 value, u32 size);
extern void func_00101120(void *packet, s32 destinationBase, s32 destinationWidth, s32 pixelFormat, s32 x, s32 y, s32 width, s32 height);
extern void func_00103220(s32 mode);
extern void func_00101308(void *packet, const void *pixels);
extern s32 func_00100E08(s32 mode, s32 timeout);
void func_001232E0(s32 destinationBase, const void *palette, s32 colorCount)
{
  u64 loadPacket[12];
  u8 paletteCopy[0x400];
  u8 *new_var[2];
  u8 *swizzledPalette;
  u8 *sourceColor;
  u8 *swizzledBlock;
  s32 colorIndex;
  s32 row;
  func_00116EA8(paletteCopy, palette, colorCount * 4);
  new_var[1] = D_0012B3D8 + 0x303000;
  sourceColor = paletteCopy;
  func_00117060(new_var[1], 0, 0x400);
  new_var[0] = new_var[1];
  for (colorIndex = 0; colorIndex < colorCount; colorIndex++, sourceColor += 4)
  {
    if ((sourceColor[2] || sourceColor[1]) || sourceColor[0])
    {
      new_var[0][0] = sourceColor[2];
      new_var[0][1] = sourceColor[1];
      new_var[0][2] = sourceColor[0];
      new_var[0][3] = 0x80;
      new_var[0] += 4;
    }
    else
    {
      new_var[0] += 4;
    }
  }

  swizzledPalette = D_0012B3D8 + 0x303400;
  row = 0;
  swizzledBlock = swizzledPalette;
  do
  {
    func_00116EA8(swizzledBlock, new_var[1], 0x20);
    func_00116EA8(swizzledBlock + 0x20, new_var[1] + 0x40, 0x20);
    func_00116EA8(swizzledBlock + 0x40, new_var[1] + 0x20, 0x20);
    func_00116EA8(swizzledBlock + 0x60, new_var[1] + 0x60, 0x20);
    row += 2;
    swizzledBlock += 0x80;
    new_var[1] += 0x80;
  }
  while (row < 16);
  func_00101120(loadPacket, destinationBase, 1, 0, 0, 0, 16, 16);
  func_00103220(0);
  func_00101308(loadPacket, (0, swizzledPalette));
  func_00100E08(0, 0);
}
