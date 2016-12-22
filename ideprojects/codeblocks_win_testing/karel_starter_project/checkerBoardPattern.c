#include "karel.h"

void setup() {
    loadWorld("20x20");
}

void run() {
    while (leftIsClear()) {
        fillRow();
        runBacktoStartofRow();
        stepUpOneRow();
        checkForBeeperBeneath();
    }
    fillRow();
}

void fillRow() {
    putBeeper();
    while(frontIsClear()) {
        move();
        if(frontIsClear()) {
            move();
            putBeeper();
        }
    }
}

void runBacktoStartofRow() {
    turnAround();
    while(frontIsClear()) {
        move();
    }
    turnAround();
}

void stepUpOneRow() {
    turnLeft();
    move();
    turnRight();
}

void checkForBeeperBeneath() {
    turnRight();
    move();
    turnLeft();
    if (beepersPresent()) {
        move();
    }
    stepUpOneRow();
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
