#include <iostream>
#include <memory>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

// Heap = pointeur => plus lent mais plus grande quantité
// Stack = non pointeur => plus rapide moins de place
class Asset
{
public:
  Asset() {}
  Asset(int x, int y, int h, int l, const char *filepath) : posx(x), posy(y), dimh(h), diml(l)
  {
    SDL_Surface *img = IMG_Load(filepath);
    texture = img;
  }

  Asset(const Asset &asset) : posx(asset.posx), posy(asset.posy), dimh(asset.dimh), diml(asset.diml) {}

  int posx;
  int posy;
  int dimh;
  int diml;

  SDL_Surface *texture;
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

  SDL_Window *window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if (window == nullptr)
  {
    printf("Cannot window nullptr (%s)\n", SDL_GetError());
    SDL_Quit();
    return EXIT_FAILURE;
  }

  // char a[10];
  // scanf("%s", a);
  // printf("Hello world\n");

  SDL_Surface *windowSurface = SDL_GetWindowSurface(window);

  Asset *player = new Asset(0, 0, 200, 300, "media/sprite.png");

  // ptr unique au scope
  std::unique_ptr<Asset> playerUniquePtr(new Asset());

  // ptr partagable
  // std::shared_ptr<Asset> playerSharedPtr(playerUniquePtr.get()->get()); si on veut accepter a un geteur d'un poiteur
  std::shared_ptr<Asset> playerSharedPtr(playerUniquePtr.get());

  SDL_Event userEvent;

  while (running)
  {
    Uint32 black = SDL_MapRGB(windowSurface->format, 0, 0, 0);
    SDL_FillRect(windowSurface, NULL, black);

    SDL_Rect playerRect = {player->posx, player->posy, player->diml, player->dimh};
    SDL_BlitSurface(player->texture, NULL, windowSurface, &playerRect);

    // std::cout << playerRect.x << ' ' << playerRect.y << std::endl;
    // std::cout << windowSurface->h << ' ' << windowSurface->w << std::endl;

    SDL_PollEvent(&userEvent);
    switch (userEvent.type)
    {
    case SDL_KEYDOWN:
      std::cout << "KeyboardEvent : " << userEvent.key.keysym.sym << " (" << userEvent.key.timestamp << ')' << std::endl;
      switch (userEvent.key.keysym.sym)
      {
      case SDLK_DOWN:
        player->posx += 10;
        std::cout << player->posx << std::endl;
        break;

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
        windowSurface = SDL_GetWindowSurface(window);
        std::cout << playerRect.w << ' ' << playerRect.h << std::endl;
        std::cout << windowSurface->h << ' ' << windowSurface->w << std::endl;
        break;

      default:
        break;
      }

    default:
      break;
    }
    SDL_UpdateWindowSurface(window);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
}