#include "Scene.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include "TextAsset.hpp"

Scene::Scene(std::vector<Asset2d> v_asset2d_p, std::vector<TextAsset> v_textAsset_p)
{

    for (std::vector<Asset2d>::iterator it = v_asset2d_p.begin(); it != v_asset2d_p.end(); ++it)
    {
        v_asset2d.push_back(*it);
    }
    for (std::vector<TextAsset>::iterator it = v_textAsset_p.begin(); it != v_textAsset_p.end(); ++it)
    {
        v_textAsset.push_back(*it);
    }
}

void Scene::addAsset2d(Asset2d asset2d_p)
{
    v_asset2d.push_back(asset2d_p);
}

void Scene::addTextAsset(TextAsset textAsset_p)
{
    v_textAsset.push_back(textAsset_p);
}