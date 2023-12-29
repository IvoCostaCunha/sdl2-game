#ifndef CORE_HPP
#define CORE_HPP

#include <list>
#include <vector>

#include "Asset2d.hpp"
#include "AssetLabel.hpp"
#include "Scene.hpp"

/**
 * Class that represents the core game engine with all modules loaded
 */
class Core
{
public:
    Core();
    Core(std::list<Asset2d> asset2dToLoad, std::list<AssetLabel> assetLabelToLoad);

    ~Core();

    void addLoadedAsset2d(Asset2d newAsset);
    void addLoadedAssetLabel(AssetLabel newAsset);
    void addLoadedFont(TTF_Font newFont);

    void deleteAsset2d(Asset2d asset);
    void deleteAssetLabel(AssetLabel asset);
    void deleteFont(TTF_Font font);

private:
    std::vector<Scene> scenes;
    std::list<Asset2d> loadedAsset2d;
    std::list<AssetLabel> loadedAssetText;
    //std::list<TTF_Font> loadedFont;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *windowSurface;

    int initiate();
};

#endif