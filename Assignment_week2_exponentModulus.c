#include <stdio.h>
#include <math.h>

long long int PowerMod(unsigned long long base, long long int exponent, unsigned long long int modulus)
{
    if (modulus <= 1) {
        printf("Error: Modulus must be greater than 1.\n");
        return -1; 
    }

    if (exponent < 0) {
        printf("Error: Negative exponents not supported for modular arithmetic.\n");
        return -1; 
    }
    
    // Base condition
    if (exponent == 0) {
        return 1;
    }

    if (exponent == 1) {
        return base % modulus;
    }

    unsigned long long value = PowerMod(base, exponent / 2, modulus);
    value = (value * value) % modulus;

    // If exponent is odd
    if (exponent % 2 == 1) {
        return (value * base) % modulus;
    }
    
    return value;
}

int main()
{
    unsigned long long base;
    long long int mod, exp;

    printf("\n  ((base)^(exponent)) MOD (modulus)\n");
    printf("Enter the base: \n");
    scanf("%llu", &base);

    printf("Enter the exponent: \n");
    scanf("%lld", &exp);

    printf("Enter the modulus: \n");
    scanf("%lld", &mod);

    // Handle negative modulus
    if (mod < 0) {
        printf("Error: Modulus cannot be negative.\n");
        return 1;
    }

    if (mod <= 1) {
        printf("Modulus must be greater than 1.\n");
        return 1;
    }

    unsigned long long result = PowerMod(base, exp, mod);

    if (result != -1) {
        printf("Result: %llu\n", result);
    } else {
        printf("Calculation failed due to invalid input.\n");
    }

    return 0;
}
