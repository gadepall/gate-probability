import matplotlib.pyplot as plt

# Reading data from the text file
with open('data.txt', 'r') as file:
    lines = file.readlines()
    cdf_values = list(map(float, lines[0].split()))
    simulated_values = list(map(float, lines[1].split()))

# Plotting the data
k_values = [0, 1, 2]

plt.figure(figsize=(10, 6))
plt.title('Theoretical vs Simulated CDF of Red Flowers')
plt.xlabel('Number of Red Flowers (k)')
plt.ylabel('Cumulative Probability')
plt.stem(k_values, cdf_values, linefmt='b-', markerfmt='bo', label='Theoretical CDF', use_line_collection=True)
plt.stem(k_values, simulated_values, linefmt='r-', markerfmt='ro', label='Simulated CDF', use_line_collection=True)
plt.legend()
plt.savefig("graph.png")

