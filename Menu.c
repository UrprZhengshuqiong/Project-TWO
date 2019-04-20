#include "stdio.h"
#include "stdlib.h"
#include "Menu.h"
#include "Tree.h"
#include "List.h"

void Begin(Node *head,Reader *reader)
{
    int choice;
    int door = 0;
    int listdoor = 0;
    do
    {
         printf("    |------------------------------------------------------------------------------------------------|\n");
         printf("    |                           Library management system                                            |\n");
         printf("    |------------------------------------------------------------------------------------------------|\n");
         printf("    | Please choose whether you are an employee or a student.(1 or 2)                                |\n");
         printf("    |------------------------------------------------------------------------------------------------|\n");
         printf("    | 1.I am a student.                                                                              |\n");
         printf("    | 2.I am a staff.                                                                                |\n");
         printf("    | 3.Exit.                                                                                        |\n");
         printf("    |------------------------------------------------------------------------------------------------|\n");

         scanf("%d",&choice);

        int comeIn = 0;

        while(choice == 1 && comeIn == 0)
        {
            printf("    |------------------------------------------------------------------------------------------------|\n");
            printf("    |                             For student                                                        |\n");
            printf("    |------------------------------------------------------------------------------------------------|\n");
            printf("    |Please choose what you want:(select number)                                                     |\n");
            printf("    |------------------------------------------------------------------------------------------------|\n");
            printf("    |1.Register with the library.                                                                    |\n");
            printf("    |2.List all books.                                                                               |\n");
            printf("    |3.Search for books.                                                                             |\n");
            printf("    |4.Borrow a book.                                                                                |\n");
            printf("    |5.Return a book.                                                                                |\n");
            printf("    |6.Exit.                                                                                         |\n");
            printf("    |------------------------------------------------------------------------------------------------|\n");

            int stuChoice;
            scanf("%d",&stuChoice);

            switch(stuChoice)
            {
                case 1:
                       StudentRegister(reader);
                    break;

                case 2:
                       printf("    |------------------------------------------------------------------------------------------------|\n");
                       printf("    |Book catalogues and borrowing information                                                       |\n");
                       printf("    |------------------------------------------------------------------------------------------------|\n");
                       Listallbook(head);
                    break;

                case 3:
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    printf("    |Please enter the book you want to find:                                                         |\n");
                    printf("    |------------------------------------------------------------------------------------------------|\n");

                    ExiorNot3 = -1;


                    do
                    {
                           char book[50];
                           scanf("%s",book);
                           Searchforbooks(head,book);

                           if(ExiorNot3 == -1)
                           {
                              printf("    |------------------------------------------------------------------------------------------------|\n");
                              printf("    |Please enter the correct title and it's unable to find the correct book.                        |\n");
                              printf("    |------------------------------------------------------------------------------------------------|\n");
                              fflush(stdin);
                           }
                           else
                           {
                               break;
                           }

                    }while(ExiorNot3 == -1);
                    break;

                case 4:
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    printf("    |Please enter the book you want to Borrow:                                                       |\n");
                    printf("    |------------------------------------------------------------------------------------------------|\n");

                    ExiorNot4 = -1;


                    do
                    {
                           char Bbook[50];
                           scanf("%s",Bbook);

                           Borrowingbooks(head,Bbook);

                           if(ExiorNot4 == -1)
                           {
                              printf("    |------------------------------------------------------------------------------------------------|\n");
                              printf("    |Please enter the correct title again and it's unable to find the correct book:                  |");
                              printf("    |------------------------------------------------------------------------------------------------|\n");
                              fflush(stdin);
                           }
                    }while(ExiorNot4 == -1);
                    break;

                case 5:
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    printf("    |Please enter the book you want to return:                                                   |\n");
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    ExiorNot5 = -1;

                    do
                    {
                           char Rbook[50];
                           scanf("%s",Rbook);

                            ReturnaBook(head,Rbook);

                           if(ExiorNot5 == -1)
                           {
                              printf("    |Please enter the correct title again and it's unable to find the correct book:    |");
                              fflush(stdin);
                           }
                    }while(ExiorNot5 == -1);

                    break;

                case 6:
                    comeIn = 1;
                    break;
            }
        }

        while(choice == 2 && comeIn == 0)
        {
            printf("    |------------------------------------------------------------------------------------------------|\n");
            printf("    |                              For staff                                                         |\n");
            printf("    |------------------------------------------------------------------------------------------------|\n");
            printf("    |Please choose what you want:(select number)                                                     |\n");
            printf("    |------------------------------------------------------------------------------------------------|\n");
            printf("    |1.List all books.                                                                               |\n");
            printf("    |2.List all registered users.                                                                    |\n");
            printf("    |3.Add books.                                                                                    |\n");
            printf("    |4.Remove book.                                                                                  |\n");
            printf("    |5.Exit.                                                                                         |\n");
            printf("    |------------------------------------------------------------------------------------------------|\n");

            int staChoice;
            scanf("%d",&staChoice);
            Reader * pMove = reader->next;

            switch(staChoice)
            {
                case 1:
                    do
                    {
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |Please select the category or all categories you want to view:                                  |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |1. Philosophy                                                                                   |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |---| 1.1 Philosophy                                                                             |\n");
                                printf("    |---| 1.2 logic                                                                                  |\n");
                                printf("    |---| 1.3 religion                                                                               |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |2. Economics                                                                                    |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |---| 2.1 financial                                                                              |\n");
                                printf("    |---| 2.2 International Trade                                                                    |\n");
                                printf("    |---| 2.3 cameralistics                                                                          |\n");
                                printf("    |---| 2.4 economics                                                                              |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |3. Law                                                                                          |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |---| 3.1 Political science                                                                      |\n");
                                printf("    |---| 3.2 Political                                                                              |\n");
                                printf("    |---| 3.3 Marxism                                                                                |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |4. Pedagogy                                                                                     |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |---| 4.1 Education                                                                              |\n");
                                printf("    |---| 4.2 Higher science education                                                               |\n");
                                printf("    |---| 4.3 Low level education                                                                    |\n");
                                printf("    |---| 4.4 Sports education                                                                       |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |5. Literature                                                                                   |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |---| 5.1 Chinese language and literature                                                        |\n");
                                printf("    |---| 5.2 Sinology                                                                               |\n");
                                printf("    |---| 5.3 Foreign language and literature                                                        |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |6. History                                                                                      |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |---| 5.1 Chinese language and literature                                                        |\n");
                                printf("    |---| 5.2 Higher science education                                                               |\n");
                                printf("    |---| 5.3 Low level education                                                                    |\n");
                                printf("    |---| 5.4 Sports education                                                                       |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |7. History                                                                                      |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |---| 5.1 Chinese language and literature                                                        |\n");
                                printf("    |---| 5.2 Higher science education                                                               |\n");
                                printf("    |---| 5.3 Low level education                                                                    |\n");
                                printf("    |---| 5.4 Sports education                                                                       |\n");



                        int listchoice;

                        scanf("%d",&listchoice);

                        if(listchoice > 13 || listchoice < 1)
                        {
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |Error : Please enter the correct number:                                                        |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                fflush(stdin);
                        }
                        else
                        {
                            printf("    |------------------------------------------------------------------------------------------------|\n");
                            printf("    |                                    %s \n",BigCategories[listchoice - 1]);
                            printf("    |------------------------------------------------------------------------------------------------|\n");

                            if(listchoice >= 1 && listchoice <= 4)
                            {
                                  Listallbook(head->child[0]->child[listchoice - 1]);
                            }
                            else if(listchoice > 4 && listchoice <= 8)
                            {
                                  Listallbook(head->child[1]->child[listchoice -5]);
                            }
                            else if(listchoice > 8 && listchoice <= 12)
                            {
                                  Listallbook(head->child[2]->child[listchoice - 9]);
                            }
                            else if(listchoice > 12 && listchoice <= 16)
                            {
                                  Listallbook(head->child[3]->child[listchoice - 13]);
                            }

                               listdoor = 1;
                        }
                    }while(listdoor == 0);
                    break;

                case 2:
                     printf("    |--------------------------------------------------------------------------------------------|\n");
                     printf("    |Studentnum------Studentname----------Collegename------Index---------Booksrentname-----------|\n");
                     printf("    |--------------------------------------------------------------------------------------------|\n");
                     printList(pMove);
                    break;

                case 3:
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    printf("    |Due to system problems, we are very sorry to tell you that you can only add %d books.\n",MaxAdd);
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    printf("    |Please enter the book you want to add:                                                      |\n");
                    printf("    |--------------------------------------------------------------------------------------------|\n");

                    ExiorNot6 = -1;

                    char Abook[50];
                    scanf("%s",Abook);

                    printf("    |Please make sure you want to add <<%s>> book\n",Abook);
                    printf("    |Please enter number 1 for yes ,number 2 for no,and any wrong number will return to the menu. \n");

                    int choice3;
                    scanf("%d",&choice3);

                    if(choice3 == 1)
                    {
                        Addbooks(head,Abook);
                        printf("door = %d",door);
                    }
                    break;

                case 4:
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    printf("    |Please enter the book you want to remove:                                                   |\n");
                    printf("    |--------------------------------------------------------------------------------------------|\n");

                    char Rbook[50];
                    scanf("%s",Rbook);

                    printf("    |Please make sure you want to remove ¡¶%s¡· book\n",Rbook);
                    printf("    |Please enter number 1 for yes ,number 2 for no,and any wrong number will return to the menu. \n");

                    int choice4;
                    scanf("%d",&choice4);

                    if(choice4 == 1)
                    {
                        RemoveBooks(head,Rbook);
                    }
                    break;

                case 5:
                    comeIn = 1;
                    break;
            }
        }

        if(choice == 3)
        {
            door = 1;
            break;
        }

        if(choice != 1 && choice != 2 && choice != 3)
        {
            printf("    |Error : Please enter the correct number, 1 for students and 2 for employees.                |\n");
            fflush(stdin);
        }

       fflush(stdin);

  }while(door != 1);

  WriteLibrary(head);
  WriteStudent(reader);

}
