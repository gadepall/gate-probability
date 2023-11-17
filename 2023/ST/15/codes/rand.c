#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double sn() {
    double u1, u2;
    while (1) {
        u1 = ((double)rand() / RAND_MAX);
        if (u1 > 0 && u1 < 1)
            break;}
    while (1) {
        u2 = ((double)rand() / RAND_MAX);
        if (u2 > 0 && u2 < 1)
            break;}
    double z1 = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    return z1;
}

int main() {
    // Seed the random number generator
    srand(time(0));

    int numSamples = 100000; // You can change this to the desired number of samples
    FILE *file = fopen("uni.dat", "w");

    if (file == NULL) {
        printf("Unable to open file for writing.\n");
        return 1;
    }

    for (int i = 0; i < numSamples; i++) {
        double sample = sn();
        fprintf(file, "%lf\n", sample);
    }

    fclose(file);

    return 0;
}

