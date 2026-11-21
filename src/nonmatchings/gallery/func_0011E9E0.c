#include "common.h"

typedef struct 
{
  s16 next;
  s16 previous;
  s16 value;
  s16 reserved[3];
} LinkEntry;
extern s8 D_001A5240[0x2000];
extern s16 D_001A7240[][6];
extern s16 D_001A7242[][6];
extern s16 D_001A724C[];
extern LinkEntry D_001A7258[0xE2];
extern s8 D_001A7CF0[0x4588];
extern s16 D_001AC282[];
extern s16 D_001AC28C[];
extern LinkEntry D_001AC298[0x401];
void func_0011E9E0(void)
{
  s32 index;
  s32 previousTail;
  LinkEntry *entry;
  s8 *destination = D_001A7CF0;
  LinkEntry *table;
  {
    s32 remaining = sizeof(D_001A7CF0);
    while (remaining--)
    {
      *(destination++) = -1;
    }

  }
  {
    s32 remaining = sizeof(D_001A5240);
    s8 *destination = D_001A5240;
    while (remaining--)
    {
      *(destination++) = -1;
    }

  }
  index = 2;
  entry = D_001AC298;
  do
  {
    entry[0].next = index - 2;
    entry[0].previous = index - 2;
    entry[1].next = index - 1;
    entry[1].previous = index - 1;
    entry[2].next = index;
    entry[2].previous = index;
    entry[3].next = index + 1;
    entry[3].previous = index + 1;
    entry[4].next = index + 2;
    entry[4].previous = index + 2;
    entry[5].next = index + 3;
    entry[5].previous = index + 3;
    entry[6].next = index + 4;
    entry[6].previous = index + 4;
    entry[7].next = index + 5;
    entry[7].previous = index + 5;
    index += 8;
    entry += 8;
  }
  while (index < 0x402);
  D_001AC282[0] = -1;
  table = D_001AC298;
  D_001AC28C[0] = -2;
  for (index = 0; index < 0x401; index++)
  {
    if (index == table[index].previous)
    {
      previousTail = table[-2].previous;
      table[previousTail].next = index;
      table[-2].previous = index;
      table[index].next = -2;
      table[index].previous = previousTail;
      table[index].value = -1;
    }
  }

  entry = D_001A7258;
  index = 2;
  do
  {
    entry[0].next = index - 2;
    entry[0].previous = index - 2;
    entry[1].next = index - 1;
    entry[1].previous = index - 1;
    entry[2].next = index;
    entry[2].previous = index;
    entry[3].next = index + 1;
    entry[3].previous = index + 1;
    entry[4].next = index + 2;
    entry[4].previous = index + 2;
    entry[5].next = index + 3;
    entry[5].previous = index + 3;
    entry[6].next = index + 4;
    entry[6].previous = index + 4;
    entry[7].next = index + 5;
    entry[7].previous = index + 5;
    index += 8;
    entry += 8;
  }
  while (index < 0xDB);
  D_001A7240[index][0] = index - 2;
  D_001A7242[index][0] = index - 2;
  D_001A7242[0][0] = -1;
  table = D_001A7258;
  D_001A724C[0] = -2;
  for (index = 0; index < 0xE2; index++)
  {
    if (index == table[index].previous)
    {
      previousTail = table[-2].previous;
      table[previousTail].next = index;
      table[-2].previous = index;
      table[index].next = -2;
      table[index].previous = previousTail;
      table[index].value = -1;
    }
  }

}
