#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
    uint32_t *ptrBuffer;
    uint32_t head;
    uint32_t tail;
    uint32_t size;
    uint32_t count;
} CircularBuffer;

void arrangeCircularBuffer(CircularBuffer *ptr, uint8_t *buffer, uint32_t size);

void pushItemToBuff(CircularBuffer *ptr, uint8_t item);

_Bool popItemFromBuff(CircularBuffer *ptr, uint8_t *item);

_Bool pickItemFromBuff(CircularBuffer *ptr, uint8_t *item, uint32_t offset);

_Bool isBufferEmpty(CircularBuffer *ptr);

void deleteFromHead(CircularBuffer *ptr);

uint32_t getHead(CircularBuffer *ptr);

uint32_t getCount(CircularBuffer *ptr);

#endif