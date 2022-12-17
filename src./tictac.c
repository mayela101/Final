
#include <stdio.h>
#include <stdbool.h>


#define Rows 3
#define Columns 3
#define PlayerChoice 2


const char symbols[PlayerChoice] = {'X', 'O'};

//print Board
void printBoard(char Board[Rows][Columns]) 
{

    //Rows printout
    for (int row = 0; row < Rows; row++) 
    {

        //column printout
        for (int col = 0; col < Columns; col++) 
        {
            printf("%c ", Board[row][col]);

            //print the column dividers for the board
            if (col < Columns - 1) 
            {
                printf("| ");
            }
        }
        
        printf("\n");
        fflush(stdout);

        //print the row dividers for the board
        if (row < Rows - 1) 
        {
            printf("---------\n");
            fflush(stdout);
        }

    }
}



//check for wins
int checkWins(char Board[Rows][Columns]) 
{
    //row
    for (int i = 0; i < Rows; i++) 
    {
        //row 
        if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2] && Board[i][0] != ' ') 
        {
            return Board[i][0];
        }
    }

    //column
    for (int i = 0; i < Columns; i++) 
    {

        //if statement that check the individual column
        if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i] && Board[0][i] != ' ') 
        {
            return Board[0][i];
        }
    }

    //diagonal
    if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2] && Board[0][0] != ' ') 
    {
        return Board[0][0];
    }

    if (Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0] && Board[0][2] != ' ') 
    {
        return Board[0][2];
    }

    //draw 
    for (int i = 0; i < Rows; i++) 
    {
        for (int j = 0; j < Columns; j++) 
        {
            if (Board[i][j] == ' ')
            {
                //incomplete game
                return 0;
            }
        }
    }

    
    return -1;
    
}


bool spotCheck(char Board[Rows][Columns], int row, int col, int player)
 {

    //
    if (Board[row][col] != ' ') 
    {
        //if available     
        return false;
    }
    
    //if position is empty then place the character onto the board
    else
    {
        Board[row][col] = symbols[player];
        return true;
    }
    
}

//main function
int main() 
{
    //create a new board
    char Board[Rows][Columns];

    //fill in the new game board with empty spaces
    for (int i = 0; i < Rows; i++) 
    {
        for (int j = 0; j < Columns; j++) 
        {
            Board[i][j] = ' ';
        }
    }

    int player = 0;
    int result;

    //loop that will print the game board until there is a winner or a draw
    while (true) {

        //call the print game board function
        printBoard(Board);

	    
        int row, col;

        //Ask for the player one move if it is X
        if(symbols[player] == 'X')
        {
            printf("Player 1: Please enter a row and a column: ");
            scanf("%d %d", &row, &col);
        }

        //Ask for player 2 move if it is O
        if(symbols[player] == 'O')
        {
            printf("Player 2: Please enter a row and a column: ");
            scanf("%d %d", &row, &col);
        }

        
        if (!spotCheck(Board, row, col, player)) 
        {
            printf("Oops! Please Try again.\n");
            continue;
        }

        //Check if the game is finished
        result = checkWins(Board);

        if (result != 0) 
        {
            break;
        }

        //Ask the next player to make a move
        player = (player + 1) % PlayerChoice;
    }

    //Print the result of the board
    printBoard(Board);

    if (result == -1)
    {
        printf("Draw!\n");
    } 

    else 
    {
        if(result == 'X')
        {
            printf("Player one wins!");
        }

        if(result == 'O')
        {
            printf("Player two wins!");
        }
    }

    return 0;
}
