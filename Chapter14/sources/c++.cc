//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Explanation of the program ...>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
#include "valarray"

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
void set(Student & sa, int n);
const int pupils = 3;
const int quizzes = 5;
using std::cout, std::cin, std::endl;
int main(void)
{
  using namespace std;
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


  Stack<std::string> st;//create an empty stack;
  char ch;
  std::string po;
  cout << "Please enter A to add a purchase order,\n"
  << "P to process a PO, or Q to quit.\n";
  while (cin >> ch && std::toupper(ch) != 'Q')
  {
    while (cin.get() != '\n')
      continue;
    if (!std::isalpha(ch))
    {
      cout << '\a';
      continue;
    }
    switch(ch)
    {
      case 'A':
      case 'a': 
          cout << "Enter a PO number to add: ";
          cin >> po;
        if (st.isfull())
          cout << "stack already full\n";
        else
          st.push(po);
      break;

      case 'P':
      case 'p': 
        if (st.isempty())
          cout << "stack already empty\n";
        else 
        {
          st.pop(po);
          cout << "PO #" << po << " popped\n";
          break;  
        }
      cout << "Please enter A to add a purchase order,\n" << "P to process a PO, or Q to quit.\n";
  }
  cout << "Bye\n";
  }
  return 0;

}

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
