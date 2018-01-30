//This code is a copy of a sample from Andrew Sutton
// Source code located here: https://gitlab.com/andrew.n.sutton/spring-18-oop/blob/master/war/card.hpp

#pragma once

enum Rank {
  Ace,
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

// Represents the suits of a card.
enum Suit {
  Hearts,
  Diamonds,
  Clubs, 
  Spades,
};

struct Card {
  Card(Rank r, Suit s)
    : rank(r), suit(s)
  {
  }

private:
  Rank rank;
  Suit suit;
};
