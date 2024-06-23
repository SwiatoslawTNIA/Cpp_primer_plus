#include <iostream>
#include "student.h"
#include <valarray>
#include <cstring>

using std::cout, std::endl, std::cin, std::ostream, std::istream;
// double Student::Average(void) const
// {
//    if(scores.size()  > 0)
//       return scores.sum() / scores.size();
//    else
//       return 0.0;
// }
// const string & Student::Name(void) const
// {
//    return name;
// }
// double & Student::operator[](int i)
// {
//    return scores[i];
// }
// double Student::operator[](int i) const
// {
//     return  scores[i];
// }
// //private method:
// std::ostream & Student::arr_out(std::ostream & os) const
// {
//    int lim = scores.size(), i = 0;
//    if(lim > 0)
//    {
//       for(; i < lim; ++i)
//       {
//          os << scores[i] << " ";
//          if(i % 5 == 4)
//             os << std::endl;
//       }
//       if(i % 5 != 0)
//          os << std::endl;

//    }
//    else 
//       cout << "empty array";
//    return os;
// }
//    //friends:
// std::istream & operator>>(std::istream & is, Student & s)
// {
//    is >> s.name;
//    return is;
// }
// std::istream & getline(std::istream & is, Student & s)
// {
//    getline(is, s.name);
//    return is;
// }
// std::ostream & operator<<(std::ostream & os, const Student & s)
// {
//    os << "Scores for: " << s.name << endl;
//    s.arr_out(os);
//    return os;
// }

//using private inheritance:
double Student::Average(void) const
{
   if(Arr_type::size() > 0)
      return Arr_type::sum() / Arr_type::size();
   else
      return 0;
}
const std::string & Student::Name(void) const
{
   return (const std::string &) *this;//conver the return obj = this, to type const std::string reference = 

}
   //to the representation in the base class;

double & Student::operator[](int i)
{
   return Arr_type::operator[](i);//using the methods of the valarray<> class template
}
double Student::operator[](int i) const
{
   return Arr_type::operator[](i);
}
ostream & Student::arr_out(ostream & os) const
{
   int i = 0, lim = Arr_type::size();
   if(lim > 0)
   {
      for(i = 0; i < lim; ++i)
      {
         os << Arr_type::operator[](i) << " ";
         if( i % 5 == 4)
            cout << endl;
      }
      if(i % 5 != 0)
         cout << endl;
   }
   else
       os << "empty array";
   return os;
}
//friends:
istream & operator>>(istream & is, const Student & s)
{
   cin >> (std::string &)s;   //conver the "s" ref to the obj to the base_class, from which we derive
   return is;
}
istream & getline(istream & is, Student & s)//getting the name of the student => string type
{
   cin >> (std::string &)s;
   return is;
}

ostream & operator<<(ostream & os, const Student & s)
{
   os << "Scores for " << (const std::string &)s << endl;
   s.arr_out(os);//use private method for scores
   return os;
   
}







