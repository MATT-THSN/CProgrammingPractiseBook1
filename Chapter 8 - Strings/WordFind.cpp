/* 
* Programming Practise File
* Desc: Strings Challenge 4
* Date Modified: 11/09/2018
* Author: Matthew Thompson
*/

/*
    - Modify the Word Find game to include one or more of the following suggestions:
        * Add a menu to the Word Find game that lets the player choose the difficulty, less time will make it harder.
        * Incorperate multiple words into the text areas.
        * Track the player's score. For example, add 1 point for each word guessed correctly, and sub 1 point for each
        word guessed incorrectly.
        * Use the strlen() function to ensure the user's input string is the same length as the hidden word.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

//Function Prototypes
void checkAnswer(char *, char [], int *);
void wait(int);

int main(void) {
    //Array of garbled letters with words inside
    char *strGame[5] = {
        "ADELANGUAGEFERVZ0PIBMOUSECURITYERT",
        "ZBPOINTERSKLML00KALIPMNOCOT",
        "PODSTRINGGDIWHIEEICERLSLINUX",
        "YVCPROGRAMMERWQKNULTFORENSICSHMD",
        "UKUNIXFIMWXIZEQZINPTYPEUTEX"
    };

    //Variables
    char answer[80] = {0};
    int displayed = 0;
    int x;
    int startTime = 0;
    int selector = 0;
    int difficulty = 20;
    int pScore = 0;
    system("clear");

    //Difficulty menu
    printf("\n\n\tWelcome to Word Find\n\n");
    printf("\t#1 For Easy");
    printf("\n\t#2 For Normal");
    printf("\n\t#3 For Hard");
    printf("\n\tChoose your difficulty: ");
    //Loop round until I valid option has been chosen
    do {
        scanf("%d", &selector);
        //Set difficulty based on selection
        if (selector == 1) {
            difficulty = 6;
            break;
        }
        if (selector == 2) {
            difficulty = 4;
            break;
        }
        if (selector == 3) {
            difficulty = 2;
            break;
        }
    }  while (selector == 0 ||!(selector > 3) || !(selector < 0));

    //Set start time to current time
    startTime = time(NULL);

    //Displays each string of garbled letters
    for(x = 0; x < 5; x++) {
        /* DISPLAY TEXT FOR FEW SECONDS */
        while(startTime + difficulty > time(NULL)) {
            if (displayed == 0) {
                system("clear");
                printf("\n\tFind a word in: \n\n");
                printf("\t%s\n\n", strGame[x]);
                displayed = 1;
            } //End If
        } // End while loop
    
    //User enters a word they think they saw
    system("clear");
    printf("\n\tEnter word found: ");
    scanf("%s", answer);

    /* Could remove redundant code by chucking bits into a function but will do that later so I can continue book */
    switch(x) {
        case 0:
            //Checking length of answer to ensure it's not a single character input
            if(strlen(answer) >= 8) {
                //If long enough then checks answer
                checkAnswer(strGame[x], answer, &pScore);
            }
            //If not the right length then remove points
            else { printf("\n\tSorry, word not found!\n"); pScore--; wait(3); }
        break;

        case 1:
            if(strlen(answer) >= 4) {
                checkAnswer(strGame[x], answer, &pScore);
            }
            else { printf("\n\tSorry, word not found!\n"); pScore--; wait(3); }
        break;

        case 2:
            if(strlen(answer) >= 5) {
                checkAnswer(strGame[x], answer, &pScore);
            }
            else { printf("\n\tSorry, word not found!\n"); pScore--; wait(3); }
        break;

        case 3:
            if(strlen(answer) >= 9) {
                checkAnswer(strGame[x], answer, &pScore);
            }
            else { printf("\n\tSorry, word not found!\n"); pScore--; wait(3); }
        break;

        case 4:
            if(strlen(answer) >= 4) {
                checkAnswer(strGame[x], answer, &pScore);
            } 
            else { printf("\n\tSorry, word not found!\n"); pScore--; wait(3); }
        break;
    }

    displayed = 0;
    startTime = time(NULL);
    //Searches challenge string for the inputted answer
    
    }// End for loop
    printf("\n\tYour final score is: %d", pScore);
    return 0;
} //End main

void wait(int x) {
    int initialTime = time(NULL);
    while(initialTime + x > time(NULL)) {
            //Holding for 'x' seconds
        }
}

void checkAnswer(char *string1, char string2[], int *score) {
    int x;
    /* Convert answer to UPPER CASE to perform a valid comparison */
    for (x = 0; x <= strlen(string2); x++) {
        string2[x] = toupper(string2[x]);
    }
    //Compares two strings and checks if answer isn't null
    if (strstr(string1, string2) != 0 && string2[0] != 0) {
        //If correct print message
        printf("\n\tGreat job!\n");
        wait(3);
        *score += 1;
    }
    else {
        //Otherwise show loose message
        printf("\n\tSorry, word not found!\n");
        wait(3);
        *score -= 1;
    }
} // End Check Answer
