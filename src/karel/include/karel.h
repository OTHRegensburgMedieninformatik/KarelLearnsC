#ifndef KAREL_H
#define KAREL_H
#include "structs.h"
#include "world.h"
#if BUILD == LINUX_BUILD || BUILD == UNIX_BUILD
#include <stdio.h>
#endif // LINUX_BUILD

extern Karel karel;
extern World world;
#if BUILD == WINDOWS_BUILD || BUILD == UNIX_BUILD
extern SDL_Surface *errorImage, *karelRightImage, *karelLeftImage, *karelUpImage, *karelDownImage, *beeperImage;
void drawKarel(void);
#endif // WINDOWS_BUILD

void setup(void);
void run(void);
void move(void);
void turnLeft(void);
void pickBeeper(void);
void putBeeper(void);
int frontIsClear();
int frontIsBlocked();
int rightIsClear();
int rightIsBlocked();
int leftIsClear();
int leftIsBlocked();
int beepersInBag();
int noBeepersInBag();
int beepersPresent();
int noBeepersPresent();

int facingNorth();
int facingEast();
int facingSouth();
int facingWest();
int notFacingNorth();
int notFacingEast();
int notFacingSouth();
int notFacingWest();

#endif /* KAREL_H */
