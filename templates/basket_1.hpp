#pragma once

namespace basket_1
{
template <typename T>
class basket
{
public:
    // This function can be even "smarter"
    void add(T product) { products_.push_back(std::move(product)); }
    double     total_weight() const
    {
        double res = 0.;

        for (const auto& prod : products_)
            res += prod.weight_;

        return res;
    }

private:
    std::vector<T> products_;
};
} // namespace basket_1
