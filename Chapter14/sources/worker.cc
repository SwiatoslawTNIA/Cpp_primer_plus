#include <iostream>
#include <string>
#include <cstring>
#include "worker.h"
using std::cout, std::endl, std::cin;


Worker::~Worker() {}

void Worker::Data(void) const
{
    cout << "Name: " << fullname << endl;
    cout << "Id: " << id << endl;
}
void Worker::Get(void)
{
   getline(cin, fullname);
   cout << "Enter worker's id: ";
   cin >> id;
   while(cin.get() != '\n')
      continue;
}
void Worker::Set()
{
   cout << "Enter worker's name: ";
   getline(cin, fullname);
   cout << "Enter worker's ID: ";
   cin >> id;
   while (cin.get() != '\n')
      continue;   
}
void Worker::Show() const
{
cout << "Name: " << fullname << "\n";
cout << "Employee ID: " << id << "\n";
}




//waiter methods:
void Waiter::Set(void)
{
   Worker::Set();
   cout << "Enter waiter's panache rating: ";
   cin >> panache;
   while (cin.get() != '\n')
      continue;
}

void Waiter::Show(void) const
{
   cout << "Category: waiter\n";
   Worker::Show();
   cout << "Panache rating: " << panache << "\n";
}
void Waiter::Data(void) const
{
   cout << "Panache rating: " << panache << endl;
}
void Waiter::Get(void) 
{
   cout << "Enter the panache";
   cin >> panache;
}
//initialize the array  :
const char *Singer::pv[7] = {"other", "alto", "contralto", "soprano", "bass", "baritone",
"tenor"};

void Singer::Set()
{
   Worker::Set();
   cout << "Enter number for singer's vocal range:\n";
   int i;
   for (i = 0; i < Vtypes; i++)
   {
      cout << i << ": " << pv[i] << "   ";
      if ( i % 4 == 3)
         cout << endl;
   }
   if (i % 4 != 0)
      cout << endl;
   while (cin >> voice && (voice < 0 || voice >= Vtypes) )
      cout << "Please enter a value >= 0 and < " << Vtypes << endl;
   while (cin.get() != '\n')
      continue;
}


void Singer::Show() const
{
   cout << "Category: singer\n";
   Worker::Show();
   cout << "Vocal range: " << pv[voice] << endl;
}
void Singer::Data(void) const
{
   cout << "Voice: " << pv[voice]; 
}
void Singer::Get(void)
{
    cout << "Enter number for singer's vocal range:\n";
   int i;
   for(i = 0; i < Vtypes;++i)
   {
      cout << i << ": " << pv[i] << "  ";
      if(i % 4 == 3)
         cout << endl;
   }
   if(i % 4 != 0)
   {
      cout << '\n';
   }
   cin >> voice;
   while(cin.get() != '\n')
      continue;

}
//singerWaiter methods:
void SingingWaiter::Data() const
{
   Singer::Data();//we split the data between multiple classes.
   Waiter::Data();
}
void SingingWaiter::Get(void)
{
   // Worker::Get();//the worker::Get() is not included
   Waiter::Get();
   Singer::Get();
}

void SingingWaiter::Set(void)
{
   cout << "Enter SingingWaiter's name: "; 
   Worker::Get();
   Get();//calling the local get calls Waiter::Get() and Singer::Get()
}
void SingingWaiter::Show(void) const
{
   Worker::Show();
   Waiter::Show();
   Singer::Show();

}