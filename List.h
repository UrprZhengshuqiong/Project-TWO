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

void WriteStudent(Reader* pwrite);

void writeList(Reader *pmove,FILE *fp2);

void readStudent(Reader *reader);

#endif // LIST_H_INCLUDED
