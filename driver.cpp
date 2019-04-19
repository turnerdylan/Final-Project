#include <iostream>
#include "player.hpp"

using namespace std;


int main(int argc, char const *argv[]) {

  Table Table;

  cout << "-------------------------------" << endl;
  cout << "---- WELCOME TO C++ POKER! ----" << endl;
  cout << "-------------------------------" << endl;

  cout << "How many human players would you like to play with? (Maximum 5)" << endl;
  int numOfPlayers = -1;
  while(true)
  {
    cin >> numOfPlayers;
    if(numOfPlayers < 2 || numOfPlayers > 5)
    {
      cout << "Please pick between 2 and 5 players" << endl;
    }
    else
    {
      break;
    }
  }

  int numOfAI;
  cout << "How many AI players would you like? (this doesnt do anything yet)" << endl;
  cin >> numOfAI;


  for(int i=0; i<numOfPlayers; i++)
  {
    string name;
    cout << "Pick a name for player " << i+1 << endl;
    cin >> name;
    Table.insertPlayer(NULL, name);
  }
  Table.reverseEntireNetwork();
  Table.printPlayers();

  //start the game
  while(numOfPlayers > 1)
  {
    //get cards
    // Table.dealCards();
    Table.turn();
    //print hand and cards on table
    //cout << "It is now " << currentPlayer->name << "'s turn" << endl;




    //getCards

    //every round
      //pull cards 2X numOfPlayers + 5 and burn one
      //deal cards to everyone
      //starting at head, take bets, until people have either folded or bet as much as highest
      //deal flop
        //repeat bets
      //deal turn
        //repeat bets
      //deal river
        //repeat bets

      //compare hands of whoever is still alive
      //give money to whoever wins
      //check peoples money
        //delete those who are out
        //check if there is one person left

  }

  // function to make players in a linked list, createTable(numOfPlayers)
  // create circular linked list
  return 0;
}
