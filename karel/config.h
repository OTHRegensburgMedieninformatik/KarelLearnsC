#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
//#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#include <errno.h>

#define WALL "Wall"
#define WEST_LOWER "west"
#define NORTH_LOWER "north"
#define EAST_LOWER "east"
#define SOUTH_LOWER "south"
#define WEST_UPPER "West"
#define NORTH_UPPER "North"
#define EAST_UPPER "East"
#define SOUTH_UPPER "South"
#define DIMENSION "Dimension"
#define BEEPER "Beeper"
#define KAREL "Karel"
#define BEEPER_BAG "BeeperBag"
#define SPEED "Speed"
#define ONE_WALL "1Wall"
#define ONE_BEEPER "1Beeper"
#define KAREL "Karel"
#define SOUTH_BEEPER_BAG "SouthBeeperBag"
#define EAST_SPEED "EastSpeed"
#define ONE_WALL "1Wall"
#define ONE_BEEPER "1Beeper"
#define INFINITE "INFINITE"
#define INFINITY "INFINITY"

#define INFINITE_BEEPERS 1000

#define IS_X 1
#define IS_Y 1

#define FONT_SIZE 16
#define SPEED_FONT_SIZE 12

#define WINDOW_DISTANCE 32
#define MENU_DISTANCE 256
#define BLANK_TILE 0
#define TILE_SIZE 64

#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 640

#define KAREL_DEFAULT_SPEED 1
#define A_LEFT_TURN 90

#define DIRECTION_RIGHT 0
#define DIRECTION_UP 90
#define DIRECTION_LEFT 180
#define DIRECTION_DOWN 270
#define DIRECTION_RIGHT_360 360

#define KAREL_WIDTH 64
#define KAREL_HEIGHT 64
#define BEEPER_WIDTH 32
#define BEEPER_HEIGHT 32

#define WALL_WIDTH 64
#define WALL_HEIGHT 64
#define DELAY 512

#define SET_NOTHING 0
#define SET_WALL_VERTICAL 1
#define SET_BEEPER 2
#define SET_WALL_HORIZONTAL 3

#define NOT_TRANSPARENT 0
#define TRANSPARENT 1

#define TRANS_R 0
#define TRANS_G 0
#define TRANS_B 0

#define ENTITY_BEEPER 10
#define ENTITY_WALL_LEFT 11
#define ENTITY_WALL_RIGHT 12
#define ENTITY_WALL_TOP 13
#define ENTITY_WALL_BOTTOM 14
#define ENTITY_KAREL 15
#define ENTITY_MARKER 16
#define ENTITY_BORDER 17




