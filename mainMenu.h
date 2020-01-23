#include <iostream>
using namespace std;

int mainMenu()
{
  int selection = 0;

  system("clear");

  cout << "Serendipity Book Sellers" << endl;
  cout << endl << endl;
  cout << "Main Menu" << endl;
  cout << "1. Cashier Module" << endl;
  cout << "2. Inventory Module" << endl;
  cout << "3. Reports Module" << endl;
  cout << "4. Exit" << endl;
  cout << endl;

  cout << "Enter Selection: ";
  cin >> selection;

  while (selection < 1 || selection > 4 || cin.fail())
  {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Please enter selection (1 - 4): ";
    cin >> selection;
  }

  return selection;
}
