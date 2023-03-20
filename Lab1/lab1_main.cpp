#include "..\Lab1\doctest.h"
#include "Interface.h"
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
        start();
        return 0;

    }
}
