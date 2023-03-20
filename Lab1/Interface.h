#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include "..\Lab1\ArrayList.h"
#include "..\Lab1\LinkedList.h"
#include "..\Lab1\BubbleSort.h"
#include "..\Lab1\InsertionSort.h"
#include "..\Lab1\MergeSort.h"
#include "..\Lab1\QuickSort.h"

class Interface {
private:

    void random_int(int count, List<int>* list);
    void random_string(int count, List<std::string>* list);
    void work_with_string_list();
    void  work_with_int_list();
public:
    void start();
};


#endif