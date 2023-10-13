#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Set a fixed seed for reproducibility
    srand(50);

    // Generate a random value for lambda
    double true_lambda = 1.0 + (5.0 * rand() / RAND_MAX);

    // No. of samples
    int n = 10000;

    // Generate random values of X based on the exponential distribution
    double *X = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        double u = (double)rand() / RAND_MAX; // Random number between 0 and 1
        X[i] = -log(1.0 - u) * true_lambda; // Exponential distribution random variable
    }

    // Compute Y using X
    double *Y = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        Y[i] = X[i] * X[i];
    }

    // Compute the sample mean of Y (Y̅)
    double sample_mean_Y = 0.0;
    for (int i = 0; i < n; i++) {
        sample_mean_Y += Y[i];
    }
    sample_mean_Y /= n;

    // Estimate lambda using (Y̅)
    double estimated_lambda = sqrt(sample_mean_Y / 2.0);

    printf("True Lambda: %.6f\n", true_lambda);
    printf("Estimated Lambda: %.6f\n", estimated_lambda);

}

