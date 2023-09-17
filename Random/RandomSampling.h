//
// Created by Niccolò Fabbri on 08/09/23.
//

#ifndef MTH9821_NUMERICALMETHODS_RANDOMSAMPLING_H
#define MTH9821_NUMERICALMETHODS_RANDOMSAMPLING_H

#include <vector>
#include "LCG.h"

std::vector<double> GenerateUniformSamples(int N, unsigned long long seed);
std::vector<double> GenerateNormalSamples(std::size_t N, unsigned long long seed);
double InverseTransformation(double u);
std::vector<double> BoxMuller(double N);
double AcceptanceRejection(std::vector<double>& uniform_samples, int& index);


#endif //MTH9821_NUMERICALMETHODS_RANDOMSAMPLING_H
