#include "common.h"

typedef struct 
{
  u8 red;
  u8 green;
  u8 blue;
  u8 alpha;
} PaletteColor;
extern u8 D_00128F40[];
extern u8 D_00128F50[];
extern u8 D_00128FD0[];
extern PaletteColor D_00132900[];
extern PaletteColor D_00132980[];
extern u8 D_001A0A80[32][512];
extern void func_0011CBA0(s32 paletteIndex);
extern void func_0011CD30(s32 paletteIndex);
void func_0011C990(void)
{
  s32 colorIndex;
  s32 paletteIndex;
  s32 rgbOffset;
  s32 column;
  for (colorIndex = 0; colorIndex < 16; colorIndex++)
  {
    column = D_00128F50[colorIndex];
    D_00132980[colorIndex].red = (D_00132980[colorIndex].green = (D_00132980[colorIndex].blue = column));
    D_00132980[colorIndex].alpha = D_00128F40[colorIndex];
  }

  paletteIndex = 1;
  first_palette:
  func_0011CD30(paletteIndex);

  if ((++paletteIndex) < 9)
  {
    goto first_palette;
  }
  paletteIndex = 9;
  second_palette:
  func_0011CBA0(paletteIndex);

  if ((++paletteIndex) < 17)
  {
    goto second_palette;
  }
  for (rgbOffset = 0, colorIndex = 0; colorIndex < 16; colorIndex++)
  {
    D_00132900[colorIndex].red = D_00128FD0[rgbOffset++];
    D_00132900[colorIndex].green = D_00128FD0[rgbOffset++];
    D_00132900[colorIndex].blue = D_00128FD0[rgbOffset++];
    if (colorIndex == 0)
    {
      D_00132900[colorIndex].alpha = 0;
    }
    else
    {
      D_00132900[colorIndex].alpha = 0x80;
    }
  }

  for (rgbOffset = 0; rgbOffset < 32; rgbOffset++)
  {
    for (column = 0; column < 512; column++)
    {
      D_001A0A80[rgbOffset][column] = 16 * 0;
    }

  }

}
