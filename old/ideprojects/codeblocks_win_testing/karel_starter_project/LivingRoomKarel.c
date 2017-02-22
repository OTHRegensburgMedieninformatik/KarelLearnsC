/*
 * File: LivingRoomKarel.c
 * -----------------------------------------
 *
 * In this program, Karel simply climbs a cupboard and picks
 * a beeper on its way.
 * The goal is to demonstrate how to think top-down
 * and how to break down a program
 * into functions.
 *
*/

#include "karel.h"

void setup() {
    loadWorld("LivingRoom");
}

void run() {
    moveToCupboard();
    climbCupboard();
    moveToBeeper();
    pickBeeper();
    moveToWall();
}

/*
 * Move to the bottom of cupboard
 *
 * pre-condition: Karel stands at bottom, left corner, facing east
 * post-condition: Karel stands at bottom of cupboard, facing east
 */
void moveToCupboard() {
    move();
    move();
    move();
    move();
    move();
}

/*
 * Climb up side of cupboard
 *
 * pre-condition: karel stands at bottom of cupboard, facing east
 * post-condition: Karel stands at top of cupboard, one field left, facing east
 */
void climbCupboard() {
    turnLeft();
    move();
    move();
    move();
    turnRight();

}

void turnRight() {
    turnLeft();
    turnLeft();
    turnLeft();
}

/*
 * Move to where the beeper lies
 *
 * pre-condition: Karel stands at top of cupboard, one field left, facing east
 * post-condition: Karel stands at top of cupboard, on beeper spot,
 * facing east
 */
void moveToBeeper() {
    move();
    move();
}

/*
 * Move to right wall
 *
 * pre-condition: Karel stands on beeper spot, facing east
 * post-condition: Karel stands on top of cupbaord, directly before right wall, facing east
 */
void moveToWall() {
    move();
    move();
}

