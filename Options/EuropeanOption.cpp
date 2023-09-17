//
// Created by Niccolò Fabbri on 15/09/23.
//

#include "EuropeanOption.h"
#include <numeric>
#include <cmath>

double EuropeanOption::N(double x) {
    return 0.5 * std::erfc(-x * M_SQRT1_2);
}
// pricing function

double EuropeanOption::price() const {
    double d1 = (std::log(S0_ / K_) + (r_ + 0.5 * sigma_ * sigma_) * T_) / (sigma_ * std::sqrt(T_));
    double d2 = d1 - sigma_ * std::sqrt(T_);

    return K_ * std::exp(-r_ * T_) * N(-d2) - S0_ * N(-d1) * std::exp( -q_ * T_);
}

double EuropeanOption::getPayoff(double spot) const {
    return (*payoff_)(spot); // use payoff class
}