/*
 *
 * CAUTION: BUGGY!!!!!!
 *
*/


#include "karel.h"

void setup() {
    loadWorld("HugeCave");
}

void run() {
    moveIntoCave();
    collectStalagmites();
    climbUp();
    collectStalactites();
}

/*
 * Karel stands in the Tunnel towards the Cave
 *
 * pre-condition: Karel stands at the start of the Tunnel, facing east
 * post-condition: Karel stands at the start of the Cave, facing east
 *
 */

void moveIntoCave() {
    move();
    move();
}

/*
 * Karel collect the Stalagmites from the bottom
 *
 * pre-condition: Karel stands at the start of the Cave, facing east
 * post-condition: Karel stands at the right bottom of the Cave, facing east
 *
 */

void collectStalagmites() {
    while(frontIsClear()) {
        if(rightIsClear()) {
            turnRight();
            while(frontIsClear()) {
                move();
            }
            if(beepersPresent()) {
                turnAround();
                collect();
            }
            turnLeft();
        } else {
            move();
            if(rightIsBlocked()) {
                if(beepersPresent()) {
                    turnLeft();
                    collect();
                    turnLeft();
                }
            }
        }

    }
}

/*
 * Karel collects a Stalagmite or Stalactite
 *
 * pre-condition: Karel stands at the start of a Stalagmite or Stalactite, facing its direction
 * post-condition: Karel stands at the start of a Stalagmite or Stalactite, facing north or south
 *
 */

void collect() {
    pickBeeper();
    while(frontIsClear()) {
        move();
        if(beepersPresent()) {
            pickBeeper();
        } else {
            turnAround();
            while(frontIsClear()) {
                move();
            }
        }
    }
}

/*
 * Karel stands at the Start of the Cave
 *
 * pre-condition: Karel stands at the right bottom of the Cave, facing east
 * post-condition: Karel stands at the right top of the Cave, facing north
 *
 */

void climbUp() {
    turnLeft();
    while(frontIsClear()) {
        move();
    }
}

/*
 * Karel collects the Stalactites at the top
 *
 * pre-condition: Karel stands at the right top of the Cave, facing north
 * post-condition: Karel stands at the the start of the tunnel, facing south
 *
 */

void collectStalactites() {
    if(beepersPresent()) {
        turnAround();
        collect();
    }
    turnLeft();

    while(rightIsBlocked()) {
        if(frontIsBlocked()) {
            if(beepersPresent()) {
                turnLeft();
                collect();
                turnLeft();
            }
            turnLeft();
            while(rightIsBlocked()) {
                if(frontIsClear()) {
                    move();
                }
            }
            turnRight();
            if(frontIsClear()) {
                move();
            }
        } else {
            if(beepersPresent()) {
                turnLeft();
                collect();
                turnLeft();
            }
            if(frontIsClear()) {
                move();
            }
        }
    }
}

void turnAround() {
    turnLeft();
    turnLeft();
}

void turnRight() {
    turnLeft();
    turnLeft();
    turnLeft();
}
