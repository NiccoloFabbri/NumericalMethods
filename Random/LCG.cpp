//
// Created by Niccolò Fabbri on 08/09/23.
//

// LCG.cpp
#include "LCG.h"

LCG::LCG(unsigned long long seed) : current(seed) {}

double LCG::next() {
    current = (a * current + c) % k;
    return static_cast<double>(current) / static_cast<double>(k);
}

void LCG::setSeed(unsigned long long seed) {
    current = seed;
}
