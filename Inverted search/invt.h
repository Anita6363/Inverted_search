#ifndef INVT_H
#define INVT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

#define FILE_EMPTY -2
#define FILE_NOT_AVAILABLE -3
#define REPEAT_FILE -4

#define DATABASE_CREATED 1
#define DATABASE_NOT_CREATED 0

#define MAX_WORD_SIZE 50
#define MAX_FILE_NAME 30
#define HASH_SIZE 27

/* File Linked List */
typedef struct file_node
{
    char fname[MAX_FILE_NAME];
    struct file_node *link;
}Slist;

/* Sub Node */
typedef struct sub_node
{
    int word_count;
    char fname[MAX_FILE_NAME];
    struct sub_node *link;
}SubNode;

/* Main Node */
typedef struct main_node
{
    int file_count;
    char word[MAX_WORD_SIZE];
    SubNode *sub_link;
    struct main_node *main_link;
}MainNode;

/* Hash Table */
typedef struct hash_table
{
    int index;
    MainNode *head;
}HashTable;

/* File Validation */
int validate_cla(int argc, char *argv[], Slist **head);
int is_file_empty(FILE *fptr);

/* File Linked List */
int insert_at_last(Slist **head, char *fname);
int print_list(Slist *head);

/* Hash Table */
void insert_ht(HashTable *arr);
int index_find(char *word);

/* Database */
int create_db(Slist *head, HashTable *arr);
int insert_word(HashTable *arr, char *word, char *filename);
int display_db(HashTable *arr);
int search_db(HashTable *arr, char *word);
int save_db(HashTable *arr, char *filename);
int update_db(HashTable *arr, Slist **head, char *filename);

#endif