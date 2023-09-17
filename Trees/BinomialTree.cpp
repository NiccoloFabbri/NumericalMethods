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
    discp(std::exp(-r * dt) * p),
    disc1p(std::exp(-r * dt) * (1. - p))
{}

// Pricing Function using Binomial Tree


double BinomialTree::price() const {
    std::vector<double> prices(N + 1);

    // Terminal values for a call option: Max between 0 and the stock price minus strike
    double S_temp = S0 * std::pow(u, N);
    double d2 = d * d;
    for (int i = 0; i <= N; ++i) {
        prices[i] = option->getPayoff(S_temp); // TO GENERALIZE
        S_temp *= d2;
    }

    // Backward induction
    for (int j = N - 1; j >= 0; --j) {
        for (int i = 0; i <= j; ++i) {
            prices[i] = discp * prices[i] + disc1p * prices[i + 1];
        }
    }

    return prices[0];
}
