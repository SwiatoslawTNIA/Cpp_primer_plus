#include <iostream>
#include "cd.h"
#include <cstring>
#include <cctype>


const unsigned short int MIN_ARR_SIZE = 10;
using std::strcpy, std::cerr, std::cout, std::endl;


Cd::Cd(const char * s1, const char * s2, int n, double x)
{
   this->performance = new char[strlen(s1) + 1];
   strcpy(performance, s1);
   this->label = new char[strlen(s2) + 1];
   strcpy(label, s2);

   selections = n;
   playtime = x;
}
Cd::Cd(const Cd & d)//copy constructor:
{
   this->performance = new char[strlen(d.performance) + 1];
   this->label = new char[strlen(d.label) + 1];
   strcpy(this->performance, d.performance);
   strcpy(this->label, d.label);
   this->selections = d.selections;
   this->playtime = d.playtime;
}
Cd::Cd(void)
{
   this->performance = new char[MIN_ARR_SIZE];
   strcpy(this->performance, "default");
   this->label = new char[MIN_ARR_SIZE];
   strcpy(this->label, "default");
}
Cd::~Cd()
{
   delete [] this->performance;
   delete [] this->label;
}
void Cd::Report(void) const
{
   cout << "CD Data: " << endl;
   cout << "\tperformance: " << this->performance << endl;
   cout << "\tlabel: " << this->label << endl;
   cout << "\tselections: " << this->selections << endl;
   cout << "\tplaytime: " << this->playtime << endl;

} // reports all CD data
Cd & Cd::operator=(const Cd & d)
{
   if(&d == this)
      return *this;
   delete [] this->performance;
   delete [] this->label;

   this->performance = new char[strlen(d.performance) + 1];
   strcpy(performance, d.performance);
   this->label = new char[strlen(d.label) + 1];
   strcpy(label, d.label);
   this->selections = d.selections;
   this->playtime = d.playtime;
   return *this;
}

//classic implementation:
Classic::Classic(const char *pr_work, const char * s1, const char *s2, int n, double x)
:Cd(s1, s2, n, x)
{
   primary_work = new char[strlen(pr_work) + 1];
   strcpy(primary_work, pr_work);

}
Classic::Classic(void): Cd()//call the default constructor
{
   primary_work = new char[MIN_ARR_SIZE];
   strcpy(primary_work, "default");//set a default value to the primary_work var;
}
Classic & Classic::operator=(const Classic & obj)
{
   if(&obj == this)
      return *this;
   Cd::operator=(obj);//call the base_class assignment operator
   delete [] primary_work;
   primary_work = new char[strlen(obj.primary_work) + 1];
   strcpy(primary_work, obj.primary_work);
   return *this;
}  
Classic::Classic(const Classic & ref): 
Cd(ref)//copy constructor
{
   primary_work = new char[strlen(ref.primary_work) + 1];
   strcpy(primary_work, ref.primary_work);

}
Classic::~Classic()//
{
   delete [] primary_work;
}
void Classic::Report(void) const
{
   Cd::Report();
   cout << "\t" << "primary_work: " << primary_work;
} // reports all CD data
