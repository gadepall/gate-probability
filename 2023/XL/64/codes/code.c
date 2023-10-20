#include <stdio.h>

// Function to perform genetic cross and calculate all possible offspring
void genetic_cross(const char parent1[2], const char parent2[2], char offspring[4][3]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            offspring[i * 2 + j][0] = parent1[i];
            offspring[i * 2 + j][1] = parent2[j];
            offspring[i * 2 + j][2] = '\0';
        }
    }
}

int main() {
    char genotype1[2];
    char genotype2[2];

    printf("Enter genotype 1 (10, 11, 00): ");
    scanf("%s", genotype1);

    printf("Enter genotype 2 (10, 11, 00): ");
    scanf("%s", genotype2);

    char offspring[4][3];

    // Perform genetic cross to calculate all possible offspring
    genetic_cross(genotype1, genotype2, offspring);

    // Display all possible offspring
    printf("Possible Offspring:\n");
    for (int i = 0; i < 4; i++) {
        printf("Offspring %d: %s\n", i + 1, offspring[i]);
    }

    return 0;
}

