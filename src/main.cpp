//
//  main.cpp
//  chordfinder~
//
//  Created by Francesco Perticarari on 09/01/2017.
//
//

#include "main.hpp"
#include "chordfinder~.hpp"

C74_EXPORT int main(void) {
    // create a class with the given name:
    Chordfinder::makeMaxClass("chordfinder~");
    
    //tell max which methods this object will use
    REGISTER_METHOD(Chordfinder, bang);
    REGISTER_METHOD_GIMME(Chordfinder, setRMS);
    REGISTER_METHOD_GIMME(Chordfinder, rate);
    REGISTER_METHOD_ASSIST(Chordfinder, assist);
    
    //REGISTER_METHOD_GIMME(Chordfinder, test);
}
