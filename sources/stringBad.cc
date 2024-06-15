#include <iostream>
#include "stringBad.h"
#include <cstring>
//initialize the static var:
using std::cout;
int StringBad::num_strings = 0;
//class methods:
StringBad::StringBad(const char *s)
{
   int length = strlen(s);
   name = new char[length + 1];
   if(name == nullptr)
   {
      std::cerr << "Insufficient amount of memory, aborting.";
      abort();
   }
   std::strcpy(name, s);
   num_strings++;//increment the number of strings;
   cout << num_strings << ": \"" << name << "\" obj. created.\n";

}
StringBad::StringBad(void)
{
   int length = 4;
   name = new char[length];
   if(name == nullptr)
   {
      std::cerr << "Not enough memory. Aborting.";
      abort();
   }
   std::strcpy(name, "C++");
   num_strings++;
   cout << num_strings << ": \"" << name << "\" obj. created.\n";
}
StringBad::~StringBad()
{
   cout << "Object" << name << " deleted.\n";
   num_strings--;
   cout << num_strings << "left.\n";
   delete [] name;
}
std::ostream & operator<<(std::ostream & os, const StringBad & s)
{
   os << s.name;
   return os;
}


