#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
namespace coup
{

    enum OPERATION
    {
        INCOME,
        FOREIGN_AID,
        COUP,
        ROLE,
        BLOCK,
        TRANSFER,
        ASSASSIN,
        TAX,
        STEAL
    };

    class Game
    {
    private:
        vector<string> _players;
        int _currPlayer = 0;
        int _numOfPlayers = 0;
        string _winner;
        bool _isRunning = false;

    public:
<<<<<<< HEAD
        Game(){};
        ~Game(){};
        int numOfPlayers();
        void setNumOfPlayers(int num);
=======
        Game() { _isRunning = true; }
        ~Game(){};
        int numOfPlayers();

>>>>>>> 0fd0e2e82c5791fc1620158877323faf2dd72de3
        vector<string> &players();
        void setWinner(string winner);
        void setTurn(int currPlayerIndex);
        int getTurn();
        string turn();
        string winner();
    };

}