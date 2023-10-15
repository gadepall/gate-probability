import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('cdf_values.dat', skiprows=1)

mu_values = data[:, 0]
cdf_X = data[:, 1]
cdf_Y = data[:, 2]

plt.figure(figsize=(10, 6))
plt.plot(mu_values, cdf_X, label='CDF of X')
plt.plot(mu_values, cdf_Y, label='CDF of Y')

plt.xlabel('μ')
plt.ylabel('CDF')
plt.title('CDF of X and Y vs. μ')
plt.legend()
plt.grid(True)
plt.savefig("../figs/figure.png")
plt.show()
