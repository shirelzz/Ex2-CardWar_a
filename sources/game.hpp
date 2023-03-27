#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
namespace ariel{}
using namespace std;
#include<iostream>

class Game{

    private:
        Player player1;
        Player player2;

    public:
        Game(Player p1, Player p2 );

        ~Game();

        void printWiner(); 

        void printLog();

        void printStats();

        void playTurn();

        void printLastTurn();

        void playAll();

};
#endif