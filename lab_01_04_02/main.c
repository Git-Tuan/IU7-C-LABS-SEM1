#include <stdio.h>

void convert_seconds(int raw_seconds, int *hours, int *minutes, int *seconds);
void input(int *raw_seconds_pointer);

int main(void)
{
    int raw_seconds, hours, minutes, seconds;

    printf("Please type time in seconds: ");
    input(&raw_seconds);
    
    convert_seconds(raw_seconds, &hours, &minutes, &seconds);
    printf("The time is %d hours %d minutes %d seconds", hours, minutes, seconds);
    
    return 0;
}

void input(int *raw_seconds_pointer)
{
    scanf("%d", raw_seconds_pointer);
}

void convert_seconds(int raw_seconds, int *hours, int *minutes, int *seconds)
{
    *hours = raw_seconds / 3600;
    *minutes = (raw_seconds % 3600) / 60;
    *seconds = raw_seconds - (*hours * 3600) - (*minutes * 60);
}
