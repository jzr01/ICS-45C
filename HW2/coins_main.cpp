#include <iostream>
using namespace std;
#include "Coins.h"
const int CENTS_FOR_CHIPS = 68;
const int TRANSFER = 205;

int main()
{
  Coins pocket = Coins(5,3,6,8);
  Coins piggyBank = Coins(50,50,50,50);
  Coins found = Coins(10,10,10,10);

  cout << "Bought Chips" << endl;
  pocket.extract_exact_change( coins_required_for_cents(CENTS_FOR_CHIPS));
  cout << "Pocket: " << pocket << endl;
  cout << endl;

  cout << "Transfer Money to Piggy Bank" << endl;
  Coins transfer = coins_required_for_cents(TRANSFER);
  piggyBank.extract_exact_change(transfer);
  pocket.deposit_coins(transfer);
  cout << "Pocket: " << pocket << endl;
  cout << "Piggy Bank: " << piggyBank << endl;
  cout << endl;

  cout << "Vacuuming Change" << endl;
  piggyBank.deposit_coins(found);
  double total = piggyBank.total_value_in_cents()/100.0;
  cout << "Piggy Bank: $" << total << endl;
  
  return 0;

}