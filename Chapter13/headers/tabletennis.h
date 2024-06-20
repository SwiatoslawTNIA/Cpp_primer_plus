#ifndef TABLE_TEN_
#define TABLE_TEN_

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using std::string;
class TableTennisPlayer
{

private:
   string name;
   string surname;
   bool hasTable;
public:
   TableTennisPlayer(const string & n = "none",const  string  & sur = "none" , bool has_t = false);
   void Name(void) const;
   bool HasTable() const {return hasTable;};//an inline func
   void resetTable(bool val) {hasTable = val;};
};
class RatedPlayer : public TableTennisPlayer
{
private:
   unsigned int rating;
public:
   RatedPlayer(unsigned int rat, const string & n = "none", const string & sur = "none", 
   bool hs = false);
   // RatedPlayer(unsigned int rat, const TableTennisPlayer & tp);//a const ref to type TableTennisPlayer class obj
   unsigned int Rating() const {return this->rating;};
   void ResetRating(unsigned int r){this->rating = r;};
};

class RatedYoungPlayer: public RatedPlayer
{
private:
   unsigned int age;
   double greatness;
public:
   RatedYoungPlayer(unsigned int age, double greatness, unsigned int rating_i, 
   const string & n = "none", const string & surname_i = "none", bool hasTable = false);
   RatedYoungPlayer(unsigned int age, unsigned int rating_i);
};
#endif 