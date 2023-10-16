#include <stdio.h>
#include <math.h>
int main() {
    // Given values
    double RSS = 44.0;  // Residual Sum of Squares
    double TSS = 80.0;  // Total Sum of Squares
    // Calculate R-squared
    double R_squared = 1.0 - (RSS / TSS);
    // Round R-squared to two decimal places
    // Print the result
    printf("The coefficient of determination (R-squared) is: %.2lf\n", R_squared);
    return 0;
}

