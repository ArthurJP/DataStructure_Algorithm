//
// Created by Administrator on 2019/6/26.
//


#include "vector.h"

template<typename T>
T &Vector<T>::operator[](Rank r) const {
    if (r <= _size && r >= 0)
        return _elem[r];
    else
        return -1;
}