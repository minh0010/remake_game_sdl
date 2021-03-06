#include "game_screen.h"

SCREEN::SCREEN()
{
	WINDOW = NULL;
	RENDERER = NULL;

	quit = false;
}

SCREEN::~SCREEN()
{
	SDL_DestroyWindow(WINDOW);
	WINDOW = NULL;

	SDL_DestroyRenderer(RENDERER);
	RENDERER = NULL;

	SDL_Quit();
}


bool SCREEN::INIT()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << SDL_Error;
		return false;
	}

	WINDOW = SDL_CreateWindow(GAME_NAME.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 700, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (WINDOW == NULL)
	{
		cout << SDL_Error;
		return false;
	}
	
	RENDERER = SDL_CreateRenderer(WINDOW, -1, SDL_RENDERER_ACCELERATED);
	if (RENDERER == NULL)
	{
		cout << string(60, '-') << '\n';
		cout << "SDL get fail\nCode: " << SDL_Error << '\n';
		cout << "Problem: somthing wrong with SDL_CreateRenderer\n";
		cout << string(60, '-') << '\n';
		return false;
	}

	int png_flags = IMG_INIT_PNG;
	if (!(IMG_Init(png_flags) & png_flags))
	{
		cout << SDL_Error;
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		cout << SDL_Error;
		return false;
	}

	if (TTF_Init() == -1)
	{
		cout << SDL_Error;
		return false;
	}

	return true;
}

bool SCREEN::LOAD_MEDIA()
{
	if (!test.Load_Texture_From_Picture(RENDERER, "GAME_TEXTURE/BACKGROUND/start_screen.png"))
	{
		cout << "Bug from: TEXTURE test\n";
		cout << string(60, '-');
	}
	return true;
}

void SCREEN::DISPLAY_SCREEN()
{
	SDL_Event e;

	while (!quit)
	{
		if (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		SDL_SetRenderDrawColor(RENDERER, 0,0,0,255);
		SDL_RenderClear(RENDERER);

		test.Render_Texture_On_Screen(RENDERER);

		SDL_RenderPresent(RENDERER);
	}
}
