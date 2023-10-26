import matplotlib.pyplot as plt
import numpy as np

# Read the simulated values from the DAT file
with open("simulation_results.dat", "r") as file:
    lines = file.readlines()
    simulated_values = [int(line.strip()) for line in lines[1:]]

# Calculate the empirical PMF (simulated)
simulated_pmf = []
for i in range(1, 4):  # Removed the value 4
    count = simulated_values.count(i)
    pmf = count / len(simulated_values)
    simulated_pmf.append(pmf)

# Calculate the analytical PMF based on the given probabilities
p1 = 1.0 / 4.0
p2_3 = 1.0 / 2.0  # Merged p2 and p3
p4 = 1.0 / 4.0
analytical_pmf = [p1, p2_3, p4]

# X values for the PMF (without 4)
x = [1, 2, 3]  # Removed the value 4

# Create a vline graph with dots at the end
plt.vlines(x, 0, simulated_pmf, color='blue', label="Simulated PMF", linestyle='-', linewidth=2)
plt.vlines(x, 0, analytical_pmf, color='red', label="Analytical PMF", linestyle='dashed', linewidth=2)

# Add dots to the end of the vlines for both datasets
dot_size = 10  # Adjust the size of the dots
for xi, yi in zip(x, simulated_pmf):
    plt.plot(xi, yi, 'bo', markersize=5)

for xi, yi in zip(x, analytical_pmf):
    plt.plot(xi, yi, 'ro', markersize=dot_size)

plt.xlabel('X')
plt.ylabel('Probability')
plt.title('Simulated PMF vs Analytical PMF')
plt.legend()
plt.grid()
plt.show()

