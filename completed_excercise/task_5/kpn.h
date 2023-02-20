#pragma once


#include <systemc.h>




SC_MODULE(kpn)
{
private:
    // ADD THINGS HERE
    //add the fifos
    //to add the depth of fifo
   /* sc_fifo<int> fifo;
    SC_CTOR(M) : fifo(4)*/
    sc_fifo<int> a;
    sc_fifo<int> b;
    sc_fifo<int> c;
    sc_fifo<int> d;
    sc_signal<int> e;
    

public:
    
    SC_CTOR(kpn): a(10), b(10), c(10), d(10), e("e") // : ADD THINGS HERE
    {
        b.write(1);
        c.write(0);

        // ADD THINGS HERE
        SC_THREAD(Add);
        SC_THREAD(Split);
        SC_THREAD(Delay);
      
        sensitive << a.data_written_event() <<b.data_written_event() << c.data_written_event() << d.data_written_event();

        //dont_initialize();
    }
    
    void Add();
    //template <class T>
    void Split();
    //template <class T>
    void Delay();


};
