// Ben Hawk
// All Rights Reserved

#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED

#include <utility>

// Ranks of a c card are:
// ace, 2-10, jack, king, and queen

// suits of a card are:
// hearts, diamnds, clubs, spades

//using Card = int[2];
//using Card = std::pair<int, int>;

enum Rank // An enumeration type
{
    Ace, // An enumerator
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

enum Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades,
};

struct Card
{
    Rank rank;
    Suit suit;
};

#endif // CARD_HPP_INCLUDED



// touch CMakeLists.txt

// add_executable(war
        //main.cpp
        //card.cpp

// git add CMakeLists.txt
// git commit -a

// look for CMAKE_BUILD_TYPE
