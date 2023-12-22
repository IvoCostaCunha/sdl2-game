#pragma once

class Asset
{
public:
  Asset() {}
  Asset(int x, int y, int h, int l) : posx(x), posy(y), dimh(h), diml(l) {}
  Asset(const Asset &asset) : posx(asset.posx), posy(asset.posy), dimh(asset.dimh), diml(asset.diml) {}

  int posx;
  int posy;
  int dimh;
  int diml;
};