#pragma once

#include <vector>

#include "Asset2d.hpp"
#include "TextAsset.hpp"

class Scene
{

public:
    Scene();
    Scene(std::vector<Asset2d> v_asset2d, std::vector<TextAsset> v_textAsset);

    void deleteAsset2d(Asset2d asset2d);
    void deleteAssetLabel(TextAsset textAsset);

    void addAsset2d(Asset2d asset2d);
    void addTextAsset(TextAsset textAsset);

private:
    std::vector<Asset2d> v_asset2d;
    std::vector<TextAsset> v_textAsset;
};
