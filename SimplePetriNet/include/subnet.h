#ifndef SUBNET_H
#define SUBNET_H

#include<iostream>
#include<systemc>
#include"place.h"
#include"transition.h"

SC_MODULE(subnet){

    place<unsigned int,1 , 1>& IDLE;
    place<unsigned int,1 , 1> ACTIVE;
    
    transition<unsigned int, 1, 1> RD, WR, PRE;  
    transition<unsigned int, 1, 1, 1> ACT;  
    

    subnet(sc_core::sc_module_name name, place<unsigned int,1,1>& idle)
        : sc_module(name),
          IDLE(idle),
          ACTIVE("ACTIVE", 0),
          ACT("ACT"), RD("RD"), WR("WR"), PRE("PRE")
    {
        ACT.in.bind(IDLE);
        ACT.out.bind(ACTIVE);
        ACT.inhibitors.bind(ACTIVE);
        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);
        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);
        PRE.in.bind(ACTIVE);
        PRE.out.bind(IDLE);

    }
};

#endif