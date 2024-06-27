//nested classes:
#include <iostream>
class Queue
{//a nested class, can be used only locally(in this case private)
private:
   int private_1;
protected:
   int protected_1;
public:
   int public_1;
   class Node//it's known only to the Queue obj, since it's declared private
   {
      private:
         int nested_private;
      protected:
         int nested_protected;
      public:
          int nested_public;
          void display(void) const
          {
            std::cout << "Private mem of the outer class: "  << Queue::private_1;
            std::cout << "Protected mem of the outer class: "  << Queue::protected_1;
            std::cout << "Public mem of the outer class: "  << Queue::public_1;
          }
         Node(int n1 = 4, int n2 = 5, int n3 =  6): nested_private(n1), nested_protected(5), nested_public(6){}
   };
    Node n1;  //default values;
   Queue(int n1 = 1, int n2 = 2, int n3= 3): private_1(n1), protected_1(n2), public_1(n3){}
   void show(void)
   {
      // std::cout << "Private mem of the inner class: "  << n1.nested_private;//cannot access
      //  std::cout << "Protected mem of the inner class: "  << n1.nested_protected;//cannot access
       std::cout << "Public mem of the inner class: "  << n1.nested_public;
   }
}; 