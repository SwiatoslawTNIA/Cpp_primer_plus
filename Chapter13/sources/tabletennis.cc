#include <tabletennis.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
void TableTennisPlayer::Name(void) const
{
   std::cout<<  this->name;
}
TableTennisPlayer::TableTennisPlayer( const string & n,  const string & sur_n, bool val):
name(n), surname(sur_n), hasTable(val)
{
   std::cout << "<TableTennisPlayer constructor>";
}; 
   //constructors must be added:


RatedPlayer::RatedPlayer(unsigned int rating_i, const string & name_i, const string & surname_i, 
   bool hasTable_i): TableTennisPlayer(name_i, surname_i, hasTable_i)
{
   std::cout << "<RatedPlayer constructor>";
   rating = rating_i;
}

RatedYoungPlayer::RatedYoungPlayer(unsigned int age_i, double greatness_i, unsigned int rating_i, 
   const string & name_i, const string & surname_i, bool hasTable_i):
      RatedPlayer(rating_i, name_i, surname_i, hasTable_i), age(age_i), greatness(greatness_i)
{
   std::cout << "<RatedYoungPlayer constructor>";
}
//constructor for two args:
RatedYoungPlayer::RatedYoungPlayer(unsigned int age_i, unsigned int rating_i)
: RatedPlayer(rating_i), age(age_i)
{
   std::cout << "<RatedYoungPlayer constructor>";

}



