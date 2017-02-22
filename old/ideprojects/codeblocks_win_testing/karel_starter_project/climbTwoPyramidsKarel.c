/*
 * File: ClimbTwoPyramids.c
 *
 * In this program Karel climbs two pyramids.
 * Karel does not know how high the pyramids are or how wide his world is.
 *
 */

#include "karel.h"

void setup() {
    loadWorld("ClimbTwoPyramidsKarel");
}

void run() {
    int i;
    for (i = 0; i < 2; i++) {
        moveToNextPyramid();
        climbOverPyramid();
    }
    moveToRightWall();
}

/*
 * Karel moves to the next pyramid
 *
 * Pre-condition: Karel stands on bottom, facing east
 * Post-condition: Karel stands on bottom directly in front of a pyramid, facing east
 */
void moveToNextPyramid() {
    while (frontIsClear()) {
        move();
    }
}

/*
 * Climb over a pyramid
 *
 * Pre-condition: Karel stands directly in front of pyramid, facing east
 * Post-condition: Karel stands behind pyramid, facing east
 */
void climbOverPyramid() {
    ascendPyramid();
    descendPyramid();
}

/*
 * Ascend pyramid
 *
 * Pre-condition: Karel stands directly in front of pyramid, facing east
 * Post-condition: Karel stands on top step of pyramid, facing east
 */
void ascendPyramid() {
    while (frontIsBlocked()) {
        turnLeft();
        move();
        turnRight();
        move();
        checkAndPickBeeper();
    }
}

/*
 * Descend pyramid
 *
 * Pre-condition: Karel stands on top step of pyramid, facing east
 * Post-condition: Karel stands behind pyramid, facing east
 */
void descendPyramid() {
    move();
		turnRight();
		while (frontIsClear()) {
			move();
			checkAndPickBeeper();
			turnLeft();
			move();
			turnRight();
		}
		turnLeft();
}

/*
 * Check if a beeper is present and pick it up, if there is one
 */
void checkAndPickBeeper() {
    if (beepersPresent()) {
        pickBeeper();
    }
}

/*
 * Moves Karel, to the right wall of the world
 *
 * Pre-condition: Karel stands behind last pyramid, facing east
 * Post-condition: Karel stands at right bottom field of the world, facing
 * east
 */
void moveToRightWall() {
    moveToNextPyramid();
}

/*
 * Turns Karel 90 degrees to the right
 *
 *
 */

void turnRight() {
    turnLeft();
    turnLeft();
    turnLeft();
}
