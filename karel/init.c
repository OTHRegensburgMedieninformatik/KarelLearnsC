#include "init.h"

void init(char *title)
{

	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) < 0)
	{
		printf("Could not initialize SDL: %s\n", SDL_GetError());

		exit(1);
	}

	if (TTF_Init() < 0)
	{
	    printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());

	    exit(1);
	}

    const char* envvars = "SDL_VIDEO_WINDOW_POS=4,26";
    SDL_putenv(envvars);
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

	if (screen == NULL)
	{
		printf("Couldn't set screen mode: %s\n", SDL_GetError());

		exit(1);
	}

	SDL_FillRect(screen, NULL, 0xffffffff);
	SDL_Flip(screen);
	SDL_WM_SetCaption(title, NULL);

}

void cleanup()
{

	if (wallVerticalImage != NULL)
	{
		SDL_FreeSurface(wallVerticalImage);
	}
	if(font != NULL) {
		closeFont(font);
		TTF_Quit();
	}

	SDL_Quit();
}
