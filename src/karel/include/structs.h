#ifndef WINDOWS_BUILD
#define WINDOWS_BUILD 0
#endif // WINDOWS_BUILD
#ifndef LINUX_BUILD
#define LINUX_BUILD 1
#endif // LINUX_BUILD
#ifndef UNIX_BUILD
#define UNIX_BUILD 2
#endif // LINUX_BUILD
#ifndef Null
#define Null 0
#endif // Null

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct WorldInformation
{
	int positionX, positionY;
	int beeper;
	int wallLeft, wallRight, wallTop, wallBottom;
	int set;
} WorldInformation;

typedef struct World
{
	char *filename;
	int goButtonX, goButtonY, resetButtonX, resetButtonY, speedButtonX, speedButtonY, speedPlusButtonX, speedPlusButtonY,
        speedMinusButtonX, speedMinusButtonY, errorX, errorY;
	int buttonWidth, buttonHeight, resetButtonWidth, resetButtonHeight, errorWidth, errorHeight, speedPlusButtonWidth, speedPlusButtonHeight,
        speedMinusButtonHeight, speedMinusButtonWidth;
	int karelStartX, karelStartY;
	int limitX, limitY;
	int startX, startY;
	int A_KAREL_STEP, angle;
	int beeperBag;
	int speed;
	WorldInformation worldInformation[100][100];
} World;

typedef struct Karel
{
	int width, height, x, y;
	int angle;
	int error;
} Karel;

#if BUILD == WINDOWS_BUILD || BUILD == UNIX_BUILD
typedef struct Cursor
{
    int x, y, tileID;
} Cursor;

typedef struct Input
{
	int left, right, up, down, add, remove;
	int previous, next, load, save;
	int mouseX, mouseY;
} Input;
#endif // WINDOWS_BUILD

#endif /* STRUCTS_H */

#include "config.h"

