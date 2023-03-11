#ifndef SORT_H
#define SORT_H

template <class T>
class Sort {
public:
    virtual void sort(T* arr, int size) = 0;
};

#endif
