#include "stdio.h"
#include "stdlib.h"
#include "Menu.h"
#include "Tree.h"
#include "List.h"
#include "math.h"
//int MaxAdd;
int JudgeNumber;

void Begin(Node *head,Reader *reader)
{
    int choice;
    int door = 0;

    JudgeNumber = 0;

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
                       SelectListallbooks(head);
                    break;

                case 3:
                    do{
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |Please enter the number you want:                                                               |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |1. I only know the title but I don't know the specific category                                 |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |2. I know exactly which category it falls into                                                  |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");


                        ExiorNot3 = -1;

                        int choice;

                        scanf("%d",&choice);
                        if(choice == 1)
                        {
                                   printf("    |------------------------------------------------------------------------------------------------|\n");
                                   printf("    |Please enter the name of the book you want to query:                                            |\n");
                                   printf("    |------------------------------------------------------------------------------------------------|\n");
                                   char book[50];
                                   getchar();
                                   gets(book);
                                   Searchforbooks(head,book);

                                   if(ExiorNot3 == -1)
                                   {
                                      printf("    |------------------------------------------------------------------------------------------------|\n");
                                      printf("    |Error:Unable to find the correct book!!!!!!                                                     |\n");
                                      printf("    |------------------------------------------------------------------------------------------------|\n");
                                      system("pause");
                                   }
                            break;
                        }
                        else if(choice == 2)
                        {
                            int temptry;

                            temptry = menu(2,head);

                            int tempZero = temptry % 10;

                            printf("tempZero = %d\n",tempZero);

                            if(tempZero > 0 && tempZero <= 4)
                            {
                                temptry /= 10;

                                   printf("    |------------------------------------------------------------------------------------------------|\n");
                                   printf("    |Please enter the name of the book you want to query:                                            |\n");
                                   printf("    |------------------------------------------------------------------------------------------------|\n");

                                   char book[50];
                                   getchar();
                                   gets(book);
                                   Searchforbooks(head->child[(temptry - 1 ) / 4]->child[(temptry - 1 ) % 4]->child[tempZero-1],book);

                                   if(ExiorNot3 == -1)
                                   {
                                      printf("    |------------------------------------------------------------------------------------------------|\n");
                                      printf("    |Error:Unable to find the correct book!!!!!!                                                     |\n");
                                      printf("    |------------------------------------------------------------------------------------------------|\n");
                                      system("pause");
                                   }
                            }
                            break;

                        }
                        else
                        {
                            printf("    |------------------------------------------------------------------------------------------------|\n");
                            printf("    |Error : Please enter the correct number:                                                        |\n");
                            printf("    |------------------------------------------------------------------------------------------------|\n");
                            fflush(stdin);
                            system("pause");
                        }

                    }while(1);
                    break;

                case 4:

                    ExiorNot4 = -1;

                    do
                    {
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |Please enter the number you want:                                                               |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |1. I know the specific category of books and names I want to borrow                             |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |2. I only know the name of books I want to borrow                                               |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |3. I know nothing !! Then we will jump to the main page for you.                                |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");

                        int choice;
                        scanf("%d",&choice);

                        if(choice == 2)
                        {
                            printf("    |------------------------------------------------------------------------------------------------|\n");
                            printf("    |Please enter the name of the book you want to borrow:                                           |\n");
                            printf("    |------------------------------------------------------------------------------------------------|\n");

                           char Bbook[50];
                           getchar();
                           gets(Bbook);

                           Borrowingbooks(head,Bbook);

                           if(ExiorNot4 == -1)
                           {
                              printf("    |------------------------------------------------------------------------------------------------|\n");
                              printf("    |Unable to find the correct book!!!!!1                                                           |\n");
                              printf("    |------------------------------------------------------------------------------------------------|\n");
                              fflush(stdin);
                           }

                           break;
                        }
                        else if(choice == 1)
                        {
                            int temptry;

                            temptry = menu(2,head);

                            int tempZero = temptry % 10;

                            printf("tempZero = %d\n",tempZero);

                            if(tempZero > 0 && tempZero <= 4)
                            {
                                temptry /= 10;

                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |Please enter the name of the book you want to borrow:                                           |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");

                               char Bbook[50];
                               getchar();
                               gets(Bbook);

                               Borrowingbooks(head->child[(temptry - 1 ) / 4]->child[(temptry - 1 ) % 4]->child[tempZero-1],Bbook);

                               if(ExiorNot4 == -1)
                               {
                                  printf("    |------------------------------------------------------------------------------------------------|\n");
                                  printf("    |Unable to find the correct book!!!!!                                                            |\n");
                                  printf("    |------------------------------------------------------------------------------------------------|\n");
                                  system("pause");
                               }
                            }

                            break;
                        }
                        else if(choice == 3)
                        {
                            break;
                        }
                            printf("    |------------------------------------------------------------------------------------------------|\n");
                            printf("    |Error : Please enter the correct number:                                                        |\n");
                            printf("    |------------------------------------------------------------------------------------------------|\n");

                            fflush(stdin);
                            system("pause");

                    }while(1);
                    break;

                case 5:
                       ExiorNot5 = -1;

                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |Please enter the number you want:                                                               |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |1. I know the specific category of books to return                                              |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |2. I only know the name of books I want to borrow                                               |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");

                       int choice;
                       scanf("%d",&choice);

                    do{
                           if(choice == 1)
                           {
                                int temptry;

                                temptry = menu(2,head);


                                int tempZero = temptry % 10;

                                if(tempZero > 0 && tempZero <= 4)
                                {
                                    temptry /= 10;

                                    printf("    |------------------------------------------------------------------------------------------------|\n");
                                    printf("    |Please input the 'Name' of the right book to return:                                            |\n");
                                    printf("    |------------------------------------------------------------------------------------------------|\n");

                                   char Rbook[50];
                                   getchar();
                                   gets(Rbook);

                                    ReturnaBook(head->child[(temptry - 1 ) / 4]->child[(temptry - 1 ) % 4]->child[tempZero-1],Rbook);

                                   if(ExiorNot5 == -1)
                                   {
                                      printf("    |------------------------------------------------------------------------------------------------|\n");
                                      printf("    |Please enter the correct title again and it's unable to find the correct book!!                 |\n");
                                      printf("    |------------------------------------------------------------------------------------------------|\n");

                                      system("pause");
                                   }
                                   break;
                                }
                             }
                             else if(choice == 2)
                             {
                                    printf("    |------------------------------------------------------------------------------------------------|\n");
                                    printf("    |Please input the 'Name' of the right book to return:                                            |\n");
                                    printf("    |------------------------------------------------------------------------------------------------|\n");

                                   char Rbook[50];
                                   getchar();
                                   gets(Rbook);

                                    ReturnaBook(head,Rbook);

                                   if(ExiorNot5 == -1)
                                   {
                                      printf("    |------------------------------------------------------------------------------------------------|\n");
                                      printf("    |Please enter the correct title again and it's unable to find the correct book!!                 |\n");
                                      printf("    |------------------------------------------------------------------------------------------------|\n");
                                      system("pause");

                                   }
                                   break;
                             }

                            printf("    |------------------------------------------------------------------------------------------------|\n");
                            printf("    |Error : Please enter the correct number:                                                        |\n");
                            printf("    |------------------------------------------------------------------------------------------------|\n");

                            fflush(stdin);
                            system("pause");

                    }while(1);

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
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    printf("    |Book catalogues and borrowing information                                                       |\n");
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    SelectListallbooks(head);
                    break;

                case 2:
                     printf("    |------------------------------------------------------------------------------------------------|\n");
                     printf("    |Studentnum--------Studentname----------Collegename--------Index---------Booksrentname-----------|\n");
                     printf("    |------------------------------------------------------------------------------------------------|\n");
                     printList(pMove);
                    break;

                case 3:
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    printf("    |Please select the type of book you want to add,please enter the serial number before the book   |\n");
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    do{
                        int num = 2;

                        int temptry;

                        temptry = menu(num,head);

                        int tempZero = temptry % 10;

                        printf("tempZero = %d\n",tempZero);

                        if(tempZero > 0 && tempZero <= 4)
                        {
                            temptry /= 10;
                            JudgeNull(head->child[(temptry - 1 ) / 4]->child[(temptry - 1 ) % 4]->child[tempZero-1]);

                           if(JudgeNumber == 0)
                           {
                                ExiorNot6 = -1;

                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |Please enter the title you want to add:                                                         |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");

                                getchar();
                                char Abook[50];

                                gets(Abook);

                                printf("    |Please make sure you want to add <<%s>> book\n",Abook);

                                printf("    |Please enter number 1 for yes ,number 2 for no,and any wrong number will return to the menu. \n");

                                int choice3;

                                scanf("%d",&choice3);

                                if(choice3 == 1)
                                {
                                    Addbooks(head->child[(temptry - 1 ) / 4 ]->child[(temptry - 1 ) % 4]->child[tempZero-1],Abook);

                                    //printf("LevelNumber[temptry -1]_in = %d\n",LevelNumber[temptry -1]);

                                    LevelNumber[temptry -1] = LevelNumber[temptry -1] + 1;

                                    //printf("LevelNumber[temptry -1]_out = %d\n",LevelNumber[temptry -1]);
                                }

                           }
                           else
                            {
                                JudgeNumber = 0;
                            }
                            system("pause");
                            break;
                        }
                        else
                        {
                            printf("    |------------------------------------------------------------------------------------------------|\n");
                            printf("    |Error : Please enter the correct number:                                                        |\n");
                            printf("    |------------------------------------------------------------------------------------------------|\n");
                            fflush(stdin);
                            system("pause");
                        }
                    }while(1);

                    break;

                case 4:
                    do{
                            int num = 2;

                            int temptry;

                            temptry = menu(num,head);

                            int tempZero = temptry % 10;

                            printf("temptry = %d\n",temptry);
                            printf("tempZero = %d\n",tempZero);

                            if(tempZero > 0 && tempZero <= 4)
                            {
                                temptry /= 10;

                                int x = (temptry - 1 ) / 4;
                                int y = (temptry - 1 ) % 4;

                                printf("x = %d\n",x);
                                printf("y = %d\n",y);

                                Listallbook(head->child[x]->child[y]->child[tempZero-1]);

                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |Please enter the book 'Index' you want to remove:                                               |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");

                                int Index;
                                scanf("%d",&Index);

                                printf("    |Please enter number 1 for yes ,number 2 for no,and any wrong number will return to the menu. \n");

                                int choice4;

                                scanf("%d",&choice4);

                                if(choice4 == 1)
                                {
                                    int before = LevelNumber[temptry -1];

                                    RemoveBooks(head->child[x]->child[y]->child[tempZero-1],Index,temptry);

                                    int after = LevelNumber[temptry -1];

                                    if(before == after)
                                    {
                                          printf("    |------------------------------------------------------------------------------------------------|\n");
                                          printf("    |Error :Remove failed, please check 'Index' before remove!!!!!                                   |\n");
                                          printf("    |------------------------------------------------------------------------------------------------|\n");
                                          system("pause");
                                    }
                                }
                                break;
                             }
                             else
                             {
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |Error : Please enter the correct number:                                                        |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                fflush(stdin);
                                system("pause");
                              }

                    }while(1);
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
            printf("    |------------------------------------------------------------------------------------------------|\n");
            printf("    |Error : Please enter the correct number, 1 for students and 2 for employees.                    |\n");
            printf("    |------------------------------------------------------------------------------------------------|\n");
            fflush(stdin);
        }

       fflush(stdin);

  }while(door != 1);

  WriteLibrary(head);
  WriteStudent(reader);

}

void SelectListallbooks(Node *head)
{
     int listdoor = 0;
     do{
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |Please select the category or all categories you want to view:                                  |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |1. Browse directly to the sixteen categories (Enter number 1)                                   |\n");
                        printf("    |2. View a specific subcategory (Enter number 2)                                                 |\n");
                        printf("    |3. Exit(Enter number 2)                                                                         |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");


                        int listchoice;

                        scanf("%d",&listchoice);

                        if(listchoice == 3)
                        {
                             listdoor = 1;
                        }
                        else if(listchoice == 1 || listchoice == 2)
                        {
                                listchoice = menu(listchoice,head);

                                int temp = listchoice % 10;

                                if(temp == 0)
                                {
                                    listchoice /= 10;
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
                                else if(temp > 0 && temp <= 4)
                                {
                                       listchoice /= 10;

                                       printf("    |------------------------------------------------------------------------------------------------|\n");
                                       printf("    |We will show you the content of the book number:%d.%d                                           |\n",listchoice,temp);
                                       printf("    |------------------------------------------------------------------------------------------------|\n");
                                       printf("    |If you think the input is wrong, please exit and re-enter:                                      |\n");
                                       printf("    |------------------------------------------------------------------------------------------------|\n");
                                       system("pause");

                                    if(listchoice >= 1 && listchoice <= 4)
                                    {
                                          Listallbook(head->child[0]->child[listchoice - 1]->child[temp - 1]);
                                    }
                                    else if(listchoice > 4 && listchoice <= 8)
                                    {
                                          Listallbook(head->child[1]->child[listchoice -5]->child[temp - 1]);
                                    }
                                    else if(listchoice > 8 && listchoice <= 12)
                                    {
                                          Listallbook(head->child[2]->child[listchoice - 9]->child[temp - 1]);
                                    }
                                    else if(listchoice > 12 && listchoice <= 16)
                                    {
                                          Listallbook(head->child[3]->child[listchoice - 13]->child[temp - 1]);
                                    }
                                       listdoor = 1;
                                }
                                else{
                                        printf("    |------------------------------------------------------------------------------------------------|\n");
                                        printf("    |Error : Please enter the correct number:                                                        |\n");
                                        printf("    |------------------------------------------------------------------------------------------------|\n");
                                        fflush(stdin);
                                        system("pause");
                                }
                        }
                        else{
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |Error : Please enter the correct number:                                                        |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                fflush(stdin);
                                system("pause");

                        }
                    }while(listdoor == 0);
}

int menu(int choice,Node* head)
{
    int door = 1;
    if(choice == 1)
    {
        do{
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |Please select the category or all categories you want to view:                                  |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |1. Philosophy                                                                                   |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |2. Economics                                                                                    |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |3. Law                                                                                          |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |4. Pedagogy                                                                                     |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |5. Literature                                                                                   |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |6. History                                                                                      |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |7. Science                                                                                      |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |8. Engineering                                                                                  |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |9. Agricultural science                                                                         |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |10. Medical profession                                                                          |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |11. Management                                                                                  |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |12. Art                                                                                         |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |13. Extracurricular books                                                                       |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |14. Foreign                                                                                     |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |15. Chinese masterpiece                                                                         |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |16. Life books                                                                                  |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");

                        double listchoice;

                        scanf("%lf",&listchoice);

                        if(listchoice >= 1 && listchoice <= 16)
                        {
                            int temp = (int)listchoice % 100;

                            //printf("temp = %d\n",temp);

                            printf("    |------------------------------------------------------------------------------------------------|\n");
                            printf("    |We will show you the content of the book number:%d                                              |\n",temp);
                            printf("    |If you think the input is wrong, please exit and re-enter:                                      |\n");
                            printf("    |------------------------------------------------------------------------------------------------|\n");

                            system("pause");

                            return temp * 10;
                        }
                        else
                        {
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |Error : Please enter the correct number:                                                        |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                fflush(stdin);
                                system("pause");
                        }
        }while(door == 1);
    }
    else if(choice == 2)
    {
                                int i,j;
                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |Please select the category or all categories you want:                                          |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");

                                system("pause");
                                int temp = 0;

                                for(i = 0;i < 4;i++)
                                {
                                    for(j = 0;j <4;j++)
                                    {
                                        printf("    |------------------------------------------------------------------------------------------------|\n");
                                        printf("    |%d. %s \n",temp + 1,BigCategories[temp]);
                                        printf("    |------------------------------------------------------------------------------------------------|\n");

                                        giveName(head->child[i]->child[j]);
                                        temp++;
                                    }
                                }
                      do{

                                printf("    |------------------------------------------------------------------------------------------------|\n");
                                printf("    |Please select the type of book you want:                                                        |\n");
                                printf("    |------------------------------------------------------------------------------------------------|\n");


                                double listchoice;

                                scanf("%lf",&listchoice);

                                if(listchoice >= 1.0 && listchoice <= 16.4)
                                {
                                     double middle_temp = listchoice * 10;

                                     int temp = (int)middle_temp;

                                    return temp;
                                }
                                else
                                {
                                        printf("    |------------------------------------------------------------------------------------------------|\n");
                                        printf("    |Error : Please enter the correct number:                                                        |\n");
                                        printf("    |------------------------------------------------------------------------------------------------|\n");
                                        fflush(stdin);
                                        system("pause");
                                }

               }while(door == 1);

    }
}

void JudgeNull(Node *node)
{
  int i;
  if(node->child[0] == NULL){
     if(strcmp(node->booksname,"null") == 0)
     {
         int door = 1;
         JudgeNumber = 1;

           do{
               printf("    |------------------------------------------------------------------------------------------------|\n");
               printf("    |Error : This class is not established :                                                         |\n");
               printf("    |------------------------------------------------------------------------------------------------|\n");
               printf("    |1. Make sure you have entered the category you want to add correctly                            |\n");
               printf("    |------------------------------------------------------------------------------------------------|\n");
               printf("    |2. If you still want to continue, enter the class name first, and then add the book             |\n");
               printf("    |------------------------------------------------------------------------------------------------|\n");
               printf("    |Please select:                                                                                  |\n");
               printf("    |------------------------------------------------------------------------------------------------|\n");
               printf("    |1. Quit                                                                                         |\n");
               printf("    |------------------------------------------------------------------------------------------------|\n");
               printf("    |2. Create a new class                                                                           |\n");
               printf("    |------------------------------------------------------------------------------------------------|\n");

               int tem;
               scanf("%d",&tem);
               getchar();

               if(tem == 2)
               {
                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    printf("    |Please enter the name of the new class:                                                         |\n");
                    printf("    |------------------------------------------------------------------------------------------------|\n");

                    char str1[30];
                    gets(str1);

                    printf("    |------------------------------------------------------------------------------------------------|\n");
                    printf("    |Please make sure that you want to add this new class: %s (1/yes and 0/no and other/exit)        \n",str1);
                    printf("    |------------------------------------------------------------------------------------------------|\n");

                    int temp;
                    scanf("%d",&temp);

                    if(temp == 1)
                    {
                        strcpy(node->booksname,str1);

                    }
                      door = 0;
               }
               else if(tem == 1)
               {
                    door = 0;
               }
               else
               {
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        printf("    |Error : Please enter the correct number:                                                        |\n");
                        printf("    |------------------------------------------------------------------------------------------------|\n");
                        fflush(stdin);
                        system("pause");
               }
           }while(door == 1);
     }
     return;
  }
  else{
        JudgeNull(node->child[0]);
  }
}

void giveName(Node* node)
{
   int i;
   if(node->child[0] == NULL)
   {
     if(strcmp(node->authorname,"SmallCategories") == 0)
     {
         int x = (node->booksindex) % 10;
         int y = (node->booksindex) / 10;
         printf("    |---|%d.%d %s\n",y,x,node->booksname);
     }
     return;
  }
  else{
        for(i = 0;i < 4;i++)
        {
            giveName(node->child[i]);
        }
  }
}













