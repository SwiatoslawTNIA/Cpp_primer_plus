#include <iostream>
#include <cstring>
#include <cstdlib>//for int rand(void) and void srand(unsigned int)
#include "queue.h"


void Customer::set(long when)
{
   srand(time(NULL));//pass the seed
   process_time = rand() % 3 + 1;//from 1 to four minutes, it takes to process a single
   //customer
   arrival_time = when;
}

Queue::Queue(int q_size) : qsize(q_size), items(0), front(NULL), back(NULL)
{
   // front = back = NULL;
   // qsize = q_size;
   // items = 0;
}
bool Queue::enqueue(const Item & item)
{
   if(isfull())
      return false;

   Node *add = new Node;
   add->item = item;
   add->next = NULL;

   if(front == nullptr)
      front = add;
   else
      back->next = add;
   
   ++items;//update the number of items in the queue
   back = add;//now back points to add;
   return true;
}
bool Queue::dequeue( Item & item)
{
   // if(isempty())
   //    return false;
   // Node * current = previous->next, previous = front;
   // while(element->item != item && element->next != nullptr)
   //    element = element->next;//find the element
   // if(element->item != item)//if the item hasn't been found
   //    return false;
   
   // //if it's the last item:
   // if(element->next == nullptr)
   item = front->item;//set the item to point to the value of the first node, 
   //so that the caller has access to the first item.
   if(isempty())
      return false;
   --items;
   Node *temp = front;
   front = front->next;
   delete temp;
   if(items == 0)
      back = nullptr;
   return true;
}
bool Queue::isfull(void) const
{
   return (items == qsize);
}
bool Queue::isempty(void) const
{
   return (items == 0);
}
int Queue::queuecount(void) const
{
   return items;
}
// a class requires an explicit destructor, to ensure, that all nodes are deleted.
Queue::~Queue(void) 
{
   if(front == nullptr) return;

   Node *current = front, *temp = front;
   while(current->next != nullptr)
   {
      current = current->next;
      delete temp;
      temp = current;
   }
   //delete the last node:
   delete current;
}
