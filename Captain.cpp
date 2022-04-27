/*
 * AUTHORS: Wissam kabha
 * gitHub: https://github.com/Wissam111
 * Date: 04/2022
 */

#include "Captain.hpp"
namespace coup
{

    void Captain::steal(Player &otherPlayer)
    {

        int plrT = game.playerTurn(player_index);
        bool b = (plrT == game.getTurn() && !game.isCopued(player_index));
        if (otherPlayer.coins() < 2 || coins() >= tenCoins || !b)
        {
            throw invalid_argument("Invalid operations!");
        }

        game.updateTurns();
        this->setLastOperPlayer(otherPlayer);
        this->setCoins(_coins + 2);
        otherPlayer.setCoins(otherPlayer.coins() - 2);
        upateOperation(STEAL);
    }

    void Captain::block(Player &otherPlayer)
    {
        if (otherPlayer.getLastOper() == STEAL)
        {

            int c = otherPlayer.getLastPlayer().coins();
            this->setCoins(coins() - 2);
            otherPlayer.getLastPlayer().setCoins(c + 2);
            return;
        }

        throw invalid_argument("Invalid operations!");
    }

    string Captain::role()
    {
        return "Captain";
    }
}