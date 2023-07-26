#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <unistd.h>
#include "team.h"   // "player.h", <string>, <vector>

class Game
{
    public:
        Game();
        int playersPerTeam;
        int maxBalls;
        int totalPLayers;
        std::string players[11];

        Team teamA, teamB;
        Team *battingTeam, *bowlingTeam;
        Player *batsman, *bowler;
        bool isFirstInnings;
        void welcome();
        void showAllPlayers();
        int takeIntegerInput();
        void selectPlayers();
        bool validateSelectedPlayer(int);
        void showTeamPlayers();
        void toss();
        void tossChoice(Team);
        void startFirstInnings();
        void initializePlayers();
        void playInnings();
        void bat1();
        bool validateInningsScore();
        void showGameScorecard1();
        void startSecondInnings();
        void bat2();
        void showGameScorecard2();
        void decideWinner();
        void showSummary();
};

#endif // GAME_H
