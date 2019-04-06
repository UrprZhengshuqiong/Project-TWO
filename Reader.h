#ifndef READER_H_INCLUDED
#define READER_H_INCLUDED
#include "Tree.h"
#include "List.h"

void readStudent(Reader *reader);

void WriteStudent(Reader* pwrite);

void writeList(Reader *pmove,FILE *fp2);

void StudentRegister();

void addStudent(Reader* pAdd,char* Studentnum,char* Studentname,char* Collegename);

void StudentRegister(Reader*reader);

#endif // READER_H_INCLUDED
