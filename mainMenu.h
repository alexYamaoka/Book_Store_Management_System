#include <iostream>
using namespace std;

int mainMenu()
{
  int selection = 0;

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
    cout << "Please enter selection (1 - 4): ";
    cin >> selection;
  }

  return selection;
}
