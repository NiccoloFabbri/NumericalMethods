//
// Created by Niccolò Fabbri on 16/09/23.
//

#ifndef MTH9821_NUMERICALMETHODS_AMERICANOPTION_H
#define MTH9821_NUMERICALMETHODS_AMERICANOPTION_H

#include "Option.h"

class AmericanOption : public Option {
public:
    using Option::Option;
    double price() const override;
    double getPayoff(double spot) const override;
    bool isAmerican() const override;
};

#endif //MTH9821_NUMERICALMETHODS_AMERICANOPTION_H
