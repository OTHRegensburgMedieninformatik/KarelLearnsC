
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
    //OK - Karel hits left outer wall - ERROR shown
    //turnLeft();
    //turnLeft();
    //move();

    // NOT OK - karel hits pyramid wall, error not shown
    move();
    move();
    move();
    move();
    move();
}
