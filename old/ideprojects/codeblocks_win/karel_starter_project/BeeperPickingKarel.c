/*
 * File: BeeperPickingKarel.c
 * -----------------------------------------
 *
 * This is a simple Karel program that defines a setup and a run function.
 *
 * The setup function loads Karel's world.
 *
 * The run function contains three commands.
 * These commands cause Karel to move forward one step, pick up
 * a beeper, and then move forward another step to the next corner.
 *
*/

#include "karel.h"

void setup() {
    loadWorld("BeeperPicking");
}

void run() {
    move();
    //pickBeeper();
    move();
    turnLeft();
}



