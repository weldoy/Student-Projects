#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    
    int z = -3, x = 6, d = 3, b = 5;
    double k, l, m;
    k = (z / (z + 1));
    l = ((x - d) / (x + d));
    m = ((z + b + x) / 3);

    printf("The value k= %f\n", k);
    printf("The value l= %f\n", l);
    printf("The value m= %f\n", m);

    return 0;
}