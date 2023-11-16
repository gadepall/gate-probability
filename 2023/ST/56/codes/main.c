#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate a random variable from a uniform distribution
double generate_uniform_random() {
    return (double)rand() / RAND_MAX;
}

// Function to calculate the Poisson PMF using CDF
int poisson_pmf(double u, double lambda) {
    int x = 0;
    double cdf = exp(-lambda); // CDF for x = 0

    while (u > cdf) {
        x++;
        cdf += exp(-lambda) * pow(lambda, x) / tgamma(x + 1); // Incrementally calculate CDF
    }

    return x;
}

int main() {
    srand(time(NULL));

    // Lambda values
    double lambda_values[] = {1, 2};

    for (int k = 0; k < 2; ++k) {
        double lambda = lambda_values[k];

        char label = (k == 0) ? 'x' : 'y';  // 'x' for lambda=1, 'y' for lambda=2

        char filename[20];
        sprintf(filename, "dat_%c.txt", label);

        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            fprintf(stderr, "Error opening file %s.\n", filename);
            return 1;
        }

        int num_simulations = 10000; // Number of simulations
        for (int i = 0; i < num_simulations; i++) {
            double u = generate_uniform_random();
            int poisson_value = poisson_pmf(u, lambda);
            double pmf_value = exp(-lambda) * pow(lambda, poisson_value) / tgamma(poisson_value + 1);

            fprintf(file, "%c: %d, PMF: %f\n", label, poisson_value, pmf_value);
        }

        fclose(file);

        printf("Data written to %s\n", filename);
    }

    return 0;
}

