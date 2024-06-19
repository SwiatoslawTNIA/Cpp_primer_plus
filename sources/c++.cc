// //---------------------------------------------------------------------------------------------------------------------
// // c++.cc
// //
// // <Explanation of the program ...>
// // <... May have multiple lines.>
// //
// //---------------------------------------------------------------------------------------------------------------------
// //

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

// const unsigned short int MIN_PER_HOUR = 60;
// bool new_customer(double x);

// int main(void)
// {

//   using std::cout, std::cin, std::endl, std::cerr, std::ios_base;
//   cout << "Case Study: Bank of Heather Automatic Teller\n";
//   cout << "Enter maximum size of queue: ";
//   int qs = 0;
//   cin >> qs;
//   Queue line(qs);//the queue obj
//   cout << "Enter the number of simulation hours: ";
//   int hours = 0;
//   // hours of simulation
//   cin >> hours;
//   long cycle_limit = MIN_PER_HOUR * hours;

//   cout << "Enter the average number of customers per hour: ";
//   double perhour = 0.0;
//   cin >> perhour;

//   double min_per_customer = MIN_PER_HOUR / perhour;
//   Item temp;//new customer data
//   long turnaways = 0;//turned away when the queue is full
//   long customers = 0;//joined the queue
//   long served = 0;//customers served
//   long sum_line = 0;//cumulative line_length
//   int wait_time = 0;//time until new customer may be served
//   int line_wait = 0;//cumulative time in line
//   //running the simulation:
//   for(int cycle = 0; cycle < cycle_limit;++cycle)
//   {
//     if(new_customer(min_per_customer))
//     {
//       if(line.isfull())
//       {
//         turnaways++;
//       }
//       else
//       {
//         customers++;
//         temp.set(cycle);//create new customer
//         line.enqueue(temp);//
//       }
//     }
//     if(wait_time <= 0 && !line.isempty())
//     {
//       line.dequeue(temp);// attend next customer;
//       wait_time = temp.ptime();
//       line_wait += cycle - temp.when();
//       served++;
//     }
//     if(wait_time > 0)
//       --wait_time;
//     sum_line += line.queuecount();//update the number of customers on the line
//   }
//   //reporting:
//   if(customers > 0)
//   {
//     cout << "customers accepted: " << customers << endl;
//     cout << "customers served: " << served << endl;
//     cout << "turnaways: " << turnaways << endl;
//     cout << "average queue size: ";
//     cout.precision(2);
//     cout.setf(ios_base::fixed, ios_base::floatfield);
//     cout << double( sum_line / cycle_limit) << endl;
//     cout << "average waiting time: " << double (line_wait / served);

//   }
//   else 
//      cout << "No customers!!!";
//   cout << "Done!!";

//   return 0;
// }
// //return true if the customer shows up this minute
// bool new_customer(double x)
// {
//    return (std::rand() * x / RAND_MAX < 1);
// }


// #include <queue.h>
//EXERCISE I
// #include <cow.h>
// const size_t MAX_STR_LEN = 200;
// int main(void)
// {
//   using std::cout, std::cin;
  
//   fprintf(stdout, "Enter the name(max 20 chars): ");
//   char *temp_name = new char[21];
//   char *temp_hobby = new char[MAX_STR_LEN];
//   double weight = 0.0;
//   cin.getline(temp_name, 21);
//   cout << "\nEnter your hobby: ";
//   cin.getline(temp_hobby, MAX_STR_LEN);
//   cout << ", and your weight: ";
//   cin >> weight;
//   Cow cow1 {temp_name,temp_hobby, weight }, cow2;
//   //free the allocated memory:
//   delete [] temp_name;
//   delete [] temp_hobby;
//   cow1 = cow2;//extends to cow1[1].operator=(cow[0]);
//   // //display the input, after using the assignment overloading operator
//   cow1.show();
//   cow1.show();
//   Cow new_cow("JAson   Momoa Something Browering", "Jumpskiing", 220);
//   new_cow.show();

//   // Cow cow_4 = Cow("OOO", "Bear tracking", 220);
//   // cow_4.show();
//   return 0;
// }
// EXERCISE 2: 
// #include <String.h>
// int main(void)
// {
//   using namespace std;
//   String s1(" and I am a C++ student.");
//   String s2 = "Please enter your name: ";
//   String s3;
//   cout << s2;

//   // overloaded << operator
//   cin >> s3;
//   // overloaded >> operator
//   s2 = "My name is " + s3;
//   // overloaded =, + operators
//   cout << s2 << ".\n";
//   s2 = s2 + s1;
//   s2.stringup();
//   // converts string to uppercase
//   cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
//   << " 'A' characters in it.\n";
//   s1 = "red";
//   // String(const char *),
//   // then String & operator=(const String&)
//   String rgb[3] = { String(s1), String("green"), String("blue")};
//   cout << "Enter the name of a primary color for mixing light: ";
//   String ans;
//   bool success = false;
//   while (cin >> ans)
//   {
//     ans.stringlow();
//     cout << ans;
//     // converts string to lowercase
//     for (int i = 0; i < 3; i++)
//     {
//       if (ans == rgb[i]) // overloaded == operator
//       {
//         cout << "That's right!\n";
//         success = true;
//         break;
//       }
//     }
//     if (success)
//       break;
//     else
//       cout << "Try again!\n";
//   }
//   cout << "Bye\n";
//   return 0;
// }
 //EXERCISE 3:
#include "c++.h"
// #include "stringBad.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stock.h>
int main(void)
{
  using namespace std;
  Stock stock1;
  Stock stock2("Y CO", 3213, 32.424);
  stock1.show();
  stock2.show();
  Stock bigger_stock = stock1.compare(stock2);

  bigger_stock.show();
  return 0;
}