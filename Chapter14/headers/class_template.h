//since a template member funcs are not really func defs but merely a rule,
#ifndef TEMPLATE_CPP
#define TEMPLATE_CPP
//that tell the compiler how to create certain funcs

template <class Type>//a class template
class Stack
{
private:
   enum {MAX = 10, SIZE = 10};
   // constant specific to class
   Type *items;
   int stack_size;
   // holds stack items
   int top;
   // index for top stack item
public:
   explicit Stack(int ss = SIZE);
   Stack(const Stack & st);
   ~Stack(){delete [] items;};
   bool isempty() const {return top == 0;}
   bool isfull() const { return top == stack_size;}

   // push() returns false if stack already is full, true otherwise
   bool push(const Type & item);
   // add item to stack
   // pop() returns false if stack already is empty, true otherwise
   bool pop(Type & item);
   Stack & operator=(const Stack & s);
   // pop top into item
};
template <typename Type>
Stack<Type>::Stack(int ss): stack_size(ss), top(0){
   items = new Type[stack_size];

}

template <typename Type>
Stack<Type>::Stack(const Stack & s)//copy constructor
{
   stack_size = s.stack_size;
   top = s.top;

   items = new Type[s.stack_size];
   for(int i = 0; i < top; ++i)
   {
      items[i] = s.items[i];
   }
}

template <typename Type>
bool Stack<Type>::push(const Type & item)
{
   if(isfull())
      return false;
   items[top++] = item;
   return true;
} 

template <typename Type>
bool Stack<Type>::pop(Type & item)
{
   // if(isempty())
   //    return false;
   // for(int i = 0; i < top; ++i)
   // {
   //    if(items[i] == item.items[i])
   //    {
   //       //shift all the elems to the left
   //       for(int j = i + 1; j < top;++j)
   //       {
   //          items[j - 1] = items[j];
   //       }
   //       --top;//decrement the top by one
   //       break;
   //    }
   // }
   // return true;
   if (top > 0)
   {
      item = items[--top];
      return true;
   }
   else
      return false;
}

template <typename Type>
Stack<Type> & Stack<Type>::operator=(const Stack & s)
{
   if(&s == this)
      return *this;
   stack_size = s.stack_size;
   top = s.top;

   delete [] items;
   items = new Type[s.stack_size];
   for(int i = 0; i < top;++i)
   {
      items[i] = s.items[i];
   }
   return *this;
}
#endif