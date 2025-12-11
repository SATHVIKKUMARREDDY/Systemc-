#ifndef PLACE_H
#define PLACE_H

#include<iostream>
#include <systemc>

template <class T>
class placeInterface : public sc_core::sc_interface{
  public :
    virtual void addTokens() = 0; 
    virtual void removeTokens() = 0;
    virtual bool testTokens() = 0;

};

template <class T, unsigned int Win=1, unsigned int Wout=1>
class place : public placeInterface<T>, public sc_core::sc_module {
    T tockens;
  public :
      place(sc_core::sc_module_name name, T initial_tokens =  0) : tockens(initial_tokens ){
         
      }

      void addTokens(){
        tockens+= Win;
      }

      void removeTokens(){
        if(tockens >= Wout){
          //sc_core::sc_report_handler::report(sc_core::SC_ERROR, "Not enough tokens to remove invlid operation");
          tockens -= Wout;
        }
        else  {
          SC_REPORT_ERROR(this->name(), "Not enough tokens to remove invalid operation");
        }

      }

      bool testTokens(){
        return tockens >= Wout;

      }
};

#endif