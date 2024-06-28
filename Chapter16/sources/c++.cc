//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Chapter 16: standard template library>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include "c++.h"
#include <string>
#include <cstring>//include string funcs
#include <fstream>
#include <cstdlib>//srand
#include <ctime>
#include <cctype>
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


#ifdef PART_1

const int NUM = 26;
const std::string wordlist[NUM] = {"apiary", "beetle", "cereal",
"danger", "ensign", "florid", "garage", "health", "insult",
"jackal", "keeper", "loaner", "manage", "nonce", "onset",
"plaid", "quilt", "remote", "stolid", "train", "useful",
"valid", "whence", "xenon", "yearn", "zippy"};
int main(void)
{
  srand(time(NULL));

  using namespace std;
  // string s1, s2 = "something";
  // cout << s2;
  // cout << string::npos;

  // ifstream fin;
  // fin.open("tobuy.txt");
  // if(fin.isopen() == false)
  // {
  //   cerr << "Can't open file. Bye.\n";
  //   exit(EXIT_FAILURE);
  // }
  // string  item;
  // int count = 0;
  // getline(fin, item, ':');
  //std::getline() method:
  // std::string s;

  // std::getline(std::cin, s, ':');//can't be used with const char *
  // cout << s;
  cout << "Will you play a word game? <y/n>?";
  char in;
  cin >> in;
  unsigned int attempts = 0;
  in = tolower(in);
  while(in == 'y')
  {
    string word = wordlist[std::rand() % NUM], guessed_letters;
    unsigned short guessed = 0, length = word.length();
    if(attempts > 10)
    {
      cout << "\nI guess better luck next time. Bye...";
      break;
    }
    char character;
    string guess(length, '-');
    cout << "Guess the word. It has " << length << " letters. You have 10 attemps to"
    << "guess each letter. Guess the letter: ";
    while(guessed < length && attempts++ < 10)//when the condition is evaluated for the 
    //last time, the val of attempts increases to eleven, so we have to check for that value
    //not for the value ten.
    {
      cin >> character;
      character  = tolower(character);//tolowercase the char
      std::cin.clear();
      std::cin.ignore(10000, '\n');
        if(guessed_letters.find(character) != string::npos)
        {
          cout << "Hey! You've already guessed that letter! Try another: ";
          continue;
        }
        else
        {
          guessed_letters += character;//add the char to the guessed letters
        }

        if(word.find(character) != string::npos)
        {
          cout << "Good guess";
          for(int i = 0; i < static_cast<int>(length);++i)
          {
            if(word[i] == character)
            {
              guess[i] = character;//then reset the character for the guess
              guessed++;//we must update the guessed value
            }
          }
        }
      else
      {
        cout << "\nSorry, the letter is not in the word. Please try again: ";
      }
      if(word == guess)
      {
        cout << "Congrats! You guessed it. The word is: " << word << " Wanna play another round?<y/n>";
        cin >> in;        
        break;
      }
      cout << "\nHere is my word now: " << guess;
      cout << "\nGuess the letter: ";
    }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  return 0;
}
#endif
int main(void)
{
  using namespace std;
  std::string s1, s2("Some text example.");
  cout << "Size: s1: " << s1.size() << " , s2: " << s2.size() << endl;
  cout << "Capacity: s1: " << s1.capacity() << " , s2: " << s2.capacity() << endl;
  cout << "Increasing the capacity : ";
  s1.reserve(100);
  cout << "New size: s1: " << s1.capacity() << ", s2: " << s2.capacity() << endl;
  int index = strcspn(s2.c_str(), "e");
  cout << "Found at: " << index;



  return 0;
}




