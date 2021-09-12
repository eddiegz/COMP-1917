// Assignment part 2     Slide
// slide.c
// This program is written by Eddie Gao
// Date 28/7
// I hereby declare that this submission is my own work and to the best of my knowledge 
// it contains no materials previously published or written by another person, or 
// substantial proportions of material which have been submitted for an assignment 
// at UNSW or any other educational institution, except where due acknowledgement 
// is made in the code.
// Include all the libaries that I am going to use later
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 15
#define EMPTY 0
#define STONE 1

// Declare the two functions that I am going to use later
// This is a function that will be used to print out the map
void print_map(int map[SIZE][SIZE], int laser_y);

// This is a function to check whether the conditions are met to win the game
bool checkwin(int map[SIZE][SIZE]);

// This is a function to check whether the conditions are met to lose the game
bool checklose(int map[SIZE][SIZE]);


int main (void) {
    // Initialize all the value in the map to empty
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
        // Initialize all the values in the map to 1
        map[row][column] = 1;
    }
    // Validate the build instructions by printing the map
    print_map(map, laser_y);

    // Loop until the game is over, the gameOver variable is used to store
    // the boolean value of whether the game has ended or not
    bool gameOver = false;
    while (!gameOver) {
        int command,direction;
        scanf("%d",&command);
        if (command == 1) {
            scanf("%d",&direction);
            if (direction == 1) {
                laser_y--;
            } else {
                laser_y++;
            }
            print_map(map,laser_y);
        }
        else if(command == 2) {
            // Set the laser line to zero
            for(int i = 0; i < SIZE; ++i) {
                map[laser_y][i] = 0;
            }
            print_map(map,laser_y);
            // Use the checkwin function to checkwin whether the game is to be ended
            if (checkwin(map)) {
                printf("Game Won!\n");
                gameOver = true;
            } else {
                gameOver = false;
            }
        }
        else if(command == 3) {
            if(checklose(map)) {  
                print_map(map,laser_y);
                printf("Game Lost!\n");
                gameOver = true;
            }
            else{
                for(int i = 0; i < SIZE; ++i) {
                    // Use a for loop to move those values leftward
                    for(int j = 0; j < SIZE; ++j) {
                        if (map[i][j] == 1 && j != 0) {
                            map[i][j-1] = 1;
                            map[i][j] = 0;
                        }
                    }
                }
                print_map(map,laser_y);
                if (checkwin(map)) {
                    printf("Game Won!\n");
                    gameOver = true;
                }
            }
        }
    }
    return 0;
}

// This function is used to print out the map
void print_map(int map[SIZE][SIZE], int laser_y) {
    // Loop through the map and print out the map and add a laser tag when required
    for (int i = 0; i < SIZE; ++i) {
        if (i != laser_y) {
            printf(" ");
        } else {
            printf(">");
        }
        for(int j = 0; j < SIZE; ++j) {
            printf(" %d",map[i][j]);
        }
        printf("\n");
    }
}

// This function is used to checkwin if the conditions have been met in order to finish the game
bool checkwin(int map[SIZE][SIZE]) {
    bool status=true;
    for(int i = 0; i < SIZE; ++i) {
        for(int j = 0; j < SIZE; ++j) {
            if(map[i][j] == 1) {
                status = false;
            }
        }
    }
    return status;
}

// This function is to check whether the conditions are met to determine the game is lost.
bool checklose(int map[SIZE][SIZE]) {
    bool lose = false;
    int index = 0;
    while(lose == false && index < SIZE) {
        if(map[index][0] == 1) {
            lose = true;
        }
        index++;
    }
    return lose;
}
