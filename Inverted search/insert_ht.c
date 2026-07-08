#include "invt.h"

void insert_ht(HashTable *arr)
{
    for(int i = 0; i < HASH_SIZE; i++)
    {
        arr[i].index = i;
        arr[i].head = NULL;
    }
}