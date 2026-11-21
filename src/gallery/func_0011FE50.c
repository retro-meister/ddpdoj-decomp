#include "common.h"

typedef struct 
{
  s16 u;
  s16 v;
  s16 width;
  s16 height;
  u64 tex0;
} ThumbSprite;
typedef struct 
{
  u8 pad0[0x404000];
  u8 textureBuffer[0x101000];
  s32 cursor;
  u8 pad505004[0x144];
  s32 nextMode;
  s32 state;
  s32 unk505150;
  s32 unk505154;
  s32 timer;
  s32 countdown;
  s32 exitMode;
  s16 visible;
  s16 fadeAlpha;
  u8 pad505168[4];
  s16 displayMode;
  s8 dialogState;
  u8 pad50516F;
  ThumbSprite pageSprites[6];
  ThumbSprite allSprites[38];
  u8 pad505430[0x100];
  s32 unk505530;
  u8 pad505534[4];
  s16 scrollX;
  s16 scrollDirection;
  s32 slotIndex;
  s32 itemCount;
  s32 pageOffset;
  s32 currentThumbId;
  u8 pad50554C[2];
  s8 isInitialized;
  s8 dialogChoice;
  u8 pad505550[0x68];
  u8 itemStatus[0x100];
  u8 itemThumbIds[0x100];
  u8 slotFlags[6];
} GalleryState;
extern GalleryState *D_0012B3D8;
extern u32 D_001A5000[];
extern u32 D_001A5020[];
extern u32 D_001A5024[];
extern s8 D_001C0B40[];
extern void func_0011AF70(void);
extern void func_0011AF90(void);
extern void func_0011AFB0(void);
extern s32 func_00122CC0(ThumbSprite *, s16, s16, void *, s32, s32);
extern void func_001236D0(s32, s32, s32, s32);
extern s32 func_001246C0(s32 *, void *);
static inline u64 getTex0Cbp(u64 tex0)
{
  return (u64) ((s32) ((tex0 >> 37) & 0x3FFF));
}

s32 func_0011FE50(void)
{
  ThumbSprite atlasSprite;
  s32 thumbnailIndex;
  s32 previousCursor;
  s32 menuResult;
  switch (D_0012B3D8->state)
  {
    case 0:
      D_0012B3D8->isInitialized = 0;
      D_0012B3D8->state = 3;

    case 3:
      D_0012B3D8->unk505154 = 0;
      while (!func_00122CC0(&atlasSprite, 0x1788, 0x2788, D_0012B3D8->textureBuffer, 0, 0))
    {
    }

      for (thumbnailIndex = 0; thumbnailIndex < 37; thumbnailIndex++)
    {
      ThumbSprite *sprite = &D_0012B3D8->allSprites[thumbnailIndex];
      *sprite = atlasSprite;
      sprite->tex0 = (sprite->tex0 & (~(((u64) 0x3FFF) << 37))) | (getTex0Cbp(atlasSprite.tex0) << 37);
      sprite->u += (s16) ((thumbnailIndex & 7) * 128);
      sprite->v += (s16) ((thumbnailIndex >> 3) * 90);
      sprite->width = 128;
      sprite->height = 90;
    }

      D_0012B3D8->timer = 0;
      D_0012B3D8->visible = 1;
      D_0012B3D8->scrollX = 0x38;
      D_0012B3D8->unk505530 = 0;
      for (D_0012B3D8->slotIndex = 0; D_0012B3D8->slotIndex < 6; D_0012B3D8->slotIndex++)
    {
      s32 itemIndex = D_0012B3D8->pageOffset + D_0012B3D8->slotIndex;
      s32 thumbnailId;
      if (itemIndex >= D_0012B3D8->itemCount)
      {
        break;
      }
      thumbnailId = D_0012B3D8->itemThumbIds[itemIndex];
      if (thumbnailId > 37)
      {
        thumbnailId = 0;
      }
      D_0012B3D8->currentThumbId = thumbnailId;
      D_0012B3D8->pageSprites[D_0012B3D8->slotIndex] = D_0012B3D8->allSprites[D_0012B3D8->currentThumbId];
      if (D_001C0B40[D_0012B3D8->currentThumbId] != 0)
      {
        D_0012B3D8->slotFlags[D_0012B3D8->slotIndex] = 4;
      }
      else
      {
        D_0012B3D8->slotFlags[D_0012B3D8->slotIndex] = 1;
      }
    }

      if (D_0012B3D8->isInitialized == 0)
    {
      D_0012B3D8->state = 10;
      return 1;
    }
      D_0012B3D8->state = 19;
      break;

    case 10:
      D_0012B3D8->fadeAlpha = 0;
      D_0012B3D8->state++;

    case 11:
      D_0012B3D8->fadeAlpha += 4;
      if (D_0012B3D8->fadeAlpha >= 0x80)
    {
      D_0012B3D8->isInitialized = 1;
      D_0012B3D8->fadeAlpha = 0;
      D_0012B3D8->state = 19;
    }
      break;

    case 19:
      D_0012B3D8->unk505530 = 0;
      D_0012B3D8->displayMode = 1;
      D_0012B3D8->unk505150 = 0;
      D_0012B3D8->state++;

    case 20:
      previousCursor = D_0012B3D8->cursor;
      menuResult = func_001246C0(&D_0012B3D8->cursor, D_001A5000);
      if (menuResult != 0)
    {
      if (menuResult < 0x100)
      {
        int directionButtons;
        D_0012B3D8->unk505530 = 0;
        if (D_0012B3D8->itemCount <= 6)
        {
          break;
        }
        directionButtons = D_001A5020[0];
        if ((directionButtons & 0x8000) && ((previousCursor == 0) || (previousCursor == 3)))
        {
          D_0012B3D8->cursor = previousCursor + 2;
          D_0012B3D8->scrollDirection = -1;
          D_0012B3D8->pageOffset -= 6;
          if (D_0012B3D8->pageOffset < 0)
          {
            D_0012B3D8->pageOffset = ((D_0012B3D8->itemCount - 1) / 6) * 6;
          }
          D_0012B3D8->state = 29;
          return 1;
        }
        if ((directionButtons & 0x2000) && ((previousCursor == 2) || (previousCursor == 5)))
        {
          D_0012B3D8->cursor = previousCursor - 2;
          D_0012B3D8->scrollDirection = 1;
          D_0012B3D8->pageOffset += 6;
          if (D_0012B3D8->pageOffset >= D_0012B3D8->itemCount)
          {
            D_0012B3D8->pageOffset = 0;
          }
          D_0012B3D8->state = 29;
          return 1;
        }
        func_0011AF70();
      }
      else
      {
        s32 itemIndex = D_0012B3D8->cursor + D_0012B3D8->pageOffset;
        if ((itemIndex < D_0012B3D8->itemCount) && (D_0012B3D8->itemStatus[itemIndex] == 2))
        {
          func_0011AFB0();
          D_0012B3D8->exitMode = 3;
          D_0012B3D8->state = 100;
        }
      }
    }
    else
    {
      u32 buttons = D_001A5024[0];
      if (buttons & 0x40)
      {
        func_0011AFB0();
        D_0012B3D8->state = 40;
        break;
      }
      else
        if (buttons & 0x4)
      {
        if (D_0012B3D8->itemCount <= 6)
        {
          break;
        }
        D_0012B3D8->scrollDirection = -1;
        D_0012B3D8->pageOffset -= 6;
        if (D_0012B3D8->pageOffset < 0)
        {
          D_0012B3D8->pageOffset = ((D_0012B3D8->itemCount - 1) / 6) * 6;
        }
        D_0012B3D8->state = 29;
        return 1;
      }
      else
        if (buttons & 0x8)
      {
        if (D_0012B3D8->itemCount <= 6)
        {
          break;
        }
        D_0012B3D8->scrollDirection = 1;
        D_0012B3D8->pageOffset += 6;
        if (D_0012B3D8->pageOffset >= D_0012B3D8->itemCount)
        {
          D_0012B3D8->pageOffset = 0;
        }
        D_0012B3D8->state = 29;
        return 1;
      }
    }
      D_0012B3D8->timer++;
      break;

    case 29:
      D_0012B3D8->timer = 0;
      D_0012B3D8->unk505530 = 0;
      func_0011AF90();
      D_0012B3D8->displayMode = 2;
      D_0012B3D8->countdown = 0x20;
      D_0012B3D8->state = 30;

    case 30:
      D_0012B3D8->timer++;
      D_0012B3D8->scrollX -= (s16) (D_0012B3D8->timer * D_0012B3D8->scrollDirection);
      if ((--D_0012B3D8->countdown) == 0)
    {
      D_0012B3D8->state = 3;
    }
      break;

    case 40:
      D_0012B3D8->dialogState = 1;
      D_0012B3D8->displayMode = 2;
      D_0012B3D8->countdown = 0x10;
      D_0012B3D8->dialogChoice = 1;
      func_001236D0(-1, 0, 0, 0);
      D_0012B3D8->state++;

    case 41:
      if (D_001A5024[0] & 0x8000)
    {
      if (menuResult = D_0012B3D8->dialogChoice != 0)
      {
        func_0011AF70();
      }
      D_0012B3D8->dialogChoice = 0;
    }
      if (D_001A5024[0] & 0x2000)
    {
      if (D_0012B3D8->dialogChoice != 1)
      {
        func_0011AF70();
      }
      D_0012B3D8->dialogChoice = 1;
    }
      if (D_001A5024[0] & 0x20)
    {
      func_0011AFB0();
      if (D_0012B3D8->dialogChoice == 0)
      {
        D_0012B3D8->dialogState = -1;
        D_0012B3D8->state = 100;
        D_0012B3D8->exitMode = 4;
      }
      else
      {
        D_0012B3D8->dialogState = 0;
        D_0012B3D8->displayMode = 1;
        D_0012B3D8->state = 20;
      }
    }
      if (D_001A5024[0] & 0x40)
    {
      func_0011AFB0();
      D_0012B3D8->dialogState = 0;
      D_0012B3D8->displayMode = 1;
      D_0012B3D8->state = 20;
    }
      break;

    case 100:
      D_0012B3D8->fadeAlpha = 0x80;
      D_0012B3D8->state++;

    case 101:
      D_0012B3D8->fadeAlpha -= 4;
      if (D_0012B3D8->fadeAlpha <= 0)
    {
      D_0012B3D8->visible = 0;
      D_0012B3D8->nextMode = D_0012B3D8->exitMode;
      D_0012B3D8->state = 0;
    }
      break;

  }

  return (unsigned long) 0;
}
