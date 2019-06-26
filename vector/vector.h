//
// Created by Administrator on 2019/5/20.
//

#ifndef ALGORITHM_VECTOR_H
#define ALGORITHM_VECTOR_H

typedef int Rank;  //秩
#define DEAFULT_CAPACITY 3  //默认的初始容量（实际应用中可设置为更大）

template<typename T>

class Vector {  //向量模板类

protected:

    Rank _size; //规模
    int _capacity;  //容量
    T *_elem;  //数据区

    void copyFrom(T const *A, Rank lo, Rank hi);

public:
    // 构造函数
    Vector(int c = DEAFULT_CAPACITY, int s = 0, T v = 0) {  //容量为c、规模为s、所有元素初始为v
        if (s < c) {
            _elem = new T[_capacity = c];
        } else {
            _elem = new T[_capacity = s];
        }
        for (_size = 0; _size < s; _elem[_size++] = v);
    }

    Vector(T const *A, Rank n) {
        copyFrom(A, 0, n);
    }

    Vector(T const *A, Rank lo, Rank hi) {
        copyFrom(A, lo, hi);
    }

    Vector(Vector<T> const &V) {
        copyFrom(V._elem, 0, V._size);
    }

    Vector(Vector<T> const &V, Rank lo, Rank hi) {
        copyFrom(V._elem, lo, hi);
    }

//    析构函数
    ~Vector() {
        delete[] _elem;
    }

// 只读访问接口



// 可写访问接口
    T &operator[](Rank r) const;

    Rank insert(Rank r, T const &e);

    Rank insert(T const &e) { return insert(_size, e); }

// 遍历

};

#endif //ALGORITHM_VECTOR_H
