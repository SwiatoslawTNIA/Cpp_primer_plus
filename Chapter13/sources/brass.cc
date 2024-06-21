#include <iostream>
#include <string>
#include "brass.h"
//class implementations:
using std::cout, std::string, std::endl, std::cerr;
//brass methods:
//constructors:

const double Brass::virtual_value = 170;

// Brass::Brass(const std::string & client_name_i, long long int account_number_i,
//       double balance_i): full_name(client_name_i), account_number(account_number_i), 
//       balance(balance_i), experiment(24)
// {

// }

// void Brass::Deposit(double balance_i)
// {
//    if(balance_i < 0)
//    {
//       cout << "Negative deposit value. Transaction aborted.";
//    }
//    else
//       balance += balance_i;
// }
// void Brass::Withdraw(double money)
// {
//    if(money < 0)
//    {
//       cout << "Input must be a positive value";
//    }
//    if(money > balance)
//    {
//       cout << "Insufficient amount of money.\n";
//    }
//    else
//       balance -= money;
// }
// double Brass::Balance() const
// {
//    return balance;
// }
// void Brass::ViewAccount(void) const
// {
//    cout << "Customer name: " << full_name << endl;
//    cout << "Account number: " << account_number << endl;
//    cout << "Balance: " << balance << endl;
// }
// Brass::~Brass()
// {

// }
// //BrassPlus methods:
// //constructor:
// BrassPlus::BrassPlus(const std::string & client_name_i, long long int account_number_i,
//    double bal , double ml , double r ): Brass(client_name_i, account_number_i, bal), 
//    maxLoan(ml), rate(r)
// {
//    owesBank = 0.0;//initialize the owesBank var
// }

// BrassPlus::BrassPlus(const Brass & ba, double ml, double r): Brass(ba), maxLoan(ml), rate(r)
// {
//    owesBank = 0.0;
// }
// //redefine ViewAccount and Withdraw():
// void BrassPlus::ViewAccount(void) const
// {
//    Brass::ViewAccount();//takes no args, Brass member func
//    cout << "Maximum loan: " << maxLoan << endl;
//    cout << "Owed to bank: " << owesBank << endl;
//    cout << "Loan percent rate: " << rate << endl;

// }
// void BrassPlus::Withdraw(double amount) 
// {
//    double current_balance = Brass::Balance();
//    if(current_balance <= amount)
//       //let brass handle it:
//       Brass::Withdraw(amount);
//    //now the amount is > balance:
//    if(amount <= current_balance + maxLoan - owesBank)
//    {// then we lend the money:
//       double advance = amount - current_balance;
//       if(advance > 0)
//       {
//          cout << "Bank advance: " << advance << endl;
//          owesBank += advance * (1 + rate);
//          cout << "Advance charge: " << advance * rate << endl;
//          Deposit(advance);//indirect access to the base_class
//          Brass::Withdraw(amount);
//       }
//    }
//    else
//       cout << "Credit limit exceeded, transaction cancelled.\n";
   
//    cout << "Direct access of a protected member of the base_class in the derived class: " 
//    << "the value of experiment: " << experiment;
// }

//implement the methods for the new class structure:
ABC::ABC(const std::string & s1, long an, double bal)
: full_name(s1), account_number(an), balance(bal)
{

}
void ABC::Deposit(double am)
{
   if(am < 0)
   {
      cout << "The amount to deposit can't be negative.";
   }
   else
      balance += am;
}
ABC::~ABC()
{
   //do nothing, the default has still to be provided;
}
void ABC::Withdraw(double am)
{
   if(balance < am)
      cerr << "The amount money is too low.";
   else
      balance -= am; 
}
//brass methods:
Brass::Brass(const std::string & client_name_i, long long int account_number_i,
      double balance_i)
   :ABC(client_name_i, account_number_i, balance_i)
{

}
void Brass::Withdraw(double am)
{
   if(am < 0)
      cout << "The amount can not be negative.";
   else if (am <= ABC::Balance())
      ABC::Withdraw(am);
   else
      cout << "Withdrawal amount exceeds your current balance. Aborting...";
}

void Brass::ViewAccount(void) const
{
   cout << "Client name: " << Full_name() << endl;
   cout << "Account number: " << Account_number() << endl;
   cout << "Balance: " << Balance() << endl;
}
Brass::~Brass()
{
   //define
}
//brassPlus:
BrassPlus::BrassPlus(const std::string & client_name_i, long long int account_number_i,
   double bal, double ml, double r)
   :ABC(client_name_i, account_number_i, bal), maxLoan(ml), rate(r), owesBank(0.0)
{

}
BrassPlus::BrassPlus(const Brass & ba, double ml, double r): ABC(ba), maxLoan(ml), rate(r) 
{

}

void BrassPlus::ViewAccount(void) const
{
   cout << "Client name: " << Full_name() << endl;
   cout << "Account number: " << Account_number() << endl;
   cout << "Balance: " << Balance() << endl;
   cout << "The current loan percent rate: " << rate << endl;
   cout << "The max amount of loan you can take: " << maxLoan;
   cout << "The amount of borrowed money: " << owesBank;
}
void BrassPlus::Withdraw(double am)
{
   if(am < ABC::Balance())
      ABC::Withdraw(am);
   else if(am <= Balance() + maxLoan - owesBank)
   {
      owesBank = (am - (double)Balance())*( 1 + rate);//func Balance returns double
      maxLoan -= owesBank;
   }
   else
      cout << "The stated amount is unable to be delivered due to insufficient account balance.";
}