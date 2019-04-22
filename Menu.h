#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Tree.h"
#include "List.h"
#include "LibraryBook.h"
int ExiorNot3;

int ExiorNot4;

int ExiorNot5;

int ExiorNot6;

int numbers;

int MaxAdd;

void Begin(Node *head,Reader *reader);

void SelectListallbooks(Node *head);

void JudgeNull(Node *node);

void giveName(Node* head);

int menu(int choice,Node* node);

#endif // MENU_H_INCLUDED
