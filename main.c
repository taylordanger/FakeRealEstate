#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_INPUT_LENGTH 100
// Structure to store information about the player
typedef struct {
    char name[MAX_NAME_LENGTH];
    int hasArtifact;
} Player;

// Function to get user input with error checking
void getUserInput(char *input, int maxLength) {
    fgets(input, maxLength, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character
}
// Function to print the game's introduction
void printIntro()
{
    int ch;

    initscr(); // Initialize the curses library
    cbreak(); // Disable line buffering
    noecho(); // Disable echoing of input characters
    keypad(stdscr, TRUE); // Enable the use of function keys

    printw("===========================================\n");
    printw("**********FAKE REAL ESTATE AGENT***********\n");
    printw("===========================================\n");
    printw("          Press any key to start             ");
    refresh();

    ch = getch(); // Wait for user input

    if (ch != ERR)  // If a key was pressed
        system("clear"); // Clear the screen
        printw("You are a burglar who just broke into a house, but there are two people inside waiting for their real estate agent to show them the house.\n");
        printw("Your objective is to get the precious artifact out of the home while tricking the people into thinking you are a real estate agent and not a burglar.\n\n");
        refresh();

    ch = getch();

    }

// Function to initialize the player's information
void initPlayer(Player *player) {
    printf("What is your name? ");
    getUserInput(player->name, MAX_NAME_LENGTH);
    player->hasArtifact = 0;
    printf("Welcome, %s. Good luck with your mission.\n\n", player->name);
}

//function to print the house layout for the player with each incursion of the question loop
void PrintMap()
{
    printf("                +---------------+\n");
    printf("                |               |\n");
    printf("                |     Living    |\n");
    printf("                |               |\n");
    printf("+---------------+---------------+---------------+\n");
    printf("|               |               |               |\n");
    printf("|     Bed 1     |     front     |     Dining    |\n");
    printf("|               |               |               |\n");
    printf("+---------------+---------------+---------------+\n");
    printf("                |               |\n");
    printf("                |     closet    |\n");
    printf("                |               |\n");
    printf("                +---------------+\n");
}
// Function to simulate a conversation with one of the people inside the house
void talkToPerson(char *personName, int *isSuspicious) {
    printf("You approach %s and start a conversation.\n", personName);
    printf("They ask if you are the real estate agent.\n");
    printf("What do you say? ");

    char input[MAX_INPUT_LENGTH];
    getUserInput(input, MAX_INPUT_LENGTH);

    if (strstr(input, "yes") != NULL || strstr(input, "Yes") != NULL) {
        printf("You say yes, and %s seems to believe you.\n\n", personName);
    } else {
        printf("You say no, and %s becomes suspicious of you.\n\n", personName);
        *isSuspicious = 1;
    }
}
int main()
{
         // Seed the random number generator
    srand(time(NULL));

    // Initialize the player's information
    Player player;
    initPlayer(&player);

    // Print the game's introduction
    printIntro();

    // Initialize the game's variables
    int hasArtifact = 0;
    int numSuspicious = 0;

    mvprintw(0, 0, "Artifact: %d Suspicion: %d", hasArtifact, numSuspicious);
    refresh();

    // Start the game loop
    while (!hasArtifact || numSuspicious < 2) {
        PrintMap();
        printf("You are in the living room of the house. There are two people here waiting for their real estate agent to show them the house.\n");
        printf("What do you want to do?\n");
        printf("1. Look for the artifact.\n");
        printf("2. Talk to the people.\n");
        printf("3. Leave the house.\n");
        printf("Enter your choice: ");

        char input[MAX_INPUT_LENGTH];
        getUserInput(input, MAX_INPUT_LENGTH);

        // Handle the player's choice
        if (strcmp(input, "1") == 0) {
            // Look for the artifact
            printf("You start searching the house for the artifact.\n");
            printf("       _\n");
            printf("     _( )_\n");
            printf("    (_ . _)\n");
            printf("      | | \n");
            printf("      | |\n");
            printf("^ the artifact");

            if (rand() % 2 == 0)
            {
                printf("youre getting warmer");
            }
            else
                printf("the woods descend upon you.  The Centaurs have you exactly where they wanted the whole time");


        if (strcmp(input, "2") == 0){
            //Talk to the people
            printf("They keep looking over at you, you should probably say something");

        if (rand() % 3 == 0)
            {
                    printf("Hi there Im totally your real estate agent and im not here to try and steal stuff from this house, you say to them with a smile");


        }

        endwin();
        return 0;
    }
