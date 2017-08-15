#include "structs.h"
#if BUILD == UNIX_BUILD
#include "itoa.h"
#endif

extern SDL_Surface *screen;
extern World world;
TTF_Font *font, *speedFont;
