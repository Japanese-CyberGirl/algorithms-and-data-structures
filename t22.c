#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct box {
    char string[8];
    struct box *first;
    struct box *next;
} box;

int main()
{
    FILE *input = fopen("input.txt", "r");

    int N = 0;
    fscanf(input, "%d", &N);

    // double **matrix = (double **)calloc(n, sizeof(double*)); //создания массива указателей длины n с указателями на строки

    // for (int i = 0; i < n ; i ++ ) {
    //     matrix[i] = (double *)calloc(n, sizeof(double)); //создание одномерных массивов для каждой строки
    // } 

    box **matrix = (box**)calloc(1000000 + 1, sizeof(box*));

    for (int i = 0 ; i < 1000000 + 1 ; i ++ ) {
        matrix[i] = (box*)calloc(1, sizeof(box));
    }

    for (int i = 0 ; i < N ; i ++ ) {
        int index = 0;
        char token[8];
        fscanf(input, "%d %s", &index, token);

        box *new_box = (box*)calloc(1, sizeof(box));
        strncpy(new_box->string, token, 7);
        new_box->next = NULL;

        if (matrix[index] == NULL) {
            new_box->first = new_box;
            matrix[index] = new_box;
        }
        else {
            box *last = matrix[index];
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = new_box;
            new_box->first = matrix[index];
        }
    }
    fclose(input);

    for (int i = 0 ; i < 1000000 + 1 ; i ++ ) {
        if (matrix[i] != NULL) {
            box *current = matrix[i];
            while (current != NULL) {
                printf("%d %s\n", i, current->string);
                current = current->next;
            }
        }
    }

    return 0;
}



    // for (int i = 0 ; i < 1000000 + 1 ; i ++ ) {
    //     box *current = matrix[i];
    //     while (current != NULL) {
    //         box *cash = current;
    //         current = current->next;
    //         free(cash);
    //     }
    // }

    // free(matrix);