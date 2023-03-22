#ifndef MENU_STRING
#define MENU_STRING

#include <iostream>
#include "..\Lab1\ArrayList.h"
#include "..\Lab1\LinkedList.h"
#include "..\Lab1\BubbleSort.h"
#include "..\Lab1\InsertionSort.h"
#include "..\Lab1\MergeSort.h"
#include "..\Lab1\QuickSort.h"
#include "Menu.h"

/// Ñlass implements user interaction with the program
class MenuString: public Menu {
private:
    
    ///Generate random string objects.
    /// @param count The number of elements
    /// @param list The list to which the elements will be generated
    void random_string(int count, List<std::string>* list);
    ///Demonstrates the operation of the list of string.
 
    ///Demonstrates the operation of the list of int.
   

   void menu_for_string(List<std::string>* list);
    void work_with_string_list(List<std::string>* list);
   
   
public:
    void  start_with_string_list();
};


#endif