
#include "Duke.hpp"

namespace coup
{

    string Duke::role()
    {
        return "Duke";
    }

    void Duke::block(Player &otherPlayer)
    {

        if (otherPlayer.getLastOper() == FOREIGN_AID)
        {

            int c = otherPlayer.coins();
            otherPlayer.setCoins(c - 2);
            return;
        }

        throw "His Last Operation Cant be blocked";
    }

    void Duke::tax()
    {
<<<<<<< HEAD
        if (coins() >= 10)
        {
            throw "Operation Should be Coup!";
        }
        if (player_index == game.getTurn() || !isCuped())
        {
            _coins += 3;
            updateTurns();
            upateOperation(TAX);
            return;
        }
        else if (isCuped())
        {
            updateTurns();
            return;
        }
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

            upateOperation(TAX);
            return;
        }
>>>>>>> 0fd0e2e82c5791fc1620158877323faf2dd72de3

        throw "Not His Turn";
    }

}