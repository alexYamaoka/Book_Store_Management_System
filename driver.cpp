#include <iostream>
#include "displayMenu.h"
#include "cashierModule.h"
#include "inventoryModule.h"
using namespace std;

int main()
{
  int selection = 0;



  do
  {
    selection = mainMenu();

    switch(selection)
    {
      case 1:
        cashierMenu();
        break;

      case 2:
        inventoryMenu();
        break;

      case 3:
        break;

      case 4:
        break;

      default:
        cout << "Something went wrong" << endl;
    }

  }while(selection != 4);






  return 0;
}
