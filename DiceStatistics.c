#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PULLS 300

// Function to introduce a delay (in milliseconds)
void delay(int milliSeconds) {
    int startTime = clock();
    while (clock() < (startTime + milliSeconds));
}

int main() {
    srand(time(0)); // Generates a statistically random seed based on the current time
    
    int pull;
    int total = 0;
    int numbers[] = {0, 0, 0, 0, 0, 0};

    while (total < MAX_PULLS) {

        pull = (rand() % 6) + 1;
        total++;

        printf("-------------------\nRoll number %d:\n", total); // Improved output message
        
        switch (pull) { // Checks the roll and increments the corresponding array value
            case 1: numbers[0]++; break;
            case 2: numbers[1]++; break;
            case 3: numbers[2]++; break;
            case 4: numbers[3]++; break;
            case 5: numbers[4]++; break;
            case 6: numbers[5]++; break;
        }

        for (int i = 1; i <= 6; i++) { // Printing the current percentage values
            printf("%d: %.2lf %%\n", i, ((double)numbers[i - 1] / total) * 100);
        }

        delay(100); // Time delay in milliseconds if desired
    }

    return 0;
}