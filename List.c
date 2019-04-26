#include "stdio.h"
#include "stdlib.h"
#include "List.h"
#include "Reader.h"
#include "string.h"

/**Create header**/
Reader* createList()
{
	Reader* headNode = (Reader*)malloc(sizeof(Reader));
	headNode->next = NULL;
	return headNode;
}

/**Reads data from a file and stores it in a List**/
void readStudent(Reader *reader)
{
    char delims[] = ",";

    FILE *fp=fopen("data/Students.txt","r");

    if(!fp)
    {
        printf("open error");
        return 0;
    }
    int a;

    char b[20],c[50],d[20],e[200];

    int count;

    Reader *pnew;

    while((fscanf(fp,"%d %s %s %s %d",&a,&b,&c,&d,&count))!=EOF)
    {
        fscanf(fp,"\n%[^\n]",&e);

        pnew = (Reader*)malloc(sizeof(Reader));

		pnew->Studentnum = a;
		strcpy(pnew->Studentname, b);
		strcpy(pnew->Collegename, c);
        strcpy(pnew->password, d);

        pnew->BookRentNum = count;

        char *result = NULL;

        result = strtok(e,delims);

        int i = 0;

        while( result != NULL )
        {
           strcpy(pnew->booksrentname[i],result);

           result = strtok(NULL,delims);

           i++;
        }
/*
        printf("pnew->Studentnum = %d\n",pnew->Studentnum);
        printf("pnew->Studentname = %s\n",pnew->Studentname);
        printf("pnew->Collegename = %s\n",pnew->Collegename);

        printf("pnew->password = %s\n",pnew->password);
        printf("pnew->BookRentNum = %d\n\n",pnew->BookRentNum);
*/

		pnew->next = reader->next;
		reader->next = pnew;
    }
    fclose(fp);
}

/**Writes the contents of the quadtree to a file**/
void WriteStudent(Reader* reader)
{
    FILE *fp2=fopen("data/Students.txt","w");

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

        fprintf(fp2,"%d %s %s %s %d\n",pmove->Studentnum,pmove->Studentname,pmove->Collegename,pmove->password,pmove->BookRentNum);

        char BookName[200] = {};

        int i;

        for(i = 0;i < pmove->BookRentNum;i++)
        {
             strcat(BookName,pmove->booksrentname[i]);

             strcat(BookName,",");

         }
         fprintf(fp2,"%s\n\n",BookName);

        pmove=pmove->next;
    }
}

/**Destroy the entire single linked list and free memory**/
void freelist(Reader * reader)
{
    Reader * p;
    while(reader != NULL)
    {
        p = reader;
        reader = reader->next;
        free(p);
        p = NULL;
   }
}
