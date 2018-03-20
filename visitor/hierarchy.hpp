//
// All objects' hierarchy
//

#pragma once

#include "visitor.hpp"

class duck
{
public:
    virtual void accept(duck_visitor& v) const = 0;
};

class mallard_duck : public duck
{
public:
    void accept(duck_visitor& v) const override;
};

class redhead_duck : public duck
{
public:
    void accept(duck_visitor& v) const override;
};

class rubber_duck : public duck
{
public:
    rubber_duck(double volume);
    void accept(duck_visitor& v) const override;

private:
    friend class sound_visitor;
    double volume_;
};

class decoy_duck : public duck
{
public:
    void accept(duck_visitor& v) const override;
};
