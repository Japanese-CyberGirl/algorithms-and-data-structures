#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *input = fopen("input.txt", "r");

    int N = 0;
    fscanf(input, "%d", &N);

    

    fclose(input);
    return 0;
}