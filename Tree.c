#include "stdio.h"
#include "stdlib.h"
#include "Tree.h"
#include "Menu.h"
#include "string.h"

int entrance;

int MiniClassification;

int cyclewriteDoor;

int JudgeSize;

int LevelNumber[50];

char BigCategories[30][50];

int MaxAdd;

int setlableblock;

/**Tree functional correlation**/
Node *makeNode( double x, double y, int level)
{

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

void makeChildren( Node *parent )
{
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

void growtree(Node *node)
{
  int i;
  if(node->child[0] == NULL)
  {
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

/**Reads data from a file and stores it in a Quadtree**/
void readLibrary(Node *node)
{
    int i;

    for(i = 0;i < 2;i++)
    {
       growtree(node);
    }

    int a;
    int c;
    char b[20],d[200];
    char delims[] = ",";

    int j = 0;

    int tempnumber = 0;

    entrance = 1;

    MiniClassification = 1;

	FILE *fp = fopen("data/Library.txt", "r");

	if(!fp)
	{
		printf("open error");
		return;
	}
	else
	{
	    /**The total number of reads and the number of sections in each category**/
	    fscanf(fp,"%d %s %d",&a,&b,&c);
        fscanf(fp,"\n%[^\n]",&d);

        char *result = NULL;

        result = strtok(d,delims);

        i = 0;

        while( result != NULL )
        {
           LevelNumber[i] = atoi(result);   //function'atoi' let string->integer

           result = strtok(NULL,delims);

           i++;
        }

        for(i = 0;i < 4;i++)
        {
           initialBuild(LevelNumber,node->child[i],tempnumber);
           tempnumber += 4;
        }

        int temp = 0;

        for(i = 0;i < 4;i++)
        {
            for(j = 0;j < 4;j++)
            {
                /**Read information for each category**/
                fscanf(fp,"%d %s %d",&a,&b,&c);
                fscanf(fp,"\n%[^\n]",&d);

                /**Store the name of each category in an array**/
                strcpy(BigCategories[temp],d);

                cycleread(fp,node ->child[i]->child[j]);

                entrance = 1;

                MiniClassification = 1;

                temp++;
            }
        }
	}
    fclose(fp);
}

void cycleread(FILE *fp, Node *node)
{
  int i;
  int a;
  char b[50];
  char d[50];
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

                    if(entrance == 1 && MiniClassification == 1 && fscanf(fp,"%d %s %d",&a,&b,&c) != EOF)
                    {
                          fscanf(fp,"\n%[^\n]",&d);

                          /**If a small class or a large class end flag is encountered, the 'read channel' is closed**/
                          if(strcmp(b,"@endBigCategories") == 0)
                          {
                              entrance = 0;
                          }
                          else if(strcmp(b,"@endSmallCategories") == 0)
                          {
                               MiniClassification = 0;
                          }
                          else
                          {
                               node->child[i]->booksindex = a;
                               strcpy(node->child[i]->authorname,b);
                               node->child[i]->borrow = c;
                               strcpy(node->child[i]->booksname,d);
/**Read test code**/
/*

                               if(strcmp(b,"SmallCategories") == 0)
                               {

                                   printf("node->child[i]->Index:%d\n",node->child[i]->booksindex);
                                   printf("Books categories:%s\n",node->child[i]->authorname);
                                   printf("Books totalNumber: %d\n\n",node->child[i]->borrow);

                               }
                               else
                               {
                                    printf("node->child[i]->booksindex:%d\n",node->child[i]->booksindex);
                                    printf("node->child[i]->booksname:%s\n",node->child[i]->booksname);
                                    printf("node->child[i]->authorname:%s\n",node->child[i]->authorname);
                                    printf("node->child[i]->borrow: %d\n\n",node->child[i]->borrow);
                               }
*/

                          }
                    }

                    /**The tage 'ClassBoundary' -- Marks the end of the entire class and the beginning of the next category read**/
                    if(strcmp(node->child[i]->authorname,"ClassBoundary") == 0)
                    {
                        MiniClassification = 1;
                    }

              }
       }
}

/**Build the tree a 'second time' in depth based on each of the large categories of information read**/
void initialBuild(int LevelNumber[50],Node * node,int tempnumber)
{
    int i,j;
    for(i = 0;i < 4;i++)
    {
        tempnumber++;

        int level = judge(LevelNumber[tempnumber]);

        for(j = 0;j < level + 1;j++)
        {
            growtree(node->child[i]);

            if(j == 0)
            {
               setlable(node->child[i],1);
            }
        }
    }
    return;
}

void setlable(Node *node,int choice)
{
  int i;
  if(node->child[0] == NULL)
  {
     if(choice == 1)
     {
         strcpy(node->authorname,"ClassBoundary");
     }
     else if(choice == 2 && setlableblock == 1)
     {
         node->borrow += 1;

         setlableblock = -1;
     }
    else if(choice == 3 && setlableblock == 1)
     {
         node->borrow -= 1;

         setlableblock = -1;
     }
     return;
  }
  else
  {
     for(i = 0;i < 4;i++)
     {
        setlable(node->child[i],choice);
     }
  }

}
/**Pass in the total number of books to determine the number of levels of trees to build**/
int judge(int numbers)
{
    int level;
    int maxnumber;
    if( numbers >=0 && numbers < 84)
    {
       level = 3;
       maxnumber = 84;
    }
    else if(numbers >= 84 && numbers < 340)
    {
       level = 4;
       maxnumber = 340;
    }
    else if(numbers >= 340 && numbers < 1364)
    {
       level = 5;
       maxnumber = 1364;
    }
    else if(numbers >= 1364 && numbers < 5460)
    {
       level = 6;
       maxnumber = 5460;
    }
    else if(numbers >= 5460 && numbers < 21844)
    {
       level = 7;
       maxnumber = 21844;
    }
    else if(numbers >= 21844 && numbers < 87380)
    {
       level = 8;
       maxnumber = 87380;
    }
    else if(numbers >= 87380 && numbers < 349524)
    {
       level = 9;
       maxnumber = 349524;
    }
    else if(numbers >= 349524 && numbers < 1398100)
    {
       level = 10;
       maxnumber = 1398100;
    }

    MaxAdd = maxnumber - numbers;

    return level;
}

/**Writes the contents of the quadtree to a file**/
void WriteLibrary(Node* node)
{
    FILE *fp1=fopen("data/Library.txt","w");

    int i = 0,j = 0;

    char * name = "TotalAmount";

    char strNum[100] = {};

    int total = 0;

    JudgeSize = 0;

    for(;i < 16;i++)
    {
         char tempstr[20];

         int temNum;

         temNum = LevelNumber[i];

         total += LevelNumber[i];

         itoa(temNum,tempstr,10);

         strcat (strNum,tempstr);

         strcat (strNum,",");

    }
    if (!fp1)
	{
		printf("open error");
		return;
	}
	else
	{
	    fprintf(fp1,"%d %s %d\n",i,name,total);
        fprintf(fp1,"%s\n\n",strNum);

        int count = 0;

	    for(i = 0;i < 4;i++)
        {
            for(j = 0;j < 4;j++)
            {
               count++;
               int serialNum = count * 10;

               char BigC[] = "BigCategories";

               fprintf(fp1,"%d %s %d\n",serialNum,BigC,LevelNumber[count - 1]);
               fprintf(fp1,"%s\n\n",BigCategories[count - 1]);

               cyclewriteDoor = 1;

		       cyclewrite(fp1,node->child[i]->child[j]);
            }
        }
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
            if(cyclewriteDoor == 1 && strcmp(node->child[i]->authorname,"SmallCategories") == 0)
            {
               int temp = node->child[i]->booksindex % 10;

               if(temp == 4)
               {
                   JudgeSize = 1;
               }
               fprintf(fp1,"%d %s %d\n",node->child[i]->booksindex,node->child[i]->authorname,node->child[i]->borrow);
               fprintf(fp1,"%s\n",node->child[i]->booksname);

            }
            else if(cyclewriteDoor == 1 && ( node->child[i]->borrow == 1 || node->child[i]->borrow == 0 ))
            {
                fprintf(fp1,"%d %s %d\n",node->child[i]->booksindex,node->child[i]->authorname,node->child[i]->borrow);
                fprintf(fp1,"%s\n",node->child[i]->booksname);

            }
            else if(cyclewriteDoor == 1 && node->child[i]->borrow == -1)
            {
                cyclewriteDoor = 0;
            }


            if(strcmp(node->child[i]->authorname,"ClassBoundary") == 0)
            {
               if(JudgeSize == 1)
               {
                    char endbig[] = "@endBigCategories";
                    fprintf(fp1,"\n %d %s %d\n",node->child[i]->booksindex,endbig,node->child[i]->borrow);
                    fprintf(fp1,"%s\n\n",endbig);

                    JudgeSize = 0;

               }
               else
               {
                       char endsmall[] = "@endSmallCategories";
                       fprintf(fp1,"\n %d %s %d\n",node->child[i]->booksindex,endsmall,node->child[i]->borrow);
                       fprintf(fp1,"%s\n\n",endsmall);
               }
               cyclewriteDoor = 1;
            }

        }

    }
}

/**Destroy the tree and free up memory**/
void destroyTree(Node *node)
{
  int i;
  if(node->child[0] == NULL){
    return;
  }
  else{
     for(i = 0;i < 4;i++)
     {
        destroyTree(node->child[i]);
        free(node->child[i]);
        node->child[i] = NULL;
     }
  }
}


