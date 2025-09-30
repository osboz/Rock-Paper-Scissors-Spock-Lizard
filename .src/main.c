#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// initialize variables
int winning_score;    // score needed to win the game
int availableChoices; // number of choices in the game

int Your_score;
int bot_score;

// function to clear the input buffer
void clearInputBuffer()
{
    while ((getchar()) != '\n')
        ;
}

// Function to check if the input matches a given option
int checkChar(char option)
{
    if (getchar() == option)
    {
        return 1;
        clearInputBuffer();
    }
    clearInputBuffer();
    return 0;
}

// function to check if int is in range, 
int intInRange(int min, int max, int num)
{
    if (num < min || num > max)
    {
        printf_s("invalid, Number not in between %d-%d\n", min, max);
        return 0;
    }
    return 1;
}

// Function to check if input with scanf_s is an integer within a range
int validInt()
{
    int num;
    char term;
    if (scanf("%d%c", &num, &term) != 2 || term != '\n')
    {
        printf("failure\n");
        return 0;
    }
    else
    {
        printf("valid integer followed by enter key\n");
        return 1;
    }
}
// Function to get an integer, // from https://stackoverflow.com/questions/1648043/how-to-check-if-input-is-an-integer-in-c
int getInt(const char *question, const char *error)
{
    int num;
    char term;
    while (1)
    {
        if (question != NULL)
        {
            printf("%s", question);
        }
        if (scanf("%d%c", &num, &term) == 2 && term == '\n')
        {
            return num;
        }
        if (error != NULL)
        {
            printf("%s\n", error);
        }
        clearInputBuffer();
    }
}

int botChoice()
{
    return rand() % availableChoices;
}

// function to determine the winner of a round
int calculateWinner(int A, int B)
{
    printf_s("You chose: %d <-> Bot chose: %d\n", A, B);
    // A is player, B is bot
    if (A == B)
    {
        printf("It's a tie!\n");
        return 0;
    }

    // Player wins if (A - B) is odd
    if ((A - B) % 2 == 1)
    {
        printf("You win this round!\n");
        Your_score++;
        return 1;
    }

    printf("Bot wins this round!\n");
    bot_score++;
    return 0;
}

// main game function
int game()
{
fullGameStart:
    clearInputBuffer();
    // get number of choices
    while (1)
    {
        availableChoices = getInt("Enter number of choices: ", NULL);
        if (availableChoices > 2 && availableChoices % 2 == 1)
            break;
        printf_s("Invalid input. Please enter an odd number greater than 2.\n");
    }
    printf_s("You chose to play with %d choices\n", availableChoices);

    // get winning score
    while (winning_score <= 0)
    {
        winning_score = getInt("How many points to win?: ", "Invalid input. Please enter a whole number");
    }
    printf_s("first to %d points wins!\n\n", winning_score);

gameStart:
    Your_score = 0;
    bot_score = 0;
    // game loop
    while (1)
    {
    loopStart:

        int number = 0;

        char question[50];
        snprintf(question, sizeof(question), "Make your choice (0-%i):\n\n", availableChoices - 1);

        do
        {
            number = getInt(question, "Invalid input. Please enter a valid input");
        } while (intInRange(0, availableChoices - 1, number) == 0);

        calculateWinner(number, botChoice());

        printf_s("Your score: %d <-> Bots score: %d\n", Your_score, bot_score);

        if (Your_score >= winning_score)
        {
            printf("You win the game!\n");
            printf("Pure luck!\n\n");
            break;
        }
        else if (bot_score >= winning_score)
        {
            printf("Bot wins the game!\n");
            printf("LMAO you shit!\n\n");
            break;
        }
    }

    printf_s("Do you want to play again? \nyes / no: ");
    if (getchar() != 'y')
    {
        return 0;
    }

    printf_s("Do you want to use the same settings? \nyes / no: ");
    if (getchar() != 'y')
    {
        goto fullGameStart;
    }
    goto gameStart;

    return 0;
}

// main function
int main(void)
{
    srand((unsigned int)time(NULL)); // seed the random number generator

startpoint:

    printf("Welcome to rock, paper, scissor, spock, lizard! \n(s)ingle player \n(e)xit \nEnter a character: ");

    switch (getchar())
    {
        // start game
    case 's':
        printf("Starting game: yay\n");
        game();

        break;

        // exit game
    case 'e':
        printf("Exiting the game. Goodbye!\n");
        exit(0);
        break;

        // invalid input
    default:
        printf("Invalid input. Please try again.\n");
        clearInputBuffer();
        goto startpoint;
        break;
    }

    return 0;
}
