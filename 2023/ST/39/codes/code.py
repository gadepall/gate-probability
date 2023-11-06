import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import gamma

# Load data from output.txt file
data = np.loadtxt('output.txt')

# Extract generated values and simulated CDF values
generated_values = data[:, 0]
simulated_cdf_values = data[:, 1]

# Sort the generated values for plotting
sorted_indices = np.argsort(generated_values)
sorted_generated_values = generated_values[sorted_indices]
sorted_simulated_cdf_values = simulated_cdf_values[sorted_indices]

# Calculate theoretical gamma CDF values for the sorted generated values
shape_parameter = 5
rate_parameter = 2.0
theoretical_cdf_values = gamma.cdf(sorted_generated_values, shape_parameter, scale=1/rate_parameter)

# Plotting
plt.figure(figsize=(8, 6))
plt.scatter(sorted_generated_values, theoretical_cdf_values, label='Theoretical CDF', color='red', s=10, marker='o')
plt.plot(sorted_generated_values, sorted_simulated_cdf_values, label='Simulated CDF', color='blue', linewidth=2)
plt.xlabel('Generated Values')
plt.ylabel('Gamma CDF')
plt.title('Theoretical vs. Simulated Gamma CDF')
plt.legend()
plt.grid(True)
plt.show()

