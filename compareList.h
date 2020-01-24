#ifndef COMPARELIST_H
#define COMPARELIST_H

#include "book.h"
#include <list>

bool compareByTitle(const Book&, const Book& second);
bool compareByQuantity(const Book& first, const Book& second);
bool compareByWholesale(const Book& first, const Book& second);
bool compareByDateAdded(const Book& first, const Book& second);



#endif
