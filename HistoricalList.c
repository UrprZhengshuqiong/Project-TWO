#include "stdio.h"
#include "stdlib.h"
#include "HistoricalList.h"
#include "HistoricalRec.h"
#include "string.h"

/**Create a header**/
His* createHisList()
{
	His* hisheadNode = (His*)malloc(sizeof(His));

	hisheadNode->next = NULL;

	return hisheadNode;
}

/**File to write**/
void WriteHistorical(His *his)
{
    FILE *fp2=fopen("data/Historical.txt","w");

    His *pwrite;

    pwrite = (His*)malloc(sizeof(His));


    pwrite = his->next;

    writeHisList(pwrite,fp2);

    fclose(fp2);

    return 0;
}

void writeHisList(His *pmove,FILE *fp2)
{
	if(pmove == NULL)
    {
        return;
    }
    else{

        writeHisList(pmove->next,fp2);

        fprintf(fp2,"%d %s %s %d\n",pmove->Studentnum,pmove->Studentname,pmove->date,pmove->status);

        fprintf(fp2,"%s\n\n",pmove->booksrentname);

        pmove=pmove->next;
    }
}

/**File to read**/
void readHistorical(His *his)
{
    char delims[] = ",";

    FILE *fp=fopen("data/Historical.txt","r");

    if(!fp)
    {
        printf("open error");
        return 0;
    }
    int a,e;

    char b[20],c[50],d[50];


    His *pnew;

    while((fscanf(fp,"%d %s %s %d",&a,&b,&c,&e))!=EOF)
    {
        fscanf(fp,"\n%[^\n]",&d);

        pnew = (His*)malloc(sizeof(His));

		pnew->Studentnum = a;
		strcpy(pnew->Studentname, b);
		strcpy(pnew->date, c);
        strcpy(pnew->booksrentname, d);
        pnew->status = e;
/*
        printf("pnew->Studentnum = %d\n",pnew->Studentnum);
        printf("pnew->Studentname = %s\n",pnew->Studentname);
        printf("pnew->date = %s\n",pnew->date);

        printf("pnew->booksrentname = %s\n",pnew->booksrentname);
        printf(" pnew->status = %d\n\n", pnew->status);
*/

		pnew->next = his->next;

		his->next = pnew;
    }
    fclose(fp);
}

/** free all memory.**/
void freeHisList(His *his)
{
    His * p;
    while(his != NULL)
    {
        p = his;
        his = his->next;
        free(p);
        p = NULL;
   }
}

