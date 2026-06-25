// 2 вариант
#include <stdio.h>
#include <math.h>

float calculate_length(float x1, float y1, float x2, float y2);
float calculate_perimeter(float l1, float l2, float l3);


int main(void)
{
    float x1, y1, x2, y2, x3, y3;
    float l1, l2, l3, p;
    
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
    
    l1 = calculate_length(x1, y1, x2, y2);
    l2 = calculate_length(x2, y2, x3, y3);
    l3 = calculate_length(x1, y1, x3, y3);
    
    p = calculate_perimeter(l1, l2, l3);
    
    printf("%f\n", p);
    
    return 0;
}

float calculate_length(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrtf(dx * dx + dy * dy);
}

float calculate_perimeter(float l1, float l2, float l3)
{
    return l1 + l2 + l3;
}
