#include <iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
public:
  Coins(int q, int d, int n, int p)
  {
    quarters = q;
    dimes = d;
    nickels = n;
    pennies = p;
  }

  void deposit_coins( Coins & c)
  {
    quarters = quarters + c.quarters;
    dimes = dimes + c.dimes;
    nickels = nickels + c.nickels;
    pennies = pennies + c.pennies;
    c = Coins(0,0,0,0);

  }

  bool has_exact_change_for_coins( Coins c )
  {
    if (((quarters >= c.quarters & dimes >= c.dimes ) & nickels >= c.nickels ) & pennies >= c.pennies )
    {
      return true;
    }else
    {
      return false;
    }
  }

  Coins extract_exact_change( Coins c )
  {
    if (has_exact_change_for_coins(c))
    {
      quarters = quarters - c.quarters;
      dimes = dimes - c.dimes;
      nickels = nickels - c.nickels;
      pennies = pennies - c.pennies;
      return Coins(c.quarters,c.dimes,c.nickels,c.pennies);
    }
    else
    {
      cout << "ERROR: Insufficient Funds" << endl;
      return Coins(0,0,0,0);
    }

  }

  int total_value_in_cents()
  {
    return quarters*CENTS_PER_QUARTER+dimes*CENTS_PER_DIME+nickels*CENTS_PER_NICKEL+pennies;
  }

  void print(ostream & out)
  {
    out << quarters <<" quarters, " << dimes <<" dimes, " << nickels << " nickels, " << pennies <<" pennies";
  }

  bool can_withdraw_coins(Coins c)
  {
    return quarters >= c.quarters && dimes >= c.dimes 
    && nickels >= c.nikcels && pennies >= c.pennies
  }

private:
  int quarters, dimes, nickels, pennies;
};

ostream & operator << ( ostream & out , Coins c)
{
  c.print(out);
  return out;
};

Coins coins_required_for_cents(int amount_int_cents)
{
  int num_q = 0;
  int num_d = 0;
  int num_n = 0;
  while (amount_int_cents >= CENTS_PER_QUARTER)
  {
    num_q++;
    amount_int_cents = amount_int_cents - CENTS_PER_QUARTER;
  }
  while (amount_int_cents >= CENTS_PER_DIME)
  {
    num_d++;
    amount_int_cents = amount_int_cents - CENTS_PER_DIME;
  }
  while (amount_int_cents >= CENTS_PER_NICKEL)
  {
    num_n++;
    amount_int_cents = amount_int_cents - CENTS_PER_NICKEL;
  }
  return Coins(num_q,num_d,num_n,amount_int_cents);

};

