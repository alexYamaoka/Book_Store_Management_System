#include "reportsModule.h"
using namespace std;


void reportsMenu(list<Book>& bookList, AvlTree& bookTree)
{
  int selection = 0;

  do
  {
    time_t now = time(0);
    char*dt = ctime(&now);


    system("clear");

    cout << "Serendipity Booksellers" << endl;
    cout << "Date and Time: " << dt << endl;
    cout << endl <<endl;

    cout << "           Reports Menu              " << endl;
    cout << "*************************************" << endl;
    cout << "* 1. Inventory Listing              *" << endl;
    cout << "* 2. Inventory Wholesale Value      *" << endl;
    cout << "* 3. Inventory Retail Value         *" << endl;
    cout << "* 4. Listing By Quantity            *" << endl;
    cout << "* 5. Listing By Wholesale Cost      *" << endl;
    cout << "* 6. Listing By Date                *" << endl;
    cout << "* 7. Return To Main Menu            *" << endl;
    cout << "*************************************" << endl;
    cout << endl;








    cout << "Enter selection: ";
    cin >> selection;


    while (selection < 0 || selection > 7 || cin.fail())
    {
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Please enter seleciton (1 - 4): ";
      cin >> selection;
    }

    switch (selection)
    {
      case 1:
        bookList.sort(compareByTitle);
        viewAllListing(bookList, bookTree);
        break;

      case 2:
        bookList.sort(compareByTitle);
        reportWholesale(bookList, bookTree);
        break;

      case 3:
        bookList.sort(compareByTitle);
        reportRetail(bookList, bookTree);
        break;

      case 4:
        bookList.sort(compareByQuantity);
        viewByQuantity(bookList, bookTree);
        break;

      case 5:
        bookList.sort(compareByWholesale);
        viewByWholesale(bookList, bookTree);
        break;

      case 6:
        bookList.sort(compareByDateAdded);
        viewByDateAdded(bookList, bookTree);
        break;

      case 7:
        cout << "Returning to Main Menu" << endl;
        break;

      default:
        cout << "Something went wrong" << endl;
    }
  } while (selection != 7);



  cout << "Press Enter To Continue..." << endl;
  cin.get();

}


void viewAllListing(list<Book>& bookList, AvlTree& bookTree)
{
  list<Book>::iterator it;
  int pageNumber = 0;
  int counter = 0;

  time_t now = time(0);
  char*dt = ctime(&now);



  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "Inventory Listing" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DB_SIZE << endl;
  cout << "Book Count: " << Book::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;
  cout << left;
  cout << setw(40) << "Title";
  cout << setw(18) << "ISBN";
  cout << setw(25) << "Author";
  cout << setw(25) << "Publisher";
  cout << setw(15) << "Date Added";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(20) << "Wholesale Cost($)";
  cout << setw(20) << "Retail Price($)";
  cout << endl;
  cout << right;
  cout << setw(178) << setfill('-') << "-" << endl;
  cout << setfill(' ');
  cin.ignore(1000, '\n');


  for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    if (0 == counter%20)
    {

      system("clear");
      pageNumber++;
      cout << "Serndipity Book Sellers" << endl;
      cout << "Inventory Listing" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DB_SIZE << endl;
      cout << "Book Count: " << Book::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;
      cout << left;
      cout << setw(40) << "Title";
      cout << setw(18) << "ISBN";
      cout << setw(25) << "Author";
      cout << setw(25) << "Publisher";
      cout << setw(15) << "Date Added";
      cout << right;
      cout << setw(15) << "Qty on Hand";
      cout << setw(20) << "Wholesale Cost($)";
      cout << setw(20) << "Retail Price($)";
      cout << endl;
      cout << right;
      cout << setw(178) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }
    cout << left << setprecision(2) << showpoint << fixed;
    cout << setw(40) << (*it).getBookTitle().substr(0, 35);
    cout << setw(18) << (*it).getIsbn();
    cout << setw(25) << (*it).getAuthor().substr(0, 20);
    cout << setw(25) << (*it).getPublisher().substr(0, 20);
    cout << setw(15) << (*it).getDateAdded();
    cout << right;
    cout << setw(15) << (*it).getQuantityOnHand();
    cout << setw(20) << (*it).getWholesaleCost();
    cout << setw(20) << (*it).getRetailPrice();
    cout << endl;


    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue..." << endl;
      cin.get();
    }
    counter++;
  }







cout << "Press Enter To Continue..." << endl;
cin.get();
}



void reportWholesale(list<Book>& bookList, AvlTree& bookTree)
{
  list<Book>::iterator it;
  int pageNumber = 0;
  int counter = 0;
  double totalWholeSaleValue = 0;

  time_t now = time(0);
  char*dt = ctime(&now);


  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "Wholesale Report" << endl << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DB_SIZE << endl;
  cout << "Book Count: " << Book::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;
  cout << left;
  cout << setw(40) << "Title";
  cout << setw(15) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(25) << "Wholesale Cost($)";
  cout << endl;
  cout << right;
  cout << setw(95) << setfill('-') << "-" << endl;
  cout << setfill(' ');
  cin.ignore(1000, '\n');

  for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    if (0 == counter%20)
    {
      system("clear");
      pageNumber++;
      cout << "Serendipity Booksellers" << endl;
      cout << "Inventory Wholesale Value" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DB_SIZE << endl;
      cout << "Book Count: " << Book::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;
      cout << left;
      cout << setw(40) << "Title";
      cout << setw(15) << "ISBN";
      cout << right;
      cout << setw(15) << "Qty on Hand";
      cout << setw(25) << "Wholesale Cost($)";
      cout << endl;
      cout << setw(95) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }
    cout << left;
    cout << setw(40) << (*it).getBookTitle().substr(0, 35);
    cout << setw(15) << (*it).getIsbn();
    cout << right;
    cout << setw(15) << (*it).getQuantityOnHand();
    cout << setw(25) << (*it).getWholesaleCost();
    cout << endl;

    totalWholeSaleValue = totalWholeSaleValue + ((*it).getQuantityOnHand() * (*it).getWholesaleCost());

    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue.." << endl;
      cin.get();
    }
    counter++;
  }
  cout << endl << endl;
  cout << fixed << showpoint << setprecision(2);
  cout << "Total Wholesale Value: $ " << totalWholeSaleValue << endl << endl;



  cout << "Press Enter To Continue..." << endl;
  cin.get();
}




void reportRetail(list<Book>& bookList, AvlTree& bookTree)
{
  list<Book>::iterator it;
  int pageNumber = 0;
  int counter = 0;
  double totalRetailValue = 0;

  time_t now = time(0);
  char*dt = ctime(&now);




  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "Retail Report" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DB_SIZE << endl;
  cout << "Book Count: " << Book::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;
  cout << left;
  cout << setw(40) << "Title";
  cout << setw(15) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(25) << "Retail Price($)";
  cout << endl;
  cout << right;
  cout << setw(95) << setfill('-') << "-" << endl;
  cout << setfill(' ');
  cin.ignore(1000, '\n');


  for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    if (0 == counter%20)
    {
      system("clear");
      pageNumber++;
      cout << "Serndipity Book Sellers" << endl;
      cout << "Inventory Retail Value" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DB_SIZE << endl;
      cout << "Book Count: " << Book::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;
      cout << left;
      cout << setw(40) << "Title";
      cout << setw(15) << "ISBN";
      cout << right;
      cout << setw(15) << "Qty on Hand";
      cout << setw(25) << "Retail Price($)";
      cout << endl;
      cout << right;
      cout << setw(95) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }

    cout << left;
    cout << setw(40) << (*it).getBookTitle().substr(0, 35);
    cout << setw(15) << (*it).getIsbn();
    cout << right;
    cout << setw(15) << (*it).getQuantityOnHand();
    cout << setw(25) << (*it).getRetailPrice();
    cout << endl;

    totalRetailValue = totalRetailValue + ((*it).getQuantityOnHand() * (*it).getRetailPrice());
    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue.." << endl;
      cin.get();
    }
    counter++;
  }

  cout << endl << endl;
  cout << "Total Retail Value: $" << totalRetailValue << endl << endl;


  cout << "Press Enter To Continue..." << endl;
  cin.get();
}




void viewByQuantity(list<Book>& bookList, AvlTree& bookTree)
{
  list<Book>::iterator it;
  int pageNumber = 0;
  int counter = 0;

  time_t now = time(0);
  char*dt = ctime(&now);




  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "View By Quantity" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DB_SIZE << endl;
  cout << "Book Count: " << Book::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;
  cout << left;
  cout << setw(70) << "Title";
  cout << setw(20) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << endl;
  cout << setw(105) << setfill('-') << "-" << endl;
  cout << setfill(' ');
  cin.ignore(1000, '\n');

  for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    if (0 == counter%20)
    {
      system("clear");
      pageNumber++;
      cout << "Serndipity Book Sellers" << endl;
      cout << "Listing By Quantity" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DB_SIZE << endl;
      cout << "Book Count: " << Book::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;
      cout << left;
      cout << setw(70) << "Title";
      cout << setw(20) << "ISBN";
      cout << right;
      cout << setw(15) << "Qty on Hand";
      cout << endl;
      cout << setw(105) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }

    cout << left;
    cout << setw(70) << (*it).getBookTitle().substr(0, 60);
    cout << setw(20) << (*it).getIsbn();
    cout << right;
    cout << setw(15) << (*it).getQuantityOnHand() << endl;


    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue.." << endl;
      cin.get();
    }
    counter++;
  }


  cout << "Press Enter To Continue..." << endl;
  cin.get();
}



void viewByWholesale(list<Book>& bookList, AvlTree& bookTree)
{
  list<Book>::iterator it;
  int pageNumber = 0;
  int counter = 0;

  time_t now = time(0);
  char*dt = ctime(&now);



  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "View By Wholesale Cost" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DB_SIZE << endl;
  cout << "Book Count: " << Book::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;
  cout << left;
  cout << setw(70) << "Title";
  cout << setw(20) << "ISBN";
  cout << right;
  cout << setw(15) << "Wholesale Cost";
  cout << endl;
  cout << setw(105) << setfill('-') << "-" << endl;
  cout << setfill(' ');
  cin.ignore(1000, '\n');


  for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    if (0 == counter%20)
    {
      system("clear");
      pageNumber++;
      cout << "Serendipity Booksellers" << endl;
      cout << "Listing By Cost" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DB_SIZE << endl;
      cout << "Book Count: " << Book::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;
      cout << left;
      cout << setw(70) << "Title";
      cout << setw(20) << "ISBN";
      cout << right;
      cout << setw(15) << "Wholesale Cost";
      cout << endl;
      cout << setw(105) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }

    cout << left;
    cout << setw(70) << (*it).getBookTitle().substr(0, 60);
    cout << setw(20) << (*it).getIsbn();
    cout << right << fixed << showpoint << setprecision(2);
    cout << setw(15) << (*it).getWholesaleCost() << endl;


    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue.." << endl;
      cin.get();
    }
    counter++;
  }

  cout << "Press Enter To Continue..." << endl;
  cin.get();
}

void viewByDateAdded(list<Book>& bookList, AvlTree& bookTree)
{
  list<Book>::iterator it;
  int pageNumber = 0;
  int counter = 0;

  time_t now = time(0);
  char*dt = ctime(&now);



  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "View By Date Added" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << "Database Size: " << DB_SIZE << endl;
  cout << "Book Count: " << Book::getBookCount() << endl;
  cout << "Page " << pageNumber << endl;
  cout << endl << endl;
  cout << left;
  cout << setw(70) << "Title";
  cout << setw(20) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(15) << "Date Added";
  cout << endl;
  cout << setw(120) << setfill('-') << "-" << endl;
  cout << setfill(' ');
  cin.ignore(1000, '\n');

  for (it = bookList.begin(); it != bookList.end(); ++it)
  {
    if (0 == counter%20)
    {
      system("clear");
      pageNumber++;
      cout << "Serendipity Booksellers" << endl;
      cout << "Listing By Date Added" << endl;
      cout << "Date and Time: " << dt << endl;
      cout << "Database Size: " << DB_SIZE << endl;
      cout << "Book Count: " << Book::getBookCount() << endl;
      cout << "Page " << pageNumber << endl;
      cout << endl << endl;
      cout << left;
      cout << setw(70) << "Title";
      cout << setw(20) << "ISBN";
      cout << right;
      cout << setw(15) << "Qty on Hand";
      cout << setw(15) << "Date Added";
      cout << endl;
      cout << setw(120) << setfill('-') << "-" << endl;
      cout << setfill(' ');
    }


    cout << left;
    cout << setw(70) << (*it).getBookTitle().substr(0, 60);
    cout << setw(20) << (*it).getIsbn();
    cout << right;
    cout << setw(15) << (*it).getQuantityOnHand();
    cout << setw(15) << (*it).getDateAdded() << endl;


    if (19 == counter%20)
    {
      cout << endl;
      cout << "Press Enter To Continue.." << endl;
      cin.get();
    }
    counter++;
  }





  cout << "Press Enter To Continue..." << endl;
  cin.get();
}
