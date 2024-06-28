//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Chapter15>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
#include "sales.h"
#include <typeinfo>
#include <stdexcept>
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
#include <new>//for the bad_alloc exception
#include <exception>//for exceptions 

#ifdef PART_1
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
#endif
#ifdef PART_2
struct Big
{
  double stuff[20000];
};
int main(void)
{
  using std::cout, std::string, std::cin, std::endl;
  // try
  // {
  //   Big *p = new Big[10000];//10^10 bytes * 2 * 6
  //   cout << "Allocated successfully.";
  // }
  // catch(bad_alloc & ba)
  // {
  //   cout << "Bad_alloc exception caught.";
  //   cout << ba.what();
  //   exit(EXIT_FAILURE);//terminate
  // }
  // delete []p;
  double vals1[12] =
  {
  1220, 1100, 1122, 2212, 1232, 2334,
  2884, 2393, 3302, 2922, 3002, 3544
  };
  double vals2[12] =
  {
  12, 11, 22, 21, 32, 34,
  28, 29, 33, 29, 32, 35
  };
  Sales sales1(2011, vals1, 12);
  LabeledSales sales2("Blogstar",2012, vals2, 12 );

  cout << "First try block: " << endl;
  try 
  {
    int i = 0;
    cout << "Year = " << sales1.Year() << endl;
    for(i = 0; i < 12; ++i)
    {
      cout << sales1[i] << ' ';
      if (i % 6 == 0)
        cout << endl;

    }
    cout << "Label = " << sales2.Label() << endl;
    for (i = 0; i <= 12; ++i)
    {
    cout << sales2[i] << ' ';
    if (i % 6 == 5)
    cout << endl;
    }
    cout << "End of try block 1.\n";
  }
  catch(LabeledSales::Labeled_Bad_index & obj)
  {
    cout << obj.lbl_value();
  }
  catch(Sales::Bad_index & b)
  {
    cout << b.str_val();
    cout << "The index: " << b.bi_val();
  }
  cout << "\nNext try block:\n";
try
{
  sales2[2] = 37.5;
  sales1[20] = 23345;
  cout << "End of try block 2.\n";
}
catch(LabeledSales::Labeled_Bad_index & bad)
{
  cout << bad.lbl_value();
  cout << "Company: " << bad.lbl_value() << endl;
  cout << "bad index: " << bad.bi_val() << endl;
}
catch(Sales::Bad_index & bad)
{
  cout << bad.str_val();
  cout << "bad index: " << bad.bi_val() << endl;
}
cout << "done\n";

  return 0;

}
#endif
class A{
  public:
    int a;
  public:
    A(int in = 0): a(in){}
    virtual void print(void) const
    {
      std::cout << "<Class A>";
      std::cout << "A value: " << a; 
    }
};
class B: public A
{
  public:
    virtual void print(void) const
    {
      std::cout << "<Class B>";
    }
};
class C: public B
{
  public:
    virtual void print(void) const
    {
      std::cout << "<Class C>";
    }
};

A *randomClass(void) 
{
  int answer = rand() % 3;
  A* p = nullptr;
  switch(answer)
  {
    case(0): 
    {
      p = new A();
      break;
    }
    case(1): 
    {
      p = new B();
      break;
    }
    case(2): 
    {
      p = new C();
      break;
    }
    default: p = nullptr;
  }
  return p;
}






class class1
{
public: 
  //make class2 friend:
  friend class class2;//we don't have to make a predecl, since we delcare here that class2 is a class

  void show(void) const
  {
    std::cout << "Class 1_0";
  }

  void show2(void) const;
  
private:
  void show3(void) const
  {
    std::cout << "Class 1_2";
  }
};
class class2
{
public: 
  class2(int a_i = 9): a(a_i){}
  friend void class1::show2(void) const;//make class one func show2 a friend
  void show(void) const
  {
    std::cout << "Class 1_0";
    //it needs an obj instance to operate on: 
    class1 obj1;
    obj1.show();
    obj1.show2();
    obj1.show3();
  }
  void show2(void) const
  {
    std::cout << "Class 1_1";
  }
  void show3(void) const
  {
    std::cout << "Class 1_2";
  }
private:
  int a;
};

void class1::show2(void) const
{
    std::cout << "Class 1_1";
    class2 o;
    std::cout << "Val a: " << o.a;
}




class bad_err: public std::exception
{
public:   
  const char * what(void) {return "Bad arg, detected in bad_err";};
};
class bad_err2: public std::exception
{
public:   
  const char * what(void) {return "Bad arg, detected in bad_err2";};
};
int main(void)
{

  using namespace std;
  cout << "Enter a number: ";
  try
  {
    int n = 0;
    cin >> n;
    if(n > 0)
      throw logic_error("A true mastership.");
    else 
      throw bad_err2();
  }
  catch(bad_err2 & er)
  {
    cout << "Caught bad_err2";
  }
  catch(bad_err & er)
  {
    cout << "Caught bad_err";
  }
  catch(logic_error & error)
  {
    cout << error.what();
  }







  srand(time(NULL));//seed
  // A *p = new A;
  // A *p_b = new B;
  // A *p_c = new C;

  // C *p1 = (C *) p_c;
  // C *p2 = (C * ) p;//a pointer to A
  // B * p3 = (C * ) p_c;

  // delete p;
  // delete p_b;
  // delete p_c;
  const A* p_to_a = new A();
  p_to_a->print();
  A* non_const_p = const_cast<A*>(p_to_a);
  non_const_p->a = 24;
  p_to_a->print();
  delete non_const_p;
  std::cout << "Now trying to cast pointer to the const: ";
  //  A* obj = new A();
  //  obj->print();
  //  obj->a = 24;
  // //  obj->print();
  //  const A* obj2 = const_cast<const A*>(obj);
  // //  obj2->a = 22; 
  // for(int i = 0; i < 5; ++i)
  // {
  //   std::cout << "\nRound: " << i + 1 << std::endl;
  //   p_to_a = randomClass();
  //   // p_to_a->print(); 
  //   if(p_to_b = dynamic_cast<B *>(p_to_a))
  //   {
  //     p_to_b->print();
  //     std::cout << "Class name: " << typeid(*p_to_b).name() << std::endl;
  //   }
  //   delete p_to_a;
  // }

  //convert n to hex:
  long va = 0xA224B118;//hex
  struct data{short a;short b;};
  data *p = reinterpret_cast<data *> (&va);
  std::cout << "FIrst two bytes: " << p->a;



  class1 obj1;
  class2 obj;
  obj1.show2();
  obj.show();
  return 0;
}
