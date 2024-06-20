#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
class Brass
{  
private:
   std::string full_name;
   long long int account_number;
   double balance;
public:
   Brass(const std::string & client_name_i = "Nullboy", long long int account_number_i = -1,
      double balance_i = 0.0);

   void Deposit(double amt);
   double Balance() const;

   //funcs with virtual: 
   virtual void ViewAccount(void) const;
   virtual void Withdraw(double amt);

   virtual ~Brass();
};
class BrassPlus : public Brass
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
   void ResetOwes() { owesBank = 0;};

}; 