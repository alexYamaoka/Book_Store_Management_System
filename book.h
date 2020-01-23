#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <string>
using namespace std;

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
  double retailCost;

  static void incrementBookCount();
  static void decrementBookCount();

  friend ostream& operator << (ostream& osObject, const Book& book);

public:
  static int getBookCount();

  Book();
  Book(string bookTitle, string isbn, string author, string publisher, string dateAdded, int quantityOnHand, double wholesaleCost, double retailCost);
  Book(const Book& otherBook);

  void setBookTitle(string bookTitle);
  void setIsbn(string isbn);
  void setAuthor(string author);
  void setPublisher(string publisher);
  void setDateAdded(string dateAdded);
  void setQuantityOnHand(int quantityOnHand);
  void setWholesaleCost(double wholesaleCost);
  void setRetailCost(double retailCost);

  string getBookTitle();
  string getIsbn();
  string getAuthor();
  string getPublisher();
  string getDateAdded();
  int getQuantityOnHand();
  double getWholesaleCost();
  double getRetailCost();

  void print();
  bool equals(const Book& other) const;

  bool operator == (const Book& otherBook) const;
  bool operator != (const Book& otherBook) const;
  bool operator >= (const Book& otherBook) const;


};



#endif
