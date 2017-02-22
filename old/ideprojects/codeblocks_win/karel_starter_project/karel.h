#ifndef KAREL_H
#define KAREL_H

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

void loadWorld(char *name);

#endif /* KAREL_H */
