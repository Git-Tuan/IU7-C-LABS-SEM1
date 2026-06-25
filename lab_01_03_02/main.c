#include <stdio.h>

float calculate_resistance(float r, float r2, float r3);

void input(float *rr, float *rr2, float *rr3)
{
    printf("Type value for 1st resistor (in Ohm): ");
    scanf("%f", rr);

    printf("Type value for 2nd resistor (in Ohm): ");
    scanf("%f", rr2);

    printf("Type value for 3rd resistor (in Ohm): ");
    scanf("%f", rr3);
}

int main(void)
{
    float r, r2, r3, total_res;

    input(&r, &r2, &r3);
    total_res = calculate_resistance(r, r2, r3);
    printf("Total resistance is: %f Ohm\n", total_res);
    
    return 0;
}

float calculate_resistance(float r, float r2, float r3)
{
    return (r * r2 * r3) / (r2 * r3 + r * r3 + r * r2);
}

