#ifndef STRING_BAD_
#define STRING_BAD_
#include <iostream>
class StringBad
{
private:
   char *name;
   unsigned int str_len;
   static int num_strings;//to store the number of objects
public:
   StringBad();
   StringBad(const char *string);
   ~StringBad();
   //overload the ostream operator:
   friend std::ostream & operator<<(std::ostream & os, const StringBad & obj);
   // afriend function
};
#endif