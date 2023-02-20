#pragma once

#include <systemc.h>

SC_MODULE(stim)
{
public:
    sc_out<bool> A, B;
    sc_in<bool> Clk;

    SC_CTOR(stim)
    {
        SC_THREAD(StimGen);
        sensitive << Clk.pos();
    }

private:
    void StimGen()
    {
       // wait(SC_ZERO_TIME);
        wait();
        A.write(false);
        B.write(false);
        wait();
        //wait(10, SC_NS);
        A.write(false);
        B.write(true);
        wait();
       // wait(15, SC_NS);
        A.write(true);
        B.write(false);
        wait();
       // wait(10, SC_NS);
        A.write(true);
        B.write(true);
        wait();
        //wait(10, SC_NS);
        A.write(false);
        B.write(false);
        wait();
       // wait(10, SC_NS);
        sc_stop();
    }
};