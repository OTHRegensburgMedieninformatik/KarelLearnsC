#include "karel.h"

void setup() {
    loadWorld("BeeperPile");
}

void run() {
    move();
    doubleBeepers();
    moveBackward();
}

/*
 * pre-condition: Karel faces right (on beeper spot)
 * post-condition: Karel faces right (on beeper spot)
 */
void doubleBeepers() {
    while(beepersPresent()) {
        moveTwoBeepersToNextPile();
    }
    moveNextPileBack();
}

void moveTwoBeepersToNextPile() {
    pickBeeper();
    move();
    putBeeper();
    putBeeper();
    moveBackward();
}


/*
 * pre-condition: Karel faces right (on beeper spot)
 * post-condition: Karel faces right (on beeper spot)
 */
void moveNextPileBack() {
    move();
    while(beepersPresent()) {
        moveOneBeeperBack();
    }
    moveBackward();
}

/*
 * pre-condition: Karel faces right (on beeper spot)
 * post-condition: Karel faces right (on beeper spot)
 */
void moveOneBeeperBack() {
    pickBeeper();
    moveBackward();
    putBeeper();
    move();
}

void moveBackward() {
    turnAround();
    move();
    turnAround();
}

void turnAround() {
    turnLeft();
    turnLeft();
}



