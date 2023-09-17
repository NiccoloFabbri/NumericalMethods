#pragma once
#include "Payoff.h"

class BinomialTree;  // Forward declaration to avoid header mistakes


enum class OptionType {
    Call,
    Put
};

class Option {
    friend class BinomialTree;  // Declare BinomialTree as a friend
protected:
    double S0_, K_, T_, sigma_, r_, q_;
    std::unique_ptr<Payoff> payoff_; // load payoff function

public:
    Option(double S0, double K, double T, double sigma, double r, double q, OptionType type);
    virtual double price() const = 0;
    virtual double getPayoff(double spot) const = 0;
    virtual bool isAmerican() const = 0;
};