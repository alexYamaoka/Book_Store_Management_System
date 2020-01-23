#include "inventoryModule.h"


using namespace std;

void inventoryMenu(list<Book>& bookList, AvlTree& bookTree)
{
  int selection = 0;

  do
  {
    system("clear");

    cout << "Serendipity Book Sellers" << endl << endl;

    cout << "*            Inventory Menu          *" << endl;
    cout << "**************************************" << endl;
    cout << "* 1. Search Book                     *" << endl;
    cout << "* 2. Add a Book                      *" << endl;
    cout << "* 3. Edit a Book's Record            *" << endl;
    cout << "* 4. Delete a Book's Record          *" << endl;
    cout << "* 5. Return to Main Menu             *" << endl;
    cout << "**************************************" << endl;
    cout << endl;


    cout << "Enter selection: ";
    cin >> selection;


    while (selection < 0 || selection > 5 || cin.fail())
    {
      cin.clear();
      cin.ignore(1000, '\n');

      cout << "Please enter seleciton (1 - 4): ";
      cin >> selection;
    }

    switch (selection)
    {
      case 1:
        searchBook(bookList, bookTree);
        break;

      case 2:
        addBook();
        break;

      case 3:
        editBook();
        break;

      case 4:
        deleteBook();
        break;

      case 5:
        cout << "Returning to Main Menu" << endl;
        break;

      default:
        cout << "Something went wrong" << endl;
    }



  } while (selection != 5);
}






void searchBook(list<Book>& bookList, AvlTree& bookTree)
{
  string toSearch = "";

  system("clear");
  cout << "Serendipity Book Sellers" << endl << endl;

  cout << "Search Book" << endl;

  cout << "Enter Book Title or ISBN(x-xxxx-xxxx-x): ";
  getline(cin, toSearch, '\n');

  Book* tempBook = new Book(toSearch, toSearch);


  // ***************** List data structure **********************
  try
  {
    sequentialSearch(bookList, *tempBook);
  }
  catch(string ex)
  {
    cout << ex << endl;
  }



  // ***************** AVL Tree data structure **********************
  try
  {
    bookTree.search(*tempBook);
  }
  catch(string ex)
  {
    cout << ex << endl;
  }







  cin.ignore(1000, '\n');
  cin.get();
}


void addBook()
{
  int selection = 0;

  char saveBook = 'n';
  string bookTitle = "Not Set";
  string isbn = "Not Set";
  string author = "Not Set";
  string publisher = "Not Set";
  string dateAdded = "Not Set";
  int quantityOnHand = -1;
  double wholesaleCost = -1;
  double retailPrice = -1;

  do
  {
    system("clear");
    cout << "Serendipity Book Sellers" << endl << endl;

    cout << "Add Book" << endl << endl;

    cout << " 1. Enter Book Title: " << bookTitle << endl;
    cout << " 2. Enter ISBN: " << isbn << endl;
    cout << " 3. Enter Author: " << author << endl;
    cout << " 4. Enter Publisher: " << publisher << endl;
    cout << " 5. Enter Date Added (mm/dd/yyyy): " << dateAdded << endl;
    cout << " 6. Enter Quantity on Hand: " << quantityOnHand << endl;
    cout << " 7. Enter Wholesale Cost: " << wholesaleCost << endl;
    cout << " 8. Enter Retail Price: " << retailPrice << endl;
    cout << " 9. Save Book To Data Base" << endl;
    cout << " 0. Return to Inventory Menu" << endl;
    cout << endl;


    cout << "Enter Selection: ";
    cin >> selection;

    while (selection < 0 || selection > 9 || cin.fail())
    {
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Please Enter Selection (0 - 9): ";
      cin >> selection;
    }
    cout << endl << endl;


    switch (selection)
    {
      case 1:
        cin.ignore(1000, '\n');
        cout << "Enter Book Title: ";
        getline(cin, bookTitle, '\n');
        break;

      case 2:
        cin.ignore(1000, '\n');
        cout << "Enter ISBN: ";
        getline(cin, isbn, '\n');
        break;

      case 3:
        cin.ignore(1000, '\n');
        cout << "Enter Author: ";
        getline(cin, author, '\n');
        break;

      case 4:
        cin.ignore(1000, '\n');
        cout << "Enter Publisher: ";
        getline(cin, publisher, '\n');
        break;

      case 5:
        cin.ignore(1000, '\n');
        cout << "Enter Date Added (mm/dd/yyy): ";
        getline(cin, dateAdded, '\n');
        break;

      case 6:
        cout << "Enter Quality on Hand: ";
        cin >> quantityOnHand;
        break;

      case 7:
        cout << "Enter Wholesale Cost: $ ";
        cin >> wholesaleCost;
        break;

      case 8:
        cout << "Enter Retail Price: $ ";
        cin >> retailPrice;
        break;

      case 9:
        cout << "Saving Book To Data Base" << endl;
        break;

      case 0:
        cout << "Returning to Inventory Menu" << endl;
        cout << "Please Press Enter To Continue..." << endl;
        break;

      default:
        cout << "Something went wrong" << endl;
    }










  } while (selection != 0);





  cin.ignore(1000, '\n');
  cin.get();
}


void editBook()
{
  system("clear");
  cout << "Serendipity Book Sellers" << endl << endl;

  cout << "Edit Book" << endl;


  cin.ignore(1000, '\n');
  cin.get();
}


void deleteBook()
{
  system("clear");
  cout << "Serendipity Book Sellers" << endl << endl;

  cout << "Delete Book" << endl;


  cin.ignore(1000, '\n');
  cin.get();
}
