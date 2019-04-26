#ifndef HISTORICALREC_H_INCLUDED
#define HISTORICALREC_H_INCLUDED

#include "HistoricalList.h"

/**Print student loan book information.**/
void printHisList(His* pMove);

/**Get the local time **/
void getTime();

/**Adds new historical information**/
void AddRecord(His* his,int Studentnum,char* Studentname,int status,char *bookname);
#endif // HISTORICALREC_H_INCLUDED
