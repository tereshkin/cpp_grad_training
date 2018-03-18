//
// Class which stores filters and can apply them to the vector
//
#pragma once

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

template <typename T>
class filter
{
public:
    template <typename Fn>
    void add_filter(Fn fn)
    {
        filters_.push_back(std::move(fn));
    }

    auto transform(const std::vector<T>& vec) const
    {
        std::vector<T> result;

        auto filters_result = [&](const T& elem) {
            return std::all_of(
                std::begin(filters_), std::end(filters_),
                [&elem](const std::function<bool(T)>& fn) { return fn(elem); });
        };

        for (const auto& elem : vec)
            if (filters_result(elem))
                result.push_back(elem);

        return result;
    }

    size_t num_filters() const { return filters_.size(); }
private:
    std::vector<std::function<bool(T)>> filters_;
};

template <typename T>
void add_default_length_filter(filter<T>& filt)
{
    int length = 10;

    // PROBLEM with default capturing by reference
    filt.add_filter([&](const std::string& str) { return str.length() < length; });
}
