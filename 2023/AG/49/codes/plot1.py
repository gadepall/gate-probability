import numpy as np
import matplotlib.pyplot as plt

# Read data from .dat files
with open("random_vars1.dat", "r") as file:
    random_vars = [float(line) for line in file]

with open("cdf_values1.dat", "r") as file:
    cdf_values = [float(line) for line in file]

with open("theoretical_cdf_values1.dat", "r") as file:
    theoretical_cdf_values = [float(line) for line in file]

# Sort data by random_vars
sorted_data = sorted(zip(random_vars, cdf_values, theoretical_cdf_values), key=lambda x: x[0])
random_vars, cdf_values, theoretical_cdf_values = zip(*sorted_data)

# Create plots
plt.figure(figsize=(12, 6))
#plt.subplot(1, 2, 1)
plt.plot(random_vars, cdf_values, label="Generated CDF")
plt.xlabel("Random Variable")
plt.ylabel("CDF Value")
plt.title("Generated CDF vs Random Variable (Sorted)")
plt.grid(True)
plt.legend()

#plt.subplot(1, 2, 2)
plt.plot(random_vars, theoretical_cdf_values, label="Theoretical CDF")
plt.xlabel("Random Variable")
plt.ylabel("CDF Value")
plt.title("Theoretical CDF vs Random Variable (Sorted)")
plt.grid(True)
plt.legend()

plt.tight_layout()

# Show the plots
plt.savefig('/home/dhruv/EE23010/gate_49/figs/figure1')

