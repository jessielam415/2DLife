#include <stdio.h>
#include <stdlib.h>

#include "life2D_helpers.h"


int main(int argc, char **argv) {

    if (argc != 4) {
        fprintf(stderr, "Usage: life2D rows cols states\n");
        return 1;
    }

    // TODO: Implement.
    int height = strtol(argv[1], NULL, 10);
    int width = strtol(argv[2], NULL, 10);
    int num_states = strtol(argv[3], NULL, 10);
    int integer;
    int arr[height * width];
    int index = 0;
    while ((((char) scanf("%d", &integer)) != EOF) && (index < height * width)) {
        arr[index] = integer;
        index++;
    }
    for (int i = 0; i < num_states; i++) {
        print_state(arr, height, width);
        update_state(arr, height, width);
    }
    return 0;
    
}
