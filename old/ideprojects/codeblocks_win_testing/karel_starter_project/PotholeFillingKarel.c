/*
 * File: PotholeFillingKarel.c
 * ------------------------------
 * The PotholeFillingKarel program puts a beeper into a pothole
 * on 2nd Avenue. This version of the program uses no
 * decomposition other than turnRight and turnAround,
 * which are implemented in this program.
 */

#include "karel.h"

void setup() {
    loadWorld("PotholeFillingSimple");
}

void run() {
    move();
    turnRight();
    move();
    putBeeper();
    turnAround();
    move();
    turnRight();
    move();
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
