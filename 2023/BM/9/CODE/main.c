#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TOTAL_INDIVIDUALS 1000
#define POSITIVE_INDIVIDUALS 100
#define GROUP_SIZE 5

// Custom power function for integer exponentiation
double customPow(double base, int exponent) {
    double result = 1.0;

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

// Function to simulate the testing strategy
void covidTestingStrategy(int individuals[], int total, int positive) {
    int testCount = 0;
    int groupTestTrueCount = 0;

    // Shuffle the individuals randomly
    for (int i = total - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        // Swap individuals[i] and individuals[j]
        int temp = individuals[i];
        individuals[i] = individuals[j];
        individuals[j] = temp;
    }

    // Perform testing in groups
    for (int i = 0; i < total; i += GROUP_SIZE) {
        int groupResult = 0;

        // Mix the samples within each set
        for (int j = i; j < i + GROUP_SIZE; ++j) {
            groupResult |= individuals[j];
        }

        // Test the mixed sample for covid
        if (groupResult == 0) {
            // Declare all 5 individuals to be covid negative
            testCount++;
        } else {
            // Test each individual separately if the mixed sample is positive
            for (int j = i; j < i + GROUP_SIZE; ++j) {
                if (individuals[j] == 1) {
                    // Individual is covid positive
                    testCount++;
                }
            }
            groupTestTrueCount++;
        }
    }

    // Probability of the group test being true
    double p = (double)positive / total;
    double groupTestTrueProbability = 1.0 - customPow(1.0 - p, GROUP_SIZE);

    // Expected number of tests for one set
    double expectedTestsOneSet = 1 + GROUP_SIZE * groupTestTrueProbability;

    // Total expected number of sets
    double totalExpectedSets = (double)total / GROUP_SIZE;

    // Total expected number of tests
    double totalExpectedTests = totalExpectedSets * expectedTestsOneSet;

    printf("Total tests required: %d\n", testCount);
    printf("Group test true count: %d\n", groupTestTrueCount);
    printf("Probability of group test being true: %.4f\n", groupTestTrueProbability);
    printf("Expected number of tests for one set: %.2f\n", expectedTestsOneSet);
    printf("Total expected number of sets: %.2f\n", totalExpectedSets);
    printf("Total expected number of tests: %.2f\n", totalExpectedTests);
}

int main() {
    srand(time(NULL));

    // Initialize the array representing individuals with 100 positives
    int individuals[TOTAL_INDIVIDUALS] = {0};
    for (int i = 0; i < POSITIVE_INDIVIDUALS; ++i) {
        individuals[i] = 1;
    }

    // Simulate the testing strategy
    covidTestingStrategy(individuals, TOTAL_INDIVIDUALS, POSITIVE_INDIVIDUALS);

    return 0;
}

