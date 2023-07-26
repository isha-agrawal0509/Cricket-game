#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player
{
    public:
        Player();
        std::string name;
        int id;
        int runsScored;
        int ballsPlayed;
        int ballsBowled;
        int runsGiven;
        int wicketsTaken;

};

#endif // PLAYER_H
