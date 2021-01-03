//
//  main.cpp
//  DonkeyKong_ECS2
//
//  Created by Lucas Giglio on 29.12.20.
//

#include "Game.hpp"

Game game;


int main() {
    game.Init();
    while (game.Run()) {}
    return 0;
}
