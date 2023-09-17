

#include <iostream>
#include "Options/EuropeanOption.h"
#include "Trees/BinomialTree.h"
#include "Options/Option.h"

int  main() {
    EuropeanOption putOpt(54.0, 50.0, 1, 0.29, 0.0375, 0.01, OptionType::Put);
    double BSPrice = putOpt.price(); // now price just puts

    std::cout << "BS-Price:  " << BSPrice << std::endl;

    double N = 10;
    BinomialTree binomialTree(&putOpt, N); // pass put option by reference

    double p = binomialTree.price();
    std::cout << p << std::endl;
    std::cout << "Diff: " << std::abs(p - BSPrice)<< std::endl;
    return 0;
}
