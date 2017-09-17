// Ben Hawk
// All Rights Reserved

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>
#include "card.hpp"

std::random_device rng;//makes it impossible to guess the random number generator
std::minstd_rand prng;

void print_deck(const std::vector<Card>& deck);
bool card_greater(Card a, Card b);

int main()
{
    prng.seed(rng());

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

    print_deck(deck);

    std::shuffle(deck.begin(), deck.end(), prng);
    print_deck(deck);

    std::sort(deck.begin(), deck.end());
    print_deck(deck);

    std::shuffle(deck.begin(), deck.end(), prng);
    std::sort(deck.begin(), deck.end(), [](Card a, Card b)   // lambda expression
    {
        return a > b;
    });
    print_deck(deck);

    std::shuffle(deck.begin(), deck.end(), prng);
    std::sort(deck.begin(), deck.end(), card_greater);
    print_deck(deck);

    std::shuffle(deck.begin(), deck.end(), prng);
    std::sort(deck.begin(), deck.end(), [](Card a, Card b)   // lambda expression
    {
        return a.get_suit() < b.get_suit();
    });
    print_deck(deck);

}

void print_deck(const std::vector<Card>& deck)
{
    // Range-base for loop.
    int i = 1;
    for (Card c : deck)
    {
        std::cout << c << ' ';
        if (i % 13 == 0)
        {
            std::cout << '\n';
            i = 0;
        }
        ++i;
    }
    std::cout << '\n';
}

bool card_greater(Card a, Card b)
{
    return a > b;
}
