#include "Core.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include <iostream>

Core::Core()
{
    initiate();
}

Core::Core(std::list<Asset2d> asset2dToLoad, std::list<AssetLabel> assetLabelToLoad)
{
    int INIT = initiate();
    if (INIT < 0)
    {
        std::cout << "An error occured during initiation()\n"
                  << SDL_GetError() << std::endl;
    }

    for (std::list<Asset2d>::iterator it = asset2dToLoad.begin(); it != asset2dToLoad.end(); ++it)
    {
        loadedAsset2d.push_back(*it);
    }
    for (std::list<AssetLabel>::iterator it = assetLabelToLoad.begin(); it != assetLabelToLoad.end(); ++it)
    {
        loadedAssetText.push_back(*it);
    }
}

void Core::addLoadedAsset2d(Asset2d newAsset)
{
    loadedAsset2d.push_back(newAsset);
}

void Core::addLoadedAssetLabel(AssetLabel newAsset)
{
    loadedAssetText.push_back(newAsset);
}

int Core::initiate()
{
    int SDL_INIT = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS);
    IMG_Init(IMG_INIT_PNG);
    int SDL_TTF_INIT = TTF_Init();

    if (SDL_INIT || SDL_TTF_INIT < 0)
    {
        std::cout << "Cannot SDL_Init() or TTF_Init() (%s)\n"
                  << SDL_GetError() << std::endl;
        return -1;
    }

    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN);

    if (window == nullptr)
    {
        std::cout << "Could not initialize SDL window\n"
                  << SDL_GetError() << std::endl;
        return -1;
    }

    // -1 means SDL chooses automaticaly the graphical driver
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

    if (renderer == nullptr)
    {
        std::cout << "Could not initialize SDL renderer\n"
                  << SDL_GetError() << std::endl;
        return -1;
    }

    windowSurface = SDL_GetWindowSurface(window);

    if (windowSurface == nullptr)
    {
        std::cout << "Could not initialize SDL window surface\n"
                  << SDL_GetError() << std::endl;
        return -1;
    }

    return 0;
}

Core::~Core()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(windowSurface);
    SDL_Quit();
}
