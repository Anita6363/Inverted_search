#include "invt.h"

int create_db(Slist *head, HashTable *arr)
{
    char word[MAX_WORD_SIZE];

    while (head != NULL)
    {
        FILE *fptr = fopen(head->fname, "r");

        if (fptr == NULL)
        {
            head = head->link;
            continue;
        }

        while (fscanf(fptr, "%s", word) != EOF)
        {
            int index = index_find(word);

            insert_word(&arr[index], word, head->fname);
        }

        fclose(fptr);

        head = head->link;
    }

    return SUCCESS;
}

int index_find(char *word)
{
    if (isalpha(word[0]))
    {
        return tolower(word[0]) - 'a';
    }

    return 26;
}