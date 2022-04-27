
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
        player2.setCoins(player1.coins() + 1);
        upateOperation(FOREIGN_AID);
    }

    void Ambassador::block(Player &otherPlayer)
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
}
