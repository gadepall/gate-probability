#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double generate_exponential(double lambda) {
    double u = rand() / (RAND_MAX + 1.0); // Generate a random number between 0 and 1
    return -log(1 - u) / lambda; // Inverse transform method for exponential distribution
}

double gamma_pdf(double x, int shape_parameter, double lambda) {
    return (pow(lambda, shape_parameter) * pow(x, shape_parameter - 1) * exp(-lambda * x)) / tgamma(shape_parameter); // Gamma PDF formula
}

double gamma_cdf(double x, int shape_parameter, double lambda) {
    double result = 0.0;
    double step = 0.001; // Step size for numerical integration (adjust as needed for accuracy)
    double t;
    for (t = 0; t <= x; t += step) {
        result += gamma_pdf(t, shape_parameter, lambda) * step;
    }
    return result;
}

int main() {
    int num_samples = 1000; // Number of samples for the simulation
    double lambda = 2.0; // Rate parameter for exponential distribution
    int shape_parameter = 5; // Shape parameter for gamma distribution

    double gamma_samples[num_samples];
    int i;
    for (i = 0; i < num_samples; ++i) {
        double exponential_sum = 0.0;
        int j;
        for (j = 0; j < shape_parameter; ++j) {
            exponential_sum += generate_exponential(lambda);
        }
        gamma_samples[i] = exponential_sum;
    }

    // Calculate and print the estimated CDF values for the generated gamma samples
    for (i = 0; i < num_samples; ++i) {
        double cdf_value = gamma_cdf(gamma_samples[i], shape_parameter, lambda);
        printf(" %f %f\n", gamma_samples[i], cdf_value);
    }

    return 0;
}

