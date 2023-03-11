#ifndef ARRAYLIST_H
#define ARRAYLIST_H


#include "..\Lab1\List.h"

template<class T>
class ArrayList : public List<T> {
private:
    int size = 0;           
    int array_size = 2;        
    T* array = new T[16];      

    void change_array_size(int new_size) {
        while (new_size <= size) new_size *= 2;

        T* temp = new T[new_size];
        for (int i = 0; i < array_size; i++) {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        array_size = new_size;
    }

public:
     ~ArrayList() {
        delete[] array;
    }

   
    void add(T obj, int index = -1) override {
        if (index < 0)
            index = size;
        else if (index > size)
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");

        if (size == array_size)
            change_array_size(array_size / 2 * 3 + 2);

        T temp1 = obj;
        T temp2;
        while (index <= size) {
            temp2 = array[index];
            array[index] = temp1;
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
            array[i] = array[i + 1];
        }
        size--;
    }

    
    T& get(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size-1");
        else if (index < 0)
            index = size - 1;

        return array[index];
    }

   
    int find(T obj) override {
        int res = -1;
        for (int i = 0; i < size; i++) {
            if (array[i] == obj) {
                res = i;
                break;
            }
        }
        return res;
    }

    
    void clear() override {
        delete[] array;
        size = 0;
        array_size = 16;
        array = new T[array_size];
    }

    
    void sort(Sort<T>* sort) override {
      sort->sort(array, size);
        
    }

    
    static void sort(T* global_array, int global_size, Sort<T>* sort = nullptr)  {
     QuickSort<T> quickSort;
    quickSort.sort(global_array, global_size);
     
    }

    int get_size() override {
        return size;
    }

 
    std::string to_string() override {
        std::stringstream ss;
        ss << '[';
        if (size != 0) {
            for (int i = 0; i < size - 1; i++) {
                ss << array[i] << ", ";
            }
            ss << array[size - 1];
        }
        ss << ']';

        return ss.str();
    }
};

#endif