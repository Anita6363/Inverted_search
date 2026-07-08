#include "invt.h"

int validate_cla(int argc, char *argv[], Slist **head)
{
    if (argc < 2)
    {
        printf("ERROR : Pass the file names through command line\n");
        return FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        FILE *fptr = fopen(argv[i], "r");

        if (fptr == NULL)
        {
            printf("INFO : %s is not available\n", argv[i]);
            continue;
        }

        if (is_file_empty(fptr) == FILE_EMPTY)
        {
            printf("INFO : %s is empty\n", argv[i]);
            fclose(fptr);
            continue;
        }

        Slist *temp = *head;

        while (temp != NULL)
        {
            if (strcmp(temp->fname, argv[i]) == 0)
            {
                printf("INFO : %s is repeated\n", argv[i]);
                fclose(fptr);
                goto skip;
            }
            temp = temp->link;
        }

        insert_at_last(head, argv[i]);

skip:
        fclose(fptr);
    }

    if (*head == NULL)
        return FAILURE;

    return SUCCESS;
}

int is_file_empty(FILE *fptr)
{
    fseek(fptr, 0, SEEK_END);

    if (ftell(fptr) == 0)
    {
        rewind(fptr);
        return FILE_EMPTY;
    }

    rewind(fptr);

    return SUCCESS;
}