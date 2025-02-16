#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct arraylist {
    char *string;
    int current;
    int size;
} arraylist;

arraylist* new_array() {
    arraylist *list = (arraylist*)calloc(1, sizeof(arraylist));
    list->current = 0;
    list->size = 1;
    list->string = (char*)calloc(8, sizeof(char));

    return list;
}

void add(arraylist *list, char *inp) {
    list->size = (list->current >= list->size) ? list->size * 2 : list->size;
    list->string = (int *)realloc(list->string, list->size * sizeof(char));

    list->string[list->current] = inp;
    list->current += 1;
}


int main()
{
    FILE *input = fopen("input.txt", "r");

    int N = 0;
    fscanf(input, "%d", &N);

    fclose(input);
    
    return 0;

}