#include "stdio.h"
#include "stdlib.h"
#include "HistoricalRec.h"
#include "time.h"
#include "string.h"

char strdate[50];

/**Get the local time **/
void getTime()
{
        time_t timep;

        struct tm *p;

        time(&timep);

        p=gmtime(&timep);

        char stringday[20] = {};
        char stringmon[20] = {};
        char stringyear[20] = {};

        itoa(p->tm_mday,stringday,10);
        itoa(1+p->tm_mon,stringmon,10);
        itoa(1900+p->tm_year,stringyear,10);

        strcat (strdate,stringday);
        strcat (strdate,"/");
        strcat (strdate,stringmon);
        strcat (strdate,"/");
        strcat (strdate,stringyear);

        return strdate;
}

void printHisList(His* HispMove)
{
    if(!HispMove)
    {
       return;
    }
    else
    {
       printHisList(HispMove->next);

       printf("    |------------------------------------------------------------------------------------------------|\n");
       printf("    |%d        %15s        %-25s\n",HispMove->Studentnum,HispMove->Studentname,HispMove->date);
       printf("    |------------------------------------------------------------------------------------------------|\n");

       if(HispMove->status == 0)
       {
           printf("    |Borrow:                                                                                         |\n");
           printf("    |------------------------------------------------------------------------------------------------|\n");
       }
       else
       {
           printf("    |Return:                                                                                         |\n");
           printf("    |------------------------------------------------------------------------------------------------|\n");
       }
       printf("    |------------------------------------------------------------------------------------------------|\n");
       printf("    |Books: %s\n",HispMove->booksrentname);
       printf("    |------------------------------------------------------------------------------------------------|\n");
       printf("    |------------------------------------------------------------------------------------------------|\n");
    }

}

/**Adds new historical information**/
void AddRecord(His* his,int Studentnum,char* Studentname,int status,char *bookname)
{

    getTime();

    His *HispAdd = (His*)malloc(sizeof(His));

   	HispAdd->Studentnum = Studentnum;
   	HispAdd->status = status;
    strcpy(HispAdd->date, strdate);
    strcpy(HispAdd->Studentname, Studentname);
    strcpy(HispAdd->booksrentname, bookname);

    HispAdd->next = his->next;

    his->next = HispAdd;

    strdate[0]='\0';

}













