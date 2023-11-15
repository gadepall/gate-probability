import numpy as np
import matplotlib.pyplot as plt

#Simulation
T  = np.genfromtxt("T.dat")
sample_len = len(T)
x = np.linspace(0,2,100)
cdf = []
for i in x:
	count = len(T[i>T])
	cdf.append(count/sample_len)
x
#Theoretical CDF
t = 0.5
cdf_th = 1 - (np.exp(-5*x/t**2))*(625*x**4 + 500*(t**2)*x**3 + 300*(t**4)*x**2 + 120*(t**6)*x + 24*t**8)/(24*t**8)

plt.plot(x, cdf, label = "Simulation")
plt.plot(x, cdf_th, label = "Theoretical")
plt.xlabel('T')
plt.ylabel('CDF')
plt.title('Theoretical vs Simulation')
plt.legend()
plt.grid()
plt.savefig('/home/dhruv/Devansh/EE23010/gate.23.st.40/figs/cdf.png')
	
