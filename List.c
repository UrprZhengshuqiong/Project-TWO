#include "stdio.h"
#include "stdlib.h"
#include "List.h"
#include "Reader.h"

Reader* createList()
{
	Reader* headNode = (Reader*)malloc(sizeof(Reader));
	headNode->next = NULL;
	return headNode;
}

void printList(Reader* pMove)
{
    if(!pMove)
    {
       return;
    }
    else
    {
       printList(pMove->next);
       printf("    |");
       printf("%s        %10s",pMove->Studentnum,pMove->Studentname,pMove->Collegename,pMove->booksrentindex,pMove->booksrentname);
       printf("%25s        %s        ¡¶%s¡·\n",pMove->Collegename,pMove->booksrentindex,pMove->booksrentname);
       printf("    |--------------------------------------------------------------------------------------------|\n");
    }
}
