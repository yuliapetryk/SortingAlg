#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "..\Lab1\Sort.h"


template<class T>
class InsertionSort : public Sort<T> {
public:
    
   void sort(T* array, int size) override
    {
       if ((size == 0))
           throw std::out_of_range("Your list is empty ");
       T key;
        int i, j;
        for (i = 1; i < size; i++)
        {
            key = array[i];
            j = i - 1;

 
            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }
  
};

#endif
