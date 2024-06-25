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
template <typename T> void counts();
template <typename T> void report(T &);
// template class
template <typename TT>
class HasFriendT
{
private:
  TT item;
  static int ct;
public:
  HasFriendT(const TT & i) : item(i) {ct++;}
  ~HasFriendT() { ct--; }
  friend void counts<TT>();
  friend void report<>(HasFriendT<TT> &);
};
template <typename T>
int HasFriendT<T>::ct = 0;
// template friend functions definitions
template <typename T>
void counts()
{
  cout << "template size: " << sizeof(HasFriendT<T>) << "; ";
  cout << "template counts(): " << HasFriendT<T>::ct << endl;
}
template <typename T>
void report(T & hf)
{
  cout << hf.item << endl;
}
int main()
{
  counts<int>();
  HasFriendT<int> hfi1(10);
  HasFriendT<int> hfi2(20);
  HasFriendT<double> hfdb(10.5);
  report(hfi1); // generate report(HasFriendT<int> &)
  report(hfi2); // generate report(HasFriendT<int> &)
  report(hfdb); // generate report(HasFriendT<double> &)
  cout << "counts<int>() output:\n";
  counts<int>();
  counts<double>();
}

