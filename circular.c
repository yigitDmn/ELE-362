#include <stdio.h>

struct CircularBuffer
{
	int *ptrBuff;
	int *head;
	int *tail;
	int size;
	int count;
};

void arrangeCircularBuffer(struct CircularBuffer *circularBuffer, int *buffer, int size)
{
	circularBuffer->ptrBuff = buffer;
	circularBuffer->head = buffer;
	circularBuffer->tail = buffer;
	circularBuffer->size = size;
	circularBuffer->count = 1;
}

void pushItemToBuff(struct CircularBuffer, int item)
{
}

int main()
{
	struct CircularBuffer C1;
	int a[4], b;
	arrangeCircularBuffer(&C1, &a[0], b);
	return 0;
}
