import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import binom

# Open the file in read mode
with open("des_dist2.dat", "r") as file:
    # Read the lines from the file
    lines = file.readlines()

# Process the lines as needed
Z = [float(line.strip()) for line in lines]
Z = np.array(Z)

num_sim = len(Z)

desired = Z[(Z==0)]
desired1 = Z[(Z==1)]
desired2 = Z[(Z==2)]
sim_prob = len(desired)/len(Z)
sim_prob1 = len(desired1)/len(Z)
sim_prob2 = len(desired2)/len(Z)
sim = [sim_prob, sim_prob1, sim_prob2]
p0 = binom.pmf(0, 2, 0.5)
p1 = binom.pmf(1, 2, 0.5)
p2 = binom.pmf(2, 2, 0.5)
act = [p0,p1,p2]
x = [0,1,2]
plt.stem(x, sim, basefmt=" ", markerfmt="bo", linefmt="b-", label='Simulation')
plt.stem(x, act, basefmt=" ", markerfmt="go", linefmt="g-", label='Actual')
plt.legend()
plt.xlabel('X')
plt.ylabel('Probability')
plt.title('Simulated vs Theoretical Analysis')
plt.savefig('/home/sameer/65/figs/fig.png')
plt.grid(True)
plt.show()

cdf0= sim_prob
cdf1= sim_prob + sim_prob1
cdf2 =sim_prob +sim_prob1 + sim_prob2
cdf =[cdf0,cdf1,cdf2]
x = [0,1,2]
plt.stem(x, cdf, basefmt=" ", markerfmt="bo", linefmt="b-", label='CDF')
plt.legend()
plt.xlabel('X')
plt.ylabel('Probability')
plt.title('CDF')
plt.savefig('/home/sameer/65/figs/fig1.png')
plt.grid(True)
plt.show()
