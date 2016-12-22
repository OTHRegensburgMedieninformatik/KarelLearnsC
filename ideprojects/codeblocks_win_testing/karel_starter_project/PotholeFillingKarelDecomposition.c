/*
 * File: PotholeFillingKarelDecomposition.c
 * ------------------------------
 * The PotholeFillingKarel program puts a beeper into a pothole
 * on 2nd Avenue. This version of the program decomposes
 * the problem so that it makes use of a fillPothole method.
 */

#include "karel.h"

void setup() {
    loadWorld("PotholeFillingSimple");
}

void run() {
    move();
    fillPothole();
    move();
}

/**
 * Fills the pothole beneath Karel's current position by
 * placing a beeper on that corner. For this function to
 * work correctly, Karel must be facing east immediately
 * above the pothole. When execution is complete, Karel
 * will have returned to the same square and will again
 * be facing east.
 */
 void fillPothole() {
    turnRight();
    move();
    putBeeper();
    turnAround();
    move();
    turnRight();
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

