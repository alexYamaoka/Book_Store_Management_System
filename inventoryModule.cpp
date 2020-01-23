#include "inventoryModule.h"
using namespace std;

void inventoryMenu()
{
  int selection = 0;

  do
  {
    cout << "Serendipity Book Sellers" << endl;
    cout << "Reports Menu" << endl;








    cout << "Enter selection: ";
    cin >> selection;


    while (selection < 0 || selection > 4)
    {
      cout << "Please enter seleciton (1 - 4): ";
      cin >> selection;
    }

    switch (selection)
    {
      case 1:
        break;

      case 2:
        break;

      case 3:
        break;

      case 4:
        break;

      default:
        cout << "Something went wrong" << endl;
    }



  } while (selection != 4);



  cin.ignore(1000, '\n');
  cin.get();


}

void searchBook();

void addBook();

void editBook();

void deleteBook();
