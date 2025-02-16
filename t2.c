#include <stdio.h>
#include <stdlib.h>

typedef struct box {
    int index;
    char string[7];
} box;

typedef struct arraylist {
    box *array;
    int current_size;
} arraylist;

void add_elements(arraylist *list, box new_box) {
    list->current_size += 1;
    list->array = (box *)realloc(list->array, list->current_size * sizeof(box));
    list->array[list->current_size - 1] = new_box;
}

int main()
{
    FILE *input = fopen("input.txt", "r");

    int N = 0 ;
    fscanf(input, "%d", &N);

    arraylist *massive[1000000];

    char *token[7];
    int number = 0;

    for (int i = 0 ; i < N ; i ++ ) { //создание базовой структуры для каждого номера
        arraylist *list = (arraylist*)malloc(1 * sizeof(arraylist));
        list->array = (box*)malloc(1 * sizeof(box));
        list->current_size = 1;
        massive[i] = list;
    }

    for (int i = 0 ; i < N ; i ++ ) {
        box box;
        fscanf(input, "%d %s", &box.index, box.string);
        add_elements(massive[i], box);
    }

    for (int i = 0 ; i < N ; i ++ ) {
        arraylist *list = massive[i];
        for (int j = 0 ; j < massive[i]->current_size ; j ++ ) {
            printf("%s\n", list->array);
        }
    }


    fclose(input);
    return 0;
}