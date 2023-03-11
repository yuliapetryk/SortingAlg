#ifndef SORT_H
#define SORT_H

template <class T>
class Sort {
public:
    virtual void sort(T* array, int size) = 0;
};

#endif
