
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include "..\Lab1\List.h"


template<class T>
class ArrayList : public List<T> {
private:
    int size = 0;            ///< Value for saving count of elements in ArrayList.
    int arr_size = 2;        ///< Value for saving size of array in ArrayList.
    T* arr = new T[16];      ///< Array with elements.

    
    void change_arr_size(int new_size) {
        while (new_size <= size) new_size *= 2;

        T* temp = new T[new_size];
        for (int i = 0; i < arr_size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        arr_size = new_size;
    }

public:
     ~ArrayList() {
        delete[] arr;
    }

    
    void add(T obj, int index = -1) override {
        if (index < 0)
            index = size;
        else if (index > size)
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");

        if (size == arr_size)
            change_arr_size(arr_size / 2 * 3 + 2);

        T temp1 = obj;
        T temp2;
        while (index <= size) {
            temp2 = arr[index];
            arr[index] = temp1;
            std::swap(temp1, temp2);
            index++;
        }
        size++;
    }

  
    void remove(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size-1");
        else if (index < 0)
            index = size - 1;

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    
    T& get(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size-1");
        else if (index < 0)
            index = size - 1;

        return arr[index];
    }

   
    int find(T obj) override {
        int res = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == obj) {
                res = i;
                break;
            }
        }
        return res;
    }

    
    void clear() override {
        delete[] arr;
        size = 0;
        arr_size = 16;
        arr = new T[arr_size];
    }

    
    void sort(Comparator<T>* comparator = nullptr) override {
        QuickSort<T> quickSort;

        if (comparator) {
            quickSort.sort(arr, size, comparator);
        }
        else {
            DefaultComparator<T> defaultComparator;
            quickSort.sort(arr, size, &defaultComparator);
        }
    }

   
    void sort(Sort<T>* sort, Comparator<T>* comparator = nullptr) override {
        if (comparator) {
            sort->sort(arr, size, comparator);
        }
        else {
            DefaultComparator<T> defaultComparator;
            sort->sort(arr, size, &defaultComparator);
        }
    }

    
    static void sort(T* global_arr, int global_size, Sort<T>* sort = nullptr, Comparator<T>* comparator = nullptr) {
        if (sort) {
            if (comparator) {
                sort->sort(global_arr, global_size, comparator);
            }
            else {
                DefaultComparator<T> defaultComparator;
                sort->sort(global_arr, global_size, &defaultComparator);
            }
        }
        else {
            QuickSort<T> quickSort;

            if (comparator) {
                quickSort.sort(global_arr, global_size, comparator);
            }
            else {
                DefaultComparator<T> defaultComparator;
                quickSort.sort(global_arr, global_size, &defaultComparator);
            }
        }

    }

    
    int get_size() override {
        return size;
    }

 
    std::string to_string() override {
        std::stringstream ss;
        ss << '[';
        if (size != 0) {
            for (int i = 0; i < size - 1; i++) {
                ss << arr[i] << ", ";
            }
            ss << arr[size - 1];
        }
        ss << ']';

        return ss.str();
    }
};

#endif