#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
#include <stdexcept>

TEST_CASE("Same name at initialization"){
    Player player("Avi");

    CHECK_THROWS(Game{player,player});
}
