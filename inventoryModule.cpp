#include "inventoryModule.h"
using namespace std;

void inventoryMenu()
{
  bool isTransactionComplete = false;
  char selection = '\0';
  
  do
  {
    cout << "Serendipity Book Store" << endl;
    cout << "Inventory Menu" << endl;








    cout << endl << endl;
    cout << "Complete Transaction? (Y/N): ";
    cin >> selection;


    while (selection != 'y' || selection != 'Y' || selection != 'n' || selection != 'N')
    {
      cout << "Please try again (Y/N): ";
      cin >> selection;
    }

    if (selection == 'y' || selection == 'Y')
    {
      isTransactionComplete = true;
    }

  } while (isTransactionComplete != false);



  cin.ignore(1000, '\n');
  cin.get();

}
void searchBook();
void addBook();
void editBook();
void deleteBook();
