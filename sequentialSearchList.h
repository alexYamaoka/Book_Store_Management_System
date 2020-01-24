#ifndef SEQUENTIALSEARCHLIST_H
#define SEQUENTIALSEARCHLIST_H

#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>


#include "book.h"

using namespace std;

Book* sequentialSearch(list<Book>& bookList, const Book& searchItem) throw(string);




#endif
