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
  newPlayer->choice = 0;
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

void Table::addThisMuch(Player* person, int money)
{

}

void Table::takeThisMuch(Player* person, int money)
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
  while(curr != NULL)
  {
    cout << curr->name << endl;
    curr = curr->next;
  }
  return;
}

void Table::reverseEntireNetwork()
{
  Player* prev = NULL;
  Player* current = head;
  Player* next = NULL;

  while (current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}

void Table::turn()
{
  bool bettingDone = false; //this checks to see if everyone has either folded or bet the max amount
  int maxBet = 0;
  Player* current = head;
  while(!bettingDone)
  {
    if(current->choice == 1)
    {
      cout << "Player " << current->name << " folded" << endl;
      current = current->next;
    }
    else
    {


      bool flag = true;
      while(flag)
      {
        cout << "---------------" << endl;
        cout << "It is now " << current->name << "'s turn" << endl;
        cout << "---------------" << endl;

        cout << "What would you like to do?" << endl;
        cout << "1. Fold" << endl;
        cout << "2. Call" << endl;
        cout << "3. Raise" << endl;
        cout << "4. Check" << endl;

        int input = -1;

        cin >> input;

        if(input == 1)
        {
          // currentPlayer->choice = 1;
          cout << "You chose to fold" << endl;
          //all the money they bet goes into the

          current = current->next;
        }
        else if(input == 2)
        {

        }
        else if(input == 3)
        {
          cout << "You chose to raise" << endl;
          cout << "How much would you like to raise?" << endl;

          //take the input, add it to the max bet. see if they have that much money. if so, replace the max bet with it
        }
        else if(input == 4)
        {
          //see if the players current bet is equal to or bigger than the max bet. if so let them check. set current = current->next. if not
        }
      }
    }
  }
}


//player* findPlayer()
//endGame()
