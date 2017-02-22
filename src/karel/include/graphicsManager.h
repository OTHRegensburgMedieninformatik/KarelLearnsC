#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H
#include "structs.h"
#include "config.h"

extern SDL_Surface *screen;
extern World world;

void drawKarelImage(SDL_Surface *, int, int, int);
void drawErrorImage(SDL_Surface *, int, int);
void draw(void);
void delay(unsigned int);
int karelIsInitiated();

#endif /* GRAPHICSMANAGER_H */
