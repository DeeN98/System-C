#pragma once

#include<systemc.h>
#include<regex>
SC_MODULE(stateMachine) {
public:

	sc_in<char> input;
	sc_in<bool> clk;

	enum base
	{
		Start, G, GA, GAA, GAAG 
	};
	base current_state;

	int counter,seq_count, g_position, g_position_last;

	SC_CTOR(stateMachine): input("input"), clk("clk")
	{
		current_state = Start;
		counter = 0;
		seq_count = 0;
		g_position = 0;
		g_position_last = 0;
		SC_METHOD(process);
		sensitive << clk.pos();
		dont_initialize();
	}
private:
	void process();
	
};