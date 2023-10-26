#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Define the given probabilities
    double p1 = 1.0 / 4.0;  // P(X(1) = 1)
    double p2 = 1.0 / 4.0;  // P(X(2) = 2)
    double p3 = 1.0 / 4.0;  // P(X(3) = 2)
    double p4 = 1.0 / 4.0;  // P(X(4) = 3)

    // Simulate X by generating random numbers and comparing with probabilities
    int samples = 100000;  // Number of samples for the simulation
    int X_values[100000];   // Array to store the simulated values

    for (int i = 0; i < samples; i++) {
        double random = (double)rand() / RAND_MAX;  // Generate a random number in [0, 1)
        if (random < p1) {
            X_values[i] = 1;
        } else if (random < p1 + p2) {
            X_values[i] = 2;
        } else if (random < p1 + p2 + p3) {
            X_values[i] = 2;
        } else {
            X_values[i] = 3;
        }
    }

    // Open a DAT file for writing
    FILE *file = fopen("simulation_results.dat", "w");
    if (file == NULL) {
        printf("Error opening the file for writing.\n");
        return 1;
    }

    // Write the simulated values to the DAT file
   // fprintf(file, "Simulated values of X:\n");
    for (int i = 0; i < samples; i++) {
        fprintf(file, "%d\n", X_values[i]);
    }
    
    // Close the DAT file
    fclose(file);

    printf("Simulation results saved to 'simulation_results.dat'.\n");

    return 0;
}

