
#ifndef VECTORLIST_H
#define VECTORLIST_H

#include "..\Lab1\List.h"
#include <vector>
#include <iostream>


template<class T>
class VectorList : public List<T> {
    std::vector<T> vect;    ///< Vector we work with.

public:
    
    ~VectorList() {
        clear();
    }

  
    void add(T obj, int index = -1) override {
        if (index < 0)
            index = vect.size();
        else if (index > vect.size())
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");

        if (index == vect.size()) vect.push_back(obj);
        else vect.insert(vect.begin() + index, obj);
    }


    void remove(int index) override {
        if ((index >= 0 && index >= vect.size()) || (index < 0 && vect.size() == 0))
            throw std::out_of_range(
                "index " + std::to_string(index) + " is greater then the size-1 :" + std::to_string(vect.size()));
        else if (index < 0)
            index = vect.size() - 1;

        vect.erase(vect.begin() + index);
    }

    
    T& get(int index) override {
        if ((index >= 0 && index >= vect.size()) || (index < 0 && vect.size() == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size-1");
        else if (index < 0)
            index = vect.size() - 1;

        return vect.at(index);
    }

   
    int find(T obj) override {
        int res = -1;

        for (int i = 0; i < vect.size(); i++) {
            if (vect[i] == obj) {
                res = i;
                break;
            }
        }
        return res;
    }

    void clear() override {
        vect.clear();
    }

   
    void sort(Comparator<T>* comparator = nullptr) override {
        QuickSort<T> quickSort;

        if (comparator) {
            quickSort.sort(&vect[0], vect.size(), comparator);
        }
        else {
            DefaultComparator<T> defaultComparator;
            quickSort.sort(&vect[0], vect.size(), &defaultComparator);
        }
    }

   
    void sort(Sort<T>* sort, Comparator<T>* comparator = nullptr) override {
        if (comparator) {
            sort->sort(&vect[0], vect.size(), comparator);
        }
        else {
            DefaultComparator<T> defaultComparator;
            sort->sort(&vect[0], vect.size(), &defaultComparator);
        }
    }

   

    static void sort(std::vector<T> global_vector, Sort<T>* sort, Comparator<T>* comparator = nullptr) {
        if (sort) {
            if (comparator) {
                sort->sort(&global_vector[0], global_vector.size(), comparator);
            }
            else {
                DefaultComparator<T> defaultComparator;
                sort->sort(&global_vector[0], global_vector.size(), &defaultComparator);
            }
        }
        else {
            QuickSort<T> quickSort;

            if (comparator) {
                quickSort.sort(&global_vector[0], global_vector.size(), comparator);
            }
            else {
                DefaultComparator<T> defaultComparator;
                quickSort.sort(&global_vector[0], global_vector.size(), &defaultComparator);
            }
        }
    }

    int get_size() override {
        return vect.size();
    }

  
    std::string to_string() override {
        std::stringstream ss;

        ss << '[';
        if (vect.size() != 0) {
            for (int i = 0; i < vect.size() - 1; i++) {
                ss << vect[i] << ", ";
            }
            ss << vect[vect.size() - 1];
        }
        ss << ']';

        return ss.str();
    }
};

#endif