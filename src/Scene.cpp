#include "Scene.hpp"

#include "TextAsset.hpp"

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include <string>


Scene::Scene()
{
}

Scene::Scene(std::string sceneName, std::vector<Asset2d> v_asset2d_p, std::vector<TextAsset> v_textAsset_p)
{
    name = sceneName;
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

// TODO: SHOULD BE TESTED !
void Scene::deleteAsset2d(std::string assetName) {
    for(std::vector<Asset2d>::iterator it = v_asset2d.begin(); it != v_asset2d.end(); ++it) {
        if(it->getName() == assetName) {
            v_asset2d.erase(it);
        }
    }
}

// TODO: SHOULD BE TESTED ASWELL !
void Scene::deleteTextAsset(std::string assetName) {
    for(std::vector<TextAsset>::iterator it = v_textAsset.begin(); it != v_textAsset.end(); ++it) {
        if(it->getName() == assetName) {
            v_textAsset.erase(it);
        }
    }
}

std::string Scene::getName() {
    return name;
}