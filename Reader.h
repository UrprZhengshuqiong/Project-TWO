#ifndef READER_H_INCLUDED
#define READER_H_INCLUDED
#include "Tree.h"
#include "List.h"

/**Print all registered student information**/
void printList(Reader* pMove);

/**Enter the information of the registered student**/
void StudentRegister(Reader*reader);

/**Check the login information of the students**/
int examStudentPass(Reader* reader,int In_Studentnum,char * password);

/**Modify the loan information of registered students**/
void ModifyLoanInfor(Reader* reader,int In_Studentnum,char * bookname,int status,int BookRentNum);

/**Add a node to a single chain**/
void addStudent(Reader* reader,int Studentnum,char* Studentname,char* Collegename,char *password);

#endif // READER_H_INCLUDED
