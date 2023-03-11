#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>
#include "..\Lab1\Sort.h"

template<class T>
class QuickSort : public Sort<T> {
private:
    void swap(T* a, T* b)
    {
        T t = *a;
        *a = *b;
        *b = t;
    }
    int partition(T* array, int low, int high)
    {
       T pivot = array[high];
        int i
            = (low
                - 1); 

        for (int j = low; j <= high - 1; j++) {
     
            if (array[j] < pivot) {
                i++; 
                swap(&array[i], &array[j]);
            }
        }
        swap(&array[i + 1], &array[high]);
        return (i + 1);
    }

 
    void quickSort(T* array, int const low, int const high)
    {
        if (low < high) {
            int pi = partition(array, low, high);
            quickSort(array, low, pi - 1);
            quickSort(array, pi + 1, high);
        }
    }


public:
   
    void sort(T* array, int size) override {
       quickSort(array, 0,size - 1);
    }
};


#endif
