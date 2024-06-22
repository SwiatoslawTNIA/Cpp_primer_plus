#include <iostream>
#include <cstring>
#include <valarray>

using std::string;
class Student
{
private:
   typedef valarray<double> Arrdb;
   string name;
   Arrdb scores;//represent scores
public:
   Student(): name("Null student"),scores() {} // a default constructor

   explicit Student(const string & s): name(s), scores() {}
   explicit Student(int n): name("Nully"), scores(n) {}
   Student(const string & s, int n): name(s), scores(n) {}
   Student(const string & s, const Arrdb & ar): name(s), scores(ar) {}
   Student(const char *str, const double * pd, int n): name(str), scores(pd, n) {}

   ~Student(){}
   double Average(void) const;
   const string & Name(void) const;
   double & operator[](int i);
   double & operator[](int i) const;
   //friends:
   friend std::istream & operator>>(std::istream & is, Student & s);
   friend std::istream & getline(std::istream & is, Student & s);
   friend std::ostream & operator<<(std::ostream & os, const Student & s);
};