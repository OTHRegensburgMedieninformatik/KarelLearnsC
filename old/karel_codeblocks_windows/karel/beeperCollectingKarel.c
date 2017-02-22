/*
 * File: BeeperCollectingKarel.c
 * --------------------------------
 * The BeeperCollectingKarel program collects all the beepers
 * in a series of vertical towers and deposits them at the
 * rightmost corner on 1st Street.
 *
 */

#include "karel.h"
#include "world.h"


void setup() {
    loadWorld("LivingRoom");
}

void run() {
    //collectAllBeepers();
    //dropAllBeepers();
    //returnHome();
    move();
    if(beepersPresent())
    {
        pickBeeper();
    }
    else
    {
        putBeeper();
    }
    move();
}

/*
 * Collects the beepers from every tower by moving along 1st
 * Street, calling collectOneTower at every corner. The
 * postcondition for this method is that Karel is in the
 * easternmost corner of 1st Street facing east.
 */
void collectAllBeepers() {
    while (frontIsClear()) {
        collectOneTower();
        move();
    }
    collectOneTower();
}

/**
* Collects the beepers in a single tower. When collectOneTower
* is called, Karel must be on 1st Street facing east. The
* postcondition for collectOneTower is that Karel must again
* be facing east on that same corner.
*/
void collectOneTower() {
    turnLeft();
    collectLineOfBeepers();
    turnAround();
    moveToWall();
    turnLeft();
}
/**
 * Collects a consecutive line of beepers. The end of the beeper
 * line is indicated by a corner that contains no beepers.
 */
void collectLineOfBeepers() {
    while (beepersPresent()) {
        pickBeeper();
        if (frontIsClear()) {
            move();
        }
    }
}
/**
 * Drops all the beepers on the current corner.
 */
void dropAllBeepers() {
    while (beepersInBag()) {
        putBeeper();
    }
}
/**
 * Returns Karel to its initial position at the corner of 1st
 * Avenue and 1st Street, facing east. The precondition for this
 * method is that Karel must be facing east somewhere on 1st
 * Street, which is true at the conclusion of collectAllBeepers.
 */
void returnHome() {
    turnAround();
    moveToWall();
    turnAround();
}

/**
 * Moves Karel forward until it is blocked by a wall.
 */
void moveToWall() {
    while (frontIsClear()) {
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

