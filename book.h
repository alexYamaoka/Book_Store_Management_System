#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <string>
using namespace std;

const int DB_SIZE = 125;

class Book
{
private:
  static int bookCount;
  string bookTitle;
  string isbn;
  string author;
  string publisher;
  string dateAdded;
  int quantityOnHand;
  double wholesaleCost;
  double retailPrice;



  friend ostream& operator << (ostream& osObject, const Book& book);

public:
  static void incrementBookCount();
  static void decrementBookCount();
  static int getBookCount();

  Book();
  Book(string bookTitle, string isbn);
  Book(string bookTitle, string isbn, string author, string publisher, string dateAdded, int quantityOnHand, double wholesaleCost, double retailCost);
  Book(const Book& otherBook);

  void setBookTitle(string bookTitle);
  void setIsbn(string isbn);
  void setAuthor(string author);
  void setPublisher(string publisher);
  void setDateAdded(string dateAdded);
  void setQuantityOnHand(int quantityOnHand);
  void setWholesaleCost(double wholesaleCost);
  void setRetailPrice(double retailPrice);

  string getBookTitle();
  string getIsbn();
  string getAuthor();
  string getPublisher();
  string getDateAdded();
  int getQuantityOnHand();
  double getWholesaleCost();
  double getRetailPrice();

  void print();
  bool equals(const Book& other) const;

  bool operator == (const Book& otherBook) const;
  bool operator != (const Book& otherBook) const;
  bool operator >= (const Book& otherBook) const;
  bool operator > (const Book& otherBook) const;
  bool operator < (const Book& otherBook) const;


};



#endif
