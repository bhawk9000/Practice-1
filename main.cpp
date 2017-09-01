// Ben Hawk
// All Rights Reserved

#include <iostream>

#include "card.hpp"

int main()
{
    Rank r1 = Two;
    Rank r2 = Ace;
    std::cout << (r1 == r2) << std::endl;

    // Widening conversion
    int n = Jack;
    std::cout << n << std::endl;

    // Narrowing conversion. Bad.
    // Rank r3 = 4; // error: cannot convert.

    Card c1 {Ace, Spades};
    Card c2 {Four, Hearts};

    //c1.rank = Ten;
}
