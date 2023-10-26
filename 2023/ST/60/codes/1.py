import matplotlib.pyplot as plt
import numpy as np

# Read the simulated values from the DAT file
with open("simulation_results.dat", "r") as file:
    lines = file.readlines()
    simulated_values = [int(line.strip()) for line in lines[1:]]

# Calculate the empirical CDF
simulated_values.sort()
cdf_values = np.arange(1, len(simulated_values) + 1) / len(simulated_values)

# Calculate the theoretical PDF based on given probabilities
theoretical_values = [1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0]

# Plot the CDF and PDF
plt.plot(simulated_values, cdf_values, label="Empirical CDF", marker='o', linestyle='-', color='blue')
plt.plot([1, 2, 3, 4], np.cumsum(theoretical_values), label="Theoretical PDF", marker='x', linestyle='--', color='red')
plt.xlabel('X')
plt.ylabel('Probability')
plt.title('Simulated CDF vs Theoretical PDF')
plt.legend()
plt.grid()
plt.show()

