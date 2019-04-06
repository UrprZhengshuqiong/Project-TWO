#ifndef LIBRARYBOOK_H_INCLUDED
#define LIBRARYBOOK_H_INCLUDED
#include "Tree.h"
#include "List.h"

int RemoveBooksNum;

int judge(int numbers);

void readLibrary(Node* node);

void cycleread(FILE *fp, Node *node);

void WriteLibrary(Node* node);

void cyclewrite(FILE *fp, Node *node);

void writeList(Reader *pmove,FILE *fp2);

//Function
void Listallbook(Node *node);

void Searchforbooks(Node *node,char * book);

void Borrowingbooks(Node *node,char * Bbook);

void RemoveBooks(Node * node,char * Mbook);

void ReturnaBook(Node *node,char * Rbook);

void Addbooks(Node * node,char * Abook);

#endif // LIBRARYBOOK_H_INCLUDED
