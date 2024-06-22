class Cd { // represents a CD disk
private:
   char *performance;
   char *label;
   int selections;
   // number of selections
   double playtime; // playing time in minutes
public:
   Cd(const char * s1, const char * s2, int n, double x );//a default constructor
   Cd(const Cd & d);
   Cd(void);
   virtual ~Cd();
   virtual void Report(void) const; // reports all CD data
   Cd & operator=(const Cd & d);
};
class Classic: public Cd
{
private:
   char *primary_work;
public:
   Classic(const char *pr_work, const char * s1, const char *s2, int n, double x);
   Classic(void);
   Classic(const Classic & ref);//copy constructor
   Classic & operator=(const Classic & obj);
   virtual void Report(void) const override; // two diff methods for two different classes = requires virtual
   //the virtual in the derived class is optional, but is recommended, so it override, 
   //since override ensures, that the func is redefined in the class override is specified in 
   virtual ~Classic();

};
