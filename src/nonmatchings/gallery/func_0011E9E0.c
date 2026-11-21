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
  s32 index;
  s32 previousTail;
  unsigned int new_var2;
  LinkEntry *new_var;
  LinkEntry *table;
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
  for (index = 0; index <= 0x400; index++)
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
  for (index = 2; index < 0xE3; index++)
  {
    D_001A7240[index].next = index - 2;
    D_001A7240[index].previous = index - 2;
  }

  D_001A7240[0].previous = -1;
  D_001A7240[1].next = -2;
  table = &D_001A7240[2];
  for (index = 0; index <= 0xE1; index++)
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
