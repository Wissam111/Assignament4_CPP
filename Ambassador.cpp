#include "Ambassador.hpp"

namespace coup
{

    void Ambassador::transfer(Player &player1, Player &player2)
    {
        if (coins() >= 10 || player1.coins() < 1)
        {
            throw "Invalid operation";
        }

<<<<<<< HEAD
        if (_playerTurn == game.getTurn() && !isCuped())
        {

            updateTurns();
=======
        if (_playerName == game.turn())
        {

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

>>>>>>> 0fd0e2e82c5791fc1620158877323faf2dd72de3
            player1.setCoins(player1.coins() - 1);
            player2.setCoins(player1.coins() + 1);
            upateOperation(FOREIGN_AID);
            return;
        }

        throw "Not His Turn";
<<<<<<< HEAD
    }

    void Ambassador::block(Player &otherPlayer)
    {

        if (otherPlayer.getLastOper() == STEAL)
        {

            int c = Player::_playersMap.at(getLastPlayer()).coins();
            this->setCoins(coins() - 2);
            Player::_playersMap.at(getLastPlayer()).setCoins(c + 2);
            return;
        }

        throw "His Last Operation Cant be blocked";
=======
>>>>>>> 0fd0e2e82c5791fc1620158877323faf2dd72de3
    }

}
