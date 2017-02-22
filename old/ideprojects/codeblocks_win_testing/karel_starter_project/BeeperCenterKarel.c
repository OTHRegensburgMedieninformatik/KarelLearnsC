#include "karel.h"

void setup() {
    loadWorld("FindBeeperCenter3");
}

void run() {
    putBeeperAtCenter();
}

void putBeeperAtCenter() {
    climbUpToRightWall();
    turnAround();
    climbDownToCenter();
    putBeeper();
}

void climbUpToRightWall() {
    while(frontIsClear()) {
        stepOneFieldUp();
        checkAndMoveOneStepRight();
        checkAndMoveOneStepRight();
    }

}

void checkAndMoveOneStepRight() {
    if(frontIsClear()) {
        move();
    }
}

void stepOneFieldUp() {
    turnLeft();
    move();
    turnRight();
}

void climbDownToCenter() {
    while(leftIsClear()) {
        stepOneFieldDown();
        move();
    }
}

void stepOneFieldDown() {
    turnLeft();
    move();
    turnRight();

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
