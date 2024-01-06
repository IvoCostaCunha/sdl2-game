#include "TextAsset.hpp"

#include <string>

TextAsset::TextAsset(std::string name) : name(name)
{
}

std::string TextAsset::getName()
{
    return name;
}