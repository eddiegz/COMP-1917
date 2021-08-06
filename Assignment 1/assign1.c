// Assignment 1     Slide
// slide.c
// This program is written by Eddie Gao
// Date 28/7
// Include all the libaries that I am going to use later
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 15
#define EMPTY 0
#define STONE 1

// Declare the two functions that I am going to use later
void print_map(int map[SIZE][SIZE], int laser_y);

bool check(int map[SIZE][SIZE]);


int main (void) {
    int map[SIZE][SIZE] = {EMPTY};
    int laser_y = SIZE / 2;
    int block;
    // Build blocks in the map
    printf("How many blocks? ");
    scanf("%d",&block);
    printf("Enter blocks:\n");
    for (int i = 1; i <= block; ++i) {
        int row,column,vlaue;
        scanf("%d%d%d",&row,&column,&vlaue);
        map[row][column] = 1;
    }
    // Validate the build instructions by printing the map
    print_map(map, laser_y);

    // Loop until the game is over
    bool gameOver = false;
    while (!gameOver) {
        int command,direction;
        scanf("%d",&command);
        if (command == 1) {
            scanf("%d",&direction);
            if (direction == 1) {
                laser_y++;
            } else {
                laser_y--;
            }
            print_map(map,laser_y);
        }
        else if(command == 2) {
            for(int i = 0; i < SIZE; ++i){
                map[laser_y][i] = 0;
            }
            print_map(map,laser_y);
            if (check(map)) {
                printf("Game Won!\n");
                gameOver = true;
            } else {
                gameOver = false;
            }
        }
        else if(command == 3) {
            bool valid = true;
            for(int i = 0; i < SIZE; ++i){
                bool f1 = false,f2 = false;
                int start = 20,end = 0;
                for(int j = 0; j < SIZE; ++j){
                    if (map[i][j] == 1 && j != 0 && valid == true) {
                        map[i][j-1] = 1;
                        map[i][j] = 0;
                    }
                    if (map[i][j] == 1 && j == 0) {
                        valid = false;
                    }
                    
                }
            }
            print_map(map,laser_y);
            if (valid == false) {
                printf("Game Lost!\n");
                gameOver = true;
            }
            if (check(map)) {
                printf("Game Won!\n");
                gameOver = true;
            }
        }
    }
    return 0;
}

// This function is used to print out the map
void print_map(int map[SIZE][SIZE], int laser_y) {

    for (int i = 0; i < SIZE; ++i){
        if (i != laser_y){
            printf(" ");
        } else {
            printf(">");
        }
        for(int j = 0; j < SIZE; ++j){
            printf(" %d",map[i][j]);
        }
        printf("\n");
    }
}

//This function is used to check if the conditions have been met in order to finish the game
bool check(int map[SIZE][SIZE]){
    bool status=true;
    for(int i = 0;i < SIZE; ++i){
        for(int j = 0;j < SIZE; ++j){
            if(map[i][j] == 1){
                status = false;
            }
        }
    }
    return status;
}
