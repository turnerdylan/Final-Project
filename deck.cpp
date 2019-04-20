#include <iostream>
#include <fstream>
#include <string>
#include "deck.hpp"

using namespace std;

Deck Deck;

Deck::Deck()
{
  for(int i = 0; i < tablesize; i++)
  {
    HashTable[i] = new Card;
    HashTable[i]->suit = "empty";
    HashTable[i]->value = "empty";
    HashTable[i]->next = NULL;
  }
}

void Deck :: AddCard(string suit, string value)
{
  int index = Hash(suit);

  if(HashTable[index]->suit == "empty")
  {
    HashTable[index]->suit = suit;
    HashTable[index]->value = value;
  }
  else
  {
    Card* Ptr = HashTable[index];
    Card* n = new Card;
    n->suit = suit;
    n->value = value;
    n->next = NULL;

    while(Ptr->next != NULL)
    {
      Ptr = Ptr->next;
    }

    Ptr->next = n;
  }
}

int Deck :: NumItemsIndex(int index)
{
  int count = 0;

  if(HashTable[index]->suit == "empty")
  {
    return count;
  }
  else
  {
    count++;
    Card* Ptr = HashTable[index];
    while(Ptr->next != NULL)
    {
      count++;
      Ptr = Ptr->next;
    }
  }
  return count;
}

void Deck :: PrintTable()
{
  int number;

  for(int i = 0; i < tablesize; i++)
  {
    number = NumItemsIndex(i);
    cout << "----------------\n";
    cout << "index = " << i << endl;
    cout << HashTable[i]->suit << endl;
    cout << HashTable[i]->value << endl;
    cout << "# of items = " << number << endl;
    cout << "----------------\n";
  }
}

int Deck :: Hash(string key)
{
  int hash = 0;
  int index;

  for(int i = 0; i < key.length(); i++)
  {
      hash = hash + (int)key[i];
  }

  index = hash % tablesize;

  return index;
}

bool Deck :: createDeck()
{

  ifstream file("deck.txt");
  string value;
  string suit;

  if(file.is_open())
  {
    while(file >> value >> suit)
    {
        cout << value << "  " << suit << endl;
        AddCard(suit, value);
    }
    file.close();
  }
  else
  {
    cout << "File is not open!" << endl;
    return false;
  }
   return true;
}
