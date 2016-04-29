#include "TextureManager.h"
#include "Game.h"
#include <SDL_image.h>
#include <assert.h>


TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
}

void TextureManager::load(const std::string& path, const std::string& textureID)
{
	std::unique_ptr<SDL_Surface, sdldeleter> surface(IMG_Load(path.c_str()));
	assert(surface != nullptr);
	std::unique_ptr<SDL_Surface, sdldeleter> optimizedSurface(SDL_ConvertSurface(surface.get(), Game::instance()->getWindowSurface()->format, 0));
	assert(optimizedSurface != nullptr);
	std::unique_ptr<SDL_Texture, sdldeleter> texture(SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), optimizedSurface.get()));
	assert(texture != nullptr);

	m_textures[textureID] = std::move(texture);
}


void TextureManager::draw(const float x, const float y, const int w, const int h, const std::string & textureID)
{
	int textW = 0;
	int textH = 0;
	SDL_QueryTexture(&*m_textures[textureID], nullptr, nullptr, &textW, &textH);
	SDL_Rect srcRct;
	srcRct.x = 0;
	srcRct.y = 0;
	srcRct.w = textW;
	srcRct.h = textH;
	SDL_Rect dstRct;
	dstRct.x = x;
	dstRct.y = y;
	dstRct.w = w;
	dstRct.h = h;
	SDL_RenderCopy(Game::instance()->getRenderer(), &*m_textures[textureID], &srcRct, &dstRct);
}

