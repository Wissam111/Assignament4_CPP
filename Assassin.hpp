/*
 * AUTHORS: Wissam kabha
 * gitHub: https://github.com/Wissam111
 * Date: 04/2022
 */

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Player.hpp"
#include "Game.hpp"
using namespace std;
namespace coup
{

    class Assassin : public Player
    {

    public:
        Assassin(Game &game, string playerName) : Player(game, playerName) {}
        string role() override;
        void coup(Player &otherPlayer) override;
    };

}