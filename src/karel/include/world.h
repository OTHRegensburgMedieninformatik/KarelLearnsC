#include "structs.h"
#if BUILD == LINUX_BUILD || BUILD == UNIX_BUILD
#include <stdio.h>
#endif // LINUX_BUILD
#if BUILD == UNIX_BUILD
#include "itoa.h"
#endif

extern World world;
extern WorldInformation worldInformation;
void loadWorld(char *name);
#if BUILD == WINDOWS_BUILD || BUILD == UNIX_BUILD
extern SDL_Surface *wallVerticalImage, *wallHorizontalImage, *beeperImage;
void drawWorld(void);
#endif
