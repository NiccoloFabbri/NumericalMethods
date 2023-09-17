//
// Created by Niccolò Fabbri on 08/09/23.
//

#ifndef MTH9821_NUMERICALMETHODS_LCG_H
#define MTH9821_NUMERICALMETHODS_LCG_H
// LCG.h

class LCG {
private:
    // Parameters
    unsigned long long a = 39373;
    unsigned long long c = 0;
    unsigned long long k = (1ULL << 31) - 1; // 2^31 - 1
    unsigned long long current;

public:
    LCG(unsigned long long seed);

    // Generate the next pseudorandom number
    double next();

    // Set seed value
    void setSeed(unsigned long long seed);
};





#endif //MTH9821_NUMERICALMETHODS_LCG_H
