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
    int partition(T* arr, int low, int high)
    {
       T pivot = arr[high];
        int i
            = (low
                - 1); 

        for (int j = low; j <= high - 1; j++) {
     
            if (arr[j] < pivot) {
                i++; 
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i + 1], &arr[high]);
        return (i + 1);
    }

 
    void quickS(T* arr, int const low, int const high)
    {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickS(arr, low, pi - 1);
            quickS(arr, pi + 1, high);
        }
    }


public:
   
    void sort(T* arr, int size) override {
       quickS(arr, 0,size - 1);
    }
};


#endif
