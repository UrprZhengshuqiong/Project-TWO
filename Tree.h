#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

struct qnode{
  int level;
  double xy[2];
  struct qnode *child[4];


  int booksindex;      //book Index
  char booksname[50];  //book name
  char authorname[50]; //author name
  int borrow;
};

typedef struct qnode Node;

Node *makeNode( double x, double y, int level );

void makeChildren( Node *parent );

void writeTree( Node *head );

void writeNode( FILE *fp, Node *node );

void printOut( FILE *fp, Node *node );

void growtree(Node *node);

char BigCategories[30][50];

extern int RemoveBooksNum;

int judge(int numbers);

void readLibrary(Node* node);

void cycleread(FILE *fp, Node *node);

void WriteLibrary(Node* node);

void cyclewrite(FILE *fp, Node *node);

void initialBuild(int LevelNumber[50],Node *node,int tempnumber);

void setlable(Node *head);

#endif // TREE_H_INCLUDED
