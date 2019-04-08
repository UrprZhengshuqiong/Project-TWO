#include "stdio.h"
#include "stdlib.h"
#include "LibraryBook.h"
#include "Tree.h"
#include "Menu.h"

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

           if(node->child[i]->borrow == 1 ||node->child[i]->borrow == 0)
           {
               printf("    |");
               printf("%4d        %-40s ",node->child[i]->booksindex,node->child[i]->booksname);

               if(node->child[i]->borrow == 1)
               {
                      printf("retain.                |\n");
               }
               else
               {
                      printf("Already loaned out.    |\n");
               }
               printf("    |----------------------------------------------------------------------------|\n");
           }
        }
    }
}

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
                 printf("    |The book ¡¶%s¡· you have reviewed : retain                                                 |\n",node->child[i]->booksname);
            }
            else if(node->child[i]->borrow == 0 && (strcmp(node->child[i]->booksname,book) == 0))
            {
                 ExiorNot3 = 1;
                 printf("    |The book 《%s》 you have reviewed : Already loaned out.                                    |\n",node->child[i]->booksname);
            }
        }
    }

}

void Borrowingbooks(Node *node,char * Bbook)
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
              Borrowingbooks(node->child[i],Bbook);

             if(node->child[i]->borrow == 1 && (strcmp(node->child[i]->booksname,Bbook) == 0))
             {
                ExiorNot4 = 1;

                printf("    |The book 《%s》 you have reviewed : retain                                                  |\n",node->child[i]->booksname);
                printf("    |Please determine if you want to borrow ¡¶%s¡·,Please enter( 1(yes)/ 0(no) )                 |\n",node->child[i]->booksname);

                int answer;
                scanf("%d",&answer);

                do
                {
                  if(answer == 1)
                  {
                      node->child[i]->borrow = 0;
                      printf("    |successfully: 《%s》                                                                        \n",node->child[i]->booksname);
                      printf("    |You have successfully borrowed this book, please go to the window to take out the book.     \n");

                      break;

                  }
                  else if(answer == 0)
                  {
                      printf("    |The system is about to exit this option interface.........                                   \n");
                      break;
                  }
                  else
                  {
                      printf("    |Error : Please enter the correct character, number 1 for yes and number 0 for no.                         \n");
                      temp = 1;
                      fflush(stdin);
                      scanf("%d",&answer);
                  }
                }while(temp == 1);
             }

             else if(node->child[i]->borrow == 0 && (strcmp(node->child[i]->booksname,Bbook) == 0))
             {
                  ExiorNot4 = 1;
                  printf("    |Sorry: The book 《%s》 you have reviewed : Already loaned out.                                   |\n",node->child[i]->booksname);
             }

        }
    }

}

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
                printf("    |The book 《%s》 you want to return, status : Already loaned out.                           |\n",node->child[i]->booksname);
                printf("    |Please put the book in the return window:                                                  |\n");
                printf("    |Please make sure that you have already placed the book in the recycling window.(1/yes and 0/no.)\n");

                do
                {
                  int reanswer;
                  scanf("%d",&reanswer);
                  if(reanswer == 1)
                  {
                      node->child[i]->borrow = 1;
                      printf("    |successfully: 《%s》                                                                        \n",node->child[i]->booksname);
                      printf("    |You have successfully return this book.                                                     \n");

                      break;

                  }
                  else if(reanswer == 0)
                  {
                      printf("    |The system is about to exit this option interface.........                                   \n");
                      break;
                  }
                  else
                  {
                      printf("    |Error : Please enter the correct character, number 1 for yes and number 0 for no.                         \n");
                      temp = 1;
                      fflush(stdin);
                  }
                }while(temp == 1);
            }
            else if(node->child[i]->borrow == 1 && (strcmp(node->child[i]->booksname,Rbook) == 0))
            {
                 printf("    |Error : This book 《%s》has not been lent, please enter the correct title:                                \n",node->child[i]->booksname);
            }
        }
    }
}

void  Addbooks(Node * node,char * Abook)
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
            Addbooks(node->child[i],Abook);

            if(node->child[i]->borrow == -1 && ExiorNot6 == -1)
            {
                ExiorNot6 = 1;
                MaxAdd -= 1;
                numbers++;

                node->child[i]->booksindex = numbers;

                strcpy(node->child[i]->booksname,Abook);
                node->child[i]->borrow = 1;
            }
            else if(strcmp(node->child[i]->booksname,Abook) == 0 && ExiorNot6 == -1)
            {
                printf("    |Error : The name of the book 《%s》 coincides with the name of another book.",Abook);
                printf("We will use different numbers to distinguish it.\n");
                printf("    |Of course, I also hope that you will consider whether to change part of the name to maintain the discrimination of the book.\n");
                printf("    |Choose :Select number 1 - I still want to use the same name:\n");
                printf("    |Choose :Select number 2 - return to the main interface and re-enter the function area to modify the name:\n");
                printf("    |(Cautions :Any wrong numbers will be returned to the main interface too.)\n");

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


void  RemoveBooks(Node * node,char * Mbook)
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
            RemoveBooks(node->child[i],Mbook);

            if(node->child[i]->borrow == 1 && strcmp(node->child[i]->booksname,Mbook) == 0)
            {
                node->child[i]->borrow = -2;
                printf("    |--------------------------------------------------------------------------------------------|\n");
                printf("    |Success : This book is now been removed !!                                                  |\n");
                printf("    |--------------------------------------------------------------------------------------------|\n");
                RemoveBooksNum++;

            }
            else if(strcmp(node->child[i]->booksname,Mbook) == 0 && node->child[i]->borrow == 0)
            {
                printf("    |--------------------------------------------------------------------------------------------|\n");
                printf("    |Error : This book is now in a lending state and cannot be removed                           |\n");
                printf("    |--------------------------------------------------------------------------------------------|\n");
            }
        }
    }
}
