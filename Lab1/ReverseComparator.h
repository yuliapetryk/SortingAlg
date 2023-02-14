
#ifndef REVERSECOMPARATOR_H
#define REVERSECOMPARATOR_H

#include "..\Lab1\Comparator.h"

/**
 * @brief
 * Class implements the Comparator interface and compare object reverse.
 * @tparam  T   Class or primitive with override relational and equality operators.
 */
template <class T>
class ReverseComparator : public Comparator<T> {
public:
    
    int compare(T& a, T& b) override {
        if (a == b) return 0;
        else return a < b;
    }
};

#endif