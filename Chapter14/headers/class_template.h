//since a template member funcs are not really func defs but merely a rule,
#ifndef TEMPLATE_CPP
#define TEMPLATE_CPP
//that tell the compiler how to create certain funcs

template <class Type>//a class template
class Stack
{
private:
   enum {MAX = 10};
   // constant specific to class
   Type items[MAX];
   // holds stack items
   int top;
   // index for top stack item
public:
   Stack();
   bool isempty() const;
   bool isfull() const;
   // push() returns false if stack already is full, true otherwise
   bool push(const Type & item);
   // add item to stack
   // pop() returns false if stack already is empty, true otherwise
   bool pop(const Type & item);
   // pop top into item
};
template <typename Type>
Stack<Type>::Stack(void): top(0){}

template <typename Type>
bool Stack<Type>::isempty(void) const
{
   return top == 0;
}

template <typename Type>
bool Stack<Type>::isfull(void) const
{
   return top == MAX;
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
bool Stack<Type>::pop(const Type & item)
{
   if(isempty())
      return false;
   for(int i = 0; i < top; ++i)
   {
      if(items[i] == item)
      {
         //shift all the elems to the left
         for(int j = i + 1; j < top;++j)
         {
            items[j - 1] = items[j];
         }
         --top;//decrement the top by one
         break;
      }
   }
   return true;
}
#endif