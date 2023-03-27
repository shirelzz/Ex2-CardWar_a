#include "player.hpp"
#include "game.hpp"
#include "card.hpp"
namespace ariel{}

Player::Player(std::string name): name(name) {}
Player::~Player(){}

void Player::changeMode(){} //change isPlaying field

bool Player::getMode(){return false;}

int Player::stacksize(){return 0;}

int Player::cardesTaken(){return 0;}