#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "..\Lab1\Sort.h"

template<class T>
///Class implements sorting by Bubble sort.
class BubbleSort : public Sort<T> {
private:
   
    /// This function  compares two objects of type T. 
    /// @returns If the objects are equal, the function returns 0, and if the first object is greater than the second, it returns 1, otherwise -1.
    int compare(T& a, T& b) {
        if (a == b) return 0;
        else return a > b;
    }
public:
    /// Method for sorting arrays by Bubble sort
     /// @param array is array we want to sort
     /// @param size is the size ot this array
     /// @warning The function will not work if the list is empty
    void sort(T* array, int size) {
        if ((size == 0))
            throw std::out_of_range("Your list is empty ");
            
        else {
            T temp;
            for (int i = 1; i < size; i++) {
                for (int j = 0; j < size - i; j++) {
                    if (compare(array[j], array[j + 1]) == 1) {
                        temp = array[j + 1];
                        array[j + 1] = array[j];
                        array[j] = temp;
                    }
                }
            }
        }
        
    }
};


#endif
