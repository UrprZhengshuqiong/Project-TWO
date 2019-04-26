#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Tree.h"
#include "List.h"
#include "LibraryBook.h"
#include "HistoricalRec.h"

/**Menu interface**/
void Begin(Node *head,Reader *reader,His *his);

/**Judge and show the user's books**/
void SelectListallbooks(Node *head);

/**Print and shows the big sixteen class name**/
int BookSelMenu(int choice,Node* head);

/**Print and shows the small class name**/
void giveName(Node* head);

/**Judge and add a new book subclass.**/
void JudgeNull(Node *node);

#endif // MENU_H_INCLUDED
