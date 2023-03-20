#include "Interface.h"
#include "..\Lab1\doctest.h"


//In order to turn off the text mode,
//do you need to comment the function doctest,
//namespase lab,
//and remove WITH_MAIN in the doctest.cpp file
namespace lab {
    int doctest() {
     doctest::Context context;
     return context.run();
    }

int main() {
    doctest();
    Interface user_interface;
    user_interface.start();
   
    return 0;
}

    
}
