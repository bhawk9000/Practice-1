// Ben Hawk
// All Rights Reserved

#include <iostream>
#include <vector>
#include "card.hpp"

int main()
{
    // Create a deck of cards.
    std::vector<Card> deck;
    deck.reserve(52); //Allocates memory for the cards

    //Trying to initialize in one line
   // boost::push_back(deck, boost::irange(1, 13));

    //Widens the ranks and suits.
    for (int r = Ace; r <= King; ++r)
    {
        for (int s = Hearts; s <= Spades; ++s)
        {
            Card c{static_cast<Rank>(r), static_cast<Suit>(s)};
            deck.push_back(c);
        }
    }

    // Range_base for loop
    for (Card c : deck)
    {
        std::cout << c.get_rank() << ' ' << c.get_suit() << std::endl;
    }
}
