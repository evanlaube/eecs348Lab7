#include "football.h"
#include <cstdlib>

ScoreCombination createScoreCombination(int fieldGoals, int touchdowns, int conversionTds, int extraPointTds, int safeties) {
    ScoreCombination combo;
    combo.fieldGoals = fieldGoals;
    combo.touchdowns = touchdowns;
    combo.conversionTds = conversionTds;
    combo.extraPointTds = extraPointTds;
    combo.safeties = safeties;

    return combo;
}

// Check if two combinations are the same
int checkCombinationEquality(ScoreCombination a, ScoreCombination b) {
    if(a.safeties != b.safeties) 
        return 0;
    if(a.fieldGoals != b.fieldGoals) 
        return 0;
    if(a.touchdowns != b.touchdowns) 
        return 0;
    if(a.conversionTds != b.conversionTds) 
        return 0;
    if(a.extraPointTds != b.extraPointTds) 
        return 0;

    // Return true if all members match
    return 1;
}

ScoreCombinationSet getCombinations(int score) {
    ScoreCombinationSet result;
    result.combinations = malloc(result.count * sizeof(ScoreCombination));
    result.score = score;
    ScoreCombination base = createScoreCombination(0, 0, 0, 0, 0);

    return result;
}

void findCombinations(int remainingScore, ScoreCombination current, ScoreCombinationSet* result) {
    if(remainingScore == 0) {
        // Check all already saved combinations to make sure found combo is not duplicate
        for(int i = 0; i < result->count; i++) {
            // If the combo is a duplicate, return and do not add it again
            if(checkCombinationEquality(current, result->combinations[i])) {
                return;
            }
        }

        // Reallocate the combinations array in the struct to make space for an additional
        result->combinations = realloc(result->combinations, (result->count+1) * sizeof(ScoreCombination));
        // Set the element at the end of the array to the current combo
        result->combinations[result->count] = current;
        // Increment the count of the set
        result->count++;
    }

    if(remainingScore >= 2) {
        ScoreCombination new = current;
        new.safeties++;
        findCombinations(remainingScore-2, new, result);
    }

    if(remainingScore >= 3) {
        ScoreCombination new = current;
        new.fieldGoals++;
        findCombinations(remainingScore-3, new, result);
    }

    if(remainingScore >= 6) {
        ScoreCombination new = current;
        new.touchdowns++;
        findCombinations(remainingScore-6, new, result);
    }

    if(remainingScore >= 7) {
        ScoreCombination new = current;
        new.extraPointTds++;
        findCombinations(remainingScore-7, new, result);
    }

    if(remainingScore >= 8) {
        ScoreCombination new = current;
        new.conversionTds++;
        findCombinations(remainingScore-8, new, result);
    }
}

int count_combinations(int points) {
    return 0;
}

void print_combinations(int points) {

}


