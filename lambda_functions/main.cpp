//
// This is main
//

#include "filter.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

template <typename Fn>
auto transform_vector(const std::vector<int>& vec, const Fn& fn)
{
    std::vector<int> new_vec;
    new_vec.reserve(vec.size());

    for (const auto& num : vec)
        new_vec.push_back(fn(num));

    return new_vec;
}

int main()
{
    // Nothing to capture
    // No parameters
    // No return value
    auto lmbd_01 = []() { std::cout << "Lambda #1" << std::endl; };

    lmbd_01(); // call lambda

    // (Almost) equivalent lambdas
    auto lmbd_02 = []() { return "Lambda #2"; };
    auto lmbd_03 = []() -> std::string { return "Lambda #3"; };

    std::cout << lmbd_02() << " and " << lmbd_03() << std::endl;

    // Lambda with function arguments
    auto lmbd_04 = [](int num) -> int { return ++num; }; // What will happen with 'num'?
    auto lmbd_05 = [](double num, int power) { return std::pow(num, power); };

    std::cout << "Number increase: " << lmbd_04(3) << std::endl;
    std::cout << "Number power: " << lmbd_05(0.2, 3) << std::endl;

    // Function argument can be 'auto' as well
    auto lmbd_06 = [](const auto& arg) { std::cout << arg << std::endl; };
    lmbd_06(42);
    lmbd_06("Galaxy");

    // Lamdas do not have access to outside variables by default

    int  num_1 = 0, num_2 = 0;
    auto lmbd_07 = [num_1, &num_2]() { return num_1 + ++num_2; };
    auto lmbd_08 = [&] { return ++num_1 + ++num_2; };
    auto lmbd_09 = [=] { return num_1 + num_2; };

    std::cout << lmbd_07() << " " << num_1 << " " << num_2 << std::endl;
    std::cout << lmbd_08() << " " << num_1 << " " << num_2 << std::endl;
    std::cout << lmbd_09() << " " << num_1 << " " << num_2 << std::endl;

    // You can name arguments inside lambdas. You can even use the same name
    auto lmbd_10 = [ my_num_1 = num_1, my_num_2 = std::move(num_2) ]
    {
        return my_num_1 + my_num_2;
    };
    auto lmbd_11 = [ num_1 = num_1, &num_2 = num_2 ]()
    {
        num_2 = -num_1;
        return num_1 + num_2;
    };

    std::cout << lmbd_10() << std::endl;
    std::cout << lmbd_11() << std::endl;

    ////////////////////////////////////////////////////////////////////////////////
    // Some templates

    std::vector<int> vec = {1, -2, 3};

    const auto& new_vec =
        transform_vector(vec, [](int num) { return num > 0 ? num : 0; });

    std::cout << std::endl << "Vector transformation: " << std::endl;
    for (const auto& num : new_vec)
        std::cout << num << " ";
    std::cout << std::endl;

    ////////////////////////////////////////////////////////////////////////////////
    // Standard library functions http://en.cppreference.com/w/cpp/algorithm

    auto negative_number_iterator =
        std::find_if(vec.begin(), vec.end(), [](int n) { return n < 0; });

    int  target_number = 3;
    auto target_number_iter =
        std::find_if(std::begin(vec), std::end(vec),
                     [&target_number](const auto& num) { return num == target_number; });

    std::cout << "Find negative number: " << *negative_number_iterator << std::endl;
    std::cout << "Find target number: ";
    if (target_number_iter != std::end(vec))
        std::cout << *target_number_iter;
    else
        std::cout << "NOT FOUND";
    std::cout << std::endl;

    ////////////////////////////////////////////////////////////////////////////////
    // Filter example

    filter<std::string> strings_filter;
    strings_filter.add_filter([](const std::string& str) { return str.length() > 3; });
    strings_filter.add_filter(
        [](const std::string& str) { return str[0] >= 'A' && str[0] <= 'Z'; });

    std::vector<std::string> strings = {"Moscow", "Axe", "graduates"};

    auto new_strings = strings_filter.transform(strings);

    std::cout << std::endl << "Strings:" << std::endl;
    for (const auto& str : new_strings)
        std::cout << str << " ";
    std::cout << std::endl;
}
