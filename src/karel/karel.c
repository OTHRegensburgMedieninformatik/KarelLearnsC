#include "karel.h"
#if BUILD == WINDOWS_BUILD
#include "graphicsManager.h"
#endif // WINDOWS_BUILD
#if BUILD == LINUX_BUILD
#include <stdio.h>
#endif // LINUX_BUILD

#if BUILD == WINDOWS_BUILD
SDL_Surface* rotatedKarel;
void removeFromScreen();
#endif // WINDOWS_BUILD

void initKarel()
{
    karel.x = world.karelStartX;
    karel.y = world.karelStartY;

    #if BUILD == WINDOWS_BUILD
    karel.width = karelRightImage->w;
    karel.height = karelRightImage->h;
    #endif // WINDOWS_BUILD
    karel.error = 0;
}

void move()
{
    if(karel.error != 1)
    {
        if (world.speed < 1)
        {
            world.speed = 1;
        }
       #if BUILD == WINDOWS_BUILD
        int frameLimit = SDL_GetTicks() + DELAY / (world.speed * 2);
       #endif // WINDOWS_BUILD
        if (frontIsClear())
        {

            switch (world.angle)
            {

            case (DIRECTION_RIGHT):
                karel.x += 1;
                break;
            case (DIRECTION_UP):
                karel.y -= 1;
                break;
            case (DIRECTION_LEFT):
                karel.x -= 1;
                break;
            case (DIRECTION_DOWN):
                karel.y += 1;
                break;
            case (DIRECTION_RIGHT_360):
                karel.x += 1;
                break;
            }
       #if BUILD == WINDOWS_BUILD
            delay(frameLimit);
       #endif // WINDOWS_BUILD
        }
        else
        {
       karel.error = 1;
        }
    }
       #if BUILD == WINDOWS_BUILD
    draw();
       #endif // WINDOWS_BUILD
}

void turnLeft()
{
    if(karel.error != 1)
    {
        if (world.speed < 1)
        {
            world.speed = 1;
        }
        #if BUILD == WINDOWS_BUILD
            SDL_Delay(500/ (world.speed * 2));
        #endif // WINDOWS_BUILD
        if (world.angle == 360)
        {
            world.angle = 0;
        }
        world.angle += A_LEFT_TURN;
        #if BUILD == WINDOWS_BUILD
            draw();
            SDL_Delay(500/ (world.speed * 2));
        #endif // WINDOWS_BUILD
    }
}

int frontIsClear()
{

    int frontIsClear;

    switch (world.angle)
    {
    case (DIRECTION_RIGHT):

        if (karel.x + 1 != Null)
        {
            frontIsClear = world.worldInformation[karel.x][karel.y].wallRight
                           || world.worldInformation[karel.x + 1][karel.y].wallLeft;
        }
        else
        {
            frontIsClear = world.worldInformation[karel.x][karel.y].wallRight;
        }

        break;
    case (DIRECTION_UP):

        if (karel.y - 1 != Null)
        {
            frontIsClear = world.worldInformation[karel.x][karel.y].wallTop
                           || world.worldInformation[karel.x][karel.y - 1].wallBottom;
        }
        else
        {

            frontIsClear = world.worldInformation[karel.x][karel.y].wallTop;
        }
        break;
    case (DIRECTION_LEFT):

        if (karel.x - 1 != Null)
        {
            frontIsClear = world.worldInformation[karel.x][karel.y].wallLeft
                           || world.worldInformation[karel.x - 1][karel.y].wallRight;
        }
        else
        {

            frontIsClear = world.worldInformation[karel.x][karel.y].wallLeft;
        }

        break;
    case (DIRECTION_DOWN):
        if (karel.y + 1 != Null)
        {
            frontIsClear = world.worldInformation[karel.x][karel.y].wallBottom
                           || world.worldInformation[karel.x][karel.y + 1].wallTop;
        }
        else
        {

            frontIsClear = world.worldInformation[karel.x][karel.y].wallBottom;
        }
        break;
    case (DIRECTION_RIGHT_360):
        if (karel.x + 1 != Null)
        {
            frontIsClear = world.worldInformation[karel.x][karel.y].wallRight
                           || world.worldInformation[karel.x + 1][karel.y].wallLeft;
        }
        else
        {
            frontIsClear = world.worldInformation[karel.x][karel.y].wallRight;
        }
        break;
    }
    return !frontIsClear;
}

int frontIsBlocked()
{
    return !frontIsClear();
}

void pickBeeper()
{
    if(karel.error != 1)
    {
        if (world.worldInformation[karel.x][karel.y].beeper)
        {
            #if BUILD == WINDOWS_BUILD
                SDL_Delay(500/ ((world.speed == 0 ? 1 : world.speed) * 2));
            #endif // WINDOWS_BUILD
            world.beeperBag++;
            if (world.worldInformation[karel.x][karel.y].beeper >= INFINITE_BEEPERS)
                return;
            #if BUILD == WINDOWS_BUILD
                if ((--world.worldInformation[karel.x][karel.y].beeper) == 0)
                    removeFromScreen(ENTITY_BEEPER);
                draw();
                SDL_Delay(500/ ((world.speed == 0 ? 1 : world.speed) * 2));
            #endif // WINDOWS_BUILD
        }
        else
        {
            karel.error = 1;
            #if BUILD == WINDOWS_BUILD
                draw();
            #endif // WINDOWS_BUILD

        }
    }
}

void putBeeper()
{
    if(karel.error != 1)
    {
        if (world.beeperBag <= 0)
        {
            karel.error = 1;
            #if BUILD == WINDOWS_BUILD
                draw();
            #endif // WINDOWS_BUILD
            return;
        }
        #if BUILD == WINDOWS_BUILD
            SDL_Delay(500/ ((world.speed == 0 ? 1 : world.speed) * 2));
        #endif // WINDOWS_BUILD
        if (world.beeperBag >= INFINITE_BEEPERS)
        {
            if (world.worldInformation[karel.x][karel.y].beeper < INFINITE_BEEPERS)
            {
                world.worldInformation[karel.x][karel.y].beeper += 1;
            }
        }
        else
        {
            if (world.worldInformation[karel.x][karel.y].beeper >= INFINITE_BEEPERS)
            {
                world.beeperBag--;
            }
            else
            {
                world.beeperBag--;
                world.worldInformation[karel.x][karel.y].beeper += 1;
            }
        }
        #if BUILD == WINDOWS_BUILD
            draw();
            SDL_Delay(500/ ((world.speed == 0 ? 1 : world.speed) * 2));
        #endif // WINDOWS_BUILD
    }
}

int beepersInBag()
{
    return world.beeperBag > 0 ? 1 : 0;
}

int noBeepersInBag()
{
    return !beepersInBag();
}

int beepersPresent()
{
    return world.worldInformation[karel.x][karel.y].beeper ? 1 : 0;
}

int noBeepersPresent()
{
    return !beepersPresent();
}

int rightIsClear()
{

    int rightIsClear;

    switch (world.angle)
    {
    case (DIRECTION_RIGHT):

        if(karel.y + 1 != Null)
        {
            rightIsClear = world.worldInformation[karel.x][karel.y].wallBottom
                           || world.worldInformation[karel.x][karel.y + 1].wallTop;
        }
        else
        {
            rightIsClear = world.worldInformation[karel.x][karel.y].wallBottom;
        }


        break;
    case (DIRECTION_UP):

        if (karel.x + 1 != Null)
        {
            rightIsClear = world.worldInformation[karel.x][karel.y].wallRight
                           || world.worldInformation[karel.x + 1][karel.y].wallLeft;
        }
        else
        {
            rightIsClear = world.worldInformation[karel.x][karel.y].wallRight;
        }
        break;
    case (DIRECTION_LEFT):

        if (karel.y - 1 != Null)
        {
            rightIsClear = world.worldInformation[karel.x][karel.y].wallTop
                           || world.worldInformation[karel.x][karel.y - 1].wallBottom;
        }
        else
        {

            rightIsClear = world.worldInformation[karel.x][karel.y].wallTop;
        }

        break;
    case (DIRECTION_DOWN):
        if (karel.x - 1 != Null)
        {
            rightIsClear = world.worldInformation[karel.x][karel.y].wallLeft
                           || world.worldInformation[karel.x - 1][karel.y].wallRight;
        }
        else
        {
            rightIsClear = world.worldInformation[karel.x][karel.y].wallLeft;
        }
        break;
    case (DIRECTION_RIGHT_360):

        if(karel.y + 1 != Null)
        {
            rightIsClear = world.worldInformation[karel.x][karel.y].wallBottom
                           || world.worldInformation[karel.x][karel.y + 1].wallTop;
        }
        else
        {
            rightIsClear = world.worldInformation[karel.x][karel.y].wallBottom;
        }
        break;
    }
    return !rightIsClear;
}

int rightIsBlocked()
{
    return !rightIsClear();
}

int leftIsClear()
{
    int leftIsClear;

    switch (world.angle)
    {
    case (DIRECTION_RIGHT):

        if(karel.y - 1 != Null)
        {
            leftIsClear = world.worldInformation[karel.x][karel.y].wallTop
                          || world.worldInformation[karel.x][karel.y - 1].wallBottom;
        }
        else
        {
            leftIsClear = world.worldInformation[karel.x][karel.y].wallTop;
        }

        break;
    case (DIRECTION_UP):

        if (karel.x - 1 != Null)
        {
            leftIsClear = world.worldInformation[karel.x][karel.y].wallLeft
                          || world.worldInformation[karel.x - 1][karel.y].wallRight;
        }
        else
        {
            leftIsClear = world.worldInformation[karel.x][karel.y].wallLeft;
        }
        break;
    case (DIRECTION_LEFT):

        if (karel.y - 1 != Null)
        {
            leftIsClear = world.worldInformation[karel.x][karel.y].wallBottom
                          || world.worldInformation[karel.x][karel.y + 1].wallTop;
        }
        else
        {
            leftIsClear = world.worldInformation[karel.x][karel.y].wallBottom;
        }

        break;
    case (DIRECTION_DOWN):
        if (karel.x + 1 != Null)
        {
            leftIsClear = world.worldInformation[karel.x][karel.y].wallRight
                          || world.worldInformation[karel.x + 1][karel.y].wallLeft;
        }
        else
        {
            leftIsClear = world.worldInformation[karel.x][karel.y].wallRight;
        }
        break;
    case (DIRECTION_RIGHT_360):
        if(karel.y - 1 != Null)
        {
            leftIsClear = world.worldInformation[karel.x][karel.y].wallTop
                          || world.worldInformation[karel.x][karel.y - 1].wallBottom;
        }
        else
        {
            leftIsClear = world.worldInformation[karel.x][karel.y].wallTop;
        }

        break;
    }
    return !leftIsClear;
}

int leftIsBlocked()
{
    return !leftIsClear();
}

void drawError()
{
    #if BUILD == WINDOWS_BUILD
    if(karel.error == 1)
    {
        drawErrorImage(errorImage, 0, 0);
    }
    #endif // WINDOWS_BUILD
}

#if BUILD == WINDOWS_BUILD
void drawKarel()
{
    if(karelIsInitiated())
    {
        switch (world.angle)
        {
        case (DIRECTION_UP):
            drawKarelImage(karelUpImage, karel.y, karel.x, ENTITY_KAREL);
            break;
        case (DIRECTION_RIGHT):
            drawKarelImage(karelRightImage, karel.y, karel.x, ENTITY_KAREL);
            break;
        case (DIRECTION_LEFT):
            drawKarelImage(karelLeftImage, karel.y, karel.x, ENTITY_KAREL);
            break;
        case (DIRECTION_DOWN):
            drawKarelImage(karelDownImage, karel.y, karel.x, ENTITY_KAREL);
            break;
        default:
            drawKarelImage(karelRightImage, karel.y, karel.x, ENTITY_KAREL);
            break;
        }
    }
}
#endif // WINDOWS_BUILD

void removeFromScreen(int entity)
{
    switch (entity)
    {
    case ENTITY_BEEPER:
        world.worldInformation[karel.x][karel.y].beeper = 0;
        break;

    case ENTITY_KAREL:
        //world.worldInformation[karel.y][karel.x].
        break;
    default:
        break;
    }
}

int facingNorth()
{
    return (world.angle == DIRECTION_UP) ? 1 : 0;
}

int facingEast()
{
    return ((world.angle == DIRECTION_RIGHT) || (world.angle == DIRECTION_RIGHT_360)) ? 1 : 0;
}

int facingSouth()
{
    return (world.angle == DIRECTION_DOWN) ? 1 : 0;
}

int facingWest()
{
    return (world.angle == DIRECTION_LEFT) ? 1 : 0;
}

int notFacingNorth()
{
    return !facingNorth();
}

int notFacingEast()
{
    return !facingEast();
}

int notFacingSouth()
{
    return !facingSouth();
}

int notFacingWest()
{
    return !facingWest();
}
