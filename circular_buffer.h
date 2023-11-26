#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>

typedef struct
{
    int *ptrBuffer;
    int head;
    int tail;
    int size;
    int count;
} CircularBuffer;

void arrangeCircularBuffer(CircularBuffer *ptr, int *buffer, int size);

void pushItemToBuff(CircularBuffer *ptr, int item);

_Bool popItemFromBuff(CircularBuffer *ptr, int *item);

_Bool pickItemFromBuff(CircularBuffer *ptr, int *item, int offset);

_Bool isBufferEmpty(CircularBuffer *ptr);

void deleteFromHead(CircularBuffer *ptr);

int getHead(CircularBuffer *ptr);

int getCount(CircularBuffer *ptr);

#endif