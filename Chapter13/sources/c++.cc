//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Inheritance...>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
// #include "tabletennis.h"
#include "brass.h"
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
  
#include "implement.h"
#include "cd.h"
#include "vintage.h"
void Bravo(const Cd & disk);
int main(void)
  {
  using namespace std;
  // TableTennisPlayer player1("Chuck", "Blizzard", true);
  // TableTennisPlayer player2("Tara", "Boomdea", false);
  // player1.Name();
  // if(player1.HasTable())
  //   cout << ": has table\n";
  // else
  //   cout << ": hasn't table\n";
  // player2.Name();
  // if(player2.HasTable())
  //   cout << ": has table\n";  
  // else
  //   cout << ": hasn't table\n";
  
  // //
  // RatedPlayer new_player(300, "A", "B", true);
  // std::cout << std::endl << "Creating a ratedYoungPlayer: ";
  // RatedYoungPlayer young(200, 300);
  // std::cout << std::endl;
  // new_player.Name();
  // young.Name();
  // if(young.HasTable())
  // {
  //   std::cout << "young obj has hasTable var defined to true";
  // }
  // else std::cout <<"young obj has hasTable var defined to false";
  // // else std::cout << "young obj has hasTable var define to false";
  

  //brass: 

  using std::cout;
  using std::endl;
  // Brass Piggy("Porcelot Pigg", 381299, 4000.00);
  // BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
  // Piggy.ViewAccount();
  // cout << endl;
  // Hoggy.ViewAccount();
  // cout << endl;
  // cout << "Depositing $1000 into the Hogg Account:\n";
  // Hoggy.Deposit(1000.00);
  // cout << "New balance: $" << Hoggy.Balance() << endl;
  // cout << "Withdrawing $4200 from the Pigg Account:\n";
  // Piggy.Withdraw(4200.00);
  // cout << "Pigg account balance: $" << Piggy.Balance() << endl;
  // cout << "Withdrawing $4200 from the Hogg Account:\n";
  // Hoggy.Withdraw(4200.00);
  // Hoggy.ViewAccount();

  // ABC * p_clients[4];
  // std::string temp;
  // long tempnum;
  // double tempbal;
  // char kind;
  // for (int i = 0; i < 4; i++)
  // {
  //   cout << "Enter client's name: ";
  //   getline(cin,temp);
  //   cout << "Enter client's account number: ";
  //   cin >> tempnum;
  //   cout << "Enter opening balance: $";
  //   cin >> tempbal;
  //   cout << "Enter 1 for Brass Account or "
  //   << "2 for BrassPlus Account: ";
  //   while (cin >> kind && (kind != '1' && kind != '2'))
  //     cout <<"Enter either 1 or 2: ";
  //   if (kind == '1')
  //     p_clients[i] = new Brass(temp, tempnum, tempbal);
  //   else
  //   {
  //     double tmax, trate;
  //     cout << "Enter the overdraft limit: $";
  //     cin >> tmax;
  //     cout << "Enter the interest rate "
  //     << "as a decimal fraction: ";
  //     cin >> trate;
  //     p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
  //   }
  //     while (cin.get() != '\n')
  //       continue;
  //     }
  //     cout << endl;
  //     for (int i = 0; i < 4; i++)
  //     {
  //       p_clients[i]->ViewAccount();
  //       cout << endl;
  //     }
  //     for (int i = 0; i < 4; i++)
  //     {
  //       delete p_clients[i]; // free memory
  //     }
  // cout << "Done.\n";
  // Name n1("James", 23);
  // Name n2 = n1;
  // Person p1 = Person("Jojo", 34, "Corniejski");
  // cout << "showing n1: \n";
  // n1.show();
  // cout << "showing n2: \n";

  // n2.show();
  // cout << "showing p1: \n";
  // p1.show();//the default version of the func is used for both classes, 
  // p1.show(); 
  // cout << "Terminating..";
  // Name * n3 = &p1;
  
  // n3->show();//the methods for Person is gonna be used here, because virtual
  // Name *four = new Person("Lol");
  // four->show();
  // delete four; //if virtual is not defined, it calls the Name destructor, which is a problem,
  // //since the Person allocated memory

  //EXERCISES: 
  //1+2:
  Cd c1("Beatles", "Capitol", 14, 35.5);
  Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
  "Alfred Brendel", "Philips", 2, 57.17);
  Cd *pcd = &c1;
  cout << "Using object directly:\n";
  c1.Report();
  // use Cd method
  c2.Report();
  // use Classic method
  cout << "Using type cd * pointer to objects:\n";
  pcd->Report(); // use Cd method for cd object
  pcd = &c2;
  pcd->Report(); // use Classic method for classic object
  cout << "Calling a function with a Cd reference argument:\n";
  Bravo(c1);
  Bravo(c2);
  cout << "Testing assignment: ";
  Classic copy;
  copy = c2;
  copy.Report();
  cout << endl << endl;



  Port p1;
  p1.Show();
  cout << p1;


  VintagePort v1;
  Port p2;
  p1.Show();
  cout << v1;

  return 0;
}
void Bravo(const Cd & disk)
{
  disk.Report();
}