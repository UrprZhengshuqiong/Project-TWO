#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

/**The structure of a tree**/
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

/**Tree functional correlation**/

Node *makeNode( double x, double y, int level );

void makeChildren( Node *parent );

void growtree(Node *node);

void destroyTree(Node *node);

/**The operation of reading and writing files to and from a tree**/

/**Reads data from a file and stores it in a Quadtree**/

void readLibrary(Node* node);

void initialBuild(int LevelNumber[50],Node *node,int tempnumber);

void setlable(Node *node,int choice);

int judge(int numbers);

void cycleread(FILE *fp, Node *node);

/**Writes the contents of the quadtree to a file**/

void WriteLibrary(Node* node);

void cyclewrite(FILE *fp, Node *node);


#endif // TREE_H_INCLUDED
