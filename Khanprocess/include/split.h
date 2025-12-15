#ifndef SPLIT_H
#define SPLIT_H
#include <iostream>
#include "systemc.h"
SC_MODULE(Split) {
    sc_core::sc_fifo_in<int> in;
    sc_core::sc_fifo_out<int> out1;
    sc_core::sc_fifo_out<int> out2;

    void do_split() {
        while (true) {
            int value = in.read();
            out1.write(value);
            out2.write(value);
            cout<<"Split: " << value << endl;
            wait(sc_core::sc_time(1, sc_core::SC_NS));
        }
    }

    SC_CTOR(Split) {
        SC_THREAD(do_split);
    }
};
#endif // SPLIT_H