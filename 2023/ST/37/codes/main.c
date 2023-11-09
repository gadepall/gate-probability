#include <stdio.h>
#include <math.h>
#include <stdlib.h> // for rand() and srand()
#include <time.h>   // for seeding the random number generator

// Define the PDF function for X
double pdf_X(double x) {
    if (x >= 1.0 && x <= 5.0) {
        return 1.0 / (x * x);
    } else {
        return 0.0;
    }
}

// Define the CDF function for Y
double cdf_Y(double y) {
    return 1.0 - 1.0 / exp(y); // CDF of Y based on the given transformation
}

// Define a comparison function for sorting doubles in ascending order
int compare_doubles(const void *a, const void *b) {
    double x = *(double *)a;
    double y = *(double *)b;
    if (x < y) {
        return -1;
    } else if (x > y) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    FILE *xFile = fopen("x_data.txt", "w");
    FILE *yFile = fopen("y_data.txt", "w");

    if (!xFile || !yFile) {
        printf("Error: Could not open data file for writing.\n");
        return 1;
    }

    double x, y, pdf, cdf;
    double x_values[41], y_values[41];

    // Generate random values of X from a distribution with PDF f(x) = 1 / (x^2) for x in [1, 5]
    // Then compute Y = log_e(X) and calculate the CDF of Y
    for (int i = 0; i < 41; i++) {
        double u = (double)rand() / RAND_MAX; // Generate a random number from a uniform distribution [0, 1]
        double generated_X = 1.0 / (1 - u); // Generate a random variable from the given distribution
        double generated_Y = log(generated_X); // Compute Y = log_e(X)
        pdf = pdf_X(generated_X); // PDF of X
        cdf = cdf_Y(generated_Y); // CDF of Y

        // Store the values of X and Y in arrays
        x_values[i] = generated_X;
        y_values[i] = generated_Y;
    }

    // Sort the values of X and Y in ascending order
    qsort(x_values, 41, sizeof(double), compare_doubles);
    qsort(y_values, 41, sizeof(double), compare_doubles);

    // Write the sorted values of X and the PDF of X to the X data file
    for (int i = 0; i < 41; i++) {
        fprintf(xFile, "%lf %lf\n", x_values[i], pdf_X(x_values[i]));
    }

    // Write the sorted values of Y and the CDF of Y to the Y data file
    for (int i = 0; i < 41; i++) {
        fprintf(yFile, "%lf %lf\n", y_values[i], cdf_Y(y_values[i]));
    }

    fclose(xFile);
    fclose(yFile);

    return 0;
}