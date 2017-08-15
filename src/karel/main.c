#include "main.h"
#include "karel.h"
#if BUILD == LINUX_BUILD || BUILD == UNIX_BUILD
#include <stdio.h>
#endif // LINUX_BUILD

#if BUILD == WINDOWS_BUILD || BUILD == UNIX_BUILD
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
	if (karelUpImage == Null) {
		exit(1);
	}

	karelDownImage = loadImage(down_image, world.A_KAREL_STEP);
	if (karelDownImage == Null) {
		exit(1);
	}

	karelRightImage = loadImage(right_image, world.A_KAREL_STEP);
	if (karelRightImage == Null) {
		exit(1);
	}

	karelLeftImage = loadImage(left_image, world.A_KAREL_STEP);
	if (karelLeftImage == Null) {
		exit(1);
	}

	beeperImage = loadImage("assets/beeper.png", world.A_KAREL_STEP);
	if (beeperImage == Null) {
		exit(1);
	}

	errorImage = loadImage("assets/error.png", 0);
	if (errorImage == Null) {
        exit(1);
	}
}
#endif // WINDOWS_BUILD

#if BUILD == LINUX_BUILD
void printFinalState()
{
	FILE *fp;
	int x, y;
	fp = fopen("output.txt","w");

	if(fp == Null)
	{
	  printf("Datei konnte nicht geoeffnet werden.\n");
	     }
	else
	{
	 for(x=0;x<100;x++)
	 {
		 for(y=0;y<100;y++)
		 {
			 if (world.worldInformation[x][y].beeper>0)
			 {
			 fprintf(fp,"Beeper: (%d, %d) %d\n",x,(world.limitY-y),world.worldInformation[x][y].beeper);
			 }
		 }
	 }

	 fprintf(fp, "Karel: (%d, %d) ",karel.x,(world.limitY-(karel.y)));

	 switch (world.angle)
	    	{

	    	 case (DIRECTION_RIGHT):
			 fprintf(fp, "east\n");
	    	 break;
	    	 case (DIRECTION_UP):
			 fprintf(fp, "north\n");
	    	 break;
	    	 case (DIRECTION_LEFT):
			 fprintf(fp, "west\n");
	    	 break;
	    	 case (DIRECTION_DOWN):
			 fprintf(fp, "south\n");
	    	 break;
	    	 case (DIRECTION_RIGHT_360):
			 fprintf(fp, "east\n");
	    	 break;
	    	}

	 fprintf(fp, "BeeperBag: %d\n", world.beeperBag);
      fprintf(fp, "Error: %d", karel.error);
	 fclose(fp);

	}
}


int main(int argc, char **argv)
	{

	setup();
	initKarel();
	run();
	printFinalState();
	return 0;

	}

#endif // LINUX_BUILD
