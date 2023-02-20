#pragma once

#include <systemc.h>

#include "place.h"
#include "transition.h"

SC_MODULE(subnet) {
	transition<1, 1, 1> act;
	transition<1, 1, 0> pre;
	//transition<1 ,1, 1> wr, rd;
	transition<1, 1, 0> wr, rd;

	placeChannel<3, 3> active;

	SC_CTOR(subnet) : act("act"), pre("pre"), wr("wr"), rd("rd"),
		active(0) {
		//act.in(idle);
		act.out(active);
		act.inhibitors(active);

		rd.in(active);
		rd.out(active);
		wr.in(active);
		wr.out(active);

		pre.in(active);
		//pre.out(idle);
	}
};