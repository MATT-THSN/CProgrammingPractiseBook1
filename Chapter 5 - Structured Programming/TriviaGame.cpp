/* 
* App name: Trivia
* Desc: Displays topics and asks a question based on selected topic
* Date Modified: 26/07/2018
* Author: Matthew Thompson
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Questions(int Category);
void EndingDisplay(void);
void PointAllocator(void);

int iCorrectAnswers = 0;
int iIncorrectAnswers = 0;

int main(void) {
    int iSelection = 0;

    while (true) {
        system("clear");
        printf("\n\tTRIVIA GAME\n");
        printf("\n\tCategories:");
        printf("\n\tAnimal Trivia: Enter \'1\'");
        printf("\n\tVehicle Trivia: Enter \'2\'");
        printf("\n\tHistory Trivia: Enter \'3\'");
        printf("\n\tMovie Trivia: Enter \'4\'");
        printf("\n\tQUIT: Enter \'5\'\n\n");
        printf("\tSelection: ");
        scanf("%d", &iSelection);
        system("clear");
        
        if(iSelection < 5) {
            Questions(iSelection);
        }
        else {
            EndingDisplay();
            return 0;
        }
    }
}

void PointAllocator(int selection) {
    if(selection == 1) {
        iCorrectAnswers++;
    }
    else {
        iIncorrectAnswers++;
    }
}

void Questions(int Category) {
    int iSelection = 1;

    switch(Category) {
        default:
            printf("Error: Not a valid option");
        break;
        case 1:
            do {
                if(!(iSelection >= 1 && iSelection <= 4)) { 
                    printf("\nYou need to select a valid option\n"); 
                }
                printf("\n\tAnimal Trivia Question.");
                printf("\n\n\tWhat spiny venous fish, common in home aquariums, has become an invasive species in the Caribbean Sea and U.S. Atlantic coastal waters?\n");
                printf("\t1. Lion Fish\n");
                printf("\t2. Cat Fish\n");
                printf("\t3. Gold Fish\n");
                printf("\t4. Clown Fish\n");
                printf("\n\tSelection: ");
                scanf("%d", &iSelection);
                system("clear");
            } while(!(iSelection >= 1 && iSelection <= 4));
            PointAllocator(iSelection);
        break;
        case 2:
            do {
                if(!(iSelection >= 1 && iSelection <= 4)) { 
                    printf("\nYou need to select a valid option\n"); 
                }
                printf("\n\tVehicle Trivia Question.");
                printf("\n\n\tThe vehicle manufacturer Volvo was founded in what country?\n");
                printf("\t1. Sweden\n");
                printf("\t2. Austria\n");
                printf("\t3. Saudi Arabia\n");
                printf("\t4. Switzerland\n");
                printf("\n\tSelection: ");
                scanf("%d", &iSelection);
                system("clear");
            } while(!(iSelection >= 1 && iSelection <= 4));
            PointAllocator(iSelection);
        break;
        case 3:
            do {
                if(!(iSelection >= 1 && iSelection <= 4)) { 
                    printf("\nYou need to select a valid option\n"); 
                }
                printf("\n\tHistory Trivia Question.");
                printf("\n\n\tOn the Apollo 11 moon mission, which astronaut stayed aloft in the command module while Neil Armstrong and Buzz Aldrin walked on the moon?\n");
                printf("\t1. Michael Collins\n");
                printf("\t2. Buzz Aldrin\n");
                printf("\t3. James McDuff\n");
                printf("\t4. Niel Armstrong\n");
                printf("\n\tSelection: ");
                scanf("%d", &iSelection);
                system("clear");
            } while(!(iSelection >= 1 && iSelection <= 4));
            PointAllocator(iSelection); 
        break;
        case 4:
            do {
                if(!(iSelection >= 1 && iSelection <= 4)) { 
                    printf("\nYou need to select a valid option\n"); 
                }
                printf("\n\tMovie Trivia Question.");
                printf("\n\n\tWhat car did the character James Bond drive, in the film, Casino Royale?\n");
                printf("\t1. Aston Martin DBS\n");
                printf("\t2. Aston Martin DB9\n");
                printf("\t3. Aston Martin DB11\n");
                printf("\t4. Aston Martin DB5\n");
                printf("\n\tSelection: ");
                scanf("%d", &iSelection);
                system("clear");
            } while(!(iSelection >= 1 && iSelection <= 4));
            PointAllocator(iSelection);
        break;
    } 
}

void EndingDisplay() {
    system("clear");
    printf("\n\tThanks for playing my game!");
    printf("\n\n\tYou had %d correct answers and %d wrong answers.\n", iCorrectAnswers, iIncorrectAnswers);
}