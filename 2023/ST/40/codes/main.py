import matplotlib.pyplot as plt
import numpy as np

T  = np.genfromtxt("T.dat")
theta  = 0.5
c = np.linspace(-4,4,100)
MSE = []
for i in c:
	MSE.append(sum((i*T - theta**2)**2)/len(T))

plt.plot(c, MSE)
plt.xlabel("c")
plt.ylabel("Mean Square Error")
plt.grid()
plt.title("Mean Square Error vs c")
plt.savefig('/home/devansh/EE23010/gate.23.st.40/figs/fig1.png')
