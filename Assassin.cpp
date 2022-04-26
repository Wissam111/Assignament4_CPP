#include "Assassin.hpp"
#include "Player.hpp"
namespace coup
{

    void Assassin::coup(Player &otherPlayer)
    {

        if (coins() < 3)
        {
            throw "Invalid operations";
        }
<<<<<<< HEAD
        if (_playerTurn == game.getTurn() && !isCuped())
        {
            otherPlayer.setCuped(true); // killed/Cuped

            updateGameList();
            if (game.getTurn() < otherPlayer.getTurnNumber())
            {
                updateTurns();
            }
            setCoins(coins() - 3);
            this->setLastOperPlayer(otherPlayer.getPlayerIndex());
            upateOperation(ASSASSIN);
            game.setNumOfPlayers(game.numOfPlayers() - 1);

            return;
        }
        else if (isCuped())
        {
            updateTurns();
            return;
        }

        throw "Not His Turn";
=======

        game.eraseAt(p);
        setCoins(coins() - 3);
        this->setLastOperPlayer(otherPlayer);
        upateOperation(ASSASSIN);
>>>>>>> 0fd0e2e82c5791fc1620158877323faf2dd72de3
    }
    string Assassin::role()
    {
        return "Assassin";
    }

}
