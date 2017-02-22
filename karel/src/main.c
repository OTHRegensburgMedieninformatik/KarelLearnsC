#include "main.h"
#include "karel.h"

int cleanUp(int err);
int karelIsInitiated();
void prepareKarel(void);
void initializations(void);
void loadImages(void);
extern TTF_Font *loadFont(char *, int);
int karelInitiated = 0;
unsigned int frameLimit = 0;
int isRunning = 0;

int main(int argc, char **argv) {

	initializations();
    draw();

	while (isRunning) {
		getInput();
		doCursor();
	}
	return cleanUp(0);

}

void initializations() {
	init("Karel the Robot");
	atexit(cleanup);
	font = loadFont("assets/open-sans/OpenSans-Regular.ttf", FONT_SIZE);
	speedFont = loadFont("assets/open-sans/OpenSans-Regular.ttf", SPEED_FONT_SIZE);
	isRunning = 1;
	frameLimit = SDL_GetTicks() + 16;
	setup();
	//loadWorld("data/worlds/DiamondMining1.w");
	//loadImages();
    //prepareKarel();
}

void prepareKarel() {
	if (!karelIsInitiated()) {
		initKarel();
	}
	karelInitiated = 1;
}

int karelIsInitiated() {
	return karelInitiated;
}

int cleanUp(int err) {

	SDL_Quit();

	return err;

}

void loadImages() {
    char *up_image;
    char *down_image;
    char *left_image;
    char *right_image;

    if(world.limitX >= 30 || world.limitY >= 30) {
        up_image = "assets/arrow_up.png";
        down_image = "assets/arrow_down.png";
        left_image = "assets/arrow_left.png";
        right_image = "assets/arrow_right.png";
    } else {
        up_image = "assets/karel_up.png";
        down_image = "assets/karel_down.png";
        left_image = "assets/karel_left.png";
        right_image = "assets/karel_right.png";
    }
	karelUpImage = loadImage(up_image, world.A_KAREL_STEP);
	if (karelUpImage == NULL) {
		exit(1);
	}

	karelDownImage = loadImage(down_image, world.A_KAREL_STEP);
	if (karelDownImage == NULL) {
		exit(1);
	}

	karelRightImage = loadImage(right_image, world.A_KAREL_STEP);
	if (karelRightImage == NULL) {
		exit(1);
	}

	karelLeftImage = loadImage(left_image, world.A_KAREL_STEP);
	if (karelLeftImage == NULL) {
		exit(1);
	}

	beeperImage = loadImage("assets/beeper.png", world.A_KAREL_STEP);
	if (beeperImage == NULL) {
		exit(1);
	}

	errorImage = loadImage("assets/error.png", 0);
	if (errorImage == NULL) {
        exit(1);
	}
}

