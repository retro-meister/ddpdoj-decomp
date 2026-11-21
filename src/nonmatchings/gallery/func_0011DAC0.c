#include "common.h"

typedef struct 
{
  u8 raw[0x20];
  u32 buttons;
  u32 trigger;
  u32 prevButtons;
  u32 rawButtons;
  u16 unk30;
  s8 analogX;
  s8 analogY;
  u8 state;
  u8 padId;
  u8 prevPadId;
  u8 padTypeFlag;
} PadInfo;
extern u8 D_0012B340[6];
extern u8 D_0012B380[6];
extern PadInfo D_001A4F90[3];
extern s32 func_0010C690(s32, s32, u8 *);
extern s32 func_0010C710(s32, s32);
extern s32 func_0010C828(s32, s32);
extern s32 func_0010C8B0(s32, s32, s32, s32);
extern s32 func_0010CAF0(s32, s32, s32, s32);
extern s32 func_0010CC28(s32, s32, s32, s32);
extern s32 func_0010CDA0(s32, s32, u8 *);
extern s32 func_0010CFE0(s32, s32);
extern s32 func_0010D040(s32, s32);
void func_0011DAC0(void)
{
  s32 port;
  PadInfo *pad;
  for (port = 0, pad = D_001A4F90; port < 2; port++, pad++)
  {
    s32 padState;
    pad->rawButtons = 0;
    pad->analogX = 0;
    pad->analogY = 0;
    padState = func_0010C710(port, 0);
    if (padState == 0)
    {
      pad->state = 0;
    }
    switch (pad->state)
    {
      case 0x00:
        if ((padState == 6) || (padState == 2))
      {
        s32 mode = func_0010CAF0(port, 0, 1, 0);
        if (mode != 0)
        {
          s32 exMode = func_0010CAF0(port, 0, 2, 0);
          if (exMode > 0)
          {
            mode = exMode;
          }
          if (mode == 4)
          {
            pad->state = 0x28;
          }
          else
            if (mode == 7)
          {
            pad->state = 0x46;
          }
          else
          {
            pad->state = 0x80;
          }
        }
      }
        break;

      case 0x28:
        if (func_0010CAF0(port, 0, 4, -1) == 0)
      {
        pad->state = 0x80;
        pad->padTypeFlag = 1;
        break;
      }
        pad->state++;

      case 0x29:
        if (func_0010CC28(port, 0, 1, 3) == 1)
      {
        pad->state++;
      }
        break;

      case 0x2A:
        if (func_0010C828(port, 0) == 1)
      {
        pad->state--;
      }
        if (func_0010C828(port, 0) == 0)
      {
        pad->state = 0;
      }
        break;

      case 0x46:
        if (func_0010C8B0(port, 0, -1, 0) == 0)
      {
        pad->state = 0x80;
        pad->padTypeFlag = 2;
        break;
      }
        D_0012B340[0] = (D_0012B380[0] = (D_0012B380[1] = (D_0012B380[2] = (D_0012B380[3] = (D_0012B380[4] = (D_0012B380[5] = 0))))));
        D_0012B340[1] = 1;
        D_0012B340[2] = (D_0012B340[3] = (D_0012B340[4] = (D_0012B340[5] = 0xFF)));
        if (func_0010CDA0(port, 0, D_0012B340) != 0)
      {
        pad->state++;
      }
        break;

      case 0x47:
        if (func_0010C828(port, 0) == 1)
      {
        pad->state--;
      }
        if (func_0010C828(port, 0) == 0)
      {
        pad->state++;
      }
        break;

      case 0x48:
        if (func_0010CFE0(port, 0) == 0)
      {
        pad->prevPadId = 0;
        pad->state = 0x80;
        pad->padTypeFlag = 4;
        break;
      }
        pad->state = 0x4C;

      case 0x4C:
        if (func_0010D040(port, 0) == 0)
      {
        pad->state = 0x48;
      }
      else
      {
        pad->state++;
      }
        break;

      case 0x4D:
        if (func_0010C828(port, 0) == 1)
      {
        pad->state--;
      }
        if (func_0010C828(port, 0) == 0)
      {
        pad->state = 0x80;
        pad->padTypeFlag = 8;
      }
        break;

      case 0x80:
        if ((padState == 6) || (padState == 2))
      {
        u32 rawBtns;
        pad->prevButtons = pad->buttons;
        if (func_0010C690(port, 0, pad->raw) > 0)
        {
          if (pad->padTypeFlag & 0xE)
          {
            s8 rx = pad->raw[4] - 0x80;
            s8 ry = pad->raw[5] - 0x80;
            s8 lx = pad->raw[6] - 0x80;
            s8 ly = pad->raw[7] - 0x80;
            pad->analogX = (((rx >= 0) ? (rx) : (-rx)) > ((lx >= 0) ? (lx) : (-lx))) ? (rx) : (lx);
            pad->analogY = (((ry >= 0) ? (ry) : (-ry)) > ((ly >= 0) ? (ly) : (-ly))) ? (ry) : (ly);
          }
          rawBtns = ((pad->raw[2] << 8) | pad->raw[3]) ^ 0xFFFF;
          pad->rawButtons = rawBtns;
        }
        else
        {
          pad->rawButtons = 0;
          pad->analogX = 0;
          pad->analogY = 0;
          break;
        }
        pad->buttons = rawBtns;
        pad->trigger = (~pad->prevButtons) & rawBtns;
        pad->padId = pad->raw[1];
        if ((pad->prevPadId != 0) && (pad->padId != pad->prevPadId))
        {
          pad->prevPadId = 0;
          pad->state = 0;
        }
        pad->prevPadId = pad->padId;
      }
        break;

    }

  }

  D_001A4F90[2].rawButtons = D_001A4F90[0].rawButtons | D_001A4F90[1].rawButtons;
  D_001A4F90[2].buttons = D_001A4F90[0].buttons | D_001A4F90[1].buttons;
  D_001A4F90[2].trigger = D_001A4F90[0].trigger | D_001A4F90[1].trigger;
  D_001A4F90[2].analogX = (((D_001A4F90[0].analogX >= 0) ? (D_001A4F90[0].analogX) : (-D_001A4F90[0].analogX)) > ((D_001A4F90[1].analogX >= 0) ? (D_001A4F90[1].analogX) : (-D_001A4F90[1].analogX))) ? (D_001A4F90[0].analogX) : (D_001A4F90[1].analogX);
  D_001A4F90[2].analogY = (((D_001A4F90[0].analogY >= 0) ? (D_001A4F90[0].analogY) : (-D_001A4F90[0].analogY)) > ((D_001A4F90[1].analogY >= 0) ? (D_001A4F90[1].analogY) : (-D_001A4F90[1].analogY))) ? (D_001A4F90[0].analogY) : (D_001A4F90[1].analogY);
  D_001A4F90[2].unk30 = D_001A4F90[0].unk30 | D_001A4F90[1].unk30;
}
