#ifndef HISTORICALLIST_H_INCLUDED
#define HISTORICALLIST_H_INCLUDED

/**A structure for recording historical lending information**/
struct Historical{

    int Studentnum;
    char Studentname[20];
    char booksrentname[50];
    char date[100];

    int status;
    struct Historical * next;

};

typedef struct Historical His;

/**Create a header**/
His * createHisList();

/**File to write**/
void WriteHistorica(His *his);

void writeHisList(His *pmove,FILE *fp2);

/**File to read**/
void readHistorical(His *his);

/**Destroy the entire single linked list and free memory**/
void freeHisList(His *his);

#endif // HISTORICALLIST_H_INCLUDED



