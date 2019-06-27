//
// Created by Arthur Zhang on 2019/6/26.
//


#include "vector.h"

template<typename T>
void Vector<T>::shrink() {
    if (_capacity < DEAFULT_CAPACITY << 1) return;  //防止缩容到默认容量以下
    if (_size << 2 > _capacity) return;  //25%为最低装填因子
    T *oldElem = _elem;
    _elem = new T[_capacity >> 1];
    for (int i = 0; i < _size; ++i) _elem[i] = oldElem[i];
    delete[] oldElem;
}