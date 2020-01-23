#ifndef TESTCASE_H
#define TESTCASE_H


#include <iostream>
#include <list>
#include <iterator>
#include <chrono>
#include <iomanip>


#include "book.h"
#include "avlTree.h"
#include "sequentialSearchList.h"
using namespace std;

void testBookList(list<Book>& bookList)
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


  cout << "List Sequential Search" << endl;
  cout << "*********************************************" << endl << endl;

  Book* searchItem = new Book("Men in Black: The Grazer Conspiracy", "0-7394-0980-8", "Dean Wesley Smith", "TBD", "05/13/2018", 15, 8.69, 11.3);


  auto start = std::chrono::high_resolution_clock::now();
  try
  {
    sequentialSearch(bookList, *searchItem);
  }
  catch(string ex)
  {
    cout << ex << endl;
  }
  auto finish = std::chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = finish - start;
  cout << "Elapsed time: " << fixed << setprecision(12) << elapsed.count()/1000 << " ms\n";


  Book* tempBook = new Book("hi", "yo", "no", "r", "to", 4, 3, 2);
  start = std::chrono::high_resolution_clock::now();
  try
  {
    sequentialSearch(bookList, *tempBook);
  }
  catch(string ex)
  {
    cout << ex << endl;
  }
  finish = std::chrono::high_resolution_clock::now();
  elapsed = finish - start;
  cout << "Elapsed time: " << fixed << setprecision(12) << elapsed.count()/1000 << " ms\n";











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



  cout << "AVL Tree Search" << endl;
  cout << "*********************************************" << endl << endl;
  Book* searchItem = new Book("Men in Black: The Grazer Conspiracy", "0-7394-0980-8", "Dean Wesley Smith", "TBD", "05/13/2018", 15, 8.69, 11.3);


  auto start = std::chrono::high_resolution_clock::now();
  try
  {
    bookTree.search(*searchItem);
  }
  catch(string ex)
  {
    cout << ex << endl;
  }
  auto finish = std::chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = finish - start;
  cout << "Elapsed time: " << fixed << setprecision(12) << elapsed.count()/1000 << " ms\n";




  Book* tempBook = new Book("hi", "yo", "no", "r", "to", 4, 3, 2);
  start = std::chrono::high_resolution_clock::now();
  try
  {
    bookTree.search(*tempBook);
  }
  catch(string ex)
  {
    cout << ex << endl;
  }
  finish = std::chrono::high_resolution_clock::now();
  elapsed = finish - start;
  cout << "Elapsed time: " << fixed << setprecision(12) << elapsed.count()/1000 << " ms\n";


  cin.ignore(1000, '\n');
  cin.get();
}


#endif
