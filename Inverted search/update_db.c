#include "invt.h"

int update_db(HashTable *arr, Slist **head, char *filename)
{
    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        return FAILURE;
    }

    int index;
    char word[MAX_WORD_SIZE];
    int file_count;

    while (fscanf(fptr, "#%d;%[^;];%d;", 
                  &index, word, &file_count) != EOF)
    {
        for (int i = 0; i < file_count; i++)
        {
            char fname[MAX_FILE_NAME];
            int count;

            fscanf(fptr, "%[^;];%d;", fname, &count);

            for(int j = 0; j < count; j++)
            {
                insert_word(&arr[index], word, fname);
            }
        }

        fscanf(fptr, "#\n");
    }

    fclose(fptr);

    return SUCCESS;
}