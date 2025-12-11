#ifndef TRANSITION_H
#define TRANSITION_H

#include<iostream>
#include <systemc>
#include "place.h"

template <class T, unsigned int N=1, unsigned int M=1, unsigned int L=0>
class transition : public sc_core::sc_module {
    public :
    sc_core::sc_port<placeInterface<T>, N, sc_core::SC_ALL_BOUND> in;
    sc_core::sc_port<placeInterface<T>, M, sc_core::SC_ALL_BOUND> out;
    sc_core::sc_port<placeInterface<T>, L, sc_core::SC_ZERO_OR_MORE_BOUND> inhibitors ;
  transition(sc_core::sc_module_name name) : sc_module(name){}
     

      void fire(){
        for(unsigned int i = 0; i < N; i++ ){ 
          if(in[i]->testTokens()){
            continue;
          }
          else {
            std::cout << this->name() << ": NOT Fired " <<  std::endl;
            return;
          }
        }
          for(unsigned int i = 0; i < L; i++ ){ 
          if(inhibitors[i]->testTokens()){
            std::cout << this->name() << ": NOT Fired " <<  std::endl;
            return;
          }

        }
        for(unsigned int i = 0; i < N; i++ ){
          in[i]->removeTokens();
        }
        for(unsigned int i = 0; i < M; i++ ){
          out[i]->addTokens();
        }
        std::cout << this->name() << ": Fired" << std::endl;
        return;
      }
};

#endif