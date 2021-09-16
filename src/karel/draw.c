#include "draw.h"
#include "world.h"
#include "karel.h"
#include "font.h"

void clearTheScreen(void);
void drawMenu(void);
void drawBeeperCounter(void);
void drawSpeed(void);

void draw() {
	clearTheScreen();

	drawMenu();

	drawBeeperCounter();

	drawSpeed();

	drawWorld();

	drawError();

	drawKarel();

	SDL_Flip(screen);

	SDL_Delay(1);
}

void drawMenu() {
	char los[4] = "go";
	char reset[7] = "reset";
	char plus[2] = "+";
	char minus[2] = "-";

    Uint32 buttonColor = SDL_MapRGB(screen->format, 211, 211, 211);
    Uint32 speedButtonColor = SDL_MapRGB(screen->format, 150, 150, 211);
	Uint32 borderColor = SDL_MapRGB(screen->format, 0, 0, 0);
	SDL_Rect buttonBackground, resetButtonBackground, speedButtonBackground, speedButtonPlusBackground, speedButtonMinusBackground;
	SDL_Rect buttonBorder, resetButtonBorder, speedButtonBorder, speedButtonPlusBorder, speedButtonMinusBorder;

	world.goButtonX = TILE_SIZE;
	world.goButtonY = 4 * TILE_SIZE;
	
	world.resetButtonX = TILE_SIZE;
	world.resetButtonY = 2 * TILE_SIZE;

	world.speedButtonX = TILE_SIZE + TILE_SIZE / 2;
	world.speedButtonY = 8 * TILE_SIZE;

    world.speedPlusButtonX = world.speedButtonX + 2 * TILE_SIZE;
	world.speedPlusButtonY = world.speedButtonY;

    world.speedMinusButtonX = world.speedButtonX - TILE_SIZE / 2;
    world.speedMinusButtonY = world.speedButtonY;
	
	buttonBackground.x = world.goButtonX;
	buttonBackground.y = world.goButtonY;
	buttonBackground.w = TILE_SIZE * 3;
	buttonBackground.h = 26;
	
	resetButtonBackground.x = world.resetButtonX;
	resetButtonBackground.y = world.resetButtonY;
	resetButtonBackground.w = TILE_SIZE * 3;
	resetButtonBackground.h = 26;

	speedButtonBackground.x = world.speedButtonX;
	speedButtonBackground.y = world.speedButtonY;
	speedButtonBackground.w = TILE_SIZE * 2;
	speedButtonBackground.h = 26;

    speedButtonPlusBackground.x = world.speedPlusButtonX;
    speedButtonPlusBackground.y = world.speedPlusButtonY;
	speedButtonPlusBackground.w = TILE_SIZE / 2;
	speedButtonPlusBackground.h = 26;

	speedButtonMinusBackground.x = world.speedMinusButtonX;
    speedButtonMinusBackground.y = world.speedMinusButtonY ;
	speedButtonMinusBackground.w = TILE_SIZE / 2;
	speedButtonMinusBackground.h = 26;

	buttonBorder.x = world.goButtonX - 4;
	buttonBorder.y = world.goButtonY - 4;
	buttonBorder.w = buttonBackground.w + 8;
	buttonBorder.h = buttonBackground.h + 8;
	
	resetButtonBorder.x = world.resetButtonX - 4;
	resetButtonBorder.y = world.resetButtonY - 4;
	resetButtonBorder.w = resetButtonBackground.w + 8;
	resetButtonBorder.h = resetButtonBackground.h + 8;

    speedButtonBorder.x = world.speedButtonX - 4;
	speedButtonBorder.y = world.speedButtonY - 4;
	speedButtonBorder.w = speedButtonBackground.w + 8;
	speedButtonBorder.h = speedButtonBackground.h + 8;

	speedButtonPlusBorder.x = world.speedPlusButtonX -4;
	speedButtonPlusBorder.y = world.speedPlusButtonY -4;
	speedButtonPlusBorder.w = speedButtonPlusBackground.w +8;
	speedButtonPlusBorder.h = speedButtonPlusBackground.h +8;

	speedButtonMinusBorder.x = world.speedMinusButtonX -4;
	speedButtonMinusBorder.y = world.speedMinusButtonY -4;
	speedButtonMinusBorder.w = speedButtonMinusBackground.w +8;
	speedButtonMinusBorder.h = speedButtonMinusBackground.h +8;

	world.buttonWidth = buttonBorder.w;
	world.buttonHeight = buttonBorder.h;
	
	world.resetButtonWidth = resetButtonBorder.w;
	world.resetButtonHeight = resetButtonBorder.h;

	world.speedPlusButtonWidth = speedButtonPlusBorder.w;
	world.speedPlusButtonHeight = speedButtonPlusBorder.h;

	world.speedMinusButtonWidth = speedButtonMinusBorder.w;
	world.speedMinusButtonHeight = speedButtonMinusBorder.h;
	
	SDL_FillRect(screen, &buttonBorder, borderColor);
	SDL_FillRect(screen, &buttonBackground, buttonColor);
	
	SDL_FillRect(screen, &resetButtonBorder, borderColor);
	SDL_FillRect(screen, &resetButtonBackground, buttonColor);

	SDL_FillRect(screen, &speedButtonBorder, borderColor);
	SDL_FillRect(screen, &speedButtonBackground, buttonColor);

    SDL_FillRect(screen, &speedButtonPlusBorder, borderColor);
	SDL_FillRect(screen, &speedButtonPlusBackground, buttonColor);

    SDL_FillRect(screen, &speedButtonMinusBorder, borderColor);
	SDL_FillRect(screen, &speedButtonMinusBackground, buttonColor);


	drawString(los, world.goButtonX + 80, world.goButtonY, font, 0, 0, 0);
	drawString(reset, world.resetButtonX + 80, world.resetButtonY, font, 0, 0, 0);
    drawString(plus, world.speedPlusButtonX + 12, world.speedPlusButtonY, font, 0, 0, 0);
    drawString(minus, world.speedMinusButtonX + 14, world.speedMinusButtonY, font, 0, 0, 0);

}


void drawBeeperCounter() {
	char temp[10];

	if (world.beeperBag < INFINITE_BEEPERS)
        itoa(world.beeperBag, temp, 10);
    else
    {
        temp[0] = 'o';
        temp[1] = 'o';
        temp[2] = '\0';
    }

    char dest[30];
	snprintf(dest, sizeof(dest), "Beeper(s) in Bag: %s", temp);

	drawString(dest, world.speedMinusButtonX, 6 * TILE_SIZE, font, 0, 0, 0);
}

void drawSpeed() {
    char* speed = "Speed: ";
	char tempSpeed[10];
	itoa(world.speed, tempSpeed, 10);

    char dest[30];

    strcpy( dest, speed );
    strcat( dest, tempSpeed );
    drawString(dest, world.speedButtonX + 40, world.speedButtonY + 4, speedFont, 0, 0, 0);
}

void delay(unsigned int frameLimit) {
	unsigned int ticks = SDL_GetTicks();

	if (frameLimit < ticks) {
		return;
	}

	if (frameLimit > ticks + DELAY) {
		SDL_Delay(DELAY);
	}

	else {
		SDL_Delay(frameLimit - ticks);
	}
}

void clearTheScreen() {
	SDL_FillRect(screen, NULL, 0xFFFFFF);
}
