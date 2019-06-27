//
// Created by Arthur Zhang on 2019/6/26.
//


#include "vector.h"

template<typename T>
//删除指定元素
T Vector<T>::remove(Rank r) {
    T e = _elem[r]; //备份被删除元素
    remove(r, r + 1);   //调用区间删除算法，等效于删除[r,r+1>
    return e;
}
