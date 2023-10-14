#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double generate_standard_normal() {
    double temp = 0;
    for (int j = 0; j < 12; j++) {
        temp += (double)rand() / RAND_MAX;
    }
    temp -= 6;
    return temp;
}

double chi_square_random(int df) {
    double sum = 0.0;
    for (int i = 0; i < df; i++) {
        double normal = generate_standard_normal();
        sum += normal * normal;
    }
    return sum;
}

double exponential_from_chi_square(int df) {
    double chi_square = chi_square_random(df);
    return chi_square / 2.0; // Convert to Exponential(1)
}

int main() {
    int n = 10000;
    double exponential_values[n];

    for (int i = 0; i < n; i++) {
        exponential_values[i] = exponential_from_chi_square(2); // Convert Chi-Square with 2 degrees of freedom to Exponential(1)
    }

    // Open a file for writing
    FILE *file = fopen("exp_gau.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the values to the file
    for (int i = 0; i < n; i++) {
        fprintf(file, "%lf\n", exponential_values[i]);
    }

    // Close the file
    fclose(file);

    return 0;
}

