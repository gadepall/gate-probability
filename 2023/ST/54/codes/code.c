#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double calculate_probability(int k) {
    if (k == 0) {
        return 0.5 * (1 + exp(-1));
    } else {
        double denominator = 1.0;
        for (int i = 1; i <= k; i++) {
            denominator *= i;
        }
        return (exp(-1)) / (2 * denominator);
    }
}

int generate_random_variable() {
    double rand_num = (double)rand() / RAND_MAX; // Generate a random number between 0 and 1
    double cumulative_prob = 0.0;
    int k = 0;

    while (1) {
        cumulative_prob += calculate_probability(k);
        if (rand_num < cumulative_prob) {
            return k;
        }
        k++;
    }
}

int main() {
    int num_variables = 1000;
    int variables[num_variables];

    srand(time(NULL)); // Seed for random number generation

    FILE *file = fopen("rv.dat", "w"); // Open the file for writing

    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < num_variables; i++) {
        variables[i] = generate_random_variable();
        fprintf(file, "%d\n", variables[i]); // Save the random variable to the file
    }

    fclose(file); // Close the file

    double sum_X = 0.0;
    double sum_X_if_positive = 0.0;
    int count_positive = 0;

    for (int i = 0; i < num_variables; i++) {
        sum_X += variables[i];
        if (variables[i] > 0) {
            sum_X_if_positive += variables[i];
            count_positive++;
        }
    }

    double E_X = sum_X / num_variables;
    double E_X_if_positive = sum_X_if_positive / count_positive;

    printf("E(X) = %lf\n", E_X);
    printf("E(X|X>0) = %lf\n", E_X_if_positive);

    return 0;
}

