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
Book* searchBook(list<Book>& bookList, AvlTree& bookTree);
void addBook(list<Book>& bookList, AvlTree& bookTree);
void editBook(list<Book>& bookList, AvlTree& bookTree);
void editBookMenu(list<Book>& bookList, Book* editBook);
void deleteBook(list<Book>& bookList, AvlTree& bookTree);

#endif
