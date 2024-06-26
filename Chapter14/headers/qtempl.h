
template <typename T, size_t Size = 10>
class Queue
{
private:
   enum {MAX_SIZE = 10};
   T arr[Size];
   int index;
   bool is_full(void) const { return index == MAX_SIZE;}
   bool is_empty(void) const { return index == 0;}
public:
   Queue(): index(0){}
   Queue(T & value): index(0)
   {
      arr[index++] = value;
   }
   bool push(T & ref)
   {
      if(is_full())
         return false;
      else
      {
         arr[index++] = ref;
      }
      return true;
   }

   bool pop(T & ref)
   {
      if(is_empty()) return false;
       for (int i = 0; i < index;++i)
       {
         if(arr[i] == ref)
         {
            for(int j = i + 1; j < index;++j)
            {
               arr[j - 1] = arr[j];
            }
         }
       }
       return true;
   }

   void show(void) const
   {
      for(int i = 0; i < index;++i)
      {
         cout << "Element" << i + 1 << ": " << arr[i] << endl;//provided that for the element the operator<<() func is defined
      }
   }
   const Queue & operator+(T & ref);

};
template <typename T, size_t Size>
const Queue<T,Size> & Queue<T,Size>::operator+(T & ref)
{
   push(ref);//use the push method
   return *this;
}

