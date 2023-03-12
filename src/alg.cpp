// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t  n) {
    double pow = value;
    if (n == 0.0) pow = 1;
    else 
    {for (uint16_t i = 1; i < n; i++) pow *= value;}
    return pow;
}

uint64_t fact(uint16_t n) {
    if (n <= 1) return 1;
    else 
    {return n * fact(n - 1);}
}

double calcItem(double x, uint16_t n) {
    double res = pown(x, n) / fact(n);
    return res;
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    while (count > 0) {
        sum += calcItem(x, count);
        count -= 1;
    }
    return sum+1;
}

double sinn(double x, uint16_t count) {
    double summ = x;
    while (count > 1) {
        summ += pown(-1, count - 1) * calcItem(x, 2 * count - 1);
        count -= 1;
    }
    return summ;
}

double cosn(double x, uint16_t count) {
    double summ = 1.0;
    while (count > 1) {
        summ += pown(-1, count - 1) * calcItem(x, 2 * count - 2);
        count -= 1;
    }
    return summ;
}
