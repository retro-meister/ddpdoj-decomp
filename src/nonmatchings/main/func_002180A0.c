#include "common.h"

/* NONMATCHING: 97.8%; regalloc only (nodes/idx a1/a2 swapped vs retail) */

typedef struct {
    s16 prev;
    s16 next;
    s16 key;
    s16 u;
    s16 v;
    s16 w;
} CacheNode;

extern s16 D_0057CF80[];
extern CacheNode D_0057EF98[];

s32 func_002180A0(u16 key) {
    s16 *slots = D_0057CF80;
    CacheNode *nodes = D_0057EF98;
    s16 idx = slots[key];
    CacheNode *node;
    s16 *keyp;
    s16 prev;
    s16 next;
    s16 tail;

    if (idx >= 0) {
        node = &nodes[idx];
        prev = node->prev;
        next = node->next;
        nodes[prev].next = next;
        nodes[next].prev = prev;
        tail = nodes[-1].prev;
        nodes[tail].next = idx;
        node->prev = tail;
        node->next = -1;
        nodes[-1].prev = idx;
        return idx;
    }
    idx = nodes[-2].next;
    if (nodes[idx].key >= 0) {
        slots[nodes[idx].key] = -1;
    }
    nodes[idx].key = key;
    next = nodes[idx].next;
    nodes[-2].next = next;
    nodes[next].prev = -2;
    tail = nodes[-1].prev;
    nodes[tail].next = idx;
    nodes[idx].prev = tail;
    nodes[idx].next = -1;
    nodes[-1].prev = idx;
    slots[key] = idx;
    nodes[idx].u = (idx % 15) * 32 + 16;
    nodes[idx].v = (idx / 15) * 32 + 16;
    nodes[idx].w = 0;
    return idx | 0x8000;
}
