//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Chapter15>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
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
#include "tv.h"
// #include "queue.h"
#include "qtemp.h"
#include <cstdlib>
#include <cfloat>
#include <cmath>
#include <string>

class Demo
{
private:
  std::string word;
public:
  Demo(const std::string & s)
  {
    word = s;
    std::cout << "demo " << word << "created\n";

  }
  ~Demo()
  {
    std::cout << "demo " << word << "destroyed\n";
  }
  void show(void)
  {
    std::cout << "demo " << word << "lives!\n";
  }
};
class Bad_hmean
{
private:
  double v1;
  double v2;
public:
  Bad_hmean(double val1 = 0.0, double val2 = 0.0): v1(val1), v2(val2){}
  virtual void message(void) const;
};

class Bad_gmean: public Bad_hmean
{
public:
  Bad_gmean(double val1 = 0.0, double val2 = 0.0): Bad_hmean(val1,val2){}
  virtual void message(void) const;
};
void Bad_gmean::message(void) const
{
  std::cout << "\nInvalid args , exception thrown for the Bad_gmean obj";
}

inline void Bad_hmean::message(void) const
{
  std::cout << "Invalid args: " << v1 << ", and " << v2;
}
double hmean(double x, double y);
double gmean(double x, double y);
double means(double x, double y);

int main(void)
{
  using namespace std;
  // Tv s42;
  // cout << "Initial settings for 42\" TV:\n";
  // s42.settings();
  // s42.onoff();
  // s42.chanup();
  // cout << "\nAdjusted settings for 42\" TV:\n";
  // s42.settings();
  // Remote grey;
  // grey.set_chan(s42, 10);
  // grey.volup(s42);
  // grey.volup(s42);
  // cout << "\n42\" settings after using remote:\n";
  // s42.settings();
  // Tv s58(Tv::ON);
  // s58.set_mode();
  // grey.set_chan(s58,28);
  // cout << "\n58\" settings:\n";
  // s58.settings();





  // Queue<int> q1(10);
  // q1.enqueue(14);
  // q1.enqueue(-10);
  
  // q1.enqueue(14);
  // q1.dequeue(2);//the test condition should be temp != nullptr && temp->item != ref
  // // !!
  // q1.dequeue(-10);
  // q1.enqueue(27);
  //exceptions:
  double x = 0.0, y = 0.0, z = 0.0;
    std::cout << "Enter two numbers: "; 
  //throwing an exception:
  while(cin >> x >> y)
  {
    
    

    // z = hmean(x, y);
    // cout << "\nHarmonic mean of " << x << " and " << y << " is: " << z;
    // cout << "\nEnter the next pair of numbers, q to quit.";
    //version 2.0:
    // if(!hmean(x, y, &z))
    // {
    //   cout << "X cannot be inverse of y" << endl;

    // }
    // else
    //   cout << "Result: " << z << endl;

    // std::cout << "Enter two numbers: "; 
    //exception version:
    // try
    //   {
    //     z = hmean(x, y);
    //   }
    // catch(const char * s)
    // {
    //   std::cout << s << std::endl;
    //   std::cout << "Enter a new pair of numbers";
    //   cout << "Don't be a fool, enter the data correctly.";
    //   continue;
    // }

    // catch(int n2)
    // {
    //   std::cout << "REceived 33";
    // }
    // catch(Bad_hmean & r)
    // {
    //   r.message();//print the message
    // }
    // cout << "\nHarmonic mean of " << x << " and " << y << " is: " << z;
    // cout << "\nEnter the next pair of numbers, q to quit.";
    Demo d1("Found in block main.");
    cout << "Enter the numbers: ";
    while(cin >> x >> y)
    {
      try
      {
        // z = means(x, y);
        cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
        cout << "enter next pair: ";
        throw Bad_gmean();
      } 
      catch(Bad_gmean & b)
      {
        b.message();
        throw;
      }
      catch(Bad_hmean & b)
      {
        b.message();
        cout << "Caught in Bad_hmean in the main func";
        cout << "Try again.\n";
        continue;//move to the next iteration of the while loop

      }
      
      catch(const char *)
      {
        cout << "Caught the rethrown exception from the mean func in the outer catch";
        continue;
      }
    }
    d1.show();//showing in the end of the while loop
  } 
  return 0;
}
// double hmean(double x,double y)
// {
//   if(x == -y)
//   {
//     std::cerr << "Invalid numbers";
//     std::abort();
//   }
//   return 2*x*y/(x + y);
// }

// bool hmean(double x, double y, double *ans)
// {
//   if(x == -y)
//   {
//     *ans = DBL_MAX;
//     return false;

//   }
//   *ans =  x*y*2/(x + y);
//   return true; 
// }
double hmean(double x,double y)
{
  if(x == -y)
    throw "hmean() has bad args: a = -a not allowed";
  else if(x == 1 || y == 1)
    throw Bad_hmean(x, y);
  return 2*x*y/(x + y);
}
double gmean(double x, double y)
{
  if(x < 0 || y < 0)
    throw Bad_gmean(x, y);
  return std::sqrt(x * y);
}
double means(double a, double b)
{
  double am, hm, gm;
  Demo d2("Found in means() func");
  am = (a + b) / 2.0;
  try
  {
    hm = hmean(a,b);
    gm = gmean(a,b);
  }
  catch(Bad_hmean & bg)
  {
    bg.message();
    std::cout << "Caught in means()\n";
    throw;//rethrow the exception
  }
  catch(const char *)
  {
    std::cout << "Caught the string in means func, rethrowing the exception.";
    throw;
  }
  d2.show();
  return (am + gm + hm) / 3.0;

}

