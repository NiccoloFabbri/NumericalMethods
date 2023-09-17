
#include "Option.h"

Option::Option(double S0, double K, double T, double sigma, double r, double q, OptionType type)
        : S0_(S0), K_(K), T_(T), sigma_(sigma), r_(r), q_(q)
        {if (type == OptionType::Call){
            payoff_ = std::make_unique<CallPayoff>(K);
        }
        else{
            payoff_ = std::make_unique<PutPayoff>(K);
        }}
