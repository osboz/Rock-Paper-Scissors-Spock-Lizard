#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random number between min and max (inclusive)
int RandomNumberInt(int min, int max)
{
    srand((unsigned int)time(NULL));
    return rand() % (max - min + 1) + min;
}

/* Function to get a validated integer input from the user within a range
(min, max, printpromt 0-1)*/
int GetIntInputMinMax(int min, int max, int PrintPrompt)
{
    char buffer[100]; // Buffer to hold the input string
    if (PrintPrompt)
        printf("Enter an integer between %i-%i: ", min, max);

    // Read a line of input
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        // Convert the first part of the string to an integer
        return atoi(buffer); // atoi converts the string to an integer
    }

    return 0; // Return 0 if input fails
}

// Function to get a validated integer input from the user
int GetIntInput()
{
    char buffer[100]; // Buffer to hold the input string

    // Read a line of input
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        // Convert the first part of the string to an integer
        return atoi(buffer); // atoi converts the string to an integer
    }

    return 0; // Return 0 if input fails
}

int GetnumberInput()
{
    int number;
    while (1)
    {
        printf("Enter a number: ");
        if (fgets("%d", &number, stdin) == 1)
        {
            clear_input_buffer(); // Clear the buffer after successful input
            return number;
        }
        else
        {
            printf("Invalid input. Please enter a valid number.\n");
            clear_input_buffer(); // Clear the buffer to remove invalid input
        }
    }
}