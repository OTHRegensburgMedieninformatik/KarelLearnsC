#include "karel.h"


void setup() {
    loadWorld("SteepSteepleChase");
}

void run() {
    int i;
    for (i = 0; i < 14; i++) {
        if (frontIsClear()) {
            move();
        } else {
            jumpOverHurdle();
        }
    }
}

/*
     * move to next field by jumping over a hurdle
     *
     * pre-condition: karel stands in front of hurdle, facing east
     * post-condition: karel stands behind hurdle, facing east
     */

void jumpOverHurdle() {
    ascendHurdle();
    move();
    descendHurdle();
}

/*
 * climb a hurdle
 *
 * pre-condition: karel stands in front of hurdle, facing east
 * post-condition: karel stands on top of hurdle, facing east
 */

void ascendHurdle() {
    turnLeft();
    while (rightIsBlocked()) {
        move();
    }
    turnRight();
}

/*
 * descend from top of hurdle
 *
 * pre-condition: karel stands on top of hurdle, facing east
 * post-condition: karel stands on bottom, behind hurdle, facing east
 */

void descendHurdle() {
    turnRight();
    moveToWall();
    turnLeft();
}

/* Moves Karel until he hits a wall
* pre-condition: none
* post-condition: Facing first wall in whichever direction Karel was facing previously
*/
void moveToWall() {
    while (frontIsClear()) {
        move();
    }
}

/* turn Karel right
 * pre-condition: none
 * post-condition: Karel has turned 90 degrees to the right
 */
void turnRight() {
    turnLeft();
    turnLeft();
    turnLeft();
}



