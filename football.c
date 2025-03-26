#include "football.h"
#include "stdio.h"
#include "stdlib.h" 

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

void printCombination(ScoreCombination combo) {
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", combo.conversionTds,
            combo.extraPointTds, combo.touchdowns, combo.fieldGoals, combo.safeties);
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

// Pointer to array of scoreCombinationSets to stash previous results for efficiency
ScoreCombinationSet *setStash;
// Number of combinationSets in the stash;
int stashCount = 0;

ScoreCombinationSet getCombinations(int score) {
    // Check if the set is in the stash
    for(int i = 0; i < stashCount; i++) {
        if(setStash[i].score == score) {
            return setStash[i];
        }
    }

    ScoreCombinationSet result;
    result.combinations = malloc(result.count * sizeof(ScoreCombination));
    result.score = score;
    result.count = 0;
    ScoreCombination base = createScoreCombination(0, 0, 0, 0, 0);

    findCombinations(score, base, &result);

    // Add the result to the stash
    if(stashCount == 0) {
        setStash = malloc(sizeof(ScoreCombinationSet));
        setStash[0] = result;
        stashCount++;
    } else {
        setStash = realloc(setStash, (stashCount+1) * sizeof(ScoreCombinationSet));
        setStash[stashCount] = result;
        stashCount++;
    }

    return result;
}

int count_combinations(int points) {
    return getCombinations(points).count;
}

void print_combinations(int points) {
    ScoreCombinationSet set = getCombinations(points);

    for(int i = 0; i < set.count; i++) {
        printCombination(set.combinations[i]);
    }
}


