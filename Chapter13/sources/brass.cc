#include <iostream>
#include <string>
#include "brass.h"
//class implementations:
using std::cout, std::string, std::endl;
//brass methods:
//constructors:

Brass::Brass(const std::string & client_name_i, long long int account_number_i,
      double balance_i): full_name(client_name_i), account_number(account_number_i), 
      balance(balance_i)
{

}

void Brass::Deposit(double balance_i)
{
   if(balance_i < 0)
   {
      cout << "Negative deposit value. Transaction aborted.";
   }
   else
      balance += balance_i;
}
void Brass::Withdraw(double money)
{
   if(money < 0)
   {
      cout << "Input must be a positive value";
   }
   if(money > balance)
   {
      cout << "Insufficient amount of money.\n";
   }
   else
      balance -= money;
}
double Brass::Balance() const
{
   return balance;
}
void Brass::ViewAccount(void) const
{
   cout << "Customer name: " << full_name << endl;
   cout << "Account number: " << account_number << endl;
   cout << "Balance: " << balance << endl;
}
Brass::~Brass()
{

}
//BrassPlus methods:
//constructor:
BrassPlus::BrassPlus(const std::string & client_name_i, long long int account_number_i,
   double bal , double ml , double r ): Brass(client_name_i, account_number_i, bal), 
   maxLoan(ml), rate(r)
{
   owesBank = 0.0;//initialize the owesBank var
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r): Brass(ba), maxLoan(ml), rate(r)
{
   owesBank = 0.0;
}
//redefine ViewAccount and Withdraw():
void BrassPlus::ViewAccount(void) const
{
   Brass::ViewAccount();//takes no args, Brass member func
   cout << "Maximum loan: " << maxLoan << endl;
   cout << "Owed to bank: " << owesBank << endl;
   cout << "Loan percent rate: " << rate << endl;

}
void BrassPlus::Withdraw(double amount) 
{
   double current_balance = Brass::Balance();
   if(current_balance <= amount)
      //let brass handle it:
      Brass::Withdraw(amount);
   //now the amount is > balance:
   if(amount <= current_balance + maxLoan - owesBank)
   {// then we lend the money:
      double advance = amount - current_balance;
      if(advance > 0)
      {
         cout << "Bank advance: " << advance << endl;
         owesBank += advance * (1 + rate);
         cout << "Advance charge: " << advance * rate << endl;
         Deposit(advance);//indirect access to the base_class
         Brass::Withdraw(amount);
      }
   }
   else
      cout << "Credit limit exceeded, transaction cancelled.\n";
   
}


