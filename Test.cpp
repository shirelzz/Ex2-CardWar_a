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

    Game game1(player1, player2);
    Game game2(player1, player3);

    CHECK_THROWS(game1,game2);
}

