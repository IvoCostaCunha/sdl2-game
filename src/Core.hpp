#pragma once

#include <unordered_map>
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

    void setScene(std::string name);
    void createScene(std::string sceneName, std::vector<Asset2d> v_asset2d_p, std::vector<TextAsset> v_textAsset_p);
    
    void run();

private:
    std::vector<Scene> v_scene;
    std::unordered_map<std::string, TTF_Font*> m_font;
    std::unique_ptr<Scene> activeScene;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *windowSurface;

    /**
     * Return 0 if success, 1 if failure
    */
    int16_t initiate(uint32_t initFlags, uint32_t windowFlags, uint32_t rendererFlags);
};