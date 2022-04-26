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
        if (player_index == game.getTurn() && !_COUPED)
        {
            // game.eraseAt(p);
            otherPlayer.setCuped(true); // killed/Cuped
            updateTurns();
            updateGameList();
            setCoins(coins() - 3);
            this->setLastOperPlayer(otherPlayer.getPlayerIndex());
            upateOperation(ASSASSIN);
            game.setNumOfPlayers(game.numOfPlayers() - 1);

            return;
        }
        else if (_COUPED)
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
