#include "invt.h"

int insert_at_last(Slist **head, char *fname)
{
    Slist *new = malloc(sizeof(Slist));

    if (new == NULL)
        return FAILURE;

    strcpy(new->fname, fname);
    new->link = NULL;

    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    Slist *temp = *head;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = new;

    return SUCCESS;
}

int print_list(Slist *head)
{
    if (head == NULL)
    {
        printf("INFO : List is empty\n");
        return FAILURE;
    }

    while (head != NULL)
    {
        printf("%s -> ", head->fname);
        head = head->link;
    }

    printf("NULL\n");

    return SUCCESS;
}