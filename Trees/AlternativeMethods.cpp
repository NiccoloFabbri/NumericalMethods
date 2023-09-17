//
// Created by Niccolò Fabbri on 17/09/23.
//


#include "AlternativeMethods.h"

TreeResult AverageTreePricer(Option* opt, double N_){
    BinomialTree treeN(opt, N_); //opt is already a ptr
    BinomialTree treeN1(opt, N_ + 1);

    TreeResult resN = treeN.execute(PricingMethod::Standard);
    TreeResult resN1 = treeN1.execute(PricingMethod::Standard);

    return TreeResult({(resN.value + resN1.value) * 0.5 ,(resN.delta + resN1.delta) * 0.5,
                       (resN.gamma + resN1.gamma) * 0.5, (resN.theta + resN1.theta) * 0.5});
}
