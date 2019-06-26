//
// Created by Administrator on 2019/5/14.
//


#include "iostream"

using namespace std;

void max2with2loop(int A[], int lo, int hi, int &x1, int &x2) {  //O(2n-3)
    x1 = lo;
    for (int i = lo + 1; i < hi; ++i) {
        if (A[i] > A[x1]) x1 = i;
    }
    x2 = lo;
    for (int i = lo + 1; i < x1; ++i) {
        if (A[i] > A[x2]) x2 = i;
    }
    for (int i = x1 + 1; i < hi; ++i) {
        if (A[i] > A[x2]) x2 = i;
    }
}

void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

void max2with1loop(int A[], int lo, int hi, int &x1, int &x2) {  //O(n-1)~O(2n-3)
    if (A[x1 = lo] < A[x2 = lo + 1]) swap(x1, x2);
    for (int i = lo + 2; i < hi; ++i) {
        if (A[x2] < A[i]) {
            if (A[x1] < A[x2 = i]) swap(x1, x2);
        }
    }
}

void max2byDivideAndConquer(int A[], int lo, int hi, int &x1, int &x2) {  //O(n-1)~O(5/3n-2)
    if (lo + 2 > hi) {
        x1 = x2 = -1;
        return;
    }

    if (lo + 2 == hi) {
        if (A[x1 = lo] < A[x2 = lo + 1]) swap(x1, x2);
        return;
    }
    if (lo + 3 == hi) {
        if (A[x1 = lo] < A[x2 = lo + 1]) swap(x1, x2);
        if (A[x2] < A[lo + 2])
            if (A[x1] < A[x2 = lo + 2]) swap(x1, x2);
        return;
    }
    int mi = (lo + hi) >> 1;
    int x1L, x2L;
    max2byDivideAndConquer(A, lo, mi, x1L, x2L);
    int x1R, x2R;
    max2byDivideAndConquer(A, mi, hi, x1R, x2R);
    if (A[x1L] > A[x1R]) {
        x1 = x1L;
        x2 = A[x2L] > A[x1R] ? x2L : x1R;
    } else {
        x1 = x1R;
        x2 = A[x1L] > A[x2R] ? x1L : x2R;
    }
}

int main() {
    int arr[] = {56, -89, 500, 22, 4, 5, 7, 89, 156, -8};

    int x1 = 0, x2 = 1;
//    max2with2loop(arr, 0, 10, x1, x2);
//    max2with1loop(arr, 0, 10, x1, x2);
    max2byDivideAndConquer(arr, 0, 10, x1, x2);
    cout << x1 << " " << x2;

    return 1;
}