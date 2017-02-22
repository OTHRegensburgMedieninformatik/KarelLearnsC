/*
 * File: damagedPillarKarel.c
 * -----------------------------------------
 *
 * In this program, Karel repairs broken pillars by
 * replacing holes with beepers.
 *
*/



#include "karel.h"

void setup()
{
    loadWorld("DamagedPillar2");
}

void run()
{

    while(frontIsClear())
    {
        repairPillar();
        moveToNextPillar();
    }
    repairPillar();
}

/*
 * Repair the pillar by adding beepers while moving up, then climb down
 *
 * pre-condition: Karel stands at bottom of pillar, facing east
 * post-condition: Karel stands at bottom of pillar, facing east
 *
 */
void repairPillar()
{
    repairPillarMovingUp();
    climbDown();
}

/*
 * Repair the pillar by adding beepers while moving up, then climb down
 *
 * pre-condition: Karel stands at bottom of pillar, facing east
 *post-condition: Karel stands at top of pillar, facing east
 *
 */
void repairPillarMovingUp()
{
    turnLeft();
    while (frontIsClear())
    {
        checkAndPutBeeper();
        move();
    }
    checkAndPutBeeper();
    turnRight();
}

/*
 * Puts a beeper, if no beeper is there
 *
 */

void checkAndPutBeeper()
{
    if(noBeepersPresent())
    {
        putBeeper();
    }
}

/*
 * Turn right
 */
void turnRight()
{
    turnLeft();
    turnLeft();
    turnLeft();
}

/*
 * Climb down a repaired pillar
 *
 * post-condition: Karel stands at top of pillar, facing east
 * pre-condition: Karel stands at bottom of repaired pillar, facing east
 *
 */
void climbDown()
{
    turnRight();
    while(frontIsClear())
    {
        move();
    }
    turnLeft();
}

/*
 * Move to the next column, after the current column was repaired
 *
 * pre-condition: Karel stands at bottom of repaired pillar, facing east
 * post-condition: Karel stands at bottom of next pillar, facing east
 *
 */

void moveToNextPillar()
{
    int i;
    for(i = 0; i < 4; i++)
    {
        move();
    }

}

