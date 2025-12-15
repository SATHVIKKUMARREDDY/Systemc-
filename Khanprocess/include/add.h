#ifndef ADD_H
#define ADD_H
#include <iostream>
#include "systemc.h"

SC_MODULE(Add) {
    sc_core::sc_fifo_in<int> a;
    sc_core::sc_fifo_in<int> b;
    sc_core::sc_fifo_out<int> sum;

    void do_add() {
        while (true){
            int val_a = a.read();
            int val_b = b.read();
            sum.write(val_a + val_b);
            wait(sc_core::sc_time(1, sc_core::SC_NS));
        }
        
    }

    SC_CTOR(Add) {
        SC_THREAD(do_add);
    }
};
#endif // ADD_H