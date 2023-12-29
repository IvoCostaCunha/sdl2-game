#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"
#include "Asset2d.hpp"

#include <iostream>

Asset2d::Asset2d() {}

Asset2d::Asset2d(int x, int y, int w, int h, const char *pngFilePath, SDL_Renderer *renderer) : posx(x), posy(y), dimw(w), dimh(h)
{
  loadAssetTextures(pngFilePath, renderer);
  assetGameObj = createGameObj();

  auto p = std::make_pair(1, 3.14);
  std::cout << '(' << std::get<0>(p) << ", " << std::get<1>(p) << ")\n";
}

Asset2d::Asset2d(const Asset2d &asset2d) : posx(asset2d.posx), posy(asset2d.posy), dimw(asset2d.dimw), dimh(asset2d.dimh) {}

Asset2d::~Asset2d()
{
  std::cout << "Asset2d destructor called" << std::endl;
  SDL_DestroyTexture(currentTexture);

  for (auto &&item : assetTextures)
  {
    // std::cout << '1' << item.first << ' ' << item.second << std::endl;
    // delete &item.first; // FIXME: item.first isn't allocated, where is the char* then ?
    SDL_DestroyTexture(item.second);
  }
}

SDL_Rect *Asset2d::getAssetGameObj()
{
  return &assetGameObj;
}

SDL_Texture *Asset2d::getCurrentTexture()
{
  return currentTexture;
}

SDL_Rect Asset2d::createGameObj()
{
  assetGameObj.x = posx;
  assetGameObj.y = posy;
  assetGameObj.w = dimw;
  assetGameObj.h = dimh;
  SDL_QueryTexture(assetTextures["idle"], NULL, NULL, &assetGameObj.w, &assetGameObj.h);
  currentTexture = assetTextures["idle"];
  return assetGameObj;
}

void Asset2d::loadAssetTextures(const char *pngFilePath, SDL_Renderer *renderer)
{
  SDL_Surface *surfaceFromPng = IMG_Load(pngFilePath);
  assetTextures["idle"] = SDL_CreateTextureFromSurface(renderer, surfaceFromPng);
  SDL_FreeSurface(surfaceFromPng);
}