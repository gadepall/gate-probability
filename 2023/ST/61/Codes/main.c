#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate random variables with the specified probability density function
void generate_random_variables(double *array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = -log((double)rand() / RAND_MAX);
    }
}

int main() {
    // Simulation parameters
    int num_simulations = 1000;
    int sample_size = 1000;

    // Initialize an array to store the values of sqrt(n) * (e^(-Y_n_bar) - e^(-1))
    double *results = malloc(num_simulations * sizeof(double));

    // Perform simulations
    for (int sim = 0; sim < num_simulations; ++sim) {
        // Generate random variables
        double *X = malloc(2 * sample_size * sizeof(double));
        generate_random_variables(X, 2 * sample_size);

        // Compute Y_n for each n
        double *Y = malloc(sample_size * sizeof(double));
        for (int i = 0; i < sample_size; ++i) {
            Y[i] = fabs(X[2 * i + 1] - X[2 * i]);
        }

        // Compute Y_n_bar
        double Y_bar = 0;
        for (int i = 0; i < sample_size; ++i) {
            Y_bar += Y[i];
        }
        Y_bar /= sample_size;

        // Compute sqrt(n) * (e^(-Y_n_bar) - e^(-1))
        results[sim] = sqrt(sample_size) * (exp(-Y_bar) - exp(-1));

        free(X);
        free(Y);
    }

    // Calculate the sample variance of the results
    double mean = 0;
    for (int i = 0; i < num_simulations; ++i) {
        mean += results[i];
    }
    mean /= num_simulations;

    double sample_variance = 0;
    for (int i = 0; i < num_simulations; ++i) {
        sample_variance += pow(results[i] - mean, 2);
    }
    sample_variance /= (num_simulations - 1);

    // Print the result rounded to two decimal places
    printf("Estimated variance: %.2f\n", sample_variance);

    // Perform your normality test here (not implemented in this example)

    // Free allocated memory
    free(results);

    return 0;
}

