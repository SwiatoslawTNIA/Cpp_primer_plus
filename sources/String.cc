#include "String.h"
#include <iostream>
#include <cstring>
#include <cctype>
using std::cout, std::cin, std::cerr;

 int String::string_count = 0;//initialize a static var
// const int String::CINLIM = 80;
String::String(void)
{
   string_count++;
   this->str_len = 0;
   this->str = new char[str_len + 1];
   if(str == nullptr)
   {
      cerr << "Unable to allocate memory. Aborting...";
      abort();
   }
   cout << "<Default constructor>";
   str[str_len] = '\0';

}
String::String(const char *s)
{
   this->str_len = strlen(s);
   this->str = new char[str_len + 1];
   if(str == nullptr)
   {
      cerr << "Unable to allocate memory. Aborting...";
      abort();
   }//if the func aborts, then the string count will still be valid
   string_count++;
   cout << "<Default constructor ( with one arg)>";

   strcpy(this->str, s);
}
String::~String()
{
   delete [] str;//with new delete[] should be used
   --string_count;
   cout << "<Destructor>";

}

//copy constructor:
String::String(const String & s)
{
   ++string_count;
   
   str_len = s.str_len;
   str = new char[str_len + 1];
   strcpy(str, s.str);
   cout << "<Copy constructor>";

}
//friend funcs:
bool operator<(const String & s1, const String & s2)
{
   return (strcmp(s1.str, s2.str) < 0);
}
bool operator>(const String & s1, const String & s2)
{
   return (!(strcmp(s1.str, s2.str) < 0));

}
bool operator==(const String & s1, const String & s2)
{
   return (strcmp(s1.str, s2.str) == 0);
}
std::istream & operator>>(std::istream & input_stream, String & s)
{
   const int INITIAL_CAPACITY = 20;
   char *input = new char[INITIAL_CAPACITY + 1];
   int char_n = 0;

   char ch;
   while(input_stream.get(ch) && ch != '\n')
   {
      input[char_n++] = ch;
      if(char_n == INITIAL_CAPACITY)
      {
         char *temp = new char[char_n*2 + 1];
         std::strcpy(temp, input);
         delete[] input;
         input = temp;
      }
   }
   input[char_n] = '\0';
   s.str_len = char_n;
   if(s.str != nullptr)
      delete [] s.str;
   s.str = new char[s.str_len + 1];
   strcpy(s.str, input);
   delete [] input;//free the alloced memory
   return input_stream;
}
//not a friend function:
char  & String::operator[](int i)
{
   return str[i];
}
const char & String::operator[](int i) const
{
   return str[i];
}
std::ostream & operator<<(std::ostream & os, String & s1)
{
   if(s1.str != nullptr)
      std::cout << s1.str;
   return os;
}
//overload the = operator, for higher efficiency with strings
String & String::operator=(const char * string)
{
   cout << "<Assignment operator>";
   
   delete [] this->str;
   this->str_len = strlen(string);
   this->str = new char[str_len + 1];
   strcpy(str, string);
   return *this;
}
const String operator+(const String & s1, const String & s2)
{
   cout << "Addition operator";
   String new_string;
   new_string.str_len = s1.str_len + s2.str_len;
   delete [] new_string.str;//the default constructor creates a str of one byte long
   new_string.str = new char[new_string.str_len + 1];//one for the '\0'
   strcpy(new_string.str, s1.str);
   strcpy(&(new_string.str[s1.str_len]), s2.str);
   return new_string;
}
void String::stringup(void)
{
   for(unsigned int index = 0; index < str_len;++index)
   {
      if(isalpha(str[index]))
         str[index] = toupper(str[index]);
   }
}
void String::stringlow(void)
{
   for(unsigned int index = 0; index < str_len;++index)
   {
      if(isalpha(str[index]))
         str[index] = tolower(str[index]);
   }
}
unsigned int String::has(const char & c) const
{
   unsigned int n_of_times = 0;
   for(unsigned int index = 0; index < str_len;++index)
   {
      if(this->str[index] == c)
         ++n_of_times;
   }
   return n_of_times;
}