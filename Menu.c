#include "stdio.h"
#include "stdlib.h"
#include "Menu.h"
#include "Tree.h"
#include "List.h"

void Begin(Node *head,Reader *reader)
{
    int choice;
    int door = 0;
    do
    {
         printf("    |--------------------------------------------------------------------------------------------|\n");
         printf("    |                        Library management system                                           |\n");
         printf("    |--------------------------------------------------------------------------------------------|\n");
         printf("    | Please choose whether you are an employee or a student.(1 or 2)                            |\n");
         printf("    |--------------------------------------------------------------------------------------------|\n");
         printf("    | 1.I am a student.                                                                          |\n");
         printf("    | 2.I am a staff.                                                                            |\n");
         printf("    |--------------------------------------------------------------------------------------------|\n");

         scanf("%d",&choice);

        while(choice == 1 && door == 0)
        {
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |                          For student                                                       |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |Please choose what you want:(select number)                                                |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |1.Register with the library.                                                                |\n");
            printf("    |2.List all books.                                                                           |\n");
            printf("    |3.Search for books.                                                                         |\n");
            printf("    |4.Borrow a book.                                                                            |\n");
            printf("    |5.Return a book.                                                                            |\n");
            printf("    |6.Exit.                                                                                     |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");

            int stuChoice;
            scanf("%d",&stuChoice);

            switch(stuChoice)
            {
                case 1:
                       StudentRegister(reader);
                    break;

                case 2:
                       printf("    |----------------------------------------------------------------------------|\n");
                       printf("    |Book catalogues and borrowing information                                   |\n");
                       printf("    |----------------------------------------------------------------------------|\n");
                       Listallbook(head);
                    break;

                case 3:
                    printf("    |----------------------------------------------------------------------------|\n");
                    printf("    |Please enter the book you want to find:                                     |\n");
                    printf("    |----------------------------------------------------------------------------|\n");

                    ExiorNot3 = -1;


                    do
                    {
                           char book[50];
                           scanf("%s",book);
                           Searchforbooks(head,book);

                           if(ExiorNot3 == -1)
                           {
                              printf("    |Please enter the correct title and it's unable to find the correct book.    |\n");
                              fflush(stdin);
                           }
                           else
                           {
                               break;
                           }

                    }while(ExiorNot3 == -1);
                    break;

                case 4:
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    printf("    |Please enter the book you want to Borrow:                                                   |\n");
                    printf("    |--------------------------------------------------------------------------------------------|\n");

                    ExiorNot4 = -1;


                    do
                    {
                           char Bbook[50];
                           scanf("%s",Bbook);

                           Borrowingbooks(head,Bbook);

                           if(ExiorNot4 == -1)
                           {
                              printf("    |Please enter the correct title again and it's unable to find the correct book:    |");
                              fflush(stdin);
                           }
                    }while(ExiorNot4 == -1);
                    break;

                case 5:
                    printf("    |--------------------------------------------------------------------------------------------|\n");
                    printf("    |Please enter the book you want to return:                                                   |\n");
                    printf("    |--------------------------------------------------------------------------------------------|\n");

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
                    door = 1;
                    break;

            }
        }

        while(choice == 2 && door == 0)
        {
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |                            For staff                                                       |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |Please choose what you want£º(select number)                                                |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |1.List all books.                                                                           |\n");
            printf("    |2.List all registered users.                                                                |\n");
            printf("    |3.Add books.                                                                                |\n");
            printf("    |4.Remove book.                                                                              |\n");
            printf("    |5.Exit.                                                                                     |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");


            int staChoice;
            scanf("%d",&staChoice);
            Reader * pMove = reader->next;

            switch(staChoice)
            {
            case 1:
                printf("    |----------------------------------------------------------------------------|\n");
                Listallbook(head);

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

                printf("    |Please make sure you want to add 《%s》book\n",Abook);
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
                door = 1;
                break;
            }
        }

        if(choice != 1 &&choice != 2)
        {
            printf("    |Error : Please enter the correct number, 1 for students and 2 for employees.                |\n");
            fflush(stdin);
        }
  }while(door != 1);
  WriteLibrary(head);
  WriteStudent(reader);

}
