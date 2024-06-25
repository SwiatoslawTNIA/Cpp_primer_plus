#ifndef ARR_T
#define ARR_T
#include <iostream>
#include <cstdlib>
using namespace std;
template <class T, int n>
class Arr
{

private:
   T list[n];
public:
   Arr();
   Arr(const Arr &);
   T & operator[](int i);
   T operator[](int i) const;
   ~Arr();
};
template< class special_type, int n>
Arr<special_type,n>::Arr(void)
{
   ;
}
template< class Type, int n>
Arr<Type,n>::Arr(const Arr & ref)
{
   for(int i = 0; i < n;++i)
   {
      list[i] = ref.list[i];
   }
}

template<class new_type, int n>
new_type & Arr<new_type,n>::operator[](int num)
{
   if(num < 0 || num > this->n)
   {
      cerr << "Error. Invalid Index, Exiting.";
      exit(EXIT_FAILURE);
   }
   else
      return list[n];
}
template <class T, int n>
T Arr<T,n>::operator[](int i) const
{
   if (i < 0 || i >= n)
   {
      std::cerr << "Error in array limits: " << i
      << " is out of range\n";
      std::exit(EXIT_FAILURE);
   }
   return list[i];
}



template<class T1, class T2>
class Pair
{
private:
   T1 a;
   T2 b;
public:
   T1 & first();
   T2 & second();
   T1 first() const {return a;}
   T2 second() const {return b;}
   Pair(const T1 & val_1, const T2 & val_2): a(val_1), b(val_2){}
   Pair(){}//default constructor
};

template<class T1, class T2>
T1 & Pair<T1, T2>::first(void)
{
   return a;
}
template<class T1, class T2>
T2 & Pair<T1, T2>::second(void)
{
   return b;
}
#endif


/*
Templates offer an enormous versatility:
template <class T1, class T2>//two different types for one template class
class Example1
{
};
template <class T1, class T2 = int>//two different types for one template class +
class Example2{//a default second type, so we can say:

};

Example2<double, double> val;
or 
Example2<double> val;//the default type will be used here

 */