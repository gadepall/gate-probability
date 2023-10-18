#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function for generating a binomial random variable
int generate_binomial(int n, float p) {
    int successes = 0;
    for (int i = 0; i < n; i++) {
        if ((float)rand() / RAND_MAX < p) {
            successes++;
        }
    }
    return successes;
}

int main() {
    FILE *fp;
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Setting seed for reproducibility
    srand(0);

    // Probability of obtaining a red flower (success) in a single offspring
    float p_success = 1.0 / 2.0;

    // Using the CDF formula for the binomial distribution
int n_trials = 2;
int k_values[3] = {0, 1, 2};
float Theo_cdf_values[3] = {0.0, 0.0, 0.0};

for (int i = 0; i < 3; i++) {
    float prob = 0.0;
    if (i == 2) { // Special case for the last element
        prob =  p_success * p_success;
    } else {
        for (int k = 0; k <= k_values[i]; k++) {
            float temp = 1.0;
            for (int j = 0; j < k; j++) {
                temp *= p_success;
            }
            for (int j = 0; j < n_trials - k; j++) {
                temp *= (1 - p_success);
            }
            prob += temp;
        }
    }
    Theo_cdf_values[i] = prob;
}



    // Simulating the results
    int num_simulations = 10000; // Number of simulations
    int simulated_values[10000];
    float x,y,z;
    float sim_cdf_values[3] = {0.0, 0.0, 0.0};
    for (int i = 0; i < num_simulations; i++) {
        simulated_values[i] = generate_binomial(n_trials, p_success);
        if (simulated_values[i] == 0){
        	x++;
        }
        if (simulated_values[i] == 1){
        	y++;
        }
        if (simulated_values[i] == 2){
        	z++;
        }
    }
    sim_cdf_values[0] = x/10000;
    sim_cdf_values[1] = y/10000;
    sim_cdf_values[2] = z/10000;
    printf("%f",Theo_cdf_values[2]);
    

    // Writing simulated CDF values to the text file
    fprintf(fp, "%f %f %f\n", Theo_cdf_values[0], Theo_cdf_values[1], Theo_cdf_values[2]);
    fprintf(fp, "%f %f %f\n", sim_cdf_values[0], sim_cdf_values[1], sim_cdf_values[2]);
    
    fclose(fp);
    return 0;
}

