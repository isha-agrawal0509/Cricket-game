#include "game.h"
using namespace std;

int main()
{
    Game game;
    game.welcome();

    cout << "\nPress Enter to continue... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    game.showAllPlayers();

    cout << "\nPress Enter to continue... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    game.selectPlayers();

    game.showTeamPlayers();

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nPress Enter to toss";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    game.toss();

    game.startFirstInnings();
    usleep(2000000);
    game.startSecondInnings();

    usleep(1000000);
    game.decideWinner();

    usleep(1000000);
    game.showSummary();

    return 0;
}
