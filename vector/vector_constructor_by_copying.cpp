//
// Created by Administrator on 2019/6/26.
//


#include "vector.h"

template<typename T>
//元素类型
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi) {
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi) {
        _elem[_size++] = A[lo++];
    }
    return;
}