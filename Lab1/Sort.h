#ifndef SORT_H
#define SORT_H

template <class T>
class Sort {
public:
    virtual void sort(T* arr, int size) = 0;
    int compare(T& a, T& b)  {
        if (a == b) return 0;
        else return a < b;
    }
};

#endif
