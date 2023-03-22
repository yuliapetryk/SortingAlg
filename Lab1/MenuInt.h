#ifndef MENU_INT
#define MENU_INT

#include <iostream>
#include "..\Lab1\ArrayList.h"
#include "..\Lab1\LinkedList.h"
#include "..\Lab1\BubbleSort.h"
#include "..\Lab1\InsertionSort.h"
#include "..\Lab1\MergeSort.h"
#include "..\Lab1\QuickSort.h"
#include "Menu.h"

/// Ñlass implements user interaction with the program
class MenuInt: Menu {
private:
    ///Generate random objects of the integer type.
    void random_int(int count, List<int>* list);
    ///Generate random string objects.
    /// @param count The number of elements
    /// @param list The list to which the elements will be generated
   
    
    
    void work_with_int_list(List<int>* list);
    
    void menu_for_int(List<int>* list);
    
    
    
   
public:
    ///Demonstrates the operation of the list of string.
    void  start_with_int_list();
    
};


#endif