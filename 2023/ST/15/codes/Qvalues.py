import scipy.stats as stats
import matplotlib.pyplot as plt
import numpy as np

# Define the cumulative distribution function
def F(x):
    if x < -1:
        return stats.norm.cdf(x)
    else:
        return stats.norm.cdf(x + 1)

# Calculate and print specific probabilities
print(f"P(X <= -1) = {F(-1)}")
print(f"P(X = -1) = {F(-1) - F(-1 - 1e-10)}")
print(f"P(X < -1) = {F(-1 - 1e-10)}")
print(f"P(X <= 0) = {F(0)}")

# Vectorize the function F(x)
vectorized_F = np.vectorize(F)

# Create a range of x values for the plot
x_values = np.linspace(-3, 3, 1000)
y_values = vectorized_F(x_values)

# Plot the cumulative distribution function (CDF)
plt.plot(x_values, y_values)
plt.xlabel('x')
plt.ylabel('F(x)')
plt.title('Cumulative Distribution Function (CDF) of X')
plt.grid(True)
plt.savefig('/home/karthikeya/Desktop/Probability/15/figs/figure1.png')
plt.show()

