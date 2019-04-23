#ifndef PLAYER_HPP
#define PLAYER_HPP


#pragma once
#include <iostream>
#include "deck.hpp"

// Country: node struct that will be stored in the CountryNetwork
//   linked-list
struct Player
{
    std::string name;
    int money;
    Card card1;
    Card card2;
    //int playerNumber;
    Player *next;
    int wager;
    bool choice; //0 = NA, 1 = fold

};

// class for storing and manipulating linked-list of countries
class Table {

    public:
        // See writeup for method descriptions
        Table();
        ~Table();
        void insertPlayer(Player* prev, std::string name);
        void repair();
        void deletePlayer(Player* curr);
        void printPlayers();
        void reverseEntireNetwork();
        int turn();
        bool checkTurnOver(Player* curr, int maxBet);
        void dealCards(Player* curr, int numOfPlayers);

        Player* head;
        Card tableCards [5];



};

#endif
