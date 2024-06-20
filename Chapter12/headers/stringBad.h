#ifndef STRING_BAD_
#define STRING_BAD_
#include <iostream>
#include <cstring>
class StringBad
{
private:
   char *name;
   unsigned int str_len;
   static int num_strings;//to store the number of objects
public:
   StringBad();
   StringBad(const char *string);
   // StringBad(const StringBad & obj);// a copy constructor
   ~StringBad();
   //operator overloading:
   // StringBad & operator=(const StringBad & obj)
   // {
   //    //protect so that obj is not this:
   //    if(&obj == this)
   //       return *this;
   //    //free the existing memory + allocate the memory fo the obj :

   //    free(this->name);
   //    this->str_len = strlen(obj.name);
   //    name = new char[str_len + 1];
   //    strcpy(name, obj.name);
   //    return *this;//so the assignments like s1 = s2 = s3 are possible;
   // }
   //overload the ostream operator:
   friend std::ostream & operator<<(std::ostream & os, const StringBad & obj);

   // afriend function
   //two implementations have to be added: 1) a custom version of a copy constructor:
   StringBad(const StringBad & str)
   {
      //copy constructor:
      // num_strings++;
      this->str_len = str.str_len;
      this->name = new char[this->str_len + 1];
      if(this->name == nullptr)
      {
         std::cerr << "Unable to allocate memory. Aborting...";
         abort();
      }
      strcpy(this->name, str.name);
      //don't return anything;
   }
   //overloading the assignment operator:
   StringBad & operator=(const StringBad & obj)//a member func, it's invoced on an obj.
   {
      //assign one obj to another: free the memory of the first one
      //prevent from assigning the obj to itself(the memory will be freed before it will be copied)
      //return the *this pointer, so exps like s1 = s2 = s3; can be written:
      if(&obj == this)
         return *this;
      free(this->name);
      this->str_len = obj.str_len;
      this->name = new char[this->str_len + 1];
      strcpy(this->name, obj.name);
      return *this;
   }
};
#endif