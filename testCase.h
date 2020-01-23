#ifndef TESTCASE_H
#define TESTCASE_H


#include <iostream>
#include <list>
#include <iterator>
#include <chrono>


#include "book.h"
#include "avlTree.h"
using namespace std;

void testBookList(list<Book> bookList)
{
  system("clear");
  cout << "Testing  STL List data structure function" << endl;
  cout << "*********************************************" << endl << endl;
  list<Book>::iterator it;


  for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    cout << (*it).getBookTitle() << endl;

  }
  cout << endl << endl;


  cout << "Get Search Time " << endl;
  cout << "*********************************************" << endl << endl;

  auto start = std::chrono::high_resolution_clock::now();
  auto finish = std::chrono::high_resolution_clock::now();






  chrono::duration<double> elapsed = finish - start;
  cout << "Elapsed time: " << elapsed.count() << " s\n";

  cin.ignore(1000, '\n');
  cin.get();
}


void testBookTree(AvlTree& bookTree)
{
  system("clear");
  cout << "Testing AVL Tree data structure" << endl;
  cout << "*********************************************" << endl << endl;
  bookTree.inOrderTraversal();
  cout << endl << endl;

  cin.ignore(1000, '\n');
  cin.get();
}


#endif
