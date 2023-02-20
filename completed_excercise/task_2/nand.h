#pragma once

SC_MODULE(nand) {
public:
	sc_in<bool> A;
	sc_in<bool> B;
	sc_out<bool> Z;

	SC_CTOR(nand) : A("A"), B("B"), Z("Z") {
		SC_METHOD(process);

		sensitive << A << B;
		dont_initialize();


	}
	void process() {
		//next_trigger(
			//A.value_changed_event,
			//B.value_changed_event
		//);
		Z.write(!A.read() || !B.read());
	}
};