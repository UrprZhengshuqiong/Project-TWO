#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "Tree.h"
#include "LibraryBook.h"
#include "Menu.h"
#include "Reader.h"
#include "HistoricalRec.h"
#include "string.h"


int main( int argc, char **argv ){

  /**Building tree framework**/
  Node *head;

  head = makeNode( 0.0,0.0, 0 );

  /**Reads data from a file and stores it in a Quadtree**/
  readLibrary(head);

  /**Establish head node**/
  Reader* reader = createList();

  /**Read student from a file**/
  readStudent(reader);

  His* his = createHisList();

  /**Read records from a file**/
  readHistorical(his);

  Begin(head,reader,his);

  /**Destroy the tree and free up memory**/
  destroyTree(head);

  free(head);

  head = NULL;

  /**Release a single linked list of student information records**/
  freelist(reader);

  free(reader);

  reader = NULL;

  /**Release a single linked list of book lending information records**/
  freeHisList(his);

  free(his);

  his = NULL;

  return 0;

}
