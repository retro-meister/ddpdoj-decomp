#include "common.h"

typedef struct 
{
  u8 pad_000000[0x202000];
  u8 flagBuf[0x303154];
  s32 state;
  u8 pad_505158[0x440];
  s32 flagBytePos;
  s32 flagBitPos;
  s32 flagSize;
  s32 dstSize;
  s32 srcSize;
  s32 chunkLimit;
  s32 dstPos;
  s32 srcPos;
} DecompWork;
extern DecompWork *D_0012B3D8;
extern void func_00116EA8(void *dst, void *src, s32 size);
inline static s32 getBits(s32 count)
{
  s32 ret = 0;
  s32 i;
  for (i = 0; i < count; i++)
  {
    if ((D_0012B3D8->flagBuf[D_0012B3D8->flagBytePos] >> D_0012B3D8->flagBitPos) & 1)
    {
      ret += 1 << ((count - 1) - i);
    }
    D_0012B3D8->flagBitPos--;
    if (D_0012B3D8->flagBitPos < 0)
    {
      D_0012B3D8->flagBitPos = 7;
      D_0012B3D8->flagBytePos++;
    }
  }

  return ret;
}

s32 func_00124820(u8 *dst, u8 *src)
{
  s32 copyLen;
  DecompWork *new_var;
  s32 backOffset;
  switch (D_0012B3D8->state)
  {
    case 0: {
      s32 *hdr = (s32 *)src;
      D_0012B3D8->flagSize = hdr[2];
      D_0012B3D8->flagBytePos = 0;
      D_0012B3D8->flagBitPos = 7;
      D_0012B3D8->dstPos = 0;
      D_0012B3D8->srcPos = 0;
      D_0012B3D8->dstSize = hdr[0];
      D_0012B3D8->srcSize = hdr[1];
      D_0012B3D8->chunkLimit = D_0012B3D8->dstSize / 16;
      func_00116EA8(D_0012B3D8->flagBuf, &hdr[3], D_0012B3D8->flagSize);
      D_0012B3D8->srcPos = D_0012B3D8->flagSize + 0xC;
      D_0012B3D8->state++;
      break;
    }

    case 1:
      while (D_0012B3D8->srcPos < D_0012B3D8->srcSize)
    {
      if (getBits(1) != 0)
      {
        copyLen = (src[D_0012B3D8->srcPos + 1] & 0x1F) + 3;
        backOffset = (src[D_0012B3D8->srcPos] << 3) + ((src[D_0012B3D8->srcPos + 1] >> 5) & 7);
        func_00116EA8(&dst[D_0012B3D8->dstPos], (&dst[D_0012B3D8->dstPos]) - backOffset, copyLen);
        D_0012B3D8->dstPos += copyLen;
        D_0012B3D8->srcPos += 2;
      }
      else
      {
        dst[D_0012B3D8->dstPos] = src[D_0012B3D8->srcPos];
        D_0012B3D8->dstPos++;
        D_0012B3D8->srcPos++;
      }
      if (D_0012B3D8->dstPos >= D_0012B3D8->chunkLimit)
      {
        D_0012B3D8->chunkLimit += D_0012B3D8->dstSize / 16;
        if (D_0012B3D8->srcPos < D_0012B3D8->srcSize)
        {
          return 0;
        }
      }
    }

      return 1;

  }

  return 0;
}
