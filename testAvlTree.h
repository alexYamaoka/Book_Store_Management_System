#ifndef TESTAVLTREE_H
#define TESTAVLTREE_H


#include <iostream>
#include <chrono>
#include <iomanip>
#include "book.h"
#include "avlTree.h"

using namespace std;



void testBookTree(AvlTree& bookTree)
{
  system("clear");
  cout << "Testing AVL Tree data structure" << endl;
  cout << "*********************************************" << endl << endl;
  bookTree.inOrderTraversal();
  cout << endl << endl;


  cout << "AVL Tree Search" << endl;
  cout << "*********************************************" << endl << endl;

  cout << "For an Existing Book" << endl;
  Book* searchItem = new Book("Men in Black: The Grazer Conspiracy", "0-7394-0980-8");


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





  






  cin.ignore(1000, '\n');
  cin.get();
}






#endif
