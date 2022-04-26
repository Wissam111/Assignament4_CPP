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
<<<<<<< HEAD
        int lastOperPlayer;
        int player_index;
        static int player_counter;
        int _playerTurn = 0;
=======
        Player *lastOperPlayer;
>>>>>>> 0fd0e2e82c5791fc1620158877323faf2dd72de3

    public:
        static map<int, Player &> _playersMap;

        Player(Game &game, string playerName) : game(game), _playerName(playerName)
        {
            game.players().push_back(playerName);
            player_index = Player::player_counter;
            Player::_playersMap.insert(pair<int, Player &>(player_index, *this));
            _playerTurn = player_counter;
            Player::player_counter++;

            game.setNumOfPlayers(game.numOfPlayers() + 1);
        };

        int coins();

        void setCoins(int coins);
        void income();
        void foreign_aid();
        void upateOperation(OPERATION oper);
        string getName();
        OPERATION getLastOper();
<<<<<<< HEAD
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
=======
        void setLastOperPlayer(Player &otherPlayer)
        {
            lastOperPlayer = &otherPlayer;
        }
        Player &getLastPlayer()
        {
            return *lastOperPlayer;
>>>>>>> 0fd0e2e82c5791fc1620158877323faf2dd72de3
        }

        virtual void coup(Player &otherPlayer);
        virtual string role() { return ""; }
    };

}