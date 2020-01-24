#ifndef REPORTSMODULE_H
#define REPORTSMODULE_H

#include <iostream>
#include <iomanip>
#include <list>
#include <iterator>
#include <ctime>
#include "book.h"
#include "avlTree.h"
#include "compareList.h"
using namespace std;

void reportsMenu(list<Book>& bookList, AvlTree& bookTree);

void viewAllListing(list<Book>& bookList, AvlTree& bookTree);

void reportWholesale(list<Book>& bookList, AvlTree& bookTree);

void reportRetail(list<Book>& bookList, AvlTree& bookTree);

void viewByQuantity(list<Book>& bookList, AvlTree& bookTree);

void viewByWholesale(list<Book>& bookList, AvlTree& bookTree);

void viewByDateAdded(list<Book>& bookList, AvlTree& bookTree);





#endif
