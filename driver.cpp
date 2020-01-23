#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include "mainMenu.h"
#include "cashierModule.h"
#include "inventoryModule.h"
#include "reportsModule.h"
#include "book.h"
#include "avlTree.h"
#include "testCase.h"
using namespace std;

void readInDataBase(list<Book>& bookList, AvlTree& bookTree);



int main()
{
  list<Book> bookList;
  AvlTree bookTree;

  readInDataBase(bookList, bookTree);
  testBookList(bookList);
  testBookTree(bookTree);


  int selection = 0;

  do
  {
    selection = mainMenu();

    switch(selection)
    {
      case 1:
        cashierMenu();
        break;

      case 2:
        inventoryMenu();
        break;

      case 3:
        reportsMenu();
        break;

      case 4:
        cout << "Exiting Program" << endl;
        break;

      default:
        cout << "Something went wrong" << endl;
    }

  }while(selection != 4);


  return 0;
}



void readInDataBase(list<Book>& bookList, AvlTree& bookTree)
{
  ifstream fin;

  string bookTitle = "Not Set";
  string isbn = "Not Set";
  string author = "Not Set";
  string publisher = "Not Set";
  string dateAdded = "Not Set";
  int quantityOnHand = -1;
  double wholesaleCost = -1;
  double retailPrice = -1;
  int count = 0;

  Book* bookPtr;




  fin.open("database-3.txt");

  if (!fin)
  {
    cout << "<!> File was not able to open <!> " << endl;
    cout << "Please Press Enter to Continue..." << endl;
    cin.ignore(1000, '\n');
    cin.get();
  }

  getline(fin, bookTitle, '\n');
  getline(fin, isbn, '\n');
  getline(fin, author, '\n');
  getline(fin, publisher, '\n');
  getline(fin, dateAdded, '\n');
  fin >> quantityOnHand;
  fin >> wholesaleCost;
  fin >> retailPrice;


  bookPtr = new Book(bookTitle, isbn, author, publisher, dateAdded, quantityOnHand, wholesaleCost, retailPrice);
  bookList.push_back(*bookPtr);
  bookTree.insert(*bookPtr);
  Book::incrementBookCount();
  count++;




  while (!fin.fail())
  {
    fin.ignore(1000, '\n');
    getline(fin, bookTitle, '\n');
    getline(fin, isbn, '\n');
    getline(fin, author, '\n');
    getline(fin, publisher, '\n');
    getline(fin, dateAdded, '\n');
    fin >> quantityOnHand;
    fin >> wholesaleCost;
    fin >> retailPrice;



    if (!fin.fail())
    {
      bookPtr = new Book(bookTitle, isbn, author, publisher, dateAdded, quantityOnHand, wholesaleCost, retailPrice);
      bookList.push_back(*bookPtr);
      bookTree.insert(*bookPtr);
      Book::incrementBookCount();
      count++;
    }
  }

}
