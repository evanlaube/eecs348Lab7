#include "football.h"
#include <stdio.h>

int main() {
    // Prompt user for ability to exit
    printf("Enter '0' or '1' to stop.\n");
    // Start a score integer at zero
    int score = 0;
    do {
        // Promp the user to enter a score to check
        printf("Enter the NFL score: ");
        // Take an integer as input and store it in 'score'
        scanf("%d", &score);

        // If the score is negative
        if(score < 0) { 
            // Display a warning to the user
            printf("Score must be a positive number!\n");
            // Repeat the loop for a different input
            continue;
        } else if(score != 1 && score != 0) { // If the score is not 1 or 0
            // Get a combination set of all the possible score combinations for the given score
            ScoreCombinationSet combo = getCombinations(score); 
            // Print the number of possible score combos for the given score
            printf("Number of possible combinations for score of %d: %d\n", score, combo.count);
            // Print each combination line by line
            printf("Possible combinations: \n");
            print_combinations(score);
        }
    } while (score != 1 && score != 0);

    // Exit cleanly if the input is 1 or 0
    printf("Exiting...\n");
    return 0;
}
