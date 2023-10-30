#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int poissonRandomVariable(double lambda) {
    double L = exp(-lambda);
    double p = 1.0;
    int k = 0;

    do {
        k++;
        double u = (double)rand() / RAND_MAX;
        p *= u;
    } while (p > L);

    return k - 1;
}

int main() {
    int lambda = 5; // Adjust the lambda (mean) value as needed
    int numSamples = 10;

    // Initialize the random number generator
    srand(time(NULL));

    for (int i = 0; i < numSamples; i++) {
        int poissonSample = poissonRandomVariable(lambda);
        printf("Sample %d: %d\n", i + 1, poissonSample);
    }

    return 0;
}


