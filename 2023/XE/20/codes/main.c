#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed the random number generator
    srand(time(0));

    int y[10000];
    int c = 0;
    int cnt = 0;

    for (int i = 0; i < 10000; i++) {
        int x1 = rand() % 6 + 1;
        int x2 = rand() % 6 + 1;
        int z = x1 - x2;

        if (z == 0) {
            c++;
            int random_value = rand() % 6 + 1;
            if (random_value <= 4) {
                y[i] = 1;
                cnt++;
            } else {
                y[i] = 0;
            }
        }
    }

    double probability = (double)cnt / c;
    printf("%lf\n", probability);

    return 0;
}

