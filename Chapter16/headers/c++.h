//---------------------------------------------------------------------------------------------------------------------
// c++.h
//
// <Explanation of the program ...>
// <... May have multiple lines.>
//
//---------------------------------------------------------------------------------------------------------------------
//
#include <iostream>
#include <string>
#include <cstring>//include string funcs
#include <fstream>
#include <cstdlib>//srand
#include <ctime>
#include <cctype>
#include <memory>
#include <typeinfo>
#include <vector>
class Report
{
private: 
   std::string str;
public: 
   Report(const std::string & s): str(s){std::cout << "<Created obj>" << typeid(this).name();}
   ~Report(){std::cout << "Obj destroyed.";}
   void comment(void) const {std::cout << str << '\n';}
};