#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "Tree.h"
#include "LibraryBook.h"
#include "Menu.h"
#include "Reader.h"


int main( int argc, char **argv ){

  Node *head;

  head = makeNode( 0.0,0.0, 0 );

  readLibrary(head);

  Reader* reader = createList();

  readStudent(reader);

  Begin(head,reader);

  return 0;

}
