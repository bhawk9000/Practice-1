// Ben Hawk
// All Rights Reserved

#include <iostream>
#include "card.hpp"
#include "deck.hpp"

int main()
{
    Deck deck = make_standard_deck();
    shuffle(deck);

    return 0;
}
