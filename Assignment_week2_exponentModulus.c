#include <stdio.h>
#include <math.h>

long long int PowerMod(unsigned long long base, unsigned long long exponent, unsigned long long int modulus)
{
    // base condition
    if (exponent == 0)
    {
        return 1;
    }

    if (exponent == 1)
    {
        return base;
    }


    unsigned long long value = PowerMod(base, exponent / 2, modulus);

    value = (value * value) % modulus;


    //if exponent is odd 
    if (exponent % 2 == 1)
    {
        return (value * base) % modulus;
    }
    
    return value;
}


int main()
{
    unsigned long long base, exp, mod;

    printf("\n  ((base)^(exponent)) MOD (modulas)\n");
    printf("Enter the (base) \n");
    scanf("%llu", &base);

    printf("Enter the exponent \n");
    scanf("%llu", &exp);

    printf("Enter the modulus \n");
    scanf("%llu", &mod);

    
    if (mod <= 1)
    {
        printf("Modulus must be greater than 1.\n");
        return 1;
    }

    unsigned long long result = PowerMod(base, exp, mod);

    printf("Result: %llu\n", result);
}
