#include "structs.h"
#if BUILD == LINUX_BUILD
#include <stdio.h>
#endif // LINUX_BUILD

extern World world;
extern WorldInformation worldInformation;
void loadWorld(char *name);
#if BUILD == WINDOWS_BUILD
extern SDL_Surface *wallVerticalImage, *wallHorizontalImage, *beeperImage;
void drawWorld(void);
#endif
