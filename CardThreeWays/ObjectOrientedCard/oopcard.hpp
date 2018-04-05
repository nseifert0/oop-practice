#ifndef OOPCARD_HPP
#define OOPCARD_HPP

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

enum Color {
  Black, Red
};


class Card
{
public:
  Card(int n)
    : id(n)
  { }

  virtual ~Card() = default;

  virtual Card* clone() = 0;
  int get_id() const { return id; }
  int id;
};


class StandardCard : public Card
{
public:

  StandardCard(int n, Rank r, Suit s)
    : Card(n), rank(r), suit(s)
  { }


  Card* clone() override {
    return new StandardCard(*this);
  }

  Rank get_rank() const { return rank; }
  Suit get_suit() const { return suit; }

  Rank rank;
  Suit suit;
};

class JokerCard : public Card
{
public:
  JokerCard(int n, Color c)
    : Card(n), color(c)
  { }

  Card* clone() override {
    return new JokerCard(*this);
  }

  Color color;
};

#endif