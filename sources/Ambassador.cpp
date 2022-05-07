
/*
 * AUTHORS: Wissam kabha
 * gitHub: https://github.com/Wissam111
 * Date: 04/2022
 */

#include "Ambassador.hpp"
namespace coup
{

    void Ambassador::transfer(Player &player1, Player &player2)
    {
        int plrT = game.playerTurn(player_index);
        bool b = (plrT == game.getTurn() && !game.isCopued(player_index));
        if (coins() >= tenCoins || player1.coins() < 1 || !b)
        {
            throw invalid_argument("Invalid operations!");
        }
        game.updateTurns();
        player1.setCoins(player1.coins() - 1);
        player2.setCoins(player2.coins() + 1);
        upateOperation(TRANSFER);
    }

    void Ambassador::block(Player &otherPlayer)
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
    string Ambassador::role()
    {
        return "Ambassador";
    }
}
