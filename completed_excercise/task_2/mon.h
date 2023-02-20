#pragma once


#include <iostream>
#include <systemc.h>


SC_MODULE(Monitor) 
{
public:
    sc_in<bool> A, B, Z;
    sc_in<bool> Clk;

    SC_CTOR(Monitor) : A("A"), B("B"), Z("Z")
    {
        std::cout << std::endl << "time\tA\tB\tF" << std::endl;
        SC_METHOD(monitor);
        sensitive << A << B << Z<< Clk.pos();
        dont_initialize();
    }

private:
    void monitor()
    {
        std::cout << sc_time_stamp() << "\t" << A << "\t" << B << "\t" << Z << std::endl;
    }
};