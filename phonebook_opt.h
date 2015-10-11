#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

 #define OPTIMIZE
#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 42737

typedef unsigned int tableSize;

typedef struct __PHONE_BOOK_LASTNAME {
    char lastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *detail;
    struct __PHONE_BOOK_LASTNAME *pNext;
} entry;

typedef struct __PHONE_BOOK_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
  //  struct __PHONE_BOOK_ENTRY *pNext;
} entryDetail;
 


typedef struct __HASH_TABLE {
	tableSize size;
	entry** hashEntry;
} hashTable;

hashTable *createHashTable(tableSize size);
size_t hash(char *lastName, hashTable *ht);
entry *findName(char lastname[], hashTable *ht);
entry *append(char lastName[], hashTable *ht);
int freeHashTable(hashTable *ht);

 
#endif