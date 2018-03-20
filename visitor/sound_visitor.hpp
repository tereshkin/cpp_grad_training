//
// Visitor to produce duck's sound
//

#pragma once

#include "visitor.hpp"

class sound_visitor : public duck_visitor
{
public:
    void visit(const mallard_duck& duck) override;
    void visit(const redhead_duck& duck) override;
    void visit(const rubber_duck& duck) override;
    void visit(const decoy_duck& duck) override;
};
