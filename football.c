#include "football.h"
#include "stdio.h"
#include "stdlib.h" 

ScoreCombination createScoreCombination(int fieldGoals, int touchdowns, int conversionTds, int extraPointTds, int safeties) {
    // Create an uninitialized combo
    ScoreCombination combo;
    // Set the field goals to passed
    combo.fieldGoals = fieldGoals;
    // Set the tds to passed
    combo.touchdowns = touchdowns;
    // Set the conversion tds to passed
    combo.conversionTds = conversionTds;
    // Set the extra point tds to passed
    combo.extraPointTds = extraPointTds;
    // Set tehe safeties to passed
    combo.safeties = safeties;

    // Return the initialized combination
    return combo;
}

// Check if two combinations are the same
int checkCombinationEquality(ScoreCombination a, ScoreCombination b) {
    // If the number of safeties are not equal, return false
    if(a.safeties != b.safeties)
        return 0;
    // If the number of field goals are not equal, return false
    if(a.fieldGoals != b.fieldGoals) 
        return 0;
    // If the number of touchdown are not equal, return false
    if(a.touchdowns != b.touchdowns) 
        return 0;
    // If the number of conversion tds are not equal, return false
    if(a.conversionTds != b.conversionTds) 
        return 0;
    // If the number of extra point tds are not equal, return false
    if(a.extraPointTds != b.extraPointTds) 
        return 0;

    // Return true if all members match
    return 1;
}

// Print a combination in a clean formatter matter
void printCombination(ScoreCombination combo) {
    // Format and print combination
    printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", combo.conversionTds,
            combo.extraPointTds, combo.touchdowns, combo.fieldGoals, combo.safeties);
}

// Adds a score combination to a set if it is not a duplicate
void addCombinationToResult(ScoreCombination combo, ScoreCombinationSet* result) {
        // Check all already saved combinations to make sure found combo is not duplicate
        for(int i = 0; i < result->count; i++) {
            // If the combo is a duplicate, return and do not add it again
            if(checkCombinationEquality(combo, result->combinations[i])) {
                return;
            }
        }

        // Reallocate the combinations array in the struct to make space for an additional
        result->combinations = realloc(result->combinations, (result->count+1) * sizeof(ScoreCombination));
        // Set the element at the end of the array to the current combo
        result->combinations[result->count] = combo;
        // Increment the count of the set
        result->count++;
}

// Combine two combinations by adding each of their score types together
ScoreCombination combineCombinations(ScoreCombination base, ScoreCombination offset) {
    // Create an uninitialized combo to store the result
    ScoreCombination combined;
    // Sum field goals
    combined.fieldGoals = base.fieldGoals + offset.fieldGoals;
    // Sum touchdowns
    combined.touchdowns = base.touchdowns + offset.touchdowns;
    // Sum conversion touchdowns
    combined.conversionTds = base.conversionTds + offset.conversionTds;
    // Sum extra point touchdowns
    combined.extraPointTds = base.extraPointTds + offset.extraPointTds;
    // Sum safeties
    combined.safeties = base.safeties + offset.safeties;

    // Return the initialized result
    return combined;
}

// Pointer to array of scoreCombinationSets to stash previous results for efficiency
ScoreCombinationSet *setStash;
// Number of combinationSets in the stash;
int stashCount = 0;

// Recursive backing call for getCombinations
void findCombinations(int remainingScore, ScoreCombination current, ScoreCombinationSet* result) {
    // If the remaining score is zero, the combination is good
    if(remainingScore == 0) {
        // Add it to the passed result
        addCombinationToResult(current, result);
        // Exit recursive branch 
        return;
    }

    // Check stash to see if combo set with remainingScore is already calculated
    for(int i = 0; i < stashCount; i++) {
        // If the remaining score is in the stash
        if(setStash[i].score == remainingScore) {
            // For each combination in the stashed set
            for (int j = 0; j < setStash[i].count; j++) {
                // Add the combination to the current combination
                ScoreCombination newComb = combineCombinations(current, setStash[i].combinations[j]);
                // Add this combination to the final result
                addCombinationToResult(newComb, result);
            }
            return;
        }
    }
    
    // If the remaining score is not in the stash, generate it: 

    // Create a temp scorecombination set
    ScoreCombinationSet temp;
    // Set the score to the remaining score
    temp.score = remainingScore;
    // Start count at zero
    temp.count = 0;
    // Set the combinations array to NULL
    temp.combinations = NULL;
    // Create a base, zero score combination
    ScoreCombination base = createScoreCombination(0, 0, 0, 0, 0);

    if(remainingScore >= 2) {
        // Create a copy of base
        ScoreCombination new = base;
        // Increment the safeties of new combo 
        new.safeties++;
        // Find the combinations of the new remaing score
        findCombinations(remainingScore-2, new, &temp);
    }

    if(remainingScore >= 3) {
        // Create a copy of base
        ScoreCombination new = base;
        // Increment fieldgoals
        new.fieldGoals++;
        // Find the combinations of the new remaing score
        findCombinations(remainingScore-3, new, &temp);
    }

    if(remainingScore >= 6) {
        // Create a copy of base
        ScoreCombination new = base;
        // Increment touchdowns
        new.touchdowns++;
        // Find the combinations of the new remaing score
        findCombinations(remainingScore-6, new, &temp);
    }

    if(remainingScore >= 7) {
        // Create a copy of base
        ScoreCombination new = base;
        // Increment extra point tds
        new.extraPointTds++;
        // Find the combinations of the new remaing score
        findCombinations(remainingScore-7, new, &temp);
    }

    if(remainingScore >= 8) {
        // Create a copy of base
        ScoreCombination new = base;
        // Increment conversion tds
        new.conversionTds++;
        // Find the combinations of the new remaing score
        findCombinations(remainingScore-8, new, &temp);
    }

    // Add the result to the stash

    // If the stash is empty
    if(stashCount == 0) {
        // Allocate it with size for only one scorecombination set
        setStash = malloc(sizeof(ScoreCombinationSet));
        // Set the first entry to the temp combo
        setStash[0] = temp;
        // Incrememnt the stash count
        stashCount++;
    } else {
        // Reallocate the stash with space for one more set
        setStash = realloc(setStash, (stashCount+1) * sizeof(ScoreCombinationSet));
        // Set the back element to the temp combo
        setStash[stashCount] = temp;
        // Increment the stash count
        stashCount++;
    }

    // Combine computed temp result with current combo
    for(int i = 0; i < temp.count; i++) {
        // Create a new combo that is the sum of the current combo and temp combo
        ScoreCombination new = combineCombinations(current, temp.combinations[i]);
        // Add this combo to results
        addCombinationToResult(new, result);
    }
}

ScoreCombinationSet getCombinations(int score) {
    // Check if the set is in the stash
    for(int i = 0; i < stashCount; i++) {
        // If it is in the stash, return it
        if(setStash[i].score == score) {
            return setStash[i];
        }
    }

    // If not in the stash, generate it

    // Create an empty set
    ScoreCombinationSet result;
    // Set the score to the score to find 
    result.score = score;
    // Start the count at zero
    result.count = 0;
    // Start the combinations array as NULL
    result.combinations = NULL;
    // Create a base set to build off of
    ScoreCombination base = createScoreCombination(0, 0, 0, 0, 0);

    // Find the combinations for the given score and store in result
    findCombinations(score, base, &result);

    // Return pointer to result array
    return result;
}

int count_combinations(int points) {
    // Return the count of the combination set with the given score
    return getCombinations(points).count;
}

void print_combinations(int points) {
    // Get the set of combinations
    ScoreCombinationSet set = getCombinations(points);

    // For each combination
    for(int i = 0; i < set.count; i++) {
        // Print it as a formatted line
        printCombination(set.combinations[i]);
    }
}


