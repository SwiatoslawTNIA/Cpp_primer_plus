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
  Brass Piggy("Porcelot Pigg", 381299, 4000.00);
  BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
  Piggy.ViewAccount();
  cout << endl;
  Hoggy.ViewAccount();
  cout << endl;
  cout << "Depositing $1000 into the Hogg Account:\n";
  Hoggy.Deposit(1000.00);
  cout << "New balance: $" << Hoggy.Balance() << endl;
  cout << "Withdrawing $4200 from the Pigg Account:\n";
  Piggy.Withdraw(4200.00);
  cout << "Pigg account balance: $" << Piggy.Balance() << endl;
  cout << "Withdrawing $4200 from the Hogg Account:\n";
  Hoggy.Withdraw(4200.00);
  Hoggy.ViewAccount();
  return 0;
}
