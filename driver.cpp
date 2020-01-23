#include <iostream>
#include "mainMenu.h"
#include "cashierModule.h"
#include "inventoryModule.h"
#include "reportsModule.h"
#include "book.h"
using namespace std;

void readInDataBase();

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
        reportsMenu();
        break;

      case 4:
        cout << "Exiting Program" << endl;
        break;

      default:
        cout << "Something went wrong" << endl;
    }

  }while(selection != 4);


  return 0;
}


void readInDataBase()
{
  
}
