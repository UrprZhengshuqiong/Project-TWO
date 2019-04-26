#include "stdio.h"
#include "stdlib.h"
#include "Reader.h"
#include "List.h"
#include "Menu.h"
#include "string.h"

extern char RecordStuName[30];

/**Print all registered student information**/
void printList(Reader* pMove)
{
    if(!pMove)
    {
       return;
    }
    else
    {
       printList(pMove->next);

       printf("    |------------------------------------------------------------------------------------------------|\n");
       printf("    |%d        %15s        Major:%-25s\n",pMove->Studentnum,pMove->Studentname,pMove->Collegename);
       printf("    |------------------------------------------------------------------------------------------------|\n");
       printf("    |Own books: (number) %d                                                                           |\n",pMove->BookRentNum);
       printf("    |------------------------------------------------------------------------------------------------|\n");
       int i;

       for(i = 0;i < pMove->BookRentNum;i++)
       {
            printf("    |<<%s>>\n",pMove->booksrentname[i]);
       }
       printf("    |------------------------------------------------------------------------------------------------|\n");
    }
}

/**Enter the information of the registered student**/
void StudentRegister(Reader*reader)
{
            printf("    |------------------------------------------------------------------------------------------------|\n");
            printf("    |                               Student Register                                                 |\n");
            printf("    |------------------------------------------------------------------------------------------------|\n");
            printf("    |Please input your informations:(as shown below)                                                 |\n");
            printf("    |------------------------------------------------------------------------------------------------|\n");

            int choice;
            do{
                printf("    |1.Your Name:(Capitalize first names without Spaces)\n");

                char name[50];
                scanf("%s",name);

                printf("    |1.Your Id Number:(Leeds College student number, nine digits)\n");

                int IdNumber;
                scanf("%d",&IdNumber);

                if(IdNumber < 100000000 || IdNumber >= 1000000000)
                {
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    printf("    |                              Error                                                             |\n");
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    printf("    |Input error. :(                                                                                 |\n");
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    system("pause");
                    break;
                }

                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |3.Your Professional full name:(you'd better no more than ten characters And No Spaces)          |\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");

                char college[50];
                scanf("%s",college);

                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |4.Your password:(Six-digit code)                                                                |\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");

                char password[50];
                getchar();
                gets(password);


                if(strlen(password) != 6)
                {
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    printf("    |                              Error                                                             |\n");
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    printf("    |Input error. :(                                                                                 |\n");
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    system("pause");
                    break;
                }

                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |Please make sure your information is correct:(We will compare false information later!!)        |\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |1.Your Name: %s\n",name);
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |2.Your Id Number: %d\n",IdNumber);
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |3.Your Professional full name: %s\n",college);
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |4.Your password: %s\n",password);
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |Please make sure that we have already got the right information .(1/yes and 0/no and -1/exit)\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");


                scanf("%d",&choice);

                if(choice == 1)
                {
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    printf("    |The information is being processed.........                                                 |\n");
                    printf("    |--------------------------------------------------------------------------------------------|\n");

                    addStudent(reader,IdNumber,name,college,password);

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

/**Check the login information of the students**/
int examStudentPass(Reader* reader,int In_Studentnum,char * password)
{
    Reader* pMove = reader->next;

    while(pMove)
    {

        if( (In_Studentnum == pMove->Studentnum) && (strcmp(password,pMove->password) == 0))
        {
           printf("    |------------------------------------------------------------------------------------------------|\n");
           printf("    |Welcome:%s\n",pMove->Studentname);
           printf("    |------------------------------------------------------------------------------------------------|\n");

           strcpy(RecordStuName,pMove->Studentname);

           return pMove->BookRentNum;
        }
        pMove = pMove->next;
    }
    return -1;
}

/**Modify the loan information of registered students**/
void ModifyLoanInfor(Reader* reader,int In_Studentnum,char * bookname,int status,int BookRentNum)
{
     Reader* pMove = reader->next;

     int i,j;

     while(pMove)
     {
         /**Borrowing a Book**/
        if(In_Studentnum == pMove->Studentnum && status == 0)
        {
          if(pMove->BookRentNum < 3)
          {
              strcpy(pMove->booksrentname[BookRentNum - 1],bookname);

              //printf("pMove->booksrentname[BookRentNum] = %s\n",pMove->booksrentname[BookRentNum]);

              pMove->BookRentNum += 1;

                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |successfully: <<%s>>                                                                        \n",bookname);
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |You have successfully borrowed this book, please go to the window to take out the book.     \n");
                printf("    |------------------------------------------------------------------------------------------------|\n");

          }
          else
          {
              printf("    |------------------------------------------------------------------------------------------------|\n");
              printf("    |Sorry, the number of books you borrow has reached the limit.                                    |\n");
              printf("    |------------------------------------------------------------------------------------------------|\n");
              system("pause");
          }

        }

        /**Return a Book**/

        else if(status == 1)
        {
            for(i = 0;i < pMove->BookRentNum;i++)
            {
                if(strcmp(pMove->booksrentname[i],bookname) == 0)
                {
                    for(j = i;j < pMove->BookRentNum - 1;j++)
                    {
                        strcpy(pMove->booksrentname[j],pMove->booksrentname[j + 1]);
                    }

                    pMove->BookRentNum -- ;

                    break;
                }

            }

        }

        pMove = pMove->next;

      }

}

/**Add a node to a single chain**/
void addStudent(Reader* reader,int Studentnum,char* Studentname,char* Collegename,char * password)
{
    Reader* pAdd = reader->next;

   	pAdd->Studentnum = Studentnum;
    strcpy(pAdd->Studentname, Studentname);
    strcpy(pAdd->Collegename, Collegename);
    strcpy(pAdd->password, password);
    pAdd->BookRentNum = 0;

    pAdd = pAdd -> next;
}

