#include <iostream>
#include "player.hpp"

using namespace std;


Table::Table()
{
 head = NULL;
 amountOnTable = 0;
}

Table::~Table()
{

}

void Table::insertPlayer(Player* prev, string name)
{
  Player* newPlayer = new Player;
  newPlayer->name = name;
  newPlayer->money = 1000;
  newPlayer->next = head;
  head = newPlayer;
  cout << "adding: " << name << endl;
}

void Table::deletePlayer(string name)
{

}

void Table::addCardsToPlayer(string first, string second, Player* curr)
{
  curr->card1 = first;
  curr->card2 = second;
}

void Table::addThisMuch(int money)
{

}

void Table::takeThisMuch(int money)
{

}

void Table::addWager(int bet)
{

}

int Table::displayChoice(int choice)
{



  return choice;
}

void Table::printPlayers()
{
  Player* curr = head;
  cout << "order of players is:" << endl;
  while(head != NULL)
  {
    cout << curr->name << endl;
    curr = curr->next;
  }
}


//player* findPlayer()
//endGame()
