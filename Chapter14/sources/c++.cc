//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Explanation of the program ...>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
#include "mem_temp.h"






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
#include "student.h"
#include <valarray>
#include "worker.h"
#include "class_template.h"
#include <cctype>
#include <cstdlib>//for rand and srand
#include <string>
#include <array_t.h>
//a class template that accepts another template:

template< template <typename T> class Thing>//T is a param for the inner template
class Crab
{
private:
  Thing<int> t1;
  Thing<double> t2;
public:
  Crab(){}
  //assuming that a class template Thing has pop and push funsc: 
  bool push(int a, double x){return t1.push(a) && t2.push(x);}
  bool pop(int & a, double & x){return t1.pop(a) && t2.pop(x);}
};




void set(Student & sa, int n);
const int pupils = 3;
const int quizzes = 5;
using std::cout, std::cin, std::endl, std::string;
// int main(void)
// {
//   using namespace std;
  //containment: a.k.a one class is a member of another
  // cout << "Everything works alright.";
  // Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
  // int i;
  // for (i = 0; i < pupils; ++i)
  //   set(ada[i], quizzes);
  // cout << "\nStudent List:\n";
  // for (i = 0; i < pupils; ++i)
  //   cout << ada[i].Name() << endl;
  // cout << "\nResults:";
  // for (i = 0; i < pupils; ++i)
  // {
  //   cout << endl << ada[i];
  //   cout << "average: " << ada[i].Average() << endl;
  // }
  // cout << "Done.\n";
  //private inheritance:
  // const int LIM = 4;
  // Waiter bob("Bob Apple", 314L, 5);
  // Singer bev("Beverly Hills", 522L, 3);
  // Waiter w_temp;
  // Singer s_temp;
  

  // Worker * pw[LIM] = {&bob, &bev, &w_temp, &s_temp};
  // int i;
  // for (i = 2; i < LIM; i++)
  //   pw[i]->Set();
  // for (i = 0; i < LIM; i++)
  // {
  //   pw[i]->Show();
  //   std::cout << std::endl;
  // }
  // const int SIZE = 5;
  // Worker * lolas[SIZE];
  // int ct;
  // for (ct = 0; ct < SIZE; ct++)
  // {
  //   char choice;
  //   cout << "Enter the employee category:\n" << "w: waiter s: singer " 
  //   << "t: singing waiter q: quit\n";
  //   cin >> choice;
  //   while (strchr("wstq", choice) == NULL)
  //   {
  //     cout << "Please enter a w, s, t, or q: ";
  //     cin >> choice;
  //   }
  //   if (choice == 'q')
  //     break;
  //   switch(choice)
  //   {
  //     case 'w':
  //       lolas[ct] = new Waiter;
  //       break;
  //     case 's':
  //       lolas[ct] = new Singer;
  //       break;
  //     case 't':
  //       lolas[ct] = new SingingWaiter;
  //       break;
  //   }
  //   cin.get();
  //   lolas[ct]->Set();
  // }
  // cout << "\nHere is your staff:\n";
  // int i;
  // for (i = 0; i < ct; i++)
  // {
  //   cout << endl;
  //   lolas[i]->Show();
  // }
  // for (i = 0; i < ct; i++)
  //   delete lolas[i];
  // cout << "Bye.\n";


//   Stack<std::string> st;//create an empty stack;
//   char ch;
//   std::string po;
//   cout << "Please enter A to add a purchase order,\n"
//   << "P to process a PO, or Q to quit.\n";
//   while (cin >> ch && std::toupper(ch) != 'Q')
//   {
//     while (cin.get() != '\n')
//       continue;
//     if (!std::isalpha(ch))
//     {
//       cout << '\a';
//       continue;
//     }
//     switch(ch)
//     {
//       case 'A':
//       case 'a': 
//           cout << "Enter a PO number to add: ";
//           cin >> po;
//         if (st.isfull())
//           cout << "stack already full\n";
//         else
//           st.push(po);
//       break;

//       case 'P':
//       case 'p': 
//         if (st.isempty())
//           cout << "stack already empty\n";
//         else 
//         {
//           st.pop(po);
//           cout << "PO #" << po << " popped\n";
//           break;  
//         }
//       cout << "Please enter A to add a purchase order,\n" << "P to process a PO, or Q to quit.\n";
//   }
//   cout << "Bye\n";
//   }
//   return 0;

// }
  // const int Num = 10;
  // srand(time(NULL));//seed
  // std::cout << "Please enter stack_size: " ;
  // int stack_size = 0;
  // cin >> stack_size;
  // Stack<const char *> st(stack_size);

  // const char * in[Num] = {
  //   " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
  //   " 3: Betty Rocker", " 4: Ian Flagranti",
  //   " 5: Wolfgang Kibble", " 6: Portia Koop",
  //   " 7: Joy Almondo", " 8: Xaverie Paprika",
  //   " 9: Juan Moore", "10: Misha Mache"
  // };
  // const char *out[Num];


  // int processed = 0, nextin = 0;
  // while(processed < Num)
  // {
  //   if(st.isempty())
  //     st.push(in[nextin++]);
  //   else if(st.isfull())
  //     st.pop(out[processed++]);
  //   else if(rand() % 2 == 1 && nextin < Num) //50-50 chance + not out of bounds
  //     st.push(in[nextin++]);
  //   else 
  //     st.pop(out[processed++]);
    
  // } 

  //   for(int i = 0; i < Num; ++i)
  //   {
  //     std::cout << out[i] << endl;  
  //   }



  // Pair<std::string, int> ratings[] = 
  // {
  //   Pair<string, int>("James", 44),
  //   Pair<string, int>("Hoho", 11),
  //   Pair<string, int>("Another one", 33),
  // };
  // int joints_count = sizeof(ratings) / sizeof(Pair<string, int>);
  // for(int i = 0; i < joints_count;++i)
  // {
  //   cout << "first variable: " << ratings[i].first() << endl;
  //   cout << "second variable: " <<  ratings[i].second() << endl;
  // }


//   template_class<double> val;
  
//   Crab<Stack> nebula;
// // Stack must match template <typename T> class thing
//   int ni;
//   double nb;
//   cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
//   while (cin>> ni >> nb && ni > 0 && nb > 0)
//   {
//     if (!nebula.push(ni, nb))
//     break;
//   }
//   while (nebula.pop(ni, nb))
//     cout << ni << ", " << nb << endl;
//   cout << "Done.\n";
//   val.show();
//   return 0;
// }
// void set(Student & sa, int n)
// {
//   cout << "Please enter the student's name: ";
//   getline(cin, sa);
//   cout << "Please enter " << n << " quiz scores:\n";
//   for (int i = 0; i < n; i++)
//     cin >> sa[i];
//   while (cin.get() != '\n')
//     continue;
// }



//class template with friend funcs(each template will have the same func (provided that it 
//is of the same type, so I have to provide the defs explicitly:))
// template <typename T>
// class HasFriend
// {
// private:
//   static int status;
//   T item;
// public:
//   HasFriend(T input): item(input) {status++;}//increment the amount of elements
//   ~HasFriend(){status--;}
//   friend void counts(void);
//   friend void report(HasFriend & ref);
// };

// //each specialization has it's own counter(since the template each generated for each type)
// template <typename T>
// int HasFriend<T>::status = 0;//initialize a static variable

// void counts(void)
// {
//   std::cout << "Count: " << HasFriend<int>::status << endl;
//   cout << "Double Count: " <<  HasFriend<double>::status << endl;
// }

// void report(HasFriend<int> & ref)
// {
//   cout << "HasFriend<int>: " << ref.item << endl;

// }
// void report(HasFriend<double> & ref)
// {
//    cout << "HasFriend<double>: " << ref.item << endl;
// }

// int main(int argc, char **argv)
// {
//   cout << "No objects declared: ";
//   counts();
//   HasFriend<int> obj1(44);
//   cout << "After obj1 declared: ";
//   counts();
//   HasFriend<int> obj2(25);
//   cout << "After obj2 declared: ";
//    counts();
//   HasFriend<double> obj3(55);
//   cout << "Ater obj3(double) declared: ";
//   counts();
//   report(obj1);
//   report(obj2);
//   report(obj3);

//   return 0;
// }

// template prototypes
// template <typename T> void counts();
// template <typename T> void report(T &);
// // template class
// template <typename TT>
// class HasFriendT
// {
// private:
//   TT item;
//   static int ct;
// public:
//   HasFriendT(const TT & i) : item(i) {ct++;}
//   ~HasFriendT() { ct--; }
//   friend void counts<TT>();
//   friend void report<>(HasFriendT<TT> &);
// };
// template <typename T>
// int HasFriendT<T>::ct = 0;
// // template friend functions definitions
// template <typename T>
// void counts()
// {
//   cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
//   cout << "template counts(): " << HasFriendT<T>::ct << endl;
// }
// template <typename T>
// void report(T & hf)
// {
//   cout << hf.item << endl;
// }
// int main()
// {
//   counts<int>();
//   HasFriendT<int> hfi1(10);
//   HasFriendT<int> hfi2(20);
//   HasFriendT<double> hfdb(10.5);
//   report(hfi1); // generate report(HasFriendT<int> &)
//   report(hfi2); // generate report(HasFriendT<int> &)
//   report(hfdb); // generate report(HasFriendT<double> &)
//   cout << "counts<int>() output:\n";
//   counts<int>();
//   counts<double>();




// }
/*
a stack of arrays of double:
Stack<std::array<double, 4>, n>//a stack of n arrays, each array has 4 doubles
An array of stacks of pointers to Worker objects:
std::array<Stack<Worker*, n>, m>//an array of m stacks, each stack with n worker pointers
EXERCISE 2*/

// class Frabjous {
// private:
// char fab[20];
// public:
// Frabjous(const char * s = "C++") : fab(s) { }
// virtual void tell() { cout << fab; }
// };
// class Gloam : private Frabjous{
// private:
// int glip;
// public:
// Gloam(int g = 0, const char * s = "C++");
// Gloam(int g, const Frabjous & f);
// void tell();
// };



/*EXERCISE 1*/
// The first member of each Pair object holds
// the vintage years, and the second member holds the numbers of bottles owned for
// the corresponding particular vintage year. For example, the first valarray object of
// the Pair object might hold the years 1988, 1992, and 1996, and the second
// valarray object might hold the bottle counts 24, 48, and 144. It may be conven-
// ient for Wine to have an int member that stores the number of years.Also some
// typedefs might be useful to simplify the coding:
// typedef std::valarray<int> ArrayInt;
// typedef Pair<ArrayInt, ArrayInt> PairArray;
// Thus, the PairArray type represents type Pair<std::valarray<int>,
// std::valarray<int> >. Implement the Wine class by using containment.The class
// should have a default constructor and at least the following constructors:
// // initialize label to l, number of years to y,
// // vintage years to yr[], bottles to bot[]

// Wine(const char * l, int y, const int yr[], const int bot[]);
// // initialize label to l, number of years to y,
// // create array objects of length y
// Wine(const char * l, int y);

// The Wine class should have a method GetBottles() that, given a Wine object with
// y years, prompts the user to enter the corresponding number of vintage years and
// bottle counts.A method Label() should return a reference to the wine name.A
// method sum() should return the total number of bottles in the second
// valarray<int> object in the Pair object.
// The program should prompt the user to enter a wine name, the number of ele-
// ments of the array, and the year and bottle count information for each array ele-
// ment.The program should use this data to construct a Wine object and then display
// the information stored in the object.
// class Wine
// {
// private:
//   int year_n;//to store the number of years;
//   std::string label;
//   //to set the values of each array, we will store it in the current vars:
//   Pair<valarray<int>, valarray<int> > pair_obj;//
//   //create a Pair object from a Pair template, that takes two arrays of type valarray<int>
// public:
//   Wine():year_n(0), label("text"), pair_obj(valarray<int>() , valarray< int>()) {year_n++;}//just one int_initialization
  
//   Wine(const char * l, int y, const int yr[], const int bot[])
//   :label(l), pair_obj(valarray<int>(yr, y), valarray<int>(bot, y)), year_n(y){}
  
//   Wine(const char * l, int y)
//   : year_n(y), label(l), pair_obj(valarray<int>(y), valarray<int>(y)) {}
  
//   void GetBottles()
//   {
//     using namespace std;
//     for(int i = 0; i < year_n; ++i)
//     {
//       cout << "Year: " ;
//       cin >> pair_obj.first()[i];
//       cout << "N of bottles: ";
//       cin >> pair_obj.second()[i];//since the func returns a ref, we can assign value to it
//       cout << endl;
//     }
//   }
//   int sum(void) const {return pair_obj.second().size();}
//   ~Wine(){--year_n;}
//   void Show(void) const
//   {
//     cout << "\t\t\tWine name: " << label;
//     for(int i = 0; i < year_n; ++i)
//     {
//       cout << "Year: " << pair_obj.first()[i] << ", " << "bottles: " << pair_obj.second()[i] << endl;
//     }
//   }

//   const std::string & Label(void) const {return label;}
// };

// int main(void)
// {
//   using std::cin;
//   using std::cout;
//   using std::endl;
//   cout << "Enter name of wine: ";
//   char lab[50];


//   cin.getline(lab, 50);
//   cout << "Enter number of years: ";
//   int yrs;
//   cin >> yrs;
//   Wine holding(lab, yrs); // store label, years, give arrays yrs elements
//   holding.GetBottles();
//   // solicit input for year, bottle count
//   holding.Show();
//   // display object contents
//   const int YRS = 3;
//   int y[YRS] = {1993, 1995, 1998};
//   int b[YRS] = { 48, 60, 72};
//   // create new object, initialize using data in arrays y and b
//   Wine more("Gushing Grape Red",YRS, y, b);
//   more.Show();
//   cout << "Total bottles for " << more.Label() // use Label() method
//   << ": " << more.sum() << endl;
//   // use sum() method
//   cout << "Bye\n";
//   return 0;
// }


#ifdef EXERCISE_2

//EXERCISE 2
class Wine: private Pair<std::valarray<int>, std::valarray<int>>
{
private:
  int year_n;//to store the number of years;
  std::string label;
  //to set the values of each array, we will store it in the current vars:
  // Pair<valarray<int>, valarray<int> > pair_obj;//
  //create a Pair object from a Pair template, that takes two arrays of type valarray<int>
public:
  Wine():Pair(valarray<int>() , valarray< int>()), year_n(0), label("text"){year_n++;}//just one int_initialization
  
  Wine(const char * l, int y, const int yr[], const int bot[])
  :Pair(valarray<int>(yr, y), valarray<int>(bot, y)), year_n(y), label(l){}
  
  Wine(const char * l, int y)
  : Pair(valarray<int>(y), valarray<int>(y)), year_n(y), label(l) {}
  
  void GetBottles()
  {
    using namespace std;
    for(int i = 0; i < year_n; ++i)
    {
      cout << "Year: " ;
      cin >> first()[i];
      cout << "N of bottles: ";
      cin >> second()[i];//since the func returns a ref, we can assign value to it
      cout << endl;
    }
  }
  int sum(void) const {return second().size();}
  ~Wine(){--year_n;}
  void Show(void) const
  {
    cout << "\t\t\tWine name: " << label;
    for(int i = 0; i < year_n; ++i)
    {
      cout << "Year: " << first()[i] << ", " << "bottles: " << second()[i] << endl;
    }
  }

  const std::string & Label(void) const {return label;}
};



int main(void)
{
  using std::cin;
  using std::cout;
  using std::endl;
  cout << "Enter name of wine: ";
  char lab[50];


  cin.getline(lab, 50);
  cout << "Enter number of years: ";
  int yrs;
  cin >> yrs;
  Wine holding(lab, yrs); // store label, years, give arrays yrs elements
  holding.GetBottles();
  // solicit input for year, bottle count
  holding.Show();
  // display object contents
  const int YRS = 3;
  int y[YRS] = {1993, 1995, 1998};
  int b[YRS] = { 48, 60, 72};
  // create new object, initialize using data in arrays y and b
  Wine more("Gushing Grape Red",YRS, y, b);
  more.Show();
  cout << "Total bottles for " << more.Label() // use Label() method
  << ": " << more.sum() << endl;
  // use sum() method
  cout << "Bye\n";
  return 0;
}
#endif
#ifdef EXERCISE_3
//EXERCISE 3
#include "qtempl.h"
int main(void)
{
  int integer = 10, int2 = -50;


  Queue<int, 10> queue1 = Queue<int, 10>(integer);
  queue1.show();
  queue1 + int2;
  queue1.show();
  int j = 1;
  for(int i = 0; i < 5; ++i)
  {
    queue1 + j;
    ++j;

  }
  queue1.pop(integer);
  queue1.show();
  //it should work(currently Worker is pure template function: )
  // Queue<Worker *, 5> WorkerQueue;
  // Worker obj[5] = 
  // {
  //   {"James", 124123},
  //   {"Morris", 124123},
  //   {"Hulu", 9999},
  //   {"Jana", 123123},
  //   {"Cuvie", -123},
  // };
  // for(int i = 0; i < 5;++i)
  // {
  //   WorkerQueue[i] = &obj[i];
  // }
  //display the values:

  return 0;
}
#endif

#ifdef EXERCISE_4
//EXERCISE4:
// A Person class holds the first name and the last name of a person. In addition to its
// constructors, it has a Show() method that displays both names.A Gunslinger class
// derives virtually from the Person class. It has a Draw() member that returns a type
// double value representing a gunslinger’s draw time.The class also has an int mem-
// ber representing the number of notches on a gunslinger’s gun. Finally, it has a
// Show() function that displays all this information.

class Person
{
private:
  std::string first_name;
  std::string last_name;
public:
  Person(): first_name("Bob"), last_name("Sikorski"){}
  Person(const char * n, const char* l): first_name(n), last_name(l){}
  Person(const char * n): first_name(n), last_name("Dziuba"){}
  virtual void Show(void) const;

};
class Gunslinger: virtual public Person//public virtual Person also possible
{
private:
  double draw;
  int notches;
public:
  //constructors:
  Gunslinger(const char * n, const char *l, double d, int nchs): Person(n, l), draw(d), notches(nchs){}
  Gunslinger(const char * n, const char *l): Person(n, l), draw(0.0), notches(0){}
  Gunslinger(double d, int ns): Person(), draw(d), notches(ns) {}
  Gunslinger(): Person(), draw(0.0), notches(0){}//default constructor

  double Draw(void) const {return draw;}
  virtual void Show(void) const override;
};
// A PokerPlayer class derives virtually from the Person class. It has a Draw() mem-
// ber that returns a random number in the range 1 through 52, representing a card
// value. (Optionally, you could define a Card class with suit and face value members
// and use a Card return value for Draw().) The PokerPlayer class uses the Person
// show() function.The BadDude class derives publicly from the Gunslinger and
// PokerPlayer classes. It has a Gdraw() member that returns a bad dude’s draw time
// and a Cdraw() member that returns the next card drawn. It has an appropriate
// Show() function. Define all these classes and methods, along with any other neces-
// sary methods (such as methods for setting object values) and test them in a simple
// program similar to that in Listing 14.12.
class PokerPlayer: virtual public Person
{
int draw;
public:
  PokerPlayer(): Person()
  {
    srand(time(NULL));//seed
    draw = rand() % 53; 
  }
  PokerPlayer(const char * n, const char* l):Person(n, l){}
  PokerPlayer(const char * n): Person(n){}
  int get_rand_N(void) const {return draw;}

  void Draw(void) 
  {
    srand(time(NULL));//seed
    draw = rand() % 53; 
  }
};
class BadDude: public Gunslinger, public PokerPlayer
{
private:
  double draw_time;
public:
  BadDude(const char *n, const char *s, double dr, double ntchs, double draw_t):
  Person(n,s), Gunslinger(dr, ntchs), draw_time(draw_t) {}

  //name, surname, draw(gunslinger), notches(Gunslinger), draw_time(BadDude)
  double Gdraw(void) const { return draw_time;}
  int Cdraw(void) const {return get_rand_N();}//calss the PokerPlayer class
};

void Person::Show(void) const
{
  cout << "Name: " << first_name << ", surname: " << last_name << endl;
}

void Gunslinger::Show(void) const
{
  Person::Show();
  cout << "Notches: " << notches << ", draw: " << draw;
}
int main(void)
{
  Person p1, p2;
  Gunslinger g1, g2;
  PokerPlayer po1, po2("Loo", "poo");
  BadDude bd1("Me", "AlsoMe", 2132.2, 3, 32.3222);
  p1.Show();
  p2.Show();
  g1.Show();
  g2.Show();
  po1.Show();
  po2.Show();
  bd1.Show();
  clock_t current_t = time(NULL);
  // fflush(std::cout);
  while(time(NULL) - current_t < 2)
    ;
  cout << "After 2 seconds:: ";
  return 0;
}
#endif


class abstr_emp
{
private:
  std::string fname;
  std::string lname;
  std::string job;
  // abstr_emp's first name
  // abstr_emp's last name
public:
  abstr_emp(): fname("Terminator"), lname("T100"), job("Extermination"){}
  abstr_emp(const std::string & fn, const std::string & ln,
  const std::string & j): fname(fn), lname(ln), job(j)
  {}
  virtual void ShowAll() const
  {
    cout << "Name: " << fname << endl;
    cout << "Last name: " << lname << endl;
    cout << "Job: " << job << endl;
  }
  // labels and shows all data
  virtual void SetAll()
  {
    cout << "Please enter data accordingly:" << endl;
    cout << "Name: ";
    cin >> fname;
    cout << "\nSurname: ";
    cin >> lname;
    cout << "\nJob: ";
    cin >> job;
  }
  // prompts user for values
  friend std::ostream &
  operator<<(std::ostream & os, const abstr_emp & e)
  {
    os << "First name: " << e.fname << endl;
    os << "Last name: " << e.lname << endl;
    return os;
  }
  // just displays first and last name
  virtual ~abstr_emp() = 0;//virtual base class
  // virtual base class
  //copy constructor:
  abstr_emp(const abstr_emp & r)
  {
    fname = r.fname;
    lname = r.lname;
    job = r.job;
  }
};

class employee : public abstr_emp
{
public:
  employee(): abstr_emp(){}
  employee(const std::string & fn, const std::string & ln,
  const std::string & j): abstr_emp(fn,ln, j){}
  virtual void ShowAll() const
  {
    abstr_emp::ShowAll();
  }
  virtual void SetAll()
  {
    abstr_emp::SetAll();
  }
};

class manager: virtual public abstr_emp
{
private:
  int inchargeof;
  // number of abstr_emps managed
protected:
  int InChargeOf() const { return inchargeof; } // output
  int & InChargeOf() { return inchargeof; }
  // input
public:
  manager(): abstr_emp(), inchargeof(0){}
  manager(int val): abstr_emp(), inchargeof(val){}
  manager(const std::string & fn, const std::string & ln,
  const std::string & j, int ico = 0): abstr_emp(fn, ln, j), inchargeof(ico){}
  manager(const abstr_emp & e, int ico): abstr_emp(e), inchargeof(ico){}

  manager(const manager & m): abstr_emp(m)
  {
    inchargeof = m.inchargeof;
  } 
  virtual void ShowAll() const
  {
    abstr_emp::ShowAll();
    cout << "Inchargeof: " << inchargeof << endl;
  }
  virtual void SetAll()
  {
    abstr_emp::SetAll();
    cout << "Enter the inchargeof value: " << endl << "> ";
    cin >> inchargeof;
  }
};
class fink: virtual public abstr_emp
{
private:
  std::string reportsto;
  // to whom fink reports
protected:
  const std::string ReportsTo() const { return reportsto; }
  std::string & ReportsTo(){ return reportsto; }
public:
  fink(): abstr_emp(), reportsto("Donkichod"){}
  fink(const std::string & fn, const std::string & ln,
  const std::string & j, const std::string & rpo): abstr_emp(fn, ln, j), reportsto(rpo){}
  fink(const abstr_emp & e, const std::string & rpo): abstr_emp(e), reportsto(rpo){}
  fink(const std::string & s):abstr_emp(), reportsto(s){}


  fink(const fink & e): abstr_emp(e)//call a parent copy constructor
  {
    reportsto = e.reportsto;
  }
  virtual void ShowAll() const
  {
    abstr_emp::ShowAll();
    cout << "Reportsto value: " << reportsto << endl;
  }
  virtual void SetAll()
  {
    abstr_emp::SetAll();
    cout << "Enter the reporstTo value: " << endl << "> ";
    cin >> reportsto;
  }
};
class highfink: public manager, public fink // management fink
{
public:
  highfink(): abstr_emp(), manager(), fink(){}
  highfink(const std::string & fn, const std::string & ln, const std::string & j, 
  const std::string & rpo, int ico): abstr_emp(fn, ln, j), manager(ico), fink(rpo){}

  highfink(const abstr_emp & e, const std::string & rpo, int ico)
  :abstr_emp(e), manager(ico), fink(rpo){}
  highfink(const fink & f, int ico): abstr_emp(), manager(ico), fink(f){}
  highfink(const manager & m, const std::string & rpo): abstr_emp(), manager(m), 
  fink(rpo)
  {}
  highfink(const highfink & h): abstr_emp(h), manager(h), fink(h){}
  virtual void ShowAll() const
  {

  }
  virtual void SetAll()
  {
    fink::SetAll();
  }
};
int main(void)
{
  employee em("Trip", "Harris", "Thumper");
  cout << em << endl;
  em.ShowAll();
  manager ma("Amorphia", "Spindragon", "Nuancer", 5);
  cout << ma << endl;
  ma.ShowAll();
  fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
  cout << fi << endl;
  fi.ShowAll();
  highfink hf(ma, "Curly Kew"); // recruitment?
  hf.ShowAll();
  cout << "Press a key for next phase:\n";
  cin.get();
  highfink hf2;
  hf2.SetAll();
  cout << "Using an abstr_emp * pointer:\n";
  abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
  for (int i = 0; i < 4; i++)
    tri[i]->ShowAll();
  return 0;
}

