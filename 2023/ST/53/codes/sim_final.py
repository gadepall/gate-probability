import numpy as np
import matplotlib.pyplot as plt
import scipy 

x=np.linspace(-1,2,30)
def cdf_simulation(randvar):
	simlen = int(10000) #number of samples
	err = [] #declaring probability list
	for i in range(0,30):
		err_ind = np.nonzero(randvar < x[i]) #checking probability condition
		err_n = np.size(err_ind) #computing the probability
		err.append(err_n/simlen) #storing the probability values in a list
	return err
	
		
cdf_e_minus_X = cdf_simulation(np.loadtxt("e_minus_X.txt"))
cdf_one_minus_e_minus_X=cdf_simulation(np.loadtxt("one_minus_e_minus_X.txt"))
cdf_two_e_minus_X_minus_1=cdf_simulation(np.loadtxt("two_e_minus_X_minus_1.txt"))
cdf_uniform_minus_1_to_0=cdf_simulation(np.loadtxt("uniform_minus_1_to_0.txt"))
cdf_uniform_0_to_2=cdf_simulation(np.loadtxt("uniform_0_to_2.txt"))
cdf_uniform_minus_1_to_1=cdf_simulation(np.loadtxt("uniform_minus_1_to_1.txt"))

plt.figure(figsize=(10, 10))
plt.plot(x.T,cdf_e_minus_X,'o',label='Simulation')#plotting the CDF
plt.plot(x.T,cdf_uniform_minus_1_to_0,label='Given')
plt.grid() #creating the grid
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')
plt.legend()
plt.savefig("cdf_comp_1.png")

plt.figure(figsize=(10, 10))
plt.plot(x.T,cdf_one_minus_e_minus_X,'o',label='Simulation')#plotting the CDF
plt.plot(x.T,cdf_uniform_0_to_2,label='Given')
plt.grid() #creating the grid
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')
plt.legend()
plt.savefig("cdf_comp_2.png")

plt.figure(figsize=(10, 10))
plt.plot(x.T,cdf_two_e_minus_X_minus_1,'o',label='Simulation')#plotting the CDF
plt.plot(x.T,cdf_uniform_minus_1_to_1,label='Given')
plt.grid() #creating the grid
plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')
plt.legend()
plt.savefig("cdf_comp_3.png")
