#include "implement.h"
#include <iostream>
#include <cstring>//for strcpy
using std::cout, std::cin, std::cerr, std::strlen;

//name methods:
Name::Name(const char * n , int a)
{
   name = new char[strlen(n) + 1];
   strcpy(name, n);
   age = a;
}

Name::~Name()
{
   delete [] name;
}
Name::Name(const Name & n)
{
   name = new char[strlen(n.name) + 1];
   strcpy(name, n.name);
   age = n.age;
}
Name & Name::operator=(const Name & n)
{
   if(&n == this)
      return *this;
   delete [] name;
   name = new char[strlen(n.name) + 1];
   strcpy(name, n.name);
   return *this;
}
void Name::show(void) const
{
   using namespace std;
   cout << "Name: " << name << ", age: " << age << endl;
}
//person class methods:
Person::Person(const  char *n , int ag, const  char * sur,  int h): Name(n, ag)
{
   height = h;
   surname = new char[strlen(sur) + 1];
   strcpy(surname, sur);
}
//since both reference and pointer can point to the base_class obj and derived class obj, 
//we can use the ref for the copy constructor of the name class to create the Name part, 
//plus add the Person part atop.
Person::Person(const Person & p): Name(p)
{
   surname = new char[strlen(p.surname) + 1];
   height = p.height;
   strcpy(surname, p.surname);
}
Person & Person::operator=(const Person & p)//can use the p ref for the Name class+ have to explicitly call the assign
//ment operator for the base class, since the assignment operator of the Person class has 
//direct access only to Person data
{
   if(this == &p)
      return *this;
   Name::operator=(p);//managing the age and name
   delete [] surname;
   surname = new char[strlen(p.surname) + 1];
   strcpy(surname, p.surname);
   return *this;
}
Person::~Person()
{
   //a destructor automatically calls the destructor of the base_class, so we have to care 
   //just for the things that were created in this class:
   delete [] surname;
}

void Person::show(void) const 
{
   Name::show();
   using std::cout, std::endl;
   // cout << "surname: " << this->surname << endl;
   // cout << "height: " << this->height << endl;
      cout << "surname: " <<  surname << endl;
   cout << "height: " << height << endl;
}