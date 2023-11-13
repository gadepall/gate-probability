import random

def simulate_x_linked_inheritance(num_trials):
    fabry_count = 0

    for _ in range(num_trials):
        # Mother is a carrier (X^cX^d)
        mother_genotype = ['Xc', 'Xd']

        # Father is normal (XY)
        father_genotype = ['X', 'Y']

        # Randomly choose one X chromosome from the mother and one from the father
        son_genotype = [random.choice(mother_genotype), random.choice(father_genotype)]

        # Check if the son has Fabry disease (XdY genotype)
        if 'Xd' in son_genotype[0] and 'Y' in son_genotype[1]:
            fabry_count += 1

    # Calculate the probability as a percentage
    probability = (fabry_count / num_trials) * 100

    return probability

# Set the number of simulation trials
num_trials = 100000

# Run the simulation
result = simulate_x_linked_inheritance(num_trials)

# Display the result
print(f"The corrected probability of having a son with Fabry disease is approximately {result:.2f}% based on {num_trials} simulations.")

