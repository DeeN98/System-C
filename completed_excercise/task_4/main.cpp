
#include <systemc.h>
#include "place.h"
#include "transition.h"
#include "subnet.h"

// toplevel:
// todo
SC_MODULE(toplevel) {
	/*transition<1, 2> t1;
	transition<2, 1> t2;
	transition<1, 1> t3;
	placeChannel<1, 1> p1, p2, p3, p4;*/

	//SC_CTOR(toplevel) : t1("t1"), t2("t2"), t3("t3"),
	//	p1(1), p2(0), p3(0), p4(0) {
	//	t1.in.bind(p1);
	//	t1.out.bind(p2);
	//	t1.out.bind(p3);

	//	t2.in.bind(p2);
	//	t2.out.bind(p1);
	//	t2.in.bind(p4);

	//	t3.in(p3);
	//	t3.out(p4);

	//	//p1.addTokens( );

	//	SC_THREAD(process);
	//}

	//void process()
	//{
	//	while (true)
	//	{
	//		/*
	//		 wait(10, sc_ns);
	//		t1.fire();
	//		wait(10, sc_ns);
	//		t1.fire();
	//		wait(10, sc_ns);
	//		t2.fire();

	//		sc_stop();
	//		*/
	//		wait(10, SC_NS);
	//		t1.fire();
	//		wait(10, SC_NS);
	//		t2.fire();
	//		wait(10, SC_NS);
	//		t3.fire();
	//		wait(10, SC_NS);
	//		t2.fire();
	//		sc_stop();
	//	}
	//}

	//transition<1, 1, 0> act;
	//transition<1, 1, 0> pre;
	////transition<1 ,1, 1> wr, rd;
	//transition<1, 1, 0> wr, rd;

	//placeChannel<3, 3> active;
	//placeChannel<1, 1> idle;
	//SC_CTOR(toplevel): act("act"), pre("pre"), wr("wr"), rd("rd"),
	//	active(0), idle(1){

	//	act.in(idle);
	//	act.out(active);

	//	rd.in(active);
	//	rd.out(active);

	//	wr.in(active);
	//	wr.out(active);

	//	pre.in(active);
	//	pre.out(idle);

	//	SC_THREAD(process);

	//}

	//void process() {
	//	while (true) {
	//		wait(10, SC_NS);
	//		act.fire();
	//		wait(10, SC_NS);
	//		act.fire();
	//		wait(10, SC_NS);
	//		rd.fire();
	//		wait(10, SC_NS);
	//		wr.fire();
	//		wait(10, SC_NS);
	//		pre.fire();
	//		wait(10, SC_NS);
	//		act.fire();
	//		sc_stop();
	//	}
	//}

	placeChannel<2, 2> idle;
	subnet s1;
	subnet s2;

	SC_CTOR(toplevel) : idle(2), s1("s1"),s2("s2")
	{
		
		
		s1.act.in(idle);
		s2.act.in(idle);

		s1.pre.out(idle);
		s2.pre.out(idle);

		SC_THREAD(process);

	}


	void process() {
		while (true) {

			wait(10, SC_NS);
			s1.act.fire();
			wait(10, SC_NS);
			s1.act.fire();
			wait(10, SC_NS);
			s1.rd.fire();
			wait(10, SC_NS);
			s1.wr.fire();
			wait(10, SC_NS);
			s1.pre.fire();
			wait(10, SC_NS);
			s1.act.fire();
			wait(10, SC_NS);
			s2.act.fire();
			wait(10, SC_NS);
			s2.act.fire();
			wait(10, SC_NS);
			s2.pre.fire();
			wait(10, SC_NS);
			s2.pre.fire();
			wait(10, SC_NS);

			sc_stop();
		}
	}
};


int sc_main(int, char**)
{
	// TODO
	toplevel t("T");

	sc_start();
	return 0;
}