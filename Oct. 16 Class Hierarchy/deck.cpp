// Ben Hawk
// All Rights Reserved

#include "deck.hpp"
#include <iostream>
#include <random>
#include <algorithm>

Deck make_standard_deck()
{
    Deck d
    {
        {0, Ace, Spades},
        {1, Two, Spades},
        {2, Three, Spades},
        {3, Four, Spades},
        {4, Five, Spades},
        {5, Six, Spades},
        {6, Seven, Spades},
        {7, Eight, Spades},
        {8, Nine, Spades},
        {9, Ten, Spades},
        {10, Jack, Spades},
        {11, Queen, Spades},
        {12, King, Spades},

        {13, Ace, Clubs},
        {14, Two, Clubs},
        {15, Three, Clubs},
        {16, Four, Clubs},
        {17, Five, Clubs},
        {18, Six, Clubs},
        {19, Seven, Clubs},
        {20, Eight, Clubs},
        {21, Nine, Clubs},
        {22, Ten, Clubs},
        {23, Jack, Clubs},
        {24, Queen, Clubs},
        {25, King, Clubs},

        {26, Ace, Hearts},
        {27, Two, Hearts},
        {28, Three, Hearts},
        {29, Four, Hearts},
        {30, Five, Hearts},
        {31, Six, Hearts},
        {32, Seven, Hearts},
        {33, Eight, Hearts},
        {34, Nine, Hearts},
        {35, Ten, Hearts},
        {36, Jack, Hearts},
        {37, Queen, Hearts},
        {38, King, Hearts},

        {39, Ace, Diamonds},
        {40, Two, Diamonds},
        {41, Three, Diamonds},
        {42, Four, Diamonds},
        {43, Five, Diamonds},
        {44, Six, Diamonds},
        {45, Seven, Diamonds},
        {46, Eight, Diamonds},
        {47, Nine, Diamonds},
        {48, Ten, Diamonds},
        {49, Jack, Diamonds},
        {50, Queen, Diamonds},
        {51, King, Diamonds},

        {52, Black},
        {53, Red},
    };
    return d;
}

void shuffle(Deck& d)
{
    // Function-local extern variable.
    extern std::minstd_rand prng;

    std::shuffle(d.begin(), d.end(), prng);
}

