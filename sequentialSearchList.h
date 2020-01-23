#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include "book.h"

using namespace std;

void sequentialSearch(list<Book>& bookList, const Book& searchItem) throw(string)
{
  list<Book>::iterator it;


  for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    if (*it == searchItem)
    {
      cout << "Item Found" << endl;
      cout << (*it).getBookTitle() << endl;
      return;
    }

  }

  string ex = "Item Not Found";
  throw (ex);

}



#endif
