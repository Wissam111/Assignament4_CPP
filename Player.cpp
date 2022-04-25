
#include "Player.hpp"
#include "Game.hpp"

namespace coup
{

    // Player::Player(Game &game, string playerName)
    // {
    //     this->game = game;
    //     this->_playerName = playerName;
    //     game.players().push_back(playerName);
    //     // this->game._players.push_back(playerName);
    // }

    int Player::coins()
    {
        return _coins;
    }

    void Player::setCoins(int coins)
    {
        _coins = coins;
    }

    void Player::income()
    {
        if (_playerName == game.turn())
        {
            _coins++;
            if (game.getCurr() == game.numOfPlayers() - 1)
            {
                game.setTurn(0);
            }
            else
            {
                int turn = game.getCurr();
                turn++;
                game.setTurn(turn);
            }

            upateOperation(INCOME);
            return;
        }

        throw "Not His Turn";
    }

    void Player::foreign_aid()
    {
        if (_playerName == game.turn())
        {
            _coins += 2;
            if (game.getCurr() == game.numOfPlayers() - 1)
            {
                game.setTurn(0);
            }
            else
            {
                int turn = game.getCurr();
                turn++;
                game.setTurn(turn);
            }

            upateOperation(FOREIGN_AID);
            return;
        }

        throw "Not His Turn";
    }

    void Player::coup(Player &otherPlayer)
    {
        int p = game.getPlayerIndex(otherPlayer._playerName);
        if (p == -1 || coins() < 7)
        {
            throw "Invalid operations";
        }

        if (_playerName == game.turn())
        {
            game.eraseAt(p);
            setCoins(coins() - 7);

            if (game.getCurr() == game.numOfPlayers() - 1)
            {
                game.setTurn(0);
            }
            else
            {
                int turn = game.getCurr();
                turn++;
                game.setTurn(turn);
            }
            this->setLastOperPlayer(otherPlayer);
            upateOperation(COUP);
            return;
        }

        throw "Not His Turn";
    }

    void Player::upateOperation(OPERATION oper)
    {
        lastoper = oper;
    }
    string Player::getName()
    {
        return _playerName;
    }

    OPERATION Player::getLastOper()
    {
        return lastoper;
    }
}