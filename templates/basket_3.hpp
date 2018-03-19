#pragma once

#include "products.hpp"

namespace basket_3
{
double product_weight(const apple& prod) { return prod.weight_; }

double product_weight(const orange& prod) { return prod.weight_; }

double product_weight(const kiwi& prod) { return prod.weight_in_gramms_ * 0.001; }

template <typename T, typename seller_t>
class basket
{
public:
    basket(seller_t seller) : products_(), seller_(std::move(seller)) {}
    void add(T product) { products_.push_back(std::move(product)); }
    double     total_weight() const
    {
        double res = 0.;

        for (const auto& prod : products_)
            res += seller_.weight(product_weight(prod));

        return res;
    }

private:
    std::vector<T> products_;
    seller_t       seller_;
};

template <typename seller_t>
class basket<water, seller_t>
{
public:
    basket(seller_t seller) : volume_(), seller_(std::move(seller)) {}

    void add(water prod) { volume_ += prod.volume_; }
    double         total_weight() const { return seller_.weight(volume_); }

private:
    double   volume_;
    seller_t seller_;
};

} // namespace basket_3
