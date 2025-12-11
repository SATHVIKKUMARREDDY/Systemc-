#include<iostream>
#include<systemc>
#include"place.h"
#include"transition.h"
#include"subnet.h"

SC_MODULE(toplevel){

    place<unsigned int,1,1> IDLE;
    subnet s1,s2;

    SC_CTOR(toplevel) : IDLE("IDLE", 2), s1("s1", IDLE), s2("s2", IDLE){
       

        SC_THREAD(process);
    }
    


    void process()
    {
        while (true)
        {
            wait(10, sc_core::SC_NS);
            s1.ACT.fire();
            wait(10, sc_core::SC_NS);
            s1.ACT.fire();
            wait(10, sc_core::SC_NS);
            s1.RD.fire();
            wait(10, sc_core::SC_NS);
            s1.WR.fire();
            wait(10, sc_core::SC_NS);
            s1.PRE.fire();
            wait(10, sc_core::SC_NS);
            s1.ACT.fire();
            wait(10, sc_core::SC_NS);
            s2.ACT.fire();
            wait(10, sc_core::SC_NS);
            s2.ACT.fire();
            wait(10, sc_core::SC_NS);
            s1.PRE.fire();
            wait(10, sc_core::SC_NS);
            s2.PRE.fire();
            wait(10, sc_core::SC_NS);
           sc_core::sc_stop();
        }
    }
};
int sc_main(int argc, char* argv[]){
    toplevel top("top");
    sc_core::sc_start();
    return 0;
}
