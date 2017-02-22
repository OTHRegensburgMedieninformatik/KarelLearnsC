#include "structs.h"

extern SDL_Surface *screen;
extern World world;

void drawString(char *text, int x, int y, TTF_Font *font, int centerX, int centerY, int isIndexLabel);
void drawError(void);

// TODO: ifndef
