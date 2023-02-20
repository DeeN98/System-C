#include <iostream>
#include <systemc.h>

#include "kpn.h"



//template <class T>
int sc_main(int, char**)
{
    

    kpn kahn("kpn");
    sc_start();
    return 0;
}