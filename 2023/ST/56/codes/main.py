import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import poisson

# Function to simulate CDF
def cdf_simulation(data):
    simlen = len(data)
    cdf_values = []

    for i in range(0, 30):  # Adjust the range based on your data
        x = i
        cdf_value = np.count_nonzero(np.array(data) <= x) / simlen
        cdf_values.append(cdf_value)

    return cdf_values

# Function to plot and save CDF
def plot_and_save_cdf(values, simulated_cdf, theoretical_cdf, label):
    plt.plot(values, simulated_cdf, marker='o', label='Simulated CDF')
    plt.plot(values, theoretical_cdf, marker='x', label='Theoretical CDF')
    plt.xlabel('Poisson Random Variable ')
    plt.ylabel('CDF')
    plt.title(f'Simulated vs. Theoretical CDF for Lambda={label}')
    plt.legend()
    plt.grid(True)
    plt.savefig(f"../figs/fig{label}.png")
    plt.show()

# Lambda values
lambda_values = [1, 2]

for lambd in lambda_values:
    # Simulated data
    simulated_data = np.random.poisson(lam=lambd, size=10000)

    # Theoretical CDF
    values = np.arange(30)
    theoretical_cdf = poisson.cdf(values, mu=lambd)

    # Simulated CDF
    simulated_cdf = cdf_simulation(simulated_data)

    # Plot and save CDF
    plot_and_save_cdf(values, simulated_cdf, theoretical_cdf, lambd)

