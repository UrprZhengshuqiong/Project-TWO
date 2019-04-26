#ifndef LIBRARYBOOK_H_INCLUDED
#define LIBRARYBOOK_H_INCLUDED
#include "Tree.h"
#include "List.h"
//Function
/**List all books**/
void Listallbook(Node *node);

/**Search for books**/
void Searchforbooks(Node *node,char * book);

/**Borrowing books**/
void Borrowingbooks(Node *node,char * Bbook,int BookRentNum);

/**Remove Books**/
void  RemoveBooks(Node * node,int Index,int temptry);

/**Return Books**/
void ReturnaBook(Node *node,char * Rbook);

/**Add books**/
void  Addbooks(Node * node,char * Abook,char * authorName,int temptry);

#endif // LIBRARYBOOK_H_INCLUDED
