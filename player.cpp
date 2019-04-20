#include <iostream>
#include "player.hpp"

using namespace std;


Table::Table()
{
 head = NULL;
 // amountOnTable = 0;
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
  newPlayer->wager = 0;
  head = newPlayer;
  cout << "adding: " << name << endl;
}

void Table::repair()
{
  Player* curr = head;
  while(curr->next != NULL)
  {
    curr = curr->next;
  }
  Player* curr2 = head;
  head = curr;
  curr->next = curr2;
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
    if(curr == head)
    {
      return;
    }
  }
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

// bool checkTurnOver(int maxBet)
// {
//   Player* curr = head;
//   bool flag = true;
//   while(curr->next != head)
//   {
//     if(curr->choice == 0)
//     {
//       return false;
//     }
//     if(curr->wager < maxBet)
//     {
//       return false;
//     }
//   }
//   return true;
// }

void Table::turn()
{
  int amountOnTable;
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

        cout << "---------------" << endl;
        cout << "It is now " << current->name << "'s turn" << endl;
        cout << "---------------" << endl;
        Player* curr2 = current->next;
        while(curr2 != current)
        {
          cout << "Player " << curr2->name << ": ";
          if(curr2->choice == 1)
          {
            cout << "folded" << endl;
          }
          else
          {
            cout << "Has bet " << curr2->wager << endl;
          }
          curr2 = curr2->next;
        }
        cout << endl;
        cout << endl;
        cout << "These are the cards on the table" << endl;
        cout << "(insert cards here)" << endl;
        cout << endl;
        cout << endl;
        cout << "These are the cards in your hand" << endl;
        cout << "(insert cards here)" << endl;
        cout << endl;
        cout << endl;


        cout << "You have $" << current->money << endl;
        cout << "The highest bet is " << maxBet << endl;

        cout << "What would you like to do?" << endl;
        cout << "1. Fold" << endl;
        cout << "2. Call" << endl;
        cout << "3. Raise" << endl;
        cout << "4. Check" << endl;

        int input = -1;

        cin >> input;

        if(input == 1)
        {
          current->choice = 1;
          cout << "You chose to fold" << endl;
          cout << "------------" << endl;
          cout << "";
          cout << "You have $" << current->money << " after folding" << endl;
          //all the money they bet goes into the

          current = current->next;
        }
        else if(input == 2)
        {
          //add loop here
          cout << "You chose to call" << endl;
          if(maxBet > current->money)
          {
            cout << "You dont have enought money to call, you must fold";
            current->choice = 1;
          }
          else
          {
            cout << "You call with $" << maxBet << endl;
            current->wager = maxBet;
            cout << "Your current wager is $" << current->wager << endl;
            current->money = current->money - maxBet;
            cout << "You have $" << current->money << " after calling" << endl;
            current = current->next;
          }
        }
        else if(input == 3)
        {
          bool enoughRaise = false;
          cout << "You chose to raise" << endl;
          while(!enoughRaise)
          {
            cout << "How much would you like to raise by?" << endl;
            int raise;
            cin >> raise;
            if(raise + maxBet > current->money)
            {
              cout << "You don't have enough money to raise that much" << endl;
            }
            else
            {
              maxBet = maxBet + raise;
              current->wager = maxBet;
              current->money = current->money - maxBet;
              cout << "Your current wager is $" << current->wager << endl;
              enoughRaise = true;
              cout << "You have $" << current->money << " after raising" << endl;
              current = current->next;
            }
          }

          //take the input, add it to the max bet. see if they have that much money. if so, replace the max bet with it
        }
        else if(input == 4)
        {
          if(maxBet == 0)
          {

          }
        }
        cout << endl;
        cout << "Total money in the pot is $" << amountOnTable << endl;
        cout << endl;

        cout << endl;
        cout << endl;
        cout << "Enter any number to continue to the next turn" << endl;
        int trash;
        cin >>trash;

    }
  }
}


//player* findPlayer()
//endGame()
