#ifndef INVENTORYMODULE_H
#define INVENTORYMODULE_H

#include <iostream>
#include <list>
#include <iterator>
#include "book.h"
#include  "sequentialSearchList.h"
#include "avlTree.h"

using namespace std;

void inventoryMenu(list<Book>& bookList, AvlTree& bookTree);
Book* searchBook(list<Book>& bookList, AvlTree& bookTree) throw(string);
void addBook();
void editBook();
void deleteBook();

#endif
