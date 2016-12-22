#ifndef MAIN_H
#define MAIN_H
#include "structs.h"

SDL_Surface *errorImage, *screen, *wallVerticalImage, *wallHorizontalImage, *karelRightImage, *karelLeftImage, *karelUpImage, *karelDownImage, *beeperImage;
TTF_Font *font, *speedFont;
World world;
Karel karel, *self;
Input input;
Cursor cursor;

void init(char *);
void cleanup(void);
//void loadWorld(char *);
void initKarel(void);
SDL_Surface *loadImage(char *, int);
void draw(void);
void getInput(void);
void doCursor(void);

#endif /* MAIN_H */
