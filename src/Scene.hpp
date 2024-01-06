#pragma once

#include <vector>

#include "Asset2d.hpp"
#include "TextAsset.hpp"

class Scene
{

public:
    Scene();
    Scene(std::string sceneName, std::vector<Asset2d> v_asset2d, std::vector<TextAsset> v_textAsset);

    void deleteAsset2d(std::string assetId);
    void deleteTextAsset(std::string assetId);

    void addAsset2d(Asset2d asset2d);
    void addTextAsset(TextAsset textAsset);

    std::string getName();

private:
    std::vector<Asset2d> v_asset2d;
    std::vector<TextAsset> v_textAsset;
    std::string name;
};
