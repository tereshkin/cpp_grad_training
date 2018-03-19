#pragma once

#include "products.hpp"

namespace basket_4
{

template <typename product_t>
struct product_traits;

template <typename product_t,
          typename storage_t = typename product_traits<product_t>::storage_t>
class basket;

template <typename product_t>
class basket<product_t, std::vector<product_t>>
{
public:
    void add(product_t product) { products_.push_back(std::move(product)); }

    template <typename seller_weight_fn>
    double total_weight(const seller_weight_fn& weight_fn) const
    {
        double res = 0.;

        for (const auto& prod : products_)
            res += weight_fn(product_traits<product_t>::weight(prod));

        return res;
    }

private:
    std::vector<product_t> products_;
};

template <typename product_t>
class basket<product_t, double>
{
public:
    basket() : volume_(0.) {}

    void add(const water& prod) { volume_ += product_traits<product_t>::volume(prod); }

    template <typename seller_weight_fn>
    double total_weight(const seller_weight_fn& weight_fn) const
    {
        return weight_fn(volume_);
    }

private:
    double volume_;
};

} // namespace basket_4
