#include "common.h"

typedef struct GalleryFrame
{
  s32 reserved00[2];
  s32 left;
  s32 top;
  s32 right;
  s32 bottom;
  s32 reserved18;
  s32 tileAttributes;
} GalleryFrame;

extern void func_0011BE30(s32 x, s32 y, s32 tileId, s32 tileAttributes, s32 depth);

void func_00124C00(GalleryFrame *frame)
{
  s32 rowState[2];
  s32 x;
  s32 y;
  s32 innerColumns;

  innerColumns = ((frame->right - frame->left) / 16) - 2;
  rowState[1] = (frame->bottom - frame->top) / 32;
  rowState[0] = rowState[1] - 2;
  x = frame->left - 6;
  y = frame->top / 2;
  func_0011BE30(x - 64, y, 0x2289, frame->tileAttributes, 300);
  y += 16;
  for (rowState[1] = 0; rowState[1] < rowState[0]; rowState[1]++)
  {
    func_0011BE30(x - 64, y, 0x228A, frame->tileAttributes, 300);
    y += 16;
  }

  func_0011BE30(x - 64, y, 0x228B, frame->tileAttributes, 300);
  x = frame->left + 10;
  y = frame->top / 2;
  for (rowState[1] = 0; rowState[1] < innerColumns; rowState[1]++)
  {
    func_0011BE30(x - 64, y, 0x2287, frame->tileAttributes, 300);
    x += 16;
  }

  x = frame->left + 10;
  y = (frame->top / 2) + ((rowState[0] + 1) * 16);
  for (rowState[1] = 0; rowState[1] < innerColumns; rowState[1]++)
  {
    func_0011BE30(x - 64, y, 0x2288, frame->tileAttributes, 300);
    x += 16;
  }

  x = frame->left + (((innerColumns + 1) * 16) - 6);
  y = frame->top / 2;
  func_0011BE30(x - 64, y, 0x2284, frame->tileAttributes, 300);
  y += 16;
  for (rowState[1] = 0; rowState[1] < rowState[0]; rowState[1]++)
  {
    func_0011BE30(x - 64, y, 0x2285, frame->tileAttributes, 300);
    y += 16;
  }

  func_0011BE30(x - 64, y, 0x2286, frame->tileAttributes, 300);
}
