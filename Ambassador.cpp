#include "Ambassador.hpp"

namespace coup
{

    void Ambassador::transfer(Player &player1, Player &player2)
    {
        int p1 = game.getPlayerIndex(player1.getName());
        int p2 = game.getPlayerIndex(player2.getName());
        if (player1.coins() < 1 || p1 == -1 || p2 == -1)
        {
            throw "Invalid operation";
        }

        player1.setCoins(player1.coins() - 1);
        player2.setCoins(player1.coins() + 1);
    }

}
