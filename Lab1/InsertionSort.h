#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "..\Lab1\Sort.h"


template<class T>
class InsertionSort : public Sort<T> {
public:

    
   void sort(int arr[], int n)
    {
        int i, key, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;

 
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
  
};

#endif
