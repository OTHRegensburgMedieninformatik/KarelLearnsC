#include "cursor.h"

extern void drawImage(SDL_Surface *, int, int);
extern void loadWorld(char *);
extern void saveWorld(void);

void doCursor()
{
	cursor.x = input.mouseX;
	cursor.y = input.mouseY;
}

void drawCursor()
{
}
