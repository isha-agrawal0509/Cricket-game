#include "game.h"
using namespace std;

Game::Game()
{
    playersPerTeam = 4;
    maxBalls = 6;
    totalPLayers = 11;

    players[0] = "Virat Kohli";
    players[1] = "Rohit Sharma";
    players[2] = "Shikhar Dhawan";
    players[3] = "Rishabh Pant";
    players[4] = "Dinesh Karthik";
    players[5] = "K.L. Rahul";
    players[6] = "M.S. Dhoni";
    players[7] = "Ravindra Jadeja";
    players[8] = "Hardik Pandya";
    players[9] = "Jasprit Bumrah";
    players[10] = "Ishant Sharma";

    isFirstInnings = false;
    teamA.name = "Team-A";
    teamB.name = "Team-B";
}

void Game::welcome(){
    cout << "-------------------------------------------------------------------\n";
    cout << "|============================ CRIC-IN ============================|\n";
    cout << "|                                                                 |\n";
    cout << "|                 Welcome to Virtual Cricket Game                 |\n";
    cout << "-------------------------------------------------------------------\n";
    cout << endl << endl;

    cout << "-------------------------------------------------------------------\n";
    cout << "|========================== Instructions =========================|\n";
    cout << "-------------------------------------------------------------------\n";
    cout << "|                                                                 |\n";
    cout << "| 1. Each team will have 4 players.                               |\n";
    cout << "| 2. The players for each team will be selected by the user       |\n";
    cout << "|    from the given pool of 11 players.                           |\n";
    cout << "| 3. The sequence in which the players are selected for each      |\n";
    cout << "|    team will decide the batting and bowling sequence for        |\n" <<
            "|    that team.                                                   |\n";
    cout << "| 4. There will be 2 innings, each of 6 balls.                    |\n";
    cout << "-------------------------------------------------------------------\n";

}

void Game::showAllPlayers(){
    cout << "-------------------------------------------------------------------\n";
    cout << "|======================== Pool of Players ========================|\n";
    cout << "-------------------------------------------------------------------\n";
    for(int i = 0; i <= 10; i++){
        cout << "\t\t     [" << i << "]" << " " << players[i] << endl;
    }
    cout << "-------------------------------------------------------------------\n";
}

int Game::takeIntegerInput(){
    int n;
    while(!(cin >> n)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please try again with valid input: ";
    }
    return n;
}

bool Game::validateSelectedPlayer(int index){
    int n;
    vector<Player> players;

    players = teamA.players;
    n = players.size();
    for (int i = 0; i < n; i++){
        if(players[i].id == index){
            return false;
        }
    }

    players = teamB.players;
    n = players.size();
    for (int i = 0; i < n; i++){
        if(players[i].id  == index){
            return false;
        }
    }

    return true;
}

void Game::selectPlayers() {
    cout << endl;
    cout << "-------------------------------------------------------------------\n";
    cout << "|==================== Create Team-A and Team-B ===================|\n";
    cout << "-------------------------------------------------------------------\n";

    for(int i = 0; i < playersPerTeam; i++){
        //Add player to team A
        teamASelection:
            cout << endl << "Select player " << i + 1 << " of Team A - ";

            int playerIndexTeamA = takeIntegerInput();

            if(playerIndexTeamA < 0 || playerIndexTeamA > 10){
                cout << endl << "Please select from the given players" << endl;
                goto teamASelection;
            }
            else if(!validateSelectedPlayer(playerIndexTeamA)){
                cout << endl << "Player has been already selected. Please select another player." << endl;
                goto teamASelection;
            }
            else {
                Player teamAPlayer;
                teamAPlayer.id = playerIndexTeamA;
                teamAPlayer.name = players[playerIndexTeamA];
                teamA.players.push_back(teamAPlayer);
            }

        //Add player to team B
        teamBSelection:
            cout << endl << "Select player " << i + 1 << " of Team B - ";

            int playerIndexTeamB = takeIntegerInput();
            if(playerIndexTeamB < 0 || playerIndexTeamB > 10){
                cout << endl << "Please select from the given players" << endl;
                goto teamBSelection;
            }
            else if(!validateSelectedPlayer(playerIndexTeamB)){
                cout << endl << "Player has been already selected. Please select another player." << endl;
                goto teamBSelection;
            }
            else {
                Player teamBPlayer;
                teamBPlayer.id = playerIndexTeamB;
                teamBPlayer.name = players[playerIndexTeamB];
                teamB.players.push_back(teamBPlayer);
            }
    }
}

void Game::showTeamPlayers(){
    vector<Player> teamAPlayers = teamA.players;
    vector<Player> teamBPlayers = teamB.players;
    cout << endl << endl;

    cout << "----------------------------\t\t-----------------------------\n";
    cout << "|========== Team-A ========|\t\t|========== Team-B =========|\n";
    cout << "----------------------------\t\t-----------------------------\n";
    for(int i = 0; i < playersPerTeam; i++){
        cout << "|  " << "[" << i << "]" << teamAPlayers[i].name << "\t |" << "\t\t" << "|  " << "[" << i << "]" << teamBPlayers[i].name << "\t |" << endl;
    }
    cout << "----------------------------\t\t-----------------------------\n";
}

void Game::toss(){
    cout << "---------------------------------------------------------------\n";
    cout << "|========================= Let's Toss ========================|\n";
    cout << "---------------------------------------------------------------\n";

    usleep(1000000);
    cout << "Tossing the coin...\n";

    usleep(1000000);
    srand(time(NULL));
    int tossValue = rand() % 2;  // 0, 1

    switch (tossValue) {
        case 0:
            cout << "Team-A won the toss" << endl << endl;
            tossChoice(teamA);
            break;
        case 1:
            cout << "Team-B won the toss" << endl << endl;
            tossChoice(teamB);
            break;
    }

}

void Game::tossChoice(Team tossWinnerTeam){
    cout << "Enter 1 to bat or 2 to bowl first." << endl
         << "1. Bat" << endl
         << "2. Bowl" << endl;

    int tossInput = takeIntegerInput();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch(tossInput){
        case 1:
           cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;
           if (tossWinnerTeam.name.compare("Team-A") == 0){  //if Team-A is the toss winner
            battingTeam = &teamA;
            bowlingTeam = &teamB;
           }
           else {  //else Team-B is the toss winner
            battingTeam = &teamB;
            bowlingTeam = &teamA;
           }

           break;
        case 2:
            cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;
            if (tossWinnerTeam.name.compare("Team-A") == 0){  //if Team-A is the toss winner
                battingTeam = &teamB;
                bowlingTeam = &teamA;
           }
            else {  //else Team-B is the toss winner
                battingTeam = &teamA;
                bowlingTeam = &teamB;
           }

            break;
        default:
            cout << "Invalid input. Please try again: " << endl << endl;
            tossChoice(tossWinnerTeam);
            break;
    }
}

void Game::startFirstInnings(){

    cout << "\t\t ||| FIRST INNINGS STARTS ||| " << endl << endl;
    isFirstInnings = true;
    initializePlayers();
    playInnings();
}

void Game::initializePlayers(){
    // Choose batsman and bowler. Initialize *batsman and *bowler
    batsman = &battingTeam->players[0];
    bowler = &bowlingTeam->players[0];

    cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
    cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
}

void Game::playInnings(){
    for(int i = 0; i < maxBalls; i++){

        cout << "Press Enter to bowl...";
        getchar();
        cout << "Bowling..." << endl;
        if(isFirstInnings){
            bat1();
        }
        else{
            bat2();
        }

        if(!validateInningsScore()){
            break;
        }
    }
}

void Game::bat1(){
    srand(time(NULL));
    int runsScored = rand() % 7;

    //Update batting team and batsman score
    batsman->runsScored = batsman->runsScored + runsScored;
    battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
    batsman->ballsPlayed = batsman->ballsPlayed + 1;

    //Update bowling team and bowler score
    bowler->ballsBowled = bowler->ballsBowled + 1;
    bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
    bowler->runsGiven = bowler->runsGiven + runsScored;


    if(runsScored != 0) {
        cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
        showGameScorecard1();
    }
    else {
        cout << endl << bowler->name << " to " << batsman->name << " OUT! " << endl << endl;

        battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
        bowler->wicketsTaken = bowler->wicketsTaken + 1;

        showGameScorecard1();

        int nextPlayerIndex = battingTeam->wicketsLost;
        batsman = &battingTeam->players[nextPlayerIndex];
    }

}

bool Game::validateInningsScore(){
    if(isFirstInnings) {
        if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls){
            cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

            cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;

            cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1 << " runs to win the match" << endl << endl;

            return false;
        }
    }
    else {
        if(bowlingTeam->wicketsLost == playersPerTeam || battingTeam->totalBallsBowled == maxBalls || bowlingTeam->totalRunsScored > battingTeam->totalRunsScored){
            cout << "\t\t ||| SECOND INNINGS ENDS |||" << endl << endl;

            return false;
        }
    }
    return true;
}

void Game::showGameScorecard1(){
    cout << "-------------------------------------------------------------------\n";

    cout << battingTeam->name << "  " << battingTeam->totalRunsScored << " - "
      << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name
      << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ")   " << bowler->name << " "
	  << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

    cout << "-------------------------------------------------------------------\n";
}

void Game::startSecondInnings(){
    cout << "\t\t ||| SECOND INNINGS STARTS ||| " << endl << endl;
    isFirstInnings = false;
    batsman = &bowlingTeam->players[0];
    bowler = &battingTeam->players[0];
    cout << bowlingTeam->name << " - " << batsman->name << " is batting " << endl;
    cout << battingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
    playInnings();
}

void Game::bat2(){
    srand(time(NULL));
    int runsScored = rand() % 7;

    //Update batting team and batsman score
    batsman->runsScored = batsman->runsScored + runsScored;
    bowlingTeam->totalRunsScored = bowlingTeam->totalRunsScored + runsScored;
    batsman->ballsPlayed = batsman->ballsPlayed + 1;

    //Update bowling team and bowler score
    bowler->ballsBowled = bowler->ballsBowled + 1;
    battingTeam->totalBallsBowled = battingTeam->totalBallsBowled + 1;
    bowler->runsGiven = bowler->runsGiven + runsScored;


    if(runsScored != 0) {
        cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
        showGameScorecard2();
    }
    else {
        cout << endl << bowler->name << " to " << batsman->name << " OUT! " << endl << endl;

        bowlingTeam->wicketsLost = bowlingTeam->wicketsLost + 1;
        bowler->wicketsTaken = bowler->wicketsTaken + 1;

        showGameScorecard2();

        int nextPlayerIndex = bowlingTeam->wicketsLost;
        batsman = &bowlingTeam->players[nextPlayerIndex];
    }
}

void Game::showGameScorecard2(){
    cout << "-------------------------------------------------------------------\n";

    cout << bowlingTeam->name << "  " << bowlingTeam->totalRunsScored << " - " << bowlingTeam->wicketsLost << " (" <<battingTeam->totalBallsBowled << ") | " << batsman->name << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " " << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << endl;

    cout << "-------------------------------------------------------------------\n";
}

void Game::decideWinner(){
    if(bowlingTeam->totalRunsScored > battingTeam->totalRunsScored){
        cout << bowlingTeam->name << " won the match by " << playersPerTeam - bowlingTeam->wicketsLost << " wickets!!!" << endl << endl;
    }
    else if(bowlingTeam->totalRunsScored < battingTeam->totalRunsScored){
        cout << bowlingTeam->name << " won the match by " << battingTeam->totalRunsScored - bowlingTeam->totalRunsScored << " runs!!!" << endl << endl;
    }
    else if(bowlingTeam->totalRunsScored == battingTeam->totalRunsScored){
        cout << "It's a TIE!!!" << endl << endl;
    }
    cout << "\t\t ||| MATCH ENDS |||" << endl << endl;
}

void Game::showSummary(){
    cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;
    cout << "===================================================================\n";
    cout << "|         PLAYER             BATTING             BOWLING          |\n";
    for(int i = 0; i < playersPerTeam; i++){
        cout << "|-----------------------------------------------------------------|\n";
        cout << "|  [" << i << "] " << battingTeam->players[i].name << "\t\t" << battingTeam->players[i].runsScored << " (" << battingTeam->players[i].ballsPlayed << ")\t\t" << battingTeam->players[i].ballsBowled << " - " << battingTeam->players[i].runsGiven << " - " << battingTeam->players[i].wicketsTaken << "\t  |"<< endl;

}
    cout << "===================================================================\n\n\n";

    usleep(1000000);

    cout << bowlingTeam->name << " " << bowlingTeam->totalRunsScored << " - " << bowlingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled << ")" << endl;
    cout << "===================================================================\n";
    cout << "|         PLAYER             BATTING             BOWLING          |\n";
    for(int i = 0; i < playersPerTeam; i++){
        cout << "|-----------------------------------------------------------------|\n";
        cout << "|  [" << i << "] " << bowlingTeam->players[i].name << "\t\t" << bowlingTeam->players[i].runsScored << " (" << bowlingTeam->players[i].ballsPlayed << ")\t\t" << bowlingTeam->players[i].ballsBowled << " - " << bowlingTeam->players[i].runsGiven << " - " << bowlingTeam->players[i].wicketsTaken << "\t  |"<< endl;

}
    cout << "===================================================================\n\n\n";
}
