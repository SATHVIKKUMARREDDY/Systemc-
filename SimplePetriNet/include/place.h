#include<iostream>

template <class T>
SC_MODULE(placeInterface) : public sc_interface{


    virtual void addTokens(T n) = 0; 
    virtual void removeTokens(T n) = 0;
    virtual T int testTokens() = 0;

};

template <class T>
SC_MODULE(place) : public placeInterface{
    T tockens;
      SC_CTOR(place) : tockens(tockens =  0){
         
      }

      addTokens(T n){
        tockens+=n;
      }

      removeTokens(T n){
        if(n > tockens ) ;
        tockens -= n;

      }

      testTokens(){
        return tockens;

      }
};