#include "invt.h"

int search_db(HashTable *arr, char *word)
{
    int index = index_find(word);

    MainNode *mtemp = arr[index].head;

    while (mtemp != NULL)
    {
        if (strcmp(mtemp->word, word) == 0)
        {
            printf("\nWord Found\n");
            printf("----------------------------\n");
            printf("Word : %s\n", mtemp->word);
            printf("File Count : %d\n", mtemp->file_count);

            SubNode *stemp = mtemp->sub_link;

            while (stemp != NULL)
            {
                printf("File Name : %s\n", stemp->fname);
                printf("Word Count : %d\n", stemp->word_count);

                stemp = stemp->link;
            }

            return SUCCESS;
        }

        mtemp = mtemp->main_link;
    }

    printf("Word not found\n");

    return FAILURE;
}