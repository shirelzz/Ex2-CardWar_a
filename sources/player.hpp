#ifndef PLAYER_HPP
#define PLAYER_HPP

namespace ariel{}
// using namespace std;
#include <vector>
#include "card.hpp"
#include <iostream>

class Player{

    private:
        const std::string name;
        std::vector<Card> cards;
        std::vector<Card> cards_thrown;
        bool isPlaying = false;


    public:
        Player(std::string name);

        ~Player();

        void changeMode(); //change isPlaying field

        bool getMode();

        int stacksize();

        int cardesTaken();


};
#endif