import numpy as np
import matplotlib.pyplot as plt

# Read data from the "uni.dat" file
x = np.genfromtxt("uni.dat")

# Create a histogram plot of the PDF
plt.hist(x, bins=50, density=True, alpha=0.6, color='b', label='PDF (Histogram)')
plt.xlabel('x (Standard Normal Random Variable)')
plt.ylabel('Frequency')
plt.title('PDF of Standard Normal Distribution (Histogram)')
plt.savefig('/home/sayyam/KHP/figs/figure1.png')
plt.show()


