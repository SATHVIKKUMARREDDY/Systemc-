#include<iostream>
#include<systemc.h>

SC_MODULE(toplevel){

    transition t1("t1");
    transition t2("t2");
    SC_CTOR(toplevel){
         SC_THREAD(process);
    }
    t1.in(t2.out);
    t1.out(t2.in);


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
