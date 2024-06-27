// class Tv
// {
// public: 
//    friend class Remote;
//    enum {ON  = 1, OFF = 0};
//    enum {MinVal, MaxVal = 20};
//    enum {Antenna, Cable};
//    enum {TV, DVD};
//    Tv(int  s = OFF, int mc = 125): state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), 
//    input(TV){}
//    void onoff(void) {state =  (state == ON)? OFF : ON;};//change the state
//    bool ison() const {return state == ON;}
//    bool volup();
//    bool voldown();
//    void chanup();
//    void chandown();
//    void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
//    void set_input() {input = (input == TV)? DVD : TV;}
//    void settings() const; // display all settings
// private:
//    int state;
//    int volume;
//    int maxchannel;
//    int channel;
//    int mode;
//    int input;
// };
// class Remote
// {
// private:
//    int mode;
// public:
//    Remote(int m = Tv::TV): mode(m) {}
//    bool volup(Tv & t) {return t.volup();}
//    bool voldown(Tv & t){return t.voldown();}
//    void onoff(Tv & t){return t.onoff();}
//    void chanup(Tv & t) {t.chanup();}
//    void chandown(Tv & t) {t.chandown();}
//    void set_chan(Tv & t, int c) {t.channel = c;}
//    void set_mode(Tv & t) {t.set_mode();}
//    void set_input(Tv & t) {t.set_input();}
// };
// bool Tv::volup(void)
// {
//    if(volume < MaxVal)
//    {
//       volume++;
//       return true;
//    }
//    else
//       return false;
// }
// bool Tv::voldown(void)
// {
//    if(volume > MinVal)
//    {
//       volume--;
//       return true;
//    }  
//    else return false;
// }

// void Tv::chanup(void)
// {
//    if(channel < maxchannel)
//       ++channel;
//    else
//       channel = 1;
// }
// void Tv::chandown(void)
// {
//    if(channel > 1)
//       --channel;
//    else
//       channel = maxchannel;
// }

// //settings:
// void Tv::settings(void) const
// {
//    using std::cout;
//    using std::endl;
//    cout << "TV is " << (state == OFF? "Off" : "On") << endl;
//    if (state == ON)
//    {
//       cout << "Volume setting = " << volume << endl;
//       cout << "Channel setting = " << channel << endl;
//       cout << "Mode = " << (mode == Antenna? "antenna" : "cable") << endl;
//       cout << "Input = "<< (input == TV? "TV" : "DVD") << endl;
//    }
// }

//now we have one method that is a friend to the Tv class:
class Tv;

class Remote
{
   private:
   enum {ON  = 1, OFF = 0};
   enum {MinVal, MaxVal = 20};
   enum {Antenna, Cable};
   enum {TV, DVD};
   int mode;
   
public:
   Remote(int m = TV): mode(m) {}
   bool volup(Tv & t);
   bool voldown(Tv & t);
   void onoff(Tv & t);
   void chanup(Tv & t);
   void chandown(Tv & t);
   void set_chan(Tv & t, int c);
   void set_mode(Tv & t);
   void set_input(Tv & t);
};
class Tv
{
public: 
   friend class Remote;
   enum {ON  = 1, OFF = 0};
   enum {MinVal, MaxVal = 20};
   enum {Antenna, Cable};
   enum {TV, DVD};
   Tv(int  s = OFF, int mc = 125): state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), 
   input(TV){}
   void onoff(void) {state =  (state == ON)? OFF : ON;};//change the state
   bool ison() const {return state == ON;}
   bool volup();
   bool voldown();
   void chanup();
   void chandown();
   void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
   void set_input() {input = (input == TV)? DVD : TV;}
   void settings() const; // display all settings
private:
   int state;
   int volume;
   int maxchannel;
   int channel;
   int mode;
   int input;
};
//making the remote funcs(inline):

   inline bool Remote::volup(Tv & t) {return t.volup();}
   inline bool Remote::voldown(Tv & t){return t.voldown();}
   inline void Remote::onoff(Tv & t){return t.onoff();}
   inline void Remote::chanup(Tv & t) {t.chanup();}
   inline void Remote::chandown(Tv & t) {t.chandown();}
   inline void Remote::set_chan(Tv & t, int c) {t.channel = c;}
   inline void Remote::set_mode(Tv & t) {t.set_mode();}
   inline void Remote::set_input(Tv & t) {t.set_input();}
bool Tv::volup(void)
{
   if(volume < MaxVal)
   {
      volume++;
      return true;
   }
   else
      return false;
}
bool Tv::voldown(void)
{
   if(volume > MinVal)
   {
      volume--;
      return true;
   }  
   else return false;
}

void Tv::chanup(void)
{
   if(channel < maxchannel)
      ++channel;
   else
      channel = 1;
}
void Tv::chandown(void)
{
   if(channel > 1)
      --channel;
   else
      channel = maxchannel;
}

//settings:
void Tv::settings(void) const
{
   using std::cout;
   using std::endl;
   cout << "TV is " << (state == OFF? "Off" : "On") << endl;
   if (state == ON)
   {
      cout << "Volume setting = " << volume << endl;
      cout << "Channel setting = " << channel << endl;
      cout << "Mode = " << (mode == Antenna? "antenna" : "cable") << endl;
      cout << "Input = "<< (input == TV? "TV" : "DVD") << endl;
   }
}