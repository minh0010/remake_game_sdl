#include "TEXTURE.h"

TEXTURE::TEXTURE()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

TEXTURE::~TEXTURE()
{
	free();
}

bool TEXTURE::Load_Texture_From_Picture(SDL_Renderer* screen, string path)
{
	free();

	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << string(60, '-') << '\n';
		cout << "SDL get fail\nCode: " << SDL_Error << '\n';
		cout << "Problem: can found any file, please check file path\n";
		return false;
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);
		if (newTexture == NULL)
		{
			cout << string(60, '-') << '\n';
			cout << "SDL get fail\nCode: " << SDL_Error << '\n';
			cout << "Problem: can not create texture from surface\n";
			return false;
		}
		else
		{
			mTexture = newTexture;
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;

			SDL_FreeSurface(loadedSurface);
		}
	}
	
	return mTexture != NULL;
}

#if defined(SDL_TTF_MAJOR_VERSION)

bool TEXTURE::Load_Texture_From_Text(SDL_Renderer* screen, string Text)
{
	free();
	return true;
}

#endif

void TEXTURE::Render_Texture_On_Screen(SDL_Renderer* screen)
{
	SDL_Rect renderQuad = { 0,0,mWidth, mHeight };
	SDL_RenderCopy(screen, mTexture, &renderQuad, NULL);
}

void TEXTURE::free()
{
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;

		mWidth = 0;
		mHeight = 0;
	}
}