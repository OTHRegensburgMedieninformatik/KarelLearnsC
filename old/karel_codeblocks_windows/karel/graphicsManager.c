#include "graphicsManager.h"
SDL_Surface* SDL_ScaleSurface(SDL_Surface* Surface, Uint16 Width, Uint16 Height);
void DrawPixel( SDL_Surface *surface, Sint16 x, Sint16 y, Uint32 pixel );
Uint32 ReadPixel(SDL_Surface* Source, Sint16 X, Sint16 Y);

SDL_Surface *loadImage(char *name, int karelStep)
{

    SDL_Surface *temp = IMG_Load(name);
    SDL_Surface *image;

    if (temp == NULL)
    {
        printf("Failed to load image %s\n", name);

        return NULL;
    }

    int width = karelStep;
    int height = karelStep;
    image = SDL_DisplayFormatAlpha(temp);
    if (karelStep != 0)
    {
        image = SDL_ScaleSurface(image, width, height);
    }

    SDL_FreeSurface(temp);

    if (image == NULL)
    {
        printf("Failed to convert image %s to native format\n", name);

        return NULL;
    }

    return image;
}

void drawKarelImage(SDL_Surface *image, int y, int x, int entity)
{
    SDL_Rect dest;

    dest.x = world.worldInformation[x][y].positionX + MENU_DISTANCE;
    dest.y = world.worldInformation[x][y].positionY + WINDOW_DISTANCE;
    dest.w = image->w;
    dest.h = image->h;

    SDL_BlitSurface(image, NULL, screen, &dest);

}

void drawErrorImage(SDL_Surface *image, int y, int x)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    dest.w = image->w;
    dest.h = image->h;
    world.errorWidth = image->w;
    world.errorHeight = image->h;
    world.errorX = x;
    world.errorY = y;
    SDL_BlitSurface(image, NULL, screen, &dest);
}

SDL_Surface *SDL_ScaleSurface(SDL_Surface *Surface, Uint16 Width, Uint16 Height)
{
    if(!Surface || !Width || !Height)
        return 0;

    SDL_Surface *scaledSurface = SDL_CreateRGBSurface(Surface->flags, Width, Height, Surface->format->BitsPerPixel,
                                 Surface->format->Rmask, Surface->format->Gmask, Surface->format->Bmask, Surface->format->Amask);

    double stretch_factor_x = ((double)(Width)  / (double)(Surface->w));
    double stretch_factor_y = ((double)(Height) / (double)(Surface->h));
    Sint32 y, x, o_y, o_x;
    for(y = 0; y < Surface->h; y++) //Run across all Y pixels.
        for(x = 0; x < Surface->w; x++) //Run across all X pixels.
            for(o_y = 0; o_y < stretch_factor_y; ++o_y) //Draw _stretch_factor_y pixels for each Y pixel.
                for(o_x = 0; o_x < stretch_factor_x; ++o_x) //Draw _stretch_factor_x pixels for each X pixel.
                    DrawPixel(scaledSurface, (Sint32)(stretch_factor_x * x) + o_x,
                              (Sint32)(stretch_factor_y * y) + o_y, ReadPixel(Surface, x, y));


    return scaledSurface;
}
Uint32 ReadPixel( SDL_Surface *surface, Sint16 x, Sint16 y )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;

    //Get the requested pixel
    return pixels[ ( y * surface->w ) + x ];
}

void DrawPixel( SDL_Surface *surface, Sint16 x, Sint16 y, Uint32 pixel )
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)surface->pixels;

    //Set the pixel
    pixels[ ( y * surface->w ) + x ] = pixel;
}

void drawBeeperImage(SDL_Surface *image, int y, int x, int entity, int A_KAREL_STEP)
{
    SDL_Rect dest;

    dest.x = world.worldInformation[x][y].positionX + MENU_DISTANCE;
    dest.y = world.worldInformation[x][y].positionY + WINDOW_DISTANCE;
    dest.w = image->w;
    dest.h = image->h;


    SDL_BlitSurface(image, NULL, screen, &dest);

}

void drawPixelOnScreen(int positionY, int positionX, int entity, int A_KAREL_STEP)
{

    Uint32 color = SDL_MapRGB(screen->format, 0, 0, 0);
    SDL_Rect rect;

    switch (entity)
    {
    case (ENTITY_BORDER):
        rect.x = MENU_DISTANCE + A_KAREL_STEP;
        rect.y = WINDOW_DISTANCE;
        rect.w = world.limitX * A_KAREL_STEP;
        rect.h = 2;
        break;
    case (ENTITY_MARKER):
        rect.x = MENU_DISTANCE + (A_KAREL_STEP / 2) + positionX * A_KAREL_STEP;
        rect.y = WINDOW_DISTANCE + (A_KAREL_STEP / 2)+ positionY * A_KAREL_STEP;
        rect.w = 2;
        rect.h = 2;
        break;

    case (ENTITY_WALL_LEFT):
        rect.x = world.worldInformation[positionX][positionY].positionX + MENU_DISTANCE;
        rect.y = world.worldInformation[positionX][positionY].positionY + WINDOW_DISTANCE;
        rect.w = 3;
        rect.h = A_KAREL_STEP + 3;
        break;

    case (ENTITY_WALL_TOP):
        rect.x = world.worldInformation[positionX][positionY].positionX + MENU_DISTANCE;
        rect.y = world.worldInformation[positionX][positionY].positionY + WINDOW_DISTANCE;
        rect.w = A_KAREL_STEP;
        rect.h = 3;
        break;

    case (ENTITY_WALL_BOTTOM):
        rect.x = world.worldInformation[positionX][positionY].positionX + MENU_DISTANCE;
        rect.y = world.worldInformation[positionX][positionY].positionY + A_KAREL_STEP
                 + WINDOW_DISTANCE;
        rect.w = A_KAREL_STEP;
        rect.h = 3;
        break;

    case (ENTITY_WALL_RIGHT):
        rect.x = world.worldInformation[positionX][positionY].positionX + MENU_DISTANCE
                 + A_KAREL_STEP;
        rect.y = world.worldInformation[positionX][positionY].positionY + WINDOW_DISTANCE;
        rect.w = 3;
        rect.h = A_KAREL_STEP + 3;
        break;
    }
    SDL_FillRect(screen, &rect, color);
}

