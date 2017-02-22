#include "karel.h"

void setup() {
    loadWorld("placeFlag");
}

void run() {
    getFlag();
    placeFlagAndMoveBack();
}


/**
 * Moving towards the Flag and picking it up
 *
 * pre-condition: Karel stands at the left bottom of the world, facing east
 * post-condition: Karel stands on the top of the Deposit, facing east
 */

void getFlag() {
    moveToTower();
    climbOverTower();
    moveToDeposit();
    climbOnDeposit();
    pickUpFlag();
}

/**
 * Moving towards the Flag and picking it up
 *
 * pre-condition: Karel stands on the top of the Deposit, facing east
 * post-condition: Karel stands of the left bottom of the world, facing west
 */

void placeFlagAndMoveBack() {
    climbDownDeposit();
    moveBackToTower();
    climbUpTower();
    placeFlag();
    climbDownTower();
    moveToStart();
}

/**
 * Moving towards the Tower
 *
 * pre-condition: Karel stands of the left bottom of the world, facing east
 * post-condition: Karel stands of the left bottom of the tower, facing east
 */

void moveToTower() {
    move();
    move();
}

/**
 * Moving over the Tower
 *
 * pre-condition: Karel stands of the left bottom of the tower, facing east
 * post-condition: Karel stands of the right bottom of the tower, facing
 * east
 */

void climbOverTower() {
    climbUpOnTower();
    climbDownFromTower();
}

/**
 *
 * Climbing up the tower
 *
 * pre-condition: Karel stands of the left bottom of the tower, facing east
 * post-condition: Karel stands on the top of the tower, facing east
 */

void climbUpOnTower() {
    turnLeft();
    move();
    move();
    move();
    move();
    turnRight();
    move();
}

/**
 *
 * Climbing down the tower
 *
 * pre-condition: Karel stands on the top of the tower, facing east
 * post-condition: Karel stands of the right bottom of the tower, facing
 * east
 */

void climbDownFromTower() {
    move();
    turnRight();
    move();
    move();
    move();
    move();
    turnLeft();
}

/**
 *
 * Moving towards the Deposit
 *
 * pre-condition: Karel stands of the right bottom of the tower, facing east
 * post-condition: Karel stands at the bottom left of the Deposit, facing
 * east
 */

void moveToDeposit() {
    move();
    move();
}

/**
 *
 * Climbing up the Deposit
 *
 * pre-condition: Karel stands at the bottom left of the Deposit, facing
 * east post-condition: Karel stands at the top of the Deposit, facing east
 */

void climbOnDeposit() {
    turnLeft();
    move();
    turnRight();
    move();
    turnLeft();
    move();
    turnRight();
    move();
    turnLeft();
    move();
    turnRight();
    move();
}

/**
 *
 * Picking up the Flag
 *
 * pre-condition: Karel stands at the top of the Deposit, facing east
 * post-condition: Karel stands at the top of the Deposit, facing east
 */

void pickUpFlag() {
    pickBeeper();
}

/**
 *
 * Climbing down the Deposit
 *
 * pre-condition: Karel stands at the top of the Deposit, facing east
 * post-condition: Karel stands at the left bottom of the Deposit, facing
 * west
 */

void climbDownDeposit() {
    turnLeft();
    turnLeft();
    move();
    turnLeft();
    move();
    turnRight();
    move();
    turnLeft();
    move();
    turnRight();
    move();
    turnLeft();
    move();
    turnRight();
}

/**
 *
 * Moving towards the Tower
 *
 * pre-condition: Karel stands at the left bottom of the Deposit, facing
 * west post-condition: Karel stands at the right bottom of the Tower,
 * facing west
 */

void moveBackToTower() {
    move();
    move();
}

/**
 * Climbing on the Tower
 *
 * pre-condition: Karel stands at the right bottom of the Tower, facing west
 * post-condition: Karel stands at the top of the Tower, facing west
 */

void climbUpTower() {
    turnRight();
    move();
    move();
    move();
    move();
    turnLeft();
    move();
}

/**
 *
 * Placing the Flag
 *
 * pre-condition: Karel stands at the top of the Tower, facing west
 * post-condition: Karel stands at the top of the Tower, facing west
 */

void placeFlag() {
    putBeeper();
}

/**
 * Climbing down the Tower
 *
 * pre-condition: Karel stands at the top of the Tower, facing west
 * post-condition: Karel stands at the left bottom of the Tower, facing west
 */

void climbDownTower() {
    move();
    turnLeft();
    move();
    move();
    move();
    move();
    turnRight();
}

/**
 * Moving to the Starting point
 *
 * pre-condition: Karel stands at the left bottom of the Tower, facing west
 * post-condition: Karel stands at the bottom left of the world, facing west
 */

void moveToStart() {
    move();
    move();
}

void turnRight() {
    turnLeft();
    turnLeft();
    turnLeft();
}

