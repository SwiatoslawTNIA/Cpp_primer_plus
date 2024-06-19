

typedef int Item;
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
public:
   Queue(int qs = Q_SIZE);
   ~Queue();
   bool isempty(void) const;
   bool isfull(void) const;
   int queuecount(void) const;
   bool enqueue(const Item &item);//add an item to a queue
   bool dequeue(Item &item);//remove Item from a queue;

};