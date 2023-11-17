#include <stdio.h>

double custom_pow(int base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    FILE *file = fopen("output.dat", "w");

    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    for (int x = 1; x <= 10; x++) {
        double sum = 0.0;

        for (int y = 0; y <= 10; y++) {
            if (x != y) {
                double p = 3.0 / custom_pow(2, x + y + 3);
                sum += p;
            }
        }

        fprintf(file, "x=%d: %lf\n", x, sum);
    }

    fclose(file);

    return 0;
}

