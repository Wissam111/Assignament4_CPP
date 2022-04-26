
#include "Game.hpp"

namespace coup
{

    vector<string> &Game::players()
    {
        return this->_players;
    }

    string Game::turn()
    {
        return _players[unsigned(_currPlayer)];
    }

    string Game::winner()
    {

        if (_numOfPlayers == 1)
        {
            return _winner;
        }

        throw "Game Still Running!!";
    }

    void Game::setWinner(string winner)
    {
        this->_winner = winner;
    }

    void Game::setTurn(int currPlayerIndex)
    {
        this->_currPlayer = currPlayerIndex;
    }

    int Game::numOfPlayers()
    {
        return _numOfPlayers;
    }
    void Game::setNumOfPlayers(int num)
    {
        _numOfPlayers = num;
    }
    int Game::getTurn()
    {
        return _currPlayer;
    }

}