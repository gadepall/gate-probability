#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <random>

// True coefficients for the quadratic polynomial regression model: y = beta0 + beta1 * x + beta2 * x^2 + epsilon
double true_beta0 = 3.0;
double true_beta1 =2.0;
double true_beta2 = 0.5;
double PI = 3.1415;
// Parameters for the Gaussian noise (epsilon)
double mean_epsilon = 0.1;     // Mean of epsilon
double variance_epsilon = 1.0; // Variance of epsilon
double true_mean_epsilon = 0.1;
// Function to generate synthetic data with Gaussian noise (epsilon) for a quadratic model
double generate_data(double x,FILE *out_file,int flag)
{
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    double z = sqrt(-2.0 * log(u1)) * cos(2 * PI * u2); 
    std::normal_distribution<double> normal(mean, stddev);       // Standard normal random variable
    double epsilon = mean_epsilon + sqrt(variance_epsilon) * z; // Gaussian noise
    double y=true_beta0 + true_beta1 * x + true_beta2 * x * x + epsilon;
    if(flag)
   fprintf(out_file, "%lf \t %lf \t %lf \n",x,y,epsilon);
    return y;
}

// Function to estimate beta0, beta1, and beta2 using MLE for a quadratic polynomial regression model
void estimate_mle(double x[], double y[], int n, double *beta0_hat, double *beta1_hat, double *beta2_hat)
{
    double sum_x = 0.0, sum_y = 0.0, sum_x2 = 0.0, sum_x3 = 0.0, sum_x4 = 0.0, sum_xy = 0.0, sum_x2y = 0.0;

    for (int i = 0; i < n; i++)
    {
        double x2 = x[i] * x[i];
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x2;
        sum_x3 += x[i] * x2;
        sum_x4 += x2 * x2;
        sum_xy += x[i] * y[i];
        sum_x2y += x2 * y[i];
    }

    // Calculate the coefficients using the MLE formulas
    double denominator = n * (sum_x2 * sum_x4 - sum_x3 * sum_x3);
    *beta2_hat = (sum_x2 * sum_x2y - sum_x3 * sum_xy) / denominator;
    *beta1_hat = (n * (sum_x2y - *beta2_hat * sum_x3) - (sum_xy - *beta2_hat * sum_x2)) / denominator;
    *beta0_hat = (sum_y - *beta1_hat * sum_x - *beta2_hat * sum_x2) / n;
}
double estimate_mu(double y[],double x[], int n) {
    double sum_y = 0.0;

    for (int i = 0; i < n; i++) {
        sum_y += (y[i]-true_beta0 - true_beta1 * x[i] - true_beta2 * x[i] * x[i]);
    }

    return sum_y / n;
}

int main()
{
    srand(time(NULL));

    int num_simulations = 10000; // Number of simulations
    int sample_size = 1000;      // Sample size in each simulation

    double x[sample_size]; // Independent variable
    double y[sample_size]; // Dependent variable
    double beta0_hat, beta1_hat, beta2_hat;

    double beta0_bias = 0.0;
    double beta1_bias = 0.0;
    double beta2_bias = 0.0;
    double mu_hat;
 FILE *out_file = fopen("generated_data.dat", "w"); 
   fprintf(out_file, "Independent variable\t dependent variable\t epsilon\n");
    double mu_bias = 0.0;

    for (int simulation = 0; simulation < num_simulations; simulation++)
    {
        // Generate synthetic data with Gaussian noise
        int flag=0;
        for (int i = 0; i < sample_size; i++)
        {
            flag=(simulation==num_simulations-1);
            x[i] = (double)i;
            y[i] = generate_data(x[i],out_file,flag);
        }
        beta0_bias -= (beta0_hat - true_beta0) / sample_size;
        // Estimate the mean (mu) using MLE
        mu_hat = estimate_mu(y,x, sample_size);

        // Calculate bias
        mu_bias += (mu_hat - true_mean_epsilon)/sample_size;

        // Calculate average bias over all simulations
       

        // Estimate beta0, beta1, and beta2 using MLE
        estimate_mle(x, y, sample_size, &beta0_hat, &beta1_hat, &beta2_hat);

        // Calculate bias
        beta0_bias += (beta0_hat - true_beta0) / sample_size;
        beta1_bias += (beta1_hat - true_beta1) / sample_size;
        beta2_bias += (beta2_hat - true_beta2) / sample_size;
    }

    // Calculate average bias over all simulations
    mu_bias /= num_simulations;

        // printf("True mean_epsilon: %lf\n", true_mean_epsilon);
        // printf("Average bias for mu_hat: %lf\n", mu_bias);
    beta0_bias /= num_simulations;
    beta1_bias /= num_simulations;
    beta2_bias /= num_simulations;
    printf("Average Value for Alpha0 : %lf\n",true_beta0-beta0_bias);
    printf("Average Value for Alpha1 : %lf\n",true_beta1-beta1_bias);
    printf("Average Value for Alpha2 : %lf\n",true_beta2-beta2_bias);
    printf("Average Value for mu : %lf\n",mean_epsilon);
    // printf("True beta0: %lf, True beta1: %lf, True beta2: %lf\n", true_beta0, true_beta1, true_beta2);
    // printf("Average bias for beta0: %lf, Average bias for beta1: %lf, Average bias for beta2: %lf\n", beta0_bias, beta1_bias, beta2_bias);
    printf("Average Bias for Alpha0 : %lf\n",beta0_bias);
    printf("Average Bias for Alpha1 : %lf\n",beta1_bias);
    printf("Average Bias for Alpha2 : %lf\n",beta2_bias);
    printf("Average Bias for mu : %lf\n",mu_bias);
    return 0;
}
