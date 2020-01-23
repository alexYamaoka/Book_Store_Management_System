#include "sequentialSearchList.h"

Book sequentialSearch(list<Book>& bookList, const Book& searchItem) throw(string)
{
  list<Book>::iterator it;


  for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    if (*it == searchItem)
    {
      cout << "Item Found" << endl;
      cout << (*it).getBookTitle() << endl;
      return *it;
    }

  }

  string ex = "Item Not Found";
  throw (ex);

}
