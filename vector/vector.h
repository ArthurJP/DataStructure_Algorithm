//
// Created by Administrator on 2019/5/20.
//

#ifndef ALGORITHM_VECTOR_H
#define ALGORITHM_VECTOR_H

typedef int Rank;  //秩
#define DEAFULT_CAPACITY 5  //默认的初始容量（实际应用中可设置为更大）

template<typename T>
class Vector {  //向量模板类

protected:

    Rank _size; //规模
    int _capacity;  //容量
    T *_elem;  //数据区

    void copyFrom(T const *A, Rank lo, Rank hi);    //复制数组区间A[lo, hi)

    void expand(); //空间不足时扩容

    void shrink();  //装填因子过小时压缩

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

    Vector(T const *A, Rank n) {    //数组长度复制
        copyFrom(A, 0, n);
    }

    Vector(T const *A, Rank lo, Rank hi) {      //数组区间复制
        copyFrom(A, lo, hi);
    }

    Vector(Vector<T> const &V) {     //向量整体复制
        copyFrom(V._elem, 0, V._size);
    }

    Vector(Vector<T> const &V, Rank lo, Rank hi) {      //向量区间复制
        copyFrom(V._elem, lo, hi);
    }

//    析构函数
    ~Vector() { delete[] _elem; }    //释放内存资源

// 只读访问接口
    Rank find(T const &e) const { return find(e, 0, _size); }   //查找无序向量整体

    Rank find(T const &e, Rank lo, Rank hi) const;      //查找无序向量区间

// 可写访问接口
    T &operator[](Rank r) const;    //重载下标操作符，可以类似于数组形式引用各元素

    Rank insert(Rank r, T const &e);    //指定位置插入元素

    Rank insert(T const &e) { return insert(_size, e); }    //默认在末尾插入元素

    T remove(Rank r);   //删除指定位置元素

    int remove(Rank lo, Rank hi);    //删除区间元素

    int deduplicate();      //无序元素去重

// 遍历
    void traverse(void (*visit)(T &));  //这里的参数是一个函数，函数名称为visit，使用其指针来调用

    template<typename VST>
    void traverse(VST &visit);  //使用函数对象做为参数，使用引用来调用
};

#endif //ALGORITHM_VECTOR_H
