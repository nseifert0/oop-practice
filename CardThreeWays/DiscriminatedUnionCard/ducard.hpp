#ifndef BITCARD_HPP
#define BITCARD_HPP

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

class Bitcard {
public:

  Bitcard(Rank r, Suit s)
    : bits((unsigned)s << 4 | (unsigned)r)
  { }

  Rank getRank() const;

  Suit getSuit() const;

  bool operator==(Bitcard bc) const;

  bool operator!=(Bitcard bc) const;

private:
  unsigned char bits;
};


#endif