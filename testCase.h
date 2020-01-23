#ifndef TESTCASE_H
#define TESTCASE_H


#include <iostream>
#include <list>
#include <iterator>
#include <chrono>


#include "book.h"
#include "avlTree.h"
#include "sequentialSearchList.h"
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


  cout << "Binary Search Linked List" << endl;
  cout << "*********************************************" << endl << endl;

  Book searchItem = new Book("Men in Black: The Grazer Conspiracy", "0-7394-0980-8", "Dean Wesley Smith", "TBD", "05/13/2018", 15, 8.69, 11.3);

  auto start = std::chrono::high_resolution_clock::now();


  Book* bookRetrieved = sequntialSearch(bookList, searchItem);



  auto finish = std::chrono::high_resolution_clock::now();

  if (bookRetrieved != nullptr)
  {
    bookRetrieved.print();
  }






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
