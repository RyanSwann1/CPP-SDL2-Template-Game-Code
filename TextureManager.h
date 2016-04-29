#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "sdldeleter.h"
#include <map>
#include <string>
#include <memory>
#include <SDL.h>
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	void load(const std::string& path, const std::string& textureID);
	void draw(const float x, const float y, const int w, const int h, const std::string& textureID);

private:
	std::map<std::string, std::unique_ptr<SDL_Texture, sdldeleter>> m_textures;
};
#endif // !TEXTURE_MANAGER_H

