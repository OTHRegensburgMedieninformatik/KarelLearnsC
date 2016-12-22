/*
 * File: MazeRunningKarel.c
 * --------------------------------
 * In this program, Karel can solve a maze
 * using the right-hand rule.
 *
 */

#include "karel.h"


void setup() {
    loadWorld("Maze");
}

void run() {
    while (noBeepersPresent()) {
        turnRight();
        while (frontIsBlocked()) {
            turnLeft();
        }
        move();
    }
}

/**
 * Turns Karel 90 degrees to the right.
 */
void turnRight() {
    turnLeft();
    turnLeft();
    turnLeft();
}

/**
 * Turns Karel 180 degrees around.
 */
void turnAround() {
    turnLeft();
    turnLeft();
}

