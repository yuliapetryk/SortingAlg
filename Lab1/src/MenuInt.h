#ifndef MENU_INT
#define MENU_INT

#include <iostream>
#include "ArrayList.h"
#include "LinkedList.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Menu.h"

/// Class implements user interaction with the program if we have a list with integer elements
class MenuInt: Menu {
private:
    ///A method to generate random objects of the integer type.
    /// @param count The number of elements
    /// @param list The list to which the elements will be generated
    void random_int(int count, List<int>* list);
   
    /// A method to start a work with a list with integer elements
    /// @param list The list we work with
    void work_with_int_list(List<int>* list);

    /// A method for demonstrating available functionality
    /// @param list The list we work with
    void menu_for_int(List<int>* list);

    /// A method to call a method to generate random integer elements 
   /// @param list The list we work with
    void command_random(List<int>* list);

    /// A method to call a method to add an element to the list
    /// @param list The list we work with
    void command_add(List<int>* list);

    /// A method to call a method to print the index of the specified element
    /// @param list The list we work with
    void command_find(List<int>* list);
 
public:
    /// A method to demonstrate working with the list 
    void  start_with_int_list();
    
};


#endif