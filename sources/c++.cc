// //---------------------------------------------------------------------------------------------------------------------
// // c++.cc
// //
// // <Explanation of the program ...>
// // <... May have multiple lines.>
// //
// //---------------------------------------------------------------------------------------------------------------------
// //
#include "c++.h"
// #include "stringBad.h"
#include <ctime>
#include <cstdlib>
#include <queue.h>
// #include "String.h"
// //---------------------------------------------------------------------------------------------------------------------
// ///
// /// This is an example header comment. Here, you explain, what the
// /// function does. Copypaste and adapt it!
// ///
// /// @param numbers an array to check
// /// @param length The length of the array. If this text is too long you can
// ///
// /// @return the highest number
// //
// const int ArSize = 10, MaxLen = 80;
// void callme1(StringBad &);
// void callme2(StringBad);
// // pass by reference
// // pass by value
// int main(void)
// {
//   // clock_t start_time = clock();
//   using namespace std;
//   srand(static_cast<unsigned int>(time(NULL)));
//   cout << "Everything works alright.";
//   using std::endl;
//   {
//     // cout << "Starting an inner block.\n";
//     // StringBad headline1("Celery Stalks at Midnight");//a default constructor is called.
//     // StringBad headline2("Lettuce Prey");
//     // StringBad sports("Spinach Leaves Bowl for Dollars");
//     // cout << "headline1: " << headline1 << endl;
//     // cout << "headline2: " << headline2 << endl;
//     // cout << "sports: " << sports << endl;
//     // callme1(headline1);
//     // cout << "headline1: " << headline1 << endl;
//     // callme2(headline2);//the copy constructor is called
//     // cout << "headline2: " << headline2 << endl;
//     // cout << "Initialize one object to another:\n";
//     // StringBad sailor = sports;//a copy constructor is called
//     // cout << "sailor: " << sailor << endl;
//     // cout << "Assign one object to another:\n";
//     // StringBad knot;
//     // knot = headline1;// a copy constructor is called
//     // cout << "knot: " << knot << endl;
//     // cout << "Exiting the block.\n";
//     // String geremy("A string example");
//     // cout << geremy;
//     // String a("block"), b("scope");
//     // a = b;//an assignment operator
//     // cout << "\n" << geremy[4];




//     // String name;
//     // cout <<"Hi, what's your name?\n>> ";
//     // cin >> name;
//     // cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
//     // String sayings[ArSize];
//     // // array of objects
//     // char temp[MaxLen];
//     // // temporary string storage
//     // int i;
//     // for (i = 0; i < ArSize; i++)
//     // {
//     //   cout << i + 1 << ": ";
//     //   cin.get(temp, MaxLen);
//     //   while (cin && cin.get() != '\n')
//     //     continue;
//     //   if (!cin || temp[0] == '\0')
//     //   // empty line?
//     //     break;
//     //   // i not incremented
//     //   else
//     //     sayings[i] = temp; // overloaded assignment
//     // }
//     // int total = i;
//     // // total # of lines read
//     // if ( total > 0)
//     // {
//     //   cout << "Here are your sayings:\n";
//     //   for (i = 0; i < total; i++)
//     //     cout << sayings[i][0] << ": " << sayings[i] << endl;
//     //   int shortest = 0;
//     //   int first = 0;
//     //   for (i = 1; i < total; i++)
//     //   {
//     //     if (sayings[i].length() < sayings[shortest].length())
//     //       shortest = i;
//     //     if (sayings[i] < sayings[first])
//     //       first = i;
//     //   }
//     //   cout << "Shortest saying:\n" << sayings[shortest] << endl;;
//     //   cout << "First alphabetically:\n" << sayings[first] << endl;
//     //   cout << "This program used "<< String::howMany()
//     //   << " String objects. Bye.\n";
//     // }
//     // else
//     //   cout << "No input! Bye.\n";

//     //the plus operator:
//     // String s1("dollar"), s2("sign"), s3("generally");
//     // // s1 = s2 + s3;
//     // cout << s1;
//     // cout << (s1 + s2 = s3).length() << std::endl;

//     //s1 + s2 creates a temp obj, to that obj the obj s3 is assigned, 
//     //then from   s3 the method length() is applied, and then that val is outputed, so 
//     //to prevent such expressions -> return const Obj.

//     //rewrite the section above using pointers:
//     String name;
//     cout <<"Hi, what's your name?\n>> ";
//     cin >> name;
//     cout << name << ", please enter up to " << ArSize << " short sayings <empty line to quit>:\n";
//     String sayings[ArSize];
//     // array of objects
//     char temp[MaxLen];
//     // temporary string storage
//     int i;
//     for (i = 0; i < ArSize; i++)
//     {
//       cout << i + 1 << ": ";
//       cin.get(temp, MaxLen);
//       while (cin && cin.get() != '\n')
//         continue;
//       if (!cin || temp[0] == '\0')
//       // empty line?
//         break;
//       // i not incremented
//       else
//         sayings[i] = temp; // overloaded assignment
//     }
//     int total = i;
//     // total # of lines read
//     if ( total > 0)
//     {
//       cout << "Here are your sayings:\n";
//       for (i = 0; i < total; i++)
//         cout << sayings[i][0] << ": " << sayings[i] << endl;
//       String *shortest = &sayings[0];
//       String *first = sayings;
//       for (i = 1; i < total; i++)
//       {
//         if (sayings[i].length() < shortest->length())
//           shortest = &sayings[i];
//         if (sayings[i] < *shortest)
//           first = (sayings + i);
//       }
//       cout << "Shortest saying:\n" << *shortest << endl;
//       cout << "First alphabetically:\n" << *first << endl;
//       cout << "This program used "<< String::howMany();
//       //create a favorite obj:
//       int rand_index = rand() % total;//select a random num from total
//       String *favorite_saying = new String(sayings[rand_index]);//created a pointer to an obj on the heap
//       cout << "My favorite quote: " << *favorite_saying;
//       delete favorite_saying;
//       cout << " String objects. Bye.\n";
//     }
    
//     else
//       cout << "No input! Bye.\n";
//     return 0;
//   }
// }
// void callme1(StringBad & rsb)
// {

//   using std::cout;
//   cout << "String passed by reference:\n";
//   cout << "\"" << rsb << "\"\n";
// }
// void callme2(StringBad sb)
// {
//   using std::cout;
//   cout << "String passed by value:\n";
//   cout << "\"" << sb << "\"\n";
//   //here the copy sb is deleted, the original object remains
// }
int main(void)
{
  using namespace std;

  cout << (int)true;  
  return 0;
}