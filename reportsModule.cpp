#include "reportsModule.h"
using namespace std;


void reportsMenu()
{
  int selection = 0;

  do
  {
    cout << "Serendipity Book Sellers" << endl << endl;

    system("clear");

    cout << "Serendipity Booksellers" << endl << endl;

    cout << "           Reports Menu              " << endl;
    cout << "*************************************" << endl;
    cout << "* 1. Inventory Listing              *" << endl;
    cout << "* 2. Inventory Wholesale Value      *" << endl;
    cout << "* 3. Inventory Retail Value         *" << endl;
    cout << "* 4. Listing By Quantity            *" << endl;
    cout << "* 5. Listing By Wholesale Cost      *" << endl;
    cout << "* 6. Listing By Date                *" << endl;
    cout << "* 7. Return To Main Menu            *" << endl;
    cout << "*************************************" << endl;
    cout << endl;








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
        viewAllListing();
        break;

      case 2:
        reportWholesale();
        break;

      case 3:
        reportRetail();
        break;

      case 4:
        viewByQuantity();
        break;

      case 5:
        viewByWholesale();
        break;

      case 6:
        viewByDateAdded();
        break;

      case 7:
        cout << "Returning to Main Menu" << endl;
        break;

      default:
        cout << "Something went wrong" << endl;
    }
  } while (selection != 7);



  cin.ignore(1000, '\n');
  cin.get();

}


void viewAllListing()
{
  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "View All Listing" << endl << endl;
  cout << left;
  cout << setw(40) << "Title";
  cout << setw(15) << "ISBN";
  cout << setw(35) << "Author";
  cout << setw(30) << "Publisher";
  cout << setw(15) << "Date Added";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(20) << "Wholesale Cost($)";
  cout << setw(20) << "Retail Price($)";
  cout << endl;
  cout << right;
  cout << setw(195) << setfill('-') << "-" << endl;
  cout << setfill(' ');







cin.ignore(1000, '\n');
cin.get();
}


void reportWholesale()
{
  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "Wholesale Report" << endl << endl;
  cout << left;
  cout << setw(40) << "Title";
  cout << setw(15) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(25) << "Wholesale Cost($)";
  cout << endl;
  cout << right;
  cout << setw(100) << setfill('-') << "-" << endl;
  cout << setfill(' ');







  cin.ignore(1000, '\n');
  cin.get();
}

void reportRetail()
{
  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "Retail Report" << endl << endl;
  cout << left;
  cout << setw(40) << "Title";
  cout << setw(15) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(25) << "Retail Price($)";
  cout << endl;
  cout << right;
  cout << setw(100) << setfill('-') << "-" << endl;
  cout << setfill(' ');







  cin.ignore(1000, '\n');
  cin.get();
}


void viewByQuantity()
{
  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "View By Quantity" << endl << endl;
  cout << left;
  cout << setw(90) << "Title";
  cout << setw(20) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << endl;
  cout << setw(150) << setfill('-') << "-" << endl;
  cout << setfill(' ');





  cin.ignore(1000, '\n');
  cin.get();
}


void viewByWholesale()
{
  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "View By Wholesale Cost" << endl << endl;
  cout << left;
  cout << setw(90) << "Title";
  cout << setw(20) << "ISBN";
  cout << right;
  cout << setw(15) << "Wholesale Cost";
  cout << endl;
  cout << setw(150) << setfill('-') << "-" << endl;
  cout << setfill(' ');








  cin.ignore(1000, '\n');
  cin.get();
}

void viewByDateAdded()
{
  system("clear");
  cout << "Serndipity Book Sellers" << endl;
  cout << "View By Date Added" << endl << endl;
  cout << left;
  cout << setw(90) << "Title";
  cout << setw(20) << "ISBN";
  cout << right;
  cout << setw(15) << "Qty on Hand";
  cout << setw(15) << "Date Added";
  cout << endl;
  cout << setw(150) << setfill('-') << "-" << endl;
  cout << setfill(' ');





  cin.ignore(1000, '\n');
  cin.get();
}
