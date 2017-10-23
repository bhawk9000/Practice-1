// Ben Hawk
// All Rights Reserved

#ifndef DECK_HPP_INCLUDED
#define DECK_HPP_INCLUDED

#include <vector>
#include "card.hpp"

// Don't write a class if you don't have to
struct Deck
{
    std::vector<Card*> cards;

    Deck make_standard_deck();

    void shuffle(std::vector<Card*> d);
};

#endif // DECK_HPP_INCLUDED
