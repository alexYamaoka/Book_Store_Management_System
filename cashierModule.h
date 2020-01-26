#ifndef CASHIERMODULE_H
#define CASHIERMODULE_H


#include <iostream>
#include <list>
#include <iterator>
#include <set>
#include "book.h"
#include "inventoryModule.h"
#include "avlTree.h"
#include "compareList.h"

using namespace std;

void cashierMenu(list<Book>& bookList, AvlTree& bookTree);

void addBookToCart(list<Book>& bookList, AvlTree& bookTree, list<Book>& shoppingCart);

void removeBookFromCart(list<Book>& bookList, AvlTree& bookTree, list<Book>& shoppingCart);

bool checkOutCart(list<Book>& bookList, AvlTree& bookTree, list<Book>& shoppingCart);

void printCartItems(list<Book>& bookList, AvlTree& bookTree, list<Book>& shoppingCart);

void completeTransaction(list<Book>& bookList, AvlTree& bookTree, list<Book>& shoppingCart);


#endif
