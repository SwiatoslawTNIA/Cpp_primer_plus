

#ifndef QUEUE_
#define QUEUE_

class Customer
{
private:
   size_t arrival_time;
   size_t process_time;
public:
   Customer(){arrival_time = process_time = 0;};
   void set(long when);
   long when () const {return arrival_time;};
   long ptime () const {return process_time;};
};

typedef Customer Item;//define an item to be a customer

class Queue
{
   enum {Q_SIZE = 10};
   struct Node
   {
      Item item;//date stored
      struct Node *next;//a pointer to the next node
   };
   
private:
   const int qsize;//max num of items in a queue
   int items;
   Node *front;
   Node *back;
   //methods that aren't defined now, should(dem Bedarf nach) spater definiert werden:
   friend const Queue operator+(const Queue & q_1, const Queue & q_2);//add ques
   Queue(const Queue & q_2) : qsize(0) {};//a copy constructor + initialize qsize
   //before complilation enters the innards of the constructor (copy constructor);
   Queue & operator=(const Queue & q) { return *this;};
public:
   Queue(int qs = Q_SIZE);
   ~Queue();
   bool isempty(void) const;
   bool isfull(void) const;
   int queuecount(void) const;
   bool enqueue(const Item &item);//add an item to a queue
   bool dequeue(Item &item);//remove Item from a queue;

};
#endif