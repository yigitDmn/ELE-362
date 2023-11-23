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
	circularBuffer->count = 0;
}

int main()
{

	return 0;
}
