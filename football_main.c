#include "football.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Enter '0' or '1' to stop.\n");
    int score = 0;
    do {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        printf("Score: %d", score);

    } while (score != 1 && score != 0);

    printf("Exiting...\n");
    return 0;
}
