#include <stdio.h>
#include <stdlib.h>


void print_state(int *board, int num_rows, int num_cols) {
    for (int i = 0; i < num_rows * num_cols; i++) {
        printf("%d", board[i]);
        if (((i + 1) % num_cols) == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void update_state(int *board, int num_rows, int num_cols) {
    // TODO: Implement.

    // make a copy of the original board before changes
    int board_copy[num_rows * num_cols];

    for (int i = 0; i < num_cols * num_rows; i++) {
        board_copy[i] = board[i];
    }

    for (int i = 0; i < num_rows * num_cols; i++) {
        // Not column edge case & not row edge case
        if  ((i >= num_cols) && (i < num_cols * num_rows - num_cols) && (i % num_cols != 0) && (i % num_cols != num_cols - 1)) {
                int num_neighbours = 0; 
                //Check for adjacent neighbours
                if (board_copy[i - 1] == 1) {
                    num_neighbours ++;
                } if (board_copy[i + 1] == 1) {
                    num_neighbours ++;
                //Check for neighbours directly or diagonally above
                } if (board_copy[i - num_cols] == 1) {
                    num_neighbours ++;
                } if (board_copy[i - num_cols - 1] == 1) {
                    num_neighbours ++;
                } if (board_copy[i - num_cols + 1] == 1) {
                    num_neighbours ++;
                }
                //Check for neighbours directly or diagonally below
                if (board_copy[i + num_cols] == 1) {
                    num_neighbours ++;
                } if (board_copy[i + num_cols - 1] == 1) {
                    num_neighbours ++;
                } if (board_copy[i + num_cols + 1] == 1) {
                    num_neighbours ++;
                }

                //If our cell is currently 0, we update it accordingly
                if (board_copy[i] == 0) {
                    if ((num_neighbours == 2) || (num_neighbours == 3)){
                        board[i] = 1;
                    } 
                }
                //If our cell is currently 1, we update it accordingly
                if (board_copy[i] == 1) {
                    if ((num_neighbours < 2) || (num_neighbours > 3)){
                        board[i] = 0;
                    }
                }
            }
        }
    }