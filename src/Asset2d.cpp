#include "SDL2/SDL_image.h"
#include "SDL2/SDL.h"
#include "Asset2d.hpp"

#include <iostream>

Asset2d::Asset2d() {}

Asset2d::Asset2d(std::string name): name(name) {}

Asset2d::Asset2d(std::string name, int32_t x, int32_t y, int32_t w, int32_t h, const char *pngFilePath, SDL_Renderer *renderer) : name(name)
{
  loadAssetTextures(pngFilePath, renderer);
  assetGameObj = createGameObj(x, y, w, h);
}

Asset2d::Asset2d(const Asset2d &asset2d){
  // TODO
  std::cout << asset2d.name << std::endl;
}

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

std::string Asset2d::getName()
{
  return name;
}

SDL_Rect Asset2d::createGameObj(int32_t x,int32_t y, int32_t w, int32_t h)
{
  assetGameObj.x = x;
  assetGameObj.y = y;
  assetGameObj.w = w;
  assetGameObj.h = h;
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