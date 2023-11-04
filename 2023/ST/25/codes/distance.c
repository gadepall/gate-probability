#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_VECTORS 1000

// Function to calculate the Mahalanobis distance
double mahalanobis_distance(double x, double y, double mu_x, double mu_y, double sigma_xx, double sigma_xy, double sigma_yy) {
    double diff_x = x - mu_x;
    double diff_y = y - mu_y;
    double det_sigma = sigma_xx * sigma_yy - sigma_xy * sigma_xy;
    double inv_sigma_xx = sigma_yy / det_sigma;
    double inv_sigma_yy = sigma_xx / det_sigma;
    
      return diff_x * (inv_sigma_xx * diff_x + sigma_xy * diff_x) + diff_y * (sigma_xy * diff_x + inv_sigma_yy * diff_y);
}

int main() {
    int i;
    double vectors[NUM_VECTORS][2];
    double mu_x = 0.0; // Mean of x
    double mu_y = 0.0; // Mean of y
    double sigma_xx = 1.0; // Variance of x
    double sigma_yy = 1.0; // Variance of y
    double sigma_xy = 0.0; // Covariance between x and y
    double c = 1.0; // Constant 'c'

    // Arrays to store the distances
    double distances[NUM_VECTORS];

    // Open the data file for reading
    FILE *file = fopen("random_vectors.dat", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the vectors from the data file and calculate distances
    for (i = 0; i < NUM_VECTORS; i++) {
        if (fscanf(file, "%lf %lf", &vectors[i][0], &vectors[i][1]) != 2) {
            perror("Error reading file");
            return 1;
        }

        // Calculate Mahalanobis distance using the calculated mean and covariance
        double distance = mahalanobis_distance(vectors[i][0], vectors[i][1], mu_x, mu_y, sigma_xx, sigma_xy, sigma_yy);
        distances[i] = c * distance;
    }

    // Close the data file
    fclose(file);

    // Open a new data file for writing the distances
    FILE *distances_file = fopen("mahalanobis_distances.dat", "w");
    if (distances_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Write the Mahalanobis distances to the data file
    for (i = 0; i < NUM_VECTORS; i++) {
        fprintf(distances_file, "%lf\n", distances[i]);
    }

    // Close the distances data file
    fclose(distances_file);

    printf("Mahalanobis distances have been written to 'mahalanobis_distances.dat'\n");

    return 0;
}

