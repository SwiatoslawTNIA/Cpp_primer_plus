   #include <iostream>
   #include <cstring>
   #include "cow.h"

Cow::Cow(const char * nm, const char *ho, double wt)
{  
   std::cout << "<constructor with args>";
   fflush(stdout);
   using std::cerr;
   strncpy(name, nm, strlen(nm));//it copies '\n', a constructor with three args 
   //is used with an obj, 
   name[19] = '\0';

   size_t hobby_length = strlen(ho);
   hobby = new char[hobby_length + 1];
   if(hobby == nullptr)
   {
      cerr << "Unable to allocate memory. Aborting...";
      abort();
   }
   strcpy(hobby, ho);
   weight = wt;
}
//a copy constructor:
Cow::Cow(const Cow & c)
{
   strcpy(this->name, c.name);
   //for hobby:
   if(c.hobby != nullptr)
   {
      this->hobby = new char[std::strlen(c.name) + 1];
      if(hobby == nullptr)
      {
         std::cerr << "Unable to allocate memory. Aborting...";
         abort();
      }
   }
   else
   {
      hobby = nullptr;
   }
   strcpy(hobby, c.hobby);
   this->weight = c.weight;
}
Cow::~Cow()
{
   if(this->hobby != nullptr)
   {
      delete [] this->hobby;
   }
}
//an assignment operator:
Cow & Cow::operator=(const Cow & c)
{
   if(this == &c)
      return *this;
   if(this->hobby != nullptr)
   {
      delete [] this->hobby;
   }
   strcpy(name, c.name);
   if(c.hobby != nullptr)
   {
      hobby = new char[std::strlen(c.hobby) + 1];
      strcpy(hobby, c.hobby);
   }
   else
      hobby = NULL;
   this->weight = weight;
   return *this;
}
void Cow::show(void) const
{
   std::cout << "Name: " << this->name << std::endl;
   if(this->hobby != nullptr)
      std::cout << "Hobby: " << this->hobby << std::endl;
   std::cout << "Weight: " << this->weight << std::endl;

}

Cow::Cow(void)
{
   std::cout << "<default constructor>";
   std::strcpy(name, "Default");
   name[19] = '\0';//properly initialize an array!!!
   hobby = nullptr;
   weight = 0.0;
}