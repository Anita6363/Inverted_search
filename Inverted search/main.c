#include "invt.h"

int main(int argc, char *argv[])
{
    Slist *head = NULL;
    HashTable arr[HASH_SIZE];

    int choice;
    int db_status = DATABASE_NOT_CREATED;
    char word[MAX_WORD_SIZE];
    char filename[MAX_FILE_NAME];

    if (validate_cla(argc, argv, &head) == FAILURE)
    {
        printf("File validation failed\n");
        return FAILURE;
    }

    insert_ht(arr);

    while (1)
    {
        printf("\n1.Create Database\n");
        printf("2.Display Database\n");
        printf("3.Search Database\n");
        printf("4.Save Database\n");
        printf("5.Update Database\n");
        printf("6.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (create_db(head, arr) == SUCCESS)
                {
                    db_status = DATABASE_CREATED;
                    printf("Database created successfully\n");
                }
                break;

            case 2:
                if (db_status == DATABASE_CREATED)
                    display_db(arr);
                else
                    printf("Create database first\n");
                break;

            case 3:
                if (db_status == DATABASE_CREATED)
                {
                    printf("Enter word : ");
                    scanf("%s", word);
                    search_db(arr, word);
                }
                else
                    printf("Create database first\n");
                break;

            case 4:
                if (db_status == DATABASE_CREATED)
                {
                    printf("Enter file name : ");
                    scanf("%s", filename);
                    save_db(arr, filename);
                }
                else
                    printf("Create database first\n");
                break;

            case 5:
                printf("Enter backup file name : ");
                scanf("%s", filename);

                if (update_db(arr, &head, filename) == SUCCESS)
                {
                    db_status = DATABASE_CREATED;
                    printf("Database updated successfully\n");
                }
                else
                {
                    printf("Update failed\n");
                }
                break;

            case 6:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}