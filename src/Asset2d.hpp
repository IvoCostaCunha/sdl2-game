#pragma once 

#include "SDL2/SDL.h"
#include "SDL2/SDL_audio.h"
#include <unordered_map>

class Asset2d
{
public:
  /**
   * Basic empty constructor
   */
  Asset2d();

  /**
   * Full constructor of Asset2d
   * @param *pngFilePath a pointer to the png containing all sprites for this asset
   * @param *renderer the associated SDL_Renderer
   */
  Asset2d(int32_t x, int32_t y, int32_t w, int32_t h, const char *ptrPngPathFile, SDL_Renderer *ptrRenderer);

  /**
   * Constructor used to copy this object
   */
  Asset2d(const Asset2d &asset2d);

  /**
   * Class destructor
   */
  ~Asset2d();

  /**
   * Returns a pointer to assetGameObj
   */
  SDL_Rect *getAssetGameObj();

  /**
   * Returns a pointers to the current SDL_Texture of the asset
   */
  SDL_Texture *getCurrentTexture();

  int32_t posx;
  int32_t posy;
  int32_t dimw;
  int32_t dimh;

private:
  std::unordered_map<const char *, SDL_Texture *> assetTextures;
  SDL_Rect assetGameObj;
  SDL_Texture *currentTexture;

  /**
   * Returns a SDL_Rect typedef that will be used by the renderer
   * @return an SDL_Rect that will be used as game object
   */
  SDL_Rect createGameObj();

  /**
   * (TODO) Cast all subimages of png file (each 25*25 pixels) and insert them in assetTextures
   * @param *pngFilePath a pointer to the png containing all sprites for this asset
   * @param *renderer the associated SDL_Renderer
   * @return 0 if no errors, -1 if errors
   */
  void loadAssetTextures(const char *pngFilePath, SDL_Renderer *renderer);
};