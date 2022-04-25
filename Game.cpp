
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
        if (!_isRunning)
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
        return _players.size();
    }

    int Game::getCurr()
    {
        return _currPlayer;
    }

    int Game::getPlayerIndex(string playerName)
    {
        for (int i = 0; i < _players.size(); i++)
        {
            if (_players[unsigned(i)] == playerName)
            {
                return i;
            }
        }

        return -1;
    }

    void Game::eraseAt(int index)
    {

        _players.erase(_players.begin() + index);
    }

}