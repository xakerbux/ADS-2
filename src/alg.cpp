// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
    double result = 1.0;
    for (uint16_t i = 0; i < n; ++i) {
        result = result * value;
    }
    return result;
}

uint64_t fact(uint16_t n) {
    uint64_t answer = 1;
    for (uint16_t i = 2; i <= n; ++i) {
        answer = answer * i;
    }
    return answer;
}

double calcItem(double x, uint16_t n) {
    double numerator = pown(x, n);
    double denominator = static_cast<double>(fact(n));
    return numerator / denominator;
}

double expn(double x, uint16_t count) {
    double total = 1.0;
    for (uint16_t idx = 1; idx <= count; ++idx) {
        total = total + calcItem(x, idx);
    }
    return total;
}

double sinn(double x, uint16_t count) {
    double total = 0.0;
    for (uint16_t term = 1; term <= count; ++term) {
        uint16_t power = 2 * term - 1;
        double value = pown(x, power) / static_cast<double>(fact(power));
        if ((term - 1) % 2 == 0) {
            total = total + value;
        } else {
            total = total - value;
        }
    }
    return total;
}

double cosn(double x, uint16_t count) {
    double total = 0.0;
    for (uint16_t term = 1; term <= count; ++term) {
        uint16_t power = 2 * term - 2;
        double value = pown(x, power) / static_cast<double>(fact(power));
        if ((term - 1) % 2 == 0) {
            total = total + value;
        } else {
            total = total - value;
        }
    }
    return total;
}
