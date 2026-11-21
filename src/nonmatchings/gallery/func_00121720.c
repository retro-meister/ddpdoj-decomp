#include "common.h"

typedef struct 
{
  s16 u;
  s16 v;
  s16 w;
  s16 h;
  u64 tex0;
} SpriteInfo;
typedef struct 
{
  s16 u;
  s16 v;
  s16 w;
  s16 h;
} Rect16;
typedef struct 
{
  u8 buf[0x101000];
  u8 unk_101000[0x303000];
  u8 unk_404000[0x101150];
  s32 state;
  s32 unk_505154;
  u8 pad_505158[0x2E8];
  SpriteInfo unk_505440;
  SpriteInfo unk_505450[6];
  u8 pad_5054B0[0x30];
  SpriteInfo unk_5054E0;
  u8 pad_5054F0[0x60];
  s16 unk_505550[8];
  s16 unk_505560[8];
  s16 unk_505570[8];
  s16 unk_505580[8];
  u8 pad_505590[0x4];
  u8 unk_505594;
  u8 unk_505595;
} GalleryWork;
extern const Rect16 D_0012B0C0[6];
extern const Rect16 D_0012B0F0[6];
extern s8 D_0012B2F0;
extern s8 D_0012B2F4;
extern GalleryWork *D_0012B3D8;
extern s32 D_0012B444;
extern s32 D_001C0344[];
extern s32 D_001C0348[];
extern s32 D_001C034C[];
extern s32 D_001C0350[];
extern void func_0011B6B0(void *buf, s32 size, s32 lsn);
extern s32 func_00122CC0(SpriteInfo *dst, s16 tbp, s16 cbp, void *src, s32 arg4, s32 arg5);
extern s32 func_00124820(void *dst);
static inline u64 getTex0Cbp(u64 tex0)
{
  return (u64) ((s32) ((tex0 >> 37) & 0x3FFF));
}
s32 func_00121720(void)
{
  s32 i;
  s32 size;
  GalleryWork *new_var;
  s32 offset;
  u8 *buf;
  s32 prev;
  s32 cur;
  switch (D_0012B3D8->state)
  {
    new_var = D_0012B3D8;
    case 0:
      D_0012B2F4 = 1;
      D_0012B2F0 = 0;
      D_0012B3D8->state++;

    case 1:
      offset = D_001C0344[0];
      buf = D_0012B3D8->buf;
      size = D_001C0348[0] - offset;
      if (offset != 0)
    {
      offset /= 0x800;
    }
      offset += D_0012B444;
      func_0011B6B0(buf, size, offset);
      if (D_0012B2F4 == 0)
    {
      D_0012B3D8->state++;
    }
      break;

    case 2:
      buf = D_0012B3D8->buf;
      prev = buf[4];
      size = D_001C0348[0] - D_001C0344[0];
      for (i = 5; (i < (size - 5)) != 0; i++)
    {
      cur = buf[i];
      buf[i] = cur - prev;
      prev = cur;
    }

      D_0012B3D8->unk_505154 = 0;
      D_0012B3D8->state++;
      break;

    case 3:
      if (func_00124820(D_0012B3D8->unk_101000) != 0)
    {
      D_0012B3D8->unk_505154 = 0;
      D_0012B3D8->state++;
    }
      break;

    case 4:
      if (func_00122CC0(&D_0012B3D8->unk_505440, 0x1180, 0x1780, D_0012B3D8->unk_101000, 0, 0) != 0)
    {
      D_0012B3D8->state = 10;
    }
      break;

    case 10:
      D_0012B2F0 = 0;
      D_0012B2F4 = 1;
      D_0012B3D8->state++;

    case 11:
      offset = D_001C0348[0];
      buf = D_0012B3D8->buf;
      size = D_001C034C[0] - offset;
      if (offset != 0)
    {
      offset /= 0x800;
    }
      offset += D_0012B444;
      func_0011B6B0(buf, size, offset);
      if (D_0012B2F4 == 0)
    {
      D_0012B3D8->state++;
    }
      break;

    case 12:
      buf = D_0012B3D8->buf;
      prev = buf[4];
      size = D_001C034C[0] - D_001C0348[0];
      for (i = 5; i < (size - 5); i++)
    {
      cur = buf[i];
      buf[i] = cur - prev;
      prev = cur;
    }

      D_0012B3D8->unk_505154 = 0;
      D_0012B3D8->state++;
      if (D_0012B3D8)
    {
    }
      break;

    case 13:
      if (func_00124820(D_0012B3D8->unk_101000) != 0)
    {
      D_0012B3D8->unk_505154 = 0;
      D_0012B3D8->state++;
    }
      break;

    case 14:
      if (func_00122CC0(&D_0012B3D8->unk_5054E0, 0x1380, 0x1784, D_0012B3D8->unk_101000, 0, 0) != 0)
    {
      D_0012B3D8->state = 20;
    }
      break;

    case 20:
      D_0012B2F0 = 0;
      D_0012B2F4 = 1;
      D_0012B3D8->state++;

    case 21:
      offset = D_001C034C[0];
      buf = D_0012B3D8->buf;
      size = D_001C0350[0] - offset;
      if (offset != 0)
    {
      offset /= 0x800;
    }
      offset += D_0012B444;
      func_0011B6B0(buf, size, offset);
      if (D_0012B2F4 == 0)
    {
      D_0012B3D8->state++;
    }
      break;

    case 22:
      buf = D_0012B3D8->buf;
      prev = buf[4];
      size = D_001C0350[0] - D_001C034C[0];
      for (i = 5; i < (size - 5); i++)
    {
      cur = buf[i];
      buf[i] = cur - prev;
      prev = cur;
    }

      D_0012B3D8->unk_505154 = 0;
      D_0012B3D8->state++;
      break;

    case 23:
      if (func_00124820(D_0012B3D8->unk_404000) != 0)
    {
      D_0012B3D8->state = 30;
    }
      break;

    case 30:
      for (i = 0; ((u32) i) < 6; i++)
    {
      SpriteInfo *dst = &D_0012B3D8->unk_505450[i];
      SpriteInfo *src = &D_0012B3D8->unk_5054E0;
      s16 u = D_0012B0C0[i].u;
      s16 v = D_0012B0C0[i].v;
      s16 w = D_0012B0C0[i].w;
      s16 h = D_0012B0C0[i].h;
      *dst = *src;
      dst->tex0 = (dst->tex0 & (~(((u64) 0x3FFF) << 37))) | (getTex0Cbp(src->tex0) << 37);
      dst->u += u;
      dst->v += v;
      dst->w = w;
      dst->h = h;
    }

      for (i = 0; ((u32) i) < 6; i++)
    {
      D_0012B3D8->unk_505550[i] = D_0012B0F0[i].u;
      if (!D_0012B3D8)
      {
      }
      D_0012B3D8->unk_505560[i] = D_0012B0F0[i].v;
      D_0012B3D8->unk_505570[i] = D_0012B0F0[i].w;
      D_0012B3D8->unk_505580[i] = D_0012B0F0[i].h;
    }

      D_0012B3D8->unk_505594 = 2;
      D_0012B3D8->unk_505595 = 2;
      return 1;

  }

  return 0;
}
