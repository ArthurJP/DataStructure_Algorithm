//
// Created by Arthur Zhang on 2019/6/27.
//


#include "vector.h"

template<typename T>
int Vector<T>::deduplicate() {
    Rank oldSize = _size;    //记录初始元素个数
    Rank i = 1;     //不比较Rank为0的元素
    while (i < _size) {
        find(_elem[i], 0, i) < 0 ? i++ : remove(i);     //当有重复的时候进行删除操作，没有重复的时候比较下一位
    }
    return oldSize - _size; //返回删除元素个数
}