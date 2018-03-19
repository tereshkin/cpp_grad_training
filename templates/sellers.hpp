//
// Sellers
//

#pragma once

#include <random>

struct honest_seller
{
    double weight(double original_weight) const { return original_weight; }
};

struct sneaky_seller
{
    double weight(double original_weight) const
    {
        return sneaky_coefficient_ * original_weight;
    }

    double sneaky_coefficient_;
};

struct junior_seller
{
    double weight(double origina_weight) const
    {
        std::mt19937                           gen(42);
        std::uniform_real_distribution<double> distr(origina_weight * maturity_,
                                                     origina_weight * (2.0 - maturity_));
        return distr(gen);
    }

    double maturity_;
};
