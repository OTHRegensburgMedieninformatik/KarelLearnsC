/*
 * File: BeeperCarryingKarel.c
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
    turnLeft();
    turnLeft();
    turnLeft();
    move();
    move();
    putBeeper();
    move();
}
