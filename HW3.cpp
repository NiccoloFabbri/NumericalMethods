

#include <iostream>
#include "Options/EuropeanOption.h"
#include "Options/AmericanOption.h"
#include "Trees/BinomialTree.h"
#include <iomanip>




void print2DVector(const std::vector<std::vector<double>>& vec) {
    for (const auto& innerVec : vec) {
        for (double val : innerVec) {
            std::cout << std::setw(10) << std::fixed << std::setprecision(2) << val << " ";
        }
        std::cout << std::endl;
    }
}


int  main() {

    std::cout << "Question 1" << std::endl;

    EuropeanOption putOptEurop(54.0, 50.0, 1, 0.29, 0.0375, 0.01, OptionType::Put);
    double BSPrice = putOptEurop.price(); // now price just puts
    std::cout << "BS-Price:  " << BSPrice << std::endl;

    AmericanOption putOptAmer(54.0, 50.0, 1, 0.29, 0.0375, 0.01, OptionType::Put);

    BinomialTree binomialTree(&putOptAmer, 10);
    std::vector<std::vector<double>> p = binomialTree.price(PricingMethod::Standard);
    print2DVector(p);
    std::cout << binomialTree.execute(PricingMethod::Standard) << std::endl;


    //BinomialTree binomialTree1(&putOptEurop, 10);
    //std::vector<std::vector<double>> p1 = binomialTree1.price();
    //print2DVector(p1);
    // run simulation till 100
    //for(int i = 10; i <= 100; ++i){
        // pass put option by reference

        //BinomialTree binomialTree(&putOptEurop, i);
        //BinomialTree binomialTree1(&putOptAmer, i);

        //double p = binomialTree.price();
        //double p1 = binomialTree1.price();
        //std::cout << p << std::endl;
        //std::cout << p << " -- " << p1 <<std::endl;
    //}


    //std::cout << p << std::endl;
    //std::cout << "Diff: " << std::abs(p - BSPrice)<< std::endl;
    return 0;
}
