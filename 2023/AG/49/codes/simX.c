#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Calculate the cumulative distribution function (CDF)
double cdf(double x) {
    if (x < 0) {
        return 0;
    } else {
        return 1 - 2*exp(-x) + (exp(-2*x));
    }
}

// Calculate the inverse CDF (quantile function)
double inverse_cdf(double u) {
    if (u < 0) {
        return 0;
    } else {
        return -log(1 - sqrt(u));
    }
}
int main() {
    int num_samples = 10000;  // Number of random variables to generate
    double random_vars[num_samples];  // Array to store random variables
    double cdf_values[num_samples];   // Array to store generated CDF values
    double theoretical_cdf_values[num_samples];  // Array to store theoretical CDF values
     srand(time(NULL));  // Seed the random number generator
     for (int i = 0; i < num_samples; i++) {
        double u = (double)rand() / RAND_MAX;  // Generate a random number between 0 and 1
        double random_var = inverse_cdf(u);
        random_vars[i] = random_var;  // Store the random variable in the array
        cdf_values[i] = cdf(random_var);  // Calculate and store the CDF value
        theoretical_cdf_values[i] = cdf(random_var); // Calculate and store the theoretical CDF 
    }

    // Compare generated CDF values with theoretical CDF at multiple points
    for (int i = 0; i < num_samples; i++) {
        printf("Random Variable %d: %f (Generated CDF = %f, Theoretical CDF = %f)\n", i + 1, random_vars[i], cdf_values[i], theoretical_cdf_values[i]);
    }

    // Save random_vars to a .dat file
    FILE *random_vars_file = fopen("random_vars3.dat", "w");
    if (random_vars_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < num_samples; i++) {
        fprintf(random_vars_file, "%f\n", random_vars[i]);
    }

    fclose(random_vars_file);

    // Save cdf_values to a .dat file
    FILE *cdf_file = fopen("cdf_values3.dat", "w");
    if (cdf_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < num_samples; i++) {
        fprintf(cdf_file, "%f\n", cdf_values[i]);
    }

    fclose(cdf_file);

    // Save theoretical_cdf_values to a .dat file
    FILE *theoretical_cdf_file = fopen("theoretical_cdf_values3.dat", "w");
    if (theoretical_cdf_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < num_samples; i++) {
        fprintf(theoretical_cdf_file, "%f\n", theoretical_cdf_values[i]);
    }

    fclose(theoretical_cdf_file);

    return 0;
}

