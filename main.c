#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// tree data structure

struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];


  int booksindex;//图书编号
  char booksname[20]; //图书名字
  int borrow;        //图书是否被借出
};

typedef struct qnode Node;

struct Readers{
    char Studentnum[20];
    char Studentname[20];
    char booksrentindex[20];
    char booksrentname[20];
    struct Readers * next;

}Readers;

typedef struct Readers Reader;

// function definitions

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void writeTree( Node *head );
void writeNode( FILE *fp, Node *node );
void printOut( FILE *fp, Node *node );
void readLibrary(Node *node );
void readStudent();
int numcount();
void growtree(Node *node);
int judge(int numbers);
void cyclewrite(FILE *fp,Node *node);
void StudentRegister();
void Listallbook(Node *node);
void begin(Node *head);
void Searchforbooks(Node *node,char * book);
void Borrowingbooks(Node *node,char * Bbook);

int ExiorNot3;
int ExiorNot4;
int ExiorNot5;
int ExiorNot6;
int MaxAdd = -1;
int numbers;

void ReturnaBook(Node *node,char * Rbook);
void  Addbooks(Node * node,char * Abook);
// main

int main( int argc, char **argv ) {

  //count numbers to  build tree
  numbers = numcount();

  printf("numbers = %d\n",numbers);

  int level = judge(numbers);

  printf("level = %d\n",level);


  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );

  int i = 0;
  // make a tree
  for(i = 0;i < level;i++)
  {
    growtree(head);
  }


  // print the tree for Gnuplot
  //writeTree(head);

  readLibrary(head);
  readStudent();

  begin(head);

  printf("已达到文章末尾.\n");
  return 0;
}



int judge(int numbers)
{
    int level;
    int maxnumber;
    if(numbers <= 84)
    {
       level = 3;
       maxnumber = 84;
    }
    else if(numbers > 84 && numbers <= 340)
    {
       level = 4;
       maxnumber = 340;
    }
    else if(numbers > 340 && numbers <= 1364)
    {
       level = 5;
       maxnumber = 1364;
    }
    else if(numbers > 1364 && numbers <= 5460)
    {
       level = 6;
       maxnumber = 5460;
    }
    else if(numbers > 5460 && numbers <= 21844)
    {
       level = 7;
       maxnumber = 21844;
    }
    else if(numbers > 21844 && numbers <= 87380)
    {
       level = 8;
       maxnumber = 87380;
    }
    else if(numbers > 87380 && numbers <= 349524)
    {
       level = 9;
       maxnumber = 349524;
    }
    else if(numbers > 349524 && numbers <= 1398100)
    {
       level = 10;
       maxnumber = 1398100;
    }

    MaxAdd = maxnumber - numbers;

    printf("MaxAdd = %d",MaxAdd);
    return level;
}

int numcount()
{
  int count = 0;
  char a[20],b[50];
  int d;
  FILE *fp=fopen("Library.txt","r");
  if(!fp)
  {
    printf("open error");
    return 0;
  }

  while((fscanf(fp,"%s %s %d",&a,&b,&d))!=EOF)
  {
      count++;
  }
  fclose(fp);
  return count;
}

void growtree(Node *node)
{
  int i;
  if(node->child[0] == NULL){
     makeChildren(node);
     return;
  }
  else{
     for(i = 0;i < 4;i++)
     {
        growtree(node->child[i]);
     }
  }
}
// make a node at given location (x,y) and level

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
  {
    node->child[i] = NULL;
  }

   node->borrow = -1;

  return node;
}

// split a leaf nodes into 4 children

void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

// write out the tree to file 'quad.out'

void writeTree( Node *head ) {

  FILE *fp = fopen("quad.out","w");

  writeNode(fp,head);

  fclose(fp);

  return;
}

// recursively visit the leaf nodes

void writeNode( FILE *fp, Node *node ) {

  int i;

  if( node->child[0] == NULL )
    printOut( fp, node );
  else {
    for ( i=0; i<4; ++i ) {
      writeNode( fp, node->child[i] );
    }
  }
  return;
}

// write out the (x,y) corners of the node

void printOut( FILE *fp, Node *node ) {
  double x = node->xy[0];
  double y = node->xy[1];
  int level = node->level;
  double h = pow(2.0,-level);

  fprintf(fp, " %g %g\n",x,y);
  fprintf(fp, " %g %g\n",x+h,y);
  fprintf(fp, " %g %g\n",x+h,y+h);
  fprintf(fp, " %g %g\n",x,y+h);
  fprintf(fp, " %g %g\n\n",x,y);

  return;
}


void begin(Node *head)
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
            printf("    |Please choose what you want：(select number)                                                |\n");
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
                       StudentRegister();
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
            printf("    |Please choose what you want：(select number)                                                |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |1.List all books.                                                                           |\n");
            printf("    |2.List all registered users.                                                                |\n");
            printf("    |3.Add books.                                                                                |\n");
            printf("    |4.Remove book.                                                                              |\n");
            printf("    |5.Exit.                                                                                     |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");


            int staChoice;
            scanf("%d",&staChoice);

            switch(staChoice)
            {
            case 1:
                Listallbook(head);
                break;
            case 2:
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

                printf("    |Please make sure you want to add 《%s》 book\n",Abook);
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

                printf("    |Please make sure you want to remove 《%s》 book\n",Rbook);
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

}
void readStudent()
{
    Reader *reader=(Reader *)malloc(sizeof(Reader));

    FILE *fp=fopen("Students.txt","r");
    if(!fp)
    {
        printf("open error");
        return 0;
    }
    char a[20],b[20],c[20],d[20];

    Reader *pnew;
    while((fscanf(fp,"%s %s %s %s",&a,&b,&c,&d))!=EOF)
    {
        pnew = (Reader*)malloc(sizeof(Reader));

		strcpy(pnew->Studentnum, a);
		strcpy(pnew->Studentname, b);
        strcpy(pnew->booksrentindex, c);
		strcpy(pnew->booksrentname, d);

        //printf("pnew->Studentnum = %s\n",pnew->Studentnum);
        //printf("pnew->Studentname = %s\n",pnew->Studentname);
        //printf("pnew->booksrentindex = %s\n",pnew->booksrentindex);
        //printf("pnew->booksrentname = %s\n\n",pnew->booksrentname);

		pnew->next = reader->next;
		reader->next = pnew;
    }
    fclose(fp);
}

void readLibrary(Node *node)
{
	printf("已经入read()函数！！\n");
	FILE *fp = fopen("Library.txt", "r");
	if (!fp)
	{
		printf("open error");
		return;
	}
	else
	{
		cyclewrite(fp,node);
	}

}

void cyclewrite(FILE *fp, Node *node)
{
  int i;
  int a;
  char b[20];
  int c;
  if(node->child[0] == NULL)
  {
     return;
  }
  else
  {
     for(i = 0;i < 4;i++)
     {
              cyclewrite(fp,node->child[i]);
              if((fscanf(fp,"%d %s %d",&a,&b,&c))!=EOF)
              {
                  //strcpy(node->child[i]->booksindex,a);

                  node->child[i]->booksindex = a;
                  strcpy(node->child[i]->booksname,b);
                  node->child[i]->borrow = c;

                  //printf("node->child[i]->level = %d\n",node->child[i]->level);
                  //printf("node->child[i]->xy[0] = %.2lf\n",node->child[i]->xy[0]);
                  //printf("node->child[i]->xy[1] = %.2lf\n",node->child[i]->xy[1]);
                  //printf("node->child[i]->booksindex = %d\n",node->child[i]->booksindex);
                  //printf("node->child[i]->booksname = %s\n",node->child[i]->booksname);
                  //printf("node->child[i]->borrow = %d\n\n",node->child[i]->borrow);
              }
        }
     }
}

void StudentRegister()
{
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |                           Student Register                                                 |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |Please input your informations：(as shown below)                                            |\n");
            printf("    |--------------------------------------------------------------------------------------------|\n");
            printf("    |1.Your Name:");

            //如何做到对字符串的检测
            char name[50];
            scanf("%s",name);
            printf("Please enter the correct name and do not include any numbers or other characters that do not match the name.\n");


            printf("    |1.Your Id Number:(Leeds College student number, nine digits)");

            char number[10];
            scanf("%s",number);

            printf("    |3.Your Professional full name:(you'd better no more than ten characters)");

            char college[50];
            scanf("%s",college);

            printf("    |--------------------------------------------------------------------------------------------|\n");

}

void Listallbook(Node *node)
{
    int i;
    if( node->child[0] == NULL )
    {
       return;
    }
    else
    {
        for ( i=0; i<4; ++i )
        {
           Listallbook(node->child[i]);

           if(node->child[i]->borrow != -1)
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
  return;

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
                 printf("    |The book 《%s》 you have reviewed : retain                                                 |\n",node->child[i]->booksname);
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
                printf("    |Please determine if you want to borrow 《%s》,Please enter( 1(yes)/ 0(no) )                 |\n",node->child[i]->booksname);

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
                node->child[i]->borrow = -1;
                printf("    |--------------------------------------------------------------------------------------------|\n");
                printf("    |Success : This book is now been removed !!                                                  |\n");
                printf("    |--------------------------------------------------------------------------------------------|\n");

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






























