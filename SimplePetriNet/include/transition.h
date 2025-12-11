#include<iostream>

template <class T>
SC_MODULE(transition) {
    sc_port<placeInterface> in, out;
      SC_CTOR(transition){
         
      }

      void fire(){
        if(in.testTokens >= 1){
            std::cout << this->name() << ": Fired" << std::endl;
            in.removeTokens(1);
            out.addTokens(1);
        }
        else {
            std::cout << this->name() << ": NOT Fired" << std::endl;
        }
      }
};