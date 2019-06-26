//
// Created by Administrator on 2019/5/18.
//


#include "iostream"

using namespace std;

#include "fibonacci.h"
#include "Fibonacci.cpp"

__int64 FibRecursive(int n);
__int64 FibLinerRecursive(int n, __int64 &prev);
__int64 FibIterator(int n);

int main(int argc, char *argv[]) { //测试FIB
// 检查参数
    if (2 > argc) {
        fprintf(stderr, "Usage: %s <rank>\n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
// 依次计算Fibonacci数列各项
    printf("\n------------- class Fib -------------\n");
    Fib f(0);
    for (int i = 0; i < n; i++, f.next())
        printf("fib(%2d) = %d\n", i, f.get());
    for (int i = 0; i <= n; i++, f.prev())
        printf("fib(%2d) = %d\n", n - i, f.get());
    printf("\n------------- Iteration -------------\n");
    for (int i = 0; i < n; i++)    //%22I64d为win格式，linux为%22lld
        printf("fib(%2d) = %22lld\n", i, FibIterator(i));
    printf("\n------------- Linear Recursion -------------\n");
    for (int i = 0; i < n; i++) {
        __int64 f;
        printf("fib(%2d) = %22lld\n", i, FibLinerRecursive(i, f));
    }
    printf("\n------------- Binary Recursion -------------\n");
    for (int i = 0; i < n; i++)
        printf("fib(%2d) = %22lld\n", i, FibRecursive(i));
    return 0;
}