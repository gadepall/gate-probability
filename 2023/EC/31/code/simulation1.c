#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double SNR_dB = 61.96; // Given SNR in dB
    double P_s = 0.5; // Signal Power

    // Arrays for quantization error values and number of bits
    double q_values[10000];
    int num_bits = 0;

    // Number of samples for simulation
    int num_samples = 10000;

    // Initialize an array of q (quantization Error) values to test
    for (int i = 0; i < 10000; i++) {
        double q = 0.001 + i * (5.0 - 0.001) / 10000;
        num_bits = (int)(round(1 - log2(q))); // Calculate the number of bits
        double quantization_error[num_samples];

        for (int j = 0; j < num_samples; j++) {
            quantization_error[j] = -q / 2 + ((double)rand() / RAND_MAX) * q; // Generating random variable uniformly of pdf between -q/2 and q/2
        }

        // Calculate Mean Error
        double mean_error = 0;
        for (int j = 0; j < num_samples; j++) {
            mean_error += quantization_error[j];
        }
        mean_error /= num_samples;

        // Calculate variance and noise power
        double variance_error = 0;
        for (int j = 0; j < num_samples; j++) {
            variance_error += pow(quantization_error[j] - mean_error, 2);
        }
        variance_error /= num_samples;
        double P_n = variance_error - pow(mean_error,2); 

        // Calculate SNR and check for the value of n for target SNR
        double SNR = 10 * log10(P_s / P_n);
        if (fabs(SNR_dB - SNR) < 1) {
            printf("Number of Bits: %d\n", num_bits);
            break;
        }
    }

    return 0;
}

