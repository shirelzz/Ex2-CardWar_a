#include "player.hpp"

using namespace std;
#include<iostream>

class Game{

    private:
        Player player1;
        Player player2;

    public:
        Game(Player p1, Player p2 ) : player1(p1), player2(p2){}

        void printWiner(); 

        void printLog();

        void printStats();

        void playTurn();

        void printLastTurn();

        void playAll();

};