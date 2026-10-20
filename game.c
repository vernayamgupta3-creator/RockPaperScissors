#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showMove(int choice)
{
    if (choice == 1)
        printf("Rock");
    else if (choice == 2)
        printf("Paper");
    else
        printf("Scissors");
}

int main()
{
    int player, computer;
    int playerScore = 0;
    int computerScore = 0;
    int draws = 0;
    int rounds = 0;

     srand((unsigned int)time(NULL));

    printf("\n");
    printf("====================================\n");
    printf("       ROCK PAPER SCISSORS\n");
    printf("====================================\n");
    printf("Welcome to the game!\n");

    while (1)
    {
        printf("\nChoose your move:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("0. Quit Game\n");
        printf("Enter your choice: ");

        if (scanf("%d", &player) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            return 1;
        }

        if (player == 0)
            break;

        if (player < 1 || player > 3)
        {
            printf("Please choose 1, 2, 3, or 0.\n");
            continue;
        }

        computer = rand() % 3 + 1;
        rounds++;

        printf("\nYou chose: ");
        showMove(player);

        printf("\nComputer chose: ");
        showMove(computer);

        printf("\n\n");

        if (player == computer)
        {
            printf("Result: IT'S A DRAW!\n");
            draws++;
        }
        else if ((player == 1 && computer == 3) ||
                 (player == 2 && computer == 1) ||
                 (player == 3 && computer == 2))
        {
            printf("Result: YOU WIN!\n");
            playerScore++;
        }
        else
        {
            printf("Result: COMPUTER WINS!\n");
            computerScore++;
        }

        printf("\n----------- SCOREBOARD -----------\n");
        printf("Rounds played : %d\n", rounds);
        printf("Your wins     : %d\n", playerScore);
        printf("Computer wins : %d\n", computerScore);
        printf("Draws         : %d\n", draws);
        printf("----------------------------------\n");
    }

    printf("\n====================================\n");
    printf("           FINAL RESULTS\n");
    printf("====================================\n");
    printf("Total rounds  : %d\n", rounds);
    printf("Your wins     : %d\n", playerScore);
    printf("Computer wins : %d\n", computerScore);
    printf("Draws         : %d\n", draws);

    if (playerScore > computerScore)
        printf("\nCongratulations! You are the champion!\n");
    else if (computerScore > playerScore)
        printf("\nComputer wins! Better luck next time!\n");
    else
        printf("\nThe match ends in a tie!\n");

    printf("\nThanks for playing!\n");

    return 0;
    
}
