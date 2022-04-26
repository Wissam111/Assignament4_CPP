
#include "Player.hpp"
#include "Game.hpp"

namespace coup
{
    int Player::player_counter = 0;
    map<int, Player &> Player::_playersMap;

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

        if (coins() >= 10)
        {
            throw "Operation Should be Coup!";
        }

        if (player_index == game.getTurn() && !isCuped())
        {
            _coins++;
            updateTurns();
            upateOperation(INCOME);
            return;
        }
        else if (isCuped())
        {
            updateTurns();
            return;
        }

        throw "Not His Turn";
    }

    void Player::foreign_aid()
    {

        if (coins() >= 10)
        {
            throw "Operation Should be Coup!";
        }

        if (player_index == game.getTurn() || !isCuped())
        {
            _coins += 2;
            updateTurns();
            upateOperation(FOREIGN_AID);
            return;
        }
        else if (isCuped())
        {
            updateTurns();
            return;
        }

        throw "Not His Turn";
    }

    void Player::coup(Player &otherPlayer)
    {

        if (coins() < 7)
        {
            throw "Invalid operations";
        }

        if (player_index == game.getTurn() && !isCuped())
        {
            game.setNumOfPlayers(game.numOfPlayers() - 1);
            setCoins(coins() - 7);
            updateTurns();
            updateGameList();
            this->setLastOperPlayer(otherPlayer.getPlayerIndex());
            upateOperation(COUP);
            return;
        }
        else if (isCuped())
        {
            updateTurns();
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

    int Player::getPlayerIndex()
    {
        return player_index;
    }

    void Player::updateTurns()
    {

        if (game.getTurn() == game.numOfPlayers() - 1)
        {
            game.setTurn(0);
        }
        else
        {
            int turn = game.getTurn();
            turn++;
            game.setTurn(turn);
        }
    }

    bool Player::isCuped()
    {
        return _COUPED;
    }
    void Player::setCuped(bool b)
    {
        _COUPED = b;
    }

    void Player::updateGameList()
    {

        int index = -1;
        int count = 0;
        game.players().clear();
        for (int i = 0; i < Player::_playersMap.size(); i++)
        {
            if (!Player::_playersMap.at(i).isCuped())
            {
                count++;
                index = i;
                game.players().push_back(Player::_playersMap.at(i).getName());
            }
        }

        if (count == 1)
        {
            game.setWinner(Player::_playersMap.at(index).getName());
        }
    }

}