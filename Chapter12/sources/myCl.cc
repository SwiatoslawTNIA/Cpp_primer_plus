#include <iostream>
#include <new>
#include <cstdlib>
   using namespace std;
class MyC
{
public:
   MyC()
   {
      value = 10;
      cout << "<default construcor>";
   }
   MyC(int val)
   {
      value = val;
      cout << "<default constructor, val: " << val << std::endl;
   }
   ~MyC()
   {
      cout << "<default destructor>";
   }
   void display(void)
   {
      cout << "displaying: val: " << this->value;
   }
private:
   int value;

};
MyC obj1;
int main(void)
{
   using std::cout, std::cin, std::cerr;
   char * buffer = new char[512];//allocate 512 bytes on the heap
   MyC *p = new (buffer) MyC();//use a default constructor + place the new class on the heap in the specific memory of the buffer.
   MyC *p2 = new MyC(12);
   p->display(), p2->display();
   {
      cout << "\ncreating an automatic obj: ";
      MyC obj3;
      cout << "\nExiting a temp block";
   }
   cout << "\ndeleting memory for p1 an p2: ";
   delete p2;

   // delete [] buffer;
   //let's try and realloc memory for another obj:
   p->~MyC();
   MyC *p3 = new (buffer) MyC(23);//assign a pointer to the heap, where an obj is stored
   delete [] buffer;
   return 0;
}