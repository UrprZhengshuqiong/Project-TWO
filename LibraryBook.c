#include "stdio.h"
#include "stdlib.h"
#include "LibraryBook.h"
#include "Tree.h"
#include "Menu.h"
#include "string.h"

int Addbookstemp;

extern int ExiorNot3;

extern int ExiorNot4;

extern int ExiorNot5;

extern int ExiorNot6;

extern int LevelNumber[50];

extern int MaxAdd;

/**list all the books of the child nodes contained in the incoming node**/
void Listallbook(Node *node)
{
    int i;
    if(node->child[0] == NULL)
    {
       return;
    }
    else
    {
        for (i=0; i<4; ++i )
        {
           Listallbook(node->child[i]);

           if(strcmp(node->child[i]->authorname,"SmallCategories") == 0 && strcmp(node->child[i]->booksname,"null") != 0)
           {
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |%s: %s\n",node->child[i]->authorname,node->child[i]->booksname);
                printf("    |------------------------------------------------------------------------------------------------|\n");
           }
           else if(strcmp(node->child[i]->booksname,"null") != 0 && (node->child[i]->borrow == 1 || node->child[i]->borrow == 0))
           {
               printf("    |");
               printf("%4d        %-40s ",node->child[i]->booksindex,node->child[i]->booksname);
               printf("%-20s",node->child[i]->authorname);

               if(node->child[i]->borrow == 1)
               {
                      printf("retain.                |\n");
               }
               else
               {
                      printf("Already loaned out!    |\n");
               }
               printf("    |------------------------------------------------------------------------------------------------|\n");
           }
        }
    }
}

/**Search for books**/
void Searchforbooks(Node *node,char * book)
{
    int i;
    if( node->child[0] == NULL )
    {
        return;
    }
    else
    {
        for(i=0; i<4; i++)
        {
            Searchforbooks(node->child[i],book);

            if(node->child[i]->borrow == 1 && (strcmp(node->child[i]->booksname,book) == 0))
            {
                 ExiorNot3 = 1;
                 printf("    |------------------------------------------------------------------------------------------------|\n");
                 printf("    |The book <<%s>> you have reviewed : retain                                                 |\n",node->child[i]->booksname);
                 printf("    |------------------------------------------------------------------------------------------------|\n");
            }
            else if(node->child[i]->borrow == 0 && (strcmp(node->child[i]->booksname,book) == 0))
            {
                 ExiorNot3 = 1;
                 printf("    |------------------------------------------------------------------------------------------------|\n");
                 printf("    |The book <<%s>> you have reviewed : Already loaned out.                                    |\n",node->child[i]->booksname);
                 printf("    |------------------------------------------------------------------------------------------------|\n");
            }
        }
    }

}

/**Borrowing books**/
void Borrowingbooks(Node *node,char * Bbook,int BookRentNum)
{
    int i;
    int temp = -1;
    if( node->child[0] == NULL )
    {
       return;
    }
    else
    {
        for(i=0; i<4; i++)
        {
              Borrowingbooks(node->child[i],Bbook,BookRentNum);

             if(node->child[i]->borrow == 1 && (strcmp(node->child[i]->booksname,Bbook) == 0))
             {
                ExiorNot4 = 1;

                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |The book <<%s>> you have reviewed : retain                                                 \n",node->child[i]->booksname);
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |Please determine if you want to borrow <<%s>> ,Please enter( 1(yes)/ 0(no) )                 \n",node->child[i]->booksname);
                printf("    |------------------------------------------------------------------------------------------------|\n");

                int answer;

                scanf("%d",&answer);

                do
                {
                  if(BookRentNum < 3 && BookRentNum >= 0)
                  {
                       if(answer == 1 )
                       {
                          node->child[i]->borrow = 0;

                          ExiorNot4 = 2;

                          break;
                        }
                          else if(answer == 0)
                          {
                              printf("    |------------------------------------------------------------------------------------------------|\n");
                              printf("    |The system is about to exit this option interface.........                                   \n");
                              printf("    |------------------------------------------------------------------------------------------------|\n");
                              system("pause");

                              break;
                          }
                          else
                          {
                              printf("    |------------------------------------------------------------------------------------------------|\n");
                              printf("    |Error : Please enter the correct character, number 1 for yes and number 0 for no.                         \n");
                              printf("    |------------------------------------------------------------------------------------------------|\n");

                              temp = 1;

                              fflush(stdin);

                              scanf("%d",&answer);
                          }
                   }

                   else
                   {
                      printf("    |------------------------------------------------------------------------------------------------|\n");
                      printf("    |Error : The number of books you can borrow has reached the limit.                               |\n");
                      printf("    |------------------------------------------------------------------------------------------------|\n");
                      break;
                   }

                }while(temp == 1);
             }

             else if(node->child[i]->borrow == 0 && (strcmp(node->child[i]->booksname,Bbook) == 0))
             {
                  ExiorNot4 = 1;
                  printf("    |------------------------------------------------------------------------------------------------|\n");
                  printf("    |Sorry: The book <<%s>> you have reviewed : Already loaned out.                                   \n",node->child[i]->booksname);
                  printf("    |------------------------------------------------------------------------------------------------|\n");
                  system("pause");
             }

        }
    }

}
/**Return a Book**/
void ReturnaBook(Node *node,char * Rbook)
{
    int i;
    int temp = -1;
    if( node->child[0] == NULL )
    {
       return;
    }
    else
    {
        for(i=0; i<4; i++)
        {
            ReturnaBook(node->child[i],Rbook);

            if(node->child[i]->borrow == 0 && strcmp(node->child[i]->booksname,Rbook) == 0)
            {
                ExiorNot5 = 1;

                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |The book <<%s>> you want to return, status : Already loaned out.        \n",node->child[i]->booksname);
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |Please put the book in the return window:                                                       |\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |Please make sure that you have already placed the book in the recycling window.(1/yes and 0/no.)|\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");

                do
                {
                  int reanswer;
                  scanf("%d",&reanswer);

                  if(reanswer == 1)
                  {
                      node->child[i]->borrow = 1;
                      printf("    |------------------------------------------------------------------------------------------------|\n");
                      printf("    |successfully: <<%s>> \n",node->child[i]->booksname);
                      printf("    |------------------------------------------------------------------------------------------------|\n");
                      printf("    |You have successfully return this book.                                                         |\n");
                      printf("    |------------------------------------------------------------------------------------------------|\n");

                      ExiorNot5 = 2;

                      break;

                  }
                  else if(reanswer == 0)
                  {
                      printf("    |------------------------------------------------------------------------------------------------|\n");
                      printf("    |The system is about to exit this option interface.........                                      |\n");
                      printf("    |------------------------------------------------------------------------------------------------|\n");
                      system("pause");
                      break;
                  }
                  else
                  {
                      printf("    |------------------------------------------------------------------------------------------------|\n");
                      printf("    |Error : Please enter the correct character, number 1 for yes and number 0 for no.               |\n");
                      printf("    |------------------------------------------------------------------------------------------------|\n");

                      temp = 1;
                      fflush(stdin);
                  }
                }while(temp == 1);
            }
            else if(node->child[i]->borrow == 1 && (strcmp(node->child[i]->booksname,Rbook) == 0))
            {
                 printf("    |------------------------------------------------------------------------------------------------|\n");
                 printf("    |Error : This book <<%s>> has not been lent, please enter the correct title!!!\n",node->child[i]->booksname);
                 printf("    |------------------------------------------------------------------------------------------------|\n");
            }
        }
    }
}

/**Add new book information to the library**/
void  Addbooks(Node * node,char * Abook,char * authorName,int temptry)
{
    int i;
    if( node->child[0] == NULL )
    {
        if(strcmp(node->authorname,"SmallCategories") == 0)
        {
            int index = node->booksindex;

            index /= 10;

            judge(LevelNumber[index - 1]);

            if(node->borrow == MaxAdd)
            {
                 printf("    |------------------------------------------------------------------------------------------------|\n");
                 printf("    |Soory : This system only supports adding %d books in small classes",MaxAdd);
                 printf("    |------------------------------------------------------------------------------------------------|\n");
                 printf("    |Please restart the system to add again.                                                         |\n");
                 printf("    |------------------------------------------------------------------------------------------------|\n");
            }
            else
            {
                Addbookstemp = node->borrow;

            }
        }
       return;
    }
    else
    {
        for(i=0; i<4; i++)
        {
            Addbooks(node->child[i],Abook,authorName,temptry);

            if(node->child[i]->borrow == -1 && ExiorNot6 == -1)
            {
                ExiorNot6 = 1;

                node->child[i]->booksindex = Addbookstemp + 1;

                strcpy(node->child[i]->booksname,Abook);

                strcpy(node->child[i]->authorname,authorName);

                node->child[i]->borrow = 1;

                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |Successful.you have successfully added <<%s>> book\n",node->child[i]->booksname);
                printf("    |------------------------------------------------------------------------------------------------|\n");

                LevelNumber[temptry -1] = LevelNumber[temptry -1] + 1;

            }
            else if(strcmp(node->child[i]->booksname,Abook) == 0 && ExiorNot6 == -1)
            {
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |Error : The name of the book <<%s>> coincides with the name of another book.\n",Abook);
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |1. Use different 'Book Index' to distinguish it.                                                |\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |2. Change part of the name to maintain the discrimination of the book.                          |\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |Choose :Select number 1 - I still want to use the same name:\n");
                printf("    |Choose :Select number 2 - return to the main interface and re-enter the function area to modify the name:\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |(Cautions :Any wrong numbers will be returned to the main interface too.)                       |\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");

                int choice;
                scanf("%d",&choice);

                if(choice != 1)
                {
                    ExiorNot6 = 1;

                }
                else
                {
                    printf("    |We will add this book for you, this book will have a different number than the previous book with the same name.\n");
                }

            }
        }
    }
}

/**Remove Books**/
void RemoveBooks(Node * node,int Index,int temptry)
{
    int i;
    if( node->child[0] == NULL )
    {
       return;
    }
    else
    {
        for(i=0; i<4; i++)
        {
            RemoveBooks(node->child[i],Index,temptry);

            if(node->child[i]->borrow == 1 && node->child[i]->booksindex == Index)
            {
                node->child[i]->borrow = -2;
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |Success : This book is now been removed !!                                                      |\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");

                LevelNumber[temptry -1] = LevelNumber[temptry -1] - 1;
            }

            else if(node->child[i]->booksindex == Index && node->child[i]->borrow == 0)
            {
                printf("    |------------------------------------------------------------------------------------------------|\n");
                printf("    |Error : This book is now in a lending state and cannot be removed                               |\n");
                printf("    |------------------------------------------------------------------------------------------------|\n");
            }
        }
    }
}
