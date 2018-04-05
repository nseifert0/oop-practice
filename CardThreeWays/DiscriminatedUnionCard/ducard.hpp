#ifndef DUCARD_HPP
#define DUCARD_HPP

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

enum Suit {
  Hearts,
  Diamonds,
  Clubs, 
  Spades,
};

class Card {
public:

  Card(Rank r, Suit s)
  { }

private:

};


#endif