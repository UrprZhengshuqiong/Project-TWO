#include "stdio.h"
#include "stdlib.h"
#include "math.h"

// tree data structure

struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];


  char booksindex[20];//图书编号
  char booksname[20]; //图书名字
  int borrow;         //图书是否被借出
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

// main

int main( int argc, char **argv ) {

  begin();

  //count numbers to  build tree
  int numbers = numcount();
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

  //PrintTest(head);

  printf("已达到文章末尾.\n");
  return 0;
}



int judge(int numbers)
{
    int level;
    if(numbers <= 4 && numbers > 0)
    {
       level = 1;
    }
    else if(numbers > 4 && numbers <= 20)
    {
       level = 2;
    }
    else if(numbers > 20 && numbers <= 84)
    {
       level = 3;
    }
    else if(numbers > 84 && numbers <= 340)
    {
       level = 4;
    }
    else if(numbers > 340 && numbers <= 1364)
    {
       level = 5;
    }
    else if(numbers > 1364 && numbers <= 5460)
    {
       level = 6;
    }
    else if(numbers > 5460 && numbers <= 21844)
    {
       level = 7;
    }
    else if(numbers > 21844 && numbers <= 87380)
    {
       level = 8;
    }
    else if(numbers > 87380 && numbers <= 349524)
    {
       level = 9;
    }
    else if(numbers > 349524 && numbers <= 1398100)
    {
       level = 10;
    }
    return level;
}

int numcount()
{
  int count = 0;
  char a[20],b[50];
  int d;
  FILE *fp=fopen("C:\\Users\\萨利酱\\Desktop\\study\\project two\\read\\info.txt","r");
  if(!fp)
  {
    printf("open error");
    return 0;
  }
   printf("    |----------------------------------------------------------------------------|\n");
   printf("    |Book catalogues and borrowing information                                   |\n");
   printf("    |----------------------------------------------------------------------------|\n");
  while((fscanf(fp,"%s %s %d",&a,&b,&d))!=EOF)
  {
      count++;
      printf("    |");
      printf("%4s        %-40s ",a,b);
      if(d == 1)
      {
          printf("retain.                |\n");
      }
      else
      {
          printf("Already loaned out.    |\n");
      }
      printf("    |----------------------------------------------------------------------------|\n");
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
    node->child[i] = NULL;

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


void begin()
{
    printf("    |--------------------------------------------------------------------------------------------|\n");
    printf("    |                        Library management system                                           |\n");
    printf("    |--------------------------------------------------------------------------------------------|\n");
    printf("    | Please choose whether you are an employee or a student.(1 or 2)                            |\n");
    printf("    |--------------------------------------------------------------------------------------------|\n");
    printf("    | 1.I am a student.                                                                          |\n");
    printf("    | 2.I am a staff.                                                                            |\n");
    printf("    |--------------------------------------------------------------------------------------------|\n");

    int choice;

    do
    {
        scanf("%d",&choice);

        if(choice == 1)
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




            break;
        }
        else if(choice == 2)
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




            break;
        }
        else
        {
            printf("    |Error : Please enter the correct number, 1 for students and 2 for employees.                |\n");
            fflush(stdin);
        }
  }while(choice != 1 || choice != 2);

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

        printf("pnew->Studentnum = %s\n",pnew->Studentnum);
        printf("pnew->Studentname = %s\n",pnew->Studentname);
        printf("pnew->booksrentindex = %s\n",pnew->booksrentindex);
        printf("pnew->booksrentname = %s\n\n",pnew->booksrentname);

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
  char a[20],b[20];
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
              if((fscanf(fp,"%s %s %d",&a,&b,&c))!=EOF)
              {
                  strcpy(node->child[i]->booksindex,a);
                  strcpy(node->child[i]->booksname,b);
                  node->child[i]->borrow = c;

                  printf("node->child[i]->level = %d\n",node->child[i]->level);
                  printf("node->child[i]->xy[0] = %.2lf\n",node->child[i]->xy[0]);
                  printf("node->child[i]->xy[1] = %.2lf\n",node->child[i]->xy[1]);
                  printf("node->child[i]->booksindex = %s\n",node->child[i]->booksindex);
                  printf("node->child[i]->booksname = %s\n",node->child[i]->booksname);
                  printf("node->child[i]->borrow = %d\n\n",node->child[i]->borrow);
              }
        }
     }
}


































