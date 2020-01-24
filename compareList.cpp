#include "compareList.h"
using namespace std;

bool compareByTitle(const Book& first, const Book& second)
{
  return (first.getBookTitle() < second.getBookTitle());
}


bool compareByQuantity(const Book& first, const Book& second)
{
  return (first.getQuantityOnHand() > second.getQuantityOnHand());
  // sort in descentding order - high to low
}


bool compareByWholesale(const Book& first, const Book& second)
{
  return (first.getWholesaleCost() > second.getWholesaleCost());
  // sort in descending order - high to low
}




bool compareByDateAdded(const Book& first, const Book& second)
{
  // sort from newest to oldest


  string date1 = first.getDateAdded().substr(6, 4);    //retrieve substring year of the date
  string date2 = second.getDateAdded().substr(6,4);

  int date1AsInt = atoi(date1.c_str());             // atoi converts cstring to integer.ascii to int
  int date2AsInt = atoi(date2.c_str());



  // checks by year

  if (date1AsInt > date2AsInt)
  {
    return true;
  }
  else
  {
    if (date1AsInt == date2AsInt)
    {
      // checks by month

      date1 = first.getDateAdded().substr(0, 2);
      date2 = second.getDateAdded().substr(0, 2);

      date1AsInt = atoi(date1.c_str());
      date2AsInt = atoi(date2.c_str());



      if (date1AsInt > date2AsInt)
      {
        return true;
      }
      else
      {
        if (date1AsInt == date2AsInt)
        {
          // checks by day

          date1 = first.getDateAdded().substr(3, 2);
          date2 = second.getDateAdded().substr(3, 2);

          date1AsInt = atoi(date1.c_str());
          date2AsInt = atoi(date2.c_str());

          if (date1AsInt > date2AsInt)
          {
            return true;
          }
        }
      }
    }
  }
  return false;
}
