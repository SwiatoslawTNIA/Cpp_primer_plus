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
  const int LIM = 4;
  Waiter bob("Bob Apple", 314L, 5);
  Singer bev("Beverly Hills", 522L, 3);
  Waiter w_temp;
  Singer s_temp;
  
  Worker * pw[LIM] = {&bob, &bev, &w_temp, &s_temp};
  int i;
  for (i = 2; i < LIM; i++)
    pw[i]->Set();
  for (i = 0; i < LIM; i++)
  {
    pw[i]->Show();
    std::cout << std::endl;
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
