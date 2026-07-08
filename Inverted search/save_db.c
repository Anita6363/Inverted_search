#include "invt.h"

int save_db(HashTable *arr, char *filename)
{
    FILE *fptr = fopen(filename, "w");

    if (fptr == NULL)
    {
        return FAILURE;
    }

    for (int i = 0; i < HASH_SIZE; i++)
    {
        MainNode *mtemp = arr[i].head;

        while (mtemp != NULL)
        {
            fprintf(fptr, "#%d;%s;%d;", 
                    i, 
                    mtemp->word, 
                    mtemp->file_count);

            SubNode *stemp = mtemp->sub_link;

            while (stemp != NULL)
            {
                fprintf(fptr, "%s;%d;", 
                        stemp->fname, 
                        stemp->word_count);

                stemp = stemp->link;
            }

            fprintf(fptr, "#\n");

            mtemp = mtemp->main_link;
        }
    }

    fclose(fptr);

    printf("Database saved successfully\n");

    return SUCCESS;
}