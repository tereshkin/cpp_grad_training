//
// Visitor to produce duck's sound
//

#include "sound_visitor.hpp"

#include "hierarchy.hpp" // notice that I include hierarchy only here

#include <iostream>

void sound_visitor::visit(const mallard_duck& /*duck*/)
{
    std::cout << "Quack" << std::endl;
}

void sound_visitor::visit(const redhead_duck& /*duck*/)
{
    std::cout << "Quack" << std::endl;
}

void sound_visitor::visit(const rubber_duck& duck)
{
    std::cout << "Quack (volume =" << duck.volume_ << ")" << std::endl;
}

void sound_visitor::visit(const decoy_duck& /*duck*/) {}
