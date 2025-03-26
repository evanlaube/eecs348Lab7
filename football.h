#ifndef __LAB_H__
#define __LAB_H__

// Struct to easily store each score combination
typedef struct {
    // Number of field goals scored (3pts)
    int fieldGoals;
    // Number of touchdowns scored with no extra points (6pts)
    int touchdowns;
    // Number of 2pt conversion touchdowns (8pts)
    int conversionTds;
    // Number of extra point touchdowns (7pts)
    int extraPointTds;
    // Number of safeties scored (2pts)
    int safeties;
} ScoreCombination;

// Struct to easily store a set of score combinations
typedef struct {
    // Total score achieved
    int score;
    // Number of combinations
    int count;
    // Pointer to array of ScoreCombinations
    ScoreCombination* combinations;
} ScoreCombinationSet;

// Create a score combination struct with the passed details
ScoreCombination createScoreCombination(int fieldGoals, int touchdowns, 
        int conversionTds, int extraPointTds, int safeties);

// Create a set of score combinations for each possible combination of a given score
ScoreCombinationSet getCombinations(int score);

/* Do not modify the function signatures here */

/**
 * @brief Return the number of possible combinations to add up to `points`
 * 
 * @param points
 * @return int 
 */
int count_combinations(int points);

/**
 * @brief Print a formatted table of all possible combinations that add up to
 * `points`
 * 
 * @param points
 */
void print_combinations(int points);

#endif /* __LAB_H__ */
