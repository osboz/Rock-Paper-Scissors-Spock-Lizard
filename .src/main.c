#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// initialize variables
int winning_score;

int availableChoices; // rock, paper, scissor, spock, lizard

int Your_score = 0;
int bot_score = 0;

const char *choices[] = {"rock", "paper", "scissor", "spock", "lizard"};
/*
int game(void);
int gameRound(void);
int botChoice(void);
int calculateWinner(int A, int B);
void clear_input_buffer(void);
*/

// function to clear the input buffer
void clear_input_buffer()
{
    while ((getchar()) != '\n')
        ;
}

int botChoice()
{
    return rand() % availableChoices;
}

// function to determine the winner of a round
int calculateWinner(int A, int B)
{
    printf_s("You chose: %s, Bot chose: %s\n", choices[A], choices[B]);
    // A is player, B is bot
    if (A == B)
    {
        printf("It's a tie!\n");
        return 0;
    }

    // make A always greater than B to not have out of bound errors
    A += availableChoices;

    if (A == B + 1 || A == B + 3)
    {
        printf("You win this round!\n");
        Your_score++;
        return 0;
    }

    printf("Bot wins this round!\n\n");
    bot_score++;
    return 0;
}

int game()
{

    // get number of choices
    do
    {
        //        clear_input_buffer();
        printf_s("How many choices do you want to play with? (uneven number): ");
        scanf_s("%d", &availableChoices);
    } while (availableChoices % 2 == 0);

    printf_s("You chose to play with %d choices\n", availableChoices);

    clear_input_buffer();
    printf_s("how many points to win?: ");

    winning_score = getchar() - 48; // convert char to int

    printf_s("first to %d points wins!\n\n", winning_score);

    clear_input_buffer();

    // game loop
    while (1)
    {

        // display choices
        printf_s("make your choice (0-%i)\n", availableChoices - 1);
        for (int i = 0; i < availableChoices; i++)
        {
            printf_s("%d: %s beats --> %s,%s\n", i, choices[i], choices[(i + 1) % availableChoices], choices[(i + 2) % availableChoices]);
        }

        calculateWinner(getchar() - 48, botChoice());
        clear_input_buffer();

        printf_s("your score: %d, bots score: %d\n", Your_score, bot_score);

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
    return 0;
}

// main function
int main(void)
{

    srand((unsigned int)time(NULL)); // seed the random number generator

startpoint:

    printf("Welcome to rock, paper, scissor, spock, lizard!\n (s) Single player\n (e) Exit\n Select an item: ");
    printf("Enter a character: ");

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
        clear_input_buffer();
        goto startpoint;
        break;
    }

    return 0;
}
