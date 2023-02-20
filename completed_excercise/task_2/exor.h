#pragma once



#include <systemc.h>

#include "nand.h"

// TODO: Insert your code here

// EXOR_H
SC_MODULE(exor) {
	sc_in<bool> A;
	sc_in<bool> B;
	sc_out<bool> Z;

	nand nand1, nand2, nand3, nand4;

	sc_signal<bool> h1, h2, h3;

	SC_CTOR(exor) : A("A"), B("B"), Z("Z"), nand1("nand1"), nand2("nand2"), nand3("nand3"), nand4("nand4"), h1("h1"), h2("h2"), h3("h3")
	{
		nand1.A.bind(A);
		nand1.B.bind(B);
		nand1.Z.bind(h1);

		nand2.A(A);
		nand2.B(h1);
		nand2.Z(h2);

		nand3.A(h1);
		nand3.B(B);
		nand3.Z(h3);

		nand4.A(h2);
		nand4.B(h3);
		nand4.Z(Z);

	}

};