#include <io.h>
#include <systemc.h>

#include "kpn.h"

//template <class T>
void kpn:: Add() {
	//a input,
	///c input
	//b =a+c
	
	//std::cout << "add"<< a << endl;
	while (true) {
		wait(10,SC_NS);
		b.write(a.read() + c.read());
	}
}

void  kpn::Split() {
	//b input 
	//a=b,d=b,e=b
	int i = 0;
	int b_read;
	while (i<10) {
		wait(10, SC_NS);
		std::cout << "split " << endl;
		b_read = b.read();
		a.write(b_read);
		d.write(b_read);
		e.write(b_read);
		std::cout << "print the e: " << b_read << endl;
		i++;
	}

	sc_stop();


}


void kpn::Delay() {
	//d input
	//c output
	while (true) {
		wait(10, SC_NS);
		c.write(d.read());
		//std::cout << "Delay" << endl;
	}
}