import numpy as np

num_simulations = 10000 

X1 = np.random.randint(1, 7, size=num_simulations)
X2 = np.random.randint(1, 7, size=num_simulations)

count = 0
for i in range(0,num_simulations):
    if X1[i] == 1 and X2[i] == 4:
        count = count + 1

print(count/num_simulations,1/36)

#print(X)


#probability = np.mean(die_rolls == 1)
#result=1/6
#print(f"Probability of getting a 1 in the 1st throw: {probability:.4f},{result}")
#
