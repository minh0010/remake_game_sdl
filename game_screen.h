#pragma once

#include <iostream>

using namespace std;

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <sdl_mixer.h>

const string GAME_NAME = "FUNIKI";

class SCREEN
{
public:
	SCREEN();
	~SCREEN();

	bool INIT();

	bool LOAD_MEDIA();

	void DISPLAY_SCREEN();

private:
	SDL_Window* WINDOW;
	SDL_Renderer* RENDERER;

	bool quit;
};


static SCREEN GAME_SCREEN;