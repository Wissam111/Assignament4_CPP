/*
 * AUTHORS: Wissam kabha
 * gitHub: https://github.com/Wissam111
 * Date: 04/2022
 */

#include "Game.hpp"
namespace coup
{

    /*
     * @brief  players thats still in the game
     */
    vector<string> Game::players()
    {
        vector<string> _players;
        for (int i = 0; i < _playersMap.size(); i++)
        {
            if (!_playersMap[i].isCouped)
            {
                _players.push_back(_playersMap[i].name);
            }
        }
        return _players;
    }

    /*
     * @brief  update players turns each round
     */
    void Game::updateTurns()
    {

        if (_numOfPlayers == 1 && !running)
        {
            throw "Should be more then 1";
        }
        if (_numOfPlayers > 1)
        {
            running = true;
        }
        if (_currPlayerTurn == _numOfPlayers - 1)
        {
            setTurn(0);
        }
        else
        {
            setTurn(_currPlayerTurn + 1);
        }
    }

    /*
     * @brief  reset all turns when player is out
     */
    void Game::resetTurns()
    {
        int t = 0;
        if (_currPlayerTurn == _numOfPlayers)
        {
            setTurn(0);
        }

        for (int i = 0; i < _playersMap.size(); i++)
        {
            if (!_playersMap[i].isCouped)
            {
                setPlayerTurn(i, t);
                t++;
            }
        }
    }

    string Game::winner()
    {

        if (_playersMap.size() == 1 || running)
        {
            throw "Game Still Running!!";
        }

        return players()[0];
    }

    string Game::turn()
    {
        return _playersMap[_currPlayerTurn].name;
    }
    void Game::setTurn(int currPlayerIndex)
    {
        this->_currPlayerTurn = currPlayerIndex;
    }

    int Game::numOfPlayers() const
    {
        return _numOfPlayers;
    }
    void Game::setNumOfPlayers(int num)
    {
        _numOfPlayers = num;
    }
    int Game::getTurn() const
    {
        return _currPlayerTurn;
    }

    void Game::setPlayerName(int playerIndex, string const &name)
    {
        _playersMap[playerIndex].name = name;
    }

    void Game::setCopued(int playerIndex, bool copued)
    {
        _playersMap[playerIndex].isCouped = copued;
    }
    void Game::setPlayerTurn(int playerIndex, int turn)
    {
        _playersMap[playerIndex].turn = turn;
    }
    int Game::playerTurn(int playerIndex)
    {
        return _playersMap[playerIndex].turn;
    }
    bool Game::isCopued(int playerIndex)
    {
        return _playersMap[playerIndex].isCouped;
    }
    void Game::setRunning(bool rn)
    {
        running = rn;
    }

    bool Game::Running() const
    {
        return running;
    }

}