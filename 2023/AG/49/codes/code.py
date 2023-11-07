import numpy as np
import scipy.integrate as spi
import matplotlib.pyplot as plt

# Define the density functions for X1 (convective storms) and X2 (tropical cyclone-induced storms)
def fX1(x1):
    return np.exp(-x1)

def fX2(x2):
    return 2 * np.exp(-2 * x2)

# Simulate the random variables X1 and X2
num_samples = 100000  # You can adjust the number of samples
x1_samples = np.random.exponential(scale=1, size=num_samples)
x2_samples = np.random.exponential(scale=0.5, size=num_samples)

# Calculate the probability of X1 + X2 > 1 through simulation
total_samples = len(x1_samples)
event_count = np.sum((x1_samples + x2_samples) > 1)
probability_simulated = event_count / total_samples

# Calculate the probability analytically using convolution
probability_analytical = 1 - spi.quad(lambda x: fX1(x) * spi.quad(lambda y: fX2(x - y), 0, x)[0], 0, np.inf)[0]

print(f"Simulated Probability: {probability_simulated:.2f}")
print(f"Analytical Probability: {probability_analytical:.2f}")

# Plot the PDFs
x = np.linspace(0, 5, 100)
pdf_x1 = [fX1(val) for val in x]
pdf_x2 = [fX2(val) for val in x]

plt.figure(figsize=(10, 5))
plt.plot(x, pdf_x1, label="Convective Storms (X1)")
plt.plot(x, pdf_x2, label="Tropical Cyclone-Induced Storms (X2)")
plt.xlabel("Event Units")
plt.ylabel("Probability Density")
plt.legend()
plt.title("Probability Density Functions (PDFs)")
plt.show()

