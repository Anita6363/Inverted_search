#include "invt.h"

int display_db(HashTable *arr)
{
    MainNode *mtemp;
    SubNode *stemp;

    printf("-----------------------------------------------------------------------------------------\n");
    printf("Index\tWord\t\tFilecount\tFilename\tWordcount\n");
    printf("-----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < HASH_SIZE; i++)
    {
        if (arr[i].head == NULL)
            continue;

        mtemp = arr[i].head;

        while (mtemp != NULL)
        {
            printf("[%d]\t%-15s%d\n", i, mtemp->word, mtemp->file_count);

            stemp = mtemp->sub_link;

            while (stemp != NULL)
            {
                printf("\t\t\t\t%-15s%d\n", stemp->fname, stemp->word_count);
                stemp = stemp->link;
            }

            printf("-----------------------------------------------------------------------------------------\n");

            mtemp = mtemp->main_link;
        }
    }

    return SUCCESS;
}