#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define TRIALS 100
#define SIZE 1000

double uniform_random() {
    return (double)rand() / RAND_MAX;
}

int binomial_random(double p, int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (uniform_random() < p) {
            count++;
        }
    }
    return count;
}

int main() {
    srand(time(NULL));

    // Given mean
    double mean;
    printf("Enter mean value: ");
    scanf("%lf", &mean);

    // Number of trials for binomial distribution
    int trials = TRIALS;

    // Generate a range of probabilities (p)
    double probabilities[100];
    for (int i = 0; i < 100; ++i) {
        probabilities[i] = 0.01 + i * 0.0098; // Adjust the step size accordingly
    }

    // Calculate variances for each probability using binomial random variable
    double variances[100];

    for (int i = 0; i < 100; ++i) {
        // Generate binomial random variable
        double p = probabilities[i];
        int binomial_rv[SIZE];
        for (int j = 0; j < SIZE; ++j) {
            binomial_rv[j] = binomial_random(p, mean / p);
        }

        // Calculate variance
        double sum = 0;
        for (int j = 0; j < SIZE; ++j) {
            sum += binomial_rv[j];
        }
        double mean_binomial = sum / SIZE;
        double variance = 0;
        for (int j = 0; j < SIZE; ++j) {
            variance += pow(binomial_rv[j] - mean_binomial, 2);
        }
        variance /= SIZE;

        // Append to the list
        variances[i] = variance;
    }
    double max_variance = variances[0];
    double min_variance = variances[0];

    for (int i = 1; i < 100; i++) {
        if (variances[i] < min_variance) {
            min_variance = variances[i];
        }
        if (variances[i] > max_variance) {
            max_variance = variances[i];
        }
    }


    // Get input variance from the user
    double user_input;
    printf("Enter a variance value to check: ");
    scanf("%lf", &user_input);

    // Check if the input variance is within the range
    if (min_variance <= user_input && user_input < max_variance) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }

  

    return 0;
}
