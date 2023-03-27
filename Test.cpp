#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;
#include <stdexcept>
#include <iostream>

TEST_CASE("Same name at initialization"){
    Player player("Avi");

    CHECK_THROWS(Game{player,player});
}

TEST_CASE("Same player is in more than one game"){
    Player player1("Avi");
    Player player2("Shirel");
    Player player3("Eli");

    Game game(player1, player2);

    CHECK_THROWS(Game{player1,player3});

}

TEST_CASE("correct initialization"){
    Player player1("Avi");
    Player player2("Eli");

    Game game(player1, player2);

    CHECK_EQ(player1.stacksize(), 26);
    CHECK_EQ(player2.stacksize(), 26);
    CHECK_EQ(player1.cardesTaken(), 0);
    CHECK_EQ(player2.cardesTaken(), 0);

}

TEST_CASE("number of cards at the end of the game"){
    Player player1("Avi");
    Player player2("Eli");

    Game game(player1, player2);
    game.playAll();

    CHECK(player1.stacksize() <= 52);
    CHECK(player1.stacksize() >= 0);
    CHECK(player2.stacksize() <= 52);
    CHECK(player2.stacksize() >= 0);
    CHECK(player1.cardesTaken() + player2.cardesTaken() == 26);

}

TEST_CASE("number of turns being played"){
    Player player1("Avi");
    Player player2("Eli");

    Game game(player1, player2);
    game.playAll();
    
    CHECK_THROWS(game.playTurn());
    CHECK_THROWS(game.playAll());

} 

TEST_CASE("number of cards in each turn"){
    Player player1("Avi");
    Player player2("Eli");

    Game game(player1, player2);

    int p1_cards = player1.cardesTaken();
    int p2_cards = player2.cardesTaken();
    
    for(int i = 0; i<25; i++){
        game.playTurn();
        
        if(player1.cardesTaken() == p1_cards && player2.cardesTaken() == p2_cards+1){
            p2_cards++;
        }
        else if(player1.cardesTaken() == p1_cards && player2.cardesTaken() == p2_cards+3){
            p2_cards = p2_cards + 3;
        }
        else if (player1.cardesTaken() == p1_cards+1 && player2.cardesTaken() == p2_cards){
            p1_cards++;
        }
        else if(player1.cardesTaken() == p1_cards+3 && player2.cardesTaken() == p2_cards){
            p1_cards = p1_cards + 3;
        }

        CHECK_EQ(player1.cardesTaken(), p1_cards);
        CHECK_EQ(player2.cardesTaken(), p2_cards);

    }
    

}


TEST_CASE("number of cards left in the stack in each turn"){
    Player player1("Avi");
    Player player2("Eli");

    Game game(player1, player2);

    for(int i = 0; i<25; i++){
        game.playTurn();
        CHECK_EQ(player1.stacksize(), player2.stacksize());
    }

} 






