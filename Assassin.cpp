/*
 * AUTHORS: Wissam kabha
 * gitHub: https://github.com/Wissam111
 * Date: 04/2022
 */

#include "Assassin.hpp"
#include "Player.hpp"
namespace coup
{

    void Assassin::coup(Player &otherPlayer)
    {

        int plrT = game.playerTurn(player_index);
        int otherplrT = game.playerTurn(otherPlayer.getPlayerIndex());
        bool b = (plrT == game.getTurn() && !game.isCopued(player_index));
        if (coins() < threeCoins || !b)
        {
            throw invalid_argument("Invalid operations!");
        }
        game.setCopued(otherPlayer.getPlayerIndex(), true);
        game.resetTurns();
        if (game.getTurn() < otherplrT)
        {
            game.updateTurns();
        }
        setCoins(coins() - threeCoins);
        setLastOperPlayer(otherPlayer);
        upateOperation(ASSASSIN);
        game.setNumOfPlayers(game.numOfPlayers() - 1);
    }
    string Assassin::role()
    {
        return "Assassin";
    }
}
