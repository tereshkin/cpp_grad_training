//
// This is main
//

#include "products.hpp"
#include "sellers.hpp"

#include "basket_1.hpp"
#include "basket_2.hpp"
#include "basket_3.hpp"
#include "basket_4.hpp"

#include <iostream>

namespace basket_4
{

template <>
struct product_traits<orange>
{
    using storage_t = std::vector<orange>;

    static double weight(const orange& prod) { return prod.weight_; }
};

template <>
struct product_traits<water>
{
    using storage_t = double;

    static double volume(const water& prod) { return prod.volume_; }
};

} // namespace basket_4

int main()
{
    {
        std::cout << "=== BASKET 1 ===" << std::endl;

        using namespace basket_1;

        basket<orange> oranges;
        oranges.add({0.100});
        oranges.add({0.220});
        oranges.add({0.125});

        basket<apple> apples;
        apples.add({0.100});
        apples.add({0.200});
        apples.add({0.100});

        std::cout << "Oranges weight: " << oranges.total_weight() << std::endl;
        std::cout << "Apples weight: " << apples.total_weight() << std::endl;
    }

    {
        std::cout << "=== BASKET 2 ===" << std::endl;

        using namespace basket_2;

        basket<orange> oranges;
        oranges.add({0.100});
        oranges.add({0.220});
        oranges.add({0.125});

        basket<kiwi> kiwis;
        kiwis.add({100});
        kiwis.add({200});
        kiwis.add({100});

        std::cout << "Oranges weight: " << oranges.total_weight() << std::endl;
        std::cout << "Kiwis weight: " << kiwis.total_weight() << std::endl;
    }

    {
        std::cout << "=== BASKET 3 ===" << std::endl;

        using namespace basket_3;

        basket<orange, honest_seller> oranges(honest_seller{});
        oranges.add({0.100});
        oranges.add({0.220});
        oranges.add({0.125});

        junior_seller seller{1.0};
        basket<water, decltype(seller)> water_tank(seller);

        water_tank.add({1.0});
        water_tank.add({0.4});
        water_tank.add({1.6});

        std::cout << "Oranges weight: " << oranges.total_weight() << std::endl;
        std::cout << "Water weight: " << water_tank.total_weight() << std::endl;
    }

    {
        std::cout << "=== BASKET 4 ===" << std::endl;

        using namespace basket_4;

        basket<orange> oranges;
        oranges.add({0.100});
        oranges.add({0.220});
        oranges.add({0.125});

        junior_seller seller{1.0};
        basket<water> water_tank;

        water_tank.add({1.0});
        water_tank.add({0.4});
        water_tank.add({1.6});

        std::cout << "Oranges weight: " << oranges.total_weight([](double weight) {
            return weight;
        }) << std::endl;
        std::cout << "Water weight: "
                  << water_tank.total_weight(
                         [&seller](double weight) { return seller.weight(weight); })
                  << std::endl;
    }

    return 0;
}
