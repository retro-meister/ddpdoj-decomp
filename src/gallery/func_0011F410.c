#include "common.h"

typedef struct 
{
  s32 words[33];
} GalleryDrawBuffer;
typedef struct 
{
  u8 padding000000[0x505034];
  GalleryDrawBuffer drawBuffers[2];
  GalleryDrawBuffer *firstDrawBuffer;
  GalleryDrawBuffer *secondDrawBuffer;
  u8 padding505144[4];
  s32 state;
  u8 padding50514C[0xC];
  s32 fadeStep;
  u8 padding50515C[8];
  s16 overlayEnabled;
  s16 overlayAdjustment;
  u8 padding505168[4];
  s16 fadeState;
  u8 padding50516E;
  s8 drawEnabled;
  u8 padding505170[0x3DC];
  s8 activeBuffer;
  s8 bufferPending;
} GalleryWork;
extern GalleryWork *D_0012B3D8;
extern s32 (*D_00129150[])(void);
extern void func_00121FB0(u8 opacity);
extern void func_00122160(void);
extern s32 func_00123920(GalleryDrawBuffer *buffer, s32 layer);
extern void func_00124E50(s32 x, s32 y, s32 width, s32 height, s32 red, s32 green, s32 blue, s32 alpha, s32 layer);
void func_0011F410(void)
{
  s32 overlayAdjustment;
  GalleryDrawBuffer *drawBuffer;
  s16 fadeState;
  s32 brightness;
  while (D_00129150[D_0012B3D8->state]() != 0)
  {
  }

  if (D_0012B3D8 == 0)
  {
    return;
  }
  if (D_0012B3D8->drawEnabled != 0)
  {
    func_00121FB0(0x80);
    if (D_0012B3D8->overlayEnabled != 0)
    {
      func_00122160();
      overlayAdjustment = D_0012B3D8->overlayAdjustment;
      if (overlayAdjustment != 0)
      {
        func_00121FB0((u8) (0x80 - ((s16) overlayAdjustment)));
      }
    }
    if ((D_0012B3D8->bufferPending != 0) && (func_00123920(&D_0012B3D8->drawBuffers[D_0012B3D8->activeBuffer ^ 1], 0) != 0))
    {
      D_0012B3D8->bufferPending = 0;
    }
    drawBuffer = D_0012B3D8->firstDrawBuffer;
    if (drawBuffer != 0)
    {
      func_00123920(drawBuffer, 0);
    }
    drawBuffer = D_0012B3D8->secondDrawBuffer;
    if (drawBuffer != 0)
    {
      func_00123920(drawBuffer, 1);
    }
  }
  fadeState = D_0012B3D8->fadeState;
  if (fadeState == 0)
  {
    brightness = 0xFF - ((D_0012B3D8->fadeStep * 8 > 0xFF) ? 0xFF : D_0012B3D8->fadeStep * 8);
    func_00124E50(0, 0, 640, 448, brightness, brightness, brightness, 0x80, 2);
  }
  else
    if (fadeState > 8)
  {
    brightness = (D_0012B3D8->fadeStep * 8 > 0xFF) ? 0xFF : D_0012B3D8->fadeStep * 8;
    func_00124E50(0, 0, 640, 448, brightness, brightness, brightness, 0x80, 2);
  }
}
