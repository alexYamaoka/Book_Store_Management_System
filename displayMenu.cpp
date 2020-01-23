#include <iostream>
#include "cashierModule.h"

using namespace std;

void mainMenu()
{
  int selection = 0;


  do
  {
    system("clear");

    cout << "Serendipity Book Store" << endl;
    cout << endl << endl;
    cout << "Main Menu" << endl;
    cout << "1. Cashier Module" << endl;
    cout << "2. Inventory Module" << endl;
    cout << "3. Reports Module" << endl;
    cout << "4. Exit" << endl;
    cout << endl;

    cout << "Enter Selection: ";
    cin >> selection;

    while (selection < 1 || selection > 4)
    {
      cout << "Please enter selection 1 - 4: ";
      cin >> selection;
    }

    switch(selection)
    {
      case 1:
        cashierMenu();
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
}
