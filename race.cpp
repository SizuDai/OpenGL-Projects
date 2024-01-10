#include <iostream>
#include <conio.h>

using namespace std;

const int WIDTH = 20;  // Width of the race track
const int HEIGHT = 10; // Height of the race track
int player1Pos = 0;    // Player 1 position
int player2Pos = 0;    // Player 2 position

// Function to draw the race track
void drawTrack()
{
    system("cls"); // Clear the console

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (i == player1Pos && j == 0)
            {
                cout << "1"; // Player 1
            }
            else if (i == player2Pos && j == 0)
            {
                cout << "2"; // Player 2
            }
            else
            {
                cout << "."; // Empty track
            }
        }
        cout << endl;
    }
}

// Function to handle key presses
void handleKeyPress()
{
    if (_kbhit())
    {
        char key = _getch();

        if (key == 'w' && player1Pos > 0)
        {
            player1Pos--; // Move player 1 up
        }
        else if (key == 's' && player1Pos < HEIGHT - 1)
        {
            player1Pos++; // Move player 1 down
        }
        else if (key == 'i' && player2Pos > 0)
        {
            player2Pos--; // Move player 2 up
        }
        else if (key == 'k' && player2Pos < HEIGHT - 1)
        {
            player2Pos++; // Move player 2 down
        }
    }
}

// Function to update the game logic
void updateGame()
{
    drawTrack();
    handleKeyPress();
}

int main()
{
    while (true)
    {
        updateGame();
        Sleep(100); // Delay to control game speed
    }

    return 0;
}