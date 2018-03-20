//
// Visitor for ducks
//

#pragma once

class mallard_duck;
class redhead_duck;
class rubber_duck;
class decoy_duck;

class duck_visitor
{
public:
    virtual void visit(const mallard_duck& duck) = 0;
    virtual void visit(const redhead_duck& duck) = 0;
    virtual void visit(const rubber_duck& duck)  = 0;
    virtual void visit(const decoy_duck& duck)   = 0;
};
