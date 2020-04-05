#include <stdio.h>

#define SIZE 1000
char matrix[SIZE][SIZE];

int main()
{
    FILE* f = fopen("input", "r");
    int left, top, width, height, num;
    while(fscanf(f, " #%d @ %d,%d: %dx%d", &num, &left, &top, &width, &height) != EOF) {
        printf("Elaborating row %d\n", num);
        for(int i = top; i < top + height; i++)
            for(int j = left; j < left + width; j++)
                if(matrix[i][j]) matrix[i][j] = 'X';
                else matrix[i][j] = '#';
    }
    int counter = 0;
    for(int i = 0; i < SIZE; i++)for(int j = 0; j<SIZE;j++) counter += matrix[i][j] == 'X';

    printf("%d\n", counter);
}
