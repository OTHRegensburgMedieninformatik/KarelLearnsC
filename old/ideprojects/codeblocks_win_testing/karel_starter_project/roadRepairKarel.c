/*
/*
 * File: RoadRepairKarel.c
 * --------------------------
 * The RoadRepairKarel program fills a series of regularly
 * spaced potholes until Karel reaches the end of the roadway.
 *
 */

#include "karel.h"


void setup() {
    loadWorld("PotholeFillingRoad");
}

void run() {
    while (frontIsClear()) {
        move();
        fillPothole();
        move();
    }
}

/**
 * Fills the hole beneath Karel's current position by
 * placing a beeper in the hole. For this function to
 * work correctly, Karel must be facing east immediately
 * above the hole. When execution is complete, Karel
 * will have returned to the same square and will again
 * be facing east. This version of fillPothole checks to
 * see if there is already a beeper present before putting
 * a new one down.
 */
void fillPothole() {
    turnRight();
    move();
    if (noBeepersPresent()) {
        putBeeper();
    }
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

