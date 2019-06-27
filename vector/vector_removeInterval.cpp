//
// Created by Arthur Zhang on 2019/6/26.
//


#include "vector.h"

template<typename T>
//删除区间[lo,hi)
int Vector<T>::remove(Rank lo, Rank hi) {
    if (lo == hi) return 0; //出于效率考虑，单独处理退化情况，比如remove(0, 0)
    while (hi < _size) _elem[lo++] = _elem[hi++];   //[hi,_size)依次前移hi-lo个位置
    _size = lo; //更新size大小，此时lo已经更新为末位
    shrink();   //防止出现装填因子过小的状况
    return hi - lo;
}