#include "world.h"
#include "config.h"
#include "structs.h"

#if BUILD == WINDOWS_BUILD || BUILD == UNIX_BUILD
#include "draw.h"
#endif // WINDOWS_BUILD

#if BUILD == LINUX_BUILD
#include <stdio.h>
#endif // LINUX_BUILD

#if BUILD == WINDOWS_BUILD || BUILD == UNIX_BUILD
extern void drawBeeperImage(SDL_Surface *, int, int, int);
extern void drawPixelOnScreen(int positionX, int positionY, int entity,
                              int A_KAREL_STEP);
#endif // WINDOWS_BUILD
int readYvalue(char singleLine[150], int index);
int readXvalue(char singleLine[150], int index);
int readSpeedValue(char singleLine[150], int index);
int readBeeperBagValue(char singleLine[150], int index);
int wallForDirection(char singleLine[150], char *direction);
int karelForDirection(char singleLine[150], char *direction);
int readBeeperAmount(char singleLine[150]);
int space = 32;
int openParenthesis = 40; //asci code
int closingParenthesis = 41;//asci code
int zeroAsci = 48;
int oneAsci = 49;
int nineAsci = 57;
char comma = ',';
char point = '.';
char offset = '0';
char colon = ':';

void loadWorld(char *name)
{
    int x, y;

    FILE *filePointer;
    #if BUILD == WINDOWS_BUILD || BUILD == UNIX_BUILD
    char *path = "data/worlds/";
    #endif // WINDOWS_BUILD
    #if BUILD == LINUX_BUILD
    char *path = "/usr/include/data/worlds/";
    #endif // LINUX_BUILD
    char *ending = ".w";

    char *file = (char *) malloc(1 + strlen(path) + strlen(name) + strlen(ending));
    strcpy(file, path);
    strcat(file, name);
    strcat(file, ending);

    int MAX = 100;

    filePointer = fopen(file, "r");
    char singleLine[MAX];

    if (filePointer == Null)
    {
        printf("Failed to open world %s\n", name);
        exit(1);
    }

    int xIndex, yIndex;
    world.speed = KAREL_DEFAULT_SPEED;
    while (!feof(filePointer))
    {
        fgets(singleLine, MAX, filePointer);

        WorldInformation worldInformation;
        worldInformation.set = 0;

        if (strstr(singleLine, DIMENSION))
        {
            char *commaPointer = strchr(singleLine, comma);
            if (commaPointer)
            {
                int index = commaPointer - singleLine;
                yIndex = readYvalue(singleLine, index);
                xIndex = readXvalue(singleLine, index);

                world.limitY = yIndex;
                world.limitX = xIndex;

                int tileSizeX = (SCREEN_WIDTH - MENU_DISTANCE - 100) / xIndex;
                int tileSizeY = (SCREEN_HEIGHT - WINDOW_DISTANCE) / yIndex;

                if (tileSizeX <= tileSizeY)
                {
                    world.A_KAREL_STEP = tileSizeX;
                }
                else
                {
                    world.A_KAREL_STEP = tileSizeY;
                }
            }

        }
        else if (strstr(singleLine, BEEPER_BAG))
        {
            char *colonPointer = strchr(singleLine, colon);
                int index = colonPointer - singleLine;
            if (strstr(singleLine, INFINITE) || (strstr(singleLine, INFINITY)))
            {
                world.beeperBag = INFINITE_BEEPERS;
            }
            else if (colonPointer) {

                if(colonPointer)
                {
                    world.beeperBag = readBeeperBagValue(singleLine, index);
                }
            }
        }
        else if (strstr(singleLine, SPEED))
        {
                char *commaPointer = strchr(singleLine, comma);
                int commaIndex = commaPointer - singleLine;
                char *pointPointer = strchr(singleLine, point);
                int pointIndex = pointPointer - singleLine;

                if (commaPointer)
                {
                    world.speed = readSpeedValue(singleLine, commaIndex);
                }else if (pointPointer)
                {
                    world.speed = readSpeedValue(singleLine, pointIndex);
                } else {
                    world.speed = 1;

                }

        }
        else if (wallForDirection(singleLine, WEST_UPPER) || wallForDirection(singleLine, WEST_LOWER))
        {
            char *commaPointer = strchr(singleLine, comma);
            if (commaPointer)
            {
                int index = commaPointer - singleLine;

                yIndex = world.limitY - readYvalue(singleLine, index);
                xIndex = readXvalue(singleLine, index);
                worldInformation = world.worldInformation[xIndex][yIndex];

                worldInformation.wallLeft = 1;
                worldInformation.set = 1;

                world.worldInformation[xIndex][yIndex] = worldInformation;

            }

        }
        else if (wallForDirection(singleLine, EAST_UPPER) || wallForDirection(singleLine, EAST_LOWER))
        {
            char *commaPointer = strchr(singleLine, comma);
            if (commaPointer)
            {
                int index = commaPointer - singleLine;

                yIndex = world.limitY - readYvalue(singleLine, index);
                xIndex = readXvalue(singleLine, index);
                worldInformation = world.worldInformation[xIndex][yIndex];

                worldInformation.wallRight = 1;
                worldInformation.set = 1;
                world.worldInformation[xIndex][yIndex] = worldInformation;
            }

        }
        else if (wallForDirection(singleLine, NORTH_UPPER) || wallForDirection(singleLine, NORTH_LOWER))
        {
            char *commaPointer = strchr(singleLine, comma);
            if (commaPointer)
            {
                int index = commaPointer - singleLine;

                yIndex = world.limitY - readYvalue(singleLine, index);
                xIndex = readXvalue(singleLine, index);
                worldInformation = world.worldInformation[xIndex][yIndex];

                worldInformation.wallTop = 1;
                worldInformation.set = 1;
                world.worldInformation[xIndex][yIndex] = worldInformation;
            }

        }
        else if (wallForDirection(singleLine, SOUTH_UPPER) || wallForDirection(singleLine, SOUTH_LOWER))
        {
            char *commaPointer = strchr(singleLine, comma);
            if (commaPointer)
            {
                int index = commaPointer - singleLine;

                yIndex = world.limitY - readYvalue(singleLine, index);
                xIndex = readXvalue(singleLine, index);
                worldInformation = world.worldInformation[xIndex][yIndex];

                worldInformation.wallBottom = 1;
                worldInformation.set = 1;
                world.worldInformation[xIndex][yIndex] = worldInformation;
            }

        }
        else if (strstr(singleLine, BEEPER))
        {
            char *commaPointer = strchr(singleLine, comma);
            if (commaPointer)
            {
                int index = commaPointer - singleLine;

                yIndex = world.limitY - readYvalue(singleLine, index);
                xIndex = readXvalue(singleLine, index);
                worldInformation = world.worldInformation[xIndex][yIndex];

                worldInformation.beeper = readBeeperAmount(singleLine);

                worldInformation.set = 1;
                world.worldInformation[xIndex][yIndex] = worldInformation;
            }

        }
        else if (karelForDirection(singleLine, EAST_UPPER) || karelForDirection(singleLine, EAST_LOWER))
        {
            char *commaPointer = strchr(singleLine, comma);
            if (commaPointer)
            {
                int index = commaPointer - singleLine;
                yIndex = world.limitY - readYvalue(singleLine, index);
                xIndex = readXvalue(singleLine, index);
                world.karelStartY = yIndex;
                world.karelStartX = xIndex;
                world.angle = DIRECTION_RIGHT;
            }
        }
        else if (karelForDirection(singleLine, WEST_UPPER) || karelForDirection(singleLine, WEST_LOWER))
        {
            char *commaPointer = strchr(singleLine, comma);
            if (commaPointer)
            {
                int index = commaPointer - singleLine;
                yIndex = world.limitY - readYvalue(singleLine, index);
                xIndex = readXvalue(singleLine, index);
                world.karelStartY = yIndex;
                world.karelStartX = xIndex;
                world.angle = DIRECTION_LEFT;
            }
        }
        else if (karelForDirection(singleLine, SOUTH_UPPER) || karelForDirection(singleLine, SOUTH_LOWER))
        {
            char *commaPointer = strchr(singleLine, comma);
            if (commaPointer)
            {
                int index = commaPointer - singleLine;
                yIndex = world.limitY - readYvalue(singleLine, index);
                xIndex = readXvalue(singleLine, index);
                world.karelStartY = yIndex;
                world.karelStartX = xIndex;
                world.angle = DIRECTION_DOWN;
            }
        }
        else if (karelForDirection(singleLine, NORTH_UPPER) || karelForDirection(singleLine, NORTH_LOWER))
        {
            char *commaPointer = strchr(singleLine, comma);
            if (commaPointer)
            {
                int index = commaPointer - singleLine;
                yIndex = world.limitY - readYvalue(singleLine, index);
                xIndex = readXvalue(singleLine, index);
                world.karelStartY = yIndex;
                world.karelStartX = xIndex;
                world.angle = DIRECTION_UP;
            }
        }
    }

    fclose(filePointer);

    for (y = 0; y < world.limitY; y++)
    {
        for (x = 1; x <= world.limitX; x++)
        {

            WorldInformation worldInformation;
            worldInformation.wallBottom = 0;
            worldInformation.wallTop = 0;
            worldInformation.wallLeft = 0;
            worldInformation.wallRight = 0;
            if (y == 0)
            {
                worldInformation.wallTop = 1;
            }

            if (x == 1)
            {
                worldInformation.wallLeft = 1;
            }

            if (x == world.limitX)
            {
                worldInformation.wallRight = 1;
            }

            if (y == world.limitY - 1)
            {
                worldInformation.wallBottom = 1;
            }
            if (world.worldInformation[x][y].set == 0)
            {
                worldInformation.positionY = world.A_KAREL_STEP * y;
                worldInformation.positionX = world.A_KAREL_STEP * x;
                worldInformation.beeper = 0;
                worldInformation.set = 0;
                world.worldInformation[x][y] = worldInformation;
            }
            else
            {
                if (y == 0)
                {
                    world.worldInformation[x][y].wallTop = 1;
                }

                if (x == 1)
                {
                    world.worldInformation[x][y].wallLeft = 1;
                }

                if (x == world.limitX)
                {
                    world.worldInformation[x][y].wallRight = 1;
                }

                if (y == world.limitY - 1)
                {
                    world.worldInformation[x][y].wallBottom = 1;
                }
                world.worldInformation[x][y].positionY = world.A_KAREL_STEP * y;
                world.worldInformation[x][y].positionX = world.A_KAREL_STEP * x;
            }

        }
    }
    world.filename = name;
    #if BUILD == WINDOWS_BUILD
    loadImages();
    prepareKarel();
    #endif // WINDOWS_BUILD
}
int readXvalue(char singleLine[150], int index)
{
    if((int) singleLine[index - 2] == openParenthesis)
    {
        return (int) singleLine[index - 1] - offset;
    }
    else if((int) singleLine[index - 2] >= zeroAsci && (int) singleLine[index - 2] <= nineAsci)
    {
        int temp = (int) singleLine[index - 2] - offset;
        return temp*10 + (int) singleLine[index - 1] - offset;
    }
}

int readYvalue(char singleLine[150], int index)
{
    if((int) singleLine[index + 4] == closingParenthesis)
    {
        int temp = (int) singleLine[index + 2] - offset;
        return  (temp*10 + singleLine[index + 3] - offset);
    }
    else if((int) singleLine[index + 3] == closingParenthesis)
    {
        return (int) (singleLine[index + 2] - offset);
    }
}

int readBeeperBagValue(char singleLine[150], int index)
{

    if((int) singleLine[index + 5] >= zeroAsci && (int) singleLine[index + 5] <= nineAsci)
    {
        int temp = (int) singleLine[index + 2] - offset;
        int temp2 = (int) singleLine[index + 3] - offset;
        int temp3 = (int) singleLine[index + 4] - offset;
        return temp*1000+temp2*100+temp3*10 + ((int) singleLine[index + 5] - offset);
    }
    else if((int) singleLine[index + 4] >= zeroAsci && (int) singleLine[index + 4] <= nineAsci)
    {
        int temp = (int) singleLine[index + 2] - offset;
        int temp2 = (int) singleLine[index + 3] - offset;
        return temp*100+temp2*10 + ((int) singleLine[index + 4] - offset);
    }
    else if((int) singleLine[index + 3] >= zeroAsci && (int) singleLine[index + 3] <= nineAsci)
    {
        int temp = (int) singleLine[index + 2] - offset;
        return temp*10 + (int) singleLine[index + 3] - offset;
    }
    else if((int) singleLine[index + 2] >= zeroAsci && (int) singleLine[index + 2] <= nineAsci)
    {
        return (int) singleLine[index + 2] - offset;
    }
}

int readSpeedValue(char singleLine[150], int index)
{
    int temp;
    if((int) singleLine[index - 1] >= zeroAsci && (int) singleLine[index - 1] <= nineAsci)
    {
        temp = (int) singleLine[index - 1] - offset;
    }

    if((int) singleLine[index - 2] >= zeroAsci && (int) singleLine[index - 2] <= nineAsci)
    {
        temp += ((int) singleLine[index - 2] - offset) * 10;
    }

    return temp;
}

int readBeeperAmount(char singleLine[150])
{
    char *parenthesisPointer = strchr(singleLine, closingParenthesis);
    if(parenthesisPointer)
    {
        parenthesisPointer += 2;
        int amount = 0;
        do
        {
            amount = amount * 10;
            amount = amount + ((int)*parenthesisPointer) - offset;
            parenthesisPointer++;
        }
        while(((*parenthesisPointer) != '\n') && ((*parenthesisPointer) != '\r') && (parenthesisPointer-singleLine < 149));

        return amount;
    }
}



int wallForDirection(char singleLine[150], char *direction)
{
    return (strstr(singleLine, WALL) && (strstr(singleLine, direction)));
}

int karelForDirection(char singleLine[150], char *direction)
{
    return (strstr(singleLine, KAREL) && (strstr(singleLine, direction)));
}

#if BUILD == WINDOWS_BUILD || BUILD == UNIX_BUILD
void drawWorld()
{
    int row, column;
    //drawPixelOnScreen(0, 0, ENTITY_BORDER, world.A_KAREL_STEP);
    for (row = 0; row < world.limitY; row++)
    {
        for (column = 1; column <= world.limitX; column++)
        {

            drawPixelOnScreen(row, column, ENTITY_MARKER, world.A_KAREL_STEP);

            if (world.worldInformation[column][row].wallLeft)
            {
                drawPixelOnScreen(row, column, ENTITY_WALL_LEFT, world.A_KAREL_STEP);
            }
            if (world.worldInformation[column][row].wallRight)
            {
                drawPixelOnScreen(row, column, ENTITY_WALL_RIGHT, world.A_KAREL_STEP);
            }
            if (world.worldInformation[column][row].wallTop)
            {
                drawPixelOnScreen(row, column, ENTITY_WALL_TOP, world.A_KAREL_STEP);
            }
            if (world.worldInformation[column][row].wallBottom)
            {
                drawPixelOnScreen(row, column, ENTITY_WALL_BOTTOM,
                                  world.A_KAREL_STEP);
            }
            if (world.worldInformation[column][row].beeper)
            {
                drawBeeperImage(beeperImage, row, column, ENTITY_BEEPER);

                drawBeeperAmount(world.worldInformation[column][row]);
            }
            else
            {

            }
        }
    }
}


drawBeeperAmount(WorldInformation worldPart)
{
    if (worldPart.beeper > 1) //only draw, when more then one
    {
        char tmp[10];
        int xOffset = 0;

        if (worldPart.beeper < 10)
            xOffset = (-1) * FONT_SIZE*1/4;
        else if (worldPart.beeper < 100)
            xOffset = (-1) * FONT_SIZE/2;
        else if (worldPart.beeper < 1000)
            xOffset = (-1) * FONT_SIZE*3/4;

        if (worldPart.beeper >= INFINITE_BEEPERS)
        {
            tmp[0] = 'o';
            tmp[1] = 111;
            tmp[2] = '\0';
            xOffset = (-1) * FONT_SIZE/2;
        }
        else
            itoa(worldPart.beeper, tmp, 10);

        drawString(tmp,
                worldPart.positionX + MENU_DISTANCE + (world.A_KAREL_STEP/2) + xOffset,
                worldPart.positionY + WINDOW_DISTANCE + (world.A_KAREL_STEP/2) - FONT_SIZE*3/4,
                font, 0, 0, 1);
    }

}
#endif // WINDOWS_BUILD

