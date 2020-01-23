#include "book.h"
using namespace std;

// static variable
int Book::bookCount = 0;

void Book::incrementBookCount()
{
  bookCount++;
}

void Book::decrementBookCount()
{
  bookCount--;
}

int Book::getBookCount()
{
  return bookCount;
}



Book::Book(string bookTitle, string isbn, string author, string publisher, string dateAdded, int quantityOnHand, double wholesaleCost, double retailPrice)
{
  setBookTitle(bookTitle);
  setIsbn(isbn);
  setAuthor(author);
  setPublisher(publisher);
  setDateAdded(dateAdded);
  setQuantityOnHand(quantityOnHand);
  setWholesaleCost(wholesaleCost);
  setRetailPrice(retailPrice);
  incrementBookCount();
}


Book::Book()
    :Book("Not Set", "Not Set", "Not Set", "Not Set", "Not Set", 0, 0, 0)
{
  // create empty book
}


Book::Book(const Book& otherBook)
{
  bookTitle = otherBook.bookTitle;
  isbn = otherBook.isbn;
  author = otherBook.author;
  publisher = otherBook.publisher;
  dateAdded = otherBook.dateAdded;
  quantityOnHand = otherBook.quantityOnHand;
  wholesaleCost = otherBook.wholesaleCost;
  retailPrice= otherBook.retailPrice;
}






void Book::setBookTitle(string bookTitle)
{
  this->bookTitle = bookTitle;
}

void Book::setIsbn(string isbn)
{
  this->isbn = isbn;
}

void Book::setAuthor(string author)
{
  this->author = author;
}

void Book::setPublisher(string publisher)
{
  this->publisher = publisher;
}

void Book::setDateAdded(string dateAdded)
{
  this->dateAdded = dateAdded;
}

void Book::setQuantityOnHand(int quantityOnHand)
{
  this->quantityOnHand = quantityOnHand;
}

void Book::setWholesaleCost(double wholesaleCost)
{
  this->wholesaleCost = wholesaleCost;
}

void Book::setRetailPrice(double retailPrice)
{
  this->retailPrice = retailPrice;
}




string Book::getBookTitle()
{
  return bookTitle;
}

string Book::getIsbn()
{
  return isbn;
}

string Book::getAuthor()
{
  return author;
}

string Book::getPublisher()
{
  return publisher;
}

string Book::getDateAdded()
{
  return dateAdded;
}

int Book::getQuantityOnHand()
{
  return quantityOnHand;
}

double Book::getWholesaleCost()
{
  return wholesaleCost;
}

double Book::getRetailPrice()
{
  return retailPrice;
}


void Book::print()
{
  cout << "Book Title: " << bookTitle << endl;
  cout << "ISBN: " << isbn << endl;
  cout << "Author: " << author << endl;
  cout << "Publisher: " << publisher << endl;
  cout << "Date Added: " << dateAdded << endl;
  cout << "Quantity On Hand: " << quantityOnHand << endl;
  cout << "wholesale Cost: $ " << wholesaleCost << endl;
  cout << "Retail Price: $ " << retailPrice << endl;
}


ostream& operator << (ostream& osObject, const Book& book)
{
  
  return osObject;
}

bool Book::operator == (const Book& otherBook) const
{

  return true;
}

bool Book::operator != (const Book& otherBook) const
{
  return true;
}

bool Book::operator >= (const Book& otherBook) const
{
  return true;
}

bool Book::operator > (const Book& otherBook) const
{
  return true;
}


bool Book::operator < (const Book& otherBook) const
{
  return true;
}
