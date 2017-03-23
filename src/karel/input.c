#include "input.h"
#include "windows.h"

extern void load();

int isStarted = 0;
int goClicked() {
	return input.mouseX >= world.goButtonX
			&& input.mouseX <= world.goButtonX + world.buttonWidth
			&& input.mouseY >= world.goButtonY
			&& input.mouseY <= world.goButtonY + world.buttonHeight;
}

int resetClicked() {
	return input.mouseX >= world.resetButtonX
			&& input.mouseX <= world.resetButtonX + world.resetButtonWidth
			&& input.mouseY >= world.resetButtonY
			&& input.mouseY <= world.resetButtonY + world.resetButtonHeight;
}

int errorClicked() {
	return input.mouseX >= world.errorX
			&& input.mouseX <= world.errorX + world.errorWidth
			&& input.mouseY >= world.errorY
			&& input.mouseY <= world.errorY + world.errorHeight;
}

int plusSpeedClicked() {
    return input.mouseX >= world.speedPlusButtonX
            && input.mouseX <= world.speedPlusButtonX + world.speedPlusButtonWidth
            && input.mouseY >= world.speedPlusButtonY
            && input.mouseY <= world.speedPlusButtonY + world.speedPlusButtonHeight;
}

int minusSpeedClicked() {
    return input.mouseX >= world.speedMinusButtonX
            && input.mouseX <= world.speedMinusButtonX + world.speedMinusButtonWidth
            && input.mouseY >= world.speedMinusButtonY
            && input.mouseY <= world.speedMinusButtonY + world.speedMinusButtonHeight;
}



DWORD WINAPI runPointer ()
{
  run();
}
void getInput() {
	SDL_Event event;
	HANDLE runThread;
	DWORD wait;

	while (SDL_PollEvent(&event))
    {
		switch (event.type) {

		case SDL_QUIT:
			exit(0);
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				if (goClicked()) {
                    			if (isStarted == 0)
                    			{
                        			//run();
                        			runThread = CreateThread(Null, 0, runPointer, Null, 0, Null);
                    			}

					//isStarted = 1;
				}
		    		if(resetClicked()){
                    			loadWorld(world.filename);
                    			initKarel();
		    			draw();
				}
				if (errorClicked()) {
					exit(0);
				}
				if (plusSpeedClicked()) {
                    if (world.speed < 20)
                    {
                        world.speed++;
                        draw();
                    }
				}
                if (minusSpeedClicked()) {
                    if(world.speed > 1)
                    {
                        world.speed--;
                        draw();
                    }
                }

				input.add = 1;
				break;

			case SDL_BUTTON_RIGHT:
				input.remove = 1;
				break;

			default:
				break;
			}
			break;

		case SDL_MOUSEBUTTONUP:
			switch (event.button.button) {
			case SDL_BUTTON_LEFT:
				input.add = 0;
				break;

			case SDL_BUTTON_RIGHT:
				input.remove = 0;
				break;

			default:
				break;
			}
			break;
		}
	}

	/*
	 * 		get mouse coordinates
	 */

	SDL_GetMouseState(&input.mouseX, &input.mouseY);

}
