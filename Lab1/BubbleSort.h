#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "..\Lab1\Sort.h"

template<class T>
class BubbleSort : public Sort<T> {
private:
    int compare(T& a, T& b) {
        if (a == b) return 0;
        else return a > b;
    }
public:
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
