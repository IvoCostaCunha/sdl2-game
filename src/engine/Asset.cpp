#include "SDL2/SDL_image.h"
#include "Asset.hpp"

class Asset
{
private:
  SDL_Surface *texture;

  int SDLloadPng(char *filepath)
  {
    SDL_Surface *img = IMG_Load(filepath);
    texture = img;
    return 0;
  }
};