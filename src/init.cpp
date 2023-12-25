#include <iostream>
#include <memory>
#include <ctime>
#include <unistd.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include "Asset2d.hpp"

// Heap = pointeur => plus lent mais plus grande quantité
// Stack = non pointeur => plus rapide moins de place
class Asset
{
public:
  Asset() {}
  Asset(int x, int y, int w, int h, const char *ptrFilepath1, const char *ptrFilepath2, SDL_Renderer *renderer) : posx(x), posy(y), dimw(w), dimh(h)
  {
    SDL_Surface *img = IMG_Load(ptrFilepath1);
    SDL_Surface *img2 = IMG_Load(ptrFilepath2);
    textures[0] = SDL_CreateTextureFromSurface(renderer, img);
    textures[1] = SDL_CreateTextureFromSurface(renderer, img2);
    SDL_FreeSurface(img);
    SDL_FreeSurface(img2);
    int *ptrPosx = &posx;
    int *ptrPosy = &posy;
    int *ptrDimw = &dimw;
    int *ptrDimh = &dimh;
    assetRect.x = *ptrPosx;
    assetRect.y = *ptrPosy;
    assetRect.w = *ptrDimw;
    assetRect.h = *ptrDimh;

    currentTexture = textures[0];

    SDL_QueryTexture(currentTexture, NULL, NULL, &assetRect.w, &assetRect.h);
  }

  Asset(const Asset &asset) : posx(asset.posx), posy(asset.posy), dimw(asset.dimw), dimh(asset.dimh) {}

  int posx;
  int posy;
  int dimw;
  int dimh;

  SDL_Rect assetRect;
  SDL_Texture *textures[2];
  SDL_Texture *currentTexture;

  void changeTexture()
  {
    currentTexture == textures[0] ? currentTexture = textures[1] : currentTexture = textures[0];
  }

  void jump(){
    // TODO with jump sprite
  }
};

int main(int argc, char *argv[])
{

#ifdef DEBUG
  std::cout << "DEBUG MODE" << std::endl;
  std::cout << "argc: " << argc << std::endl;
  for (int x = 0; x < argc; x++)
  {
    std::cout << "argv: " << argv[x] << ' ';
  }
  std::cout << std::endl;
#endif

  bool running = true;

  int r = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
  IMG_Init(IMG_INIT_PNG);

  if (r < 0)
  {
    printf("Cannot SDL_Init() (%s)\n", SDL_GetError());
    return EXIT_FAILURE;
  }

  SDL_Window *ptrWindow = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN);

  if (ptrWindow == nullptr)
  {
    std::cout << "Could not initialize SDL window\n"
              << SDL_GetError() << std::endl;
    SDL_Quit();
    return EXIT_FAILURE;
  }

  // -1 means SDL chooses automaticaly the graphical driver
  SDL_Renderer *renderer = SDL_CreateRenderer(ptrWindow, -1, SDL_RENDERER_SOFTWARE);
  // SDL_Renderer *renderer = SDL_CreateRenderer(ptrWindow, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC);

  if (renderer == nullptr)
  {
    std::cout << "Could not initialize SDL renderer\n"
              << SDL_GetError() << std::endl;
    SDL_DestroyWindow(ptrWindow);
    SDL_Quit();
    return EXIT_FAILURE;
  }
  // char a[10];
  // scanf("%s", a);
  // printf("Hello world\n");

  SDL_Surface *ptrWindowSurface = SDL_GetWindowSurface(ptrWindow);

  if (ptrWindowSurface == nullptr)
  {
    std::cout << "Could not initialize SDL window surface\n"
              << SDL_GetError() << std::endl;
    SDL_DestroyWindow(ptrWindow);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return EXIT_FAILURE;
  }

  // Asset *player = new Asset(0, 0, 200, 300, "media/sprite.png");
  // ptr unique au scope
  std::unique_ptr<Asset> player(new Asset(50, 50, 250, 10, "media/player_sprite_1.png", "media/player_sprite_2.png", renderer));

  // ptr partagable
  // std::shared_ptr<Asset> playerSharedPtr(player.get()->get()); si on veut accepter a un geteur d'un poiteur
  // std::shared_ptr<Asset> playerSharedPtr(player.get());

  // SDL_Rect playerRect = {player->posx, player->posy, player->diml, player->dimh};
  // SDL_BlitSurface(player->texture[0], NULL, ptrWindowSurface, &playerRect);

  // SDL_Point point{300, 300};

  // SDL_Rect playerRectangle;
  // playerRectangle.x = 50;
  // playerRectangle.y = 50;
  // SDL_QueryTexture(player->texture[0], NULL, NULL, &playerRectangle.w, &playerRectangle.h);

  // std::time_t t = std::time(nullptr);
  // sleep(5);
  // std::time_t t2 = std::time(nullptr);
  // std::cout << "time " << t2-t << std::endl;

  SDL_Event userEvent;

  int frames = 0;
  std::time_t t = std::time(nullptr);
  std::time_t t2 = std::time(nullptr);

  std::unique_ptr<Asset2d> test(new Asset2d(0, 0, 20, 20, "media/player_sprite_1.png", renderer));


  while (running)
  {
    if (t2 - t >= 1)
    {
      t = std::time(nullptr);
      std::cout << "FPS : " << frames << std::endl;
      frames = 0;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Uint32 black = SDL_MapRGB(ptrWindowSurface->format, 0, 0, 0);
    // SDL_FillRect(ptrWindowSurface, NULL, black);

    SDL_PollEvent(&userEvent);
    switch (userEvent.type)
    {
    case SDL_KEYDOWN:
      std::cout << "KeyboardEvent : " << userEvent.key.keysym.sym << " (" << userEvent.key.timestamp << ')' << std::endl;
      player->changeTexture();
      switch (userEvent.key.keysym.sym)
      {
      case SDLK_UP:
        test->getAssetGameObj()->y  -= 10;
        std::cout << "Player posy: " << player->posy << std::endl;
        std::cout << "PlayerRect y: " << test->getAssetGameObj()->y << std::endl;
        break;

      case SDLK_DOWN:
        test->getAssetGameObj()->y += 10;
        std::cout << "Player posy: " << player->posy << std::endl;
        std::cout << "PlayerRect y: " << test->getAssetGameObj()->y << std::endl;
        break;

      case SDLK_RIGHT:
        test->getAssetGameObj()->x += 10;
        std::cout << "Player posx: " << player->posx << std::endl;
        std::cout << "PlayerRect x: " << test->getAssetGameObj()->x << std::endl;
        break;

      case SDLK_LEFT:
        test->getAssetGameObj()->x -= 10;
        std::cout << "Player posx: " << player->posx << std::endl;
        std::cout << "PlayerRect x: " << test->getAssetGameObj()->x << std::endl;
        break;
      
      case SDLK_SPACE:


      default:
        break;
      }
      break;
    case SDL_WINDOWEVENT:
      // std::cout << "WindowEvent : " << userEvent.window.event  << " (" << userEvent.window.timestamp  << ')' << std::endl;
      switch (userEvent.window.event)
      {
      case SDL_WINDOWEVENT_CLOSE:
        running = false;
        break;

      case SDL_WINDOWEVENT_RESIZED:
        ptrWindowSurface = SDL_GetWindowSurface(ptrWindow);
        // std::cout << playerRect.w << ' ' << playerRect.h << std::endl;
        std::cout << ptrWindowSurface->h << ' ' << ptrWindowSurface->w << std::endl;
        break;

      default:
        break;
      }

    default:
      break;
    }

    SDL_RenderCopy(renderer, player->currentTexture, NULL, &player->assetRect);
    SDL_RenderCopy(renderer, test->getCurrentTexture(), NULL, test->getAssetGameObj());
    SDL_RenderPresent(renderer);
    
    frames += 1;
    t2 = std::time(nullptr);
  }

  SDL_DestroyWindow(ptrWindow);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  return EXIT_SUCCESS;
}