#pragma once

#include "products.hpp"

namespace basket_2
{
double product_weight(const apple& prod) { return prod.weight_; }

double product_weight(const orange& prod) { return prod.weight_; }

double product_weight(const kiwi& prod) { return prod.weight_in_gramms_ * 0.001; }

template <typename T>
class basket
{
public:
    void add(T product) { products_.push_back(std::move(product)); }
    double     total_weight() const
    {
        double res = 0.;

        for (const auto& prod : products_)
            res += product_weight(prod);

        return res;
    }

private:
    std::vector<T> products_;
};
} // namespace basket_2
