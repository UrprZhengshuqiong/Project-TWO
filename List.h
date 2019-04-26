#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

/**The structure of student information storage**/
struct Readers{
    int Studentnum;

    char Studentname[20];

    char Collegename[50];

    char booksrentname[200][50];

    char password[50];

    int BookRentNum;

    struct Readers * next;
};

typedef struct Readers Reader;

/**Create a header**/
Reader* createList();

/**The operation of reading and writing files to and from a Singly linked list**/

/**Reads data from a file and stores it in a List**/

void readStudent(Reader *reader);

/**Writes the contents of the quadtree to a file**/

void writeList(Reader *pmove,FILE *fp2);

void WriteStudent(Reader* pwrite);

/**Destroy the entire single linked list and free memory**/

void freeList(Reader *reader);

#endif // LIST_H_INCLUDED
