#include "collatz_sequence.h"

std::vector<int> collatz_sequence(int n) {
    std::vector<int> seq;
    while (n != 1) {
        seq.push_back(n);
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }
    seq.push_back(1);
    return seq;
}

