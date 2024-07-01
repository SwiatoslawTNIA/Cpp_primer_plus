//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Explanation of the program ...>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
#include <ctime>
#include <cstring>
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

void part1(void);

int main(void)
{
  using namespace std;
  
    //!cin 
  int value;
  cout.write("Type: ", strlen("Type: ") + 1);
  // cin >> oct >> value;//using hex type conversion, calue is 4332, even though I typed 1234..
  // cout << value;
  // int last_input;
  //set the cin stream, so that it throws exceptions for eofbit or failbit:
  // cin.exceptions(std::ios_base::eofbit | std::ios_base::failbit);
  // try{
  //   while(cin >> value)//trying to throw an exception, when the input is bad:
  //   {
  //     cout << endl << value << endl;
      
  //   }
  // }catch(std::ios_base::failure & r)
  // {
  //   cout << r.what() << endl;
  //   cout << "Wow. That is but a shame.";
  // }
  
  cout << "Last input that worked: " << value;


  //other cin methods:
  //cin.get(char & s) or cin.get(void) read a character at a time, \n included:
  cout << "Type in: ";
  char n;
  bool new_line_was = false;
  cout << "The end of file: " << EOF;
  while( (n = cin.get()) != '\n' || !new_line_was)
  {
    if(n == '\n') new_line_was = true;
    cout << n;
  }
  //let's say I set a delimeter, then I 
  return 0;
}
void part1(void) 
{
  using namespace std;
  cout << "Everything works alright.";
  wclog << "Something";


  const char * s = "Something to display.";
  wcout << s << endl;
  //the cout object has the following methods:
  //.write() and .put()//for printing strings and chars (respectively), 
  //the .put() method has the following prototypes: ostream & put(char);
  cout.put('A');//print one char
  ;
  cout.put('B').put('\n').put('H').put('A').put('!');
  cout.put(97);
  const char *s1[] = {"Kansas","Michigan","New York"};

  for(int i = 0; i < 3; ++i)
  {
    for(int j = 0; s1[i][j] != '\0';++j)
    {
      cout.write(s1[i], j + 1).write("\n", 1);
    }
  }
  // cout.write("Sunday").write("Something").write(s[1]) << endl;


  long val = 560031841;
  cout.write((char *)&val, sizeof(long));


  cout << "\n\n\n";
  cout << "Some string." << endl;
  clock_t time_start = time(NULL);
  // while(time(NULL) - time_start < 3)
  //   ;
  cout << "Another string.";


  hex(cout);
  int i = 44, b = 2, c = 15;
  cout << i << ", " << b << ", " << c;
  dec(cout);
  cout << endl  << "Decimal form: ";
  cout << i << ", " << b << ", " << c;
  cout << endl;
  cout <<"Octal form: " << oct << i << ", " << b << ", " << c << "Decimal again: " << dec <<  " " << i << ", " << '.';

  cout << "\n\n\n";
  cout << "The current field width: " << cout.width();
  int current_field_w = cout.width();
  cout.width(20);
  cout << "+" << 10 << "+" << 20 << "+";
  cout.fill('^');
  cout.width(20);
  cout << endl << hex << "Some very imp";
  cout.width(30);
  cout << "Another extract";
  cout << endl;
  cout << "Printing some checks: " << endl;
  const char *names[] = {"john", "Peter"};
  int check_width = 50, length = (check_width - strlen(names[0]) % 2 == 1)?(check_width - strlen(names[0]) + 1) :( check_width - strlen(names[0]))   / 2;//if the thing is even, then divide by two, else add 1, and then divide by two
  for(int i = 0; i < 50; ++i)
  {
    for(int  j = 0; j < check_width;++j)
    {
      if(i == 40 && j == length)
      {
        cout << names[0];//at the start with only one name
        j += strlen(names[0]);
      } 
      cout << "*";//if i is the same as length, then we print the name instead of asteriscs
      // - 1 since i gets incremented at the end of the loop.
    }
    cout << endl;
  }
  double hex_ = 0X32;//exactly fifty = the length of the string;
  cout << dec  << hex_ << sizeof("*** *** *** *** *** *** *** **j ohn *** *** *** *** *** *** *** **") / sizeof(char);
  
  
  wcout << std::cout.precision() << endl;
  long double result = 6.0 / 7.0;
  wcout << "The normal result: " << result << endl;
  wcout.precision(3);
  wcout << "The result with a precision(3): " << result << endl;
  wcout.precision(14);

  wcout << "The result with a precision(14): " << result << endl;
  wcout.precision(0);
  wcout<< "The result with a precision(0): " << result << endl;



  cout << "Using the setf() method to change the floating point settings: using ios_base::showpoint";
  cout.setf(std::ios_base::showpoint);//set the floating point trailing
  cout.precision(10);//set the precision
  cout << endl << dec << "example: " << 20.4 << ", and " << -24.123;
  cout.setf(std::ios_base::boolalpha);
  cout <<(bool)1;
  // setf stands for set flags is a powerful access method for manipulating the stream, 
  // it uses a bitmask, but instead of refering to a bit, I start by using consts: showpoint, showbase, boolalpha...
  
  cout << endl;//flush the buffers + '\n'
  cout.setf(std::ios_base::showbase);//use cpp base prefixes
  // cout.setf(std::ios_base::showpoint);//show trailing decimal point
  cout.setf(std::ios_base::showpos);//use positive before positive numbers
  cout.unsetf(std::ios_base::showpoint);
  int temperature = 25; 
  cout << "Today's water temperature averaged " << temperature << " deg C.";
  cout << "In a programming manner: "  << hex << temperature << endl;
  cout.setf(std::ios_base::uppercase);//use uppercase for hex:
  cout << "IN UPPERCASE: " << temperature << endl;
  cout << "Using fixed-point notation: " << endl;
  //change the base to 10:
  cout.setf(std::ios_base::dec, std::ios_base::basefield);
  cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  cout.setf(std::ios_base::left, std::ios_base::adjustfield);
  cout.precision(3);
  cout.width(20);
  cout << 1.2342132;
  cout << "Using scientific notation: " << endl;
  cout.setf(std::ios_base::scientific, std::ios_base::floatfield);
  cout.width(20);
  cout << 1.2342132 << endl;
  cout.unsetf(std::ios_base::showpos);
  cout.unsetf(std::ios_base::showpoint);
  cout.unsetf(std::ios_base::showbase);
  cout.unsetf(std::ios_base::floatfield);//same as cout.unsetf(std::ios_base::scientific)
  cout << 1.2342132;//precision 3
}