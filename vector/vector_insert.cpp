//
// Created by Arthur Zhang on 2019/6/26.
//


#include "vector.h"

template<typename T>
//将e作为秩为r元素插入
Rank Vector<T>::insert(Rank r, T const &e) {
    expand();   //如果有必要进行扩容
    for (int i = _size; i > r; --i) _elem[i] = _elem[i - 1];  //数据为左闭右开，从后向前依次后移一位
    _elem[r] = e;
    _size++;
    return r;
}
