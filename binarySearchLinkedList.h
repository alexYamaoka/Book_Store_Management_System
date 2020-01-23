#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include <iostream>
<<<<<<< HEAD
#include "Book.h"
=======
#include "Book"
>>>>>>> feeb66f0e30c4be9e099c14fdaacea2dfb639561
using namespace std;


struct Node
{
  Book data;
  Node* next;
}


Node* getMiddleNode(Node* start, Node* last)
{
  if (start == null)
  {
    return null;
  }


  Node* slow = start;
  Node* fast = start->next;

  while (fast != last)
  {
    fast = fast->next;

    if (fast != last)
    {
      slow = slow->next;
      fast = fast->next;
    }
  }

  return slow;
}



Node* binarySearch(Node* head, const Book& searchItem)
{
  Node* start = head;
  Node* last = nullptr;

  do
  {
    Node* mid = getMiddleNode(start, last);

    if (mid == nullptr)
    {
      return nullptr;
    }

    if (mid->data == searchItem)
    {
      return mid;
    }
    else if (mid->data < searhItem)
    {
      start = mid->next;
    }
    else
    {
      last = mid;
    }

  } while(last == nullptr || last != start);

  return nullptr;
}



#endif
