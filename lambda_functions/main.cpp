//
// This is main
//

#include <cmath>
#include <iostream>

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
}
