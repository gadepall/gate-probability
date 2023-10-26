import numpy as np
import matplotlib.pyplot as plt

# Define the probability space and random variable
probability_space = {1: 4/7, 2: 2/7, 3: 1/7, 4: 0}
random_variable = {1: 1, 2: 2, 3: 2, 4: 3}

# Number of simulations
num_simulations = 10000

# Simulate random variable X
simulated_X = np.random.choice(list(random_variable.values()), size=num_simulations, p=list(probability_space.values()))

# Analytical PMF
unique_values, counts = np.unique(simulated_X, return_counts=True)
analytical_pmf = counts / num_simulations

# Verify P({1, 4}) using simulation
simulated_P_1_4 = np.sum((simulated_X == 1) | (simulated_X == 4)) / num_simulations

# Analytical P({1, 4})
analytical_P_1_4 = 1/2

# Combine unique values from analytical and simulated PMFs
combined_unique_values = np.union1d(unique_values, [1, 4])

# Create arrays for analytical and simulated PMFs
combined_analytical_pmf = [probability_space[x] if x in unique_values else 0 for x in combined_unique_values]
combined_simulated_pmf = [analytical_pmf[np.where(unique_values == x)[0][0]] if x in unique_values else 0 for x in combined_unique_values]

# Create x-axis values for the line plot
x_values = np.arange(len(combined_unique_values))

# Create a step plot (line graph) for both the analytical and simulated PMFs
plt.step(x_values, combined_analytical_pmf, label="Analytical PMF", where='mid', alpha=0.5)
plt.step(x_values, combined_simulated_pmf, label="Simulated PMF", where='mid', alpha=0.5)

# Print the analytical and simulated results
print("Analytical P({1, 4}):", analytical_P_1_4)
print("Simulated P({1, 4}):", simulated_P_1_4)

plt.xticks(x_values, combined_unique_values)
plt.xlabel("X")
plt.ylabel("PMF")
plt.title("Analytical vs. Simulated PMF of X")
plt.legend()
plt.show()

