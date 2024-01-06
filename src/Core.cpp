#include "Core.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include <iostream>

Core::Core(uint32_t initFlags, uint32_t windowFlags, uint32_t rendererFlags)
{
    int INIT = initiate(initFlags, windowFlags, rendererFlags);
    if (INIT < 0)
    {
        std::cout << "An error occured during Core::initiation()\n"
                  << SDL_GetError() << std::endl;
        throw std::runtime_error("Failed to construct Core object.");
    }
}

void Core::createScene(std::string sceneName, std::vector<Asset2d> v_asset2d_p, std::vector<TextAsset> v_textAsset_p) {
    Scene newScene = Scene(sceneName, v_asset2d_p, v_textAsset_p);
    v_scene.push_back(newScene);
}

void Core::setScene(std::string sceneName) {
    for(Scene s: v_scene) {
        if(s.getName() == sceneName) {
            // load scene assets here
        }
    }
}

void Core::run()
{
    bool running = true;
    SDL_Event userEvent;

    while (running)
    {

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        /**
         * SDL_PoolEvent() is a necessity to show the window on MacOS & Windows
         * TODO: Inputs should be separated later
         */
        SDL_PollEvent(&userEvent);
        switch (userEvent.type)
        {
        case SDL_KEYDOWN:
            std::cout << "KeyboardEvent : " << userEvent.key.keysym.sym << " (" << userEvent.key.timestamp << ')' << std::endl;
        case SDL_WINDOWEVENT:
            // std::cout << "WindowEvent : " << userEvent.window.event  << " (" << userEvent.window.timestamp  << ')' << std::endl;
            switch (userEvent.window.event)
            {
            case SDL_WINDOWEVENT_CLOSE:
                running = false;
                break;

            case SDL_WINDOWEVENT_RESIZED:
                windowSurface = SDL_GetWindowSurface(window);
                std::cout << windowSurface->h << ' ' << windowSurface->w << std::endl;
                break;

            default:
                break;
            }

        default:
            break;
        }

        SDL_RenderPresent(renderer);
    }
}

int16_t Core::initiate(uint32_t initFlags, uint32_t windowFlags, uint32_t rendererFlags)
{
    int SDL_INIT = SDL_Init(initFlags);
    IMG_Init(IMG_INIT_PNG);
    int SDL_TTF_INIT = TTF_Init();

    if (SDL_INIT || SDL_TTF_INIT < 0)
    {
        std::cout << "Cannot SDL_Init() or TTF_Init() (%s)\n"
                  << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, windowFlags);

    if (window == nullptr)
    {
        std::cout << "Could not initialize SDL window" << std::endl;
        return EXIT_FAILURE;
    }

    // -1 means SDL chooses automaticaly the graphical driver
    renderer = SDL_CreateRenderer(window, -1, rendererFlags);

    if (renderer == nullptr)
    {
        std::cout << "Could not initialize SDL renderer" << std::endl;
        return EXIT_FAILURE;
    }

    windowSurface = SDL_GetWindowSurface(window);

    if (windowSurface == nullptr)
    {
        std::cout << "Could not initialize SDL window surface" << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

Core::~Core()
{
    // for (TTF_Font *p : v_font)
    // {
    //     TTF_CloseFont(p);
    // }
    // v_font.clear();

    SDL_DestroyRenderer(renderer);
    SDL_FreeSurface(windowSurface);
    SDL_DestroyWindow(window);

    SDL_Quit();
}
