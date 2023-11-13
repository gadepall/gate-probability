import math
import matplotlib.pyplot as plt

# Probability mass function for X
def pmf_X(k):
    if k == 0:
        return 1/2 * (1 + math.exp(-1))
    else:
        return math.exp(-1) / (2 * math.factorial(k))

# Expected Value E(X)
def expected_value_X():
    expected_value = 0
    for k in range(0, 101):  # You can adjust the range for higher values if needed
        expected_value += k * pmf_X(k)
    return expected_value

# Conditional Expected Value E(X|X>0)
def conditional_expected_value_X():
    conditional_expected_value = 0
    denominator = 1 - pmf_X(0)
    for k in range(1, 101):  # You can adjust the range for higher values if needed
        conditional_expected_value += (k * pmf_X(k)) / denominator
    return conditional_expected_value

# Theoretical Cumulative Distribution Function (CDF)
def cdf_theoretical(x):
    cdf_value = 0
    for k in range(0, x + 1):
        cdf_value += pmf_X(k)
    return cdf_value

# Read simulated data from "rv.dat"
with open("rv.dat", "r") as file:
    simulated_data = [float(line.strip()) for line in file]

# Calculate simulated CDF from the data
simulated_cdf = [sum(1 for value in simulated_data if value <= x) / len(simulated_data) for x in range(101)]

# Plot the theoretical CDF
x_values = list(range(101))
theoretical_cdf = [cdf_theoretical(x) for x in x_values]
plt.plot(x_values, theoretical_cdf, label="Theoretical CDF")

# Plot the simulated CDF
plt.scatter(x_values, simulated_cdf, label="Simulated CDF", color='red', marker='.')

# Add labels to axes
plt.xlabel("Random Variable (X)")
plt.ylabel("CDF")

# Display the legend
plt.legend()

# Show the plot
plt.savefig('plot.png')
# Calculate and print the results
e_x = expected_value_X()
e_x_given_x_gt_0 = conditional_expected_value_X()

print("E(X) =", e_x)
print("E(X|X>0) =", e_x_given_x_gt_0)

