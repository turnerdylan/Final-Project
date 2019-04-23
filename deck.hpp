#ifndef DECK_HPP
#define DECK_HPP


#pragma once
#include <iostream>

const int tablesize = 52;

struct Card
{
  std::string suit; //(spades, hearts, diamonds, clubs)
  std::string value; //(Ace,2,3,4,5,6,7,8,9.10,jack,queen,king)
  Card* next;
};

class Deck{
  private:

    Card* HashTable[52];

  public:
    Deck();
    int Hash(std::string key);
    void AddCard(std::string suit, std::string value);
    int NumItemsIndex(int index);
    void PrintTable();
    bool createDeck();
    std::string deal(int input);
    void shuffle();
    void print();
    void printCardsIndex();
    //string getcards(int index);
    //15 cards



};

#endif
