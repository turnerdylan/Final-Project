#include <iostream>
#include "player.hpp"
#include "deck.hpp"

using namespace std;

// Table Table;
Deck Deck;

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

void Table::deletePlayer(Player* curr)
{
  Player* next2 = curr->next->next;
  delete curr->next;
  curr->next = next2;

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

// bool Table::checkTurnOver(Player* curr, int maxBet)
// {
//   cout << "check" << endl;
//   // hey dylN GUESS wHAT YOU ARE really  HEad ass
//   Player* flag = curr;
//   while(curr->next != flag)
//   {
//     if(curr->choice == 0 && curr->wager < maxBet)
//     {
//       return false;
//     }
//
//     curr = curr->next;
//   }
//   return true;
// }

void Table::dealCards(Player* curr, int numOfPlayers)
{
  for(int i=0; i<numOfPlayers; i++)
  {
    curr->card1 = Deck.deal();
    curr->card2 = Deck.deal();
    curr = curr->next;
  }
  for(int i=0; i<5; i++)
  {
    tableCards[i] = Deck.deal();
  }
}

int getNumOfPlayers(Player* head)
{
  int count = 0;
  Player* hold = head->next;
  while(hold != head)
  {
    count++;
    hold = hold->next;
  }
  return count;
}

void resetPlayers(Player* head)
{
  Player* hold = head->next;
  while(hold != head)
  {
    hold->wager = 0;
    hold->card1 = "";
    hold->card2 = "";
    hold->choice = 0;
    hold = hold->next;
  }
}

int Table::turn()
{
  int numOfPlayers = getNumOfPlayers(head);
  dealCards(head, numOfPlayers);
  int round = 1;
  int amountOnTable = 0;
  int maxBet = 1;
  Player* current = head;
  // bool check = checkTurnOver(current, maxBet);
  // check = false;

  while(round < 4)
  {
    while(current->wager < maxBet)
    {
      // if(checkTurnOver(current, maxBet))
      // {
      //   cout << "end of turn" << endl;
      //   break;
      // }
      if(current->choice == 1)
      {
        cout << "Player " << current->name << " folded" << endl;
        current = current->next;
      }
      else
      {

          cout << "---------------" << endl;
          cout << "IT IS NOW " << current->name << "'s TURN" << endl;
          cout << "---------------" << endl << endl;
          Player* curr2 = current->next;
          while(curr2 != current)
          {
            cout << "Player " << curr2->name << ": ";
            if(curr2->choice == 1)
            {
              cout << "FOLDED" << endl;
            }
            else
            {
              cout << "HAS BET: " << curr2->wager << endl;
            }
            curr2 = curr2->next;
          }

          cout << endl<< "You have $" << current->money << endl;
          cout << "The highest bet is $" << maxBet << endl;
          cout << "Your highest bet is $" << current->wager << endl;

          cout << endl;
          cout << endl;
          cout << "These are the cards on the table" << endl;
          for(int i=0; i<5; i++)
          {
            cout << tableCards[i] << "  ";
          }
          cout << endl;

          cout << endl;
          cout << endl;
          cout << "These are the cards in your hand" << endl;
          cout << current->card1 << " & " << current->card2 << endl;
          cout << endl;
          cout << endl;



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
              cout << "You have $" << current->money << " after folding" << endl;
              current->choice = 1;
            }
            else
            {
              cout << "You call with $" << maxBet << endl;
              current->money = current->money - (maxBet- current->wager);
              current->wager = maxBet;
              cout << "Your current wager is $" << current->wager << endl;
              amountOnTable = amountOnTable + current->wager;
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
                amountOnTable = amountOnTable + current->wager;
                enoughRaise = true;
                cout << "You have $" << current->money << " after raising" << endl;
                current = current->next;
              }
            }

            //take the input, add it to the max bet. see if they have that much money. if so, replace the max bet with it
          }
          else if(input == 4)
          {
            deletePlayer(current);
            // if(maxBet == 0 || current->wager >= maxBet)
            // {
            //   cout << "You chose to check" << endl;
            //   current = current->next;
            // }
            // else
            // {
            //   cout << "You cannot check, try your turn again" << endl;
            // }
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

    cout << "round " << round << " done. flip cards" << endl;
    resetPlayers(head);
    round++;

  }


  if(round == 3)
  {
    cout << "End of hand and restart" << endl;

    //calculate winner
    //pay winner


    //royal flush
    //stright flush
    //four of a kind
    //full house
    //flush
    //straight
    //3 of a kind
    //2 pair
    //pair
    //high card

    //compare hands of whoever is still alive
    //give money to whoever wins
    // winner->money = winner->money + amountOnTable;
    amountOnTable = 0;

    //check peoples money
    cout << "checking money" << endl;
    Player* flag = head;
    while(current->next != flag)
    {
      if(current->next->money <= 0)
      {
        cout << current->next->name << " is out" << endl;
        deletePlayer(current);
        if(head->next == head)
        {
          cout << head->name << " is the winner!" << endl;
          //end code
        }
      }
    }
  }
  else
  {
    round++;
  }
}


//player* findPlayer()
//endGame()
