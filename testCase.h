#ifndef TESTCASE_H
#define TESTCASE_H


#include <iostream>
#include <list>
#include <iterator>
#include "book.h"
#include "avlTree.h"
using namespace std;

void testBookList(list<Book> bookList)
{
  system("clear");
  cout << "Testing  STL List data structure function" << endl << endl;
  list<Book>::iterator it;


  for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    cout << (*it).getBookTitle() << endl;

  }

  cin.ignore(1000, '\n');
  cin.get();
}


void testBookTree(AvlTree& bookTree)
{
  system("clear");
  cout << "Testing AVL Tree data structure" << endl;
  bookTree.inOrderTraversal();

  cin.ignore(1000, '\n');
  cin.get();
}


#endif
