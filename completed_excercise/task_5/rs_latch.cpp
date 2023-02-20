﻿#include "systemc.h"

SC_MODULE(rslatch)
{
	sc_in<bool> S;
	sc_in<bool> R;
	sc_out<bool> Q;
	sc_out<bool> N;

	SC_CTOR(rslatch) : S("S"), R("R"), Q("Q"), N("N")
	{
		SC_METHOD(process);
		sensitive << S << R << Q << N;
	}

	void process()
	{
		Q.write(!(R.read() || N.read()));
		N.write(!(S.read() || Q.read()));
	}

};

SC_MODULE(toplevel)
{
    sc_signal<bool> Ssig;
    sc_signal<bool> Rsig;
    sc_signal<bool> Qsig;
    sc_signal<bool> Nsig;

    rslatch rs;
    sc_time currentTime;
    unsigned long long currentDelta;

    SC_CTOR(toplevel) : rs("rs")
    {
        SC_THREAD(process);

        rs.S(Ssig);
        rs.R(Rsig);
        rs.Q(Qsig);
        rs.N(Nsig);

        std::cout << "\nS=0, R=1, Q=0, N=1\n" << std::endl;
        Ssig.write(false);
        Rsig.write(true);
        Qsig.write(false);
        Nsig.write(true);

        currentTime = SC_ZERO_TIME;
        currentDelta = sc_delta_count();
    }

    void waitAndPrint(sc_time delay)
    {
        wait(delay);
        sc_time time = sc_time_stamp();

        // The sc_delta_count() returns the total number of executed
        // delta delays. In order to estimate the delta delay
        // between the time advances the following is done:
        if (time > currentTime)
        {
            currentDelta = sc_delta_count();
            currentTime = time;
        }

        unsigned long long delta = sc_delta_count() - currentDelta;

        std::cout << time << " + " << delta << "δ\t"
            << Ssig.read() << "\t"
            << Rsig.read() << "\t"
            << Qsig.read() << "\t"
            << Nsig.read() << "\t" << std::endl;
    }

    void process()
    {
        // Start in Reset State
        waitAndPrint(SC_ZERO_TIME);
        waitAndPrint(SC_ZERO_TIME);
        waitAndPrint(SC_ZERO_TIME);

        // Set:
        std::cout << "\nS=1, R=0\n" << std::endl;
        waitAndPrint(sc_time(10, SC_NS));

        Ssig.write(true);
        Rsig.write(false);

        waitAndPrint(SC_ZERO_TIME);
        waitAndPrint(SC_ZERO_TIME);
        waitAndPrint(SC_ZERO_TIME);

        // Reset:
        std::cout << "\nS=0, R=1\n" << std::endl;
        waitAndPrint(sc_time(10, SC_NS));

        Ssig.write(false);
        Rsig.write(true);

        waitAndPrint(SC_ZERO_TIME);
        waitAndPrint(SC_ZERO_TIME);
        waitAndPrint(SC_ZERO_TIME);

        sc_stop();
    }
};

/*
int sc_main(int argc,char* argv[])
{
    std::cout << "\nT\t\tS\tR\tQ\tN" << std::endl;
    toplevel t("t");

    sc_set_stop_mode(SC_STOP_FINISH_DELTA);
    sc_start();
    return 0;
}

*/