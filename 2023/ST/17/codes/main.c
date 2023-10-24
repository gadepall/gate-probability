#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int Poisson(int l){
    double el = exp(-l);  //defining e^l
        double F = el;         //initialising p(X=0)
        double u = (double)rand() / RAND_MAX;   //generating uniform random variable
        int X = 0;          //initialising poisson random variable
        double fact = 1;    //(numerator)factorial part in pmf
        double pow = 1;     //(denominator)power part in pmf
        //pmf is as in equation (2)

        while (u > F) { //checking which part of poisson distribution urv is lieing in 
            X++;
            fact *= X; //updating factorial and powers according to the poisson distribution
            pow *= l;
            F += (pow / fact) * el; //going up poisson random variable by one step every time
        }
        return X;
}

int main() {
    double l = 9; // Change l to your desired mean

    int n = 10000; // Number of simulations
    int validCount = 0; // Count of valid X values (X > 0)
    double sumY = 0.0; // Sum of 1 / (X + 1)

    srand(time(0)); // Seed the random number generator

    FILE *file = fopen("pois.dat", "w"); // Open a file for writing

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int X = Poisson(l);
        
        if (X > 0) {
            double Y = 1.0 / (X + 1);
            sumY += Y;
            validCount++;
        }

        fprintf(file, "%d\n", X); // Write X to the file
    }

    fclose(file); // Close the file

    if (validCount > 0) {
        double conditionalExpectation = sumY / validCount;
        printf("Simulated E(1 / (X + 1) | X > 0): %lf\n", conditionalExpectation);
    } else {
        printf("No valid X values (X > 0) were generated.\n");
    }

    double formulaans = (1 - exp(-l) - l * exp(-l)) / (l * (1 - exp(-l)));
    printf("Formula-based answer: %lf\n", formulaans);

    return 0;
}
