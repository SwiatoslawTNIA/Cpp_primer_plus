//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Explanation of the program ...>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
#include "stringBad.h"
#include <ctime>
//---------------------------------------------------------------------------------------------------------------------
///
/// This is an example header comment. Here, you explain, what the
/// function does. Copypaste and adapt it!
///
/// @param numbers an array to check
/// @param length The length of the array. If this text is too long you can
///
/// @return the highest number
//
void callme1(StringBad &);
void callme2(StringBad);
// pass by reference
// pass by value
int main(void)
{
  clock_t start_time = clock();
  using namespace std;
  StringBad str_1;
  cout << "Everything works alright.";


  using std::endl;
{
cout << "Starting an inner block.\n";
StringBad headline1("Celery Stalks at Midnight");
StringBad headline2("Lettuce Prey");
StringBad sports("Spinach Leaves Bowl for Dollars");
cout << "headline1: " << headline1 << endl;
cout << "headline2: " << headline2 << endl;
cout << "sports: " << sports << endl;
callme1(headline1);
cout << "headline1: " << headline1 << endl;
callme2(headline2);
cout << "headline2: " << headline2 << endl;
cout << "Initialize one object to another:\n";
StringBad sailor = sports;
cout << "sailor: " << sailor << endl;
cout << "Assign one object to another:\n";
StringBad knot;
knot = headline1;
cout << "knot: " << knot << endl;
cout << "Exiting the block.\n";
}
cout << "End of main()\n";
cout << "Time spent: " << (clock() - start_time) / CLOCKS_PER_SEC;
  return 0;
}
void callme1(StringBad & rsb)
{
  using std::cout;
cout << "String passed by reference:\n";
cout << "\"" << rsb << "\"\n";
}
void callme2(StringBad sb)
{
  using std::cout;
cout << "String passed by value:\n";
cout << "\"" << sb << "\"\n";
}
