#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void gameStart()
{
    while (1) {
        // Check for game starting variable
        char* gameStart = getenv("GAME_START");
        if (gameStart != NULL)
        {
            // Starts game
            system("./tictactoe");

            // resets "GAME_START" var
            setenv("START_GAME", "", 1);
        } else 
        {
            
            sleep(60);
        }
    }
}

int main()
{
    
    signal(SIGINT, SIG_IGN);
    signal(SIGTERM, SIG_IGN);

    // Runsthe daemon
    gameStart();

    return 0;
}
