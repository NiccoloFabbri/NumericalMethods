//
// Created by Niccolò Fabbri on 15/09/23.
//
#include <iostream>
#include <cmath>
#include "BinomialTree.h"
#include "../Options/Option.h"
#include <vector>

// Constructor with option
BinomialTree::BinomialTree(Option* opt, double N_):
    option(opt),
    S0(opt->S0_),
    K(opt->K_),
    T(opt->T_),
    sigma(opt->sigma_),
    r(opt->r_),
    q(opt->q_),
    N(N_),
    dt(T / N),
    u(std::exp(sigma * std::sqrt(dt))),
    d(1. / u),
    p((std::exp((r - q) * dt) - d) / (u - d)),
    edt(std::exp(-r * dt)),
    discp(edt * p),
    disc1p(edt * (1. - p))
{}

// Pricing Function using Binomial Tree

std::vector<std::vector<double>> BinomialTree::price(PricingMethod method) {

    std::vector<std::vector<double>> Vi;

    //if(method == PricingMethod::BBS){
        //Vi = this->BBsPrice();
        //return BBsPrice() // INSTANTLY RETURN
    //}
    //else if(method == PricingMethod::BBSR){
        //Vi = ;
    //}
    if (method == PricingMethod::Standard){
        Vi = this->StandardPrice();
    }
    else{
        std::cout << "Pricing method not contemplated" << std::endl;
    }

    if (option->isAmerican()) {
        return PathDepPricer(Vi);
    } else {
        return PathIndepPricer(Vi);
    }
}
// PRICING METHODS
// Terminal values for a call option: Max between 0 and the stock price minus strike
std::vector<std::vector<double>> BinomialTree::StandardPrice(){
    std::vector<std::vector<double>> prices(N + 1, std::vector<double>(N + 1));
    double S_temp = S0 * std::pow(u, N);
    double d2 = d * d;
    for (int i = 0; i <= N; ++i) {
        prices[N][i] = option->getPayoff(S_temp); // TO GENERALIZE
        S_temp *= d2;
    }
    return prices;
}






// PATH INDEPENDENT (EUROPEAN OPTION)
std::vector<std::vector<double>> BinomialTree::PathIndepPricer(std::vector<std::vector<double>> prices) {

    // Backward induction
    for (int j = N - 1; j >= 0; --j) {
        for (int i  = 0; i <=j; ++i) {
            prices[j][i] = discp * prices[j + 1][i] + disc1p * prices[j + 1][i + 1];
        }
    }
    return prices;
}

//PATH DEPENDENT (AMERICAN OPTIONS)
std::vector<std::vector<double>> BinomialTree::PathDepPricer(std::vector<std::vector<double>> prices) {

    // Backward induction for american options
    for (int j = N - 1; j >= 0; --j) {
        for (int i  = 0; i <=j; ++i) {
            double x1 = discp * prices[j + 1][i] + disc1p * prices[j + 1][i + 1];
            double x2 = std::max(option->getPayoff(S0 * std::pow(u, j-i) * std::pow(d, i)), 0.0);
            prices[j][i] = std::max(x1, x2);
        }
    }
    return prices;
}





TreeResult BinomialTree::execute(PricingMethod method) {

    std::vector<std::vector<double>> prices = this->price(method);
    double delta = (prices[1][0] - prices[1][1]) / (S0 * (u - d));

    double s22 = S0 * u * u;
    double s20 = S0 * d * d;
    double gamma = ((prices[2][0] - prices[2][1]) /
            (s20 - S0))  - ((prices[2][1] - prices[2][2])/ (S0 - s22))
            / ((s20 - s22) / 2);

    double theta = (prices[2][1] - prices[0][0]) / (2 * dt);
    return TreeResult({prices[0][0], delta, gamma, theta });
}



// HELPER FUNCTIONS
// copy constructor
