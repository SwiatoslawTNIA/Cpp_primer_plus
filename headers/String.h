#ifndef STRING_
#define STRING_
#include <iostream>
#include <cstring>

class String
{
private:
   unsigned int str_len;
   static int string_count;
   char *str;
   static const int CINLIM;
public:
   String();//default constructor
   String(const String & s);//copy constructor
   ~String();//desctructor
   String(const char *string);//default constructor with one arg
   //member funcs:
   int length(void) const {return str_len;};//inline function 
   void stringlow(void);
   void stringup(void);
   unsigned int has(const char & c) const;
   static int howMany(void) {return string_count;};//static inline function, returns a static var
   //overloading:
   String & operator=(const String & s)//an assignment operator
   {
      if(this == &s)
         return *this;//return the reference to this obj
      delete [] str;//or using free
      
      this->str_len = s.str_len;
      this->str = new char[str_len + 1];
      if(str == nullptr)
      {
         std::cerr << "Unable to allocate memory.";
         abort();
      }
      strcpy(str, s.str);
      return *this;//so that we could do something like s1 = s2 = s3;
   }
   String & operator=(const char *);
   //friend funcs:

   //overloading:

   friend bool operator<(const String & s1, const String & s2);
   friend bool operator>(const String & s1, const String & s2);
   friend bool operator==(const String & s1, const String & s2);
   friend const String operator+(const String & s1, const String & s2);

   char & operator[](int i);//expands to obj.operator[](i) from obj[i]
   const char & operator[](int i) const;// a second version for const String types
   //istream:
   friend std::istream & operator>>(std::istream & input_stream, String & s1);
   friend std::ostream & operator<<(std::ostream & output_stream, String & s1);
   //other funcs:

};
#endif