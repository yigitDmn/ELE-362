#include <stdio.h>

typedef struct
{
	int *ptrBuff;
	int head;
	int tail;
	int size;
	int count;
} CircularBuffer;

void arrangeCircularBuffer(CircularBuffer *circularBuffer, int *buffer, int size)
{
	circularBuffer->ptrBuff = buffer;
	circularBuffer->head = buffer;
	circularBuffer->tail = buffer;
	circularBuffer->size = size;
	circularBuffer->count = 1;
}

void pushItemToBuff(CircularBuffer, int item)
{
}

int main()
{
	CircularBuffer C1;
	int a[] = {1, 2, 3, 4};
	int b = 4;
	arrangeCircularBuffer(&C1, &a[0], b);
	return 0;
}
