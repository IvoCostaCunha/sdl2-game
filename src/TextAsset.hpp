#pragma once

#include "SDL2/SDL_ttf.h"

#include <string>

class TextAsset
{
public:
    TextAsset();
    TextAsset(std::string name);
    TextAsset(std::string name, int32_t x, int32_t y, int32_t w, int32_t h);
    std::string getName();

private:
    std::string name;
};