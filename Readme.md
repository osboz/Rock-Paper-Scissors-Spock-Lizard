# Rock paper scissors Spock lizard opgave

Draw a flowchart for this [problem](#problem).
> Flowchart : [Flowchart](flowchart_RPPSC.png)

Make code to solve the [problem](#problem)
> Da code : [code](.src/main.c)

---

## Problem 
You must have played Rock paper scissors in your childhood. In this problem, we will implement a variation with Spock and lizard shapes which we refer to as RPSSL.

Expectations:

- Has an entry menu
- The agent can play randomly
- Shows score after each shape comparison

- Can handle wrong input both in the menu and gameplay, e.g., by showing an error message
    - In case you know EOF: you don’t have to handle it

- If a player reaches the WINNING_SCORE
    - Then this player wins
    - The program exits.


## Changes

- Player can choose how many differernt choises they want to play with.
- Player can choose how many points the games goes to.
- Player can chose to play again after game is won or lost.
- Removed Rock, Paper, Scissors, Spock and Lizard in favor of using numbers.
    - Instead the player wins if (player-choice - Bot-choise) is odd. Else player looses

