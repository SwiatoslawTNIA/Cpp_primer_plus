#ifndef MEM_T
#define MEM_T
#include <iostream>
template <class T>
class template_class
{
private:
   template <typename Inner_T>
   class Hold
   {
      private:
         Inner_T val;
      public:
         Inner_T get_val(void) const {return val;}
         Hold(Inner_T v = 0): val(v){}
         ~Hold(){}
   };
public:

   Hold<T> val_out;
   Hold<int> val_int = 14;
   void show(void) const 
   {
         std::cout << "Valout " << val_out.get_val() << ", val_int: " << val_int.get_val(); 
   }
   //a template func:
   template <class U>
   void tell_type(U var)
   {
      std::cout << "The value has been passed to a template func> ";
   }
};
#endif