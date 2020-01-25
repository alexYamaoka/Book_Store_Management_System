#include "sequentialSearchList.h"
using namespace std;

Book* sequentialSearch(list<Book>& bookList, const Book& searchItem)
{
  list<Book>::iterator it;
  bool isFound = false;
  char selection;


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
      cout << endl << endl;
      cout << "<Book Found>" << endl << endl;
      cout << left;
      cout << setw(15) << "Title: " << it->getBookTitle() << endl;
      cout << setw(15) << "ISBN: " << it->getIsbn() << endl;
      cout << setw(15) << "Author: " << it->getAuthor() << endl;
      cout << setw(15) << "Publisher: " << it->getPublisher() << endl;
      cout << setw(15) << "retailPrice: " << it->getRetailPrice() << endl;
      cout << setw(15) << "Qty: " << it->getQuantityOnHand() << endl;
      cout << right << endl;

      do
      {
        cout << "Is This The Book You Were Looking For? (Y/N): ";
        cin >> selection;

        if (selection == 'y' || selection == 'Y')
        {
          isFound = true;
        }

      } while (selection != 'y' && selection != 'Y' && selection != 'n' && selection != 'N');



      if (isFound)
      {
        Book* tempBook = new Book(*it);
        return tempBook;
      }


    }

  }



  return nullptr;
}
