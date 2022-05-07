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
        if (coins() >= tenCoins || !b)
        {
            throw invalid_argument("Invalid operations!");
        }

        if (otherPlayer.coins() >= 2)
        {
            this->setCoins(_coins + 2);
            otherPlayer.setCoins(otherPlayer.coins() - 2);
            upateOperation(STEAL);
        }
        else if (otherPlayer.coins() == 1)
        {
            this->setCoins(_coins + 1);
            otherPlayer.setCoins(otherPlayer.coins() - 1);
            upateOperation(STEAL1);
        }

        this->setLastOperPlayer(otherPlayer);
        game.updateTurns();
    }

    void Captain::block(Player &otherPlayer)
    {
        if (otherPlayer.getLastOper() != STEAL && otherPlayer.getLastOper() != STEAL1)
        {
            throw invalid_argument("Invalid operations!");
        }
        if (otherPlayer.getLastOper() == STEAL)
        {
            int c1 = otherPlayer.getLastPlayer().coins();
            int c2 = otherPlayer.coins();
            otherPlayer.setCoins(c2 - 2);
            otherPlayer.getLastPlayer().setCoins(c1 + 2);
        }
        else if (otherPlayer.getLastOper() == STEAL1)
        {
            int c1 = otherPlayer.getLastPlayer().coins();
            int c2 = otherPlayer.coins();
            otherPlayer.setCoins(c2 - 1);
            otherPlayer.getLastPlayer().setCoins(c1 + 1);
        }
    }

    string Captain::role()
    {
        return "Captain";
    }
}