#pragma once

#include <list>
#include <vector>
#include <string>

#include "Asset2d.hpp"
#include "TextAsset.hpp"
#include "Scene.hpp"

/**
 * Class that represents the core game engine with all modules loaded
 */
class Core
{
public:
    Core();
    Core(uint32_t initFlags, uint32_t windowFlags, uint32_t rendererFlags);

    ~Core();

    void addFont(std::string pathToFont);
    void deleteFont(std::string fontName);
    void run();

private:
    std::vector<Scene> v_scene;
    std::vector<TTF_Font *> v_font;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *windowSurface;

    int initiate(uint32_t initFlags, uint32_t windowFlags, uint32_t rendererFlags);
};