//
// Created by Niccolò Fabbri on 15/09/23.
//

#ifndef MTH9821_NUMERICALMETHODS_BINOMIALTREE_H
#define MTH9821_NUMERICALMETHODS_BINOMIALTREE_H
#include "../Options/Option.h"
#include <iostream>

// Tree result -> visualize output
struct TreeResult{
    double value;
    double delta;
    double gamma;
    double theta;
    friend inline std::ostream& operator<<(std::ostream& os, const TreeResult& tr);
};
inline std::ostream& operator<<(std::ostream& os, const TreeResult& tr) {
    os << "Value: " << tr.value << '\n'
       << "Delta: " << tr.delta << '\n'
       << "Gamma: " << tr.gamma << '\n'
       << "Theta: " << tr.theta;
    return os;
}

enum class PricingMethod {
    Standard,
    Average,
    BBS,
    BBSR
};


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
    double edt; // e^(-rT)
    double discp; //
    double disc1p; //


    std::vector<std::vector<double>> StandardPrice();
    //std::vector<std::vector<double>> BBsPrice();
    std::vector<std::vector<double>> PathIndepPricer(std::vector<std::vector<double>> prices);
    std::vector<std::vector<double>> PathDepPricer(std::vector<std::vector<double>> prices);
public:
    BinomialTree(Option* opt, double N_);
    std::vector<std::vector<double>> price(PricingMethod method);
    TreeResult execute(PricingMethod method);

};


#endif //MTH9821_NUMERICALMETHODS_BINOMIALTREE_H
