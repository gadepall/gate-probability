import matplotlib.pyplot as plt

# Read data from the file
with open("output.dat", "r") as file:
    lines = file.readlines()

# Extract x and sum values
x_values = []
sum_values = []

for line in lines:
    parts = line.split(":")
    x_values.append(int(parts[0].split("=")[1].strip()))
    sum_values.append(float(parts[1].strip()))

# Plot the results with vertical lines connecting each point
plt.scatter(x_values, sum_values, marker='o')
plt.title('Marginal pmf of X')
plt.xlabel('x')
plt.ylabel('Marginal pmf')
plt.grid(True)

# Add vertical lines connecting each point
for x, y in zip(x_values, sum_values):
    plt.vlines(x, ymin=0, ymax=y, color='b', linestyle='--', alpha=0.5)

plt.legend()
plt.show()

