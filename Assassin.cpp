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
    }
    string Assassin::role()
    {
        return "Assassin";
    }

}
