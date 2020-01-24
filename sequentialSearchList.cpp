#include "sequentialSearchList.h"
using namespace std;

Book* sequentialSearch(list<Book>& bookList, const Book& searchItem) throw(string)
{
  list<Book>::iterator it;



  string searchTitle = searchItem.getBookTitle();
  string searchIsbn = searchItem.getIsbn();


	// convert searchTitle to upper case
	for_each(searchTitle.begin(), searchTitle.end(), [](char & c) {
		c = ::toupper(c);
	});


  // convert searchIsbn to upper case
	for_each(searchIsbn.begin(), searchIsbn.end(), [](char & c) {
		c = ::toupper(c);
	});







  for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    string tempTitle = it->getBookTitle();
    string tempIsbn = it->getIsbn();




    // convert tempTitle to upper case
  	for_each(tempTitle.begin(), tempTitle.end(), [](char & c)
    {
  		c = ::toupper(c);
  	});

    // convert tempIsbn to upper case
  	for_each(tempIsbn.begin(), tempIsbn.end(), [](char & c)
    {
  		c = ::toupper(c);
  	});



    if ((tempTitle.find(searchTitle) != string::npos) ||  (tempIsbn.find(searchIsbn) != string::npos))
    {
      cout << "Item Found" << endl;
      cout << it->getBookTitle() << endl;

      Book* tempBook = new Book(*it);
      return tempBook;
    }

  }

  //string ex = "Item Not Found";
  //throw (ex);

  return nullptr;
}
