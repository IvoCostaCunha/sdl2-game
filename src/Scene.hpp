#pragma once

#include "Asset2d.hpp"
#include <vector>

class Scene
{

public:
    Scene();

private:
    std::vector<Asset2d> asset2d;
};
