#include<iostream>
#include<systemc.h>

using namespace std;

//dynamic porting
SC_MODULE(module)
{
	sc_port<sc_fifo_out_if<int>,
	0,
	SC_ZERO_OR_MORE_BOUND> port;

	SC_CTOR(module) {
		SC_THREAD(process);
	}

	void process() {
		for (int i = 0; i < port.size();i++) {
			port[i]->write(2);
			cout << "WRITE TO PORT" << i << endl;
			wait(1, SC_NS);
		}
	}
};

//int sc_main(int argc, char* argv[])
//{
//	module m("m");
//	sc_fifo<int> f1, f2, f3;
//
//	m.port.bind(f1);
//	m.port.bind(f2);
//	m.port.bind(f3);
//
//	sc_start(sc_time(20, SC_NS));
//	return 0;
//
//
//
//}