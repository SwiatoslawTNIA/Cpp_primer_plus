#include <iostream>

template <class T>
class Queue
{
private:
   enum {Q_SIZE = 10};
   class Node
   {
      public:
         T item;
         Node *n;
         Node(const T & r): item(r), n(0){}
   };
   Node * rear;
   Node *front;
   int items;//number of items;
   const int queue_size; //the max queue size
   Queue(const Queue & r): queue_size(r) {}
   Queue & operator=(const Queue & q) {return *this;}
public:
   Queue(int qs = Q_SIZE);
   ~Queue();
   bool isempty(void) const { return items == 0;}
   bool isfull(void) const {return items == queue_size;}
   int queuecount(void) const {return items;}

   bool enqueue(const T & ref);
   bool dequeue(T & ref);//remove an item;
   bool dequeue(T ref);
};
template <typename T>
bool Queue<T>::dequeue(T ref)
{
   if(isempty()) return false;
   Node * temp = front, *prev = nullptr;
   while( temp != nullptr && temp->item != ref)
   {
      prev = temp;//keep track of the previous element
      temp = temp->n;
   }
   if(temp == nullptr) 
      return false;

   if(prev != nullptr)
      prev->n = temp->n;
   else
      front->n = temp->n;

   if(temp->n == nullptr)//if it is the last element:
      rear = prev;
   delete temp;//delete that node
   --items;
   return true;
   //  if (isempty()) return false;
   //  Node* temp = front;
   //  Node* prev = nullptr;
   //  while (temp != nullptr && temp->item != ref) {
   //      prev = temp;  // keep track of the previous element
   //      temp = temp->n;
   //  }
   //  if (temp == nullptr) return false;  // item not found
   //  if (prev != nullptr) {
   //      prev->n = temp->n;
   //  } else {
   //      front = temp->n;
   //  }
   //  if (temp->n == nullptr)  // if it is the last element:
   //      rear = prev;
   //  delete temp;  // delete that node
   //  --items;
   //  return true;
}
template <typename T>
Queue<T>::Queue(int qs): queue_size(qs)
{
   front = rear = nullptr;
   items = 0;
}
template <typename T>
bool Queue<T>::enqueue(const T & ref)
{
   if(isfull())
      return false;
   if(front == nullptr)
   {
      rear = front = new Node(ref);
      front->n = nullptr;
      items++;
      return true;
   }
   else
   {
      rear->n = new Node(ref);
      rear = rear->n;//reset the rear to the current node;
      rear->n = nullptr;
      ++items;
   }
   return true;
}
template <typename T>
bool Queue<T>::dequeue(T & ref)
{
   if(isempty()) return false;
   Node * temp = front, *prev = nullptr;
   while(temp->item != ref)
   {
      prev = temp;//keep track of the previous element
      temp = temp->n;
   }
   if(temp == nullptr)
      return false;
   prev->n = temp->n;

   if(temp->n == nullptr)//if it is the last element:
      rear = prev;
   delete temp;//delete that node
   --items;
   return true;
}


template <typename T>
Queue<T>::~Queue()
{
   if(front != nullptr)
   {
      Node *temp;
      while(front != nullptr)
      {
         temp = front;
         front = front->n;
         delete temp;
      }
   }
}
