#include "stdio.h"
#include "stdlib.h"
#include "Reader.h"
#include "List.h"

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

void StudentRegister(Reader*reader)
{
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |                           Student Register                                                 |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |Please input your informations£º(as shown below)                                            |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");

            int choice;
            do{
                printf("    |1.Your Name:");

                char name[50];
                scanf("%s",name);

                printf("    |1.Your Id Number:(Leeds College student number, nine digits)");

                char number[10];
                scanf("%s",number);

                printf("    |3.Your Professional full name:(you'd better no more than ten characters)");

                char college[50];
                scanf("%s",college);

                printf("    |--------------------------------------------------------------------------------------------|\n");
                printf("    |--------------------------------------------------------------------------------------------|\n");
                printf("    |Please make sure your information is correct:(We will compare false information later!!)    |\n");
                printf("    |--------------------------------------------------------------------------------------------|\n");
                printf("    |1.Your Name: %s\n",name);
                printf("    |2.Your Id Number: %s\n",number);
                printf("    |3.Your Professional full name: %s\n",college);

                printf("    |Please make sure that we have already got the right information .(1/yes and 0/no and -1/exit)\n");


                scanf("%d",&choice);

                if(choice == 1)
                {
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    printf("    |The information is being processed.........                                                 |\n");
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    addStudent(reader,number,name,college);

                    break;
                }
                else if(choice == -1)
                {
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    printf("    |Preparing to exit.........                                                                  |\n");
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    break;
                }
                else
                {
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    printf("    |Returning to original information page, please re - enter your information........          |\n");
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    fflush(stdin);
                }
            }while(choice != 1 ||choice != -1 );
}

void addStudent(Reader* reader,char* Studentnum,char* Studentname,char* Collegename)
{
    Reader* pAdd = reader->next;

   	strcpy(pAdd->Studentnum, Studentnum);
    strcpy(pAdd->Studentname, Studentname);
    strcpy(pAdd->Collegename, Collegename);
    pAdd = pAdd -> next;
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


