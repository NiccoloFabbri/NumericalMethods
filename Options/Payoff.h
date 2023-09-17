//
// Created by Niccolò Fabbri on 16/09/23.
//

#ifndef MTH9821_NUMERICALMETHODS_PAYOFF_H
#define MTH9821_NUMERICALMETHODS_PAYOFF_H
#include <numeric>

class Payoff {
public:
    virtual ~Payoff() = default; // Virtual destructor for polymorphic base class
    virtual double operator()(double spot) const = 0; // Pure virtual function for calculating payoff
};
class CallPayoff : public Payoff {
    double K_; // Strike price
public:
    CallPayoff(double K) : K_(K) {}
    virtual double operator()(double spot) const override {
        return std::max(spot - K_, 0.0);
    }
};

class PutPayoff : public Payoff {
    double K_; // Strike price
public:
    PutPayoff(double K) : K_(K) {}
    virtual double operator()(double spot) const override {
        return std::max(K_ - spot, 0.0);
    }
};

#endif //MTH9821_NUMERICALMETHODS_PAYOFF_H
