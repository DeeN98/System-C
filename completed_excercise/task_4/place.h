#pragma once

#include<systemc.h>
#include<iostream>

using namespace std;


class placeInterface : public sc_interface
{
public:
	/*virtual void addTokens(unsigned int n) = 0;
	virtual void removeTokens(unsigned int n) = 0;
	virtual unsigned int testTokens() = 0;*/
	//a virtual function is specified pure by using the pure specifier "= 0"
	virtual void addTokens() = 0;
	virtual void removeTokens() = 0;
	virtual bool testTokens() = 0;
};

//template<unsigned int N = 1, unsigned int M = 1>
template<unsigned int Win = 1, unsigned int Wout = 1>
class placeChannel : public placeInterface {
private:
	unsigned int tokens; // a member variable 
public:
	placeChannel(unsigned int tokens ): tokens(tokens)
	{
		// maybe initial numberof tokens should be passed
	}
	void addTokens() {
		tokens += Win;
	}
	void removeTokens() {
		tokens -= Wout;
	}
	bool testTokens() {
		return (tokens >= Wout );
	}
};