#include "invt.h"

int insert_word(HashTable *arr, char *word, char *filename)
{
    //int index = index_find(word);

    MainNode *temp = arr->head;

    // Main node search
    while(temp != NULL)
    {
        if(strcmp(temp->word, word) == 0)
        {
            SubNode *sub_temp = temp->sub_link;

            // File already present
            while(sub_temp != NULL)
            {
                if(strcmp(sub_temp->fname, filename) == 0)
                {
                    sub_temp->word_count++;
                    return SUCCESS;
                }

                sub_temp = sub_temp->link;
            }

            // New file for existing word
            SubNode *new_sub = malloc(sizeof(SubNode));

            strcpy(new_sub->fname, filename);
            new_sub->word_count = 1;
            new_sub->link = temp->sub_link;

            temp->sub_link = new_sub;
            temp->file_count++;

            return SUCCESS;
        }

        temp = temp->main_link;
    }


    // New word creation
    MainNode *new_main = malloc(sizeof(MainNode));

    strcpy(new_main->word, word);
    new_main->file_count = 1;

    SubNode *new_sub = malloc(sizeof(SubNode));

    strcpy(new_sub->fname, filename);
    new_sub->word_count = 1;
    new_sub->link = NULL;


    new_main->sub_link = new_sub;

    new_main->main_link = arr->head;

    arr->head = new_main;


    return SUCCESS;
}