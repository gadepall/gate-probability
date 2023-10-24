import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import poisson

# Load data from 'pois.dat'
with open('pois.dat', 'r') as file:
    data = [int(line.strip()) for line in file]

def cdf_simulation(randvar, data):
    simlen = len(data)  # Number of samples
    err = []  # Declaring probability list

    for i in range(0, 30):  # Adjust the range based on your data
        x = i
        err_ind = np.count_nonzero(np.array(data) <= x)  # Checking probability condition
        err_n = err_ind / simlen  # Computing the probability
        err.append(err_n)  # Storing the probability values in a list

    return err

# Calculate the CDF using the cdf_simulation function
simulated_cdf = cdf_simulation(data, data)

# Create a theoretical Poisson distribution with the same lambda (l) value
l = 9  # Change this to your desired lambda
theoretical_cdf = poisson.cdf(range(30), mu=l)

# Plot both the simulated and theoretical CDFs
plt.plot(range(30), simulated_cdf, marker='o', label='Simulated CDF')
plt.plot(range(30), theoretical_cdf, marker='x', label='Theoretical CDF')
plt.xlabel('Poisson Random Variable (X)')
plt.ylabel('CDF')
plt.title('Simulated vs. Theoretical CDF of Poisson Distribution')
plt.legend()
plt.grid(True)
plt.show()
