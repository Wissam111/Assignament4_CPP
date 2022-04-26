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
        bool _COUPED = false;
        OPERATION lastoper;
        int lastOperPlayer;
        int player_index;
        static int player_counter;
        int _playerTurn = 0;

    public:
        static map<int, Player &> _playersMap;

        Player(Game &game, string playerName) : game(game), _playerName(playerName)
        {
            game.players().push_back(playerName);
            player_index = Player::player_counter;
            Player::_playersMap.insert(pair<int, Player &>(player_index, *this));

            Player::player_counter++;
            _playerTurn = game.numOfPlayers();
            game.setNumOfPlayers(game.numOfPlayers() + 1);
        };

        int coins();

        void setCoins(int coins);
        void income();
        void foreign_aid();
        void upateOperation(OPERATION oper);
        string getName();
        OPERATION getLastOper();
        int getPlayerIndex();
        void updateTurns();
        void updateGameList();
        bool isCuped();
        void setCuped(bool b);
        void setTurnNumber(int num);
        int getTurnNumber();
        void setLastOperPlayer(int otherPlayer)
        {
            lastOperPlayer = otherPlayer;
        }
        int getLastPlayer()
        {
            return lastOperPlayer;
        }

        virtual void coup(Player &otherPlayer);
        virtual string role() { return ""; }
    };
}