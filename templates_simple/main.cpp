//
// Simple templates exersise
//

#include <iostream>
#include <string>
#include <vector>

template <typename T>
struct A
{
    void print_a() const { std::cout << "A<T>" << std::endl; }
};

template <>
struct A<double>
{
    void print_a_double() const { std::cout << "A<double>" << std::endl; }
};

template <typename T>
struct A<std::vector<T>>
{
    void print_a_vec() const { std::cout << "A<vector<T>>" << std::endl; }
};

template <>
struct A<std::vector<int>>
{
    void print_a_vec_int() const { std::cout << "A<vector<int>>" << std::endl; }
};

////////////////////////////////////////////////////////////////////////////////

template <bool happy>
struct B;

template <>
struct B<true>
{
    void print() const { std::cout << "Happy" << std::endl; }
};

template <>
struct B<false>
{
    void print() const { std::cout << "Sad" << std::endl; }
};

////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct obj_happy_traits;

template <typename T>
struct C
{
    void print() const
    {

        if (obj_happy_traits<T>::value)
            std::cout << "Happy" << std::endl;
        else
            std::cout << "Sad" << std::endl;
    }
};

template <typename T, bool happy = obj_happy_traits<T>::value>
struct D;

template <typename T>
struct D<T, true>
{
    void print() const { std::cout << "Happy" << std::endl; }
};

template <typename T>
struct D<T, false>
{
    void print() const { std::cout << "Sad" << std::endl; }
};

////////////////////////////////////////////////////////////////////////////////

template <>
struct obj_happy_traits<int>
{
    static constexpr bool value = true;
};

template <>
struct obj_happy_traits<double>
{
    static constexpr bool value = false;
};

int main()
{
    A<int> a1;
    a1.print_a();

    A<std::string> a2;
    a2.print_a();

    A<double> a3;
    a3.print_a_double();

    A<std::vector<double>> a4;
    a4.print_a_vec();

    A<std::vector<int>> a5;
    a5.print_a_vec_int();

    std::cout << "==========" << std::endl;

    B<true> b1;
    b1.print();

    B<false> b2;
    b2.print();

    C<int> c1;
    c1.print();

    C<double> c2;
    c2.print();

    D<int> d1;
    d1.print();

    D<double> d2;
    d2.print();
}
