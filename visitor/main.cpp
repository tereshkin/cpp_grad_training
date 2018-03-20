#include "hierarchy.hpp"
#include "sound_visitor.hpp"

int main()
{

    mallard_duck duck_1;
    redhead_duck duck_2;
    rubber_duck  duck_3(0.7);
    decoy_duck   duck_4;

    auto make_sound = [](const duck& d) {
        sound_visitor v;
        d.accept(v);
    };

    make_sound(duck_1);
    make_sound(duck_2);
    make_sound(duck_3);
    make_sound(duck_4);
}
