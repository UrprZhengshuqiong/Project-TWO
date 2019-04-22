#ifndef LIBRARYBOOK_H_INCLUDED
#define LIBRARYBOOK_H_INCLUDED
#include "Tree.h"
#include "List.h"
//Function

void Listallbook(Node *node);

void Searchforbooks(Node *node,char * book);

void Borrowingbooks(Node *node,char * Bbook);

void  RemoveBooks(Node * node,int Index,int temptry);

void ReturnaBook(Node *node,char * Rbook);

void Addbooks(Node * node,char * Abook);

#endif // LIBRARYBOOK_H_INCLUDED
