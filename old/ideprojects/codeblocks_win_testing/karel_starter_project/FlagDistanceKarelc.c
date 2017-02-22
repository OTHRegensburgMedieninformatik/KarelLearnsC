/*
 * File: FlafDistanceKarel.c
 * -----------------------------------------
 *
 * In this program, Karel measures the distance to a flag
 * and creates a pile of beepers equal to the distance from his
 * starting position to the flag.
 *
*/

#include "karel.h"

void setup() {
    loadWorld("flagDistance1");
}

void run() {
    if (frontIsClear()) {
        measureDistance();
    } else {
        stepUp();
    }
}

/*
 * Measures the distance between Karel and a flag
 *
 * Pre-condition: Karel stands on left edge of world facing east
 * Post-condition: Karel stands one field above starting position
 *
*/

void measureDistance() {
    runToFlag();
    turnAround();
    putBeeper();
    while (frontIsClear()) {
        moveBeeperPileAhead();
        putBeeper();
    }
    pickBeeper();
    turnAround();
    stepUp();
}

/*
 * Move a pile of beepers one field ahead
 * Pre-condition: Karel stands on beeper pile
 * Post-condition: Karel stands one field ahead of start position on moved pile
 */

void moveBeeperPileAhead() {
    while (beepersPresent()) {
        pickBeeper();
        placeOneBeeperAhead();
        moveOneFieldBack();
    }
     move();
}

void placeOneBeeperAhead() {
    move();
    putBeeper();
}

void moveOneFieldBack() {
    turnAround();
    move();
    turnAround();
}

/*
 * Run until Karel stand before the flag
*/
void runToFlag() {
    while (frontIsClear()) {
        move();
    }
}

void stepUp() {
    turnLeft();
    move();
}

void turnAround() {
    turnLeft();
    turnLeft();
}

