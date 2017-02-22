/*
/*
 * File: RoadRepairKarelGeneral.c
 * --------------------------
 * This version of the RoadRepairKarel class fills an
 * arbitrary sequence of potholes in a roadway.
 *
 */

#include "karel.h"


void setup() {
    loadWorld("PotholeFillingRoadUneven");
}

void run() {
    while (frontIsClear()) {
        checkForPothole();
        move();
    }
    checkForPothole();
}

/**
 * Checks for a pothole immediately beneath Karel's current
 * looking for a wall to the right. If a pothole exists,
 * Karel calls fillPothole to repair it.
 */
void checkForPothole() {
    if (rightIsClear()) {
        fillPothole();
    }
}
/**
 * Fills the pothole beneath Karel's current position by
 * placing a beeper on that corner. For this method to
 * work correctly, Karel must be facing east immediately
 * above the pothole. When execution is complete, Karel
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

