#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    long int n = 1000; // Sample size
    long int num_simulations = 10000; // Number of simulations
    double theta = 2; // Value of theta
    double estimations[num_simulations];

    srand(time(0));

    for (int i = 0; i < num_simulations; i++) 
       {
        double samples[n];
        for (int j = 0; j < n; j++) 
        {
            samples[j] = ((double)rand() / RAND_MAX) * (theta - 1/3) + 1/3;
        }
        
        // Calculate the maximum value (Y)
        double Y = samples[0];
        for (int j = 1; j < n; j++) 
        {
            if (samples[j] > Y) 
            {
                Y = samples[j];
            }
        }

        // Calculate the estimator
        double estimator = ((n + 1) / n) * (Y - 1/3) + 1/3;
        estimations[i] = estimator;
    }

    // Save estimations to a file
    FILE *file = fopen("estimations.txt", "w");
    if (file != NULL) 
    {
        for (int i = 0; i < num_simulations; i++) 
        {
            fprintf(file, "%lf\n", estimations[i]);
        }
        fclose(file);
    }

    return 0;
}

