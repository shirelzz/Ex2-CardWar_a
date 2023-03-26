#include <vector>
#include "card.hpp"
#include <iostream>
class Player{

    private:
        const std::string name;
        std::vector<Card> cards;
        bool isPlaying = false;


    public:
        Player(std::string name): name(name) {}
        //Player:: Player(std::string name): name(name){}

        ~Player(){}

        void changeMode(); //change isPlaying field

        bool getMode();

        int stacksize();

        int cardesTaken();




};