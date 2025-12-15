#include<iostream>
#include "systemc.h"
#include "delay.h"
#include "split.h"
#include "add.h"    

SC_MODULE(KhanProcess) {
public:
    // Internal signals
    sc_core::sc_fifo<int> fifo_a;
    sc_core::sc_fifo<int> fifo_b;
    sc_core::sc_fifo<int> fifo_d;
    sc_core::sc_fifo<int> fifo_c;

    // Module instances
    Delay delay;
    Split split;
    Add add;

    SC_CTOR(KhanProcess): delay("delay"), split("split"), add("add") ,fifo_a("fifo_a",10), fifo_b("fifo_b",10), fifo_d("fifo_d",10), fifo_c("fifo_c",10) {

        fifo_b.write(1); // Initial value
        fifo_c.write(0); // Initial value
        // Connect Delay module
        delay.in(fifo_d);
        delay.out(fifo_c);

        // Connect Split module
        split.in(fifo_b);
        split.out1(fifo_d);
        split.out2(fifo_a);
        // Connect Add module
        add.a(fifo_a);
        add.b(fifo_c);
        add.sum(fifo_b);
    }

    ~KhanProcess() {
    }
};

int sc_main(int argc, char* argv[]) {
    KhanProcess khan_process("khan_process");

    sc_core::sc_start(10, sc_core::SC_NS); // Run the simulation for 10 ns

    return 0;
}