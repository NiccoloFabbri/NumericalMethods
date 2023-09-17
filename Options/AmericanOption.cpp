//
// Created by Niccolò Fabbri on 16/09/23.
//

#include "AmericanOption.h"
double AmericanOption::getPayoff(double spot) const {
    return (*payoff_)(spot); // use payoff class
}

bool AmericanOption::isAmerican() const { return true;}

double AmericanOption::price() const {return 0;};