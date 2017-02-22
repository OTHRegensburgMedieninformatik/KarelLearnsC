/*
 * File: BeeperCarryingKarelRevised.c
 * -----------------------------------------
 *
 * In this program, Karel picks up a beeper from 1st Street and then
 * carries that beeper to the center of a ledge on 2nd Street.
 *
*/

#include "karel.h"

void setup() {
    loadWorld("BeeperPicking");
}

void run() {
    move();
    pickBeeper();
    move();
    turnLeft();
    move();
    turnRight();
    move();
    move();
    putBeeper();
    move();
}

/**
 * Turns Karel 90 degrees to the right.
 */
void turnRight() {
    turnLeft();
    turnLeft();
    turnLeft();
}
