#include "football.h"
#include <stdio.h>

int main() {
    printf("Enter '0' or '1' to stop.\n");
    int score = 0;
    do {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if(score < 0) {
            printf("Score must be a positive number!\n");
            continue;
        } else if(score != 1 && score != 0) {
            ScoreCombinationSet combo = getCombinations(score); 
            printf("Number of possible combinations for score of %d: %d\n", score, combo.count);
            printf("Possible combinations: \n");
            print_combinations(score);
        }

    } while (score != 1 && score != 0);

    printf("Exiting...\n");
    return 0;
}
