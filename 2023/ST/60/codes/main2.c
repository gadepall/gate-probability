#include <stdio.h>

int main() {
    // Open the DAT file for reading
    FILE *file = fopen("simulation_results.dat", "r");
    if (file == NULL) {
        printf("Error opening the file for reading.\n");
        return 1;
    }

    // Initialize variables to count occurrences of 1 and 3
    int count_1 = 0;
    int count_3 = 0;
    int total_samples = 100000; // Corrected the total number of samples

    // Read the values from the DAT file
    int value;
    while (fscanf(file, "%d", &value) == 1) {
        if (value == 1) {
            count_1++;
        } else if (value == 3) {
            count_3++;
        }
    }

    // Close the DAT file
    fclose(file);

    // Calculate the probabilities
    double probability_1 = (double)count_1/total_samples ;
    double probability_3 = (double)count_3 / total_samples;

   
    printf("probablity of ({1,4}) : %lf\n", probability_1 + probability_3);
    return 0;
}

