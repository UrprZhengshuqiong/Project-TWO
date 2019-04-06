#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

struct Readers{
    char Studentnum[20];
    char Studentname[20];
    char Collegename[50];
    char booksrentindex[20];
    char booksrentname[20];
    struct Readers * next;

};

typedef struct Readers Reader;

Reader* createList();

void printList(Reader* pMove);

#endif // LIST_H_INCLUDED
