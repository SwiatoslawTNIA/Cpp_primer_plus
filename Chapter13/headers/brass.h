#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
//an abstract class:
class ABC
{
private:
   std::string full_name;
   long long int account_number;
   double balance;
protected:
   const std::string Full_name(void) const {return full_name;};
   long Account_number(void) const {return account_number;};
public:
   ABC(const std::string & s = "Nullboy", long an = -1, double bal = 0.0);
   void Deposit(double amt);
   virtual void Withdraw(double amt) = 0;// a pure virtual function
   double Balance(void) const { return balance;};
   virtual void ViewAccount(void) const = 0; //a pure virtual function
   virtual ~ABC();//a destructor for ABC class
};
class Brass: public ABC
{  
private:
   static const double virtual_value;//static const var
public:
   Brass(const std::string & client_name_i = "Nullboy", long long int account_number_i = -1,
      double balance_i = 0.0);
   //funcs with virtual: 
   virtual void ViewAccount(void) const override;
   virtual void Withdraw(double amt) override;
   virtual ~Brass();
};
class BrassPlus : public ABC
{
private:
   double maxLoan;
   double rate;
   double owesBank;
public:
   BrassPlus(const std::string & client_name_i = "Nullyboy", long long int account_number_i = -1,
   double bal = 0.0, double ml = 500, double r = 0.11125);
   BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
   //default values: ml == loan amount, r = rate;
   virtual void ViewAccount(void) const override;
   virtual void Withdraw(double amount) override;

   void ResetMax(double m) {maxLoan = m;};
   void ResetRate(double r){rate = r;};
   void ResetOwes(void) { owesBank = 0;};

}; 