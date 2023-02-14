
#ifndef LIST_H
#define LIST_H

#include "sstream"
#include "..\Lab1\Sort.h"
#include "..\Lab1\QuickSort.h"




template<class T>
class List {
public:
    
    virtual void add(T obj, int index = -1) = 0;

  
    virtual void remove(int index) = 0;

   
    virtual T& get(int index) = 0;

    
    virtual int find(T obj) = 0;

 
    virtual void clear() = 0;

   
    virtual void sort(Comparator<T>* comparator = nullptr) = 0;

    
    virtual void sort(Sort<T>* sort, Comparator<T>* comparator = nullptr) = 0;

    
    virtual int get_size() = 0;

   
    virtual std::string to_string() = 0;

    
    friend std::ostream& operator<<(std::ostream& out, List<T>& list) {
        out << list.to_string();
        return out;
    };

    
    bool operator==(List& rhs) {
        if (get_size() != rhs.get_size()) return false;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) != rhs.get(i)) return false;
        }
        return true;
    }

   
    bool operator!=(List& rhs) {
        return !(rhs == *this);
    }

    
    bool operator<(List& rhs) {
        if (get_size() == rhs.get_size()) {
            for (int i = 0; i < get_size(); i++) {
                if (get(i) < rhs.get(i)) return true;
            }
            return false;
        }
        return get_size() < rhs.get_size();
    }

   
    bool operator>(List& rhs) {
        return rhs < *this;
    }

   
    bool operator<=(List& rhs) {
        return !(rhs < *this);
    }

  
    bool operator>=(List& rhs) {
        return !(*this < rhs);
    }
};


#endif
