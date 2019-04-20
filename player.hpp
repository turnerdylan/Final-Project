#ifndef PLAYER_HPP
#define PLAYER_HPP


#pragma once
#include <iostream>

// Country: node struct that will be stored in the CountryNetwork
//   linked-list
struct Player
{
    std::string name;
    int money;
    std::string card1;
    std::string card2;
    //int playerNumber;
    Player *next;
    int wager;
    int choice; //0 = NA, 1 = fold, 2 = call, 3 = raise, 4 = check

};

// class for storing and manipulating linked-list of countries
class Table {
    private:
        // pointer to head of linked-list of countries
        Player* head;
        // int amountOnTable;

    public:
        // See writeup for method descriptions
        Table();
        ~Table();
        void insertPlayer(Player* prev, std::string name);
        void repair();
        void deletePlayer(std::string name);
        void addCardsToPlayer(std::string first, std::string second, Player* curr);
        void addThisMuch(Player* person, int money);
        void takeThisMuch(Player* person, int money);
        void addWager(int bet);
        int displayChoice(int choice);
        void printPlayers();
        void reverseEntireNetwork();
        void turn();


};

#endif
