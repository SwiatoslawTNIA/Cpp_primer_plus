
#include <iostream>
#include <string>

class Sales
{
public:
   enum {months = 12};
   class Bad_index
   {
      private: 
         int bi;//bad index value;
         const std::string s;
      public:
         Bad_index(){}//default constructor
         explicit Bad_index(int x,  const char * str = "Index error in Sales object."): bi(x), s(str){}
         int bi_val(void) const { return bi;}
         const std::string & str_val(void) const {return s;}
         virtual ~Bad_index(){}
   
   };
   explicit Sales(int yy = 0): year(yy){for(int i = 0; i < months; ++i){gross[i] = 0.0;}}
   Sales(int yy, const double *gr, int n);
   virtual ~Sales(){}//ensures, that if we derive from this class and use another pointer, the destructor will be called based on the object the pointer points to 
   int Year(void) const { return year;}
   virtual double operator[](int i) const;
   virtual double & operator[](int i);
private:
   double gross[months];
   int year;
};
Sales::Sales(int yy, const double *gr, int l)
{
   int lim =( l < months)? l: months ;
   for(int i = 0; i < lim; ++i)
   {
      gross[i] = gr[i];
   }
   for(int i = lim; i < months; ++ i)
   {
      gross[i] = 0;//initialize the array further
   }
   year = yy;
}
double Sales::operator[](int i ) const 
{
   if(i < 0 || i >=  months) throw Bad_index(i);
   return gross[i];
}
double & Sales::operator[](int i )
{
   if(i < 0 || i >=  months) throw Bad_index(i);
   return gross[i];
}



class LabeledSales: public Sales
{
private:
   std::string lb;

public:
      
   class Labeled_Bad_index: public Sales::Bad_index
   {
      private:
         std::string lbl;//label
      public:
         Labeled_Bad_index(const std::string & lb = "Labeled_Bad_index caught."): lbl(lb){}
         const std::string & lbl_value(void) const {return lbl;}
         virtual ~Labeled_Bad_index() throw (){}//won't throw an exception
   };
   explicit LabeledSales(const std::string & lb_i = "none", int yy = 0): Sales(yy),lb(lb_i){}
   LabeledSales(const std::string & s, int yy, const double * gr, int n): Sales(yy, gr, n), lb(s){}
   virtual ~LabeledSales(){}
   const std::string & Label(void) const {return lb;}

   virtual double & operator[](int i );
   virtual double operator[](int i ) const;

};
double LabeledSales::operator[](int i) const
{
   if(i < 0 || i >= months) throw Labeled_Bad_index();
   return Sales::operator[](i);
}

double & LabeledSales::operator[](int i)
{
   if(i < 0 || i >= months) throw Labeled_Bad_index();
   return Sales::operator[](i);

}
