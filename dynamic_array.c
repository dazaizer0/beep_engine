#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* array;
size_t array_size = 32;

int main(int args, char *argv[]){
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    array = (int*) malloc(array_size * sizeof(int));

    if (array == NULL){
        printf("NULL");
    } else{
        for (int i = 0; i < array_size; ++i) {
            array[i] = i + 1;
        }

        printf("array: ");
        for (int i = 0; i < array_size; ++i) {
            printf("%d, ", array[i]);
        }
        printf("\n");
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    long long result = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
    printf("time: %lld\n", result);

    free(array);
    return 0;
}
