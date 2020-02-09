#include "inventoryModule.h"


using namespace std;

void inventoryMenu(list<Book>& bookList, AvlTree& bookTree)
{
  int selection = 0;
  Book* retreivedBook;



  do
  {
    time_t now = time(0);
    char*dt = ctime(&now);

    system("clear");

    cout << "Serendipity Book Sellers" << endl;
    cout << "Date and Time: " << dt << endl;
    cout << endl << endl;

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
        retreivedBook = searchBook(bookList, bookTree);

        if (retreivedBook != nullptr)
        {

          system("clear");
          cout << "Book Information" << endl;
          cout << "*******************************" << endl;
          cout << endl << endl;
          retreivedBook->print();
          delete retreivedBook;
        }
        else
        {
          cout << "Book Not Found" << endl;
        }
        cin.ignore(1000, '\n');
        cin.get();

        break;

      case 2:
        addBook(bookList, bookTree);
        break;

      case 3:
        editBook(bookList, bookTree);
        break;

      case 4:
        deleteBook(bookList, bookTree);
        break;

      case 5:
        cout << "Returning to Main Menu" << endl;
        break;

      default:
        cout << "Something went wrong" << endl;
    }


  } while (selection != 5);


}



Book* searchBook(list<Book>& bookList, AvlTree& bookTree)
{
  string toSearch = "";

  system("clear");
  cout << "Serendipity Book Sellers" << endl << endl;

  cout << "Search Book" << endl;

  cin.ignore(1000, '\n');

  cout << "Enter Book Title or ISBN(x-xxxx-xxxx-x): ";
  getline(cin, toSearch, '\n');

  Book* tempBook = new Book(toSearch, toSearch);
  Book* retreivedBook;





  // ***************** List data structure **********************
  retreivedBook = sequentialSearch(bookList, *tempBook);

  delete tempBook;

  if (retreivedBook != nullptr)
  {
    return retreivedBook;
  }




  return nullptr;
}



void addBook(list<Book>& bookList, AvlTree& bookTree)
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

  Book* bookPtr;


  time_t now = time(0);
  char*dt = ctime(&now);



  do
  {
    system("clear");
    cout << "Serendipity Book Sellers" << endl;
    cout << "Date and Time: " << dt << endl;
    cout << endl << endl;


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
        bookPtr = new Book(bookTitle, isbn, author, publisher, dateAdded, quantityOnHand, wholesaleCost, retailPrice);
        bookList.push_back(*bookPtr);
        bookTree.insert(*bookPtr);
        Book::incrementBookCount();
        delete bookPtr;
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



void editBook(list<Book>& bookList, AvlTree& bookTree)
{
  time_t now = time(0);
  char*dt = ctime(&now);


  Book* editBook;


  system("clear");
  cout << "Serendipity Book Sellers" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << endl << endl;

  cout << "Edit Book" << endl;

  editBook = searchBook(bookList, bookTree);

  if (editBook != nullptr)
  {
    editBookMenu(bookList, editBook);

  }
  else
  {
    cout << "Book Not Found" << endl;
    delete editBook;
  }

}



void editBookMenu(list<Book>& bookList, Book* editBook)
{
  int selection = 0;
  string bookTitle = editBook->getBookTitle();
  string isbn = editBook->getIsbn();
  string author = editBook->getAuthor();
  string publisher = editBook->getPublisher();
  string dateAdded = editBook->getDateAdded();
  int quantityOnHand = editBook->getQuantityOnHand();
  double wholesaleCost = editBook->getWholesaleCost();
  double retailPrice = editBook->getRetailPrice();
  bool bookSaved = false;

  Book* replaceBook = nullptr;

  time_t now = time(0);
  char*dt = ctime(&now);

  do
  {
    system("clear");
    cout << "Serendipity Book Sellers" << endl;
    cout << "Date and Time: " << dt << endl;
    cout << endl << endl;


    cout << "Edit Book" << endl << endl;

    cout << " 1. Edit Book Title: " << bookTitle << endl;
    cout << " 2. Edit ISBN: " << isbn << endl;
    cout << " 3. Edit Author: " << author << endl;
    cout << " 4. Edit Publisher: " << publisher << endl;
    cout << " 5. Edit Date Added (mm/dd/yyyy): " << dateAdded << endl;
    cout << " 6. Edit Quantity on Hand: " << quantityOnHand << endl;
    cout << " 7. Edit Wholesale Cost: " << wholesaleCost << endl;
    cout << " 8. Edit Retail Price: " << retailPrice << endl;
    cout << " 9. Save Changes" << endl;
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
        cout << "Enter Quantity on Hand: ";
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
        bookSaved = true;
        cout << "Saving Changes" << endl;
        editBook->setBookTitle(bookTitle);
        editBook->setIsbn(isbn);
        editBook->setAuthor(author);
        editBook->setPublisher(publisher);
        editBook->setDateAdded(dateAdded);
        editBook->setQuantityOnHand(quantityOnHand);
        editBook->setWholesaleCost(wholesaleCost);
        editBook->setRetailPrice(retailPrice);

        replaceBook = new Book(*editBook);

        bookList.remove(*editBook);
        bookList.push_back(*replaceBook);
        delete editBook;
        delete replaceBook;

        cout << "Please Press Enter To Continue..." << endl;
        cin.ignore(1000, '\n');
        cin.get();
        return;
        break;

      case 0:
        cout << "Returning to Inventory Menu" << endl;
        cout << "Please Press Enter To Continue..." << endl;
        break;

      default:
        cout << "Something went wrong" << endl;
    }

  } while (selection != 0);


}


void deleteBook(list<Book>& bookList, AvlTree& bookTree)
{
  time_t now = time(0);
  char*dt = ctime(&now);

  char toDelete;



  system("clear");
  cout << "Serendipity Book Sellers" << endl;
  cout << "Date and Time: " << dt << endl;
  cout << endl << endl;

  cout << "Delete Book" << endl;

  Book* deleteBook = searchBook(bookList, bookTree);

  if (deleteBook != nullptr)
  {
    deleteBook->print();
    cout << endl << endl;


    do
    {
      cout << "Are You Sure You Want To Delete This Book? (Y/N): ";
      cin >> toDelete;
    } while (toDelete != 'y' && toDelete != 'Y' && toDelete != 'n' && toDelete != 'N');


    if (toDelete == 'y' || toDelete == 'Y')
    {
      bookList.remove(*deleteBook);
      delete deleteBook;
    }

  }
  else
  {
    cout << "Book Not Found" << endl;
    delete deleteBook;
  }


  cin.ignore(1000, '\n');
  cin.get();
}
