#include "karel.h"
#include "graphicsManager.h"

SDL_Surface* rotatedKarel;
void removeFromScreen();
int error = 0;

void initKarel()
{

    karel.x = world.karelStartX;
    karel.y = world.karelStartY;

    karel.width = karelRightImage->w;
    karel.height = karelRightImage->h;
}

void move()
{
    if(error != 1)
    {
        if (world.speed < 1)
        {
            world.speed = 1;
        }

        int frameLimit = SDL_GetTicks() + DELAY / (world.speed * 2);

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

            delay(frameLimit);

        }
        else
        {
            error = 1;
            //SDL_Quit();
        }
    }

    draw();

}

void turnLeft()
{
    if(error != 1)
    {
        if (world.speed < 1)
        {
            world.speed = 1;
        }
        SDL_Delay(500/ (world.speed * 2));
        if (world.angle == 360)
        {
            world.angle = 0;
        }
        world.angle += A_LEFT_TURN;
        draw();
        SDL_Delay(500/ (world.speed * 2));
    }
}

int frontIsClear()
{

    int frontIsClear;

    switch (world.angle)
    {
    case (DIRECTION_RIGHT):

        if (karel.x + 1 != NULL)
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

        if (karel.y - 1 != NULL)
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

        if (karel.x - 1 != NULL)
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
        if (karel.y + 1 != NULL)
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
        if (karel.x + 1 != NULL)
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
    if(error != 1)
    {
        if (world.worldInformation[karel.x][karel.y].beeper)
        {
            SDL_Delay(500/ ((world.speed == 0 ? 1 : world.speed) * 2));
            world.beeperBag++;
            if (world.worldInformation[karel.x][karel.y].beeper >= INFINITE_BEEPERS)
                return;

            if ((--world.worldInformation[karel.x][karel.y].beeper) == 0)
                removeFromScreen(ENTITY_BEEPER);
            draw();
            SDL_Delay(500/ ((world.speed == 0 ? 1 : world.speed) * 2));
        }
        else
        {
            error = 1;
        }
    }
}

void putBeeper()
{
    if(error != 1)
    {
        if (world.beeperBag <= 0)
        {
            error = 1;
            return;
        }

        SDL_Delay(500/ ((world.speed == 0 ? 1 : world.speed) * 2));
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
        draw();
        SDL_Delay(500/ ((world.speed == 0 ? 1 : world.speed) * 2));
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

        if(karel.y + 1 != NULL)
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

        if (karel.x + 1 != NULL)
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

        if (karel.y - 1 != NULL)
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
        if (karel.x - 1 != NULL)
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

        if(karel.y + 1 != NULL)
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
//    int rightIsClear;
//    if (karel.x + 1 != NULL)
//    {
//        rightIsClear = world.worldInformation[karel.x][karel.y].wallRight
//                       || world.worldInformation[karel.x + 1][karel.y].wallLeft;
//    }
//    else
//    {
//
//        rightIsClear = world.worldInformation[karel.x][karel.y].wallRight;
//    }
//    return !rightIsClear;
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

        if(karel.y - 1 != NULL)
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

        if (karel.x - 1 != NULL)
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

        if (karel.y - 1 != NULL)
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
        if (karel.x + 1 != NULL)
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
        if(karel.y - 1 != NULL)
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

//    if (karel.x - 1 != NULL)
//    {
//        leftIsClear = world.worldInformation[karel.x][karel.y].wallLeft
//                      || world.worldInformation[karel.x - 1][karel.y].wallRight;
//    }
//    else
//    {
//
//        leftIsClear = world.worldInformation[karel.x][karel.y].wallLeft;
//    }
//    return !leftIsClear;
}

int leftIsBlocked()
{
    return !leftIsClear();
}

void drawError()
{
    if(error)
    {
        drawErrorImage(errorImage, 0, 0);
    }
}

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
