#include <stock.h>
#include <iostream>
#include <cstring>
const unsigned short int ARR_SIZE = 50;//includes the '\0'
//constructors:
Stock::Stock(void): default_size(ARR_SIZE), shares(0), share_val(0.0), total_val(0.0)
{

   company = new char[default_size];
   strcpy(company, "Default name");
}
Stock::Stock(const char * co, long number_of_shares, double price): default_size(ARR_SIZE)
{
   
   if(co != nullptr)
   {
      std::cout << "length: " << strlen(co);
      fflush(stdout);
      company = new char[static_cast<size_t>(std::strlen(co)) + 1];//->5
      strcpy(company, co);//set the company to co
   }
   else
   {
      company = new char[1];
      company[0] = '\0';
   }
   shares = number_of_shares;
   share_val = price;
   set_tot();//compute the total value
}
Stock::Stock(const Stock & s): default_size(ARR_SIZE)
{// a copy constructor
   if(s.company != nullptr)
   {
      this->company = new char[strlen(s.company) + 1];
      strcpy(company, s.company);
   }
   else
   {
      company = new char[1];
      company[0] = '\0';
   }
   this->shares = s.shares;
   this->share_val = s.share_val;
   set_tot();//set all the vals
}
Stock & Stock::operator=(const Stock & s )
{
   if(&s == this) return *this;
   if(company != nullptr)
      delete [] company;

   if(s.company != nullptr)
   {
      this->company = new char[strlen(s.company) + 1];
      strcpy(company, s.company);
   }
   this->shares = s.shares;
   this->share_val = s.share_val;
   return *this;//so that we could do things like s1 = s2 = s3;
}

//destructor:
Stock::~Stock()
{
   using namespace std;
   cout << "Deleting the object: " << (company ? company : nullptr)  << endl;
   cout << "It's values: shares: " << shares << ", share_val: " << share_val 
   << "total_val: " << total_val;
   fflush(stdout);
   if(company != nullptr)
   {
      delete [] company;
   }
}

void Stock::acquire(const  char * co, long n, double pr)
{
   if(this->company != nullptr)
      delete [] company;
   if(co == nullptr)
   {
      company = new char[default_size];
   }
   else
   {
      company = new char[static_cast<size_t>(std::strlen(co)) + 1];
      strcpy(company, co);//set the company to co
   }
   shares = n;
   share_val = pr;
   set_tot();//compute the total value
}
void Stock::buy(long num, double price)
{
   shares += num;
   share_val = price;
   set_tot();
}
void Stock::sell(long num, double price)
{
   if(num > shares)
   {
      std::cerr << "Invalid amount of shares.Aborting.";
      return;
   }
   shares -= num;
   total_val += num * price;//if the price is sold, the money is gained
}
void Stock::update(double price)
{
   share_val = price;
}
void Stock::show(void) const
{
   using namespace std;
   if(company != nullptr)
      cout << "Company name: " << company << endl;

   cout << "Number of shares: " << shares << ", value of each share: " << share_val << endl;
   cout << "Total worth: " << total_val << endl;

}
   //compare two stocks by total_val, return the one with the biggest total_val:
const Stock & Stock::compare(const Stock & stock1) const
{
   if(this->total_val > stock1.total_val)
      return *this;
   else
      return stock1;
}
