import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm
from scipy.stats import gaussian_kde

# Load the data from the generated C program (you may need to store the data in a file)
data = np.loadtxt('simulated_data.txt')  # Replace with the actual file name

# Generate a sample of a standard normal distribution for comparison
standard_normal_sample = np.random.randn(len(data))

# Create kernel density estimation (KDE) for the data
kde_data = gaussian_kde(data)
x_data = np.linspace(min(data), max(data), 1000)
y_data = kde_data(x_data)

# KDE for the standard normal distribution
x_standard = np.linspace(min(standard_normal_sample), max(standard_normal_sample), 1000)
y_standard = norm.pdf(x_standard)

# Create curve plots
plt.figure(figsize=(8, 6))

plt.plot(x_data, y_data, label='Simulated Data', color='b')
plt.plot(x_standard, y_standard, label='Standard Normal', color='r')

plt.title('KDE Curve Plot of Simulated Data vs. Standard Normal Distribution')
plt.xlabel('Value')
plt.ylabel('Probability Density')
plt.legend()

plt.savefig("sim.png") 
plt.show()
