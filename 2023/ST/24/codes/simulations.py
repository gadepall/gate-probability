import numpy as np
import matplotlib.pyplot as plt

# Load the simulated estimations
estimations = np.loadtxt('estimations.txt')
n=1000 #number of samples
# Theoretical CDF
def theoretical_cdf(x):
    if x < 1/3:
        return 0
    elif x < theta:
        return ((x - 1/3) / (theta - 1/3))**n
    else:
        return 1

theta = 2
x = np.sort(estimations)
y_theoretical = [theoretical_cdf(val) for val in x]

# Empirical CDF
y_simulated = np.arange(1, len(x) + 1) / len(x)

# Plot the CDFs
plt.plot(x, y_theoretical, label="Theoretical CDF")
plt.step(x, y_simulated, label="Simulated CDF", where='post')
plt.xlabel("Y")
plt.ylabel("CDF")
plt.legend()
plt.show()

