#include <iostream>
#include <iomanip>
using namespace std;
#include "Coins.h"

int main()
{
  Coins myCoins = Coins(0,0,0,0);
  bool running = true;
  while (running)
  {
    cout << "Coin Menu" << endl;
    cout << endl;
    cout << "1. Deposit Change" << endl;
    cout << "2. Extract Change" << endl;
    cout << "3. Print Balance" << endl;
    cout << "4. Exit" << endl;
    cout << endl;
  
    int user_input;
    cout << "User Input: ";
    cin >> user_input;
    cout << endl;

    switch (user_input)
    {
      case 1:
      {      
        int q,d,n,p;
        cout << "Quarters? ";
        cin >> q;
        cout << "Dimes? ";
        cin >> d;
        cout << "Nickels? ";
        cin >> n;
        cout << "Pennies? ";
        cin >> p;
        cout << endl;

        Coins deposit = Coins(q,d,n,p);
        myCoins.deposit_coins(deposit);

        cout << "Thank you!" << endl;
        cout << endl;
        break;
      }
    
      case 2:
      {
        int q,d,n,p;
        cout << "Quarters? ";
        cin >> q;
        cout << "Dimes? ";
        cin >> d;
        cout << "Nickels? ";
        cin >> n;
        cout << "Pennies? ";
        cin >> p;
        cout << endl;

        Coins extract = Coins(q,d,n,p);
        myCoins.extract_exact_change(extract);

        cout << "Thank you!" << endl;
        cout << endl;
        break;
      }

      case 3:
      {
        double total = myCoins.total_value_in_cents()/100.0 ;
        cout << fixed << setprecision(2);
        cout << "$" << total << endl;
        cout << endl;
        cout << "Thank you!" << endl;
        cout << endl;
        break;
      }

      case 4:
      {
        running = false;
        break;
      }

      default:
      {
        running = false;
        break;
      }
    }
  }
  return 0;
}