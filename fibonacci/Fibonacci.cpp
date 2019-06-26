//
// Created by Administrator on 2019/5/18.
//


__int64 FibRecursive(int n) {
    return n < 2 ? n : FibRecursive(n - 1) + FibRecursive(n - 2);
}

__int64 FibLinerRecursive(int n, __int64 &prev) {
    if (n == 0) {
        prev = 1;
        return 0;
    } else {
        __int64 prevPrev;
        prev = FibLinerRecursive(n - 1, prevPrev);
        return prev + prevPrev;
    }
}

__int64 FibIterator(int n) {
    __int64 f = 1, g = 0;
    while (0 < n--) {
        g += f;
        f = g - f;
    }
    return g;
}