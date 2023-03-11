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
    void merge(T* arr, int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

       
        T* L = new T[n1];
       T* R = new T[n2];
        //T L[n1], R[n2];

        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2) {
            if (compare(L[i], R[j]) <= 0) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }


        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(T* arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;

            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            merge(arr, l, m, r);
        }
    }
    
public:
   
    void sort(T* arr, int size) override {
        mergeSort(arr, 0, size-1);
    }
};


#endif
