//---------------------------------------------------------------------------------------------------------------------
// c++.cc
//
// <Chapter 16: standard template library>
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




#ifdef PART_2
typedef struct 
  {
    std::string name;
    unsigned short int rating;
  } book;


void display_book(const book & r);
bool sort_book(const book & book1, const book & book2);
#include <algorithm>
#include <ctime>
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
  cout << "Found at: " << index << endl;
  //use the auto_ptr to create an automatic pointer:


  // unique_ptr<int> p(new int);
  // *p = 3333;
  // cout << *p;


  // {
  //   std::unique_ptr<Report> p1(new Report("Something interesting."));
  //   p1->comment();
  // }
  // auto_ptr<string> ps (new string("What a beautiful day.!"));
  // auto_ptr<string> cpy;
  // cpy = ps;
  // auto_ptr<string> movies[5] = 
  // {
  //   auto_ptr<string> (new string("Fight club.")),
  //   auto_ptr<string> (new string("Lord of the rings.")),
  //   auto_ptr<string> (new string("Imitation game.")),
  //   auto_ptr<string> (new string("Pursuit of happiness.")),
  //   auto_ptr<string> (new string("A beautiful mind."))

  // };
  // //transfer the ownership:
  // auto_ptr<string> first_movie = movies[0];
  // for(int i = 0; i < 5;++i)
  // {
  //   cout << movies[i];
  // }
  shared_ptr<string> movies[5] = 
  {
    shared_ptr<string> (new string("Fight club.")),
    shared_ptr<string> (new string("Lord of the rings.")),
    shared_ptr<string> (new string("Imitation game.")),
    shared_ptr<string> (new string("Pursuit of happiness.")),
    shared_ptr<string> (new string("A beautiful mind."))

  };
  //transfer the ownership:
  shared_ptr<string> first_movie = movies[0];
  for(int i = 0; i < 5;++i)
  {
    cout << *movies[i] << endl;
  }
  cout << "The winner is: " << *first_movie;
  
  {
    using std::string;
    std::unique_ptr<string> s1, s2;
    s1 = std::unique_ptr<string>(new string("What a wonderful world!"));
    // s2 = s1;//wrong
    s2 = std::move(s1);
    vector<int> vector1(5);
    const int num = 5;
    
    vector<string> names(num);
    // for(int i = 0; i < num; ++i)
    // {
    //     cout << "Enter the number of book: " << i + 1 << endl;
    //     cin >> names[i];

    // }
    //   cout << "Here are your books: ";

    // for(int j = 0; j < num; ++j)
    // {
    //   names[i];
    // }
    // std::vector<int> integers(10);
    // std::vector<int>::iterator i;//make an iterator to the vector template class
    // i = integers.begin();
    // *i = 10;
    // ++i;
    // std::cout << "The value of the first element of the vector template class:  "<< integers[0];
    // std::vector<double> arr(24);
    // std::vector<double>::iterator start;
    // for(start  = arr.begin(); start != arr.end(); ++start)
    //   cout << *start << endl;

    // arr.erase(arr.begin(), arr.begin() + 4);//erase 3 elements, display the content:
    // std::vector<double>::iterator arr_ref;
    // cout << "The new array: " << std::endl;
    // for(arr_ref = arr.begin(); arr_ref != arr.end();++arr_ref)
    //   cout << *arr_ref << endl;


    // std::vector<int> int_a(10);
    // for(std::vector<int>::iterator i = int_a.begin(); i != int_a.end();++i)
    // {
    //   *i = rand() % 10;
    // }
    // cout << "New vector: ";
    // for(std::vector<int>::iterator b = int_a.begin(); b != int_a.end(); ++b)
    // {
    //   cout << *b<< endl;
    // }
    // random_shuffle(int_a.begin(), int_a.begin() + 5);//shuffle the first 4 elements
    // cout << "After shuffling the first four elements randomly: " << endl;
    // for(std::vector<int>::iterator i = int_a.begin(); i != int_a.end(); ++i)
    // {
    //   cout << *i << endl;
    // }
  }
  //create an array of books, shuffle them, sort them and display them using for_each func, sort() and random_shuffle():
  
  std::vector<book> books;
  cout << "Enter the names of the books: ";
  std::string input;
  srand(time(NULL));
  while(getline(std::cin, input))
  {
    if(input == "quit")
    {
      break;
    }
    book temp_book;
    int rating = 0;

    temp_book.name = input;
    cout << "\nEnter the book rating: " << endl;
    cin >> rating;
    temp_book.rating = static_cast<unsigned short int>(rating);
    books.push_back(temp_book);
    while(cin.get() != '\n')
      continue;
    cout << "\nEnter the next name, quit to quit: ";
  }
  if(books.size() == 0)
    cout << "\nNo books to display!!!";
  else
  {
    while(books.size() < 10)
    {
      //generate a random name for a book: random length of 1-10 + random chars;
      unsigned int name_l = rand() % 10;
      std::string n(name_l, '\0');//using constructor
      for(unsigned int i = 0; i < name_l;++i)
      {
        n[i] = (char)(97 + rand() % 27);//twenty seven letters
      } 
      //provide random rating from 1 to 100:
      unsigned short int temp_rating = static_cast<unsigned short int>(rand() % 101);
      book temp_book = {n, temp_rating};
      books.push_back(temp_book);
    }
    
  }
  for_each(books.begin(), books.end(), display_book);
  cout << "Shuffling the order of the books: " << endl;
  random_shuffle(books.begin(), books.end());
  for_each(books.begin(), books.end(), display_book);
  cout << "Sorting the books: ";
  sort(books.begin(), books.end(), sort_book);
  for_each(books.begin(), books.end(), display_book);
  return 0;
}
void display_book(const book & b)
{
  using std::cout;
  cout << "\nBook's title: " << b.name;
  cout << "\nBook's rating: " << b.rating;
}

bool sort_book(const book & book1, const book & book2)
{
  return (book1.rating > book2.rating)? true: false;
}
#endif

#include <algorithm>
#include <ctime>
//overload the A class with dereferecing and dereferencing write:
class A
{
  public:
    int value;
    enum {INPUT_VALUE = 100};
  public:
    A(int v  = INPUT_VALUE): value(v){}
    ~A(){}
    //write access
    
    const int & operator*(void) const
    { 
      return value;//to reassign the value
    } //if we return the reference to the value, it can be assigned a value
    // const int *operator*(void) const //read access
    // {
    //   return &value;
    // }
    
    // const int & operator->(void) const
    // { 
    //   return value;
    // } //if we return the reference to the value, it can be assigned a value
    // const int *operator->(void) const //read access
    // {
    //   return &value;
    // }
};

inline void output(const std::string & s) {std::cout << s << std::endl;}
#include <iterator>
int main(void)
{
  using namespace std;
  A *obj = new A(13);
  (*obj).value = 4;
  cout << (*obj).value;



  double arr[] = {12.2, 123.2313, 2132.23, -123.23, 2.3, 1};
  sort(&arr[0], &arr[sizeof(arr) / sizeof(arr[0])]);
  for(double & a: arr) cout << a << endl;
  // the ostream_iterator: to reference to the cout:
  ostream_iterator<int, char> out(cout, " ");
  *out++ = 17;
  ostream_iterator<char, char> out_char(cout, " ");
  *out_char++ = '\n';
  // istream_iterator<int, char> in(cin, " ");
  std::string input;
  //the reverse_iterator:
  //implicit use:
  cout << "\nPrinting the string(vector) in an ordinary order: ";
  char a[] = "Something to display.";
  //copy from array to vector:
  std::vector<char> longing(50);
  copy(a, &a[sizeof(a)], longing.begin());//copied, 
  //display:
  ostream_iterator<char, char> a_out(cout, "");
  copy(longing.begin(), longing.end(), a_out);
  cout << endl << "Now printing in the reverse order: ";
  copy(longing.rbegin(), longing.rend(), a_out);
  // copy()
  // *in++ = input;

  string s1[4] = {"fine", "fish", "fashion", "fate"};
  string s2[2] = {"busy", "bats"};
  string s3[2] = {"silly", "singers"};
  vector<string> words(4);
  copy(&s1[0], s1 + 4, words.begin());
  for_each(words.begin(), words.end(), output);
  cout << endl;
  copy(s1, s1 + 2, back_insert_iterator<vector <std::string> >(words));

  for_each(words.begin(), words.end(), output);
  return 0;
}
