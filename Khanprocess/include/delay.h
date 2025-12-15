#ifndef DELAY_H
#define DELAY_H
#include <iostream>
#include "systemc.h"
SC_MODULE(Delay) {
    sc_core::sc_fifo_in<int> in;
    sc_core::sc_fifo_out<int> out;

    void do_delay() {
        while (true) {
            int value = in.read();
            out.write(value);
            wait(sc_core::sc_time(1, sc_core::SC_NS));
        }
    }

     SC_CTOR(Delay) {

        SC_THREAD(do_delay);
    }
};
#endif // DELAY_H