// tvfm.h -- tv and remote classes using a friend member

#ifndef TVFM_H_
#define TVFM_H_
using namespace std;
class Tv;

class Remote
{

private:
	int mode;
	int fmode;
	enum {USUAL, EXCHANGE};
	friend class Tv;  //к╫сп
public:
	enum State{off, on};
	enum {MinVal, MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV, DVD};


public:
	Remote(int m = TV, int f = USUAL) : mode(m), fmode(f) {}
	bool volup(Tv & t);//prototype only  
	bool voldown(Tv & t);
	void onoff(Tv & t);
	void chanup(Tv & t);
	void chandown(Tv & t);
	void set_mode(Tv & t);
	void set_input(Tv & t);
	void set_chan(Tv & t, int c);
	void mode_show() const {cout << "Remote pretent mode is : " << fmode << endl;}
};

class Tv
{
	friend class Remote;
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	friend void Remote::set_chan(Tv & t, int c);
	enum State{off, on};
	enum {MinVal, MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV,DVD};
	enum {USUAL, EXCHANGE};

	Tv(int s = off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() {state = (state == on) ? off : on;}
	bool ison() const {return state == on;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna;}
	void set_input() {input = (input == TV) ? DVD : TV;}
	void settings() const;
	void set_rmode(Remote & r);
};

//Remote methods as inline functions

inline bool Remote::volup(Tv & t) { return t.volup();}
inline bool Remote::voldown(Tv & t) { return t.voldown();}
inline void Remote::onoff(Tv & t) { t.onoff();}
inline void Remote::chanup(Tv & t) {t.chanup();}
inline void Remote::chandown(Tv & t) { t.chandown();}
inline void Remote::set_mode(Tv & t) {t.set_mode();}
inline void Remote::set_input(Tv & t) {t.set_input();}
inline void Remote::set_chan(Tv & t, int c) { t.channel = c;}
inline void Tv::set_rmode(Remote & r)
{
	if(ison())
	{
		r.fmode = Remote::EXCHANGE;
		r.mode_show();
	}
}
#endif