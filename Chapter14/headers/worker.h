#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>//for std::string class

class Worker
{
private:
   std::string fullname;
   long id;
public:
   Worker(): fullname("JollY"), id(11111) {}
   Worker(const std::string & s, long id_i): fullname(s), id(id_i) {}
   virtual ~Worker() = 0;//make it a pure virtual object, =can't create a worker instance
   virtual void Set(void);
   virtual void Show(void) const;
};
class Waiter: public Worker
{
private:
   int  panache;
public:
   Waiter(): Worker(), panache(23) {}
   Waiter(const std::string & s, long id_i, int pan): Worker(s, id_i), panache(pan) {}
   Waiter(const Worker & wk, int p = 0): Worker(wk), panache(p){} //to convert Type Waiter to Worker(implicit)
   virtual void Set(void) override;
   virtual void Show(void) const override;

};

class Singer: public Worker
{
protected:
   enum {other, alto, contralto, soprano, bass, batinone, tenor};
   enum {Vtypes = 7};
private:
   static const char *pv[Vtypes];//array of pointers
   int voice;
public:
   //contstructors:
   Singer() : Worker(), voice(other) {}
   Singer(const std::string & s, long n, int v = other): Worker(s, n), voice(v) {}
   Singer(const Worker & wk, int v = other): Worker(wk), voice(v) {}
   virtual void Set(void) override;
   virtual void Show(void) const override;
};


#endif