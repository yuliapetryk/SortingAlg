#ifndef SORT_H
#define SORT_H

template <class T>
/// Class implements Sort.
class Sort {
public:
   
    /// Virtual method for sort arrays
    /// @param array is array we want to sort
    /// @param size is the size ot this array
    virtual void sort(T* array, int size) = 0;
};

#endif
