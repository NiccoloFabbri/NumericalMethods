//
// Created by Niccolò Fabbri on 15/09/23.
//

#ifndef MTH9821_NUMERICALMETHODS_BINOMIALTREE_H
#define MTH9821_NUMERICALMETHODS_BINOMIALTREE_H
#include "../Options/Option.h"


class BinomialTree{

private:
    Option *option; // constructor given an Option obj

    double S0; // Underlying price at time 0
    double K; // strike price
    double T; // Maturity
    double sigma; // volatility
    double q; // dividend rate
    double r; // interest rate

    int N; // Number of time steps
    double dt; // increment every
    double u; // up
    double d; // down (1/u)
    double p; // helper
    double discp; //
    double disc1p; //

public:
    BinomialTree(Option* opt, double N_);

    double price() const;


};


#endif //MTH9821_NUMERICALMETHODS_BINOMIALTREE_H
