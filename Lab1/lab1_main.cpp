#include "MenuInt.h"
#include "MenuString.h"
#include "..\Lab1\doctest.h"


//In order to turn off the text mode,
//do you need to comment the function doctest,
//namespase lab,
//and remove WITH_MAIN in the doctest.cpp file
//namespace lab {
   // int doctest() {
   //  doctest::Context context;
   //  return context.run();
   // }
 
int main() {
    // doctest();
    int type_in_list;
    std::cout << "---Choose type in List...\n"
        "[1] int\n"
        "[2] string\n" << std::endl;
    scanf("%d", &type_in_list);
    switch (type_in_list) {
    case 1:
        MenuInt menu;
        menu.start_with_int_list();
        break;
    case 2:
        MenuString menu_string;
        menu_string.start_with_string_list();
        break;
    default:
        MenuInt menu2;
        menu2.start_with_int_list();
    }
    return 0;
}

    
//}
