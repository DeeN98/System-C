#pragma once

#include<systemc.h>
#include"place.h"

//template<unsigned int N = 1, unsigned int M = 1>
template<unsigned int N = 1, unsigned int M = 1, unsigned int L = 0>

SC_MODULE(transition) {
	sc_port<placeInterface, N, SC_ALL_BOUND> in;
	sc_port<placeInterface, M, SC_ALL_BOUND> out;
	sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;

public:
	SC_CTOR(transition) {

	};

	void fire() {
		int	e_0 = 0;
		for (int i = 0; i < N;i++) {
			if (in[i]->testTokens()==0) {
				e_0 = 1;
			}
		}
		int inhibitor_count = 0;
		for (int i = 0;i < L; i++) {
			if (inhibitors[i]->testTokens() != 0) {
				//cout << "no inhibitor" << endl;
				inhibitor_count++;
				//SC_REPORT_WARNING("main", "report inhibitor is not 0");
			}
		}
		if (e_0==0 && inhibitor_count==0) {
			
			std::cout << this->name() << ": Fired" << std::endl;
			for (int a = 0; a < N;a++) {
				//in[a]->removeTokens(1);*
				in[a]->removeTokens();
			}
			//The template parameter N denotes the number of input ports
			//and M denotes the number of output ports

			for (int b = 0; b < M;b++) {
				//out[b]->addTokens(1);
				out[b]->addTokens();
			}

		}
		else {
			std::cout << this->name() << ": NOT Fired" << std::endl;
			
		}
	}

};
