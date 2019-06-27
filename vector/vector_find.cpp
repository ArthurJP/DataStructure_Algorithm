//
// Created by Arthur Zhang on 2019/6/27.
//


#include "vector.h"

template<typename T>
//查找无序向量中的元素：查找成功返回元素位置，查找失败返回lo-1
Rank Vector<T>::find(const T &e, Rank lo, Rank hi) const {
    if (lo < 0 or hi > _size) return -1;    //防止越界
    while ((lo < hi--) && (e != _elem[hi]));    //从后向前依次查找，这里最后lo==hi时，hi仍会再执行依次--
    return hi;
}