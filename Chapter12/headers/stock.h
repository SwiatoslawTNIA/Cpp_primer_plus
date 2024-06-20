#ifndef STOCKS_
#define STOCKS_
class Stock
{
private:
   const int default_size;//const obj
   long shares;
   double share_val;
   double total_val;

   char *company;
   void set_tot(){total_val = share_val * shares;}
public:
   //a constructor:
   Stock(void);
   Stock(const Stock & obj);// a copy constructor
   Stock(const char * co, long number_of_shares, double price);
   //a destructor:
   ~Stock(void);//must have no args, no return value and no decl type
   void acquire(const  char * co, long n, double pr);
   void buy(long num, double price);
   void sell(long num, double price);
   void update(double price);
   void show(void) const;
   //compare two stocks:
   //operator overloading:
   Stock & operator=(const Stock & s1 );

   const Stock & compare(const Stock & stock1) const;
};
#endif
