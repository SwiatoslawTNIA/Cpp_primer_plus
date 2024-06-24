#ifndef WORKER_H
#define WORKER_H
#include <iostream>
#include <string>//for std::string class

class Worker
{
protected:
   virtual void Data() const;
   virtual void Get(void);
private:
   std::string fullname;
   long id;
public:
   Worker(): fullname("JollY"), id(11111) {}
   Worker(const std::string & s, long id_i): fullname(s), id(id_i) {}
   virtual ~Worker() = 0;//make it a pure virtual object, =can't create a worker instance
   virtual void Set(void) = 0;
   virtual void Show(void) const = 0;//a pure virtual functions
};
class Waiter: virtual public Worker// so that the derived class has only one Worker obj
{
private:
   int  panache;
protected:
   void Data(void) const;
   void Get(void);
public:
   Waiter(): Worker(), panache(23) {}
   Waiter(const std::string & s, long id_i, int pan): Worker(s, id_i), panache(pan) {}
   Waiter(const Worker & wk, int p = 0): Worker(wk), panache(p){} //to convert Type Waiter to Worker(implicit)
   virtual void Set(void) override;
   virtual void Show(void) const override;
};

class Singer: public  virtual Worker
{
protected:
   enum {other, alto, contralto, soprano, bass, batinone, tenor};
   enum {Vtypes = 7};
   void Data(void) const;
   void Get();
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
class SingingWaiter: public Singer, public Waiter
{
protected:
   void Data(void) const;
   void Get(void);
public:
   SingingWaiter(): Worker(), Singer(), Waiter() {}
   SingingWaiter(const std::string & full_n, long ID, int pan, int voice = other): 
   Worker(full_n, ID), Singer(full_n, ID, voice), Waiter(full_n, ID, pan){}

   virtual void Set(void) override;
   virtual void Show(void) const override;
};

#endif


