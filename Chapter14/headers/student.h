#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>
#include <valarray>

using std::string;
// class Student
// {
// private:
//    typedef std::valarray<double> Arrdb;
//    string name;
//    Arrdb scores;//represent scores
//    std::ostream & arr_out(std::ostream & os) const;
// public:
//    Student(): name("Null student"),scores() {} // a default constructor

//    explicit Student(const string & s): name(s), scores() {}
//    explicit Student(int n): name("Nully"), scores(n) {}
//    Student(const string & s, int n): name(s), scores(n) {}
//    Student(const string & s, const Arrdb & ar): name(s), scores(ar) {}
//    Student(const char *str, const double * pd, int n): name(str), scores(pd, n) {}

//    ~Student(){}
//    double Average(void) const;
//    const string & Name(void) const;
//    double & operator[](int i);
//    double  operator[](int i) const;
//    //friends:
//    friend std::istream & operator>>(std::istream & is, Student & s);
//    friend std::istream & getline(std::istream & is, Student & s);
//    friend std::ostream & operator<<(std::ostream & os, const Student & s);
// };


//the second version of the class Student:(using private inheritance)
class Student: private std::string, private std::valarray<double>//I have to use double here, 
//because valarray is a class template
{
private:  
   //no members, since the members are added automatically (with no names)
   typedef std::valarray<double> Arr_type;
   std::ostream & arr_out(std::ostream & os) const;

public:
   Student(): std::string("Nullboy"), Arr_type() {}
   explicit Student(const std::string & s): std::string(s), Arr_type() {}
   explicit Student(int i): std::string("Nullboy"), Arr_type(i) {}
   explicit Student(const std::string & s, int n): std::string(s), Arr_type(n) {}
   explicit Student(const std::string & s, const Arr_type & arr): std::string(s), Arr_type(arr) {}
   explicit Student(const char * str, const double * val_arr, int n): std::string(str), 
   Arr_type(val_arr, n) {}
   ~Student() {};
   double Average(void) const;
   double & operator[](int i);
   double operator[](int i ) const;
   const std::string & Name() const;
   friend std::istream & operator>>(std::istream & is, Student & stu); // 1 word
   friend std::istream & getline(std::istream & is, Student & stu);
   // 1 line
   // output
   void get_something(void)
   {
      std::cout << "Get something works.";
   }
   friend std::ostream & operator<<(std::ostream & os, const Student & stu);
};
class Boss: private Student
{
public:
   using Student::get_something;
};
class Soss: public Boss
{
public:
   void show(void)
   {
      get_something();//is private within this context
   }
};


#endif