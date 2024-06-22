#include <vintage.h>
#include <iostream>
#include <cstring>
#include <cctype>

using std::cout, std::cin, std::endl, std::strlen, std::ostream;


Port::Port(const char * br , const char * st, int b)
{
   brand = new char[strlen(br) + 1];
   strcpy(brand, br);
   strcpy(style, st);
   bottles = b;
}
Port::Port(const Port & p)
{
   brand = new char[strlen(p.brand) + 1];
   strcpy(brand, p.brand);
   strcpy(style, p.style);
   bottles = p.bottles;
}

Port & Port::operator=(const Port & p)//it can also take references to the derived classes
   {
      if(&p == this)
         return *this;
      delete [] brand;
      brand = new char[strlen(p.brand) + 1];
      strcpy(brand, p.brand);
      strcpy(style, p.style);
      bottles = p.bottles;
      return *this;
   }
Port & Port::operator+=(int b)
{
   this->bottles += b;
   return *this;
}
   // adds b to bottles
Port & Port::operator-=(int b)
{
   this->bottles -= b;
   return *this;
}
   // subtracts b from bottles, if
   //available
void Port::Show(void) const
{
   cout << "Brand: " << this->brand << endl;
   cout << "Kind: " << this->style << endl;
   cout << "Bottles: " << this->bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
   os << p.brand << ", " << p.style << ", " << p.bottles << "\n";
   return os;
}
//derived_class implementations:
VintagePort::VintagePort(void): Port()//call the port default constructor(the decl. can be omitted)
{
   nickname = new char[1];
   nickname[0] = '\0';
   year = 0;//initialize the private mem of the derived class
}
VintagePort::VintagePort(const char * br, int b, const char * nn, int y): Port(br, "default", b)
{
   nickname = new char[strlen(nn) + 1];
   strcpy(nickname, nn);
   year = y;
}
VintagePort::VintagePort(const VintagePort & vp): Port(vp)//because here I explicitly call
//the copy constructor of the base_class class
{
   this->nickname = new char[strlen(vp.nickname) + 1];
   strcpy(this->nickname, vp.nickname);
   this->year = vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
   if(&vp == this)
      return *this;
   Port::operator=(vp);
   this->nickname = new char[strlen(vp.nickname) + 1];
   strcpy(this->nickname, vp.nickname);
   this->year = vp.year;
   return *this;
}
void VintagePort::Show() const
{
   Port::Show();
   cout << "nickname: " << nickname << endl;
   cout << "year: " << year << endl;
}
ostream & operator<<(ostream & os, const VintagePort & vp)
{
   os << (const Port &)vp;
   return os;
}