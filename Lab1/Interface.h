#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "..\Lab1\ArrayList.h"
#include "..\Lab1\LinkedList.h"
#include "..\Lab1\BubbleSort.h"
#include "..\Lab1\InsertionSort.h"
#include "..\Lab1\MergeSort.h"
#include "..\Lab1\QuickSort.h"

/// Ñlass implements user interaction with the program

class Interface {
private:
    ///Generate random objects of the integer type.
    void random_int(int count, List<int>* list);
    ///Generate random string objects.
    /// @param count The number of elements
    /// @param list The list to which the elements will be generated
    void random_string(int count, List<std::string>* list);
    ///Demonstrates the operation of the list of string.
    void work_with_string_list();
    ///Demonstrates the operation of the list of int.
    void  work_with_int_list();
public:
    ///Start working.
    void start();
};


#endif