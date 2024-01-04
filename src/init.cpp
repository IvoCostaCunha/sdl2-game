#include <iostream>

#include "Core.hpp"

// Heap = pointeur => plus lent mais plus grande quantité
// Stack = non pointeur => plus rapide moins de place
// class Asset
// {
// public:
//     Asset() {}
//     Asset(int x, int y, int w, int h, const char *ptrFilepath1, const char *ptrFilepath2, SDL_Renderer *renderer) : posx(x), posy(y), dimw(w), dimh(h)
//     {
//         SDL_Surface *img = IMG_Load(ptrFilepath1);
//         SDL_Surface *img2 = IMG_Load(ptrFilepath2);
//         textures[0] = SDL_CreateTextureFromSurface(renderer, img);
//         textures[1] = SDL_CreateTextureFromSurface(renderer, img2);
//         SDL_FreeSurface(img);
//         SDL_FreeSurface(img2);
//         int *ptrPosx = &posx;
//         int *ptrPosy = &posy;
//         int *ptrDimw = &dimw;
//         int *ptrDimh = &dimh;
//         assetRect.x = *ptrPosx;
//         assetRect.y = *ptrPosy;
//         assetRect.w = *ptrDimw;
//         assetRect.h = *ptrDimh;

//         currentTexture = textures[0];

//         SDL_QueryTexture(currentTexture, NULL, NULL, &assetRect.w, &assetRect.h);
//     }

//     Asset(const Asset &asset) : posx(asset.posx), posy(asset.posy), dimw(asset.dimw), dimh(asset.dimh) {}

//     int posx;
//     int posy;
//     int dimw;
//     int dimh;

//     SDL_Rect assetRect;
//     SDL_Texture *textures[2];
//     SDL_Texture *currentTexture;

//     void changeTexture()
//     {
//         currentTexture == textures[0] ? currentTexture = textures[1] : currentTexture = textures[0];
//     }

//     void jump()
//     {
//         // TODO with jump sprite
//     }
// };

// void renderFont(const char *text, TTF_Font *font, SDL_Color fontColor, SDL_Renderer *renderer)
// {
//     SDL_Surface *fontSurface = TTF_RenderUTF8_Blended(font, text, fontColor);
//     SDL_Texture *fontTexture = SDL_CreateTextureFromSurface(renderer, fontSurface);

//     SDL_Rect fontRect{0, 0, fontSurface->w, fontSurface->h};
//     SDL_QueryTexture(fontTexture, NULL, NULL, &fontRect.w, &fontRect.h);

//     SDL_FreeSurface(fontSurface);

//     SDL_RenderCopy(renderer, fontTexture, NULL, &fontRect);
// }

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

#ifdef RELEASE
    // For a release
#endif

    uint32_t initFlags = SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS;
    uint32_t windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN;
    uint32_t rendererFlags = SDL_RENDERER_SOFTWARE;

    try
    {
        Core core = Core(initFlags, windowFlags, rendererFlags);
        core.run();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

    // SDL_Init(initFlags);

    // SDL_Window *window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, windowFlags);

    // // -1 means SDL chooses automaticaly the graphical driver
    // SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, rendererFlags);
    // // SDL_Renderer *renderer = SDL_CreateRenderer(ptrWindow, -1, SDL_RENDERER_SOFTWARE | SDL_RENDERER_PRESENTVSYNC);

    // SDL_Event e;
    // bool quit = false;
    // while (!quit)
    // {
    //     while (SDL_PollEvent(&e))
    //     {
    //         if (e.type == SDL_QUIT)
    //         {
    //             quit = true;
    //         }
    //         if (e.type == SDL_KEYDOWN)
    //         {
    //             quit = true;
    //         }
    //         if (e.type == SDL_MOUSEBUTTONDOWN)
    //         {
    //             quit = true;
    //         }
    //     }
    // }

    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();

    // char a[10];
    // scanf("%s", a);
    // printf("Hello world\n");

    // SDL_Surface *windowSurface = SDL_GetWindowSurface(window);

    // if (windowSurface == nullptr)
    // {
    //     std::cout << "Could not initialize SDL window surface\n"
    //               << SDL_GetError() << std::endl;
    //     SDL_DestroyWindow(window);
    //     SDL_DestroyRenderer(renderer);
    //     SDL_Quit();
    //     return EXIT_FAILURE;
    // }

    // TTF_Init();
    // // TODO: Should load all fonts at program start
    // // each file in ttf/ should be loaded

    // TTF_Font *robotoMediumFont = TTF_OpenFont("ttf/Roboto-Regular.ttf", 20);

    // if (robotoMediumFont == nullptr)
    // {
    //     std::cout << "Could not initialize font\n"
    //               << SDL_GetError() << std::endl;
    //     SDL_DestroyWindow(window);
    //     SDL_DestroyRenderer(renderer);
    //     SDL_Quit();
    //     return EXIT_FAILURE;
    // }

    // const char *text = "test";
    // SDL_Color fontColor = {20, 20, 20, 255};

    // SDL_Surface *fontSurface = TTF_RenderUTF8_Blended(robotoMediumFont, text, fontColor);
    // SDL_Texture *fontTexture = SDL_CreateTextureFromSurface(renderer, fontSurface);

    // SDL_Rect fontRect{0, 0, fontSurface->w, fontSurface->h};

    // SDL_QueryTexture(fontTexture, NULL, NULL, &fontRect.w, &fontRect.h);

    // SDL_FreeSurface(fontSurface);

    // Asset *player = new Asset(0, 0, 200, 300, "media/sprite.png");
    // ptr unique au scope
    // std::unique_ptr<Asset> player(new Asset(50, 50, 250, 10, "media/player_sprite_1.png", "media/player_sprite_2.png", renderer));

    // ptr partagable
    // std::shared_ptr<Asset> playerSharedPtr(player.get()->get()); si on veut accepter a un geteur d'un poiteur
    // std::shared_ptr<Asset> playerSharedPtr(player.get());

    // SDL_Rect playerRect = {player->posx, player->posy, player->diml, player->dimh};
    // SDL_BlitSurface(player->texture[0], NULL, windowSurface, &playerRect);

    // SDL_Point point{300, 300};

    // SDL_Rect playerRectangle;
    // playerRectangle.x = 50;
    // playerRectangle.y = 50;
    // SDL_QueryTexture(player->texture[0], NULL, NULL, &playerRectangle.w, &playerRectangle.h);

    // std::time_t t = std::time(nullptr);
    // sleep(5);
    // std::time_t t2 = std::time(nullptr);
    // std::cout << "time " << t2-t << std::endl;

    // SDL_Event userEvent;

    //   int frames = 0;
    //   const char *lastFPSValue = "0";
    //   std::time_t t = std::time(nullptr);
    //   std::time_t t2 = std::time(nullptr);

    // std::unique_ptr<Asset2d> test(new Asset2d(0, 0, 20, 20, "media/player_sprite_1.png", renderer));

    // while (running)
    // {
    //     // if (t2 - t >= 1)
    //     // {
    //     //   t = std::time(nullptr);
    //     //   // std::cout << "FPS : " << std::to_string(frames) << std::endl;
    //     //   lastFPSValue = std::to_string(frames).c_str();
    //     //   frames = 0;
    //     // }

    //     // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //     // SDL_RenderClear(renderer);

    //     // SDL_PollEvent(&userEvent);
    //     // switch (userEvent.type)
    //     // {
    //     // case SDL_KEYDOWN:
    //     //   std::cout << "KeyboardEvent : " << userEvent.key.keysym.sym << " (" << userEvent.key.timestamp << ')' << std::endl;
    //     //   player->changeTexture();
    //     //   switch (userEvent.key.keysym.sym)
    //     //   {
    //     //   case SDLK_UP:
    //     //     test->getAssetGameObj()->y -= 10;
    //     //     std::cout << "Player posy: " << player->posy << std::endl;
    //     //     std::cout << "PlayerRect y: " << test->getAssetGameObj()->y << std::endl;
    //     //     break;

    //     //   case SDLK_DOWN:
    //     //     test->getAssetGameObj()->y += 10;
    //     //     std::cout << "Player posy: " << player->posy << std::endl;
    //     //     std::cout << "PlayerRect y: " << test->getAssetGameObj()->y << std::endl;
    //     //     break;

    //     //   case SDLK_RIGHT:
    //     //     test->getAssetGameObj()->x += 10;
    //     //     std::cout << "Player posx: " << player->posx << std::endl;
    //     //     std::cout << "PlayerRect x: " << test->getAssetGameObj()->x << std::endl;
    //     //     break;

    //     //   case SDLK_LEFT:
    //     //     test->getAssetGameObj()->x -= 10;
    //     //     std::cout << "Player posx: " << player->posx << std::endl;
    //     //     std::cout << "PlayerRect x: " << test->getAssetGameObj()->x << std::endl;
    //     //     break;

    //     //   case SDLK_SPACE:

    //     //   default:
    //     //     break;
    //     //   }
    //     //   break;
    //     // case SDL_WINDOWEVENT:
    //     //   // std::cout << "WindowEvent : " << userEvent.window.event  << " (" << userEvent.window.timestamp  << ')' << std::endl;
    //     //   switch (userEvent.window.event)
    //     //   {
    //     //   case SDL_WINDOWEVENT_CLOSE:
    //     //     running = false;
    //     //     break;

    //     //   case SDL_WINDOWEVENT_RESIZED:
    //     //     windowSurface = SDL_GetWindowSurface(window);
    //     //     // std::cout << playerRect.w << ' ' << playerRect.h << std::endl;
    //     //     std::cout << windowSurface->h << ' ' << windowSurface->w << std::endl;
    //     //     break;

    //     //   default:
    //     //     break;
    //     //   }

    //     // default:
    //     //   break;
    //     // }

    //     // SDL_RenderCopy(renderer, player->currentTexture, NULL, &player->assetRect);
    //     // SDL_RenderCopy(renderer, test->getCurrentTexture(), NULL, test->getAssetGameObj());
    //     // renderFont(lastFPSValue, robotoMediumFont, fontColor, renderer);
    //     // SDL_RenderPresent(renderer);

    //     // frames += 1;
    //     // t2 = std::time(nullptr);
    // }

    // IMG_Quit();
    // TTF_Quit();
}