#include <systemc.h>

#include "place.h"
#include "transition.h"
#include "subnet.h"

// Toplevel:
// TODO
SC_MODULE(Toplevel) {
    

    SC_CTOR(Toplevel) {
        SC_THREAD(process);
        
    }

    void process()
    {
        while (true)
        {
            wait(10, SC_NS);
            t1.fire();
            wait(10, SC_NS);
            t1.fire();
            wait(10, SC_NS);
            t2.fire();
            sc_stop();
        }
    }


}

int sc_main(int, char**)
{
    // TODO
    Toplevel t("Toplevel");
   
    sc_start();
    return 0;
}