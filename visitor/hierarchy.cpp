//
// All objects' hierarchy
//

#include "hierarchy.hpp"

void mallard_duck::accept(duck_visitor &v) const { v.visit(*this); }

void redhead_duck::accept(duck_visitor &v) const { v.visit(*this); }

rubber_duck::rubber_duck(double volume) : volume_(volume) {}

void rubber_duck::accept(duck_visitor &v) const { v.visit(*this); }

void decoy_duck::accept(duck_visitor &v) const { v.visit(*this); }
