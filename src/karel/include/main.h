#ifndef MAIN_H
#define MAIN_H
#include "structs.h"

#if BUILD == WINDOWS_BUILD
SDL_Surface *errorImage, *screen, *wallVerticalImage, *wallHorizontalImage, *karelRightImage, *karelLeftImage, *karelUpImage, *karelDownImage, *beeperImage;
TTF_Font *font, *speedFont;
Input input;
Cursor cursor;
#endif // WINDOWS_BUILD

World world;
Karel karel, *self;

void initKarel(void);

#if BUILD == WINDOWS_BUILD
void init(char *);
void cleanup(void);
SDL_Surface *loadImage(char *, int);
void draw(void);
void getInput(void);
void doCursor(void);
#endif // WINDOWS_BUILD

#if BUILD == LINUX_BUILD
void loadWorld(char *);
#endif // LINUX_BUILD

#endif /* MAIN_H */
