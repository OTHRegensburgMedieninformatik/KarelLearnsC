#include "karel.h"

void setup() {
    loadWorld("DiamondMining1");
}

void run() {
    while(frontIsClear()) {
        move();
        if(leftIsClear()) {
           turnRight();
           while(frontIsClear()) {
            move();
           }
        }
    }
}

/* pre-condition: karel stands over mine-tunnel, facing right
 * post-condition: Karel stands on field after mine-tunnel, facing right
 */

void emptyDiamondMine() {
    clearDownwardsTunnel();
    clearRightTunnel();
    clearLeftTunnel();
    climbUp();
}

//pre-condition: karel stands on top of tunnel, facing right
//post-condition: karel stands at bottom, facing right
void clearDownwardsTunnel() {
    turnRight();
    while(frontIsClear()) {
        checkAndPickBeeper();
        move();
    }
    checkAndPickBeeper();
    turnLeft();
}

//pre-condition: karel stands at bottom, facing right
//post-condition: karel stands at bottom, facing right
void clearRightTunnel() {
    while(frontIsClear()) {
        checkAndPickBeeper();
        move();
        checkAndPickBeeper();
    }
}

//pre-condition: karel stands at bottom left edge, facing right
//post-condition: karel stands on top, one field after tunnel, facing right
void climbUp() {
    while(leftIsBlocked()) {
        move();
    }
    turnLeft();
    move();
    while(rightIsBlocked()) {
        move();
    }
    turnRight();
    move();
}

//pre-condition: karel stands at bottom, facing right
//post-condition: karel stands at bottom left edge, facing right
void clearLeftTunnel() {
    turnAround();
    while(frontIsClear()) {
        move();
        checkAndPickBeeper();
    }
    checkAndPickBeeper();
    turnAround();

}

void turnRight() {
    turnLeft();
    turnLeft();
    turnLeft();
}

void turnAround() {
    turnLeft();
    turnLeft();
}

void checkAndPickBeeper() {
    if(beepersPresent()) {
        pickBeeper();
    }
}

