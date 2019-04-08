#include "stdio.h"
#include "stdlib.h"
#include "Tree.h"
#include "Menu.h"

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

void readLibrary(Node *node)
{
    int a,c;
    char b;

	FILE *fp = fopen("Library.txt", "r");

	if (!fp)
	{
		printf("open error");
		return;
	}
	else
	{
	    fscanf(fp,"%d %s %d",&a,&b,&c);

        printf("number = %d\n",c);

        numbers = c;

	    int i = 0;

        int level = judge(numbers);

        printf("level = %d\n",level);

        for(i = 0;i < level;i++)
        {
            growtree(node);
        }

		cycleread(fp,node);
	}
    fclose(fp);
}

void cycleread(FILE *fp, Node *node)
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
              cycleread(fp,node->child[i]);
              if((fscanf(fp,"%d %s %d",&a,&b,&c))!=EOF)
              {
                  node->child[i]->booksindex = a;
                  strcpy(node->child[i]->booksname,b);
                  node->child[i]->borrow = c;

                  //printf("node->child[i]->booksindex:%d\n",node->child[i]->booksindex);

                  //printf("node->child[i]->booksname:%s\n",node->child[i]->booksname);
              }
        }
     }
}

void WriteLibrary(Node* node)
{
    FILE *fp1=fopen("Library.txt","w");
    int i = 0;
    char * name = "图书总量";

    if (!fp1)
	{
		printf("open error");
		return;
	}
	else
	{
	    fprintf(fp1,"%d %s %d\n",i,name,numbers - RemoveBooksNum);
		cyclewrite(fp1,node);
	}
    fclose(fp1);

}

void cyclewrite(FILE *fp1, Node *node)
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
            cyclewrite(fp1, node->child[i]);

            if(node->child[i]->borrow == 1 || node->child[i]->borrow == 0)  //只有在未被移除地情况下，才写入
            {
                printf("node->child[i]->booksindex = %d\n",node->child[i]->booksindex);
                printf("node->child[i]->booksname = %s\n",node->child[i]->booksname);
                printf("node->child[i]->borrow = %d\n\n",node->child[i]->borrow);
                fprintf(fp1,"%d %s %d\n",node->child[i]->booksindex,node->child[i]->booksname,node->child[i]->borrow);
            }

        }
    }

}
//Old tree build
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

void writeTree( Node *head ){

  FILE *fp = fopen("quad.out","w");

  writeNode(fp,head);

  fclose(fp);

  return;
}

void writeNode( FILE *fp, Node *node ){

  int i;

  if( node->child[0] == NULL )
    printOut( fp, node );
  else {
    for ( i=0; i<4; ++i ) {
      writeNode( fp, node->child[i]);
    }
  }
  return;
}

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
