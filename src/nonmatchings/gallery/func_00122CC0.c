#include "common.h"

typedef struct 
{
  u8 unk_0[0x303000];
  u8 unk_303000[0x202154];
  s32 state;
} WorkArea;
typedef struct 
{
  u32 biSize;
  u32 biWidth;
  u32 biHeight;
  u16 biPlanes;
  u16 biBitCount;
  u8 unk_10[0x20];
  u8 loadImage[0x40];
} BmpContext;
typedef struct 
{
  s16 x;
  s16 y;
  s16 w;
  s16 h;
  u64 tex0;
} TexInfo;
extern WorkArea *D_0012B3D8;
extern u8 *D_0012B3E4;
extern u8 *D_0012B3E8;
extern u8 *D_0012B3EC;
extern u8 *D_0012B3F0;
extern u8 *D_0012B3F4;
extern u32 D_0012B3F8;
extern u32 D_0012B3FC;
extern u8 *D_0012B400;
extern u32 D_0012B404;
extern u32 D_0012B408;
extern u32 D_0012B40C;
extern u32 D_0012B410;
extern u32 D_0012B414;
extern u8 *D_0012B418;
extern s32 D_0012B41C;
extern s32 D_0012B420;
extern u32 D_0012B424;
extern s32 D_0012B428;
extern BmpContext D_001C02B0;
extern void func_00100E08(s32, s32);
extern s32 func_00101120(void *, s16, s16, s16, s16, s16, s16, s16);
extern s32 func_00101308(void *, void *);
extern void func_00103220(s32);
extern void *func_00116EA8(void *, void *, u32);
extern void func_001232E0(s16, void *, s32);
s32 func_00122CC0(TexInfo *tex, s16 tbp, s16 cbp, u8 *bmp, s32 x, s32 y)
{
  u32 offBits;
  u32 wPow;
  u32 hPow;
  u32 tw;
  u32 th;
  u8 *src;
  u8 *dst;
  switch (D_0012B3D8->state)
  {
    case 0:
      D_0012B3E4 = bmp;
      D_0012B3E8 = bmp + 0xE;
      func_00116EA8(&D_001C02B0, D_0012B3E8, 0x28);
      D_0012B410 = (((D_001C02B0.biWidth * D_001C02B0.biBitCount) >> 3) + 3) & (~3);
      D_0012B3EC = D_0012B3E8 + 0x28;
      D_0012B414 = D_0012B410;
      func_00116EA8(&offBits, bmp + 0xA, 4);
      D_0012B3F0 = bmp + offBits;
      D_0012B3F0 += (D_001C02B0.biHeight - 1) * D_0012B410;
      D_0012B400 = D_0012B3D8->unk_303000;
      D_0012B3F4 = D_0012B400;
      if (D_001C02B0.biBitCount < 16)
    {
      D_0012B408 = (D_001C02B0.biBitCount == 4) ? (0x14) : (0x13);
      D_0012B40C = 0;
    }
    else
    {
      if (D_001C02B0.biBitCount == 16)
      {
        D_0012B408 = 2;
      }
      else
        if (D_001C02B0.biBitCount == 24)
      {
        D_0012B408 = 1;
      }
      else
      {
        D_0012B408 = 0;
      }
      D_0012B40C = 0;
    }
      D_0012B428 = 0;
      D_0012B3D8->state++;
      break;

    case 1:
      switch (D_001C02B0.biBitCount)
    {
      case 4:
        for (D_0012B3FC = 0; D_0012B3FC < (D_001C02B0.biHeight / 8); D_0012B3FC++)
      {
        src = D_0012B3F0;
        dst = D_0012B3F4;
        for (D_0012B3F8 = 0; D_0012B3F8 < D_0012B410; D_0012B3F8++)
        {
          *(dst++) = ((*src) << 4) | ((*src) >> 4);
          src++;
        }

        D_0012B3F0 -= D_0012B410;
        D_0012B3F4 += D_0012B414;
      }

        break;

      case 8:
        for (D_0012B3FC = 0; D_0012B3FC < (D_001C02B0.biHeight / 8); D_0012B3FC++)
      {
        func_00116EA8(D_0012B3F4, D_0012B3F0, D_0012B410);
        D_0012B3F0 -= D_0012B410;
        D_0012B3F4 += D_0012B414;
      }

        break;

    }

      if ((++D_0012B428) >= 8)
    {
      D_0012B3D8->state++;
    }
      break;

    case 2:
      D_0012B404 = (D_001C02B0.biWidth / 64) + ((D_001C02B0.biWidth % 64) != 0);
      if (D_001C02B0.biBitCount < 16)
    {
      if (D_0012B404 & 1)
      {
        D_0012B404++;
      }
    }
      D_0012B420 = 0;
      do
    {
      D_0012B420++;
      D_0012B424 = D_001C02B0.biHeight >> D_0012B420;
    }
    while ((D_0012B410 * D_0012B424) > 0x7FFF0);
      D_0012B41C = 0;
      D_0012B418 = D_0012B400;
      D_0012B3D8->state++;

    case 3:
      func_00101120(&D_001C02B0.loadImage, tbp, D_0012B404, D_0012B408, x, y + (D_0012B424 * D_0012B41C), D_001C02B0.biWidth, D_0012B424);
      func_00103220(0);
      func_00101308(&D_001C02B0.loadImage, D_0012B418);
      func_00100E08(0, 0);
      D_0012B418 += (D_0012B424 * D_0012B410) & (~0xF);
      if ((++D_0012B41C) >= (1 << D_0012B420))
    {
      D_0012B3D8->state++;
    }
      break;

    case 4:
      if (D_001C02B0.biBitCount < 16)
    {
      func_001232E0(cbp, D_0012B3EC, (D_001C02B0.biBitCount == 4) ? (0x10) : (0x100));
    }
      D_0012B3D8->state++;
      break;

    case 5:
      wPow = 2;
      hPow = 2;
      tw = 1;
      th = 1;
      while ((D_001C02B0.biWidth + x) > wPow)
    {
      wPow <<= 1;
      tw++;
    }

      while ((D_001C02B0.biHeight + y) > hPow)
    {
      hPow <<= 1;
      th++;
    }

      tex->tex0 = (((((((((u64) tbp) | (((u64) D_0012B404) << 14)) | (((u64) D_0012B408) << 20)) | (((u64) tw) << 26)) | (((u64) th) << 30)) | (((u64) 1) << 34)) | (((u64) cbp) << 37)) | (((u64) D_0012B40C) << 51)) | (((u64) 1) << 61);
      tex->x = x;
      tex->y = y;
      tex->w = D_001C02B0.biWidth;
      tex->h = D_001C02B0.biHeight;
      return 1;

  }

  return 0;
}
