//tv.h -- TV and Remote classes
#ifndef TV_H_
#define TV_H_

class TV
{
private:
	int state;      //on or off
	int volume;     //assumed to be digitized
	int maxchannel; // maximum number of channels
	int channel;    // current channel setting
	int mode;       //broadcast or cable
	int input;      //tv or DVD
public:
	friend class Remote;   //友元类Remote可以访问TV是的私有成员
	enum {off,on};
	enum {MinVal, MaxVal = 20};
	enum {Antenna, Cable};
	enum {tv, DVD};

	TV(int s = off, int mc =125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(tv) {}
	void onoff() {state = (state ==on) ? off : on;}
	bool ison() const {return state ==on;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() {mode = (mode == Antenna) ? Cable : Antenna;}
	void set_input() {input = (input == tv)? DVD : tv;}
	void settings() const;   //display all settings
};

class Remote 
{
private: 
	int mode;
public:
	Remote(int m = TV::tv) : mode(m) {}
	bool volup(TV & t) { return t.volup();}
	bool voldown(TV & t) { return t.voldown();}
	void onoff(TV & t) { return t.onoff();}
	void chanup(TV & t) { return t.chanup();}
	void chandown(TV & t) { return t.chandown();}
	void set_chan(TV & t, int c) { t.channel = c;}
	void set_mode(TV & t) {t.set_mode();}
	void set_input(TV & t) {t.set_input();}
};

#endif