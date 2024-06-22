class Name //base class
{
private: //or we could use protected with no funcs to refer to the data in the derived class
   char *name;
   int age;
public:
   Name(const char * n = "default", int a = 20);//a default constructor is a necessity for the base_class classes.
   
   const char *get_hame(void) const {return name;};
   int get_age(void) const {return age;};
   virtual ~Name();
   Name(const Name & n);//copy constructor
   Name & operator=(const Name & n);
   virtual void show(void) const;
};
class Person: public Name
{
private:
   char *surname;
   int height;
public:
   Person(const char *n = "default", int age = 0, const char * sur = "Holovkin", int height = 0);
   Person(const Person & p);
   virtual void show(void) const;
   Person & operator=(const Person & p);
   virtual ~Person();
};




