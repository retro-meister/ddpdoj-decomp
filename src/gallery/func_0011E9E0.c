#include "common.h"

typedef struct 
{
  s16 next;
  s16 previous;
  s16 value;
  s16 reserved[3];
} LinkEntry;
extern s8 D_001A5240[0x2000];
extern LinkEntry D_001A7240[0xE3];
extern s8 D_001A7CF0[0x4588];
extern LinkEntry D_001AC298[0x401];
void func_0011E9E0(void)
{
  LinkEntry *table;
  s32 index;
  s32 i;
  s32 j;
  s32 previousTail;
  {
    s8 *destination = D_001A7CF0;
    s32 remaining = sizeof(D_001A7CF0);
    while (remaining--)
    {
      *(destination++) = -1;
    }

  }
  {
    s8 *destination = D_001A5240;
    s32 remaining = sizeof(D_001A5240);
    while (remaining--)
    {
      *(destination++) = -1;
    }

  }
  {
    LinkEntry *p;
    for (index = 2, p = D_001AC298; index < 0x402; index++, p++)
    {
      p->next = index - 2;
      p->previous = index - 2;
    }

  }
  D_001AC298[-2].previous = -1;
  D_001AC298[-1].next = -2;
  table = D_001AC298;
  for (i = 0; i <= 0x400; i++)
  {
    if (i == table[i].previous)
    {
      previousTail = table[-2].previous;
      table[previousTail].next = i;
      table[-2].previous = i;
      table[i].next = -2;
      table[i].previous = previousTail;
      table[i].value = -1;
    }
  }
  for (index = 2; index < 0xE3; index++)
  {
    D_001A7240[index].next = index - 2;
    D_001A7240[index].previous = index - 2;
  }

  table = &D_001A7240[2];
  D_001A7240[0].previous = -1;
  D_001A7240[1].next = -2;
  for (j = 0; j <= 0xE1; j++)
  {
    if (j == table[j].previous)
    {
      previousTail = table[-2].previous;
      table[previousTail].next = j;
      table[-2].previous = j;
      table[j].next = -2;
      table[j].previous = previousTail;
      table[j].value = -1;
    }
  }
}
