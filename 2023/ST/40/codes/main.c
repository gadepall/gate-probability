#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate a random sample from a normal distribution
double generateNormalSample(double mean, double variance) {
   	double u1 , u2;
 	while (1) {
 		u1 = ((double)rand () / RAND_MAX);
 		if (u1 > 0 && u1 < 1)
 			break;}
 	while (1) {
		u2 = ((double)rand () / RAND_MAX);
		if (u2 > 0 && u2 < 1)
 			break;}
	double z1 = sqrt (-2 * log(u1)) * cos (2 *M_PI * u2);
	z1 = z1*sqrt(variance) + mean;
	return z1;
}

double E(double* var, int n){
	double result = 0;
	for (int i = 0; i < n; i++){
		result += var[i];
	}
	result /= n;
	return result;
}
int main() {

    // Parameters of the normal distribution
    double mean = 0.0;  // Mean
    double theta = 0.5;  // Variance = theta^2
	
    // Generate and print random samples from the normal distribution
    
    int numSamples = 10000;  // You can change the number of samples as needed
    srand(time(NULL));
    double variables[10][numSamples];
    for (int i = 0; i < 10; i++){
    	// Set the seed for the random number generator (you can use any seed)
    	for (int j = 0; j < numSamples; j++) {
        	double sample = generateNormalSample(mean, theta*theta);
        	//Converting X to X^2
        	variables[i][j] = sample*sample;
    	}
    }
    double T[numSamples];
    for(int i = 0; i < numSamples; i++){
    	T[i] = 0;
    	for (int j = 0; j < 10; j++){
    	T[i] += variables[j][i]/10;
    }
    }
    FILE *file = fopen("T.dat", "w");
    if (file == NULL){
    	printf("Unable to open file for writing.\n");
		return 1;
	}
	for(int i = 0; i < numSamples; i++){
		fprintf(file, "%lf\n", T[i]);
	}
	fclose(file);		
    //Finding value of C which minimizes E((cT - theta^2)^2)
    double min = 1000;
    double c_min = 0;
    for(double c = 0.0; c < 10; c += 0.01){
    	double sum = 0.0;
    	for(int i = 0; i < numSamples; i++){
    		sum += pow(c*T[i] - theta*theta, 2);	
    	}
    	sum = sum/numSamples;
    	if (sum < min){
    		min = sum;
    		c_min = c;
    	}
    }
    printf("The value of c which minimizes the mean square error is %lf \n", c_min);
    return 0;
}

