#include "circular_buffer.h"

void arrangeCircularBuffer(CircularBuffer *ptr, int *buffer, int size)
{
	ptr->size = size;		 // Bufferın Boyutunun Belirlenmesi
	ptr->ptrBuffer = buffer; // Bufferda Kullanılacak Dizinin Atanması
	ptr->count = 0;			 // Eleman yok
	ptr->head = 0;
	ptr->tail = 0;
}

void pushItemToBuff(CircularBuffer *ptr, int item)
{
	ptr->ptrBuffer[ptr->tail] = item; // Buffer Hala dolmamış ise son kısma veriyi ata
	if (ptr->count < ptr->size)
	{
		ptr->count++; // İçine eleman eklendiği için eleman sayacını arttır.
	}
	else if (ptr->count == ptr->size)
	{
		ptr->head = (ptr->head + 1) % ptr->size;
	}

	ptr->tail = (ptr->tail + 1) % ptr->size; // Eğer tail son elemandaysa tekrar başa dönsün
}

_Bool popItemFromBuff(CircularBuffer *ptr, int *item)
{
	if (ptr->count == 0) // Buferda eleman olmadığı için çıkarma işlemi başarısız
	{
		return 1;
	}

	*item = ptr->ptrBuffer[ptr->head];		 // En baştaki elemanı item değikenine atıyoruz
	ptr->ptrBuffer[ptr->head] = 0;			 // Bufferın bu elemanını sil
	ptr->head = (ptr->head + 1) % ptr->size; // size = 8 olması durumunda head=8 ise 9 değil 1.elemana gitsin
	ptr->count--;							 // Eleman sayısı azaldı

	return 0;
}

_Bool pickItemFromBuff(CircularBuffer *ptr, int *item, int offset)
{
	int tempIndex = (ptr->head + offset) % ptr->size;
	if (tempIndex > ptr->count) // Eğer bu index önceden değer almamışsa değer yok olarak say
	{
		return 1;
	}

	*item = ptr->ptrBuffer[tempIndex - 1];

	return 0;
}

_Bool isBufferEmpty(CircularBuffer *ptr)
{
	return (ptr->count == 0);
}

void deleteFromHead(CircularBuffer *ptr)
{
	ptr->ptrBuffer[ptr->head] = 0;
}

int getHead(CircularBuffer *ptr)
{
	return ptr->head;
}

int getCount(CircularBuffer *ptr)
{
	return ptr->count;
}