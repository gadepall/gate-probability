import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import chi2

# Load Mahalanobis distances from the data file
with open("mahalanobis_distances.dat", "r") as file:
    distances = [float(line.strip()) for line in file]

# Sort the distances
distances.sort()

# Calculate the empirical CDF
n = len(distances)
ecdf = np.arange(1, n + 1) / n

# Calculate the chi-squared CDF with 2 degrees of freedom (2 variables in your data)
chi2_cdf = chi2.cdf(distances, df=2)

# Plot the empirical CDF
plt.figure()
plt.plot(distances, ecdf, label="Empirical CDF")

# Plot the chi-squared CDF
plt.plot(distances, chi2_cdf, label="Chi-squared CDF (df=2)")

plt.xlabel("Mahalanobis Distance")
plt.ylabel("Cumulative Probability")
plt.legend()
plt.title("CDF Comparison")
plt.grid(True)
plt.savefig('../figs/graph.png')

