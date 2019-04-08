#include "stdio.h"
#include "stdlib.h"
#include "Reader.h"
#include "List.h"

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


