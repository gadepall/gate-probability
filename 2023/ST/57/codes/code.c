#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 1000 // Number of simulations

double generateUniformRandom()
{
  return ((double)rand() / RAND_MAX) * 2.0 - 1.0; // Generate a random number in the range [-1, 1]
}

// Define the function to calculate the 2nd mean of the sequence {Y_n}n≥1
double calculate2ndmean(double *Y, int n)
{
  double sum = 0.0;
  for (int i = 0; i < n; i++)
  {
    sum += Y[i] * Y[i];
  }
  return sum / n;
}

// Define the function to calculate the sequence {Y_n + (1/n)}n≥1
double calculateYnplus1overn(double *Y, int n)
{
  double X = generateUniformRandom();
  Y[n] = (1.0 / n) * (X * X);
  return Y[n] + (1.0 / n);
}

// Define the function to calculate the proportion of simulations where |Y_n + (1/n)| >= epsilon
double calculate_proportion_above_epsilon(double *Y, int n, double epsilon)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (fabs(Y[i] + (1.0 / n)) >= epsilon)
    {
      count++;
    }
  }
  return (double)count / n;
}

// Define the function to simulate the sequence {Xn} = \sum_{i=1}^{n} X_i
double simulate_Xn(int n)
{
  // Initialize the sum
  double sum = 0.0;

  // Iterate over the sequence Xn
  for (int i = 1; i <= n; i++)
  {
    // Generate a uniform random variable
    double X = generateUniformRandom();

    // Add the random variable to the sum
    sum += X;
  }

  // Return the sum
  return sum;
}

// Define the function to check if the sequence {Xn} converges almost surely to 0
int check_convergence_almost_surely(double *Xn, int n)
{
  // Initialize the flag
  int converges_almost_surely = 1;

  // Iterate over the sequence Xn
  for (int i = 0; i < n; i++)
  {
    // If Xn is not equal to 0, then the sequence does not converge almost surely to 0
    if (fabs(Xn[i]) >= 1.0)
    {
      converges_almost_surely = 0;
      break;
    }
  }

  // Return the flag
  return converges_almost_surely;
}

int main()
{
  int n;
  double Yn;

  // option A

  // Initialize the random number generator
  srand(time(0));

  // Open a file to save the data
  FILE *file = fopen("simulated_data.txt", "w");
  if (file == NULL)
  {
    perror("Error opening the file");
    return 1;
  }

  // Simulate and collect data
  for (n = 1; n <= N; n++)
  {
    Yn = 0;
    for (int i = 0; i < 9 * n; i++)
    {
      Yn += generateUniformRandom() * generateUniformRandom();
    }

    // Standardize Yn
    Yn /= sqrt(n);

    // Save Yn to the file
    fprintf(file, "%lf\n", Yn);
  }

  // Close the file
  fclose(file);

  printf("\n");

  // option B

  // Allocate memory for the sequence {Y_n}n≥1
  double *Y = (double *)malloc(sizeof(double) * N);

  // Simulate the sequence {Y_n}n≥1
  for (int i = 0; i < N; i++)
  {
    double X = generateUniformRandom();
    Y[i] = (1 / n) * (X * X);
  }

  // Calculate the 2nd mean of the sequence {Y_n}n≥1
  double second_mean = calculate2ndmean(Y, N);

  // Print the 2nd mean
  printf("B)The 2nd mean of the sequence {Y_n}n≥1 is: %f\n", second_mean);

  printf("\n");

  // option C

  // Simulate the sequence {Y_n + (1/n)}n≥1
  for (int i = 0; i < N; i++)
  {
    Y[i] = calculateYnplus1overn(Y, i);
  }

  // Calculate the proportion of simulations where |Y_n + (1/n)| >= epsilon
  double epsilon = 0.1;
  double proportion_above_epsilon = calculate_proportion_above_epsilon(Y, N, epsilon);

  // Print the proportion of simulations where |Y_n + (1/n)| >= epsilon
  printf("C)Proportion of simulations where |Y_n + (1/n)| >= %f: %f\n", epsilon, proportion_above_epsilon);

  // Free the allocated memory
  free(Y);

  printf("\n");

  // option D

  // Allocate memory for the sequence {Xn}
  double *Xn = (double *)malloc(sizeof(double) * N);

  // Simulate the sequence {Xn}
  for (int i = 0; i < N; i++)
  {
    Xn[i] = simulate_Xn(i + 1);
  }

  // Check if the sequence {Xn} converges almost surely to 0
  int converges_almost_surely = check_convergence_almost_surely(Xn, N);

  // Print the result
  if (converges_almost_surely)
  {
    printf("D)The sequence {Xn} converges almost surely to 0.\n");
  }
  else
  {
    printf("D)The sequence {Xn} does not converge almost surely to 0.\n");
  }

  // Print the value of X_n
  printf("D)Pr(|X_n-X|<eps) = %f\n", Xn[N - 1]);

  // Free the allocated memory
  free(Xn);

  return 0;
}
