//
// Created by Niccolò Fabbri on 15/09/23.
//

#ifndef MTH9821_NUMERICALMETHODS_EUROPEANOPTION_H
#define MTH9821_NUMERICALMETHODS_EUROPEANOPTION_H
#include "Option.h"
#include <numeric>

class EuropeanOption : public Option {
private:
    static double N(double x);
public:
    using Option::Option;
    double price() const override;
    double getPayoff(double spot) const override;
    bool isAmerican() const override;
};


#endif //MTH9821_NUMERICALMETHODS_EUROPEANOPTION_H
