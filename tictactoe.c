#include <stdio.h>
#include <stdbool.h>

void print_board(int grid[]){
    printf("\n");
    printf("%c | %c | %c\n", grid[0], grid[1], grid[2]);
    printf("- + - + -\n");
    printf("%c | %c | %c\n", grid[3], grid[4], grid[5]);
    printf("- + - + -\n");
    printf("%c | %c | %c\n", grid[6], grid[7], grid[8]);
}

void win(int player, bool winner, int grid[]){
    print_board(grid);
    if (winner){
        printf("Player %d is the winner\n", player);

    } else {
        printf("Match draw\n");
    }
}

int main(){
    bool winner = false;
    int count = 0;
    int grid[9];
    int player, pos_counter, index;
    int sign;

    // iterates through grid
    for (int i = 0; i < 9; ++i){
        grid[i] = ' ';
    }

    while(count < 9 && winner != true){
        pos_counter = 0;

        // print board
        print_board(grid);
    
        if (count % 2 == 0){
            sign = 'X';
            player = 1;
        } else {
            sign = 'O';
            player = 2;
        }

        printf("Move for player %d: \n", player);
        printf("Please enter a number from 1 to 9\n");

        scanf("%d", &index);

        if (index < 1 || index > 9){
            printf("ERROR: please enter a number from 1 to 9\n");
            continue;
        }

        if (grid[index - 1] == 'X' || grid[index - 1] == 'O'){
            printf("ERROR: please entered a space that is unoccupied\n");
            continue;
        }

        grid[index - 1] = sign;
        ++count;

        // check winner in rows
        for (int j = 0; j < 9; ++j){
            if (j % 3 == 0){
                pos_counter = 0;
            }
            if (grid[j] == sign){
                ++pos_counter;
            }
            if (pos_counter == 3){
                winner = true;
                win(player, winner, grid);
            }
        }

        pos_counter = 0;

        // check winner in columns
        for (int k = 0; k < 3; ++k){
            for (int m = k; m <= k + 6; m += 3){
                if (grid[m] == sign){
                    ++pos_counter;
                }
            }
            if (pos_counter == 3){
                winner = true;
                
            }
            pos_counter = 0;
        }

        // check winner in diagonals
        if ((grid[0] == sign && grid[4] == sign && grid[8] == sign) || (grid[2] == sign && grid[4] == sign && grid[6] == sign)){
            winner = true;
            win(player, winner, grid);
        }
    }
}

