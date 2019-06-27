//
// Created by Arthur Zhang on 2019/6/26.
//


#include "vector.h"

template<typename T>
void Vector<T>::expand() {
    if (_size < _capacity) return;  //尚未满员时，不必扩容
    if (_capacity < DEAFULT_CAPACITY) _capacity = DEAFULT_CAPACITY; //不低于最小容量
    T *oldElem = _elem;
    _elem = new T[_capacity <<= 1]; //容量加倍
    for (int i = 0; i < _size; ++i) {
        _elem[i] = oldElem[i];  //复制原向量内容（T为基本类型，或已重载赋值操作符'='）
    }
    printf("\n_ELEM [%x]*%d/%d expanded and shift to [%x]*%d/%d\n", oldElem, _size, _capacity / 2, _elem, _size,
           _capacity);
    delete[] oldElem; //释放原空间
}

