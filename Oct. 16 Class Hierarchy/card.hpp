// Ben Hawk
// All Rights Reserved

#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED

#pragma once

#include <utility>
#include <iosfwd>

// Ranks of a c card are:
// ace, 2-10, jack, king, and queen

// suits of a card are:
// hearts, diamonds, clubs, spades

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

enum Color
{
    Black,
    Red,
};

struct Card
{
    Card(int num)
    : id(num)
    {}

    int id;
};

struct Suited:Card
{
    Suited(int num, Rank r, Suit s)
    :   Card(num), rank(r), suit(s)
        {}

    Rank rank;
    Suit suit;
};

struct Joker:Card
{
    Joker(int num, Color c)
    : Card(num), color(c)
    {}

    Color color;
};

#endif // CARD_HPP_INCLUDED
