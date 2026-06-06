// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result *= value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t result = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / static_cast<double>(fact(n));
}

double expn(double x, uint16_t count) {
    double sum = 0.0;
    // Суммируем от n=0 до n=count (включительно) — всего count+1 членов
    for (uint16_t n = 0; n <= count; ++n) {
        sum += calcItem(x, n);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = 0.0;
    // Для синуса: степени 1,3,5,... до 2*count+1
    for (uint16_t n = 0; n <= count; ++n) {
        uint16_t power = 2 * n + 1;
        double term = pown(x, power) / static_cast<double>(fact(power));
        if (n % 2 == 1) {
            term = -term;
        }
        sum += term;
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 0.0;
    // Для косинуса: степени 0,2,4,... до 2*count
    for (uint16_t n = 0; n <= count; ++n) {
        uint16_t power = 2 * n;
        double term = pown(x, power) / static_cast<double>(fact(power));
        if (n % 2 == 1) {
            term = -term;
        }
        sum += term;
    }
    return sum;
}
