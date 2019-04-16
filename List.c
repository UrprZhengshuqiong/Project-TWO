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
       printf("%25s        %s        '%s' \n",pMove->Collegename,pMove->booksrentindex,pMove->booksrentname);
       printf("    |--------------------------------------------------------------------------------------------|\n");
    }
}

void WriteStudent(Reader* reader)
{
    FILE *fp2=fopen("Students.txt","w");

    Reader *pwrite;
    pwrite = (Reader*)malloc(sizeof(Reader));


    pwrite = reader->next;

    writeList(pwrite,fp2);

    fclose(fp2);

    return 0;
}

void writeList(Reader *pmove,FILE *fp2)
{
	if(pmove == NULL)
    {
        return;
    }
    else{
        writeList(pmove->next,fp2);
        fprintf(fp2,"%s %s %s %s %s\n",pmove->Studentnum,pmove->Studentname,pmove->Collegename,pmove->booksrentindex,pmove->booksrentname);
        pmove=pmove->next;
    }
}

void readStudent(Reader *reader)
{
    FILE *fp=fopen("Students.txt","r");
    if(!fp)
    {
        printf("open error");
        return 0;
    }
    char a[20],b[20],c[50],d[20],e[20];

    Reader *pnew;

    while((fscanf(fp,"%s %s %s %s %s",&a,&b,&c,&d,&e))!=EOF)
    {
        pnew = (Reader*)malloc(sizeof(Reader));

		strcpy(pnew->Studentnum, a);
		strcpy(pnew->Studentname, b);
		strcpy(pnew->Collegename, c);
        strcpy(pnew->booksrentindex, d);
		strcpy(pnew->booksrentname, e);

        printf("Welcome readStudent().\n");
        printf("pnew->Studentnum = %s\n",pnew->Studentnum);
        printf("pnew->Studentname = %s\n",pnew->Studentname);
        printf("pnew->Studentname = %s\n",pnew->Collegename);
        printf("pnew->booksrentindex = %s\n",pnew->booksrentindex);
        printf("pnew->booksrentname = %s\n\n",pnew->booksrentname);

		pnew->next = reader->next;
		reader->next = pnew;
    }
    fclose(fp);
}

