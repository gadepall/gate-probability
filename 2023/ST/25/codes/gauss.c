#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_VECTORS 1000

// Function to generate a random number between 0 and 1
double rand01() {
    return (double)rand() / (double)RAND_MAX;
}

// Function to generate a random number from a standard normal distribution
double rand_normal() {
    double u1 = rand01();
    double u2 = rand01();
    return sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
}

int main() {
    int i;
    double vectors[NUM_VECTORS][2];
    FILE *file;

    // Seed the random number generator
    //srand(time(NULL);

    // Generate random vectors with Gaussian distribution
    for (i = 0; i < NUM_VECTORS; i++) {
        vectors[i][0] = rand_normal();
        vectors[i][1] = rand_normal();
    }

    // Open a data file for writing
    file = fopen("random_vectors.dat", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the generated vectors to the data file
    for (i = 0; i < NUM_VECTORS; i++) {
        fprintf(file, "%lf %lf\n", vectors[i][0], vectors[i][1]);
    }

    // Close the data file
    fclose(file);

    printf("Data has been written to 'random_vectors.dat'\n");

    return 0;
}

