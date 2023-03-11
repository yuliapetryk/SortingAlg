#ifndef MERGESORT_H
#define MERGESORT_H

#include "..\Lab1\Sort.h"
#include <iostream>
using namespace std;
template<class T>
class MergeSort : public Sort<T> {
private:

    int compare(T& a, T& b) {
        if (a == b) return 0;
        else return a > b;
    }
    void merge(T* array, int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

       
        T* L = new T[n1];
       T* R = new T[n2];
        

        for (i = 0; i < n1; i++)
            L[i] = array[l + i];
        for (j = 0; j < n2; j++)
            R[j] = array[m + 1 + j];

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2) {
            if (compare(L[i], R[j]) <= 0) {
                array[k] = L[i];
                i++;
            }
            else {
                array[k] = R[j];
                j++;
            }
            k++;
        }


        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            array[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(T* array, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;

            mergeSort(array, l, m);
            mergeSort(array, m + 1, r);

            merge(array, l, m, r);
        }
    }
    
public:
   
    void sort(T* array, int size) override {
        mergeSort(array, 0, size-1);
    }
};


#endif
