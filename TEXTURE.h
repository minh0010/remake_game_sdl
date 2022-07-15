#pragma once

#include <iostream>
#include <string>

using namespace std;

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class TEXTURE
{
public:
	TEXTURE();
	
	~TEXTURE();
	
	bool Load_Texture_From_Picture(SDL_Renderer* screen, string path);

#if defined(SDL_TTF_MAJOR_VERSION)

	bool Load_Texture_From_Text(SDL_Renderer* screen, string Text);

#endif

	void Render_Texture_On_Screen(SDL_Renderer* screen);
	
	void free();

private:

	SDL_Texture* mTexture;
	int mWidth, mHeight;
};

static TEXTURE test;