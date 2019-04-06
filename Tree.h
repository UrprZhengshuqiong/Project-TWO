#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

struct qnode{
  int level;
  double xy[2];
  struct qnode *child[4];


  int booksindex;      //book Index
  char booksname[20]; //book name
  int borrow;
};

typedef struct qnode Node;

Node *makeNode( double x, double y, int level );

void makeChildren( Node *parent );

void writeTree( Node *head );

void writeNode( FILE *fp, Node *node );

void printOut( FILE *fp, Node *node );

void growtree(Node *node);


#endif // TREE_H_INCLUDED
