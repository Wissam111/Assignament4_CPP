#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "Game.hpp"
using namespace std;
namespace coup
{

    class Player
    {
    protected:
        Game &game;
        string _playerName;
        int _coins = 0;
        bool _Blocked;
        OPERATION lastoper;

    public:
        Player(Game &game, string playerName) : game(game), _playerName(playerName)
        {
            game.players().push_back(playerName);
        };
        int coins();
        void setCoins(int coins);
        void income();
        void foreign_aid();
        void upateOperation(OPERATION oper);
        string getName();
        OPERATION getLastOper();

        virtual void coup(Player &otherPlayer);
        virtual string role() { return ""; };
    };

}