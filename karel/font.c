#include "font.h"

TTF_Font *loadFont(char *name, int size)
{

    TTF_Font *font = TTF_OpenFont(name, size);

    if (font == NULL)
    {
        printf("Failed to open Font %s: %s\n", name, TTF_GetError());

        exit(1);
    }

    return font;
}

void drawString(char *text, int x, int y, TTF_Font *font, int centerX, int centerY, int isIndexLabel)
{
    SDL_Rect dest;
    SDL_Surface *surface;
    SDL_Color foregroundColor, backgroundColor;

    foregroundColor.r = 0;
    foregroundColor.g = 0;
    foregroundColor.b = 0;

    if(isIndexLabel == 0)//transparent
    {
		backgroundColor.r = 211;
		backgroundColor.g = 211;
		backgroundColor.b = 211;
    }
    else if(isIndexLabel == 1)//grey
    {
 		/*backgroundColor.r = 179;
		backgroundColor.g = 179;
		backgroundColor.b = 179;*/
		backgroundColor.r = 0;
		backgroundColor.g = 0;
		backgroundColor.b = 0;
		backgroundColor.unused = 0;
    }
    else//white
    {
 		backgroundColor.r = 255;
		backgroundColor.g = 255;
		backgroundColor.b = 255;
    }

    surface = TTF_RenderUTF8_Shaded(font, text, foregroundColor, backgroundColor);

    if (surface == NULL)
    {
        printf("Couldn't create String %s: %s\n", text, SDL_GetError());

        return;
    }

    dest.x = x;
    dest.y = y;

    dest.w = surface->w;
    dest.h = surface->h;

    if(isIndexLabel == 1)
        SDL_SetColorKey(surface,
                        SDL_SRCCOLORKEY,
                        0);

    SDL_BlitSurface(surface, NULL, screen, &dest);

    SDL_FreeSurface(surface);
}

void closeFont(TTF_Font *font)
{

    if (font != NULL)
    {
        TTF_CloseFont(font);
    }
}
